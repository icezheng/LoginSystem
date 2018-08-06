package model

import (
	"database/sql"
	"errors"
	_ "github.com/go-sql-driver/mysql"
	"github.com/satori/go.uuid"
	"log"
	"time"
)

var db *sql.DB

func init() {
	dbConn, err := sql.Open("mysql", "unilogin:unilogin123@tcp(127.0.0.1:3306)/uni_login")
	if err != nil {
		log.Fatalln(err)
	}

	err = dbConn.Ping()
	if err != nil {
		log.Fatalln(err)
	}

	db = dbConn

	log.Println("mysql conn succ")
}

func Login(userName, password string) (string, error) {
	// TODO 密码需要进行加密传输
	log.Printf("user login userName: %s, password %s",userName, password)

	// 检查用户名和密码是否正确，成功返回用户id
	var userId sql.NullString
	err := db.QueryRow("SELECT id FROM user WHERE user_name=? and password=?", userName, password).Scan(&userId)
	if err != nil {
		log.Println(err)
		return "", err
	}

	if !userId.Valid {
		// user not exist
		err = errors.New("user or password wrong")
		return "", err
	}

	// 剔除掉其他用户的session [TODO 以下剔除和新增session逻辑需要使用事物]
	stmt, err := db.Prepare("UPDATE user_session SET enable = 0 WHERE user_id = ? AND enable = 1")
	if err != nil {
		log.Println(err)
		return "", err
	}
	_, err = stmt.Exec(userId)
	if err != nil {
		log.Println(err)
		return "", err
	}

	// 生成用户sessionID，当前使用uuid，也可以使用其他的随机id生成算法
	sessionUUID, err := uuid.NewV4()
	if err != nil {
		log.Println(err)
		return "", err
	}

	sessionId := sessionUUID.String()

	// 保存用户session
	stmt, err = db.Prepare("INSERT INTO user_session(user_id, session_id, enable, login_time) values(?,?,?,?)")
	if err != nil {
		log.Println(err)
		return "", err
	}
	_, err = stmt.Exec(userId, sessionId, 1, time.Now().Format("2006-01-02 15:04:05"))
	if err != nil {
		log.Println(err)
		return "", err
	}

	log.Printf("user login success, sessionId %s", sessionId)
	return string(sessionId), nil
}

func Register(userName, password string) (userId int64, err error) {
	// TODO 密码传输需要进行加密，存储需要进行加密
	log.Printf("user register, userName %s, password %s", userName, password)
	userId = 0

	// 检查用户名是否存在
	var isUserExist int
	err = db.QueryRow("SELECT count(1) as cnt FROM `user` WHERE user_name=?", userName).Scan(&isUserExist)
	if err != nil {
		log.Println(err)
		return
	}

	if isUserExist >= 1 {
		err = errors.New("user exist")
		log.Println(err)
		return
	}

	// 新注册用户
	stmt, err := db.Prepare("INSERT INTO user(user_name, password, reg_time ) values(?,?,?)")
	if err != nil {
		log.Println(err)
		return
	}
	rs, err := stmt.Exec(userName, password, time.Now().Format("2006-01-02 15:04:05"))
	if err != nil {
		log.Println(err)
		return
	}
	userId, _ = rs.LastInsertId()
	log.Println("user registger new id ", userId)

	return userId, nil
}

func CheckSession(sessionId string) (isValid bool, err error) {
	log.Printf("user check session %s", sessionId)

	isValid = false
	// 检查用户名是否存在
	var isSessionValid sql.NullString
	err = db.QueryRow("SELECT session_id FROM user_session WHERE session_id=? AND enable = 1 ", sessionId).Scan(&isSessionValid)
	if err != nil {
		log.Println(err)
		return
	}

	if !isSessionValid.Valid {
		err = errors.New("session expired")
		log.Println(err)
		return
	}

	// 更新当前session活跃时间 -> lu_time为last_update_time，用户最后活跃时间，可以基于此处制定踢人策略
	stmt, err := db.Prepare("UPDATE user_session SET lu_time = ? WHERE session_id = ?")
	if err != nil {
		log.Println(err)
		return
	}
	defer stmt.Close()

	_, err = stmt.Exec( time.Now().Format("2006-01-02 15:04:05"), sessionId)
	if err != nil {
		log.Println(err)
		return
	}

	log.Printf("user check session succ, session id %s", sessionId)
	return true, nil
}

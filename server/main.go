package main

import (
	"log"
	"net"

	"golang.org/x/net/context"
	"google.golang.org/grpc"
	pb "uin-login/proto"
	"google.golang.org/grpc/reflection"
	"uin-login/model"
)

const (
	// 默认端口号
	port = ":53101"
)

// server is used to implement helloworld.GreeterServer.
type server struct{}

// Login
func (s *server) Login(ctx context.Context, in *pb.LoginReq) (*pb.LoginResp, error)  {
	sessionId, err := model.Login(in.UserName, in.Password)
	if err != nil {
		return &pb.LoginResp{Errcode:1, Errmsg:err.Error()}, nil
	} else {
		return &pb.LoginResp{Errcode:0, SessionId:sessionId}, nil
	}
}

// Register
func (s *server) Register(ctx context.Context, in *pb.RegisterReq) (*pb.RegisterResp,error)  {
	var resp = &pb.RegisterResp{}

	_, err := model.Register(in.UserName, in.Password)
	if err != nil {
		resp.Errcode = 2
		resp.Errmsg = err.Error()
		return resp, nil
	}

	resp.Errcode = 0
	resp.Errmsg = ""

	return resp, nil
}

// CheckSession
func (s *server) CheckSession(ctx context.Context, in *pb.CheckSessionReq) (*pb.CheckSessionResp, error)  {
	var resp = &pb.CheckSessionResp{}
	isValid, _ := model.CheckSession(in.SessionId)
	resp.IsValid = isValid
	return resp, nil
}


func main() {
	// Golang grpc svr
	lis, err := net.Listen("tcp", port)
	if err != nil {
		log.Fatalf("failed to listen: %v", err)
	}
	s := grpc.NewServer()
	pb.RegisterUniLoginServer(s, &server{})
	// Register reflection service on gRPC server.
	reflection.Register(s)
	log.Println("server start to run.")
	if err := s.Serve(lis); err != nil {
		log.Fatalf("failed to serve: %v", err)
	}
}

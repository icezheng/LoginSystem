package com.dropbox.loginsystem;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.text.TextUtils;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import com.dropbox.loginsystem.http.NetworkCallback;
import com.dropbox.loginsystem.http.NetworkRequestId;
import com.dropbox.loginsystem.http.NetworkResult;
import com.dropbox.loginsystem.http.NetworkService;
import com.dropbox.loginsystem.proto.CheckSessionResp;
import com.dropbox.loginsystem.proto.LoginResp;
import com.dropbox.loginsystem.proto.RegisterResp;


public class MainActivity extends AppCompatActivity implements View.OnClickListener, NetworkCallback {

    static {
        System.loadLibrary("loginsystem_jni");
    }

    private TextView mSummaryView;
    private EditText mAccountEdit;
    private EditText mPasswordEdit;
    private Button mRegisterBtn;
    private Button mLoginBtn;
    private Button mCheckStatusBtn;

    private EnumLoginStatus mLoginStatus = EnumLoginStatus.init;

    private AccountInfo mAccount;

    enum EnumLoginStatus {
        init, registered, login, valid, expired
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        initView();
        renderLoginStatus();

//
//        AndroidHttpClient httpClient = new AndroidHttpClient();
//        ServerClient serverClient = ServerClient.create(httpClient);
//        byte[] postData = new byte[8 * 1024];
//        serverClient.request(new HttpRequest("127.0.0.1", postData), new RequestCallback() {
//            @Override
//            public void callback(@NonNull HttpResponse response) {
//                renderSummary(response.getData());
//            }
//        });
    }

    private void initView() {
        mSummaryView = findViewById(R.id.summary);
        mAccountEdit = findViewById(R.id.account);
        mPasswordEdit = findViewById(R.id.password);
        mRegisterBtn = findViewById(R.id.register);
        mLoginBtn = findViewById(R.id.login);
        mCheckStatusBtn = findViewById(R.id.check_status);

        mRegisterBtn.setOnClickListener(this);
        mLoginBtn.setOnClickListener(this);
        mCheckStatusBtn.setOnClickListener(this);
    }

    private void renderLoginStatus() {
        switch (mLoginStatus) {
            case init:
                mAccountEdit.setVisibility(View.VISIBLE);
                mPasswordEdit.setVisibility(View.VISIBLE);
                mRegisterBtn.setVisibility(View.VISIBLE);
                mLoginBtn.setVisibility(View.VISIBLE);
                mCheckStatusBtn.setVisibility(View.GONE);
                renderSummary("register or login");
            case registered:
                mAccountEdit.setVisibility(View.VISIBLE);
                mPasswordEdit.setVisibility(View.VISIBLE);
                mRegisterBtn.setVisibility(View.VISIBLE);
                mLoginBtn.setVisibility(View.VISIBLE);
                mCheckStatusBtn.setVisibility(View.GONE);
                renderSummary("login please");
                break;
            case login:
                mAccountEdit.setVisibility(View.GONE);
                mPasswordEdit.setVisibility(View.GONE);
                mRegisterBtn.setVisibility(View.GONE);
                mLoginBtn.setVisibility(View.GONE);
                mCheckStatusBtn.setVisibility(View.VISIBLE);
                renderSummary("login success! \n " + (mAccount != null ? mAccount.toString() : null));
                break;
            case valid:
                renderSummary("check session success! sessionId is valid.\n" + (mAccount != null ? mAccount.toString() : null));
                break;
            case expired:
                mAccountEdit.setVisibility(View.VISIBLE);
                mPasswordEdit.setVisibility(View.VISIBLE);
                mRegisterBtn.setVisibility(View.VISIBLE);
                mLoginBtn.setVisibility(View.VISIBLE);
                mCheckStatusBtn.setVisibility(View.GONE);
                renderSummary("check session success! sessionId is invalid");
                break;
        }
    }

    private void renderSummary(String extraInfo) {
        String summaryBuilder = "summary:\n" + "loginStatus:" + mLoginStatus + "\n" +
                "extraInfo:" + extraInfo;
        mSummaryView.setText(summaryBuilder);
    }

    @Override
    public void onClick(View view) {
        switch (view.getId()) {
            case R.id.register:
                onClickRegister();
                break;
            case R.id.login:
                onClickLogin();
                break;
            case R.id.check_status:
                onClickCheckSession();
                break;
        }
    }

    @Override
    public void onNetworkResult(NetworkResult result) {
        switch (result.getRequestId()) {
            case NetworkRequestId.Register:
                RegisterResp registerRsp = (RegisterResp) result.getResultData();
                if (registerRsp != null && registerRsp.getErrcode() == 0) {
                    updateStatus(EnumLoginStatus.registered);
                } else {
                    Toast.makeText(this, result.failMsg, Toast.LENGTH_LONG).show();
                }
                break;
            case NetworkRequestId.Login:
                LoginResp loginRsp = (LoginResp) result.getResultData();
                if (loginRsp != null && loginRsp.getErrcode() == 0) {
                    mAccount = new AccountInfo();
                    mAccount.account = mAccountEdit.getText().toString();
                    mAccount.password = mAccountEdit.getText().toString();
                    mAccount.sessionId = loginRsp.getSessionId();
                    updateStatus(EnumLoginStatus.login);
                } else {
                    Toast.makeText(this, result.failMsg, Toast.LENGTH_LONG).show();
                }
                break;
            case NetworkRequestId.CheckStatus:
                CheckSessionResp checkSessionRsp = (CheckSessionResp) result.getResultData();
                if (checkSessionRsp != null && checkSessionRsp.getErrcode() == 0) {
                    updateStatus(checkSessionRsp.getIsValid() ? EnumLoginStatus.valid : EnumLoginStatus.expired);
                } else {
                    Toast.makeText(this, result.failMsg, Toast.LENGTH_LONG).show();
                }
                break;
        }
    }

    private void updateStatus(EnumLoginStatus newStatus) {
        mLoginStatus = newStatus;
        renderLoginStatus();
    }

    private void onClickRegister() {
        String account = mAccountEdit.getText().toString();
        String password = mPasswordEdit.getText().toString();
        if (!checkEditAvailable(account, password)) {
            return;
        }
        NetworkService service = NetworkService.getInstance();
        service.register(account, password, this);
    }

    private void onClickLogin() {
        String account = mAccountEdit.getText().toString();
        String password = mPasswordEdit.getText().toString();
        if (!checkEditAvailable(account, password)) {
            return;
        }
        NetworkService service = NetworkService.getInstance();
        service.login(account, password, this);
    }

    private void onClickCheckSession() {
        if (mAccount == null || mAccount.sessionId == null) {
            Toast.makeText(this, R.string.need_login, Toast.LENGTH_LONG).show();
            return;
        }
        NetworkService service = NetworkService.getInstance();
        service.checkLoginStatus(mAccount.sessionId, this);
    }

    private boolean checkEditAvailable(String account, String password) {
        if (TextUtils.isEmpty(account) || TextUtils.isEmpty(password)) {
            Toast.makeText(this, R.string.info_unavailable, Toast.LENGTH_LONG).show();
            return false;
        }
        return true;
    }

}

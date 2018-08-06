package com.dropbox.loginsystem.http;

import com.dropbox.loginsystem.ThreadUtils;
import com.dropbox.loginsystem.proto.CheckSessionReq;
import com.dropbox.loginsystem.proto.LoginReq;
import com.dropbox.loginsystem.proto.RegisterReq;
import com.dropbox.loginsystem.proto.UniLoginGrpc;

public class NetworkService implements NetworkCallback {

    public static final String URL_HOST = "120.77.169.75";
    public static final int URL_PORT = 53101;

    private static NetworkService instance = null;

    private NetworkService() {
    }

    public static NetworkService getInstance() {
        if (null == instance) {
            instance = new NetworkService();
        }
        return instance;
    }

    public void register(String account, String password, NetworkCallback callback) {
        RegisterReq.Builder builder = RegisterReq.newBuilder();
        builder.setUserName(account);
        builder.setPassword(password);
        RegisterReq req = builder.build();
        NetworkRequest<RegisterReq> request = new NetworkRequest<>(NetworkRequestId.Register, req);
        NetworkRequestTask.create((NetworkRequestTask.StubMethodDispatch<RegisterReq>) UniLoginGrpc.UniLoginBlockingStub::register, callback).execute(request);
    }

    public void login(String account, String password, NetworkCallback callback) {
        LoginReq.Builder builder = LoginReq.newBuilder();
        builder.setUserName(account);
        builder.setPassword(password);
        LoginReq req = builder.build();
        NetworkRequest<LoginReq> request = new NetworkRequest<>(NetworkRequestId.Login, req);
        NetworkRequestTask.create((NetworkRequestTask.StubMethodDispatch<LoginReq>) UniLoginGrpc.UniLoginBlockingStub::login, callback).execute(request);
    }

    public void checkLoginStatus(String sessionId, NetworkCallback callback) {
        CheckSessionReq.Builder builder = CheckSessionReq.newBuilder();
        builder.setSessionId(sessionId);
        CheckSessionReq req = builder.build();
        NetworkRequest<CheckSessionReq> request = new NetworkRequest<>(NetworkRequestId.CheckStatus, req);
        NetworkRequestTask.create((NetworkRequestTask.StubMethodDispatch<CheckSessionReq>) UniLoginGrpc.UniLoginBlockingStub::checkSession, callback).execute(request);
    }

    @Override
    public void onNetworkResult(NetworkResult result) {
        NetworkCallback callback = result.getCallback();
        NetworkCallback uiNetworkCallback = null;
        if (callback instanceof NetworkCallbackImpl) {
            uiNetworkCallback = ((NetworkCallbackImpl) callback).getUiNetworkCallback();
        }
        if (uiNetworkCallback != null) {
            if (ThreadUtils.isMainThread()) {
                uiNetworkCallback.onNetworkResult(result);
            } else {
                NetworkCallback finalUiNetworkCallback = uiNetworkCallback;
                ThreadUtils.runOnUiThread(() -> finalUiNetworkCallback.onNetworkResult(result));
            }
        }
    }
}

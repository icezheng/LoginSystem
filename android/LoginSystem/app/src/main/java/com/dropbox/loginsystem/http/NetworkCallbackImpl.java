package com.dropbox.loginsystem.http;

import java.lang.ref.WeakReference;

/**
 * Created by icezheng on 2018/8/1
 */
public class NetworkCallbackImpl implements NetworkCallback {

    private WeakReference<NetworkCallback> mNetworkCallbackRef;

    private final NetworkCallback mNetworkCallback;

    public NetworkCallbackImpl(NetworkCallback callback) {
        mNetworkCallback = callback;
    }

    public void setUICallback(NetworkCallback uiCallback) {
        mNetworkCallbackRef = new WeakReference<>(uiCallback);
    }

    public NetworkCallback getUiNetworkCallback() {
        return mNetworkCallbackRef.get();
    }

    @Override
    public void onNetworkResult(NetworkResult result) {
        mNetworkCallback.onNetworkResult(result);
    }
}

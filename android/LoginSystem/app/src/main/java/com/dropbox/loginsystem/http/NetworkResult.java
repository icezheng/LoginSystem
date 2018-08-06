package com.dropbox.loginsystem.http;

import android.support.annotation.Nullable;

import com.google.protobuf.GeneratedMessageLite;

public class NetworkResult {

    public boolean success = false;

    public GeneratedMessageLite mResultData;

    public String failMsg;

    public NetworkRequestTask mNetworkRequestTask;

    private int mRequestId;

    public void setRequestTask(NetworkRequestTask task) {
        mNetworkRequestTask = task;
    }

    @Nullable
    public NetworkCallback getCallback() {
        if (mNetworkRequestTask != null) {
            return mNetworkRequestTask.getNetworkCallback();
        }
        return null;
    }

    public int getRequestId() {
        return mRequestId;
    }

    public void setRequestId(int requestId) {
        mRequestId = requestId;
    }

    public GeneratedMessageLite getResultData() {
        return mResultData;
    }

    public void setResultData(GeneratedMessageLite resultData) {
        mResultData = resultData;
    }
}

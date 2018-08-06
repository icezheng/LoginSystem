package com.dropbox.loginsystem.http;


import android.support.annotation.NonNull;

import com.google.protobuf.GeneratedMessageLite;

public class NetworkRequest<T extends GeneratedMessageLite> {

    public String url = NetworkService.URL_HOST;

    public T requestMessage;

    private int mRequestId;

    public NetworkRequest() {
    }

    public NetworkRequest(int requestId, @NonNull T messageV3) {
        mRequestId = requestId;
        requestMessage = messageV3;
    }

    public int getRequestId() {
        return mRequestId;
    }
}

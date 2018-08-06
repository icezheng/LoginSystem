package com.dropbox.loginsystem.http;

import android.os.AsyncTask;
import android.support.annotation.Nullable;
import android.util.Log;

import com.dropbox.loginsystem.proto.UniLoginGrpc;
import com.google.protobuf.GeneratedMessageLite;

import io.grpc.ManagedChannel;
import io.grpc.ManagedChannelBuilder;

public class NetworkRequestTask extends AsyncTask<NetworkRequest, Void, NetworkResult> {

    private NetworkCallback mNetworkCallback;

    private ManagedChannel mChannel;

    private StubMethodDispatch mStubMethodDispatch;

    private NetworkRequestTask() {
    }

    public NetworkCallback getNetworkCallback() {
        return mNetworkCallback;
    }

    public static NetworkRequestTask create(StubMethodDispatch dispatch, NetworkCallback networkCallback) {
        NetworkRequestTask task = new NetworkRequestTask();
        task.mStubMethodDispatch = dispatch;
        task.mNetworkCallback = networkCallback;
        return task;
    }

    @Override
    protected void onPreExecute() {
        super.onPreExecute();
    }

    @Override
    protected NetworkResult doInBackground(NetworkRequest... networkRequests) {
        NetworkRequest request = networkRequests[0];
        NetworkResult result = new NetworkResult();
        result.setRequestId(request.getRequestId());
        result.setRequestTask(this);
        try {
            mChannel = ManagedChannelBuilder.forAddress(NetworkService.URL_HOST, NetworkService.URL_PORT).usePlaintext().build();
            UniLoginGrpc.UniLoginBlockingStub stub = UniLoginGrpc.newBlockingStub(mChannel);
            GeneratedMessageLite messageLiteRequest = request.requestMessage;
            GeneratedMessageLite messageLiteResult = mStubMethodDispatch.doAction(stub, messageLiteRequest);
            result.setResultData(messageLiteResult);
        } catch (Throwable e) {
            Log.e("icezheng", "doInBackground occur exception = " + e.toString());
        }
        return result;
    }

    @Override
    protected void onPostExecute(@Nullable NetworkResult networkResult) {
        super.onPostExecute(networkResult);
        mNetworkCallback.onNetworkResult(networkResult);
    }

    public interface StubMethodDispatch<R> {
        GeneratedMessageLite doAction(UniLoginGrpc.UniLoginBlockingStub stub, R request);
    }

}

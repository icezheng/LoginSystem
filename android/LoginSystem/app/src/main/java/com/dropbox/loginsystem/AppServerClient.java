package com.dropbox.loginsystem;

/**
 * Created by icezheng on 2018/8/2
 */
public class AppServerClient {

    private static AppServerClient instance = null;

    private ServerClient mServerClient;

    private AppServerClient() {
        AndroidHttpClient httpClient = new AndroidHttpClient();
//        mServerClient = ServerClient.create(httpClient);
    }

    public static AppServerClient getInstance() {
        if (null == instance) {
            instance = new AppServerClient();
        }
        return instance;
    }


}

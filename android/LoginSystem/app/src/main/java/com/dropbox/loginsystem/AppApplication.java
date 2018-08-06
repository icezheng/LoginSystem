package com.dropbox.loginsystem;

import android.app.Application;

/**
 * Created by icezheng on 2018/8/2
 */
public class AppApplication extends Application {

    private static AppApplication sInstance;

    @Override
    public void onCreate() {
        super.onCreate();
        sInstance = this;
    }

    public static AppApplication getInstance() {
        return sInstance;
    }
}

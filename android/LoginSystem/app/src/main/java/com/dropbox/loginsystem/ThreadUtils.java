package com.dropbox.loginsystem;

import android.os.Handler;
import android.os.Looper;

/**
 * Created by icezheng on 2018/7/29
 */
public final class ThreadUtils {

    private static Thread sMainThread = Looper.getMainLooper().getThread();
    private static Handler sMainHandler = new Handler(Looper.getMainLooper());

    private ThreadUtils() {
    }

    public static void post(Runnable r) {
        sMainHandler.post(r);
    }

    public static void runOnUiThread(Runnable r) {
        if (isMainThread()) {
            r.run();
        } else {
            post(r);
        }
    }

    public static boolean isMainThread() {
        return sMainThread == Thread.currentThread();
    }

    public Handler getMainHandler() {
        return sMainHandler;
    }
}

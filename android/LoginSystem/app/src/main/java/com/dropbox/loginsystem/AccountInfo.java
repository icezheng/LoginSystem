package com.dropbox.loginsystem;

/**
 * Created by icezheng on 2018/8/1
 */
public class AccountInfo {

    public String account;
    public String password;
    public String sessionId;

    @Override
    public String toString() {
        return "account = " + account + ", sessionId = " + sessionId;
    }
}

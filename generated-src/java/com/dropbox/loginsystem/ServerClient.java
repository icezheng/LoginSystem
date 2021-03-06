// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from loginsystem.djinni

package com.dropbox.loginsystem;

import android.support.annotation.NonNull;
import java.util.concurrent.atomic.AtomicBoolean;

/*package*/ interface ServerClient {
    @NonNull
    public RegisterResponse registerAccount(@NonNull String userName, @NonNull String password);

    @NonNull
    public LoginResponse loginAccount(@NonNull String userName, @NonNull String password);

    @NonNull
    public CheckSessionResponse checkSession(@NonNull String sessionId);

    public static ServerClient create()
    {
        return CppProxy.create();
    }

    static final class CppProxy implements ServerClient
    {
        private final long nativeRef;
        private final AtomicBoolean destroyed = new AtomicBoolean(false);

        private CppProxy(long nativeRef)
        {
            if (nativeRef == 0) throw new RuntimeException("nativeRef is zero");
            this.nativeRef = nativeRef;
        }

        private native void nativeDestroy(long nativeRef);
        public void _djinni_private_destroy()
        {
            boolean destroyed = this.destroyed.getAndSet(true);
            if (!destroyed) nativeDestroy(this.nativeRef);
        }
        protected void finalize() throws java.lang.Throwable
        {
            _djinni_private_destroy();
            super.finalize();
        }

        @Override
        public RegisterResponse registerAccount(String userName, String password)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_registerAccount(this.nativeRef, userName, password);
        }
        private native RegisterResponse native_registerAccount(long _nativeRef, String userName, String password);

        @Override
        public LoginResponse loginAccount(String userName, String password)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_loginAccount(this.nativeRef, userName, password);
        }
        private native LoginResponse native_loginAccount(long _nativeRef, String userName, String password);

        @Override
        public CheckSessionResponse checkSession(String sessionId)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_checkSession(this.nativeRef, sessionId);
        }
        private native CheckSessionResponse native_checkSession(long _nativeRef, String sessionId);

        public static native ServerClient create();
    }
}

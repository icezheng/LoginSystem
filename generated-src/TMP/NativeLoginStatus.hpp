// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from loginsystem.djinni

#pragma once

#include "djinni_support.hpp"
#include "login_status.hpp"

namespace djinni_generated {

class NativeLoginStatus final : ::djinni::JniEnum {
public:
    using CppType = ::loginsystem::login_status;
    using JniType = jobject;

    using Boxed = NativeLoginStatus;

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return static_cast<CppType>(::djinni::JniClass<NativeLoginStatus>::get().ordinal(jniEnv, j)); }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, CppType c) { return ::djinni::JniClass<NativeLoginStatus>::get().create(jniEnv, static_cast<jint>(c)); }

private:
    NativeLoginStatus() : JniEnum("com/dropbox/loginsystem/LoginStatus") {}
    friend ::djinni::JniClass<NativeLoginStatus>;
};

}  // namespace djinni_generated

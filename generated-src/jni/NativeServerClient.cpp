// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from loginsystem.djinni

#include "NativeServerClient.hpp"  // my header
#include "Marshal.hpp"
#include "NativeCheckSessionResponse.hpp"
#include "NativeLoginResponse.hpp"
#include "NativeRegisterResponse.hpp"

namespace djinni_generated {

NativeServerClient::NativeServerClient() : ::djinni::JniInterface<::loginsystem::ServerClient, NativeServerClient>("com/dropbox/loginsystem/ServerClient$CppProxy") {}

NativeServerClient::~NativeServerClient() = default;


CJNIEXPORT void JNICALL Java_com_dropbox_loginsystem_ServerClient_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<::djinni::CppProxyHandle<::loginsystem::ServerClient>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jobject JNICALL Java_com_dropbox_loginsystem_ServerClient_00024CppProxy_create(JNIEnv* jniEnv, jobject /*this*/)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        auto r = ::loginsystem::ServerClient::create();
        return ::djinni::release(::djinni_generated::NativeServerClient::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_com_dropbox_loginsystem_ServerClient_00024CppProxy_native_1registerAccount(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jstring j_userName, jstring j_password)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::loginsystem::ServerClient>(nativeRef);
        auto r = ref->register_account(::djinni::String::toCpp(jniEnv, j_userName),
                                       ::djinni::String::toCpp(jniEnv, j_password));
        return ::djinni::release(::djinni_generated::NativeRegisterResponse::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_com_dropbox_loginsystem_ServerClient_00024CppProxy_native_1loginAccount(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jstring j_userName, jstring j_password)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::loginsystem::ServerClient>(nativeRef);
        auto r = ref->login_account(::djinni::String::toCpp(jniEnv, j_userName),
                                    ::djinni::String::toCpp(jniEnv, j_password));
        return ::djinni::release(::djinni_generated::NativeLoginResponse::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jobject JNICALL Java_com_dropbox_loginsystem_ServerClient_00024CppProxy_native_1checkSession(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jstring j_sessionId)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::loginsystem::ServerClient>(nativeRef);
        auto r = ref->check_session(::djinni::String::toCpp(jniEnv, j_sessionId));
        return ::djinni::release(::djinni_generated::NativeCheckSessionResponse::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

}  // namespace djinni_generated

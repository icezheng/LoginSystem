// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from loginsystem.djinni

#include "NativeRegisterResponse.hpp"  // my header
#include "Marshal.hpp"

namespace djinni_generated {

NativeRegisterResponse::NativeRegisterResponse() = default;

NativeRegisterResponse::~NativeRegisterResponse() = default;

auto NativeRegisterResponse::fromCpp(JNIEnv* jniEnv, const CppType& c) -> ::djinni::LocalRef<JniType> {
    const auto& data = ::djinni::JniClass<NativeRegisterResponse>::get();
    auto r = ::djinni::LocalRef<JniType>{jniEnv->NewObject(data.clazz.get(), data.jconstructor,
                                                           ::djinni::get(::djinni::Bool::fromCpp(jniEnv, c.success)))};
    ::djinni::jniExceptionCheck(jniEnv);
    return r;
}

auto NativeRegisterResponse::toCpp(JNIEnv* jniEnv, JniType j) -> CppType {
    ::djinni::JniLocalScope jscope(jniEnv, 2);
    assert(j != nullptr);
    const auto& data = ::djinni::JniClass<NativeRegisterResponse>::get();
    return {::djinni::Bool::toCpp(jniEnv, jniEnv->GetBooleanField(j, data.field_mSuccess))};
}

}  // namespace djinni_generated

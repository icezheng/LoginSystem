// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from loginsystem.djinni

#import "TXSServerClient+Private.h"
#import "TXSServerClient.h"
#import "DJICppWrapperCache+Private.h"
#import "DJIError.h"
#import "DJIMarshal+Private.h"
#import "TXSCheckSessionResponse+Private.h"
#import "TXSLoginResponse+Private.h"
#import "TXSRegisterResponse+Private.h"
#include <exception>
#include <stdexcept>
#include <utility>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@interface TXSServerClient ()

- (id)initWithCpp:(const std::shared_ptr<::loginsystem::ServerClient>&)cppRef;

@end

@implementation TXSServerClient {
    ::djinni::CppProxyCache::Handle<std::shared_ptr<::loginsystem::ServerClient>> _cppRefHandle;
}

- (id)initWithCpp:(const std::shared_ptr<::loginsystem::ServerClient>&)cppRef
{
    if (self = [super init]) {
        _cppRefHandle.assign(cppRef);
    }
    return self;
}

+ (nullable TXSServerClient *)create {
    try {
        auto objcpp_result_ = ::loginsystem::ServerClient::create();
        return ::djinni_generated::ServerClient::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (nonnull TXSRegisterResponse *)registerAccount:(nonnull NSString *)userName
                                        password:(nonnull NSString *)password {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->register_account(::djinni::String::toCpp(userName),
                                                                    ::djinni::String::toCpp(password));
        return ::djinni_generated::RegisterResponse::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (nonnull TXSLoginResponse *)loginAccount:(nonnull NSString *)userName
                                  password:(nonnull NSString *)password {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->login_account(::djinni::String::toCpp(userName),
                                                                 ::djinni::String::toCpp(password));
        return ::djinni_generated::LoginResponse::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (nonnull TXSCheckSessionResponse *)checkSession:(nonnull NSString *)sessionId {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->check_session(::djinni::String::toCpp(sessionId));
        return ::djinni_generated::CheckSessionResponse::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

namespace djinni_generated {

auto ServerClient::toCpp(ObjcType objc) -> CppType
{
    if (!objc) {
        return nullptr;
    }
    return objc->_cppRefHandle.get();
}

auto ServerClient::fromCppOpt(const CppOptType& cpp) -> ObjcType
{
    if (!cpp) {
        return nil;
    }
    return ::djinni::get_cpp_proxy<TXSServerClient>(cpp);
}

}  // namespace djinni_generated

@end
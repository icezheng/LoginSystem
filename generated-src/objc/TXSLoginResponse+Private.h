// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from loginsystem.djinni

#import "TXSLoginResponse.h"
#include "login_response.hpp"

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@class TXSLoginResponse;

namespace djinni_generated {

struct LoginResponse
{
    using CppType = ::loginsystem::LoginResponse;
    using ObjcType = TXSLoginResponse*;

    using Boxed = LoginResponse;

    static CppType toCpp(ObjcType objc);
    static ObjcType fromCpp(const CppType& cpp);
};

}  // namespace djinni_generated
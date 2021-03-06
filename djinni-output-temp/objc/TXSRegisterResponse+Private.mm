// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from loginsystem.djinni

#import "TXSRegisterResponse+Private.h"
#import "DJIMarshal+Private.h"
#include <cassert>

namespace djinni_generated {

auto RegisterResponse::toCpp(ObjcType obj) -> CppType
{
    assert(obj);
    return {::djinni::Bool::toCpp(obj.success)};
}

auto RegisterResponse::fromCpp(const CppType& cpp) -> ObjcType
{
    return [[TXSRegisterResponse alloc] initWithSuccess:(::djinni::Bool::fromCpp(cpp.success))];
}

}  // namespace djinni_generated

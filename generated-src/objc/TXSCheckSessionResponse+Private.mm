// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from loginsystem.djinni

#import "TXSCheckSessionResponse+Private.h"
#import "DJIMarshal+Private.h"
#include <cassert>

namespace djinni_generated {

auto CheckSessionResponse::toCpp(ObjcType obj) -> CppType
{
    assert(obj);
    return {::djinni::Bool::toCpp(obj.success),
            ::djinni::Bool::toCpp(obj.isValid)};
}

auto CheckSessionResponse::fromCpp(const CppType& cpp) -> ObjcType
{
    return [[TXSCheckSessionResponse alloc] initWithSuccess:(::djinni::Bool::fromCpp(cpp.success))
                                                    isValid:(::djinni::Bool::fromCpp(cpp.is_valid))];
}

}  // namespace djinni_generated

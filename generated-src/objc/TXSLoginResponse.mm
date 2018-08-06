// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from loginsystem.djinni

#import "TXSLoginResponse.h"


@implementation TXSLoginResponse

- (nonnull instancetype)initWithSuccess:(BOOL)success
                              sessionId:(nonnull NSString *)sessionId
{
    if (self = [super init]) {
        _success = success;
        _sessionId = [sessionId copy];
    }
    return self;
}

+ (nonnull instancetype)loginResponseWithSuccess:(BOOL)success
                                       sessionId:(nonnull NSString *)sessionId
{
    return [[self alloc] initWithSuccess:success
                               sessionId:sessionId];
}

- (NSString *)description
{
    return [NSString stringWithFormat:@"<%@ %p success:%@ sessionId:%@>", self.class, (void *)self, @(self.success), self.sessionId];
}

@end
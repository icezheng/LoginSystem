// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from loginsystem.djinni

#import <Foundation/Foundation.h>

@interface TXSLoginResponse : NSObject
- (nonnull instancetype)initWithSuccess:(BOOL)success
                              sessionId:(nonnull NSString *)sessionId;
+ (nonnull instancetype)loginResponseWithSuccess:(BOOL)success
                                       sessionId:(nonnull NSString *)sessionId;

@property (nonatomic, readonly) BOOL success;

@property (nonatomic, readonly, nonnull) NSString * sessionId;

@end

// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from loginsystem.djinni

#import <Foundation/Foundation.h>

@interface TXSCheckSessionResponse : NSObject
- (nonnull instancetype)initWithSuccess:(BOOL)success
                                isValid:(BOOL)isValid;
+ (nonnull instancetype)checkSessionResponseWithSuccess:(BOOL)success
                                                isValid:(BOOL)isValid;

@property (nonatomic, readonly) BOOL success;

@property (nonatomic, readonly) BOOL isValid;

@end
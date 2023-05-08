//
//  QNDebug.h
//  QNDeviceSDKDemo
//
//  Created by com.qn.device on 2018/3/7.
//  Copyright © 2018年 com.qn.device. All rights reserved.
//

#import <Foundation/Foundation.h>

#define QNDEBUG_IDENTIFIER @"QNBLEAPI"

#define QNDebugLogIsVail QNDebug.debug

@interface QNDebug : NSObject

@property (nonatomic, assign, class) BOOL debug;

+ (QNDebug *)sharedDebug;

- (void)log:(NSString *)meg;

@end

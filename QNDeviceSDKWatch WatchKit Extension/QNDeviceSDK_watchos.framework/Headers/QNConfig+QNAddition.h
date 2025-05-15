//
//  QNConfig+QNAddition.h
//  QNDeviceSDK
//
//  Created by com.qn.device on 2020/2/25.
//  Copyright © 2020 com.qn.device. All rights reserved.
//


#import "QNConfig.h"
#import "QNDataTool.h"

NS_ASSUME_NONNULL_BEGIN

#define QNFileManageConfigOnlyScreenOn @"onlyScreenOn"
#define QNFileManageConfigAllowDuplicates @"allowDuplicates"
#define QNFileManageConfigDuration @"duration"
#define QNFileManageConfigUnit @"unit"
#define QNFileManageConfigShowPowerAlertKey @"showPowerAlertKey"
#define QNFileManageConfigEnhanceBleBroadcastKey @"enhanceBleBroadcastKey"

@interface QNConfig (QNAddition)

@property(nonatomic, strong) NSString *configPath;

@property(nonatomic, strong) NSLock *lock;


+ (QNConfig *)sharedConfig;

- (instancetype)initConvenient;

@end

NS_ASSUME_NONNULL_END

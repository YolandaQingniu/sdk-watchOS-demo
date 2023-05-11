//
//  QNBleApi.h
//  QNDeviceSDK
//
//  Created by com.qn.device on 2018/1/9.
//  Copyright © 2018年 com.qn.device. All rights reserved.
//


#import <Foundation/Foundation.h>
#import "QNBleStateProtocol.h"
#import "QNBleDeviceDiscoveryProtocol.h"
#import "QNBleConnectionChangeProtocol.h"
#import "QNScaleDataProtocol.h"
#import "QNLogProtocol.h"
#import "QNUser.h"
#import "QNConfig.h"
#import "QNWiFiConfig.h"
#import <CoreBluetooth/CoreBluetooth.h>
#import "QNWspConfig.h"
#import "QNUserScaleConfig.h"

/**
 秤测量方法说明：
 1. 必须光脚测量，才能测到人体生物阻抗
 
 
 关于秤数据的说明：
 1. 在连接上秤的时候测量，测量完毕后数据会立即上传
 2. 在未连接秤的时候测量，测量数据会自动存储到秤端，详细说明请参考"QNScaleStoreData"存储数据类
 
 秤有广播的两种情况:
 1. 秤亮屏的时候，会发出广播
 2. 当秤有存储数据的时候，即使秤处于灭屏的状态下也会发广播
 
 */

@interface QNBleApi : NSObject

/// 是否打开调试开关 默认为NO (建议发布版本时,设置为NO)
@property (nonatomic, assign, class) BOOL debug;
/// 系统蓝牙状态的监听
@property (nonatomic, weak) id<QNBleStateListener> bleStateListener;
/// 发现设备监听，该监听必须实现，否则无法获取搜索到的设备信息
@property (nonatomic, weak) id<QNBleDeviceDiscoveryListener> discoveryListener;
/// 设备状态的监听
@property (nonatomic, weak) id<QNBleConnectionChangeListener> connectionChangeListener;
/// 测量数据的监听，该监听必须实现
@property (nonatomic, weak) id<QNScaleDataListener> dataListener;
/// 日志信息监听
@property(nonatomic, weak) id<QNLogProtocol> logListener;

/// 初始化SDK
+ (QNBleApi *)sharedBleApi;

/// 注册SDK
/// @param appId 需要向官方获取正确的appid
/// @param dataFile 配置文件路径
/// @param callback 结果回调
- (void)initSdk:(NSString *)appId firstDataFile:(NSString *)dataFile callback:(QNResultCallback)callback;

/// 注册SDK
/// @param appId 需要向官方获取正确的appid
/// @param dataFileContent 配置文件内容
/// @param callback 结果回调
- (void)initSdk:(NSString *)appId dataFileContent:(NSString *)dataFileContent callback:(QNResultCallback)callback;

/// 获取当前系统蓝牙转台
- (QNBLEState)getCurSystemBleState;

/// 扫描设备
/// @param callback 结果回调
- (void)startBleDeviceDiscovery:(QNResultCallback)callback;

/// 停止扫描
/// @param callback 结果回调
- (void)stopBleDeviceDiscorvery:(QNResultCallback)callback;

/// 连接设备
/// @param device 连接的设备(该设备对象必须是搜索返回的设备对象)
/// @param user 用户信息
/// @param callback 结果回调
- (void)connectDevice:(QNBleDevice *)device user:(QNUser *)user callback:(QNResultCallback)callback;

/// 连接轻牛用户秤设备
/// @param device 需要连接的蓝牙设备
/// @param config 连接用户秤设备时的配置项
/// @param callback 结果回调
- (void)connectUserScaleDevice:(QNBleDevice *)device config:(QNUserScaleConfig *)config callback:(QNResultCallback)callback;

/// 断开设备的连接
/// @param device 当前连接的设备
/// @param callback 结果回调
- (void)disconnectDevice:(QNBleDevice *)device callback:(QNResultCallback)callback;

/// 获取SDK的当前设置情况
- (QNConfig *)getConfig;

/// 根据提供的kg数值的体重，转化为指定单位的数值
/// @param weight 默认单位的重量（KG）
/// @param unit  KG、LB、JIN、ST、STLB 为体脂秤单位 (不支持ST的转换，查询文档获取相关转化方法)
- (double)convertWeightWithTargetUnit:(double)weight unit:(QNUnit)unit;

/// 设置用户秤秤端是否测脂
/// @param state 开关状态
/// @param longTerm 是否长期有效
/// @param callback 结果的回调
- (void)setFatMeasurementSwitch:(BOOL)state longTerm:(BOOL)longTerm callback:(QNResultCallback)callback;

/// 设置用户秤进入抱婴模式
/// @param state 开关状态
/// @param callback 结果的回调
- (void)setBabyCarryingModelSwitch:(BOOL)state callback:(QNResultCallback)callback;

@end


//
//  InterfaceController.m
//  QNDeviceSDKWatch WatchKit Extension
//
//  Created by sumeng on 2022/8/4.
//  Copyright © 2022 Yolanda. All rights reserved.
//

#import "InterfaceController.h"
#import <QNDeviceSDK_watchos/QNBleApi.h>

@interface InterfaceController ()<QNBleStateListener,QNBleDeviceDiscoveryListener,QNBleConnectionChangeListener,QNScaleDataListener>
{
    QNBleApi *_bleApi;
}
@end


@implementation InterfaceController

- (void)awakeWithContext:(id)context {
   
    _bleApi = [QNBleApi sharedBleApi];
    _bleApi.bleStateListener = self;
    _bleApi.discoveryListener = self;
    _bleApi.connectionChangeListener = self;
    _bleApi.dataListener = self;
}

- (void)onBleSystemState:(QNBLEState)state {
    NSLog(@"系统蓝牙状态： %ld",state);
    [[QNBleApi sharedBleApi] startBleDeviceDiscovery:^(NSError *error) {
        
    }];
}

- (void)onStartScan {
    
}

- (void)onDeviceDiscover:(QNBleDevice *)device {
    
    if (![device.mac isEqualToString:@"D8:0B:CB:52:4E:61"] && ![device.mac isEqualToString:@"A8:48:FA:35:8F:AE"]) {
        return;
    }
    
    NSLog(@"发现设备，mac = %@",device.mac);
    QNUser *user = [[QNUser alloc] init];
    user.userId = @"1234";
    user.height = 170;
    user.gender = @"male";
    user.birthday = [[NSDate date] initWithTimeIntervalSince1970:967022585];
    [_bleApi connectDevice:device user:user callback:^(NSError *error) {
        
    }];
}

- (void)onConnectError:(QNBleDevice *)device error:(NSError *)error {
    NSLog(@"设备链接失败，mac = %@",device.mac);
}

- (void)onConnected:(QNBleDevice *)device {
    NSLog(@"设备链接成功，mac = %@",device.mac);
}

- (void)onConnecting:(QNBleDevice *)device {
    NSLog(@"设备正在链接，mac = %@",device.mac);
}

- (void)onDisconnected:(QNBleDevice *)device {
    NSLog(@"设备断开链接，mac = %@",device.mac);
}

- (void)onDisconnecting:(QNBleDevice *)device {
    NSLog(@"设备正在断开链接，mac = %@",device.mac);
}

- (void)onServiceSearchComplete:(QNBleDevice *)device {
    
}

- (void)onGetElectric:(NSUInteger)electric device:(QNBleDevice *)device {
    
}

- (void)onGetScaleData:(QNBleDevice *)device data:(QNScaleData *)scaleData {
    QNScaleItemData* bodyFatRate = [scaleData getItem:QNScaleTypeBodyFatRate];
    QNScaleItemData* BMI = [scaleData getItem:QNScaleTypeBMI];
    NSLog(@"收到测量数据，体重 = %0.2f，BMI = %0.1f, 体脂 = %0.1f",scaleData.weight,BMI.value,bodyFatRate.value);
}

- (void)onGetStoredScale:(QNBleDevice *)device data:(NSArray<QNScaleStoreData *> *)storedDataList {
    NSLog(@"存储数据数量： %ld",storedDataList.count);
}

- (void)onGetUnsteadyWeight:(QNBleDevice *)device weight:(double)weight {
    NSLog(@"收到实时数据，体重 = %0.2f",weight);
}

- (void)onScaleEventChange:(QNBleDevice *)device scaleEvent:(QNScaleEvent)scaleEvent {
    
}

- (void)onScaleStateChange:(QNBleDevice *)device scaleState:(QNScaleState)state {
    
}


- (void)onBroadcastDeviceDiscover:(QNBleBroadcastDevice *)device {
    
}

- (void)onStopScan {
    
}

- (void)willActivate {
    // This method is called when watch view controller is about to be visible to user
}

- (void)didDeactivate {
    // This method is called when watch view controller is no longer visible
}

@end




//
//  SYCoreManager.h
//  SYCore
//
//  Created by xiong fa on 2020/6/11.
//  Copyright © 2020 nil. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SYCoreConfig.h"

//share状态改变通知，如果关系这部分状态改变，可以添加对应通知
#define SYCoreShareStatusChange         @"SYCoreShareStatusChange"
@interface SYCoreManager : NSObject
+ (SYCoreManager*)shared;

/*
 */
- (void)initSdkWithAppID:(NSString*)appid CallBack:(SYShareRequestSuccessClosure)callback;
- (void)unInitSdk;
@end


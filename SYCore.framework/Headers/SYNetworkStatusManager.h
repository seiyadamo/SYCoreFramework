//
//  SYNetworkStatusManager.h
//  SYCore
//
//  Created by Tong on 2020/12/5.
//  Copyright © 2020 nil. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum : NSInteger {
    NotReachable = 0,
    ReachableViaWiFi,
    ReachableViaWWAN
} NetworkStatus;

//网络状态改变通知
#define SYNetworkStatusNotification     @"SYNetworkStatusNotification"

@interface SYNetworkStatusManager : NSObject
@property (nonatomic, assign, readonly) NetworkStatus netStatus;

+ (SYNetworkStatusManager*)shared;
@end



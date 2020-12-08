//
//  SYCoreConfig.h
//  SYCore
//
//  Created by hongfa xiong on 2020/7/10.
//  Copyright © 2020 nil. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "SYCoreCommentModel.h"

typedef enum : NSUInteger {
    SYShareRequestError     = 0,
    SYShareRequestSuccess   = 1
} SYShareRequestStatus;

typedef void(^SYShareRequestSuccessClosure)(SYShareRequestStatus);

#ifdef DEBUG
    #define SYLog(...)  NSLog(__VA_ARGS__)
#else
    #define SYLog(...)
#endif

#define SYLogErr(...)   NSLog(__VA_ARGS__)

@interface SYCoreConfig : NSObject
@property (nonatomic, strong) NSString              *appid;

/*
 订阅产品id，需要在初始化的时候，设置值
*/
@property (nonatomic, strong) NSArray               *productIdentifiers;

/*
 订阅校验密钥，需要在初始化的时候，设置值
 */
@property (nonatomic, strong) NSString              *subscriptionSecretKey;

/*
 评论model,不为空，需要跳转评论
 */
@property (nonatomic, strong) SYCoreCommentModel    *commentModel;

/*
 更新model,不为空，表示需要做推广跳转---- 跳转app store
 */
@property (nonatomic, strong) SYCoreUpdateModel     *updateModel;

/*
 banner 页面推广，主要用于应用内跳转或者跳转第三方界面，
 需要根据type类型做相应动作
 */
@property (nonatomic, strong) NSArray<SYCoreBannerADModel*>               *bannerModels;

//价格显示透明度设置     后台json字段-PA    默认为1
@property (nonatomic, assign) CGFloat               priceAlpha;

//价格字体大小          后台json字段-PFS   默认为-1, 表示不需要设置
@property (nonatomic, assign) CGFloat               priceFont;

//订阅按钮文案          后台json字段-BSBT  默认""
@property (nonatomic, strong) NSString              *beginSubscription;

//控制订阅价格描述文字    后台json字段-GST   默认""
@property (nonatomic, strong) NSString              *gentingSubcscriptionString;

//控制订阅按钮与订阅描述文字之间间距    后台json字段-BP  默认-1表示不需要设置
@property (nonatomic, assign) CGFloat               spaceWithBtn;

//隐藏恢复以及取消订阅界面按钮    后台json字段-BBH  默认为YES-表示显示，NO-表示隐藏
@property (nonatomic, assign) BOOL                  backBtnHide;

//订阅失败或者取消订阅是否调整主界面   后台json字段-IGHVC  默认为YES
@property (nonatomic, assign) BOOL                  isGoHomeVC;

//订阅周期控制  后台json字段-ST  默认-1
//0表示周、1表示月、2表示年、3表示永久、4表示季度、5表示消耗型购买，可购买多次 6表示无订阅 -1表示不需要关注
@property (nonatomic, assign) NSInteger             subscriptionType;

// 游戏变量  暂时没用起来
@property (nonatomic, strong) NSString *aj_Address;

//share状态 请求成功时为YES  否则为NO
@property (nonatomic, assign) BOOL shareState;

+ (SYCoreConfig *)manager;
@end

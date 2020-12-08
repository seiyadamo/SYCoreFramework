//
//  SYHttpManager.h
//  SYCore
//
//  Created by hongfa xiong on 2020/7/9.
//  Copyright © 2020 nil. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <StoreKit/StoreKit.h>

NS_ASSUME_NONNULL_BEGIN
@protocol SYCoreIAPManagerDelegate <NSObject>
/*
 *获取产品信息回调
 */
-(void)SY_IAPManagerDidReceiveProducts:(NSDictionary *)productsDic;

/*
* 订阅内购成功回调
*/
-(void)SY_IAPManagerSubscribtionSuccessd:(NSString *)productId;

/*
* 内购失败回调。（包含订阅和一次买断型）
*/
-(void)SY_IAPManagerSubscrintionFail:(NSString *)productId;

/*
* 恢复购买回调
*/
-(void)ff_IAPManagerSubscribtionRestoreSuccess:(NSString *)productId;

/*
 * 恢复购买失败
 */
-(void)ff_IAPManagerSubscribtionRestoreFail:(NSString *)productId;
@end

@interface SYCoreIAPManager : NSObject
@property (nonatomic, weak) id<SYCoreIAPManagerDelegate> delegate;

/*
 *缓存订阅产品信息
 */
@property (nonatomic,strong, readonly) NSDictionary     *productDict;

/*
 * 订阅性内购id 数组
 */
@property (nonatomic, strong, readonly) NSArray         *productIds;

/*
 校验密钥
 */
@property (nonatomic, strong, readonly) NSString        *subscriptionSecretKey;
+ (SYCoreIAPManager *)manager;

/*
 *请求商品
*/
- (void)requestProductsInfo;

/*
 *购买，发起购买请求后，如果订阅成功，用户不需要自己在进行额外订阅状态保存，单例中
 已经有保存状态，判断是否购买，只需关注subscriptionStatus 状态即可
 */
- (void)buyProduct:(SKProduct *)product;

/*
 *恢复购买
 */
- (void)restorePurchase;
@end

NS_ASSUME_NONNULL_END

//
//  SYCoreCommentModel.h
//  SYCore
//
//  Created by hongfa xiong on 2020/7/13.
//  Copyright © 2020 nil. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SYCoreCommentModel : NSObject
@property (nonatomic, strong) NSString      *title;
@property (nonatomic, strong) NSString      *content;
@property (nonatomic, strong) NSString      *cancelBtnStr;
@property (nonatomic, strong) NSString      *confirmBtnStr;

//不直接使用YYModel 是为了避免与用户其他地方使用有冲突
- (instancetype)initWithDictionary:(NSDictionary*)dict;
@end

//用于更新或者强制推广其他app
@interface SYCoreUpdateModel : NSObject
@property (nonatomic, strong) NSString      *title;
@property (nonatomic, strong) NSString      *content;
@property (nonatomic, strong) NSString      *cancelBtnStr;
@property (nonatomic, strong) NSString      *confirmBtnStr;
@property (nonatomic, strong) NSString      *link;

//不直接使用YYModel 是为了避免与用户其他地方使用有冲突
- (instancetype)initWithDictionary:(NSDictionary*)dict;
@end

@interface SYCoreBannerADModel : NSObject
@property (nonatomic, assign) NSInteger     type;
@property (nonatomic, strong) NSString      *image;
@property (nonatomic, strong) NSString      *linkUrl;
@end

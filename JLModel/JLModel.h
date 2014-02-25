//
//  JLModel.h
//  JLModel
//
//  Created by 전수열 on 13. 10. 10..
//  Copyright (c) 2013년 MyFoodList. All rights reserved.
//

#import <Foundation/Foundation.h>

#define Model(__className) \
@protocol __className <NSObject>\
@end

#define Integer @property (nonatomic, strong) NSNumber *
#define Float Integer
#define Boolean Integer
#define String @property (nonatomic, strong) NSString *
#define Date @property (nonatomic, strong) NSDate *
#define Array @property (nonatomic, strong) NSMutableArray *
#define ToMany(__className) @property (nonatomic, strong) NSMutableArray<__className> *
#define ToOne(__className) @property (nonatomic, strong) __className *

@interface Property : NSObject

@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) Class type;
@property (nonatomic, strong) NSArray *protocols;
@property (nonatomic, assign) BOOL readonly;

@end


@interface JLModel : NSObject

@property (nonatomic, strong) id id;

@property (nonatomic, readonly) NSArray *properties;

+ (id)modelWithID:(id)id;
+ (id)modelWithDictionary:(NSDictionary *)dictionary;
+ (void)delete:(JLModel *)model;

- (id)initWithDictionary:(NSDictionary *)keyedValues;
- (void)clear;
- (NSDate *)parseDateString:(NSString *)dateString forField:(NSString *)field;

@end

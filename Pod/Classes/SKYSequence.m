//
//  SKYSequence.m
//  SKYKit
//
//  Copyright 2015 Oursky Ltd.
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//

#import "SKYSequence.h"

@implementation SKYSequence

+ (instancetype)sequence
{
    return [[SKYSequence alloc] init];
}

- (instancetype)init
{
    return [super init];
}

#pragma NSCoding

- (instancetype)initWithCoder:(NSCoder *)decoder
{
    return [SKYSequence sequence];
}

- (void)encodeWithCoder:(NSCoder *)encoder
{
}

#pragma NSCopying
- (id)copyWithZone:(NSZone *)zone
{
    return [SKYSequence sequence];
}

@end

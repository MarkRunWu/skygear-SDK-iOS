//
//  SKYQueryUsersOperation.h
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

#import "SKYOperation.h"

#import "SKYRelation.h"

typedef enum : NSUInteger {
    SKYUserDiscoveryMethodEmail = 0,
    SKYUserDiscoveryMethodRelation = 1,
} SKYUserDiscoveryMethod;

/* clang-format off */
/**
 <SKYQueryUsersOperation> is a subclass of <SKYOperation> that implements user query
 in Ourd. Use this operation to query other user in the same application.
 */
__deprecated @interface SKYQueryUsersOperation : SKYOperation

/**
 Returns an operation object that discovers users by their email.
 */
+ (instancetype)discoverUsersOperationByEmails:(NSArray /* NSString */ *)emails;
/* clang-format on */

/**
 Returns an operation object that queries users by their relation to the current user.
 */
+ (instancetype)queryUsersOperationByRelation:(SKYRelation *)relation;

/**
 Returns an operation object that queries users by their relation to the current user with the
 specified direction.
 */
+ (instancetype)queryUsersOperationByRelation:(SKYRelation *)relation
                                    direction:(SKYRelationDirection)direction;

/**
 Initializes and returns a email-based user discovery operation object.

 @param emails An array of emails to be used for user discovery.
 */
- (instancetype)initWithEmails:(NSArray /* NSString */ *)emails NS_DESIGNATED_INITIALIZER;

/**
 Initializes and returns a relation-based user query operation object.

 @param relation The relation object to be used for user discovery.
 */
- (instancetype)initWithRelation:(SKYRelation *)relation;

/**
 Initializes and returns a relation-based user query operation object with relation direction
 specified.

 @param relation The relation object to be used for user discovery.
 */
- (instancetype)initWithRelation:(SKYRelation *)relation
                       direction:(SKYRelationDirection)direction NS_DESIGNATED_INITIALIZER;

/**
 Sets or returns an array of emails to be used to discover users.

 The value in this property is used only if the discoveryMethod is set to
 SKYUserDiscoveryMethodEmail; otherwise, it is ignored.
 */
@property (nonatomic, copy) NSArray /* NSString */ *emails;

/**
 Sets or returns the relation object used to query for users.

 The value in this property is used only if the discoveryMethod is set to
 SKYUserDiscoveryMethodRelation; otherwise, it is ignored.
 */
@property (strong, nonatomic) SKYRelation *relation;

/**
 Sets or returns the relation direction used for query. Defaults to SKYRelationDirectionOutgoing.

 The value in this property is used only if the discoveryMethod is set to
 SKYUserDiscoveryMethodRelation or the relation assigned to this operation is directional (like
 follow); otherwise, it is ignored.
 */
@property (nonatomic, assign) SKYRelationDirection relationDirection;

/**
 The method used to discover users. Assigned at creation time. (read-only)
 */
@property (nonatomic, readonly, assign) SKYUserDiscoveryMethod discoveryMethod;

/**
 Returns the nubmer of all matching records if the original query requested this info.
 */
@property (nonatomic, readonly) NSUInteger overallCount;

/**
 Sets or returns a block to be called when a user fetch operation completes for
 a <SKYUser>.

 This block is not called when the entire operation results in an error.
 */
@property (nonatomic, copy) void (^perUserCompletionBlock)(SKYUser *user);

/**
 Sets or returns a block to be called when the entire operation completes. If
 the entire operation results in an error, the <NSError> will be specified.

 This block reports an error with code SKYErrorPartialFailure if the operation disocvers users by
 emails and no users can be found by some of the emails. The userInfo dictionary of the error
 contains a SKYPartialEmailsNotFoundKey key, whose value is a NSArray object containing all emails
 that no users can be found.
 */
@property (nonatomic, copy) void (^queryUserCompletionBlock)
    (NSArray<SKYUser *> *users, NSError *operationError);

@end

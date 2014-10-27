//
//  CDSessionManager.h
//  AVOSChatDemo
//
//  Created by Qihe Bian on 7/29/14.
//  Copyright (c) 2014 AVOS. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CDCommon.h"

@interface CDSessionManager : NSObject <AVSessionDelegate, AVSignatureDelegate, AVGroupDelegate>
+ (instancetype)sharedInstance;
//- (void)startSession;
//- (void)addSession:(AVSession *)session;
//- (NSArray *)sessions;
- (NSArray *)chatRooms;
- (void)addChatWithPeerId:(NSString *)peerId;
- (AVGroup *)joinGroup:(NSString *)groupId;
- (void)startNewGroup:(AVGroupResultBlock)callback;
- (void)sendMessage:(NSString *)message toPeerId:(NSString *)peerId;
- (void)sendMessage:(NSString *)message toGroup:(NSString *)groupId;
- (void)sendAttachment:(AVFile *)object type:(NSString*)type toPeerId:(NSString *)peerId;
- (void)sendAttachment:(AVFile *)object type:(NSString*)type toGroup:(NSString *)groupId;
- (NSArray *)getMessagesForPeerId:(NSString *)peerId;
- (NSArray *)getMessagesForGroup:(NSString *)groupId;
- (void)getHistoryMessagesForPeerId:(NSString *)peerId callback:(AVArrayResultBlock)callback;
- (void)getHistoryMessagesForGroup:(NSString *)groupId callback:(AVArrayResultBlock)callback;
- (void)clearData;

- (void)registerUsers:(NSArray*)users;
- (void)registerUser:(User*)user;
- (User *)lookupUser:(NSString*)userId;
@end

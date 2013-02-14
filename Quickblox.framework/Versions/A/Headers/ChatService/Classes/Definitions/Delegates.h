//
//  Delegates.h
//  QBChat
//
//  Copyright 2012 QuickBlox team. All rights reserved.
//

#import <Foundation/Foundation.h>

#define kStopVideoChatCallPurpose_OpponentDidNotAnswer @"kStopVideoChatCallPurpose_OpponentDidNotAnswer"
#define kStopVideoChatCallPurpose_Manually @"kStopVideoChatCallPurpose_Manually"

@protocol QBVideoChatDelegate <NSObject>

@optional

-(void) chatDidReceiveCallRequestFromUser:(NSUInteger)userID conferenceType:(enum QBVideoChatConferenceType)conferenceType;
-(void) chatCallUserDidNotAnswer:(NSUInteger)userID;
//
-(void) chatCallDidAcceptByUser:(NSUInteger)userID;
-(void) chatCallDidRejectByUser:(NSUInteger)userID;
//
-(void) chatCallDidStopByUser:(NSUInteger)userID purpose:(NSString *)purpose;
//
//-(void) chatCallDidStartWithUser:(NSUInteger)userID;
//-(void) chatCallDidEndWithUser:(NSUInteger)userID;
//
- (UIImageView *) viewToRenderOpponentVideoStream;
- (UIImageView *) viewToRenderOwnVideoStream;

@end

/**
 QBChatDelegate protocol definition
 This protocol defines methods signatures for callbacks. Implement this protocol in your class and
 set QBChat.delegate to your implementation instance to receive callbacks from QBChat
 */

@protocol QBChatDelegate <QBVideoChatDelegate>

@optional


#pragma mark -
#pragma mark Base IM

/**
 didLogin fired by QBChat when connection to service established and login is successfull
 */
- (void)chatDidLogin;

/**
 didNotLogin fired when login process did not finished successfully
 */
- (void)chatDidNotLogin;

/**
 didNotSendMessage fired when message cannot be send to offline user
 
 @param message Message passed to sendMessage method into QBChat
 */
- (void)chatDidNotSendMessage:(QBChatMessage *)message;

/**
 didReceiveMessage fired when new message was received from QBChat
 
 @param message Message received from QBChat
 */
- (void)chatDidReceiveMessage:(QBChatMessage *)message;

/**
 didFailWithError fired when connection error occurs
 
 @param error Error code from QBChatServiceError enum
 */
- (void)chatDidFailWithError:(int)error;

/**
 Called in case receiving presence
 */
- (void)chatDidReceivePresenceOfUser:(NSUInteger)userID type:(NSString *)type;


#pragma mark -
#pragma mark Rooms

/**
 Called in case receiving list of avaible to join rooms. Array rooms contains jids NSString type
 */
- (void)chatDidReceiveListOfRooms:(NSArray *)rooms;

/**
 Fired when room was successfully created
 */
- (void)chatRoomDidCreate:(QBChatRoom*)room;

/**
 Called when room received message. It will be fired each time when room receiving message from any user
 */
- (void)chatRoomDidReceiveMessage:(QBChatMessage *)message fromRoom:(NSString *)roomName;

/**
 Fired when you did enter to room
 */
- (void)chatRoomDidEnter:(NSString *)roomName;

/**
 Called when you didn't enter to room
 */
- (void)chatRoomDidNotEnter:(NSString *)roomName error:(NSError *)error;

/**
 Fired when you did leave room
 */
- (void)chatRoomDidLeave:(NSString *)roomName;

/**
 Called in case changing online users  
 */
- (void)chatRoomDidChangeOnlineUsers:(NSArray *)onlineUsers room:(NSString *)roomName;

/**
 Called in case receiving list of users who can join room
 */
- (void)chatRoomDidReceiveListOfUsers:(NSArray *)users room:(NSString *)roomName;

@end
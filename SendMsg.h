//
//  SendMsg.h
//  AutoSendQQMsg
//
//  Created by ShawnJiFreeMan on 2018/11/7.


#import <UIKit/UIKit.h>
#import <objc/runtime.h>



@interface QQMessageModel : NSObject


@property(nonatomic) int messageSendType;
@property(nonatomic) int messageSeq;
@property(nonatomic) long long messageRandom;
@property(nonatomic) unsigned long long msgSessionType;
@property(nonatomic) _Bool loadingState;
@property(retain, nonatomic) NSString *syncUin;
@property(nonatomic) unsigned int roamTime;
@property(nonatomic) unsigned int roamRandom;
@property(retain, nonatomic) NSString *actionUrl;
@property(nonatomic) BOOL actionType;
@property(nonatomic) long long msgUid;
@property(nonatomic) long long msgSeq;
@property(nonatomic) int msgLen;
@property(nonatomic) int msgID;
@property(nonatomic) _Bool isSelfImage;
@property(nonatomic) _Bool inOut;
@property(nonatomic) int read;
@property(nonatomic) unsigned long long time;
@property(nonatomic) int msgType;
@property(retain, nonatomic) NSString *groupCode;
@property(nonatomic) int msgVia;
@property(retain, nonatomic) id content; 
+ (unsigned long long)randomToUid:(unsigned int)arg1;
@end


@interface CIMEngine : NSObject
+ (id)GetInstance;
- (int)GetServerTimeDiff;
@end

@interface QQBaseChatModel : NSObject
@end

@interface QQPlatform : NSObject
+ (id)sharedPlatform;
- (id)QQServiceCenter;
@end

@interface QQServiceCenter : NSObject
- (id)C2CMultiTableDB;
@end

@interface C2CDBService_MultiTable : NSObject
- (_Bool)insertSendMessage:(id)arg1;
@end
@interface QQAIOModel : NSObject
+ (id)createAIOModelWithMessageModel:(id)arg1;
@end
@interface QQAIOMsgModel : QQAIOModel
@end

@interface QQMsgSyncManager : NSObject
+ (id)sharedInstance;
- (unsigned int)getC2CSendMessageRandom;
- (unsigned short)getC2CSendMessageSeq:(long long)arg1;
@end

@interface QQChatListManager : NSObject
- (void)addMessage:(id)arg1;
@end
@interface QQPbMsgSenderBase : NSObject
- (int)SendPbShakeWindowMessage:(id)arg1;
- (int)sendPbTextMessage:(id)arg1 shareAppInfo:(id)arg2;

@end
@interface QQF2FMessageSender : QQPbMsgSenderBase
+ (id)getInstance;

@end

@interface QServiceFactory : NSObject
+ (id)sharedFactory;
- (id)getMessageListService;
@end



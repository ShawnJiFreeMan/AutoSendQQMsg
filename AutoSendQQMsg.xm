

#import "SendMsg.h"


%hook QQChatViewTable
- (void)viewDidAppear{
    %orig;
    UITapGestureRecognizer *tap = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(sendTxtMsg)];
    tap.numberOfTapsRequired = 2;
    [self addGestureRecognizer:tap];
}
%new
-(void)sendTxtMsg{
    NSLog(@"开始发送文本消息////");
    QQMessageModel *msgModel = [[%c(QQMessageModel) alloc] init];
    //这里是消息的内容
    [msgModel setContent:@"AutoSendMsg"];
    [msgModel setLoadingState:YES];
    long long sendTime = [[%c(CIMEngine) GetInstance] GetServerTimeDiff];
    [msgModel setTime:sendTime];
    [msgModel setInOut:NO];
    [msgModel setRead:0];
    [msgModel setMsgType:0];
    [msgModel setMsgState:1];
    //这里是接收人的QQ号
    [msgModel setUin:@""];
    unsigned int msgRadom = [[%c(QQMsgSyncManager) sharedInstance] getC2CSendMessageRandom];
    [msgModel setMessageRandom:msgRadom];
    unsigned short msgSeq = [[%c(QQMsgSyncManager) sharedInstance] getC2CSendMessageSeq:[[msgModel uin] longLongValue]];
    [msgModel setMsgSeq:msgSeq];
    [msgModel setMsgUid:[%c(QQMessageModel) randomToUid:msgRadom]];
    QQPlatform *platform = [%c(QQPlatform) sharedPlatform];
    QQServiceCenter *serviceCenter = [platform QQServiceCenter];
    C2CDBService_MultiTable *multiTablwDB = [serviceCenter C2CMultiTableDB];
    [multiTablwDB insertSendMessage:msgModel];
    QQChatListManager *listManager = [[%c(QServiceFactory) sharedFactory] getMessageListService];
    [listManager addMessage:msgModel];
    [[%c(QQF2FMessageSender) getInstance] sendPbTextMessage:msgModel shareAppInfo:nil];
}
%end



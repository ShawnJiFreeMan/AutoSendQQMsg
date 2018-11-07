 iOS逆向_QQ自动发送消息
===================================


涉及的工具及软件版本
-----------------------------------
reveal、IDA Pro、class-dump、QQ(7.1.0PP助手上下载的脱壳版,当然appStore下载的QQ需要自己砸壳)
注:本文不涉及软件安装

正题开始
-----------------------------------
### 🔥1、准备工作:砸壳 、导出ipa到电脑 、class-dump导出头文件、IDA加载可执行文件
      clutch砸壳:
      
      1、将下载好的clutch文件用pp助手copy到手机/usr/bin/目录下
      2、ssh到越狱手机上:ssh root@你手机的ip
      3、clutch -i  //终端上将会列出手机上所有安装的未砸壳的app并带有序号
      4、根据你要砸壳的app序号砸壳即可:clutch -d 序号
      5、砸壳结束终端将会显示砸壳后的ipa存放的目录，用pp助手到相应目录将ipa导出即可
      
      class-dump导出头文件:
      1、右击砸壳后的ipa包,打开方式-->归档实用工具-->解压后可以看到一个payload文件夹
      2、cd到payload目录下: class-dump -H QQ.app -o QQ  //在payload目录下会生成一个QQ目录即为头文件
      
      IDA加载可执行文件:
      右击payload内QQ.app文件显示包内容,将同项目名的可执行文件拖入IDA加载
      
      END:准备工作完毕。
        

### 🔥2、从界面表现入手,寻找分析的一个切入点
    1、手机打开QQ聊天室页面,电脑打开reveal，查看聊天页面的控制器:QQChatViewController
   ![reveal.png](https://github.com/ShawnJiFreeMan/AutoSendQQMsg/tree/master/image/reveal.png)

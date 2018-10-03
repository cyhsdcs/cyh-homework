# 初次使用Construct2写鼠标操作型射击游戏

## 引言
老师突然叫做个游戏出来，明明才上了两节课。。。做游戏听起来那么高大上和我这刚入门的菜鸡完全对不上号呀，没有办法，我硬着头皮做了整整一个下午，虽然没我想象中那么难（毕竟只是做了一个4399都不会有的小游戏），但也不会简单。接下来就是我的操作流程

## 游戏预览
![](http://thyrsi.com/t6/380/1538576625x-1404775605.gif)

## 开发前准备

1. 到官方网站上下载并安装Construct2软件。

2. 在进行游戏制作前首先对自己想要做的游戏有一个初步的构思和规划，然后再收集素材，我就直接使用了官网教程的素材。。。

## 界面介绍

### Layout

这是游戏画面的布局，白框就是游戏的整个活动范围，而虚线框内就是显示屏上显示的画面，它们的大小都可以通过properties栏进行调整。
![](https://img-blog.csdn.net/20171012203902151?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvc3lzdV9saWFuZ3dq/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

### Properties

在这里可以对所有添加对象的属性，包括对背景和游戏画面的尺寸进行修改，而对于对象比较重要的一个特性Behaviour也可以在这里找到。
![](https://img-blog.csdn.net/20171012204825013?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvc3lzdV9saWFuZ3dq/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

### Layers

层，类似于ps里的图层，每一个图层间都是平行的关系，可以在点击“加号”进行添加Layer，每个Layer可以单独锁定起来，可以防止在修改其他Layer对象的时候把某一对象误删了或误改了，另外不同的Layer有不同的显示级别，Layer越高，就放在越顶层，而下层的对象有可能被上层的对象所遮挡（这个应该是和ps类似的）。
![](https://img-blog.csdn.net/20171012205441831?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvc3lzdV9saWFuZ3dq/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

### Objects

对象，所添加对象都会出现在这里。
1[](https://img-blog.csdn.net/20171012210252278?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvc3lzdV9saWFuZ3dq/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

### Event sheet

事件表，在这里给对象添加的每一个事件可以赋予游戏对象一个功能。
![](https://img-blog.csdn.net/20171012210510946?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvc3lzdV9saWFuZ3dq/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

## 进行开发

### 新建项目

打开Construct2并新建一个项目。

### 修改游戏地图尺寸

在Properties一栏里找到Layout size，我按照教程将其修改为800,800。

### 添加背景

在Object的区域点击鼠标右键，找到Insert New object，然后找到Tiled Background，可以修改它的名称，然后点击插入，跟在鼠标指针变为一个”加号”，点击随意空白位置，打开一个窗口，然后点击左上角打开一张图片作为背景图，其后关闭窗口即可。添加完成后可以自己对背景图大小进行修改以让其与窗口大小相容。

### 添加其他对象

同样在Object的区域点击鼠标右键，找到Insert New object，然后找到Sprite进行添加其他对象。我添加了player，monster，explosion和bullet。

### 让player随键盘移动

这一步超级麻烦，但最后还是弄成了，player不仅可以随键盘往各个方向，头还永远向着鼠标方向。

### 让player发射子弹
在player头部设置了一个虚拟点，让子弹从头部发出而不是从player的中心发出

### 添加碰撞事件

让子弹碰撞的时候同时消失，并产生爆炸，让怪物拥有五点生命值（既被子弹击中五次才会爆炸消失）
让怪物碰到玩家时玩家会死亡（hhh，不然可以无限刷分多无聊）

### 零零散散的步骤

主要是对游戏的修饰，让怪物变成八个并且飞出区域就会自动瞄准玩家再飞回来；修改了怪物和子弹的飞行速度

### 添加得分情况

在Event sheet处右击空白地方，点击Add global variable添加全局变量，命名为score。 
在一个新的Layer上添加一个新的object：Text，修改它的颜色、字号和位置。 

## 游戏做成功啦！

## 结语

完全按照教程一步步来的！中间出错了一次导致前功尽弃了，重新做了一遍，做好了之后还是很有成就感的。附教程地址：https://www.scirra.com/tutorials/37/beginners-guide-to-construct-2/page-6
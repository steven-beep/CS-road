# Git

> Git是全球使⽤最为⼴泛的分布式版本管理⼯具，Markdown则是开发⼯程师⽤的⽐较多的、轻量的、易读写的⽂档标记语⾔。能熟练的使⽤Git和Markdown，养成版本分⽀管理的良好习惯，编写规范的接⼝说明、部署⽂档和⽤户⼿册，是专业⼯程师成⻓道路上的必经节点

## 使用Github
### 目的
借助 github 托管项目代码
### 基本概念
### 仓库（Repository）
仓库，其实就是你的项目，你想在GitHub上开源一个项目，那就必须创建一个仓库；多个开源项目就必须创建对应个数的仓库与之对应
### 收藏（Star）
收藏即是被收藏该项目的人数，方便下次查看，该收藏“含金量”很高！
### 复制克隆项目（Fork）
复制克隆项目,这个字面意思不太好理解，类似于**转载**
![在这里插入图片描述](https://use-typora.oss-cn-hangzhou.aliyuncs.com/20210606015803224.png)

### 发起请求（Pull Reguest）
发起请求,就是克隆完对方的项目，并对它进行修改，出现new item,可以向原仓库发起请求，原项目如果同意，将修改原项目
![在这里插入图片描述](https://use-typora.oss-cn-hangzhou.aliyuncs.com/20210606020635574.png)
### 关注（Watch）
关注，就很好理解，但是在github中是关注某个项目，关注那个项目的更新
### 事务卡片（Issue）
事务卡片，发现代码的BUG，需要讨论时候使用
### 主页
#### Github主页
账户创建成功或点击网址导航栏github图标都可进入GitHub主页

![在这里插入图片描述](https://use-typora.oss-cn-hangzhou.aliyuncs.com/2021060602300846.png)
#### 仓库主页
仓库主要显示项目的信息,如项目代码，版本，收藏关注等
#### 个人主页
个人信息，头像，个人简介等等信息

### 注册Github账号
[官方网址](https://github.com/explor)
![](https://use-typora.oss-cn-hangzhou.aliyuncs.com/20210606151811743.png)
###   创建仓库
![在这里插入图片描述](https://use-typora.oss-cn-hangzhou.aliyuncs.com/20210606153804214.png)

## Git 安装和使用
### 目的
通过git管理github托管项目代码
### 下载安装
[下载地址](http://git-scm.com/downloads)
[安装教程](https://www.cnblogs.com/xueweisuoyong/p/11914045.html)
## 本地仓库的操作
### Git工作流程
### Git工作区域
![在这里插入图片描述](https://use-typora.oss-cn-hangzhou.aliyuncs.com/20210617225104790.png)
### 向仓库中添加文件流程
![在这里插入图片描述](https://use-typora.oss-cn-hangzhou.aliyuncs.com/20210617231622229.png)
### Git初始化及仓库创建和操作
#### 基础信息设置

> 注意：该设置在github仓库主页显示谁提交了该文件

##### 1.设置用户名
**$ git config --global user.name '用户名'**
##### 2.设置用户名邮箱
**$ git config --global user.name '用户名邮箱'**
##### 3.查看设置
**$ git config --list**
#### 初始化一个新的Git仓库
##### 1.创建文件夹
**$ mkdir 文件名**
![在这里插入图片描述](https://use-typora.oss-cn-hangzhou.aliyuncs.com/20210618005309657.png)


##### 2.在文件内初始化git(创建git仓库)

> 初始化完可能你会疑惑这个和普通空文件有什么区别呢
> 进行如下操作

![在这里插入图片描述](https://use-typora.oss-cn-hangzhou.aliyuncs.com/20210618005839886.png)
发现区别了嘛小伙伴们！
![在这里插入图片描述](https://use-typora.oss-cn-hangzhou.aliyuncs.com/20210618005918377.png)


**$ cd test 
$ git init**

#### 向仓库添加文件
**$ touch a.java**
![在这里插入图片描述](https://use-typora.oss-cn-hangzhou.aliyuncs.com/20210618010306541.png)
联系上文我介绍的向仓库中添加文件流程，这里通过获得状态，告诉我们 add file
![在这里插入图片描述](https://img-blog.csdnimg.cn/2021061801060382.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0FsX3RhaXI=,size_16,color_FFFFFF,t_70)
这里我们添加到了暂存区，接下来添加到仓库（我没创建新仓库，我就不演示了）
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210618010757773.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0FsX3RhaXI=,size_16,color_FFFFFF,t_70)
#### 修改仓库的文件
打开a.java文件，可以在里面修改文件
**$ vi(vim) a.java**

#### 删除仓库文件
##### 删除工程目录的文件
**$ rm -rf 文件名**
##### 从Git暂存区删除文件
**$ git rm 文件名**



## 远程仓库的操作 

### Git 管理远程仓库
#### 目的
备份，实现代码共享集中化管理
#### 实现过程
**git push** 将本地仓库提交到远程
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210618140824302.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0FsX3RhaXI=,size_16,color_FFFFFF,t_70)
### Git 克隆操作
#### 目的
将远程仓库（Github对应的项目）复制到本地
#### 实现过程
**$ git clone 仓库地址** 
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210618141506498.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0FsX3RhaXI=,size_16,color_FFFFFF,t_70)

![在这里插入图片描述](https://img-blog.csdnimg.cn/20210618141816955.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0FsX3RhaXI=,size_16,color_FFFFFF,t_70)
**注意：下载如果出现以下错误**
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210618142107414.png)
**解决方法**
1.先执行下列命令
**$ git config --global http.postBuffer 5242880000**
然后
**再执行git pull或者 git clone 命令**
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210618142242669.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0FsX3RhaXI=,size_16,color_FFFFFF,t_70)



##  简单搭建个人网站

### Github 搭建网站
#### 个人站点 >> 新建仓库
**网址(强制)：https://用户名.github.io** 

#### 搭建步骤

> 注意：该网站只支持静态网页

1.新建仓库  >> 仓库名必须是 【用户名.github.io】
2.在创建下新建 index.html
![在这里插入图片描述](https://img-blog.csdnimg.cn/202106181502381.png)
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210618150301838.png)**
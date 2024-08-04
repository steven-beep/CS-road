# JavaSE  
## 概述

### Java诞生

> **Java**(英式发音[ˈʤɑːvə],美式发音[ˈʤɑvə])是一种广泛使用的计算机[编程语言](https://zh.wikipedia.org/wiki/程式設計語言).

1. 嵌入式系统的发展，c/c++在不同平台上的开发需要不同的编译器，然而创建编译器"费时费力"
2. 开发者研究开发一种可移植，跨平台的计算机语言
3. 1991 Oak的出现  ~~>  1995 更名为Java



### 开发Java语言的初衷

Java之所以被开发，是要达到以下五个目的：

​                            初衷                 <==>              语言特点

- 应当使用面向对象程序设计方法学    <==>  面向对象
- 应当允许同一程序在不同的计算机平台执行  <==>  平台无关性
- 应当包括内建的对计算机网络的支持  <==>   分布式
- 应当被设计成安全地执行远端代码  <==>  安全性
- 应当易于使用，并借鉴以前那些面向对象语言（如C++）的长处。 <==>  简单性，健壮性，高性能



### java语言特点

##### 概述图

![Java语言特点](https://use-typora.oss-cn-hangzhou.aliyuncs.com/Java%E8%AF%AD%E8%A8%80%E7%89%B9%E7%82%B9.png) 

#### 1. 面向对象

Java 是一种面向对象的语言，它对对象中的类、对象、继承、封装、多态、接口、包等均有很好的支持。使用 Java 语言开发程序，需要采用面向对象的思想设计程序和编写代码。

#### 2. 平台无关性

平台无关性的具体表现在Java 是“一次编写，到处运行“的语言，因此采用 Java 语言编写的程序具有很好的可移植性，而保证这一点的正是 Java 的虚拟机机制。在引入虚拟机之后，Java 语言在不同的平台上运行不需要重新编译。

![image-20211211145530665](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20211211145530665.png) 

#### 3. 简单性

Java 语言的语法与 C 语言和 C++ 语言很相近，使得很多程序员学起来很容易。对 Java 来说，它舍弃了很多 C++ 中难以理解的特性，如操作符的重载和多继承等，而且 Java 语言不使用指针，加入了垃圾回收机制，解决了程序员需要管理内存的问题，使编程变得更加简单。

#### 4. 编译与解释并存

Java 程序在 Java 平台运行时会被编译成字节码文件，然后可以在有 Java 环境的操作系统上运行。在运行文件时，Java 的解释器对这些字节码进行解释执行，执行过程中需要加入的类在连接阶段被载入到运行环境中。

Java即是编译型的，也是解释型语言，总的来说Java更接近解释型语言（补充:解释型语言：javascript,PHP,Java    编译型语言:c/c++）

**解释型语言和编译型语言的区别:**

解释性语言，编译后的代码，不能直接被机器执行,需要解释器来执行 ; 编译性语言,编译后的代码,可以直接被机器执行,c/c++

#### 5. 多线程

Java 语言是多线程的，这也是 Java 语言的一大特性，Java 支持多个线程同时执行，并提供多线程之间的同步机制。任何一个线程都有自己的 run() 方法，要执行的方法就写在 run() 方法体内。

#### 6. 分布式

Java 语言支持 Internet 应用的开发，在 Java 的基本应用编程接口中就有一个网络应用编程接口，它提供了网络应用编程的类库，包括 URL、URLConnection、Socket 等。Java 的 RIM 机制也是开发分布式应用的重要手段。

#### 7. 健壮性

Java 的强类型机制、异常处理、垃圾回收机制等都是 Java 健壮性的重要保证。

#### 8. 高性能

Java 的高性能主要是相对其他高级脚本语言来说的，随着 JIT（Just in Time）的发展，Java 的运行速度也越来越高。

#### 9. 安全性

Java 通常被用在网络环境中，为此，Java 提供了一个安全机制以防止恶意代码的攻击。除了 Java 语言具有许多的安全特性以外，Java 还对通过网络下载的类增加一个安全防范机制，分配不同的名字空间以防替代本地的同名类，并包含安全管理机制。



### Java虚拟机（JVM）

JVM是一个虚拟的计算机，具有指令集并使用不同的存储区域。负责执行指令，管理数据 内存 寄存器。

![preview](https://segmentfault.com/img/remote/1460000038620837/view) 

**JDK  JRE  JVM 关系**（重点）

![image-20211212195742515](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20211212195742515.png) 



### 编译与解释

![image-20211215170531770](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20211215170531770.png)

**在dos窗口运行 如 helloJava.java 的文件**

```java
// 编译 java
javac helloJava.java
// 解释 helloJava.class
java helloJava // 这里只需要类名，切记非 java helloJava.class
```

**源文件中代码注意事项**  

- 一个源文件中最多只能有一个被public修饰的类（可以没有），而非public修饰的类可以有无数个  

- 如果一个源文件中有被public修饰的类，则该类的名字必须和文件名相同 

- 主方法（程序入口 main）可以放在非public修饰的类  

- 一个源文件中含有多个类，通过编译会生成对应个数的字节码文件（字节码文件的名字 <==> 类名）

    ![image-20211215173945096](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20211215173945096.png) 

- 如果一个源文件中的类与类之间**没有存在联系**，可以在每一个类中使用主方法，由于最后生成不同的字节码文件，我们只需要通过java.exe工具将各个字节码加载到JVM虚拟机中进行解释执行

    ```java
    class java{
    	public static void main(String[] args){
    		System.out.println("helloworld~");
    	}
    }
    class person{
    	public static void main(String[] args){
    		System.out.println("person~");
    	}
    }
    class animal{
    	public static void main(String[] args){
    		System.out.println("animal~");
    	}
    }
    
    // 运行结果
    C:\Users\Ushop\Desktop\mess\textJava>java java
    helloworld~
    C:\Users\Ushop\Desktop\mess\textJava>java person
    person~
    C:\Users\Ushop\Desktop\mess\textJava>java animal
    animal~
    ```

    

### 转义字符

概述：\ 开头  表示接下这个字符是转义字符    比如：\n 中的n不在是字母n的含义

```java
public static void main(String[] args){
    /* 
    	转义字符  俗称：改变意思的字符
		\t : 一个制表符，起到对齐的功能 类似于tab的作用
		\\ : 一个\   文件路径通常表示是 C:\\Users\\Ushop\\Desktop\\mess\\textJava
		\n : 换行符
		\" : 一个"
		\' : 一个'
		\r : 一个回车，将光标移动到该行最前面，可能会引起覆盖的反作用 通常使用手法是： \r\n  == \n
				 例如"罗念笙like dog\r张洛融 ==> 显示内容:"张洛融"
	*/
    System.out.println("罗念笙\tlove\t张洛融");   // 运行结果： 罗念笙	love	张洛融
    System.out.println("\\");                    // 运行结果： \
    System.out.println("罗念笙\nlove\n张洛融");   // 运行结果：罗念笙 换行  love  换行 张洛融
    System.out.println("\"");                    // 运行结果： "
    System.out.println("\'");                     // 运行结果：'   
    System.out.println("罗念笙 like dog\r张洛融");  // 运行结果：张洛融
}
```



### 三种注释

#### **单行注释 && 多行注释**

注释的内容 不会被虚拟机JVM解释执行

```java
// 单行注释
/* 
   多
   行
   注
   释
 */
```

#### **文档注释**

注释内容可以被JDK提供的工具javadoc所解析，生成一套以网页文件形式体现的该程序的说明文档

![image-20211216211455670](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20211216211455670.png) 

**代码实现说明**

```java
/**
  * 文档注释
  * @author 罗念笙   -- 文档注释中的注解
  * @version 1.0    
  */
public class hello{
	public static void main(String[] args){
		System.out.println("helloworld~");
	}
}
/*
	笙式讲解：（下面的两行命令的区别如下图）
	        javadoc  doc文件                生成的网页文件存放自己的文件目录             文档注释的java文件
		1.  javadoc   -d       C:\\Users\\Ushop\\Desktop\\mess\\textJava\\javadoc      hello.java
		    javadoc  doc文件                生成的网页文件存放自己的文件目录          java文件中的文档注释中所用注解（带@）  文档注释的java文件
		2.  javadoc    -d      C:\\Users\\Ushop\\Desktop\\mess\\textJava\\javadoc2   -author -version                  hello.java
		
		我使用的编码类型是GB2312  在dos命令中无出现乱码的问题
		如果你使用IDEA编译器,默认是utf-8，添加  -encoding utf-8  （放在注解的位置前后）  java代码采用的是utf-8字符编码编写的
		添加 -charset utf-8       java doc html文件为utf-8字符编码
		
		为什么要说明是utf-8，java的编码不都是以utf-8为主的嘛？
		因为我是用的是dos命令窗口，要想显示中文得遵守GBK编码
*/
```

![image-20220328103509320](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220328103509320.png) 

#### **javadoc 标签**（文档注解）

**javadoc 工具软件识别以下标签：**

| ***\*标签\****          | ***\*描述\****                                               | ***\*示例\****                                               |
| ----------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| ***\*@author\****       | ***\*标识一个类的作者\****                                   | ***\*@author description\****                                |
| ***\*@deprecated\****   | ***\*指名一个过期的类或成员\****                             | ***\*@deprecated description\****                            |
| ***\*{@docRoot}\****    | ***\*指明当前文档根目录的路径\****                           | ***\*Directory Path\****                                     |
| ***\*@exception\****    | ***\*标志一个类抛出的异常\****                               | ***\*@exception exception-name explanation\****              |
| ***\*{@inheritDoc}\**** | ***\*从直接父类继承的注释\****                               | ***\*Inherits a comment from the immediate surperclass.\**** |
| ***\*{@link}\****       | ***\*插入一个到另一个主题的链接\****                         | ***\*{@link name text}\****                                  |
| ***\*{@linkplain}\****  | ***\*插入一个到另一个主题的链接，但是该链接显示纯文本字体\**** | ***\*Inserts an in-line link to another topic.\****          |
| ***\*@param\****        | ***\*说明一个方法的参数\****                                 | ***\*@param parameter-name explanation\****                  |
| ***\*@return\****       | ***\*说明返回值类型\****                                     | ***\*@return explanation\****                                |
| ***\*@see\****          | ***\*指定一个到另一个主题的链接\****                         | ***\*@see anchor\****                                        |
| ***\*@serial\****       | ***\*说明一个序列化属性\****                                 | ***\*@serial description\****                                |
| ***\*@serialData\****   | ***\*说明通过writeObject( ) 和 writeExternal( )方法写的数据\**** | ***\*@serialData description\****                            |
| ***\*@serialField\****  | ***\*说明一个ObjectStreamField组件\****                      | ***\*@serialField name type description\****                 |
| ***\*@since\****        | ***\*标记当引入一个特定的变化时\****                         | ***\*@since release\****                                     |
| ***\*@throws\****       | ***\*和 @exception标签一样.\****                             | ***\*The @throws tag has the same meaning as the @exception tag.\**** |
| ***\*{@value}\****      | ***\*显示常量的值，该常量必须是static属性。\****             | ***\*Displays the value of a constant, which must be a static field.\**** |
| ***\*@version\****      | ***\*指定类的版本\****                                       | ***\*@version info\****                                      |

 

### Java开发规范

1. 编码格式

    ​	统一都是用utf-8编码格式

2. 名字命名方式（重要!!!）

    - 包名统一使用小写，点分隔符之间有且仅有一个自然语义的英语单词
    - 类名：首字母大写，采用驼峰式风格 例外：DO / BO / DTO / VO / AO / PO / UID 等
    - 方法名、参数名、成员变量、局部变量都统一首字母小写，同样采用驼峰式风格
    - 常量命名全部大写，单词间用下划线隔开，力求语义表达完整清楚
    - 抽象类命名使用 Abstract 或 Base 开头；异常类命名使用 Exception 结尾
    - 枚举类名建议带上 Enum 后缀，枚举成员名称需要全大写，单词间用下划线隔开

3. 次行风格和行尾风格

    ```java
    public void method(){
        // 行尾风格 推荐
    }
    
    public void method2()
    {
        // 次行风格
    }
    ```



### DOS命令操作

- 讲解相对路径 VS  绝对路径（重要!!!）

    ![](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20211218202246703.png)

- DOS命令(大小写一样效果)

    1. 更改当前目录

        ```txt
        切换成其他盘（改变根目录）
        cd (chang directory) 盘符号
        例子：切换到E盘 cd: /D e:  或者 e:
        
        切换成当前盘的其他目录
        例子：cd 绝对路径 或者 相对路径
        
        切换到当前的根目录
        例子：cd\
        
        切换到上一级目录
        例子：cd ..
        ```

    2. 对文件夹的操作

        ```txt
        创建文件夹（目录）
        例子： md 文件名 (make directory)
        
        删除文件夹（目录）
        例子：rd 文件名 （remove directory）
        
        复制文件到指定文件夹（目录）
        例子： copy 复制的文件名 文件夹所在绝对路径 或者 相对路径
        
        移动文件到指定文件夹（目录）
        例子： move 移动的文件名 文件夹所在绝对路径 或者 相对路径
        ```

    3. 查看当前文件（目录）

        ```txt
        查看当前目录的文件
        dir (directory)
        例子：
        dir （查看当前目录）  
        dir 绝对路径 或者 相对路径 （查看指定目录下的文件）
        
        以一种树状图的形式展示文件结构
        用tree 代替 dir
        例子：
        tree （查看当前目录的树状图结构）
        tree 绝对路径 或者 相对路径 （查看指定目录的树状图结构）
        ```

    4. 其他命令

        ```txt
        帮助查看相关命令的使用
        例子：help cd 
        
        清屏
        例子：cls (clean screen)
        
        退出
        例子：exit
        ```



## 变量

### 变量概述

每个变量都有一个对应的数据类型以及变量名

**变量名，类名，方法名等等标识符命名规则**

1. 组成：由26个字母大小写，0-9，- 或 $ 组成，不可以以数字为开头命名，中间不能留有空格

2. 不可以使用关键字和保留字

    ![image-20220113145556828](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220113145556828.png) 

3. 区分大小写，长度无限制

**变量的声明**

```java
// 数据类型 + 变量名，变量名...
int age;
String name;
String school,grade;
// 注意变量名不要是java保留字（关键字）
```

**变量初始化**

```java
// 成员变量可以不用赋值 有默认初始化
// 局部变量必须初始化(两种方式）
int num;
num = 10;
int num2 = 10;、
// jdk10之后，可以不需要声明类型（从变量的初始值来判断类型）
var  i = 10;
```



### 数据类型（重点）

java是一种强制类型语言，每一种数据都定义了明确的数据类型，在内存中分配了不同大小的内存空间（字节）

![image-20211219160638668](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20211219160638668.png) 

细节：字符串本质是类，属于引用数据类型



#### 整数的类型

|     类型     | 占用存储空间 |      范围      |
| :----------: | :----------: | :------------: |
|  byte  字节  |    1字节     |   -128 ~ 127   |
| short 短整型 |    2字节     | -2^15 ~ 2^15-1 |
|  int  整型   |    4字节     | -2^31 ~ 2^31-1 |
| long  长整型 |    8字节     | -2^63 ~ 2^63-1 |

1字节（byte） = 8 位（bit）

**bit** 计算机中的最小的存储单位   **byte** 计算机中基本存储单位

**整数型注意细节**

1. 数值常量值默认为int类型

2. 长整型后面有一个后缀（L或l）

    ```java
    // 自动转型
    Long num = 1000; int -> long
    // 赋值
    Long num2 = 40000000L;
    // 反问：那为什么需要特定后缀L，不是自动转型不就可以了吗？
    // 如果你的数值在int范围内，那自然都没事；但是当你要赋值一个int范围外的数字又该怎么做呢？
    ```

3. 十六进制数值前缀：0X或者0x；八进制数值前缀：0 ；二进制数值前缀：0b 或者 0B （记住是数字0）

    ```java
    // 十六进制
    OXCAFE
    // 八进制
    010
    // 二进制
    0B1001
    0B1_0000_0000 // jdk7以后 编译时会自动去除下划线
    ```

4. 注意java没有任何无符号形式的关键字（unsigned）但是提供了方法处理



#### 浮点类型

浮点数字 = 符号位 + 指数位 + 尾数位 （尾数位可能丢失，造成精度的损失）

|      类型       | 占用存储空间 |           范围           |
| :-------------: | :----------: | :----------------------: |
| float (单精度)  |    4字节     |  -3.403E38 ~ 3.403E38-1  |
| double (双精度) |    8字节     | -1.798E308 ~ 1.798E308-1 |

备注：E38 指的是 10^38

**浮点数注意细节**

1.  浮点型常量默认为double类型

1.  float 后面需要添加f 或 F，double后面可加可不加

    ```java
    float num1 = 1.0; // 错误
    double num2 = 1.1; // 正确
    float num3 = 1.2F; // 正确
    double num4 = 1.3f; // 正确
    ```

2. 浮点型常量的表示形式

    ```java
    double num = 1.0; // 十进制数形式 1.0f  .512 == 0.512(小数点必须在可以省略0)
    double num5 = 5.12e2; // 科学计数法 5.12e2 == 512  5.12E-2 == 0.0512
    ```

3. 通常情况下我们使用double 精度高

    ```java
    double num = 1.23456789123f;
    float num1 = 1.23456789123f;
    System.out.println(num);  // 1.23456789123
    System.out.println(num1);  // 1.2345679
    ```

4. 比较 小数数字是否相等时要注意：最好不要直接去比较两个浮点数是否 ==，最好是两个浮点数的差值绝对值在某个精度范围内来进行比较（如0.000001）

    ```java
    double num = 8.1 / 3;
    double num1 = 2.7;
    System.out.println(num); // 2.6999999999999997 
    System.out.println(num1); //2.7
    
    if(Math.abs(num - num1) < 0.000001){
        System.out.println("相等");
    }
    ```
    
6. 对于使用strictfp关键字标记的方法必须严格的浮点计算来生成结果，好处：不仅让浮点数运算更加精确，而且不会因为不同硬件平台所执行而效果不同；坏处：降低性能

    ```java
    // 主方法下的所有浮点数都严格按照IEEEE-754标准进行运算
    public static strictfp void main(String[] args){}
    ```

    

#### 字符类型

| 类型 | 占用存储空间 |     表示     |
| :--: | :----------: | :----------: |
| char |    2字节     | 表示单个字符 |

**字符型注意细节**

1. 字符常量是用单引号（’‘）括起来的单个字符

    ```java
    char c = 'n';
    ```

2. 单引号里面可以放入转义字符（虽然有两个字符，但是它是表示一个字符的 比如 // 表示 / ）

    ```java
    char ch = '//'
    ```

3. char 的本质就是一个整数（unicode表） (**注意：字符 -->  数字 unicode       数字 --> 字符   **)

    ```java
    // unicode 编码
    'a' --  97
    // char 类型字符可以进行加减 但是注意超出范围的问题
    'a' + 10 -- 107
    ```

**字符在计算机里的存储方式**

存储：‘a’   ==> 97   ==>  二进制数(11000001)  ==> 存储

读取： 二进制(11000001)  ==> 97  ==>  'a'  ==>  读取

**字符编码表**

- ASCll编码表，一个字节表示，ASCII实际上可以表示256个字符，但是只使用了128个
- Unicode编码表 ，固定两个字节表示字符（字符和汉字统一都是占用2个字节）
- utf-8编码表，大小可变的编码（字母使用1个字节，汉字使用3个字节）
- GBK编码，大小可变的编码（字母使用1个字节，汉字使用2个字节）
- big5编码，繁体字，台湾，香港（了解）



#### 布尔类型

常用于条件判断语句  if - else   while

|  类型   | 占用存储空间 |    表示    |
| :-----: | :----------: | :--------: |
| boolean |    1字节     | +  / false |

注意：布尔类型不能和整数型相互转换（这里和c/c++不同）



### 数据类型转换

#### 自动类型转换

精度小的数据类型自动转换为精度大的数据类型

![image-20220111140545230](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220111140545230.png) 

**自动类型转换相关的注意细节**

1. 当一个二元运算符连接两个值时，先将两个操作数转换成同一类型的数据进行计算（转换成操作数两边范围最大的数据类型）

    ```java
    // 伪代码 顺序：double -> float -> long -> int -> short -> byte
    //             double -> float -> long -> int -> char
    if(两个操作数中有一个是double类型数据){
        另一个操作数也会强制转换成double类型数据
    }else if(两个操作数中有一个是float类型数据){
        另一个操作数也会强制转换成float类型数据
    }... // 依次下去
    ```

2. （byte,short）和 char 之间不会自动转换

2. 注意赋值区别（具体数值赋值和变量赋值）

    ```java
    // 具体值赋值会先进行范围的判进行赋值
    char c = 10000; 
    short s = 'a';
    byte b = 'b';
    // 变量赋值就是依据自动类型转换或者强制类型转换
    c = (char)s;
    s = (short)c;
    ```
    
3. 整数赋值和浮点数赋值的注意点

    ```java
    // 整数之间的赋值
    byte n = 10; // 具体数值赋值，先进行判断该数值是否在byte范围，如果在编译就不会出错，便会赋值
    int n1 = 10;
    n = n1; // int类型变量无法直接赋值给byte类型（可以进行强制类型转换）
    
    // 小数之间赋值 
    float f = 10.0; // 错误，float中将无法进行比较，本来都是一个估算值，无法进行比较范围，因此10.0是double类型无法自动转型为float
    ```

4. byte,char,short 三者进行计算，在计算时首先转换成int类型数据（变量计算都会转换成int类型，不管是否是同类型数据相加减）

5. boolean 数据类型不参与类型转换



#### 强制类型转换

**概念：**自动类型转换的逆过程，将范围大的数据类型转换成范围小的数据类型，使用时需要在变量或者具体值前面加（）

**好处：**根据程序员的意愿进行修改   **坏处：**范围超出了想要转换的数据类型，会导致溢出问题

```java
// 例如 double ==> float
float f = (float)10.0;
```

**强制类型转换的注意细节**

1. 强制符号只针对最近的操作数有效，往往会使用小括号来提升优先级

    ```java
    int n = (int)10*3.5+12*2.3; // 错误
    int n = (int)(10*3.5+12*2.3); // 正确
    ```
    
2. 注意区别 i++ 和 i = i+1的区别

    ```java
    // 直接上代码
    class test{
        public static void main(String[] args) {
            byte j = 10;
            j++;
    	    short k = 11;
    		k += 1;
    		int i = 11;
    		i = i + 1;
        }
    }
    // 反编译看细节
    class test {
      test();
        Code:
           0: aload_0
           1: invokespecial #1                  // Method java/lang/Object."<init>":()V
           4: return
    
      public static void main(java.lang.String[]);
        Code:
           0: bipush        10  // 将数值10压入栈
           2: istore_1   // 栈中弹出一个数（10），赋值给局部变量j（_1表示赋值给第一个局部变量，即j）
           3: iload_1    // 将局部变量j(_1表示第一个局部变量，即j)的值入栈，此时栈顶的值为10
           4: iconst_1   // 将常量1(_1)压入栈中
           5: iadd       // 相加常量和局部变量j => 11
           6: i2b        // 注意！！ 强制类型转换 int -> byte
           7: istore_1
           8: bipush        11
          10: istore_2  //  栈中弹出一个数（11），赋值给局部变量k（_2表示赋值给第二个局部变量，即k）
          11: iload_2
          12: iconst_1
          13: iadd
          14: i2s        //  注意！！ 强制类型转换 int -> short
          15: istore_2
          16: bipush        11 
          18: istore_3
          19: iload_3
          20: iconst_1
          21: iadd
          22: istore_3
          23: return
    }
    // 总结
    i++ && i += 1 // 会进行强制类型转换成原来的类型
    i = i+1  // 如果i是byte或者short类型都不能通过编译，因为i+1会自动转换成int类型，int类型必须通过强制类型转换才可以转换成short或者byte类型
    ```

#### 基本数据类型和String类型的转换

1. 将基本数据类型+"" ==> String类型

    ```java
    String s = 10 + "";
    ```

2. 通过基本数据类型的包装类调用parseXX方法

    ```java
    String s = "2"
    Integer.parseInt(s);
    Double.parseDouble(s);
    Float.parseFloat(s);
    Short.parseShort(s);
    Long.parseLong(s);
    Boolean.parseBoolean("true");
    Byte.parseByte(s);
    
    // char 根据索引来判断
    String str = "123456789";
    char c  = str.charAt(0);
    ```



## 运算符

运算符是一种特殊的符号，用来表示数据的运算，赋值或者比较等

### 算术运算符

| 操作符 |               描述                |                例子                |
| :----: | :-------------------------------: | :--------------------------------: |
|   +    |     加法 - 相加运算符两侧的值     |           A + B 等于 30            |
|   -    |    减法 - 左操作数减去右操作数    |           A – B 等于 -10           |
|   *    |     乘法 - 相乘操作符两侧的值     |            A * B等于200            |
|   /    |    除法 - 左操作数除以右操作数    |             B / A等于2             |
|   ％   | 取余 - 左操作数除以右操作数的余数 |              B%A等于0              |
|   ++   |       自增: 操作数的值增加1       | B++ 或 ++B 等于 21（区别详见下文） |
|   --   |       自减: 操作数的值减少1       | B-- 或 --B 等于 19（区别详见下文） |
|   +    |            字符串连接             | “lns”+"love"+"zlr" = "lnslovezlr"  |

**代码讲解**

```java
//  / 整除使用 
// 注意：整数被0除将会产生一个异常，浮点书被0除将会得到Infinity结果
10 / 4; // 2
10.0 / 4 // 2.5 
double d = 10 / 4; // 2.0  int -> double
double i = 10.0/0; // Infinity 无穷的意思

// % 使用
// 取模的本质 公式： a % b = a - a / b * b （当 a 是整数）   a % b = a - （int）a / b * b （当 a 是浮点数，但是是近似值）
10 % 3 // 1
-10 % 3 // -1
10 % -3 // 1
-10 % -3 // -1
// 总结得出取模的正负取决于被模数
```



### 关系运算符

关系运算符的结果都为boolean类型， true / false

关系运算符组成的表达式我们称为关系表达式

|   运算符   |                             描述                             |            例子             |
| :--------: | :----------------------------------------------------------: | :-------------------------: |
|     ==     |     检查如果两个操作数的值是否相等，如果相等则条件为真。     |       （A == B）为假        |
|     !=     |   检查如果两个操作数的值是否相等，如果值不相等则条件为真。   |        (A != B) 为真        |
|     >      |  检查左操作数的值是否大于右操作数的值，如果是那么条件为真。  |        （A> B）为假         |
|     <      |  检查左操作数的值是否小于右操作数的值，如果是那么条件为真。  |        （A <B）为真         |
|     >=     | 检查左操作数的值是否大于或等于右操作数的值，如果是那么条件为真。 |       （A> = B）为假        |
|     <=     | 检查左操作数的值是否小于或等于右操作数的值，如果是那么条件为真。 |       （A <= B）为真        |
| instanceof |   用于判断对象的运行类型是否为某某类型或者是某某类型的子类   | “XX” instanceof String 为真 |



### 逻辑运算符

用于连接多个条件（多个关系表达式）

|  操作符   |                          描述                          |
| :-------: | :----------------------------------------------------: |
| && 短路与 | 如果某一个条件为false,则后面的条件不用判断,结果为false |
| & 逻辑与  |                    全部条件都要执行                    |
| II 短路或 |  如果某一个条件为true,则后面的条件不用判断,结果为true  |
| I 短路或  |                    全部条件都要执行                    |
|  ！取反   |          取反：true -> false ; false -> true           |
|   ^异或   | 如果两个条件都为true或者false则返回false,反之返回true  |

**举例**

![image-20220111141500121](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220111141500121.png) 

**习题练习**

```java
// 习题1
int x = 5,y = 5;
if(x++ == 6 & ++y == 6) x = 11; // 逻辑与 &  ;  结果 x = 6, y = 6

// 习题2
int x = 5,y = 5;
if(x++ == 6 && ++y == 6) x = 11; // 短路与 &&  ;  结果 x = 6, y = 5

// 习题3
int x = 5,y = 5;
if(x++ == 5 | ++y == 5) x = 11; // 逻辑或 |  ;  结果 x = 11, y = 6

// 习题4
int x = 5,y = 5;
if(x++ == 5 || ++y == 5) x = 11; // 短路或 ||  ;  结果 x = 11, y = 5

// 习题5
boolean x = true, y = true;
short z = 46;
if((z++ == 46) && (y = true)) z++;
if((x = false) || (++z == 49)) z++;
// 结果：z = 50
```



### 赋值运算符

将某个运算后的值赋给指定的变量  

| 操作符  |                             描述                             |                   例子                   |
| :-----: | :----------------------------------------------------------: | :--------------------------------------: |
|    =    |        简单的赋值运算符，将右操作数的值赋给左侧操作数        |     C = A + B将把A + B得到的值赋给C      |
|   + =   |   加和赋值操作符，它把左操作数和右操作数相加赋值给左操作数   |          C + = A等价于C = C + A          |
|   - =   |   减和赋值操作符，它把左操作数和右操作数相减赋值给左操作数   |          C - = A等价于C = C - A          |
|   * =   |   乘和赋值操作符，它把左操作数和右操作数相乘赋值给左操作数   |          C * = A等价于C = C * A          |
|   / =   |   除和赋值操作符，它把左操作数和右操作数相除赋值给左操作数   | C / = A，C 与 A 同类型时等价于 C = C / A |
| （％）= | 取模和赋值操作符，它把左操作数和右操作数取模后赋值给左操作数 |           C％= A等价于C = C％A           |
|  << =   |                       左移位赋值运算符                       |         C << = 2等价于C = C << 2         |
|  >> =   |                       右移位赋值运算符                       |         C >> = 2等价于C = C >> 2         |
|   ＆=   |                       按位与赋值运算符                       |           C＆= 2等价于C = C＆2           |
|   ^ =   |                      按位异或赋值操作符                      |          C ^ = 2等价于C = C ^ 2          |
|  \| =   |                       按位或赋值操作符                       |         C \| = 2等价于C = C \| 2         |

**注意细节**

1. 运算顺序从右往左
2. 复合赋值运算符会进行类型转换（上文强制类型转换中有详细介绍）



### 条件运算符

条件运算符也被称为三元运算符。该运算符有3个操作数，并且需要判断布尔表达式的值。该运算符的主要是决定哪个值应该赋值给变量。

```java
// 如果条件的表达式为 true ,运算后的结果表达式1，反之运行表达式2
// 格式：条件表达式 ？表达式1 ： 表达式2 
// 可以理解为如下
if(true) 
    return 表达式1 
else 
    return 表达式2 
```



### 位运算

#### 进制转换

**其他进制转换成十进制**

规则：从最低位（右边）开始，将每个位上的数提取出来，乘以进制（其他进制的进制数）的（位数-1）次方，然后求和

```java
// 举例：八进制转换成十进制
0234 = 4*8^0 + 3*8^1 + 2*8^2 = 156
```

**十进制转换成其他进制**

规则：将该数不断除以进制（其他进制的进制数），直到商为0为止，然后将每步得到的余数倒过来，就是对应的进制数

举例： 十进制转换成二进制

```java
// 将34转换成二进制 0B0010_0010
34 / 2 = 17  34 % 2 = 0
17 / 2 = 8   17 % 2 = 1
8 / 2 = 4    8 % 2 = 0
4 / 2 = 2    4 % 2 = 0
2 / 2 = 1    2 % 2 = 0
1 / 2 = 0    1 % 2 = 1 
// 结果反转 10_0010 高位补齐 -> 0010_0010
```

#### 位运算符

| 操作符 |                             描述                             |              例子              |
| :----: | :----------------------------------------------------------: | :----------------------------: |
|   ＆   |            如果相对应位都是1，则结果为1，否则为0             | （A＆B），得到12，即0000 1100  |
|   \|   |           如果相对应位都是 0，则结果为 0，否则为 1           | （A \| B）得到61，即 0011 1101 |
|   ^    |            如果相对应位值相同，则结果为0，否则为1            | （A ^ B）得到49，即 0011 0001  |
|   〜   |     按位取反运算符翻转操作数的每一位，即0变成1，1变成0。     |  （〜A）得到-61，即1100 0011   |
|   <<   |     按位左移运算符。左操作数按位左移右操作数指定的位数。     |  A << 2得到240，即 1111 0000   |
|   >>   |     按位右移运算符。左操作数按位右移右操作数指定的位数。     |      A >> 2得到15即 1111       |
|  >>>   | 无符号右移，按位右移补零操作符。左操作数的值按右操作数指定的位数右移，移动得到的空位以零填充。 |     A>>>2得到15即0000 1111     |

#### 计算机底层运行实例

**引入原码，反码，补码**

- 二进制的最高位是符号位：0表示正数，1表示负数
- 自然数的原码，反码，补码都是相同的（0的反码，补码都是0）
- 负数的反码等于它的原码符号位不变，其他位取反
- 负数的补码等于它的反码+1（负数的反码等于它的补码-1）
- 计算机运行的数据以补码的方式进行运算，但是输入输出的都是原码

**注意细节**

无符号右（>>>）：无论是正数还是负数，都是高位补0

负数右移（>>）：高位补符号位1 ； 负数左移（<<）：低位补0 

正数右移（>>）：高位补符号位0 ； 正数左移（<<）：低位补0 

```java
// 运用补码原码知识
// 注意位运算操作的都是补码而非原码！！
System.out.println(2 & 6); // 2
/*
 * 讲解计算机运行过程
 * 运算用补码
 * 1. 2的原码 ==> 00000000 00000000 00000000 00000010 == 2 的补码
 * 2. 6的原码 ==> 00000000 00000000 00000000 00000110 == 6 的补码
 * 运算结果为原码
 * 3. 按位与& ==> 00000000 00000000 00000000 00000010 == 6 的原码 结果为2
 */

System.out.println(~-2); // 1
/*
 * 讲解计算机运行过程
 * 运算用补码
 * 1. -2的原码 ==> 10000000 00000000 00000000 00000010
 * 2. -2的补码 ==> 11111111 11111111 11111111 11111110
 * 3. ~-2的补码 ==> 00000000 00000000 00000000 00000001
 * 运算结果为原码
 * 3. 原码结果为 00000000 00000000 00000000 00000001 == 1
 */

System.out.println(-2 >> 3); // -1
/*
 * 讲解计算机运行过程
 * 运算用补码
 * 1. -2的原码 ==> 10000000 00000000 00000000 00000010
 * 2. -2的补码 ==> 11111111 11111111 11111111 11111110
 * 3. -2>>3的补码 ==> 11111111 11111111 11111111 11111111
 * 4. -2>>3的反码 ==> 11111111 11111111 11111111 11111110
 * 运算结果为原码
 * 5. 原码结果为 10000000 00000000 00000000 00000001 == -1
 */
```



### 运算符优先级

|   类别   |                   操作符                   |  关联性  |
| :------: | :----------------------------------------: | :------: |
|   后缀   |             () [] . (点操作符)             |  左到右  |
|   一元   |               expr++ expr--                | 从左到右 |
|   一元   |          ++expr --expr + - ～ ！           | 从右到左 |
|   乘性   |                   * /％                    |  左到右  |
|   加性   |                    + -                     |  左到右  |
|   移位   |                 >> >>>  <<                 |  左到右  |
|   关系   |                 > >= < <=                  |  左到右  |
|   相等   |                   == !=                    |  左到右  |
|  按位与  |                     ＆                     |  左到右  |
| 按位异或 |                     ^                      |  左到右  |
|  按位或  |                     \|                     |  左到右  |
|  逻辑与  |                     &&                     |  左到右  |
|  逻辑或  |                   \| \|                    |  左到右  |
|   条件   |                    ？：                    | 从右到左 |
|   赋值   | = + = - = * = / =％= >> = << =＆= ^ = \| = | 从右到左 |
|   逗号   |                     ，                     |  左到右  |



## 控制结构

### 控制循环类型

- **顺序控制**：程序从上到下逐行地执行，中间没有跳转和任何判断

-  **分支控制**：if - else 判断 

    ```java
    // 单分支
    if(条件表达式){ 
        执行语句;
    }
    // 双分支
    if(条件表达式){ 
        执行语句;
    }else{
        执行语句;
    }
    // 多分支
    if(条件表达式){ 
        执行语句;
    }else if(条件表达式){
        执行语句;
    }else{
        
    }
    ```

- **嵌套分支**：在一个分支结构中嵌套另一层分支结构（最好不要超过三层）

- **switch分支结构**

    ```java
    switch(表达式){ // 表达式有具体的值 
           case 常量 1：语句一; // 表达式代表一个具体值，常量1与该值进行比较，相同则运行语句一
                      break; // 退出switch循环，否则直接进行语句2的运行（无需比较常量2）
    
           case 常量2：语句二; // 表达式代表一个具体值，常量2与该值进行比较，相同则运行语句二
                      break; 
           ....
           default: 最后一个语句; // 当不等于所有值，则默认执行default语句   
    }
    ```

    **细节注意：**

    1. 表达式的数据类型必须和常量的数据类型必须相同 或者 可以自动转换的数据类型（必须是其他类型转换成int类型 比如：byte(表达式类型) - > int(常量类型)）
    2. 表达式中具体值和常量的数据类型只能是（byte,short,int,char,enum,String）中的其中一个
    3. default关键字是可选择添加的
    
- for循环控制 &&  while循环控制  && do...while循环语句

    ```java
    // 基本语法
    for(循环变量初始化;循环条件;循环变量的变化){
        循环操作（可以多条语句);
    }
    运行顺序： 循环变量初始化 --> [ 循环条件 --> 循环操作 --> 循环条件的变化 ]
       
    
    // 等价于while x
    循环变量初始化;
    while(循环条件){
        循环操作（可以多条语句);
        循环变量的变化;
    }
    
    // 等价于do...while  先执行后判断
    循环变量初始化;
    do{
        循环操作（可以多条语句);
        循环变量的变化;
    }
    while(循环条件);
    ```



### 中断控制流程语句

#### break语句

概念：用于退出当前循环

```java
// 不带标签的语句
for(int i = 0;i < 10;i++){
    for(int j = 0;j < 10;j++){
        break; // 默认中断当下循环
    }
}

// 带有标签的语句（格式： 标签名自定义 + ：）
label1:
    for(int i = 0;i < 10;i++){
        label2:
        for(int j = 0;j < 10;j++){
            break label1; // 中断标签1的循环
        }
    }

// switch 中断语句
switch(表达式){ // 表达式有具体的值 
       case 常量 1：语句一; // 表达式代表一个具体值，常量1与该值进行比较，相同则运行语句一
                  break; // 退出switch循环，否则直接进行语句2的运行（无需比较常量2）

       case 常量2：语句二; // 表达式代表一个具体值，常量2与该值进行比较，相同则运行语句二
                  break; 
       ....
       default: 最后一个语句; // 当不等于所有常量，则默认执行default语句   
}

```

#### continue语句

概念：结束本次循环，继续进行下一次循环

```java
// 不带标签的语句
for(int i = 0;i < 10;i++){
    for(int j = 0;j < 10;j++){
        continue; // 默认结束本次循环，而非退出循环，注意和break的区别
    }
}

// 带有标签的语句（格式： 标签名自定义 + ：）
label1:
    for(int i = 0;i < 10;i++){
        label2:
        for(int j = 0;j < 10;j++){
            continue label1; // 结束label1的本次循环，跳转到label标签匹配的循环首部
        }
    }
```

#### return语句

概念：表示跳出当前所在的方法，如果该方法是main主方法，则相当于结束程序

注意：break 和 continue 必须使用在 loop 或者 switch中，而return可以用在方法的任何位置



## 数组

### 一维数组

![image-20220330093229938](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220330093229938.png) 

数组是引用数据类型，可以存放多个同一类型的数据,引用数据类型有默认初始值

| 数据类型 | byte | short |  char  | int  | long | float | double | boolean | String |
| :------: | :--: | :---: | :----: | :--: | :--: | :---: | :----: | :-----: | :----: |
|  初始值  |  0   |   0   | \u0000 |  0   |  0   |  0.0  |  0.0   |  false  |  null  |

#### 数组的创建

```java
// 先声明后初始化
// 声明数组名
int[] a; // 定义数组数据类型 和 数组名
或者
int a[]; // 推荐使用上面的形式 简洁明了
// 初始化数组
a = new int[5];  // 5 指的是数组长度（a.length) 

// 声明 + 初始化
int[] b = new int[5]; // 5 指的是数组长度（a.length) 
// 通过下标/索引 [0,array.length)来访问数组值 如：a[1]指的是第二个数组 

// 静态初始化  存入数组值
int[] c = {2,3,4,5,6}; // 最后一个值后面的逗号可加可不加

// 注意格式
Integer[] num = new Integer{2,3,4,5,6} // error
Integer[] num = new Integer[]{2,3,4,5,6} // ok
Integer[] num = new Integer[5]{2,3,4,5,6} // error
```

#### 值传递和引用传递

1、基本类型的变量保存原始值，所以变量就是数据本身（值传递）

常见的基本类型：byte,short,int,long,char,float,double,Boolean

2、引用类型的变量保存引用值，所谓的引用值就是对象所在内存空间的“首地址值”，通过对这个引用值来操作对象。（引用传递）

常见的引用类型：类类型，接口类型和数组

**举例说明**

内存图（代码如下）

  ![image-20220330121211030](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220330121211030.png) 

```java
public static void main(String[] args){
    // 值传递
    int m = 10;
    int n = m;
    n = 20;
    System.out.println("m: "+ m +"n: "+ n); // m: 10 n: 20

    // 引用传递
    int[] arr1 = {1,2,3};
    int[] arr2 = arr1;
    arr[0] = 10;
    // 结果：arr1: 10 2 3 ; arr2: 10 2 3
}
```

#### 数组拷贝

Arrays类的copyOf方法：复制指定的数组

注意：数组拷贝 != 数组赋值（引用传递）

![](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220113235950538.png) 

```c
// copyOf方法源码分析
public static int[] copyOf(int[] original, int newLength) {
    int[] copy = new int[newLength];
    System.arraycopy(original, 0, copy, 0,
                     Math.min(original.length, newLength));
    return copy;
}
// 本地方法
public static native void arraycopy(Object src,  int  srcPos,
                                        Object dest, int destPos,
                                        int length);

// jvm.cpp文件
JVM_ENTRY(void, JVM_ArrayCopy(JNIEnv *env, jclass ignored, jobject src, jint src_pos,
                               jobject dst, jint dst_pos, jint length))
    JVMWrapper("JVM_ArrayCopy");
    // 检查源数组和目的数组是否为null
    if (src == NULL || dst == NULL) {
        THROW(vmSymbols::java_lang_NullPointerException());
    }
    arrayOop s = arrayOop(JNIHandles::resolve_non_null(src));
    arrayOop d = arrayOop(JNIHandles::resolve_non_null(dst));
    assert(s->is_oop(), "JVM_ArrayCopy: src not an oop");
    assert(d->is_oop(), "JVM_ArrayCopy: dst not an oop");
    //真正调用复制的方法
    s->klass()->copy_array(s, src_pos, d, dst_pos, length, thread);
JVM_END

// 调用copy_array方法
void ObjArrayKlass::copy_array(arrayOop s, int src_pos, arrayOop d,
                        int dst_pos, int length, TRAPS) {
  //检测s是数组
  assert(s->is_objArray(), "must be obj array");
 
  //目的数组不是数组对象的话，则抛出ArrayStoreException异常
  if (!d->is_objArray()) {
    THROW(vmSymbols::java_lang_ArrayStoreException());
  }
  //检测下标参数非负
  if (src_pos < 0 || dst_pos < 0 || length < 0) {
    THROW(vmSymbols::java_lang_ArrayIndexOutOfBoundsException());
  }
  //检测下标参数是否越界
  if  ( (((unsigned int) length + (unsigned int) src_pos) > (unsigned int) s->length())
     || (((unsigned int) length + (unsigned int) dst_pos) > (unsigned int) d->length()) ) {
    THROW(vmSymbols::java_lang_ArrayIndexOutOfBoundsException());
  }
 
  // 如果长度为0则无需复制
  if (length==0) {
    return;
  }
  //UseCompressedOops只是用来区分narrowOop和oop
  //调用do_copy函数来复制
  if (UseCompressedOops) {
    narrowOop* const src = objArrayOop(s)->obj_at_addr<narrowOop>(src_pos);
    narrowOop* const dst = objArrayOop(d)->obj_at_addr<narrowOop>(dst_pos);
    do_copy<narrowOop>(s, src, d, dst, length, CHECK);
  } else {
    oop* const src = objArrayOop(s)->obj_at_addr<oop>(src_pos);
    oop* const dst = objArrayOop(d)->obj_at_addr<oop>(dst_pos);
    do_copy<oop> (s, src, d, dst, length, CHECK);
  }
}

// 调用do_copy方法
// Either oop or narrowOop depending on UseCompressedOops.
template <class T> void ObjArrayKlass::do_copy(arrayOop s, T* src,
                               arrayOop d, T* dst, int length, TRAPS) {
 
  BarrierSet* bs = Universe::heap()->barrier_set();
  // 出于性能原因，我们假设我们使用的写屏障具有针对引用数组的优化模式。
  // 如果不是这种情况，至少以下断言之一将失败
  assert(bs->has_write_ref_array_opt(), "Barrier set must have ref array opt");
  assert(bs->has_write_ref_array_pre_opt(), "For pre-barrier as well.");
 
  if (s == d) {
    // since source and destination are equal we do not need conversion checks.
    assert(length > 0, "sanity check");
    bs->write_ref_array_pre(dst, length);
	// 复制的函数
    Copy::conjoint_oops_atomic(src, dst, length);
  } else {
    // We have to make sure all elements conform to the destination array
    Klass* bound = ObjArrayKlass::cast(d->klass())->element_klass();
    Klass* stype = ObjArrayKlass::cast(s->klass())->element_klass();
    if (stype == bound || stype->is_subtype_of(bound)) {
      // elements are guaranteed to be subtypes, so no check necessary
	  //stype对象是bound，或者stype是bound的子类抑或stype实现bound接口
      bs->write_ref_array_pre(dst, length);
      Copy::conjoint_oops_atomic(src, dst, length);
    } else {
      // slow case: need individual subtype checks
      // note: don't use obj_at_put below because it includes a redundant store check
      T* from = src;
      T* end = from + length;
      for (T* p = dst; from < end; from++, p++) {
        // XXX this is going to be slow.
        T element = *from;
        // even slower now
        bool element_is_null = oopDesc::is_null(element);
        oop new_val = element_is_null ? oop(NULL)
                                      : oopDesc::decode_heap_oop_not_null(element);
        if (element_is_null ||
            (new_val->klass())->is_subtype_of(bound)) {
          bs->write_ref_field_pre(p, new_val);
          *p = element;
        } else {
          // We must do a barrier to cover the partial copy.
          const size_t pd = pointer_delta(p, dst, (size_t)heapOopSize);
          // pointer delta is scaled to number of elements (length field in
          // objArrayOop) which we assume is 32 bit.
          assert(pd == (size_t)(int)pd, "length field overflow");
          bs->write_ref_array((HeapWord*)dst, pd);
          THROW(vmSymbols::java_lang_ArrayStoreException());
          return;
        }
      }
    }
  }
  bs->write_ref_array((HeapWord*)dst, length);
}
```

 [参考链接](https://www.jianshu.com/p/baa4c29c0f99)



### 二维数组

#### 数组的创建

```java
// 先声明后初始化
// 声明方式
int[][] a;   int[] a[];  int a[][];  
int[] x,y[]; // x 是一维数组 y 是二维数组
// 初始化二维数组
a[n] new int[5];  //n 的取值范围 [0,5) ,表示的是某一行的一维数组元素

// 动态初始化
int[][] twoArray = new int[5][]; // 5个一维数组，每个一维数组元素可以不相同
int[][] twoArray = new int[5][5]; // 5*5的二维数组
 
twoArray.length; // 二维数组的行数（二维数组元素个数）
twoArray[n].length; // n 的取值范围 [0,twoArray.length) ,表示的是某一行的一维数组元素

// 静态初始化
// 每个二维数组的每行元素并不一定相等
int[][] a =  {{1,2},{3,4,5,6,},{1,2,3}};
for (int i = 0; i < a.length; i++) {
    for (int j = 0; j < a[i].length; j++) {
        System.out.print("\t"+a[i][j]);
    }
    System.out.println();
}
	1	2
	3	4	5	6
	1	2	3
```

#### 内存分析

```java
public static void main(String[] args){
    int arr[][] = new int[2][3];
    arr[1][1] = 8;
}
```

![](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220331092442078.png)  

#### 习题

```java
// 杨辉三角
final int N = 10;
int[][] array = new int[N][];
for (int i = 0; i < N; i++) {
    array[i] = new int[i+1];
    for (int j = 0; j <= i; j++) {
        if(j == 0 || j == i){
            array[i][j] = 1;
        }else{
            array[i][j] = array [i-1][j] + array[i-1][j-1];
        }
    }
}

for (int i = 0; i < array.length; i++) {
    for (int j = 0; j < array[i].length; j++) {
        System.out.print(array[i][j]+"  ");
    }
    System.out.println();
}
// 实现效果
1  
1  1  
1  2  1  
1  3  3  1  
1  4  6  4  1  
1  5  10  10  5  1  
1  6  15  20  15  6  1  
1  7  21  35  35  21  7  1  
1  8  28  56  70  56  28  8  1  
1  9  36  84  126  126  84  36  9  1  
```



### 多态数组

数组的定义类型为父类类型，里面保存的实际元素类型为子类类型

```java
// 初始化多态数组
public class attay{
    public static void main(String[]args){
        // 向上转型
        // 创建5个对象： 一个人 二个学生 二个老师
        person[] p = new person[5];
        p[0] = new person();
        p[1] = new student();
        p[2] = new student();
        p[3] = new teacher();
        p[4] = new teacher();
    }
}
class person{} // 父类
class student extends person{} // 子类
class teacher extends person{}  // 子类
```



## 类和对象

概念：类是**自定义的数据类型**，对象就是一个具体的实例   <==>   int   和  100 的关系

对象【属性，行为】

### 包

概念：包本质就是文件夹，用来存放java文件

作用: 1.区分相同名字的类 2.可以很好的管理类 3.控制方法范围通过访问修饰符

```java
// 声明当前类所在的包，需要放在类的最上面 ，一个类最多只有一句package
package com.al_tair.study;
```

#### 命名规则和规范 

包的命名规则：只能包含数字，字母，下划线，小圆点，但不能用数字开头，不能是关键字或者保留字

包的命名规范：全名都是小写字母（包名和包名之间用点来分隔）

比如 ： com.公司名.项目名.业务模块名

#### 系统的包导入

```java
// 声明当前类所在的包
package com.al_tair.study;

// 导入包，import关键字放在package下面，在类定义前面，可以有多句，没有顺序要求
import java.util.Scanner;
import java.util.Arrays;

// 类定义
public class study{
    public static void main(String[]args){}
}
```

.* 指的是包下所有的类都导入（注意 java.util.* 导入的是util下的类，而不会导入util.Stream.*中Stream下的类）



### 修饰符

#### 访问修饰符

- public : 对全部包中的类开放
- protected ： 对不同包的子类和同一个包中的类公开
- 默认访问修饰符（无修饰符）：对同一个包中的类（包含子类）公开，但是对不同包的子类不公开
- private : 只有类本身可以访问 

![image-20220130203735334](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220130203735334.png) 

**使用注意细节**

- 修饰符可以用来修饰类中的属性，成员方法以及类
- 局部变量不能有访问修饰符，因为范围已经被局限在方法或者代码块等等
- 只能用默认的和public来修饰类
    - protected 用于修饰成员，表示在继承体系中成员对于子类可见，但是这个访问修饰符对于类没有意义

---

#### static静态修饰符

类的组成：成员变量，成员方法，代码块，内部类，构造器

被static静态修饰符修饰：静态成员变量，静态成员方法，静态代码块，静态内部类，构造器不能被static修饰

static静态修饰符表示的更多是共享数据，是属于类的，随着类的加载而加载，随着类的消亡而销毁（具体介绍如下文类的组成）

---

#### final修饰符

final 关键字可以用来修饰类，属性，方法和局部变量，不能修饰构造器

```java
public class Final {
    /*
     * 使用final的情况
     * (1)当不希望类被继承时,可以用final修饰
     * (2)当不希望父类的某个方法被子类覆盖或者重写
     * (3)当不希望类的某个属性的值被修改,可以用final修饰 [例如：final double PI = 3.1415926] -> 常量
     * (4)当不希望某个局部变量被修改,可以用final修饰 -> 局部常量
     *
     * 使用final关键字的细节讨论
     * 1.final修饰的属性又叫常量,一般用 XXX_XXX_XXX来命名
     * 2.final修饰的属性在定义时,必须赋初始值,赋值可以加在如下的位置上
     *    属性定义时初始化 / 在构造器中 / 在代码块中
     * 3.final修饰的属性是静态的,则赋值可以加在如下的位置上
     *    静态属性定义时初始化 / 在静态代码块中
     * 4.final类不能继承，但是可以实例化对象
     * 5.如果类不是final类，但是含有final方法，虽然该方法不能重写，但是该类可以被继承
     * 6.final 和 static 往往搭配使用效率更高,不会导致类加载,底层编译器做了优化 如下例子
     * 7.包装类(Integer,double,Float,Boolean等)不能继承
     */
    public static void main(String[] args) {
        /*
         * final 修饰基本数据类型
         * 基本数据类型的值不能发生变化
         */
        final int FINAL = 30;
        // FINAL = 100; 报错

        /*
         * final修饰引用数据类型
         * 引用数据类型饿地址值不能发生改变，但是该地址上的内容可以发生改变
         */
        final FU fu = new FU();
        // fu.show4();
        // fu = new FU();  报错
        
        // final 和 static 往往搭配使用效率更高,不会导致类加载,底层编译器做了优化
        System.out.println(BB.name);
    }
}

class AA{
   // 静态属性定义时初始化
    public static final int NUMS1 = 12;
    public final int NUM1 = 12;

    public static final int NUMS2;
    public final int NUM2;

    public static final int NUMS3;
    public final int NUM3;
    
    // 在静态代码块中初始化
    static{
        NUMS2 = 12;
        NUMS3 = 12;
    }
    {
        NUM3 = 12;
    }
    // 在构造器中初始化
    public AA(){
        NUM2 = 12;
    }
}

// final 和 static 往往搭配使用效率更高,不会导致类加载,底层编译器做了优化
class BB{
    public static final String name = "yyds";
    static {
        System.out.println("类加载了");
    }
    // 运行效果：不会显示类加载了 说明类没有被加载
}
```



### 类的组成

####  成员变量

##### 普通成员变量

```java
格式：<public|protected|默认|private> [static] [final] <type> <variable_name>
// <public|protected|默认|private> 访问修饰符
// [static] [final] 可以选择添加，具体作用接下来的会有专门讲解
// <type> 数据类型
// <variable_name> 变量名
```

**实例**

```java
// 成员变量 = 属性 = 字段（field）
class Person{
    // 属性的数据类型可以是基本数据类型或者引用数据类型
    String name;
    int height;
    int weight;
    String[] friends;
}
```

成员变量如果不赋值，有默认初始值

| 数据类型 | byte | short |  char  | int  | long | float | double | boolean | String |
| :------: | :--: | :---: | :----: | :--: | :--: | :---: | :----: | :-----: | :----: |
|  初始值  |  0   |   0   | \u0000 |  0   |  0   |  0.0  |  0.0   |  false  |  null  |

---

##### 静态成员变量

静态变量也称作类变量

语法：访问修饰符 static 数据类型 变量名； （访问修饰符和static的顺序可以交换）

与普通成员变量的语法区别就是有无 **static 关键字**

注意细节

1. 静态变量是同一个类所有对象共享
2. 类变量的生命周期随着类的加载开始，随着类消亡而销毁
3. 类变量中不能使用和对象有关的关键字（比如：this,super ），因为this或者super的产生是伴随着对象的创建而出现的，但是类变量在类加载的时候就出现了

访问方式： 类名.类变量（推荐）  对象名.类变量名

```java
// 举例类变量和类方法的使用
// Math类的源码
 public static final double PI = 3.14159265358979323846;
// 取绝对值
@HotSpotIntrinsicCandidate
public static int abs(int a) {
    return (a < 0) ? -a : a;
}
```



#### 成员方法

##### 普通成员方法

方法本质就是操作数据

```java
// 格式：伪代码 
访问修饰符  返回的数据类型  方法名（形参列表..）{
    方法体: 实现某种功能
    return 返回的数据类型: // 返回类型可以是任何数据类型（数组或对象等等）
}
```

**实例**

```java
// 注意:方法不能嵌套使用
public static void main(String[]args){
    Person p  new Person();
    // "XXX"是实参，实参：调用该方法时传入的参数
    p.run("XXX");
}
class Person{
    // name为形参，形参：在形参列表上定义的参数
    void run(String name){
        String name = name; // 局部变量，作用范围就在这个方法
        System.out.println(name+"  "+"runing..");
    }
}

// 区分实参和形参：实参是调用该方法时传入的参数，形参是在形参列表上定义的参数，需要满足：个数相同，数据类型相同或者可以自动转换，顺序对应
// 1.基本数据类型传递的是值，形参的任何改变不影响实参
// 2.引用数据类型传递的是地址，比如：数组可以通过形参来修改实参引用的数据参数，但是无法修改引用数据类型的引用地址值
```

###### 局部变量

主要的变量就是成员变量和局部变量（除成员变量外就是局部变量）

格式：数据类型  变量名 = 数值

```java
// 局部变量可以是代码块，方法，构造器等等，作用都一样，我在此以方法的局部变量进行详细说明
class person{
    // 属性（成员变量，全局变量）作用范围在至少在整个类中，具体看访问修饰符 
    // 可以不用赋值，初始值等价于数组
    String name;
    
    void say(){
        // 局部变量 作用范围在该方法中
        // 注意：局部变量不可以添加修饰符；没有赋值则无法使用
        String content = "lns"; 
        System.out.println(content); 
    }
}
```

**成员变量和局部变量的区别**

- 成员变量可以和局部变量重名，访问时遵循就近原则

    ```java
    class scope{
        String name = "罗念笙";
        void show(){
            System.out.println("方法中:"+name);  // 罗念笙
        }
        {
            String name = "张洛融";
            System.out.println("代码块:"+name);  // 张洛融
        }
    }
    ```

- 在同一作用域中，成员变量和局部变量都不能重复出现

    - 成员变量作用范围在当前类以及创建的对象
    - 局部变量的作用范围在当前代码块，方法, 循环等等

- 生命周期的区别，成员变量的生命周期由创建对象和销毁对象决定；局部变量的生命周期由创建代码块或者方法和销毁代码块或者方法决定

- 修饰符不同：成员变量可以有修饰符，但是局部变量不可以添加修饰符

###### 递归调用

概念：方法调用它自己本身

```java
// 例子:阶乘
// 注意：递归必须会有结束语句，否则就会无限循环，最终导致栈溢出
public int factorial(int num){
    if(num == 1)  return num; // 结束语句
    else  return num * factorial(num-1);
}    
```

**反转链表(206)**

![image-20220319110420306](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220319110420306.png) 

> 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
>
> 示例 1：输入：head = [1,2,3,4,5]
> 			  输出：[5,4,3,2,1]
> 示例 2：输入：head = [1,2]
> 			  输出：[2,1]
> 示例 3：输入：head = []
> 			  输出：[]

**递归算法**

我们很多时候对于递归算法都有种排斥，那就是无从入手，原本正向推导就是件不容易的事，现在还要先反向构思，这难度可想而知，对初学者特别不友好。

不妨听我说说递归算法解决思路：

我觉得在使用递归算法之前，你先问问自己三个问题

1. 判断递归结束的条件是什么？（并且该结束条件最终是一定会执行到的，不然就会造成死循环）
2. 该递归方法的作用是什么？ 换句话来说你想通过这个递归方法得到什么？
3. 得到该递归方法之后，我们还需要什么才可以达到题目的要求？

```java
/**
 * 代码实现
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode reverseList(ListNode head) {
        if(head == null) return null;
        else if(head.next == null){
            return head;
        }else{
            ListNode list = reverseList(head.next);
            ListNode Node = list;
            while(Node.next != null){
                Node = Node.next;
            }
            Node.next = head;
            Node.next.next = null;
            return list;
        }
    }
}
```

**分析过程**

判断递归结束的条件：

```java
// 这个条件也是一定会执行到的
else if(head.next == null){
    return head;
}
```

该递归方法的作用：

本题的作用就是获得head反转链表（就是题目要求的实现）

```java
// reverseList(head.next)这个作用就是获得head.next的反转链表，但是不要问为什么，因为你在这一步得不到答案，你只要假定这个方法就是这个作用就可以了
ListNode list = reverseList(head.next);
```

得到该递归方法之后，我们还需要什么才可以达到题目的要求：

head.next 以后的链表是反转的，那我们只要在该节点的最后添加上head的节点是不是整体就实现了反转

然后我们反思一下是不是每次调用递归方法后我们都是干同一件事，那就是把第一节点移动到最后，这不就实现了链表最后的反转嘛（寻找到这个共同特征，那么递归方法就迎刃而解了）

```java
// 遍历 head.next反转后的链表，并在最后接上当前的head的节点
ListNode Node = list;
while(Node.next != null){
    Node = Node.next;
}
Node.next = head;
Node.next.next = null;
return list;
```

**递归习题练习（注重规律 + 条件）**

```java
// 1.斐波那契数 1 1 2 3 5 8 ...  后面的数是前面两个数之和（n > 2）
// 规律：要求的那个数 = 要求的那个数前面的数 + 要求的那个数前面的前面的数 （条件是大于2）
public int　Fibonacci(int n){
    if(n == 2 || n == 1){
        return 1;
    }
    return Fibonacci(n - 1) + Fibonacci(n - 2)；
}

// 2.猴子吃桃 原题： 一天少一半并再多次一个，当第十天发现只剩下一个桃子，试问最初有几个桃子 
// 规律：要求的当天桃子数 = （要求的明天的桃子 + 1） / 2 （条件是桃子数不等于1）
public int peachMonkey(){
    if(peachMonkey() == 1){
        return 1;
    }
     return peachMonkey()/2-1;  
}

/**
 * 3.迷宫 8*7 （1 障碍物 0 可以通过的路）
 * 1  1  1  1  1  1  1  
 * 1  0  0  0  0  0  1  
 * 1  0  0  0  0  0  1  
 * 1  1  1  0  0  0  1  
 * 1  0  0  0  0  0  1  
 * 1  0  0  0  0  0  1  
 * 1  0  0  0  0  0  1  
 * 1  1  1  1  1  1  1
 *
 * 起点坐标（2,-2） ==> 终点坐标（6,-7）
 * 转换成数组坐标  起点坐标（1,1） ==> 终点坐标（6,5）
 */
class miGong{
    public static void main(String[] args) {

        // 创建迷宫 8*7
        int[][] map = new int[8][7];

        for (int i = 0; i < map.length; i++) {
            map[i][0] = 1;
            map[i][map[0].length-1] = 1;
        }

        for (int i = 0; i < map[0].length; i++) {
            map[0][i] = 1;
            map[map.length-1][i] = 1;
        }

        map[3][1] = 1;
        map[3][2] = 1;

        for (int i = 0; i < map.length; i++) {
            for (int j = 0; j < map[0].length;j++) {
                System.out.print(map[i][j]+"  ");
            }
            System.out.println();
        }
        System.out.println("===================");
        miGong miGong = new miGong();
        if(miGong.findWay(map,1,1)){
            for (int i = 0; i < map.length; i++) {
                for (int j = 0; j < map[0].length;j++) {
                    System.out.print(map[i][j]+"  ");
                }
                System.out.println();
            }
        }else{
            System.out.println("迷宫没有出入");
        }
    }

    /**
     * 递归方法解决走出迷宫问题
     * line , col 指的是当前的位置
     * 该方法判断当前的路能否可以走
     */
    public  Boolean findWay(int[][]map,int line,int col){
        // map 数组的各个值的含义 0 可以走的路但是没有走过 1 障碍物 2 表示走过之后可以走的路 3 表示走过，走不通的路
        if(map[6][5] == 2){
            return true;
        }else{
            // 没走过
            if(map[line][col] == 0){
                map[line][col] = 2;
                // 尝试向四个方向探索
                if(findWay(map,line - 1,col)){ // 上
                    return true;
                }else if(findWay(map,line + 1,col)){ // 下
                    return true;
                }else if(findWay(map,line,col - 1)){ // 左
                    return true;
                }else if(findWay(map,line,col + 1)){ // 右
                    return true;
                }else{
                    map[line][col] = 3;
                    return false;
                }
            }else{
                return false;
            }
        }
    }
}
// 运行效果
1  1  1  1  1  1  1  
1  0  0  0  0  0  1  
1  0  0  0  0  0  1  
1  1  1  0  0  0  1  
1  0  0  0  0  0  1  
1  0  0  0  0  0  1  
1  0  0  0  0  0  1  
1  1  1  1  1  1  1  
===================
1  1  1  1  1  1  1  
1  2  2  2  2  2  1  
1  2  2  2  2  2  1  
1  1  1  2  2  2  1  
1  3  3  2  2  2  1  
1  3  3  2  2  2  1  
1  3  3  2  2  2  1  
1  1  1  1  1  1  1  
    
// 4.汉诺塔 
class tower{
    public static void main(String[] args) {
        tower.move(64,'a','b','c');
    }

    // 方法:移动汉诺塔
    public static void move(int num,char a,char b,char c){
        // 如果只有一个盘
        if(num == 1){
            System.out.println(a +"->"+ c);
        }else{
            // 将当前的盘分成两部分,分别是:最底下一个盘以及上面的盘
            // 1.将上面的盘移到b位置借助c位置，然后将a位置最底下的盘移动到c位置
            move(num - 1,a,c,b);
            System.out.println(a +"->"+ c);

            // 2.将b位置上的盘分成两部分,分别是:最底下一个盘以及上面的盘
            // 可以将以下代码优化成:  move(num - 1,b,a,c);
            if(num == 2){
                // 2.1 如果b位置上只有一个盘，那就直接将b位置上的盘移动到c位置上
                System.out.println(b +"->" + c);
            }else{
                // 2.2 反之则将b位置上的上面的盘移动到a位置上，然后将最底下的盘移动到c位置上
                move(num - 2,b,c,a);
                System.out.println(b +"->"+ c);
                move(num - 2,a,b,c);
            }
        }
    }
}
// 运行效果
a->c
a->b
c->b
a->c
b->a
b->c
a->c
```

###### 方法重载

条件：方法名必须相同 ； 形参列表类型，类型顺序或者数量不一致  ； 与返回类型无关 ； 方法的修饰符可以不同

如果编译器找不到匹配的参数，就会产生编译时错误，因为不存在该匹配，查询匹配的过程称重载解析

比如：输出println语句

![image-20220126235245517](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220126235245517.png) 

###### 方法重写

方法重写又称方法覆盖，可以简单理解为就是子类覆盖了父类的某些方法（比如 String 的 equals()）

可以通过@Override来进行检查是否真正的重写

条件

- 重写方法不能缩小访问权限（public > protected > 默认 > private）
    - 如果子类的方法重写了父类的方法，那么子类中该方法的访问级别不允许低于父类的访问级别。这是为了确保可以使用父类实例的地方都可以使用子类实例，也就是确保满足里氏替换原则
- 参数列表必须与被重写方法相同
- 当子类和父类有一个方法的名称以及参数相同时就构成了 方法的重写，返回类型必须是相同的或者构成父类返回父类的类型 <> 子类返回子类的类型，否则会报错！
- 重写方法不能抛出新的异常，或者超过了父类范围的异常，但是可以抛出更少、更有限的异常，或者不抛出异常

**方法重载和和重写的区别**

同样的一个方法能够根据输入数据的不同，做出不同的处理，即方法的重载——有不同的参数列表（静态多态性）

而当子类继承自父类的相同方法，输入数据一样，但要做出有别于父类的操作时，你就要覆盖父类方法，即在子类中重写该方法——相同参数，不同实现（动态多态性）

|       名称       | 发生范围 | 方法名   |             形参列表             |                   返回类型                   |                    修饰符                    |
| :--------------: | :------: | -------- | :------------------------------: | :------------------------------------------: | :------------------------------------------: |
| 重载（overload） |   本类   | 必须一样 | 类型，个数或者顺序至少有一个不同 |                    无要求                    |                    无要求                    |
| 重写（override） |  父子类  | 必须一样 |             必须相同             | 返回的类型和父类返回的类型相同，或者是其子类 | 子类方法的访问范围大于等于父类方法的访问范围 |

###### 可变参数（了解）

概念：将同一个类中多个同名同功能同数据类型但参数不同的方法，封装成一个方法，就可以通过可变参数实现 （本质上就是数组形参）

格式：访问修饰符 返回数据类型 方法名(数据类型**...**  形参名) 

```java
// 求和公式
class Method{
    // 整数型
    public int add(int... nums){
        int sum = 0;
        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
        }
        return sum;
    }
    // 浮点型
    public double add(double... nums){
        double sum = 0;
        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
        }
        return sum;
    }
}
```

**注意细节**

- 可变参数传入的实参可以为0或任意多个

- 可变参数传入的实参可以为数组（实际上就是二维数组）

- 可变参数可以和普通数据类型的参数放在参数列表中，但是必须保证可变参数放在最后

    ```java
    // 一个参数列表，可变参数的个数只能出现一个
    public double add(int num,double... nums){} // right
    public double add(int... num,double... nums){} // error
    ```

---

##### 静态方法  

静态方法也称作类方法

与成员方法的语法区别就是有无 **static 关键字**

注意细节

1. 类方法量是同一个类所有对象共享
2. 类方法中不能使用和对象有关的关键字（比如：，this,super ），因为this或者super的产生需要创建对象，但是类方法在类加载的时候就出现了
3. 类方法只能访问类变量或者类方法，但是反之普通成员方法既可以访问非静态成员，也可以访问静态成员
4. 类方法的生命周期随着类的加载开始，随着类消亡而销毁
6. 如果父类中含有一个静态方法，且在子类中也含有一个返回类型、方法名、参数列表均与之相同的静态方法，那么该子类实际上只是将父类中的该同名方法进行了隐藏，而非重写。换句话说，父类和子类中含有的其实是两个没有关系的方法，它们的行为也并不具有多态性

###### Main方法

Main方法就是我们最常用的类方法（静态方法）

```java
public class HelloMain {
    /*
     * 1.main方法时虚拟机调用
     * 2.java虚拟机调用类的main方法，所以该方法的访问权限必须是public
     * 3.java虚拟机在执行main()方法时不必创建对象，所以用static
     * 4.Java执行程序 参数1 参数2 参数3【dos界面操作说明： java HelloMain hello main !】 参数1：hello 参数2：main 参数3：！
     *
     * 特别提示：
     * 1.在main()方法中，我们可以直接调用main方法所在的类的静态方法和静态属性
     * 2.但是不能直接访问该类中的非静态成员，必须创建该类的一个实例对象后，才能通过这个对象访问非静态成员
     */
    public static void main(String[]args){
        // args 是如何传入，在idea上设置 Run ->  Edit Configurations  ->  program arguments:
        // 遍历显示
        for(int i=0;i<args.length;i++){
            System.out.println("第"+(i+1)+"个参数"+args[i]);
        }
    }
}
```



#### 代码块

##### 普通代码块

普通代码块又称初始化块，属于类中的成员部分，没有方法名，没有返回，没有形参，只有方法体；普通代码块不需要被调用，而是加载对象的时候隐式调用

语法：{ // 方法体 }；（ 结尾分号可有可无 ）

```java
public class CodeBlock {
    /*
     * 代码块
     * 1.相当于另外一种形式的构造器（对构造器的补充机制），可以做初始化的操作
     * 2.场景:如果多个构造器中都有重复的语句，可以抽取到初始化块中，提高代码的重用性（如下）
     */
    public static void main(String[]args){
        new Movie("爱情神话");
    }
}
class Movie{
    private String name;
    private double price;
    private String director;
    /*
     * 下面的三个构造函数都有相同的语句，这样看起来重复
     * 代码块的使用就可以很好的解决这个问题
     */
    {
        System.out.println("电影开始~~");
    };
    public  Movie(){}
    public Movie(String name){
//        System.out.println("电影开始~~");
        this.name = name;
    }
    public Movie(String name,double price){
//        System.out.println("电影开始~~");
        this.name = name;
        this.price = price;
    }
    public Movie(String name,double price,String director){
//        System.out.println("电影开始~~");
        this.name = name;
        this.price = price;
        this.director = director;
    }
}
```

**注意细节**

- 普通代码块是随着对象的创建而执行的，每次创建对象都会调用代码块
- 如果不创建对象，只是使用类的静态成员，不会执行普通代码块

---

##### 静态代码块

静态代码块，属于类中的成员部分，没有方法名，没有返回，没有形参，只有方法体和修饰符static；静态代码块不需要被调用，而是加载类的时候隐式调用

语法：static{ // 方法体 }；（ 结尾分号可有可无 ）

**类什么时候被加载？**

1. 创建子类对象化实例或者使用子类的静态成员时，父类也会被加载
2. 使用类的静态成员时（静态属性，静态方法）

**父类和子类的静态代码块和普通代码块执行顺序是什么呢？**

- 在父类和子类都有静态代码块和普通代码块时候,创建子类实例时候的执行顺序: 父类静态代码块 --> 子类静态代码块 --> 父类普通代码块 --> 子类普通代码块
- 在父类和子类都有静态代码块和普通代码块时候,创建父类实例时候的执行顺序: 父类静态代码块 --> 父类普通代码块
- 在父类和子类都有静态代码块和普通代码块时候,使用父类的静态成员时只调用父类的静态代码块
- 在父类和子类都有静态代码块和普通代码块时候,使用子类的静态成员时候的执行顺序: 父类静态代码块 --> 子类静态代码块 

**代码示例**

```java
public class StaticCodeBlock {
    /*
     * 静态属性初始化,静态代码块,静态方法,构造器的优先级
     * 1.父类的静态属性初始化优先级 == 父类的静态代码块优先级 （看代码的执行顺序）
     * 2.子类的静态属性初始化优先级 == 子类的静态代码块优先级 （看代码的执行顺序）
     * 3.父类的成员变量初始化优先级 == 父类的普通代码块优先级 （看代码的执行顺序）
     * 4.父类的构造器
     * 5.子类的成员变量初始化优先级 == 子类的普通代码块优先级 （看代码的执行顺序）
     * 6.子类的构造器
     * 方法调用的时候才会执行
     * public 构造函数名(){
     *    1)super()  
     *    2)普通代码块
     *    3)构造函数内容
     * }
     */
    public static void main(String[]args){
        // 使用类的静态成员时（静态属性，静态方法）
        // AA.name = "念笙";
        // AA.show();

        // 创建对象实例时（new）
        // new AA();

        // 创建子类的对象实例，父类也会被加载
        // new BB();

        // 使用子类的静态成员时（静态属性，静态方法）
        // BB.sex = "男";
        // BB.show();

        // 静态初始化,静态代码块,静态方法的优先级
           new CC();
        //   CC.show();
    }
}

class AA{
    public static String name;

    static {
        System.out.println("AA静态代码块被调用");
    }
    {
        System.out.println("AA普通代码块被调用");
    }
    public static void show(){
        System.out.println("name:"+name);
    }
}

class BB extends AA{
    public static String sex;
    static {
        System.out.println("BB静态代码块被调用");
    }
    {
        System.out.println("BB普通代码块被调用");
    }
    public static void show(){
        System.out.println("sex:"+sex);
    }
}

class CC{
    public CC(){
        // 1)super()
        // 2)普通代码块
        System.out.println("构造器被调用");
    }
    // 静态属性初始化
    private static int age = getAge();

    // 静态方法
    public static void show(){
        System.out.println("age:"+age);
    }

    // 静态代码块
    static{
        System.out.println("CC静态代码块被调用");
    }

    public static int getAge(){
        System.out.println("age:"+age);
        return 18;
    }
}
```



#### 内部类

概念：一个类的内部嵌套了另一个类结构，被嵌套的类称为内部类，嵌套其他类的类称为外部类（注意类的五大成员：属性，方法，构造器，代码块，内部类）

语法：class Outer{  // 外部类    class Inner{   // 内部类   }    }

```java
class OuterClass{ // 外部类
    int n1 = 100; // 属性
    public OuterClass(int n3){} // 构造方法
    void n2(){} //方法
    {} // 代码块
    class InnerClass{} // 内部类
}
```

内部类的分类：

- 定义在外部类局部位置（比如方法内）
    - 局部内部类（有类名）
    - 匿名内部类（没有类名,重点）
- 定义在外部类的成员位置上
    - 成员内部类（没有static修饰）
    - 静态内部类（有static修饰）

---

##### 局部内部类

概念：局部内部类是定义在外部类的局部位置（比如：方法或者代码块），有类名

1. 局部内部类可以访问外部类的所有成员变量，包含私有的类的成员
2. 局部内部类不能添加访问修饰符,但是是可以被final修饰（不被继承）
3. 作用域:仅在定义它的方法或代码块中
    - 外部类在方法中可以创建InnerPartClass对象，然后调用局部内部类的方法,不允许在方法外创建该对象
4. 如果外部类和局部内部类的成员重名时，默认遵循就近原则，如果就想访问外部类的成员，则可以使用(外部类名.this.成员)

```java
class OuterClass02{ // 外部类
    private int n1 = 100;
    public void n2(){
        class InnerPartClass{ 
            private int n1 = 20;
            public void n3(){
                // 如果外部类和局部内部类的成员重名时，默认遵循就近原则，如果想访问外部类的成员，则可以使用(外部类名.this.成员)
                System.out.println(n1); // 20
                // 解读OuterClass02.this 本质就是外部类的对象即那个对象调用了n2方法，OuterClass02.this就是那个对象，这里是out对象调用的，因此					  OuterClass02.this指向out对象（动态绑定）
                System.out.println(OuterClass02.this.n1); // 100
                System.out.println(OuterClass02.this); // com.Al_tair.innerClass_.OuterClass02@27d6c5e0
            }
        }
        // 外部类在方法中可以创建InnerPartClass对象，然后调用局部内部类的方法
        InnerPartClass innerPartClass = new InnerPartClass();
        innerPartClass.n3();
    }
}

public class InnerClass01 { // 外部其他类
    public static void main(String[] args) {
        OuterClass02 out = new OuterClass02();
        out.n2();
        System.out.println(out); // com.Al_tair.innerClass_.OuterClass02@27d6c5e0
    }
}
```

---

##### 匿名内部类

概念：定义在外部类的局部位置，没有类名

作用域： 仅仅在定义它的方法和代码块中

语法：new 类名或接口名(参数列表){  // 匿名内部类 }

```java
class OutClass{
    private int n = 10;
    public void meathod(){
        /*
         * 使用匿名内部类简化开发
         * aa的编译类型 -- AA ; aa的运行类型 -- 匿名内部类OutClass$1 (外部类名$匿名内部类的序号)
         * 1.创建匿名内部类后马上创建该实例,并返回该地址给aa
         * 2.匿名内部类只能使用一次，但是该实例对象可以反复引用，就是不能用一个匿名内部类创建多个对象实例
         * 3.不能添加访问修饰符，因为它的就是一个局部变量
         * 4.如果外部类和局部内部类的成员重名时，默认遵循就近原则，如果想访问外部类的成员，则可以使用(外部类名.this.成员)
         */
        // 第一种调用匿名内部类的内部方法
        // 这里new的不是接口实例化,而是接口的匿名内部实现类
        AA aa = new AA(){ // 向上转型
            @Override
            public void cry() {
                System.out.println("嘤嘤嘤~~");
            }
        };
        aa.cry();
        System.out.println(aa.getClass()); // class com.Al_tair.innerClass_.OutClass$1

        // 第二种调用匿名内部类的内部方法
        System.out.println(
            new AA(){
                @Override
                public void cry() {
                    System.out.println("555~~");
                }
            }.getClass()
        ); // class com.Al_tair.innerClass_.OutClass$2
    }
}
interface AA{
    void cry();
}

// 调用者
public class AnonymousInnerClass {
    public static void main(String[] args) {
        OutClass outClass = new OutClass();
        outClass.meathod();
    }
}
```

**对比传统方式和匿名内部类的区别**

- 如果实现该接口或者类的对象只被使用少次，建议使用匿名内部类
- 反之需要反复调用就可以使用传统方式减少代码的复用

```java
// 代码示例
public class Test {
    public static void main(String[] args) {
        // 当作实参直接传递，简洁高效
        show(new Paint() {
            @Override
            public void show() {
                System.out.println("最美油画！");
            }
        });

        // 传统方式
        new Picture().show();
    }

    public static void show(Paint paint){
        paint.show();
    }
}
// Paint接口
interface Paint{
    public void show();
}
class Picture implements Paint{
    @Override
    public void show() {
        System.out.println("最美油画！");
    }
}
```

---

##### 成员内部类

概念：成员内部类是定义在外部类的成员位置，并且没有static修饰

作用域： 可以直接访问外部类的所有成员

```java
public class MemberInnerDemo01 {
    public static void main(String[] args) {
        // 成员内部类的访问方式
        // 1.创建外部类的对象来调用(推荐)
        // 1.1.创建外部类的对象
        MemberOuterClass memberOuterClass = new MemberOuterClass();
        // 1.2.创建成员内部类的对象 需要加外部类名 (如: 外部类名.内部类名 对象引用名 = 外部类的对象名.new 内部类名();)
        MemberOuterClass.InnerClass innerClass = memberOuterClass.new InnerClass();

        // 2.调用外部类方法访问成员内部类
        MemberOuterClass.InnerClass innerClass2 = new MemberOuterClass().getInnerInstance();
    }
}

class MemberOuterClass{
    /*
     *  成员内部类（没有static修饰）
     *  1.可以添加任意的访问修饰符: public 默认 protected private
     *  2.成员内部类的访问方式
     *    1.成员内部类 —> 外部类成员 [直接访问]
     *    2.外部类 -> 成员内部类 [创建成员内部类的对象，再访问]
     *    3.其他外部类 -> 成员内部类 [创建外部类的对象，创建成员内部类的对象，再由访问修饰符决定访问权]
     *  3.如果外部类和局部内部类的成员重名时，默认遵循就近原则，如果想访问外部类的成员，则可以使用(外部类名.this.成员)
     */
    protected class InnerClass{}
    public InnerClass getInnerInstance(){
        return new InnerClass();
    }
}
```

---

##### 静态内部类

概念：成员内部类是定义在外部类的成员位置，并且有static修饰

作用域： 可以直接访问内部类的所有静态成员，包含私有的，但是不能访问非静态成员

```java
class StaticOuterClass{
    static class StaticInner{
        public  void say(){
            System.out.println("StaticInner 在 saying");
        }
    }
}

public class StaticInnerClass {
    public static void main(String[] args) {
       /*
        * 静态内部类 static修饰
        * 1.可以添加任何的访问修饰符: public 默认 protected private
        * 2.静态内部类的访问方式（2和3创建静态内部类的对象写法不一样）
        *   1.静态内部类 -> 外部类 [直接访问所有静态成员]
        *   2.外部类 -> 静态内部类 [创建静态内部类的对象，再访问]
        *   3.其他外部类 -> 静态内部类 [创建静态内部类的对象，再由访问修饰符决定访问权]
        *  3.如果外部类和局部内部类的成员重名时，默认遵循就近原则，如果想访问外部类的成员，则可以使用(外部类名.成员)
        */
        StaticOuterClass.StaticInner staticClass = new StaticOuterClass.StaticInner();
        staticClass.say();
    }
}
```



#### 构造器

##### 构造器的概念

构造器是一个特殊的方法，没有返回值，同时是用来类创建对象的纽带

格式： 修饰符  方法名(形参列表){ 方法体 }

```java
class person{
    int age;
    String name;
    
    // 构造器也称构造方法
    // 1.构造器修饰符：与普通方法相同
    // 2.构造器没有返回值
    // 3.方法名必须和类名一样！！！
    // 4.在创建对象时，系统会自动的调用该类的构造器完成对对象的初始化（注意：构造器非创建对象）
    public person(String name,int age){
        this.age = age;
        this.name = name;
    }
    
    // 5.如果没有有参构造器，则有一个默认的无参构造器，如果有有参构造器，则没有默认的无参构造器
    // 6.构造器重载，一个类可以有多个构造器
    public person(){}
}
```

##### 创建对象

```java
// 先声明后创建
Car car;
// 调用无参构造器
car = new Car();  // car 是对象引用，非对象本身，new Car()是对象本身

// 直接创建
Car car = new Car();
```

##### 类和对象的内存图

```java
public static void main(String[] args){
    Cat cat = new Car(); // 无参构造器
    cat.name = "小黄";
    cat.age = 18;
    cat.color = "黄色";
}
class Cat{
    String name;
    int age;
    String color;
}
```

![image-20220401105238965](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220401105238965.png) 

##### this关键字

概念：jvm虚拟机会给每个对象分配this，代表当前对象

```Java
class person{
    int age;
    String name;
    
    // this可以看作该类的属性，value就是该类的地址，我们可以通过对象的hashcode() == this.hashcode()来判断哪个对象调用，这个this就是指的是哪个对象
    public person(String name,int age){
        this.age = age;
        this.name = name;
    }
}
```

**注意细节**

- this关键字可以用来区分成员变量和局部变量

- this关键字可以用来访问本类中的属性，成员方法，构造器

    ```java
    // this不能在类定义的外部使用，只能在类定义的方法或者构造器中使用
    class Method{
        String content = "成功!";
        // 访问构造器语句：this(参数列表)
        // 注意：this调用构造器的时候必须方法第一条语句
        public Method(){
            this("优秀！")
            System.out.println("无参构造方法");
        }
        void f1(){
            // 访问属性
            String con = this.content;
            System.out.println("f1方法");
        }
        // 访问成员方法的语法：this.方法名(参数列表)；
        void f2(){
            this.f1();
            System.out.println("f2方法");
        }
    ```

##### super关键字 

用处：super 代表父类的引用，用于访问父类的方法，属性和构造器

注意细节：

- 无法访问父类的私有方法和属性
- 使用的时候必须放在构造器的第一行，因此只能调用一次父类的构造器
- 当子类的属性，方法和父类重名时，为了访问父类的成员，必须通过super关键字来完成

 **this 和 super 的区别**

|   区别点   |                          this                          |                   super                    |
| :--------: | :----------------------------------------------------: | :----------------------------------------: |
|  访问属性  | 访问本类中的属性，如果本类没有此属性则从父类中继续查找 |             从父类开始查找属性             |
|  调用方法  | 访问本类中的方法，如果本类没有此方法则从父类中继续查找 |             从父类开始查找方法             |
| 调用构造器 |         调用本类的构造器，必须放在构造器的首行         | 调用父类的构造器，必须放在子类构造器的首行 |
|    特殊    |                      表示当前对象                      |             子类中访问父类对象             |



### 面向对象编程的三大特征

#### 封装

概念：就是把抽象的数据【属性】和对数据的操作【方法】封装在一起，数据被保护在内部，程序的其他部分只能通过被授权的操作【方法】，才能对数据进行操作

好处： 1.隐藏实现的细节   2.可以对数据进行验证，保证数据安全合理 

封装的实现步骤

1. 将属性进行私有化，不能直接修改属性

2. 提供一个公共的set方法，用于对属性判断,赋值

    ```java
    public void setXxx(类型 参数名){  // Xxx表示某个属性的set方法
        // 加入数据验证的业务逻辑
        // this.属性=参数名
    } 
    ```

3. 提供一个公共的get方法，用于获取属性的值

    ```java
    public 数据类型 getXxx(){  // 权限判断，Xxx某个属性
    	return Xxx;
    }
    ```

---

#### 继承

格式：class 子类 extends 父类 { } （extends 关键字）

好处：解决代码复用性，当多个类中有相同的属性和方法时候，我们可以抽出相同属性和方法作为父类

![image-20220526225827094](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220526225827094.png) 


**注意细节**

- 子类继承了父类所有的属性和方法，但是私有属性和方法不能被直接访问，子类和父类之间必须满足 is - a 的逻辑关系

- 子类必须调用父类的构造器，完成父类的初始化，默认无参父类构造器，当父类没有无参构造器并且子类未用super指明对应的父类的构造器，编译不会通过

    ```java
    // 父类
    public class person {
        public person() {
            System.out.println("父类构造器");
        }
    }
    // 子类
    public class Child extends person{
        public Child() {
            // 默认 super();
            System.out.println("子类构造器");
        }
    }
    
    class test{
        public static void main(String[] args) {
            Child child = new Child();
        }
    }
    // 运行结果
    父类构造器
    子类构造器
    ```
    
- super and this 关键字使用的时候必须放在构造器的第一行，因此这两个方法调用不能共存在一个构造器

- java所有类都是Object类的子类

- 父类的构造器的调用不仅限于直接父类，会一直追朔直到Object类（顶级父类）

- 子类最多只能继承一个父类（单继承机制）

**内存分布图**

查找属性和方法数据根据就近原则（从调用的类的属性和方法开始，依次向父类寻找，只要找到该属性或者方法则不再继续寻找）

![image-20220203234708017](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220203234708017.png) 

---

#### 多态

 概念：方法或者对象具有多种状态，多态是建立在封装和继承之上的

方法的重载和重写体现了方法的多态

对象的多态具体体现

- 前提条件：两个对象（类）存在继承关系    

- 一个对象的编译类型和运行类型可以不一致

    ```java
    // Animal 父类 Dog 子类 Cat 子类
    Animal  animal = new Dog(); // 编译类型 Aniaml 运行类型 Dog
    animal = new Cat(); // 运行类型是可以改变的
    ```

- 编译类型在定义对象时候就确定了

- 运行类型是可以改变的

- 编译类型看定义，运行类型看 new 对象

 **细节分析**

- 多态的向上转型

    1. 本质：父类的引用指向子类的对象
    2. 语法：父类类型  引用名 = new 子类类型();
    3. 特点：编译类型看定义，运行类型看 new 对象 
    4. 用该对象调用方法的时候，只能调用父类中的方法，不能调用子类特有的方法，因为编译不通过；但是调用方法在运行类型中是先从子类开始查找方法
    5. 属性没有重写的说法，所以属性的值看编译类型

- 多态的向下转型

    1. 语法：子类类型 引用名 = （子类类型）父类引用；

    2. 只能强转父类的引用，不能强转父类的对象

    3. 可以调用子类类型中的所有成员

    4. 向下转型是为了方便能访问子类独有的属性或者方法

        ```java
        // 举例
        Animal  animal = new Dog(); // 编译类型 Aniaml 运行类型 Dog
        Dog dog = (Dog) animal; // // 编译类型 Dog 运行类型 Dog 
        ```


#### 动态绑定机制

 具体体现：

- 当调用对象方法时候，该方法会和该对象的内存地址/ 运行类型进行动态绑定
- 当调用对象的属性的时候没有动态绑定的说法

举例说明：

```java
// 举例
public class demo{
    public static void main(String[] args){
        father f = new son();
        System.out.println(f.sum()); // 40
        System.out.println(f.sum2());  // 60
    }
}

class father{ // 父类
    public int attribute = 10;
    public int sum(){
        return getAttribute() + 10; // getAttribute()绑定的是子类的该方法
    }
    public int sum2(){
        return attribute + 50; // 属性没有动态绑定机制
    }
    public int getAttribute(){
        return attribute;
    } 
    
}

class son extends father{ // 子类
    public int attribute = 30;
    public int getAttribute(){
        return attribute;
    }
}
```

### 五大设计原则 

[转载自CS-Notes](https://github.com/CyC2018/CS-Notes/blob/master/notes/%E9%9D%A2%E5%90%91%E5%AF%B9%E8%B1%A1%E6%80%9D%E6%83%B3.md)

#### 1. 单一责任原则

> 分治

换句话说就是让一个类只负责一件事，当这个类需要做过多事情的时候，就需要分解这个类

如果一个类承担的职责过多，就等于把这些职责耦合在了一起，一个职责的变化可能会削弱这个类完成其它职责的能力

#### 2. 开放封闭原则

> 类应该对扩展开放，对修改关闭

扩展就是添加新功能的意思，因此该原则要求在添加新功能时不需要修改代码

符合开闭原则最典型的设计模式是装饰者模式，它可以动态地将责任附加到对象上，而不用去修改类的代码

#### 3. 里氏替换原则

> 子类对象必须能够替换掉所有父类对象

继承是一种 IS-A 关系，子类需要能够当成父类来使用，并且需要比父类更特殊

如果不满足这个原则，那么各个子类的行为上就会有很大差异，增加继承体系的复杂度

#### 4. 接口分离原则

> 不应该强迫客户依赖于它们不用的方法

因此使用多个专门的接口比使用单一的总接口要好

#### 5. 依赖倒置原则

> 高层模块不应该依赖于低层模块，二者都应该依赖于抽象；
> 抽象不应该依赖于细节，细节应该依赖于抽象。

高层模块包含一个应用程序中重要的策略选择和业务模块，如果高层模块依赖于低层模块，那么低层模块的改动就会直接影响到高层模块，从而迫使高层模块也需要改动

依赖于抽象意味着：

- 任何变量都不应该持有一个指向具体类的指针或者引用；
- 任何类都不应该从具体类派生；
- 任何方法都不应该覆写它的任何基类中的已经实现的方法

### 其他常见原则

除了上述的经典原则，在实际开发中还有下面这些常见的设计原则

#### 1. 迪米特法则

迪米特法则又叫作最少知识原则（Least Knowledge Principle，简写 LKP），就是说一个对象应当对其他对象有尽可能少的了解，不和陌生人说话

#### 2. 合成复用原则

尽量使用对象组合，而不是通过继承来达到复用的目的

#### 3. 共同封闭原则

一起修改的类，应该组合在一起（同一个包里）。如果必须修改应用程序里的代码，我们希望所有的修改都发生在一个包里（修改关闭），而不是遍布在很多包里。

#### 4. 稳定抽象原则

最稳定的包应该是最抽象的包，不稳定的包应该是具体的包，即包的抽象程度跟它的稳定性成正比

#### 5. 稳定依赖原则

包之间的依赖关系都应该是稳定方向依赖的，包要依赖的包要比自己更具有稳定性



## 抽象类和接口

### 抽象类

引出：当父类的某些方法需要申明，但又不确定如何实现的时候，可以把这个类变成抽象类添加 abstract 关键字

抽象类和普通类最大的区别：抽象类不能被实例化；抽象类可以有抽象方法

抽象类和抽象方法的关系：抽象类一般会包含抽象方法，抽象方法一定位于抽象类或者接口中

```java
public class AbstractDemo {
    public static void main(String[] args) {
        // 抽象类不能被实例化
        // AbstractClassExample ac1 = new AbstractClassExample(); 
        // 抽象类会被继承，由自己的子类实现方法
        AbstractClassExample ac2 = new AbstractExtendClassExample();
        // 能直接通过类名.静态属性/静态方法来访问抽象类中的静态属性/静态方法
        System.out.println(AbstractClassExample.x);
        Animal.func3();
    }
}
// 抽象类: 访问修饰符 abstract class 类名{} (class 关键字要放在 abstract关键字后面)
// 抽象类的本质还是类可以有方法，属性，代码块，构造器，但是抽象类不能被实例化
public abstract class AbstractClassExample {
    // 属性
    private int y;
    // 静态属性
    public static int x;
    // 构造器：可以被子类用super关键字调用构造器
    public AbstractClassExample(){}
    // 代码块
    {}
	// 抽象方法：不能使用private,final和static修饰符，因为这些修饰符都是和重写相违背的
    // 访问修饰符 abstract 返回类型 方法名(参数列表)； // 没有方法体
    public abstract void func1();
    // 普通方法
    public void func2() {
        System.out.println("func2");
    }
    // 静态方法
    public static void func3() {
        System.out.println("func3");
    }
}
// 继承抽象类，必须重写该抽象类的抽象方法
class AbstractExtendClassExample extends AbstractClassExample {
    @Override
    public void func1() {
        System.out.println("func1");
    }
}
// 如果一个类继承了抽象类,则它必须实现抽象类的所有抽象方法，除非它自己也声明为abstract;如果子类实现抽象类的全部抽象方法，则子类的子类就不需要实现了该抽象类的抽象方法
abstract class AbstractExtendAbstractClassExample extends AbstractClassExample {}
```

---

### 接口

#### 接口的概述

概念：接口不是类，而是对希望符合这个接口的类的一组需求，接口是抽象类的延伸，接口是弥补抽象类不能实现多继承的缺点

在jdk8之前都是没有方法体的抽象方法；自从jdk8开始，接口的方法可以有具体实现，但是必须是静态方法或者是默认方法（添加default关键字）

```java
// 访问修饰符 interface 接口名{}  访问修饰符：public 和默认  
interface Interface{
    // 静态属性 默认是public static final修饰
    int n1 = 10;
    
    // 静态内部类 默认是public static final修饰，可以实现当前接口
    class InterfaceInnerClass{};
    
    // 静态方法  默认是public修饰
    static void method3(){
        System.out.println("静态方法");
    }

    // 抽象方法  默认是public abstract
     void method1();

    // 默认方法 添加default关键字  默认是public 
    default public void method2(){
        System.out.println("默认方法");
    }
} 

// class 类名 implements 接口
class ImplInterface implements Interface{
    // 必须实现的抽象方法
    public void method1() {};
    
    public static void main(String[] args) {
        // 接口不能被实例化
        //  Interface interfaces = new Interface();  error
        // 可以实现接口的静态内部类
        Interface.InterfaceInnerClass innerClass = new Interface.InterfaceInnerClass();
        innerClass.method3();
        
        // 可以通过接口名.静态方法名来调用静态方法 接口名.属性名来访问属性
        Interface.method3();
        System.out.println(Interface.n1);
    }
}

// 一个非抽象类实现了该接口就必须实现该接口上的所有抽象方法，抽象类去实现接口时候，可以不用实现接口的抽象方法
abstract class AbstractImplInterface implements Interface{}
```

注意：一个类同时可以实现多个接口，一个接口不能继承其他的类，但是可以继承多个其他接口

```java
// 接口 <-> 接口 AND 类 <-> 类 称 继承
// 类 -> 接口 称 实现
// 顶级接口
interface top{}

// 父级接口  一个接口不能继承其他的类，但是可以继承多个其他接口
interface secondTop extends top{}

//另外一个接口
interface another{}

// 实现类 一个类同时可以实现多个接口
class imp implements secondTop,another{}
```

#### 接口的多态性

```java
// Usb接口
public interface UsbInterface {  
    // 规定相关接口的方法
    public void start();
    public void end();
}

// 相机实现了该接口
public class Camera implements UsbInterface{ 
    @Override
    public void start() {
        System.out.println("照相机开始运行了~");
    }
    @Override
    public void end() {
        System.out.println("照相机开始关机了~");
    }
}

// 手机实现了该接口
public class Phone implements UsbInterface{ // 实现接口
    @Override
    public void start() {
        System.out.println("手机开始运行了~");
    }
    @Override
    public void end() {
        System.out.println("手机开始关机了~");
    }
}

// 接口插入，分别实现不同功能
public class Computer {
    // 计算机工作
    public  void work(UsbInterface usbInterface){
        usbInterface.start();
        usbInterface.end();
    }
}

public class Interface01 {
    /*
     * 接口多态特性
     * 1）既可以接收手机对象，又可以接受相机对象，就体现了接口多态（接口引用可以指向实现了该接口的类的对象）
     * 2）多态数组
     * usbs[i] instanceof Phone 向下转型,判读Usb接口是否为Phone
     * 接口类型的变量可以指向实现了该接口的类的对象的实例
     */
    public static void main(String[]args){
        // 创建手机和相机对象
        Camera camera = new Camera();
        Phone phone = new Phone();
        // 创建电脑对象
        Computer computer = new Computer();
        // 插入接口，相机和手机分别运作
        computer.work(phone);
        computer.work(camera);
        // 多态数组
        UsbInterface[] UsbS = new UsbInterface[2]; 
        UsbS[0] = new Phone(); 
        UsbS[1] =  new Camera();
        for (int i = 0; i < UsbS.length; i++) {
            computer.work(UsbS[i]);
        }
    }
}
```

---

**接口实现  Vs  继承类**

1. 接口和继承解决的问题不同
    继承的价值主要在于:解决代码的复用性和可维护性
    接口的价值主要在于:设计好各种规范（方法）,让其他类去实现这些方法

2. 接口比继承更加灵活
    继承满足is-a的关系,而接口只需满足like-a的关系

3. 接口在一定程度上实现代码解耦[接口的规范性+动态绑定


---

**抽象类 Vs 接口**

-  从设计层面上看，抽象类提供了一种 IS-A 关系，那么就必须满足里式替换原则，即子类对象必须能够替换掉所有父类对象。而接口更像是一种 LIKE-A 关系，它只是提供一种方法实现契约，并不要求接口和实现接口的类具有 IS-A 关系
-  一个类只能继承一个抽象类，而一个类却可以实现多个接口
-  接口的成员只能是 public 的，而抽象类的成员可以有多种访问权限（接口不能有代码块，抽象类和普通类就是多了抽象方法）
- 抽象可以有普通方法（含有方法体），接口只能是默认方法（带有default关键字）

**使用选择**

使用接口:

- 需要让不相关的类都实现一个方法，例如不相关的类都可以实现 Compareable 接口中的 compareTo() 方法
- 需要使用多重继承（通过多个接口实现弥补单继承）

使用抽象类:

- 需要在几个相关的类中共享代码

- 需要能控制继承来的成员的访问权限，而不是都为 public




## 枚举类

概念：枚举是一种特殊的类，里面只包含一组有限的特定的对象

### 自定义枚举

```java
// 案例：创建春夏秋冬四个季节
public class EnumClass01 {
    public static void main(String[] args) {
        System.out.println(EnumDemo.WINTER);
        System.out.println(EnumDemo.SUMMER);
        System.out.println(EnumDemo.AUTUMN);
        System.out.println(EnumDemo.SPRING.toString());
    }
}
/*
 * 自定义枚举 （枚举对象名通常为大写字母）
 * 1）构造器私有化 => 外部不能创建对象
 * 2）去掉setXxx方法 => 外部不能修改属性
 * 3）直接创建固定的对象 => 枚举的特定用法
 * 4）可以使用 final static 修饰符优化 => 防止类初始化的时候加载对象
 * 5）可以提供get方法,重写toString方法用来输出
 */
class EnumDemo{
    private String seasonName;
    private String seasonFeature;

    public String getSeasonFeature() {
        return seasonFeature;
    }

    public String getSeasonName() {
        return seasonName;
    }

    //构造器
    private EnumDemo(String seasonName,String seasonFeature){
        this.seasonName = seasonName;
        this.seasonFeature = seasonFeature;
    }
    // 创建枚举对象
    final static EnumDemo SPRING = new EnumDemo("春天","温暖");
    final static EnumDemo SUMMER = new EnumDemo("夏天","炎热");
    final static EnumDemo AUTUMN = new EnumDemo("秋天","凉爽");
    final static EnumDemo WINTER = new EnumDemo("冬天","寒冷");

    @Override
    public String toString() {
        return "["+getSeasonName()+"--->"+getSeasonFeature()+"]";
    }
}
```

### enum关键字实现枚举

```java
public class EnumClass02 {
    public static void main(String[] args) {
        System.out.println(Session.AUTUMN); // [秋天--->凉爽]
    }
}
/*
 * 使用enum关键字来实现枚举
 * 1.当我们使用enum关键字开发一个枚举类时，默认会继承Enum类  java.lang.Enum<com.Al_tair.enum_.Session>
 * 反编译javap Session.class：
 * final class com.Al_tair.enum_.Session extends java.lang.Enum<com.Al_tair.enum_.Session> {
 *   public static final com.Al_tair.enum_.Session SPRING;
 *   public static final com.Al_tair.enum_.Session SUMMER;
 *   public static final com.Al_tair.enum_.Session AUTUMN;
 *   public static final com.Al_tair.enum_.Session WINTER;
 *   public static com.Al_tair.enum_.Session[] values();  // 隐藏
 *   public static com.Al_tair.enum_.Session valueOf(java.lang.String); 
 *   public java.lang.String getSeasonFeature();
 *   public java.lang.String getSeasonName();
 *   public java.lang.String toString();
 *   static {};
 * }
 */

// Enum枚举类：使用关键字enum替代class
// 用enum关键字后,就不能在继承其他类了,因为会隐式继承Enum类(如上反编译文件),但是仍然是类,所以可以实现接口
enum Session{
    
    // 格式: 形式常量名（实参列表）
    // 如果有多个常量对象使用逗号间隔；并且要将定义常量对象写在最前面
    SPRING("春天","温暖"),
    SUMMER("夏天","炎热"),
    AUTUMN("秋天","凉爽"),
    // 如果我们是使用无参构造器的时候，创建常量对象可以省略括号
    WINTER;
    
    private String seasonName;
    private String seasonFeature;
    
    // 构造器
    Session() {}
    private Session(String seasonName,String seasonFeature){
        this.seasonName = seasonName;
        this.seasonFeature = seasonFeature;
    }

    public String getSeasonFeature() {
        return seasonFeature;
    }
    public String getSeasonName() {
        return seasonName;
    }

    @Override
    public String toString() {
        return "["+getSeasonName()+"--->"+getSeasonFeature()+"]";
    }
}
```

### 枚举常用方法

![image-20220221102947758](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220221102947758.png) 

```java
 // 测试枚举常用方法
enum Week{
    MONDAY("星期一"),TUESDAY("星期二"),WEDNESDAY("星期三"),THURSDAY("星期四"),FRIDAY("星期五"),SATURDAY("星期六"),SUNDAY("星期日");

    private String WeekName;

    private Week(String WeekName) {
        this.WeekName = WeekName;
    }
}

class testMethod{
    public static void main(String[] args) {
        Week f = Week.FRIDAY;
        /*
        	name() 默认获得父类Enum重写的toString()的方法;如果枚举类有重写toString()方法
             public String toString() {
                return name; // 返回对象名
            }
        */
        System.out.println(f.toString()); // FRIDAY
        System.out.println(f.toString() == f.name()); // true

        // ordinal() 返回此枚举常量的序数（它在其枚举声明中的位置，其中初始常量的序数为0）
        System.out.println(f.ordinal()); // 4

        // values();  // 隐藏，Enum类中无法查看 本质: 包含所有常量对象的数组
        // 实现效果: MONDAY  TUESDAY  WEDNESDAY  THURSDAY  FRIDAY  SATURDAY  SUNDAY
        for (int i = 0; i < Week.values().length; i++) {
            System.out.print(Week.values()[i]+"  ");
        }

        /* 
         * valueOf()方法 将字符串转换成枚举对象，要求字符串必须为已有的常量对象名，否则会报错
         * 源码如下
         *     public static <T extends Enum<T>> T valueOf(Class<T> enumType,String name) {
         *         T result = enumType.enumConstantDirectory().get(name);
         *         if (result != null) return result;
         *         if (name == null) throw new NullPointerException("Name is null");
         *         throw new IllegalArgumentException("No enum constant " +
         *                      enumType.getCanonicalName() + "." + name);
         *     }
         */
        Week m = Week.valueOf("MONDAY");
        System.out.println(m.toString()); // MONDAY

        /*
         * compareTo()方法：比较两个枚举常量对象序号，返回两个枚举常量序号（ordinal）差
         *     public final int compareTo(E o) {
         *         Enum<?> other = (Enum<?>)o;
         *         Enum<E> self = this;
         *         if (self.getClass() != other.getClass() && // optimization
         *             self.getDeclaringClass() != other.getDeclaringClass())
         *             throw new ClassCastException();
         *         return self.ordinal - other.ordinal; // 比较编号
         *     }
         */
        System.out.println(m.compareTo(f)); // -4
    }
}
```



## 注解机制

### 注解

概念：注解是绑定到程序源代码元素的元数据，对运行代码的操作没有影响。

#### @Deprecated  

概念：表示代码被弃用，如果使用了被@Deprecated注解的代码则编译器将发出警告

```java
@Deprecated
特征: 有划线
1.该注解修饰某个元素，表示该元素已经过时
2.即不推荐使用，但可以用
// @Deprecated 定义
@Documented // 能生成javadoc文档
@Retention(RetentionPolicy.RUNTIME) // 保留至运行时期间
// 可以添加在 构造器 成员变量 局部变量 成员方法 包 方法参数 （类、接口、枚举类）
@Target(value={CONSTRUCTOR, FIELD, LOCAL_VARIABLE, METHOD, PACKAGE, MODULE, PARAMETER, TYPE}) 
public @interface Deprecated {
    // 返回注释元素被弃用的java版本
    String since() default "";

    // 指示带注释的元素是否会在未来版本中被删除
    boolean forRemoval() default false;
}
```

#### @Override  

概念：表示当前的方法定义将覆盖父类中的方法

```java
// @Override的定义
@Target(ElementType.METHOD) // 可以添加在成员方法
@Retention(RetentionPolicy.SOURCE) // 只在编译时有效
public @interface Override { // @interface 不是接口,代表注解(jdk5.0之后添加)
}
```

#### @SuppressWarnings

概念：表示代码被弃用，如果使用了被@Deprecated注解的代码则编译器将发出警告

```java
// @SuppressWarnings定义
// 使用格式：@SuppressWarning({"","",""...});
// 例子：@SuppressWarning({"all"}); 抑制所有警告
@Target({TYPE, FIELD, METHOD, PARAMETER, CONSTRUCTOR, LOCAL_VARIABLE})
@Retention(RetentionPolicy.SOURCE)
public @interface SuppressWarnings {
    String[] value();
}
```

它能够修饰的程序元素包括类型、属性、方法、参数、构造器、局部变量，只能存活在源码时，取值为String[]。它的作用是告诉编译器忽略指定的警告信息，它可以取的值如下所示：

|           参数           |                        作用                        |
| :----------------------: | :------------------------------------------------: |
|           all            |                    抑制所有警告                    |
|          boxing          |            抑制装箱、拆箱操作时候的警告            |
|           cast           |                 抑制映射相关的警告                 |
|         dep-ann          |                 抑制启用注释的警告                 |
|       deprecation        |                  抑制过期方法警告                  |
|       fallthrough        |          抑制确在switch中缺失breaks的警告          |
|         finally          |           抑制finally模块没有返回的警告            |
|          hiding          |         抑制与隐藏变数的区域变数相关的警告         |
|    incomplete-switch     |              忽略没有完整的switch语句              |
|           nls            |                忽略非nls格式的字符                 |
|           null           |                  忽略对null的操作                  |
|         rawtype          |        使用generics时忽略没有指定相应的类型        |
|       restriction        |        抑制与使用不建议或禁止参照相关的警告        |
|          serial          | 忽略在serializable类中没有声明serialVersionUID变量 |
|      static-access       |            抑制不正确的静态访问方式警告            |
|     synthetic-access     |       抑制子类没有按最优方法访问内部类的警告       |
|        unchecked         |           抑制没有进行类型检查操作的警告           |
| unqualified-field-access |             抑制没有权限访问的域的警告             |
|          unused          |             抑制没被使用过的代码的警告             |



### 元注解

概念: 元注解是用于定义注解的注解

#### @Target 

指定注解可以在哪些地方使用(如 @Target(ElementType.METHOD)  // 方法中使用 )

```java
public enum ElementType {
    // 类、接口（包括注解类型）、枚举或记录声明
    TYPE,
    // 字段声明（包括枚举常量）
    FIELD,
    // 方法声明
    METHOD,
    // 普通参数声明
    PARAMETER,
    // 构造函数声明
    CONSTRUCTOR,
    // 局部变量声明
    LOCAL_VARIABLE,
    // 注解类型声明
    ANNOTATION_TYPE,
    // 包声明
    PACKAGE,
    // 类型参数声明 since jdk1.8
    TYPE_PARAMETER,
    // 使用类型 since jdk1.8
    TYPE_USE,
    // 模块声明 since jdk9
    MODULE,
}

```

#### @Retention 

指定注解的作用范围,三种策略：SOURCE,CLASS,RUNTIME，定义在RetentionPolicy枚举中

- RetentionPolicy.SOURCE   源文件保留
- RetentionPolicy.CLASS   编译期保留
- RetentionPolicy.RUNTIME 运行期保留，可通过反射去获取注解信息

#### @Documented 

描述在使用 javadoc 工具为类生成帮助文档时是否要保留其注解信息

#### @Inherited 

子类会继承父类的注解

```java
// @Override的源码案例分析
@Target(ElementType.METHOD) // 方法中使用
@Retention(RetentionPolicy.SOURCE)  // 该注解主要是用于编译，所以在编译之后丢弃
public @interface Override { // @interface 不是接口,代表注解(jdk5.0之后添加)
}
```

**测试代码**

```java
// 自定义注解类 TestInheritedAnnotation
// 使用元注解@Inherited
@Inherited
@Retention(RetentionPolicy.RUNTIME)
@Target({ElementType.TYPE,ElementType.METHOD})
@interface TestInheritedAnnotation {
    String [] values();
    int number();
}
// 父类
@TestInheritedAnnotation(values = {"lns"}, number = 100)
class Person {
}
// 子类
class Student extends Person{
    public static void main(String[] args) {
        // RetentionPolicy.RUNTIME 注解保存至运行期间，所以可以通过反射获取该注解
        Class cls = Student.class;
        Annotation[] annotations = cls.getAnnotations();
        for (Annotation anno : annotations) {
            System.out.println(anno.toString());
        }
    }
}

// 结果
@com.Al_tair.mhlProject.view.TestInheritedAnnotation(values={"lns"}, number=100)
```

#### @Native (jdk8)

使用 @Native 注解修饰成员变量，则表示这个变量可以被本地代码引用(了解)

#### @Repeatable (jdk8)

重复注解：允许在同一申明类型(类，属性，或方法)的多次使用同一个注解

[重复注解详细说明](https://dzone.com/articles/repeatable-annotations-in-java-8-1)

作用：仅仅是为了提高代码可读性



## 异常机制

### 基本概念

概念: 程序执行中发生的不正常情况(语法错误和逻辑错误不是异常)

java异常机制可以使程序中异常处理代码和正常业务代码分离，提高程序健壮性

### Throwable

Throwable 是 Java 语言中所有错误与异常的超类

Throwable 包含两个子类：Error（错误）和 Exception（异常）如下图

![image-20220222105957339](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220222105957339.png)

### Error（错误）

Error 类及其子类：程序中无法处理的错误，表示运行应用程序中出现了严重的错误

此类错误一般表示代码运行时 JVM 出现问题。通常有 Virtual MachineError（虚拟机运行错误）、NoClassDefFoundError（类定义错误）等。比如 OutOfMemoryError：内存不足错误；StackOverflowError：栈溢出错误。此类错误发生时，JVM 将终止线程

这些错误是不受检异常，非代码性错误。因此，当此类错误发生时，应用程序不应该去处理此类错误

### Exception（异常）

异常分为两大类：运行时异常，编译时异常

- 运行时异常是编译器不要求强制处置的异常（一般是逻辑错误），运行时异常和错误为**非可查异常**，不需要处理
- 编译时异常是编译器要求必须处置的异常

![image-20220410133947189](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220410133947189.png)

#### 编译异常

概念：编译异常又可以称为**可查异常**，编译异常是RuntimeException以外的异常，是编译器要求必须处置的异常

| 异常类型                  | 发生的场景                         |
| ------------------------- | ---------------------------------- |
| SQLException              | 操作数据库时，查询表可能发生异常   |
| lOException               | 操作文件时，发生的异常             |
| FileNotFoundException     | 当操作一个不存在的文件时，发生异常 |
| ClassNotFoundException    | 加载类，而该类不存在时，异常       |
| EOFException              | 操作文件，到文件末尾，发生异常     |
| IllegalArguementException | 参数异常                           |

#### 运行时异常

运行时异常，编译器不要求强制处置的异常（一般是逻辑错误）

##### 空指针异常

NullPointException ：当应用程序在需要使用对象的地方使用null，抛出该异常

```java
// 实例
class NullPointException{
    public static void main(String[] args) {
        String name = null;
        System.out.println(name.length()); // NullPointerException
    }
}
```

##### 数字运算异常

ArithmeticException：当出现异常运算条件时，抛出异常

```java
// 实例
class ArithmeticException {
    public static void main(String[] args) {
        int num1 = 10,num2 = 0;
        int div = num1/num2; // ArithmeticException
    }
}
```

##### 数组下标越界

ArrayIndexOutOfBoundsException：用非法索引访问数组的异常

```java
// 实例
class ArrayIndexOutOfBoundsException {
    public static void main(String[] args) {
        int[] array = new int[3];
        System.out.println(array[3]); //ArrayIndexOutOfBoundsException
    }
}
```

##### 类型转换异常

ClassCastException：当试图将对象强制类型转换为不是该实例的子类，抛出该异常

```java
// 实例
class ClassCastException {
    public static void main(String[] args) {
         A b = new B();
         C c = (C)b; // ClassCastException
    }
}
class A{}
class B extends A{}
class C extends A{}
```

##### 数字格式不正确异常

NumberFormatException：当应用程序试图将字符串转换成一种数值类型，将抛出该异常

```java
// 实例
class NumberFormatException {
    public static void main(String[] args) {
        String name = "";
        int num = Integer.parseInt(name); // NumberFormatException
    }
}
```

 

### 异常处理

**异常处理关键字**

- **try** – 用于监听。将要被监听的代码(可能抛出异常的代码)放在try语句块之内，当try语句块内发生异常时，异常就被抛出。
- **catch** – 用于捕获异常。catch用来捕获try语句块中发生的异常。
- **finally** – finally语句块总是会被执行。它主要用于回收在try块里打开的资源(如数据库连接、网络连接和磁盘文件)。只有finally块，执行完成之后，才会回来执行try或者catch块中的return或者throw语句，如果finally中使用了return或者throw等终止方法的语句，则就不会跳回执行，直接停止。
- **throw** – 用于抛出异常。
- **throws** – 用在方法签名中，用于声明该方法可能抛出的异常。

**两种处理方式**

**1.try - catch - finally** （程序员在代码中捕获异常，自行处理）

注意：try、catch和finally都不能单独使用，只能是try-catch、try-finally或者try-catch-finally

```java
// try - catch - finally格式如下
try{
    // 代码可能有异常
    // 如果没有出现异常,则执行try块中所有的语句，反之有出现异常,则不再执行try块中剩余的语句，抛出异常
}catch(NullPointerException e){ 
    // 捕获异常
    // 1.当异常发生时，才会执行catch内的代码
    // 2.系统将异常封装成Exception对象e,传递给catch
    // 3.同一个 catch 也可以捕获多种类型异常，用 | 隔开
}catch(RuntimeException e){ 
    // 可以有多个catch语句进行捕获不同的异常，要求子类异常在父类异常之前，不然就没有子类异常存在的意义
}finally{
    // 不管是否有异常，一般都会执行
    // 总结：finally遇见如下情况不会执行
    // 1.在前面的代码中用了System.exit()退出程序。
    // 2.finally语句块中发生了异常。
    // 3.程序所在的线程死亡。
    // 4.关闭CPU。
}

// 可以进行try-finally配合使用，不进行其他异常捕获（包括throws），不管是否有异常都执行某些语句，然后程序退出
try{  
}finally{
}
```

**2.throw或者throws 将异常抛出**（交给调用者来处理，最顶级处理者JVM）

|  throws  VS throw  |           意义           |    位置    | 后面的语句 |
| :----------------: | :----------------------: | :--------: | :--------: |
| throws(异常的申明) |    异常处理的一种方式    | 方法声明处 |  异常类型  |
| throw(异常的抛出)  | 手动生成异常对象的关键字 |  方法体中  |  异常对象  |

**测试代码**

```java
// throws(异常的申明)
class Father{
    // RuntimeException 是 NullPointerException 的父类
    // 运行时异常：如果没有处理,默认throws的方式处理
    public void methos() throws RuntimeException{}
}

class Son extends Father{
    // 子类重写的方法,所抛出的异常类型要么和父类抛出的异常一样,要么为父类抛出异常的子类型
    @Override
    public void methos() throws NullPointerException{
        super.methos();
    }
}

// throw (异常的抛出)
public double method(int num,int value) {
    if(value == 0) {
        throw new ArithmeticException("参数不能为0"); // 抛出一个运行时异常
    }
    return num / value;
}
```

throw或者throws 抛出形式：

![image-20220222155846503](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220222155846503.png) 



### 自定义异常

继承Throwable的子类或者间接子类

运行时异常通常继承RuntimeException；编译时异常通常继承Exception

```java
// 例子
class test{
    public static void main(String[] args) {
        int age = 208;
        /*
         * Exception in thread "main" com.Al_tair.exception_.AgeJudge: 不符合年龄
         * 	at com.Al_tair.exception_.test.main(Exception01.java:71)
         */
        if(!(age >= 0 && age <= 140)){
            throw new AgeJudge("不符合年龄");
        }
    }
}
class AgeJudge extends RuntimeException{
    public AgeJudge(String message) {
        super(message);
    }
}
```



### JVM处理异常的机制

#### 异常表

异常发生时的机制如下 [取自java全栈知识体系](https://pdai.tech/md/java/basic/java-basic-x-exception.html#%E6%B7%B1%E5%85%A5%E7%90%86%E8%A7%A3%E5%BC%82%E5%B8%B8)

1. JVM会在当前出现异常的方法中，查找异常表，是否有合适的处理者来处理
2. 如果当前方法异常表不为空，并且异常符合处理者的from和to节点，并且type也匹配，则JVM调用位于target的调用者来处理
3. 如果上一条未找到合理的处理者，则继续查找异常表中的剩余条目
4. 如果当前方法的异常表无法处理，则向上查找（弹栈处理）刚刚调用该方法的调用处，并重复上面的操作
5. .如果所有的栈帧被弹出，仍然没有处理，则抛给当前的Thread，Thread则会终止
6. 如果当前Thread为最后一个非守护线程，且未处理异常，则会导致JVM终止运行

```java
// 测试代码 test.java
public class test{
    public static int[] list  = new int[2];
    public static void main(String[]args){
        try {
            int a = list[2];
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
```

```cmd
# 反编译 test.class文件
public class test {
  public static int[] list;

  public test();
    Code:
       0: aload_0
       1: invokespecial #1                  // Method java/lang/Object."<init>":()V
       4: return

  public static void main(java.lang.String[]);
    Code:
       0: getstatic     #7                  // Field list:[I
       3: iconst_2
       4: iaload
       5: istore_1
       6: goto          14
       9: astore_1
      10: aload_1
      11: invokevirtual #15                 // Method java/lang/Exception.printStackTrace:()V
      14: return
    Exception table:   异常表
    # from 可能发生异常的起始点
	# to 可能发生异常的结束点
	# target 上述from和to之前发生异常后的异常处理者的位置
	# type 异常处理者处理的异常的类信息
       from    to  target type
           0     6     9   Class java/lang/Exception

  static {};
    Code:
       0: iconst_2
       1: newarray       int
       3: putstatic     #7                  // Field list:[I
       6: return
}
```



## 常用类

### Object类

|    修饰符和类型    | 方法的描述                                                   |
| :----------------: | :----------------------------------------------------------- |
| `protected Object` | `clone()`创建并返回此对象的副本                              |
|     `boolean`      | `equals(Object obj)`指示一些其他对象是否等于此               |
|  `protected void`  | `finalize()`当垃圾收集确定不再有对该对象的引用时，垃圾收集器在对象上调用该对象 |
|     `Class<?>`     | `getClass()`返回此 `Object`的运行时类                        |
|       `int`        | `hashCode()`返回对象的哈希码值                               |
|       `void`       | `notify()`唤醒正在等待对象监视器的单个线程                   |
|       `void`       | `notifyAll()`唤醒正在等待对象监视器的所有线程                |
|      `String`      | `toString()`返回对象的字符串表示形式                         |
|       `void`       | `wait()`导致当前线程等待，直到另一个线程调用该对象的 [`notify()`](../../java/lang/Object.html#notify--)方法或 [`notifyAll()`](../../java/lang/Object.html#notifyAll--)方法 |
|       `void`       | `wait(long timeout)`导致当前线程等待，直到另一个线程调用 [`notify()`](../../java/lang/Object.html#notify--)方法或该对象的 [`notifyAll()`](../../java/lang/Object.html#notifyAll--)方法，或者指定的时间已过 |
|       `void`       | `wait(long timeout, int nanos)`导致当前线程等待，直到另一个线程调用该对象的 [`notify()`](../../java/lang/Object.html#notify--)方法或 [`notifyAll()`](../../java/lang/Object.html#notifyAll--)方法，或者某些其他线程中断当前线程，或一定量的实时时间 |

#### equals

**1.五种特性**

```java
x.equals(x); // 自反性 true
x.equals(y) == y.equals(x); // 对称性，一致性 true
if (x.equals(y) && y.equals(z)) x.equals(z); // 传递性 true
x.equals(null); // 与 null 的比较  false
```

**2.equals方法 和 == 比较运算符 的区别**

 == ：如果判断基本数据类型，判断值是否相同；如果判断引用数据类型，判断的是地址是否相同（是否是同一个对象）

equals：是Object类中的方法，只能用来判断引用数据类型，默认是判断地址是否相同，但是像String类重写了该方法，用来判断字符串值是否相同

```java
// Object类的源码
public boolean equals(Object obj) {
    return (this == obj);
}

/**
 * String类的源码
 * Compares this string to the specified object.  The result is {@code
 * true} if and only if the argument is not {@code null} and is a {@code
 * String} object that represents the same sequence of characters as this
 * object.
 */
public boolean equals(Object anObject) {
    if (this == anObject) { // 比较地址是否相同
        return true;
    }
    if (anObject instanceof String) { // 判断是否为String 或者 String的父类
        String aString = (String)anObject; // 向下转型：目的是为了获得String类的属性和方法
        if (!COMPACT_STRINGS || this.coder == aString.coder) {
            return StringLatin1.equals(value, aString.value);
        }
    }
    return false;
}

// StringLatin1类的源码 底层就是比较字符数组中每个字符是否相同
@HotSpotIntrinsicCandidate
public static boolean equals(byte[] value, byte[] other) {
    if (value.length == other.length) {
        for (int i = 0; i < value.length; i++) {
            if (value[i] != other[i]) {
                return false;
            }
        }
        return true;
    }
    return false;
}
```

####  hashCode

作用：返回该对象的哈希码值（散列值），是为了提高哈希表的性能

注意细节

- 提高具有哈希结构的容器的效率
- 两个引用都指向同一个对象，则哈希值一定相同
- 哈希值主要是根据地址来的，将对象的内部地址转换成一个整数来实现的

#### toString

默认返回：全类名 + @ + 哈希值十六进制

作用：用于返回该对象的属性信息

```java
// Object源码
// java.lang.Object@16b98e56
public String toString() {
    return getClass().getName() + "@" + Integer.toHexString(hashCode());
}
```

当直接输出一个对象时，toString方法会被默认的调用

```java
Object o = new Object();
System.out.println(o.toString()); // java.lang.Object@16b98e56
System.out.println(o); //java.lang.Object@16b98e56
```

####  clone()

概念：clone() 是 Object 的 protected 方法，它不是 public，一个类不显式去重写 clone()，其它类就不能直接去调用该类实例的 clone() 方法

```java
@HotSpotIntrinsicCandidate
protected native Object clone() throws CloneNotSupportedException;
```

Cloneable 接口只是规定，如果一个类没有实现 Cloneable 接口又调用了 clone() 方法，将会抛出异常

```java
public class ObjectDemo01 {
    public static void main(String[] args) throws CloneNotSupportedException {
        cloneImpl clone = new cloneImpl();
        clone.clone();
    }
}

// 没有实现Cloneable接口，直接调用clone.clone()会出现CloneNotSupportedException异常
class cloneImpl implements Cloneable{
    @Override
    protected Object clone() throws CloneNotSupportedException {
        return super.clone();
    }
}
// Invoking Object's clone method on an instance that does not implement Cloneable
// Cloneable接口原码
public interface Cloneable {
}
```

**区分浅拷贝和深拷贝**

- 浅拷贝：拷贝对象和原始对象的引用类型引用同一个对象
- 深拷贝：拷贝对象和原始对象的引用类型引用不同对象

可以使用重写的方法进行拷贝，但是方式复杂并且有风险，并且还需要类型转换，可以使用拷贝构造函数或者拷贝工厂来拷贝一个对象（[例子取自java全栈体系](https://pdai.tech/md/java/basic/java-basic-lan-basic.html#object-%E9%80%9A%E7%94%A8%E6%96%B9%E6%B3%95)）

```java
public class CloneConstructorExample {
    private int[] arr;

    public CloneConstructorExample() {
        arr = new int[10];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = i;
        }
    }

    public CloneConstructorExample(CloneConstructorExample original) {
        arr = new int[original.arr.length];
        for (int i = 0; i < original.arr.length; i++) {
            arr[i] = original.arr[i];
        }
    }

    public void set(int index, int value) {
        arr[index] = value;
    }

    public int get(int index) {
        return arr[index];
    }
}

CloneConstructorExample e1 = new CloneConstructorExample();
CloneConstructorExample e2 = new CloneConstructorExample(e1);
e1.set(2, 222);
System.out.println(e2.get(2)); // 2
```

#### finalize

概念：当垃圾回收器确定不存在该对象的更多引用时，由对象的垃圾回收器调用此方法

注意细节

- 当某个对象没有任何引用时，则jvm虚拟机就会来销毁该对象，在销毁该对象前，就会调用该对象的finalize方法

    ```java
    public class person {
    	public person() {}
        // 该方法已经被废除，不推荐使用
        @Override
        protected void finalize() throws Throwable {
            System.out.println("我已经被销毁了...");
        }
    }
    
    class test{
        public static void main(String[] args) {
            new person();
            System.gc(); // 运行垃圾回收器
        }
    }
    
    // 显示效果：我已经被销毁了...
    ```

- 垃圾回收机制的调用，由系统来决定，我们可以通过System.gc() 主动触发垃圾回收机制



### Wrapper类

#### 包装类的分类

| 包装类  | 基本数据类型 | 直接父类 |
| :-----: | :----------: | :------: |
| boolean |   Boolean    |  Object  |
|  char   |  Character   |  Object  |
|  byte   |     Byte     |  Number  |
|  short  |    Short     |  Number  |
|   int   |     Int      |  Number  |
|  long   |     Long     |  Number  |
|  float  |    Float     |  Number  |
| double  |    Double    |  Number  |

![image-20220326131823205](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220326131823205.png) 

#### 装箱 & 拆箱

- 手动拆装箱
- 自动拆装箱

```java
// 代码示例
public class Wrapper01 {
    public static void main(String[] args) {
        // jdk5以前手动装箱&手动拆箱;jdk5之后可以自动拆装箱
        // 以Character为例
        char name = 'n';
        // 手动装箱
        // Character ch1 = new Character(name); // 不推荐
        Character ch2 = Character.valueOf(name);
        // 手动拆箱
        char name2 = Character.valueOf(ch2); // 本质就是使用charValue方法
        char name3 = ch1.charValue();

        // 自动装箱
        Character ch3 = name; // 本质使用的就是valueOf方法
        // 自动拆箱
        char CH4 = ch3; // 本质就是使用charValue方法
    }
}
```

**底层分析**

![image-20220326132417215](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220326132417215.png)

#### 缓冲池（重点!!!）

**基本类型对应的缓冲池如下:**

- boolean ：true and false
- byte ：all values
- short ： between -128 and 127
- int ：between -128 and 127
- char ：in the range \u0000 to \u007F

在使用这些基本类型对应的包装类型时，就可以直接使用缓冲池中的对象。

```java
// 以Integer为例
// new Integer(1) 与 Integer.valueOf(1)或者数值1 的区别在于:
// 1.new Integer(123) 每次都会新建一个对象
// 2.Integer.valueOf(123) 会使用缓存池中的对象，多次调用会取得同一个对象的引用
System.out.println(new Integer(1) == new Integer(1));  // false
Integer a = 1;
Integer b = 1;
System.out.println(a==b); // true
Integer a = Integer.valueOf(1);
Integer b = Integer.valueOf(1);
System.out.println(a==b); // true
```

**缓冲池源码分析**

```java
// 以Integer为例 jdk1.8中缓存池的大小默认为 -128~127
static final int low = -128;
static final int high;
static final Integer cache[];

static {
    // high value may be configured by property
    // 最大值会根据配置数据而改变，但是h的值至少大于127 Math.max(i, 127);
    int h = 127;
    String integerCacheHighPropValue =
        sun.misc.VM.getSavedProperty("java.lang.Integer.IntegerCache.high");
    if (integerCacheHighPropValue != null) {
        try {
            int i = parseInt(integerCacheHighPropValue);
            i = Math.max(i, 127);
            // Maximum array size is Integer.MAX_VALUE
            h = Math.min(i, Integer.MAX_VALUE - (-low) -1);
        } catch( NumberFormatException nfe) {
            // If the property cannot be parsed into an int, ignore it.
        }
    }
    high = h;

    cache = new Integer[(high - low) + 1];
    int j = low;
    // 静态初始化所有在缓冲池内的数据
    for(int k = 0; k < cache.length; k++)
        cache[k] = new Integer(j++);

    // range [-128, 127] must be interned (JLS7 5.1.7)
    assert IntegerCache.high >= 127;
}
```



### String类

#### 概述

是一组字符序列 本质上是char[] value 字符数组实现

```java
public static void main(String[] args) {
   /*
    * "Al_tair"被称为字符常量 用双引号括起来的字符序列
    *  一个字符占用两个字节（每个字符不区分字母和汉字）
    */
    String name = "Al_tair";
}

// public final class String 说明String的final类，不能被其它类继承
// private final byte[] value 用于存放字符串 value是用final修饰的类型，该数组不能指向新地址，但是能修改它的值
public final class String
    implements java.io.Serializable, Comparable<String>, CharSequence {
    /** The value is used for character storage. */
    private final char value[];
}
```

#### 接口和构造器

![image-20211028164429590](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20211028164429590.png)

#### String内存图

```java
// 运行代码,内存图如下
class code{
    public static void main(String[] args){
        String a = "Al_tair";
        String b = new String("Al_tair");
    }
}
```

![image-20220223163658951](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220223163658951.png) 

**字符串 VS 字符数组** 

结合代码和内存图分析

```java
class Text{
    String str = new String("lns");
    // final指的是char类型数据存储的地址不能改变，但是值是可以改变的
    final char[] ch = {'j','a','v','a'};
    public void change(String str,char[]  ){
        str = "zlr";
        ch[1] = 'c';
    }
    public static void main(String[] args) {
        Text text = new Text();
        text.change(text.str,text.ch);
        System.out.println(text.str.toString()+" and "+text.ch[1]); // lnsandc
    }
}
```

![image-20220223162328369](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220223162328369.png) 

#### String类的常用方法

- equals  区别大小写，判断字符串的内容是否相同
- equalsIgnoreCase 忽略大小写 来判断字符串的内容是否相同
- length 获取字符串的个数，或者称为字符串长度
- indexOf 获取字符在字符串中第一次出现的索引，索引从0开始，如果没有找到则返回-1
- lastindexOf 获取字符在字符串中最后一次出现的索引，索引从0开始，如果没有找到则返回-1
- substring 截取指定范围的字串
- trim 去掉字符串前后的空格
- charAt 获取某索引处的字符
- compareTo 比较两个字符串的大小，如果前者大于等于后者，则返回自然数；反之后者大，则返回负数
- intern 如果常量池中已经包含值相同的字符串，则返回常量池中的字符串引用地址，否则将String对象添加到常量池中，并返回String对象的引用

```java
// intern 方法的使用
String a = "l";
String b = new String("l");
System.out.println(a.equals(b)); // true
System.out.println(a == b); // false
System.out.println(a == b.intern()); // true
System.out.println(b == b.intern()); // false

// equals()方法源码
public boolean equals(Object anObject) {
    if (this == anObject) { // 地址是否相同
        return true;
    }
    if (anObject instanceof String) { // 是否为String类或者String父类
        String aString = (String)anObject;
        if (!COMPACT_STRINGS || this.coder == aString.coder) {
            return StringLatin1.equals(value, aString.value);
        }
    }
    return false;
}
@HotSpotIntrinsicCandidate
public static boolean equals(byte[] value, byte[] other) {
    if (value.length == other.length) {
        for (int i = 0; i < value.length; i++) {
            if (value[i] != other[i]) {
                return false;
            }
        }
        return true;
    }
    return false;
}

// 占位符的讲解 涉及方法format <=> c语言输出
// %s,%d,%.3f，%c
String name = "lns";
int age = 18;
double height = 185.35;
char gender = '男';

String Info = "姓名：%s\t年龄：%d\t身高：%.3f\t性别：%c";
String show = String.format(Info,name,age,height,gender);
System.out.println(show); // 姓名：lns	年龄：18	身高：185.350	性别：男

```

#### 包装类 <=> String类

```java
public class WrapperVsString {
    public static void main(String[]args){
        // String类 转换成 包装类
        String age = "120"; 
        Integer age2 = Integer.valueOf(age);  // 方式一:valueOf函数 本质上就是parseInt()方法
        Integer a2 = Integer.parseInt(age); // 方式二:parseInt函数
        Integer age3 = new Integer(age);  //不推荐，本质就是parseInt()方法

        // 包装类 转换成 String类
        Integer height = 180; // 自动装箱
        String h = String.valueOf(height); // 方式一:valueOf函数 本质就是调用toString()方法
        String h2 = height + "";  // 方式二: 类型转换 Integer + ""
        String h3 = height.toString(); // 方式三: toString()函数

        /*
         *   String.valueOf()源码
         *   public static String valueOf(Object obj) {
         *       return (obj == null) ? "null" : obj.toString();
         *   }
         * 
         *   Integer.valueOf()源码
         *   public static Integer valueOf(String s) throws NumberFormatException {
         *        return Integer.valueOf(parseInt(s, 10)); // 10指的是传入的数字是十进制数
         *   }
         *
         *   new Integer()源码
         *   @Deprecated(since="9")
         *   public Integer(String s) throws NumberFormatException {
         *          this.value = parseInt(s, 10);
         *   }
         */
    }
}
```



### StringBuffer类

概念：代表可变的字符序列，可以对字符串内容进行增删，是一个容器

![image-20220223203041672](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220223203041672.png) 

#### 构造方法

| Constructor and Description                                  |
| :----------------------------------------------------------- |
| `StringBuffer()`构造一个没有字符的字符串缓冲区，初始容量为16个字符。 |
| `StringBuffer(CharSequence seq)`构造一个包含与指定的相同字符的字符串缓冲区 `CharSequence` 。 |
| `StringBuffer(int capacity)`构造一个没有字符的字符串缓冲区和指定的初始容量。 |
| `StringBuffer(String str)`构造一个初始化为指定字符串内容的字符串缓冲区。 |

```java
/*
 * Constructs a string buffer with no characters in it and an
 * initial capacity of 16 characters.
 * StringBuffer()构造器
 */
@HotSpotIntrinsicCandidate
public StringBuffer() {
    super(16); // 初始容量为16个字符 存储在父类的value数组中
}
```

#### 常用方法

| 修饰符和类型   | 方法和描述                                                   |
| :------------- | :----------------------------------------------------------- |
| `StringBuffer` | `append(String str)`将指定的字符串附加到此字符序列           |
| `StringBuffer` | `delete(int start, int end)`删除此序列的子字符串中的字符     |
| `int`          | `length()`返回长度（字符数）                                 |
| `StringBuffer` | `replace(int start, int end, String str)`用指定的String中的字符替换此序列的子字符串中的 `String` |
| `int`          | `indexOf(String str)`返回指定子字符串第一次出现的字符串内的索引 |

```java
public static void main(String[] args) {
    // 常用方法
    // append 增
    StringBuffer stringBuffer = new StringBuffer("");
    stringBuffer.append("lns"); // lns
    /*
     *  append源码
     *  不管传入什么数据类型，返回StringBuffer类型
     *  public synchronized StringBuffer append(String str) {
     *      toStringCache = null;
     *      super.append(str);
     *      return this;
     *  }
     */

    // delete 删除
    // 删除索引范围 [start,end)
    stringBuffer.delete(0,1); // 删除第一个字符 ns

    // replace 替换
    // 替换范围[start,end)
    stringBuffer.replace(0, 1,"ln"); // lns

    // indexOf 查找
    // 查找第一次在字符串中出现的索引，如果查找到会返回你查找的字符串首个字母索引，如果找不到返回-1
    stringBuffer.indexOf("ns"); // 1

    // length 长度
    System.out.println(stringBuffer.length()); // 3
}
```

#### StringBuffer底层分析

**添加null字符串**

```java
String str = null;
StringBuffer sb = new StringBuffer();
sb.append(str);
System.out.println(sb); // null
System.out.println(sb.length()); // 4  
/*
 *  // 底层分析
 *  // StingBuffer类
 *  public synchronized StringBuffer append(String str) {
 *      toStringCache = null;
 *      super.append(str); // 跳转到父类
 *      return this;
 *  }
 *  // AbstractStringBuilder抽象类
 *  public AbstractStringBuilder append(String str) {
 *      if (str == null) {
 *          return appendNull(); // 跳转到该方法
 *      }
 *      int len = str.length();
 *      ensureCapacityInternal(count + len);
 *      putStringAt(count, str);
 *      count += len;
 *      return this;
 *  }
 *  // appendNull方法
 *  private AbstractStringBuilder appendNull() {
 *      ensureCapacityInternal(count + 4);
 *      int count = this.count;
 *      byte[] val = this.value;
 *      if (isLatin1()) {
 *          val[count++] = 'n';
 *          val[count++] = 'u';
 *          val[count++] = 'l';
 *          val[count++] = 'l';
 *      } else {
 *          count = StringUTF16.putCharsAt(val, count, 'n', 'u', 'l', 'l');
 *      }
 *      this.count = count;
 *      return this;
 *  }
 */
 StringBuffer sb = new StringBuffer(str); // 抛出空指针异常 NullPointerException
 /*
 * AbstractStringBuilder(String str) {
 *    int length = str.length(); // str为null 
 *    int capacity = (length < Integer.MAX_VALUE - 16)
 *           ? length + 16 : Integer.MAX_VALUE;
 *    final byte initCoder = str.coder();
 *    coder = initCoder;
 *    value = (initCoder == LATIN1)
 *           ? new byte[capacity] : StringUTF16.newBytesFor(capacity);
 *    append(str);
 * }
 */
```

**字符串拼接**

```java
// 创建了几个对象 答：3  结论:字符串常量相加地址存放在常量池，字符串变量相加地址存放在String对象中
// sum 指向的是value[](String对象)，再指向常量池中"HelloString"字符串
public static void main(String[]args){
    String m = "Hello";
    String n = "String";
    /*
     * 解读：
     * 1. 创建新对象 new StringBuilder();
     * 2. 通过append函数添加字符串 “Hello”
     * 3. 通过append函数添加字符串 “String”
     * 4. 返回new String("HelloString");
     */
    String sum = m + n;
}
// 分析sum 的指向和底层源码
// debug test
// first insert
public StringBuilder() {
    super(16);
}
//secong insert  str = "Hello"
public StringBuilder append(String str) {  
    super.append(str);
    return this;
}
// third insert str = "String"
public StringBuilder append(String str) {
    super.append(str);
    return this;
}
// last one
public String toString() {
    // Create a copy, don't share the array
    return isLatin1() ? StringLatin1.newString(value, 0, count): StringUTF16.newString(value, 0, count);
}
```

#### String <=> StringBuffer

**String类和StringBuffer类的区别**

- String保存的是字符串常量，里面的值不能更改，每次值的更新实际上就是更改地址，效率低
- Stringbuffer保存的是字符串变量，里面的值是可以改变的，不需要每次都更改地址，效率高

**String类和StringBuffer类的相互转换** 

```java
public static void main(String[] args) {
    // String和StringBuffer的相互转换
    // String => StringBuffer
    String str = "lns";
    StringBuffer stringBuffer = new StringBuffer(str); // 方式一: 使用StringBuffer构造器
    StringBuffer append = new StringBuffer().append(str); // 方式二: 使用的是append方法

    // StringBuffer => String
    StringBuffer sbr = new StringBuffer("zlr");
    String s = sbr.toString(); // 方式一: 使用toString方法
    String s1 = new String(sbr); // 方式二：使用String构造器 
}
```



### StringBuilder类

概念：一个可变的字符序列。 线程不安全。 此类设计用作简易替换为`StringBuffer`在正在使用由**单个线程**字符串缓冲区的地方。 在可以的情况下，建议使用这个类别优先于`StringBuffer` ，因为它在大多数实现中将更快。

常用方法大部分与 StringBuffer类似

![image-20220224105411449](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220224105411449.png) 

特殊点：没有做互斥处理，因此在单线程下使用

```java
// 源码剖析 区别在于关键字 synchronized 保证线程安全
// StringBuffer 的append方法
@Override
@HotSpotIntrinsicCandidate
public synchronized StringBuffer append(String str) {
    toStringCache = null;
    super.append(str);
    return this;
}

// StringBuilder 的append方法
@Override
@HotSpotIntrinsicCandidate
public StringBuilder append(String str) {
    super.append(str);
    return this;
}
```

**String，StringBuffer，StringBuilder的区别**

- String：不可变字符序列，效率低，但是因为存在常量池所以复用率高，String 不可变，因此是线程安全的
- StringBuffer：可变字符序列，效率较高（增删），线程安全 
- StringBuilder：可变字符序列，效率最高，线程不安全

**使用原则**

- 如果字符串存在大量的修改操作，一般使用StringBuffer或者StringBuider
    - 如果字符串存在大量的修改操作，并在单线程的情况，使用StringBuilder
    - 如果字符串存在大量的修改操作，并在多线程的情况，使用StringBuffer
- 如果字符串很少修改，被多个对象引用，使用String 比如：配置信息等



### Math类

概念：Math类包含执行基本数学运算的方法

#### 常用方法

```java
public static void main(String[] args) {
    // Math类中大部分是静态方法，可以直接通过类名.方法名访问
    // abs 绝对值
    int abs = Math.abs(-10);
    System.out.println(abs); // 10

    // pow 求幂
    double pow = Math.pow(2,4);
    System.out.println(pow); // 16.0

    // ceil 向上取整，返回>=该参数的最小整数(整数会转换成double型)
    double ceil = Math.ceil(-3.002);
    System.out.println(ceil); // -3.0

    // floor 向下取整，返回<=该参数的最大整数（整数会转换成double型)
    double floor = Math.floor(3.2);
    System.out.println(floor); // 3.0

    // round 四舍五入 <=> Math.floor(参数+0.5)
    double round = Math.round(3.24);
    System.out.println(round); // 3.0

    // sqrt 求开平方
    double sqrt = Math.sqrt(4);
    System.out.println(sqrt); // 2.0

    // random 随机数 [0,1)
    int random = (int)(Math.random()*50+50);
    System.out.println(random); // 整数范围 [50,100)
}
```



### Arrays类

概念：该类包含用于操作数组的各种方法（如排序和搜索），大部分方法也是静态方法

#### 常用方法

##### toString方法 

作用：将数组的值按照一定格式以字符串的方式输出 

```java
// 测试代码
public static void main(String[] args) {
    Integer[] array1 = null;
    System.out.println(Arrays.toString(array1)); // null
    Integer[] array2 = {};
    System.out.println(Arrays.toString(array2)); // []
    Integer[] array3 = new Integer[3];
    System.out.println(Arrays.toString(array3)); // [null,null,null]
    Integer[] array4 = {3,5,6,47,8};
    System.out.println(Arrays.toString(array4)); // [3, 5, 6, 47, 8]
}

// toString方法源码（以整数数组为例）
// 1.数组为null  Integer[] array = null；
// 2.数组为空 Integer[] array = {}；
// 3.底层使用StringBuider来拼接数组值，并且转换成String
public static String toString(int[] a) {
    if (a == null) 
        return "null";
    int iMax = a.length - 1;
    if (iMax == -1)
        return "[]";

    StringBuilder b = new StringBuilder();
    b.append('[');
    for (int i = 0; ; i++) {
        b.append(a[i]); 
        if (i == iMax)
            return b.append(']').toString();
        b.append(", ");
    }
}
```

##### sort方法  

作用：排序数组默认从小到大

```java
// sort重载，可以通过传入一个接口Comparator实现定制排序
Integer[] array = {3,5,6,47,8};
Arrays.sort(array);
System.out.println(Arrays.toString(array)); // [3, 5, 6, 8, 47]
Arrays.sort(array,new Comparator(){
    @Override
    public int compare(Object o1, Object o2) {
        Integer i1 = (Integer)o1;
        Integer i2 = (Integer)o2;
        return i2 - i1; // 决定是升序还是降序
    }
});
System.out.println(Arrays.toString(array)); // [47, 8, 6, 5, 3]

// MySort的冒泡实现
public class MySort {
    public static void main(String[] args) {
        int[] arr = {6,4,5,6,845,4,51};
        bubble(arr, new Comparator() {
            @Override
            public int compare(Object o1, Object o2) {
                int i1 = (Integer)o1;
                int i2 = (Integer)o2;
                return i1 - i2;
            }
        });
        System.out.println(Arrays.toString(arr));
    }

    public static void bubble(int[] arr, Comparator c){
        int temp = 0;
        for (int i = 0; i < arr.length - 1; i++) {
            for (int j = 0; j < arr.length - 1 - i; j++) {
                if(c.compare(arr[j],arr[j+1]) >= 0){ // 动态绑定机制
                    temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
    }
}
```

##### binarySearch方法

作用：通过二分搜索法进行查找,要求必须升序，如果数组中不存在，则返回 -(low + 1)

```java
Integer[] array = {3,5,6,47,8};
Arrays.sort(array); // [3, 5, 6, 8, 47]
int index = Arrays.binarySearch(array,9); 
System.out.println(index); // -5 应该在索引4位置(8和471之间)，返回-(4+1)

// binarySearch 源码
public static int binarySearch(int[] a, int fromIndex, int toIndex,
                               int key) {
    rangeCheck(a.length, fromIndex, toIndex);
    return binarySearch0(a, fromIndex, toIndex, key);
}

// Like public version, but without range checks.
private static int binarySearch0(int[] a, int fromIndex, int toIndex,
                                 int key) {
    int low = fromIndex;
    int high = toIndex - 1;

    while (low <= high) {
        // 无符号右移，按位右移补零操作符
        // >>> 操作符运算 要快于加减乘除运算
        int mid = (low + high) >>> 1; 
        int midVal = a[mid];

        if (midVal < key)
            low = mid + 1;
        else if (midVal > key)
            high = mid - 1;
        else
            return mid; // key found
    }
    return -(low + 1);  // key not found.
}
```

##### 其他方法

```java
// copeOf 数组的赋值 如果赋值的长度大于原数组的长度，则多余的数据用null填入
Integer[] integers = Arrays.copyOf(array, array.length-1);
System.out.println(Arrays.toString(integers)); // [3, 5, 6, 8]

// fill 数组的填充 替换数组中的所有数据
int[] fillNum = {2,45,78,85,15};
Arrays.fill(fillNum,2);
System.out.println(Arrays.toString(fillNum)); // [2, 2, 2, 2, 2]

// equals 比较两个数组元素内容是否相同
int[] equalsNum = {2,45,78,85,15};
int[] equalsNum2 = {2,45,78,85,15};
System.out.println(Arrays.equals(equalsNum,equalsNum2)); // true
```



### System类

概念：`System`类包含几个有用的类字段和方法。 它不能被实例化。

#### 常用方法

```java
public static void main(String[] args) {
    // gc方法：调用垃圾回收器
    new System01();
    System.gc(); 

    // currentTimeMillis方法：在1970年1月1日UTC之间的当前时间和午夜之间的差异，以毫秒为单位
    System.out.println(System.currentTimeMillis()); // 1645776480314

    // arraycopy方法：复制数组（深拷贝）
    int[] src = {1,2,3};
    int[] desc = {0,0,0};
    /*
     * 从左到右的五个参数描述
     *  src      the source array. 被复制内容的数组
     *  srcPos   starting position in the source array. 源数组索引位置（从哪个位置开始拷贝）
     *  dest     the destination array. 复制内容得到的数组
     *  destPos  starting position in the destination data. 目标数组的索引位置
     *  length   the number of array elements to be copied. 拷贝的数组长度
     */
    System.arraycopy(src,0,desc,0,3);
    System.out.println(Arrays.toString(desc)); //[1, 2, 3]
    System.out.println(src == desc); // false 

    // exit方法：退出程序
    System.out.println("程序开始");
    // System.exit(0)是正常退出程序，而System.exit(1)或者说非0表示非正常退出程序
    System.exit(0); 
    System.out.println("程序结束"); // 不执行
}
@Override
protected void finalize(){
    System.out.println("我已经被销毁了");
}
```



### BigIneger和BigDecimal类

概念：**BigIneger** 适合保存比较大的整型数据；**BigDecimal** 适合保存精度更高的浮点型数据

#### 常用方法

```java
// BigIneger 适合保存比较大的整型数据  long数据类型无法存储
BigInteger bigInteger = new BigInteger("998456349564561256465489");
System.out.println(bigInteger); // 998456349564561256465489
// + - * / 运算 => 方法实现 add subtract multiply divide
bigInteger = bigInteger.add(new BigInteger("1"));
System.out.println(bigInteger); // 998456349564561256465490
bigInteger = bigInteger.divide(new BigInteger("2"));
System.out.println(bigInteger); // 499228174782280628232745
bigInteger = bigInteger.subtract(new BigInteger("2"));
System.out.println(bigInteger); // 499228174782280628232743
bigInteger = bigInteger.multiply(new BigInteger("2"));
System.out.println(bigInteger); // 998456349564561256465486



// BigDecimal 适合保存精度更高的浮点数  double数据类型无法存储
BigDecimal bigDecimal = new BigDecimal("9980.2561295645485648548485646541");
System.out.println(bigDecimal); // 9980.2561295645485648548485646541
// + - * / 运算 => 方法实现 add  subtract multiply divide
bigDecimal = bigDecimal.add(new BigDecimal("1"));
System.out.println(bigDecimal); // 9981.2561295645485648548485646541
bigDecimal = bigDecimal.divide(new BigDecimal("2")); // 如果除不尽则返回算术异常
System.out.println(bigDecimal); // 4990.62806478227428242742428232705
bigDecimal = bigDecimal.subtract(new BigDecimal("2"));
System.out.println(bigDecimal); // 4988.62806478227428242742428232705
bigDecimal = bigDecimal.multiply(new BigDecimal("2"));
System.out.println(bigDecimal); // 9977.25612956454856485484856465410
// 解决小数除法异常问题：指定精度(JDK9以后不建议使用)
bigDecimal = bigDecimal.divide(new BigDecimal("2.3326"),BigDecimal.ROUND_CEILING);
System.out.println(bigDecimal); // 4277.31121047952866537548167909376
```

**源码分析BigIneger**

```java
// BigIneger 适合保存比较大的整型数据  long数据类型无法存储
BigInteger bigInteger = new BigInteger("998456349564561256465489");
System.out.println(bigInteger); // 998456349564561256465489

// 源码分析
public BigInteger(String val) {
    this(val, 10); // 默认十进制
}
public BigInteger(String val, int radix) {
    int cursor = 0, numDigits;
    final int len = val.length();

    if (radix < Character.MIN_RADIX || radix > Character.MAX_RADIX)
        throw new NumberFormatException("Radix out of range");
    if (len == 0)
        throw new NumberFormatException("Zero length BigInteger");

    // 检查符号
    int sign = 1;
    int index1 = val.lastIndexOf('-');
    int index2 = val.lastIndexOf('+');
    if (index1 >= 0) {
        if (index1 != 0 || index2 >= 0) {
            throw new NumberFormatException("Illegal embedded sign character");
        }
        sign = -1;
        cursor = 1;
    } else if (index2 >= 0) {
        if (index2 != 0) {
            throw new NumberFormatException("Illegal embedded sign character");
        }
        cursor = 1;
    }
    if (cursor == len)
        throw new NumberFormatException("Zero length BigInteger");

    // Skip leading zeros and compute number of digits in magnitude
    while (cursor < len &&
           Character.digit(val.charAt(cursor), radix) == 0) {
        cursor++;
    }

    if (cursor == len) {
        signum = 0;
        mag = ZERO.mag;
        return;
    }

    numDigits = len - cursor;
    signum = sign;

    // 预分配预期大小的数组。可能太大，但永远不能太小，通常是准确的
    long numBits = ((numDigits * bitsPerDigit[radix]) >>> 10) + 1;
    if (numBits + 31 >= (1L << 32)) {
        reportOverflow();
    }
    int numWords = (int) (numBits + 31) >>> 5;
    int[] magnitude = new int[numWords];

    // Process first (potentially short) digit group
    int firstGroupLen = numDigits % digitsPerInt[radix];
    if (firstGroupLen == 0)
        firstGroupLen = digitsPerInt[radix];
    String group = val.substring(cursor, cursor += firstGroupLen);
    magnitude[numWords - 1] = Integer.parseInt(group, radix);
    if (magnitude[numWords - 1] < 0)
        throw new NumberFormatException("Illegal digit");

    // Process remaining digit groups
    int superRadix = intRadix[radix];
    int groupVal = 0;
    while (cursor < len) {
        group = val.substring(cursor, cursor += digitsPerInt[radix]);
        groupVal = Integer.parseInt(group, radix);
        if (groupVal < 0)
            throw new NumberFormatException("Illegal digit");
        destructiveMulAdd(magnitude, superRadix, groupVal);
    }
    // Required for cases where the array was overallocated.
    mag = trustedStripLeadingZeroInts(magnitude);
    if (mag.length >= MAX_MAG_LENGTH) {
        checkRange();
    }
}
```



### 日期类

#### 第一代日期类

Date：精确到毫秒，代表瞬间

SimpleDateFormat：格式和解析日期类（日期 <=> 文本） 

```java
public static void main(String[] args) throws ParseException {
    // Date 日期类
    Date date = new Date(); // 当前日期
    System.out.println(date); // Mon Apr 25 11:49:31 CST 2022
    Date date2 = new Date(4564956); // 输入距离1970年1月1日的毫秒数
    System.out.println(date2); // Thu Jan 01 09:16:04 CST 1970

    // SimpleDateFormat 格式和解析日期类 按照自己的格式的日期  年 月 日 时 分 秒 星期
    SimpleDateFormat sdf = new SimpleDateFormat("YYYY年MM月dd日 hh:mm:ss E");
    System.out.println(sdf.format(date)); // 2022年04月25日 11:28:41 周一

    String dateStr = "2021年02月26日 05:07:32 周一";
    System.out.println(sdf.format(sdf.parse(dateStr))); // 2021年12月28日 05:07:32 周一  
}
```

**SimpleDateFormat的规定格式**

![image-20220225170623223](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220225170623223.png)

#### 第二代日期类

Calendar类（日历） 是一个抽象类

```java
// 抽象类 可以通过getInstance方法获取实例
Calendar calendar = Calendar.getInstance();
System.out.println("年:"+calendar.get(calendar.YEAR)); // 年:2022
System.out.println("月:"+calendar.get(calendar.MONTH)+1); // 月:2 源码:JANUARY} which is 0
System.out.println("日:"+calendar.get(calendar.DAY_OF_MONTH)); // 日:25
System.out.println("小时:"+calendar.get(calendar.HOUR)); // 小时:8
System.out.println("分钟:"+calendar.get(calendar.MINUTE)); // 分钟:11
System.out.println("秒:"+calendar.get(calendar.SECOND)); // 秒:46
```



#### 第三代日期类 （JDK8）

LocalDate 日期：年月日

LocalTime 时间：时分秒

LocalDateTime：年月日 时分秒

```java
LocalDateTime localDateTime = LocalDateTime.now();
LocalTime localTime = LocalTime.now();
LocalDate localDate = LocalDate.now();
// localDateTime: 2022-02-25T20:30:19.250574 
// LocalDate: 2022-02-25
// LocalTime: 20:30:19.250574 
System.out.println("localDateTime: "+localDateTime+" LocalTime: "+
                   localTime+" LocalDate: "+localDate);

System.out.println("年: "+localDateTime.getYear()); // 年: 2022
System.out.println("月: "+localDateTime.getMonth()); // 月: FEBRUARY
System.out.println("日: "+localDateTime.getDayOfMonth()); // 日: 25
System.out.println("时: "+localDateTime.getHour()); // 时: 20
System.out.println("分: "+localDateTime.getMinute()); // 分: 33
System.out.println("秒: "+localDateTime.getSecond()); // 秒: 45
```

DateTimeFormatter格式日期类

```java
//  DateTimeFormatter 格式日期类
LocalDateTime localDateTime = LocalDateTime.now();
DateTimeFormatter dateTimeFormatter = DateTimeFormatter.ofPattern("YYYY年MM月dd日 hh:mm:ss E");
System.out.println(dateTimeFormatter.format(localDateTime)); //  2022年04月25日 11:28:41 周一
```

```txt
  所有字母“A”至“Z”和“a”至“z”保留为图案字母。 定义了以下图案字母： 
  Symbol  Meaning                     Presentation      Examples
  ------  -------                     ------------      -------
   G       era                         text              AD; Anno Domini; A
   u       year                        year              2004; 04
   y       year-of-era                 year              2004; 04
   D       day-of-year                 number            189
   M/L     month-of-year               number/text       7; 07; Jul; July; J
   d       day-of-month                number            10

   Q/q     quarter-of-year             number/text       3; 03; Q3; 3rd quarter
   Y       week-based-year             year              1996; 96
   w       week-of-week-based-year     number            27
   W       week-of-month               number            4
   E       day-of-week                 text              Tue; Tuesday; T
   e/c     localized day-of-week       number/text       2; 02; Tue; Tuesday; T
   F       week-of-month               number            3

   a       am-pm-of-day                text              PM
   h       clock-hour-of-am-pm (1-12)  number            12
   K       hour-of-am-pm (0-11)        number            0
   k       clock-hour-of-am-pm (1-24)  number            0

   H       hour-of-day (0-23)          number            0
   m       minute-of-hour              number            30
   s       second-of-minute            number            55
   S       fraction-of-second          fraction          978
   A       milli-of-day                number            1234
   n       nano-of-second              number            987654321
   N       nano-of-day                 number            1234000000

   V       time-zone ID                zone-id           America/Los_Angeles; Z; -08:30
   z       time-zone name              zone-name         Pacific Standard Time; PST
   O       localized zone-offset       offset-O          GMT+8; GMT+08:00; UTC-08:00;
   X       zone-offset 'Z' for zero    offset-X          Z; -08; -0830; -08:30; -083015; -08:30:15;
   x       zone-offset                 offset-x          +0000; -08; -0830; -08:30; -083015; -08:30:15;
   Z       zone-offset                 offset-Z          +0000; -0800; -08:00;

   p       pad next                    pad modifier      1

   '       escape for text             delimiter
   ''      single quote                literal           
   [       optional section start
   ]       optional section end
   #       reserved for future use
   {       reserved for future use
   }       reserved for future use 
```

Instant 时间戳

```java
// Instant -> Date
Instant instant = Instant.now();
System.out.println(instant); // 2022-02-25T14:48:47.557358800Z
java.util.Date from = Date.from(instant);
System.out.println(from); // Fri Feb 25 22:48:47 CST 2022

// Date -> Instant
Instant instant1 = from.toInstant();
System.out.println(instant1); // 2022-02-25T14:55:27.377Z
```



## 集合类

集合又称为容器，只能存储对象，对于基本类型(int, long, float, double等)，需要将其包装成对象类型后(Integer, Long, Float, Double等)才能放到容器里

容器主要包括 Collection 和 Map 两种，Collection 存储着对象的集合，而 Map 存储着键值对(两个对象)的映射表

### 集合框架

**Collection接口框架**

![image-20220226113621627](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220226113621627.png) 

![image-20220813203009747](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220813203009747.png)

**Map接口框架**

![image-20220226114159934](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220226114159934.png) 

![image-20220823194714462](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220823194714462.png)

### Collection接口

#### 概述

Collection 实现 Iterable接口 ： public interface Collection<E> extends Iterable<E> 

Collection接口特征

1. 可以实现存放多个元素，每个元素可以是Object类或者其子类
2. 没有直接实现的子类，都是通过它的子接口Set，Queue和List来实现的

#### 遍历方式

##### 遍历方式-迭代器

![image-20220226131905068](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220226131905068.png) 

Iterator接口 又称为 迭代器，主要用于遍历Collcection集合中的元素，所有实现了Collection接口的集合类都有一个Iterator()方法，用来返回一个迭代器

**迭代器的遍历方式**

![image-20220504233710149](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220504233710149.png) 

**迭代器方法**

|   变量和类型   |                      方法                      |                             描述                             |
| :------------: | :--------------------------------------------: | :----------------------------------------------------------: |
| `default void` | `forEachRemaining(Consumer<? super E> action)` | 对每个剩余元素执行给定操作，直到处理完所有元素或操作引发异常。 |
|   `boolean`    |                  `hasNext()`                   |            如果迭代具有更多元素，则返回 `true` 。            |
|      `E`       |                    `next()`                    |                   返回迭代中的下一个元素。                   |
| `default void` |                   `remove()`                   |   从底层集合中移除此迭代器返回的最后一个元素（可选操作）。   |

```java
// Iterator方法的使用示例
public class Iterator01 {
    public static void main(String[] args) {
        List list = new ArrayList();
        list.add(new Book("三国演义",10));
        list.add(new Book("水浒传",20));
        list.add(new Book("西游记",15));
	    // 获取迭代器
        Iterator iterator = list.iterator();
        while(iterator.hasNext()){
            System.out.println(iterator.next());
        }
        // 退出循环之后，迭代器指向最后一个元素的后面
        // iterator.next(); // 抛出异常 NoSuchElementException
        // 需要重置迭代器  iterator = list.iterator();
    }
    static class Book{
        private String name;
        private int price;
        public Book(String name, int price) {
            this.name = name;
            this.price = price;
        }
        @Override
        public String toString() {
            return "Book{" +
                "name='" + name + '\'' +
                ", price=" + price +'}';
        }
    }
}
```

---

##### 遍历方式-for增强

特点：只能用于遍历集合和数组（简化版迭代器）

```java
// 基本格式
for(元素类型 元素名：集合名或数组名){ 
     // 访问元素
 }
```

**代码示例**

```java
public class ForS {
    public static void main(String[] args) {
        List list = new ArrayList();
        list.add(new Toy("猛虎王",10));
        list.add(new Toy("霹雳火",20));
        list.add(new Toy("洛洛",15));

        // 增强for 本质仍然是迭代器
        // 集合
        for (Object b:list) {
            System.out.println(b.toString());
        }
        // 数组
        int[] num = {2,4,5,6};
        for (int n:num) {
            System.out.println(n+"  ");
        }
    }
    static class Toy{
        private String name;
        private int price;
        public Toy(String name, int price) {
            this.name = name;
            this.price = price;
        }
        @Override
        public String toString() {
            return "Toy{" +
                    "name='" + name + '\'' +
                    ", price=" + price + '}';
        }
    }
}
```

**分析增强for的底层**

```java
// debug 跳转 底层也是迭代器
// 跳转1
public Iterator<E> iterator() {
    return new Itr();
}
// 跳转2
public boolean hasNext() {
    return cursor != size;
}
// 跳转3
public E next() 等等
```

---

##### 遍历方式-普通for循环

```java
public static void main(String[] args) {
    List list = new ArrayList();
    list.add("张三丰");
    list.add("秦天柱");
    for (int i = 0; i < list.size(); i++) {
        System.out.println(list.get(i));
    }
}
```



#### List接口

##### 概述

Collection接口的子接口 

特点

- List集合类元素顺序有序，且可以重复
- List集合类中的每个元素都有其对应的顺序索引

```java
// 以实现list接口的ArrayList类为例
// List集合类元素顺序有序，且可以重复
List list = new ArrayList();
list.add("das");
list.add("tom");
list.add("tom");
System.out.println(list); // [das, tom, tom]
// List集合类中的每个元素都有其对应的顺序索引
System.out.println(list.get(0));  // das
```

---

##### ArrayList类

###### 概述

顺序容器，即元素存放的数据与放进去的顺序相同，允许放入`null`元素，底层通过**数组**实现

![image-20220531232420663](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220531232420663.png) 

特点：

- 元素可以是null，并且可以有多个

- ArrayList是线程不安全的，不能在多线程的情况下使用，如果需要多个线程并发访问，用户可以手动同步，也可使用Vector替代

    ```java
    // 对比这两种源码 区别在于是否线程安全  synchronized
    // ArrayList源码
    public boolean add(E e) {
        modCount++;
        add(e, elementData, size);
        return true;
    }
    // Vector源码
    public synchronized boolean add(E e) {
        modCount++;
        add(e, elementData, elementCount);
        return true;
    }
    ```

###### 源码分析扩容机制

![image-20220226184245606](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220226184245606.png) 

1. ArrayList类数据存储在Object类数组中（elementData）

    ```java
    transient Object[] elementData; // transient 表示该属性不会被序列化
    ```

2. 当使用无参构造方法创建该对象，初始elementData容量为0，第一次添加数据，扩容到10容量，以后每次扩容，则会扩大当前容量的1.5倍

3. 如果使用指定大小的有参构造器，则初始elementData容量为指定大小，如果需要扩容，也是直接扩容1.5倍

4. 自动扩容这种操作的代价是很高的，因此在实际使用时，我们应该尽量避免数组容量的扩张。当我们可预知要保存的元素的多少时，要在构造ArrayList实例时，就指定其容量，以避免数组扩容的发生。或者根据实际需求，通过调用ensureCapacity方法来手动增加ArrayList实例的容量

**无参构造器**

1.设置断点

![image-20220226200138044](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220226200138044.png) 

 2.debug跳转

```java
// 跳转1
public boolean add(E e) {
    modCount++; // 记录集合被修改的次数  如果madCount的值因为线程原因意外改变，则抛出异常
    add(e, elementData, size); // e:传入的数据 elementDate:Object数组 size:数组元素数量
    return true;
}
// 跳转2
private void add(E e, Object[] elementData, int s) {
    if (s == elementData.length) // s:数组元素数量 elementDate.length:数组容量 
        elementData = grow(); // 只有当容量够用，不会调用该方法
    elementData[s] = e; // 数组添加数据
    size = s + 1; 
}
// 当数组size == capacity 跳转3
private Object[] grow() {
    return grow(size + 1); 
}
// 跳转4
private Object[] grow(int minCapacity) { // minCapacity：当前元素个数+1
    int oldCapacity = elementData.length; // 记录原容量
    if (oldCapacity > 0 || elementData != DEFAULTCAPACITY_EMPTY_ELEMENTDATA){ //判断容量是否为0
        //  传入newLength方法的参数：原容量，超出容量，0.5倍容量大小
        int newCapacity = ArraysSupport.newLength(oldCapacity,
                  minCapacity - oldCapacity, oldCapacity >> 1 ); // >> 1 相当于乘0.5
        return elementData = Arrays.copyOf(elementData, newCapacity); // 扩容，保留原数据
    } else {
        // DEFAULT_CAPACITY 10   如果是容量为0，第一次扩容默认为10
        return elementData = new Object[Math.max(DEFAULT_CAPACITY, minCapacity)];
    }  
}
// 当传入第11个数据时候跳转5
public static int newLength(int oldLength, int minGrowth, int prefGrowth) {
    // assert oldLength >= 0
    // assert minGrowth > 0

    int newLength = Math.max( minGrowth,prefGrowth ) + oldLength; // 当超出容量，则扩容1.5倍
    if (newLength - MAX_ARRAY_LENGTH <= 0) {
        return newLength;
    }
    return hugeLength(oldLength, minGrowth);
}
```

**有参构造器**

![image-20220226202444863](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220226202444863.png) 

```java
public ArrayList(int initialCapacity) {
    if (initialCapacity > 0) {
        this.elementData = new Object[initialCapacity];
    } else if (initialCapacity == 0) {
        this.elementData = EMPTY_ELEMENTDATA;
    } else {
        throw new IllegalArgumentException("Illegal Capacity: "+
                                           initialCapacity);
    }
}
```

###### 源码分析常用方法

**toString方法**

父类AbstractCollection 实现了toString方法

```java
public String toString() {
    Iterator<E> it = iterator(); // 创建迭代器进行遍历该集合
    if (!it.hasNext())
        return "[]";
    StringBuilder sb = new StringBuilder();
    sb.append('[');
    for (;;) {
        E e = it.next();
        sb.append(e == this ? "(this Collection)" : e);
        if (! it.hasNext())
            return sb.append(']').toString();
        sb.append(',').append(' ');
    }
}
```

**add方法**

增加元素之前判断数组长度是否能够容量该元素

```java
// 默认插入到数组队尾
public boolean add(E e) {
    modCount++;
    add(e, elementData, size);
    return true;
}
// 在此列表中的指定位置插入指定元素。将当前位于该位置的元素（如果有）和任何后续元素向右移动（将其索引加一）
public void add(int index, E element) {
    rangeCheckForAdd(index);
    modCount++;
    final int s;
    Object[] elementData;
    if ((s = size) == (elementData = this.elementData).length)
        elementData = grow();
    System.arraycopy(elementData, index, elementData, index + 1, s - index);
    elementData[index] = element;
    size = s + 1;
}

```

**addAll **

按照指定集合的迭代器返回的顺序，将指定集合中的所有元素附加到此列表的末尾

```java
public boolean addAll(Collection<? extends E> c) {
    Object[] a = c.toArray();
    modCount++;
    int numNew = a.length;
    if (numNew == 0)
        return false;
    Object[] elementData;
    final int s;
    if (numNew > (elementData = this.elementData).length - (s = size))
        elementData = grow(s + numNew);
    System.arraycopy(a, 0, elementData, s, numNew);
    size = s + numNew;
    return true;
}
```

**remove方法**

移除此列表中指定位置的元素

```java
public E remove(int index) {
    // 检查索引下标是否超出数组大小
    Objects.checkIndex(index, size);
    final Object[] es = elementData;
    @SuppressWarnings("unchecked") E oldValue = (E) es[index];
    fastRemove(es, index);
    return oldValue;
}
```

**clear方法**

从此列表中删除所有元素

```java
public void clear() {
    modCount++;
    final Object[] es = elementData;
    for (int to = size, i = size = 0; i < to; i++)
        es[i] = null;
}
```

**set方法**

将此列表中指定位置的元素替换为指定元素

```java
public E set(int index, E element) {
    Objects.checkIndex(index, size);
    E oldValue = elementData(index);
    elementData[index] = element;
    return oldValue;
}
```

**indexOf方法**

返回该对象首次出现的索引位置,如果没有这样的索引返回 -1

```java
public int indexOf(Object o) {
    return indexOfRange(o, 0, size);
}

int indexOfRange(Object o, int start, int end) {
    Object[] es = elementData;
    // 用来判断是否插入字符串null，和初始化赋值null（Object）是不相等的（equals没有被重写）
    if (o == null) {
        for (int i = start; i < end; i++) {
            if (es[i] == null) {
                return i;
            }
        }
    } else {
        for (int i = start; i < end; i++) {
            if (o.equals(es[i])) {
                return i;
            }
        }
    }
    return -1;
}
```

**lastIndexOf 方法**

返回该对象最后一次出现的索引位置,如果没有这样的索引返回 -1

```java
public int lastIndexOf(Object o) {
    return lastIndexOfRange(o, 0, size);
}
int lastIndexOfRange(Object o, int start, int end) {
    Object[] es = elementData;
    if (o == null) {
        for (int i = end - 1; i >= start; i--) {
            if (es[i] == null) {
                return i;
            }
        }
    } else {
        for (int i = end - 1; i >= start; i--) {
            if (o.equals(es[i])) {
                return i;
            }
        }
    }
    return -1;
}
```

**代码示例**

```java
// add 添加单个元素
List list = new ArrayList();
list.add("lns");
list.add(520); // 自动装箱 new Integer(520)
list.add("zlr");
System.out.println(list.toString()); // [lns, 520, zlr]
// addAll 添加多个元素
List list2 = new ArrayList();
list2.add("lns");
list2.add("love");
list2.add("zlr");
list.addAll(list2);
System.out.println(list); // [lns, 520, zlr, lns, love, zlr]
// remove 删除指定元素
list.remove(1); // 等价于 list.remove(520);
System.out.println(list); // [lns, zlr, lns, love, zlr]
// clear 清空
list.clear();
System.out.println(list); // []
// set 替换对象数据
list.add("lns");
list.add(520); 
list.add("zlr");
list.set(1,"love"); // 520 => love
System.out.println(list); // [lns, love, zlr]
// indexOf 返回该对象首次出现的索引位置
System.out.println(list.indexOf("lns")); // 0
// lastIndexOf 返回该对象最后一次出现的索引位置
System.out.println(list.lastIndexOf("zlr")); // 2
// 其他方法
// containsAll 查找多个元素是否存在
// contains 查找元素是否存在
// size 获取元素个数
// isEmpty 判读是否为空
// subList 返回范围为[fromIndex,toIndex)位置的子集合 该方法返回的是子串集合的地址索引
// trimToSize() 提供了将底层数组的容量调整为当前列表保存的实际元素的大小的功能
```

---

##### Vector类

###### 概述

是由数组实现数据存储，并且是线程安全的（通常方法被 synchronized 关键字修饰）

```java
// Vector的类定义
public class Vector<E>extends AbstractList<E>
    implements List<E>, RandomAccess, Cloneable, java.io.Serializable
    
// Vector底层本质也是对象数组
protected Object[] elementData;
```

###### 源码分析

```java
/*
 * 当向量的大小变得大于其容量时，向量的容量自动增加的量。如果容量增量小于或等于零，
 * 则每次需要增长时，向量的容量都会增加一倍
 */
protected int capacityIncrement;

private Object[] grow(int minCapacity) {
    int oldCapacity = elementData.length;
    int newCapacity = ArraysSupport.newLength(oldCapacity,minCapacity - oldCapacity, capacityIncrement > 0 ? capacityIncrement : oldCapacity);
    return elementData = Arrays.copyOf(elementData, newCapacity);
}

public static int newLength(int oldLength, int minGrowth, int prefGrowth) {
    // assert oldLength >= 0
    // assert minGrowth > 0
    int newLength = Math.max(minGrowth, prefGrowth) + oldLength; // 2倍
    if (newLength - MAX_ARRAY_LENGTH <= 0) {
        return newLength;
    }
    return hugeLength(oldLength, minGrowth);
}
// 方法和ArrayList相似，略 
```

Stack类继承于Vector,当需要使用栈时，Java已不推荐使用*Stack*，而是推荐使用更高效的ArrayDeque(次选是LinkedList)

---

##### LinkedList类

###### 概述

- LinkedList类底层实现了双向链表和双端队列特点，也就是说它既可以看作一个顺序容器，又可以看作一个队列(Queue)，同时又可以看作一个栈(Stack)

- 其中含有两个属性：first 和 last 分别指向首节点和尾节点

    ![image-20220227134230977](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220227134230977.png) 

- 可以添加任意元素包括null，并且可以重复

- 线程不安全没有实现同步

- 进行添加和删除操作，效率比数组高

- 每个节点里面含有prev，next，item三个属性，其中通过prev指向前一个节点，通过next指向后一个节点，用item来存储数据

    ```java
    private static class Node<E> {
        E item;
        Node<E> next;
        Node<E> prev;
    
        Node(Node<E> prev, E element, Node<E> next) {
            this.item = element;
            this.next = next;
            this.prev = prev;
        }
    }
    ```

![image-20220227142526922](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220227142526922.png)

###### 源码分析

**添加数据源码分析**

![image-20220227160330222](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220227160330222.png) 

```java
// 添加第一个数据
// 跳转1
public boolean add(E e) { 
    linkLast(e);
    return true;
}
// 跳转2
void linkLast(E e) {
    final Node<E> l = last; // last:null 第一次添加last为null
    final Node<E> newNode = new Node<>(l, e, null); //l：null e:"lns"  说明prev和next指向null
    last = newNode; // last 指向尾节点 
    if (l == null) // 添加第一个节点
        first = newNode; //  first和last都指向同一个节点
    else
        l.next = newNode; 
    size++;
    modCount++;
}
// 添加第二个数据: 省略部分不重要的
void linkLast(E e) {
    // 总结： l这个变量可以当成连接器，连接新节点和原来最后一个节点
    final Node<E> l = last; // l:链表的最后一个节点
    final Node<E> newNode = new Node<>(l, e, null); // 创建连接上一个节点的新节点，e："zlr"
    last = newNode; // last指向新的节点（该节点就是新的最后一个节点）
    if (l == null)
        first = newNode;
    else 
        l.next = newNode; // l指向新节点：节点变成l的下一个节点
    size++;
    modCount++;
}
// 删除数据还是更改数据...等等看源码
```

###### 常用方法

```java
// add 增加节点
LinkedList linkedList = new LinkedList();
linkedList.add("lns");
linkedList.add("zlr");
System.out.println(linkedList.toString()); // [lns, zlr]

// remove 删除节点
linkedList.remove(); // 默认删除第一个节点
System.out.println(linkedList); // [zlr]

// set 修改节点
linkedList.set(0,"奥里给");
System.out.println(linkedList); // [奥里给]

// get 根据索引获得某个节点数据
System.out.println(linkedList.get(0)); // 奥里给
```

---

**Vector、ArrayList和LinkedList的比较**

| 实现List接口 | 底层结构 |  版本  |       线程安全       |                           扩容机制                           |
| :----------: | :------: | :----: | :------------------: | :----------------------------------------------------------: |
|    Vector    | 可变数组 | jdk1.0 |   安全，但效率不高   | 如果有参构造 扩容2倍；如果是无参构造器第一次默认10，第二次扩容2倍 |
|  ArrayList   | 可变数组 | jdk1.2 | 不安全，但改查效率高 | 如果有参构造 扩容1.5倍；如果是无参构造器第一次默认10，第二次扩容1.5倍 |
|  LinkedList  | 双向链表 | jdk1.2 | 不安全，但增删效率高 |                         链表动态扩容                         |



#### Queue接口

Java里有一个叫做Stack的类，却没有叫做Queue的类(它是个接口名字)。当需要使用栈时，Java已不推荐使用Stack，而是推荐使用更高效的ArrayDeque；既然Queue只是一个接口，当需要使用队列时也就首选ArrayDeque了(次选是LinkedList)

##### Deque接口

"double ended queue", 表示双向的队列，Deque接口继承于Queue接口

|  Deque Method   |                  说明                  |
| :-------------: | :------------------------------------: |
|  `addLast(e)`   |     向队尾插入元素，失败则抛出异常     |
| `offerLast(e)`  |   向队尾插入元素，失败则返回`false`    |
| `removeFirst()` |   获取并删除队首元素，失败则抛出异常   |
|  `pollFirst()`  |  获取并删除队首元素，失败则返回`null`  |
|  `getFirst()`   |  获取但不删除队首元素，失败则抛出异常  |
|  `peekFirst()`  | 获取但不删除队首元素，失败则返回`null` |

###### ArrayDeque类

**概述**

ArrayDeque类 本质是一个循环数组，为什么这么认为？

```java
public void addLast(E e) {
    if (e == null)
        throw new NullPointerException();
    elements[tail] = e;
    if ( (tail = (tail + 1) & (elements.length - 1)) == head) // 判端尾节点是否与首节点相遇，意味着是循环的
        doubleCapacity();
}
```

**特点**

- 不能插入空值 null ，如果插入则会抛出空指针异常

    ```java
    if (e == null)
        throw new NullPointerException(); 
    ```

- 非线程安全的（没有被synchronized修饰）

- 每个节点是Object对象

    ```java
    transient Object[] elements;
    ```

**构造器**

如果是无参构造器，初始化容量为16，扩容则以两倍的方式就行扩容

```java
public ArrayDeque() {
    elements = new Object[16];
}

// 扩容
private void doubleCapacity() {
    // 断言是否容量不足
    assert head == tail;
    int p = head;
    int n = elements.length;
    int r = n - p; // number of elements to the right of p
    // 扩容两倍
    int newCapacity = n << 1;
    if (newCapacity < 0)
        throw new IllegalStateException("Sorry, deque too big");
    Object[] a = new Object[newCapacity];
    System.arraycopy(elements, p, a, 0, r); // 复制右半部分
    System.arraycopy(elements, 0, a, r, p); // 复制左半部分
    elements = a;
    head = 0;
    tail = n;
}
```

反之是有参构造器，需要指定容量的大小

```java
public ArrayDeque(int numElements) {
    allocateElements(numElements);
}
```

**常用方法**

addFirst ： 在此双端队列的前面插入指定元素

```java
public void addFirst(E e) {
    if (e == null)
        throw new NullPointerException();
    elements[head = (head - 1) & (elements.length - 1)] = e // 防止由于空间没有满而导致数组下标越界的问题
    if (head == tail) // 判断是否还有容量
        doubleCapacity();
}
```

getFirst ：获取头节点的对象，但是该对象不会被弹出 (类似 peekFirst())

```java
public E getFirst() {
    @SuppressWarnings("unchecked")
    E result = (E) elements[head];
    if (result == null)
        throw new NoSuchElementException();
    return result;
}
```

pollFirst() ：删除并返回*Deque*首端元素

```java
public E pollFirst() {
    int h = head;
    @SuppressWarnings("unchecked")
    E result = (E) elements[h];
    // Element is null if deque empty
    if (result == null)
        return null;
    elements[h] = null;     // Must null out slot
    head = (h + 1) & (elements.length - 1);
    return result;
}
```

代码示例

```java
public static void main(String[] args) {
    ArrayDeque arrayDeque = new ArrayDeque();
    arrayDeque.addFirst("lns");
    arrayDeque.addLast("zlr");
    System.out.println(arrayDeque); // [lns, zlr]

    System.out.println(arrayDeque.getFirst()); // lns
    System.out.println(arrayDeque.getLast()); // zlr

    arrayDeque.pollFirst();
    System.out.println(arrayDeque); // [zlr]
}
```

---

##### PriorityQueue类

[学习链接](https://pdai.tech/md/java/collection/java-collection-PriorityQueue.html)

###### 概述

优先队列：能保证每次取出的元素都是队列中权值最小的元素（默认）；具体说是通过完全二叉树(*complete binary tree*)实现的**小顶堆**(任意一个非叶子节点的权值，都不大于其左右子节点的权值)，也就意味着可以通过数组来作为*PriorityQueue*的底层实现

```java
 transient Object[] queue; // non-private to simplify nested class access
```

图片取自[Java 全栈知识体系](https://pdai.tech/)（真的简洁清楚）

![[Java 全栈知识体系](https://pdai.tech/)](https://use-typora.oss-cn-hangzhou.aliyuncs.com/PriorityQueue_base.png)

注意父子节点的编号之间有如下关系:

- leftNo = parentNo * 2+1
- rightNo = parentNo * 2+2
- parentNo = (nodeNo-1) / 2

###### 构造器

- 如果是无参构造器，默认初始化为 11

    ```java
    private static final int DEFAULT_INITIAL_CAPACITY = 11; 
    
    public PriorityQueue() {
        this(DEFAULT_INITIAL_CAPACITY, null);
    }
    
    public PriorityQueue(int initialCapacity,
                         Comparator<? super E> comparator) {
        if (initialCapacity < 1)
            throw new IllegalArgumentException();
        this.queue = new Object[initialCapacity];
        this.comparator = comparator;
    }
    ```

    扩容机制：如果原数组长度小于64的时候，扩容 2倍 + 2 ；反之扩容1.5倍

    ```java
    private void grow(int minCapacity) {
        int oldCapacity = queue.length;
        // Double size if small; else grow by 50%
        int newCapacity = oldCapacity + ((oldCapacity < 64) ?
                                         (oldCapacity + 2) :
                                         (oldCapacity >> 1));
        // overflow-conscious code
        if (newCapacity - MAX_ARRAY_SIZE > 0)
            newCapacity = hugeCapacity(minCapacity);
        queue = Arrays.copyOf(queue, newCapacity);
    }
    ```

- 如果是有参构造器，需要指定初始化容量大小，同时可以传入比较器（匿名内部类的形式）

###### 常用方法

**offer()方法**

```java
public boolean offer(E e) {
    if (e == null)
        throw new NullPointerException();
    modCount++;
    int i = size;
    if (i >= queue.length) // 是否需要扩容
        grow(i + 1);
    size = i + 1;
    if (i == 0)
        queue[0] = e;
    else
        siftUp(i, e); // 接下来重点讲解！！！
    return true;
}
```

 **siftUp(i, e)方法**

```java
private void siftUp(int k, E x) {
    if (comparator != null)  // 是否有自己定制比较器
        siftUpUsingComparator(k, x);
    else
        siftUpComparable(k, x); 
}

// 任意一个非叶子节点的权值，都不大于其左右子节点的权值（所以需要进行重排）
@SuppressWarnings("unchecked")
private void siftUpComparable(int k, E x) {
    Comparable<? super E> key = (Comparable<? super E>) x;
    while (k > 0) {
        int parent = (k - 1) >>> 1; // parentNo = (nodeNo-1) / 2 父节点和子节点的关系 
        Object e = queue[parent];
        if (key.compareTo((E) e) >= 0)
            break;
        queue[k] = e;
        k = parent;
    }
    queue[k] = key;
}

// 以此类推
@SuppressWarnings("unchecked")
private void siftUpUsingComparator(int k, E x) {
    while (k > 0) {
        int parent = (k - 1) >>> 1;
        Object e = queue[parent];
        if (comparator.compare(x, (E) e) >= 0)
            break;
        queue[k] = e;
        k = parent;
    }
    queue[k] = x;
}
```

图片取自[Java 全栈知识体系](https://pdai.tech/)（siftUp方法的实现过程）

![PriorityQueue_offer.png](https://use-typora.oss-cn-hangzhou.aliyuncs.com/PriorityQueue_offer.png)

**poll() 方法**

```java
public E poll() {
    if (size == 0)
        return null;
    int s = --size;
    modCount++;
    E result = (E) queue[0];
    E x = (E) queue[s];
    queue[s] = null;
    if (s != 0)
        siftDown(0, x);
    return result;
}
```

 **siftDown(0, x)方法**

```java
private void siftDown(int k, E x) {
    if (comparator != null) 
        siftDownUsingComparator(k, x);
    else
        siftDownComparable(k, x);
}

@SuppressWarnings("unchecked")
private void siftDownComparable(int k, E x) {
    Comparable<? super E> key = (Comparable<? super E>)x;
    int half = size >>> 1;        // loop while a non-leaf
    while (k < half) {
        int child = (k << 1) + 1; // assume left child is least
        Object c = queue[child];
        int right = child + 1;
        if (right < size &&
            ((Comparable<? super E>) c).compareTo((E) queue[right]) > 0)
            c = queue[child = right];
        if (key.compareTo((E) c) <= 0)
            break;
        queue[k] = c;
        k = child;
    }
    queue[k] = key;
}

@SuppressWarnings("unchecked")
private void siftDownUsingComparator(int k, E x) {
    int half = size >>> 1;
    while (k < half) {
        int child = (k << 1) + 1;
        Object c = queue[child];
        int right = child + 1;
        if (right < size &&
            comparator.compare((E) c, (E) queue[right]) > 0)
            c = queue[child = right];
        if (comparator.compare(x, (E) c) <= 0)
            break;
        queue[k] = c;
        k = child;
    }
    queue[k] = x;
}
```

图片取自[Java 全栈知识体系](https://pdai.tech/)（siftDown方法的实现过程）

![https://use-typora.oss-cn-hangzhou.aliyuncs.com/PriorityQueue_poll.png](https://use-typora.oss-cn-hangzhou.aliyuncs.com/PriorityQueue_poll.png)



#### Set接口

public interface Set<E> extends Collection<E>

**Set接口基本介绍**

- 无序（添加和取出顺序不一致），没有索引，因此该接口不能再使用普通for循环索引的方式遍历 
- 不允许重复数据
- 允许有 null 值
- Set接口实现了Collection接口，所以可以使用该接口的所有方法

```java
Set set = new HashSet();
set.add("lns");
set.add("null"); // 允许存入 null 值
set.add("null"); // 只会存入一个数据
set.add("zlr");
System.out.println(set); // [lns, zlr, null] 无序
```

---

##### HashSet类

HashSet的底层实际上就是HashMap

```java
/**
 * Constructs a new, empty set; the backing {@code HashMap} instance has
 * default initial capacity (16) and load factor (0.75).
 */
public HashSet() {
    map = new HashMap<>();
}
```

**HashSet 框架图**

![image-20220228105517461](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220228105517461.png) 

**HashSet 特点**

- 不能存放重复元素（基本数据类型取决于值是否相等，引用数据类型取决于 equal() 和 hashcode() 方法）

    ```java
    public class HashSet01 {
        public static void main(String[] args) {
            Set set = new HashSet();
            System.out.println(set.add("lns")); // true
            System.out.println(set.add("lns")); // false
            System.out.println(set.add(new String("lns"))); // false 
            System.out.println("lns".hashCode() == new String("lns").hashCode()); // true
            System.out.println(set.add(new person("zlr"))); // true
            System.out.println(set.add(new person("zlr"))); // true
            // new String("lns") 的hashCode和"lns"相同
        }
    }
    class person{
        private String name;
    
        public person(String name) {
            this.name = name;
        }
    }
    
    // 实例说明：如果有元素并且hashCode值相同，则调用equals方法进行比较，如果相同则不添加，反之添加
    // 这就是为什么new String("lns")不会被添加以及为什么new person("zlr")会被添加2次
    // 核心就在于equals方法
    // 但是为什么"lns"的hashCode会和 new String("lns")相同呢（不是不同的地址吗）
    // 关键就在String类重写了hashCode方法,字符串的hashCode是根据字符算出来的
    /*
        String类计算hashCode的算法
        public static int hashCode(byte[] value) {
            int h = 0;
            for (byte v : value) { // value：传入的字符串
                h = 31 * h + (v & 0xff);
            }
            return h;
        }
    */
    ```

- 元素是无序的，但是顺序是有依据的而非随机数

**HashSet底层机制**

先介绍散列表：数组 + 链表 

实例代码

```java
public class HashSetStructure {
    public static void main(String[] args) {
        // 数组 + 链表
        Node[] table = new Node[16];
        // 创建节点
        Node node21 = new Node("lns", null);
        table[2] = node21;

        Node node22 = new Node("zlr", null);
        node21.next = node22;

        Node node23 = new Node("lp", null);
        node22.next = node23;

        Node node31 = new Node("cyj", null);
        table[3] = node31;

        System.out.println(Arrays.toString(table));
    }
}
// 链表
class Node{ // 节点
    Object item; // 数据
    Node next; // 指向下个节点

    public Node(Object item, Node next) {
        this.item = item;
        this.next = next;
    }
}
```

图解分析散列表结构

![image-20220227201842892](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220227201842892.png) 

```java
// 节点Node代码
static class Node<K,V> implements Map.Entry<K,V> {
    final int hash;
    final K key;
    V value;
    Node<K,V> next;

    Node(int hash, K key, V value, Node<K,V> next) {
        this.hash = hash;
        this.key = key;
        this.value = value;
        this.next = next;
    }

    public final K getKey()        { return key; }
    public final V getValue()      { return value; }
    public final String toString() { return key + "=" + value; }

    public final int hashCode() {
        return Objects.hashCode(key) ^ Objects.hashCode(value);
    }

    public final V setValue(V newValue) {
        V oldValue = value;
        value = newValue;
        return oldValue;
    }

    public final boolean equals(Object o) {
        if (o == this)
            return true;
        if (o instanceof Map.Entry) {
            Map.Entry<?,?> e = (Map.Entry<?,?>)o;
            if (Objects.equals(key, e.getKey()) &&
                Objects.equals(value, e.getValue()))
                return true;
        }
        return false;
    }
}

```

**HashSet底层实现过程**

1. 添加一个元素时，先得到hash值 => 索引值（类似图中 0-16索引）

2. 找到存储数据表table，看这个索引上是否有存放数据

    1. 如果没有找到，就直接加入（如图中的node21,node31）；如果有元素并且hashCode值相同，则调用equals方法进行比较，如果相同则不添加，反之添加
3. 在jdk8中，一个链表的元素达到8个以及table数据表长度达到64.则将 数组+链表 => 红黑树

```java
public class HashSet02 {
    public static void main(String[] args) {
        HashSet hashSet = new HashSet();
        hashSet.add("罗念笙");
        hashSet.add("张洛融");
        hashSet.add("罗念笙");
        System.out.println(hashSet); // [张洛融, 罗念笙]
    }
}
        
/*
 *     分析源码
 *     假设传入"罗念笙"
 *     跳转1：add方法
 *     public boolean add(E e) {
 *         return map.put(e, PRESENT)==null; // PRESENT：占位 new Object()
 *     }
 *
 *     跳转2：put方法
 *     public V put(K key, V value) {
 *         return putVal(hash(key), key, value, false, true);
 *     }
 *
 *     跳转3：hash方法 计算hash值并返回给put方法中hash(key)
 *     static final int hash(Object key) {
 *         int h;
 *         return (key == null) ? 0 : (h = key.hashCode()) ^ (h >>> 16);
 *     }
 *
 *     跳转4：pubVal方法   传入形参：hash值, "罗念笙", PRESENT, false, true
 *     final V putVal(int hash, K key, V value, boolean onlyIfAbsent,boolean evict) {
 *         Node<K,V>[] tab; Node<K,V> p; int n, i; // 定义辅助变量
 *         // transient Node<K,V>[] table; table：数组+链表形式
 *         if ((tab = table) == null || (n = tab.length) == 0) // 没有分配数组空间
 *             // 分配数组空间 newCap = DEFAULT_INITIAL_CAPACITY 默认16
 *             n = (tab = resize()).length; 
 *         if ((p = tab[i = (n - 1) & hash]) == null) // i = (n - 1) & hash 通过hash值计算索引
 *             tab[i] = newNode(hash, key, value, null); // 该索引下数组值为null，就直接添加节点
 *         else {
 *             Node<K,V> e; K k; // 定义辅助变量
 *             // 比较索引处首节点的 hash值 以及 指向地址是否相同 或者 比较值是否相同（重写的情况）
 *             if (p.hash == hash && ((k = p.key) == key || (key != null && key.equals(k))))
 *                 e = p;
 *             // 判断索引p 指向的是否是红黑树
 *             else if (p instanceof TreeNode)
 *                 e = ((TreeNode<K,V>)p).putTreeVal(this, tab, hash, key, value);
 *             // 遍历该索引的所有节点，依次比较；如果相同则不添加
 *             else {
 *                 for (int binCount = 0; ; ++binCount) {
 *                     if ((e = p.next) == null) {
 *                         p.next = newNode(hash, key, value, null);
 *                         if (binCount >= TREEIFY_THRESHOLD - 1) // -1 for 1st
 *                             treeifyBin(tab, hash);
 *                         break;
 *                     }
 *                     if (e.hash == hash &&
 *                         ((k = e.key) == key || (key != null && key.equals(k))))
 *                         break;
 *                     p = e;
 *                 }
 *             }
 *             if (e != null) { // existing mapping for key
 *                 V oldValue = e.value;
 *                 if (!onlyIfAbsent || oldValue == null)
 *                     e.value = value;
 *                 afterNodeAccess(e);
 *                 return oldValue;
 *             }
 *         }
 *         ++modCount;
 *         // threshold 阈值,用来提前给数组扩容 ：threshold = (int)(DEFAULT_LOAD_FACTOR *                    DEFAULT_INITIAL_CAPACITY);
 *         // size 大小值得是加入的节点个数达到了阈值
 *         if (++size > threshold)
 *             resize();
 *         afterNodeInsertion(evict); // HashMap类留给子类继承使用的方法
 *         return null;
 *     }
 *
 *     // treeifyBin方法 一个链表的元素达到8个以及table数据表长度达到64.则将 数组+链表 => 红黑树
 *     final void treeifyBin(Node<K,V>[] tab, int hash) {
 *         int n, index; Node<K,V> e;
 *         // 如果表的长度（数组长度）小于64，则扩容
 *         // MIN_TREEIFY_CAPACITY：64  
 *         if (tab == null || (n = tab.length) < MIN_TREEIFY_CAPACITY)
 *             resize();
 *         // 如果表的长度（数组长度）大于等于64，则数组+链表 => 红黑树
 *         else if ((e = tab[index = (n - 1) & hash]) != null) {
 *             TreeNode<K,V> hd = null, tl = null;
 *             do {
 *                 TreeNode<K,V> p = replacementTreeNode(e, null);
 *                 if (tl == null)
 *                     hd = p;
 *                 else {
 *                     p.prev = tl;
 *                     tl.next = p;
 *                 }
 *                 tl = p;
 *             } while ((e = e.next) != null);
 *             if ((tab[index] = hd) != null)
 *                 hd.treeify(tab);
 *         }
 *     }
 */
```

---

##### LinkedHahSet类

LinkedHashSet类底层是一个LinkedHashMap，是一个**数组**+**双向链表**的结构

```java
// 初始化LinkedHashSet
// LinkedHashSet类构造器
public LinkedHashSet() {
    super(16, .75f, true); // 初始化容量16；负载因子0.75
}
// 调用父类HashSet构造器，初始化LinkedHashMap
HashSet(int initialCapacity, float loadFactor, boolean dummy) {
    map = new LinkedHashMap<>(initialCapacity, loadFactor);
}
// LinkedHashMap调用父类的HashMap的构造器
public LinkedHashMap(int initialCapacity, float loadFactor) {
    super(initialCapacity, loadFactor);
    accessOrder = false;
}
// 初始化HashMap
public HashMap(int initialCapacity, float loadFactor) {
    if (initialCapacity < 0)
        throw new IllegalArgumentException("Illegal initial capacity: " +
                                           initialCapacity);
    if (initialCapacity > MAXIMUM_CAPACITY) // MAXIMUM_CAPACITY = 1 << 30
        initialCapacity = MAXIMUM_CAPACITY;
    if (loadFactor <= 0 || Float.isNaN(loadFactor))
        throw new IllegalArgumentException("Illegal load factor: " +
                                           loadFactor);
    this.loadFactor = loadFactor;
    this.threshold = tableSizeFor(initialCapacity);
}
```

**LinkedHashSet 框架图**

![image-20220228105904095](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220228105904095.png) 

**特点**

- 根据hashCode值来决定元素的存储位置，同时使用双向链表来维护元素的次序，所以在一定程度上是有序的
- 不允许重复添加元素

**LinkedHashSet类的底层分析**

![image-20220228170158121](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220228170158121.png)

```java
// LinkedHashSet节点源码
// 继承Node节点(HashMap的静态内部类) 
static class Entry<K,V> extends HashMap.Node<K,V> {
    Entry<K,V> before, after; // 增加前驱节点和后继节点 => 双向链表
    // 构造器
    Entry(int hash, K key, V value, Node<K,V> next) {
        // Node节点构造器
        super(hash, key, value, next);
    }
}
// 实现Map接口里的Entry接口
static class Node<K,V> implements Map.Entry<K,V> {
    final int hash;
    final K key;
    V value;
    Node<K,V> next;

    Node(int hash, K key, V value, Node<K,V> next) {
        this.hash = hash;
        this.key = key;
        this.value = value;
        this.next = next;
    }

    public final K getKey()        { return key; }
    public final V getValue()      { return value; }
    public final String toString() { return key + "=" + value; }

    public final int hashCode() {
        return Objects.hashCode(key) ^ Objects.hashCode(value);
    }

    public final V setValue(V newValue) {
        V oldValue = value;
        value = newValue;
        return oldValue;
    }

    public final boolean equals(Object o) {
        if (o == this)
            return true;
        if (o instanceof Map.Entry) {
            Map.Entry<?,?> e = (Map.Entry<?,?>)o;
            if (Objects.equals(key, e.getKey()) &&
                Objects.equals(value, e.getValue()))
                return true;
        }
        return false;
    }
}
```

---

##### TreeSet类

**基本介绍**

TreeSet类本质就是调用TreeMap,源码，比较机制等会在TreeMap中详细述说

```java
public TreeSet() {
    this(new TreeMap<>());
}
```

![image-20220302162013910](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220302162013910.png) 



### Map接口

public interface Map<K, V>  与Collection接口并列存在

**Map接口特点**

- 保存具有映射关系的数据：Key - Value
- Map 中的Key - Value数据可以是任何的引用数据类型，会封装到HashMap$Node对象中
- Map中的Key不允许重复，但是Value可以重复（并且数据都可以是null）
- Key 和 Value存在一对一的关系，总是能通过Key找到对应得Value

![image-20220228191506219](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220228191506219.png) 

**深入理解map接口的Node节点**

```java
// Node节点属于HashMap内部类,实现了Map.Entry<K,V>接口 ; 一个Node节点对象含有一个key和value
// Map.Entry<K,V> 为Map接口的内部接口
static class Node<K,V> implements Map.Entry<K,V> 
// key-value值是存储在Node节点对象中，Map.Entry中key-value指向Node节点对象的key-value值的引用（类似对象名对对象的引用）
final int hash;
final K key;
V value;
Node<K,V> next;
// 那么EntrySet又是什么呢
// Set接口都可理解就是单列集合，其实EntrySet就是存放Map.Entry数据类型的集合 
transient Set<Map.Entry<K,V>> entrySet;
// 代码示例
Map map = new HashMap();
map.put("name","罗念笙"); // key: name value: 罗念笙
map.put("name","张洛融"); // key值不能重复，如果重复会覆盖之前相同key值的value值
map.put("person","张洛融"); // value值能重复
System.out.println(map); // {person=张洛融, name=张洛融}
System.out.println(map.get("name")); // 张洛融 ; 能通过Key找到对应得Value
// 着重点看运行类型
Set set = map.entrySet();
System.out.println(set.getClass()); // class java.util.HashMap$EntrySet
for (Object obj: set
    ) {
    System.out.println(obj.getClass()); // class java.util.HashMap$Node
}
```

---

#### HashMap类

HashMap底层是**数组**+**链表**+**红黑树**

**HashMap类特点**

- 保存具有映射关系的数据：Key - Value

- Key不允许重复，但是Value可以重复（并且数据都可以是null）; 如果重复，将会替换掉value值

    ![image-20220301171734335](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220301171734335.png) 

- Key 和 Value存在一对一的关系，总是能通过Key找到对应得Value

- HashMap没有实现线程同步，是线程不安全的

**HashMap框架图**

![image-20220301171028407](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220301171028407.png) 

**注意  HashMap扩容机制等价于HashSet扩容机制,如上述**

**遍历方式**

```java
// Map接口遍历方式
Map map = new HashMap();
map.put("name","lns");
map.put("age",18);
map.put("grade",99);

//  第一组: 先取出key（keySet方法，通过key取出value (get方法)
Set set = map.keySet();
// 方式1: 增强for
for (Object key:set
     ) {
    // key: grade value: 99  key: name value: lns  key: age value: 18
    System.out.print("key: "+key+" value: "+map.get(key)+"  ");
}
System.out.println();
// 方式2: 迭代器
Iterator iterator = set.iterator();
while(iterator.hasNext()){
    Object key = iterator.next();
    // key: grade value: 99  key: name value: lns  key: age value: 18
    System.out.print("key: "+key+" value: "+map.get(key)+"  ");
}
System.out.println();

// 第二组: 通过EntrySet来获取key-value
Set entrySet = map.entrySet();
// 方式3: 用getKey方法 和 getValue方法
for (Object obj: entrySet
     ) {
    Map.Entry entry = (Map.Entry)obj;
    // key: grade value: 99  key: name value: lns  key: age value: 18
    System.out.print("key: "+entry.getKey()+" value: "+entry.getValue()+"  ");
}
System.out.println();
// 方式4: 迭代器
Iterator iterator1 = entrySet.iterator();
while(iterator1.hasNext()){
    Map.Entry entry = (Map.Entry)iterator1.next(); 
    // key: grade value: 99  key: name value: lns  key: age value: 18
    System.out.print("key: "+entry.getKey()+" value: "+entry.getValue()+"  ");
}
```

**常用方法**

```java
// 常用方法
// put方法 添加key-value
Map map = new HashMap();
map.put("name","lns");
map.put("age",18);
map.put("grade",99);
map.put("grade",60); // 重复key，覆盖之前的value
System.out.println(map); // {grade=60, name=lns, age=18}
// remove方法 根据key值删除映射关系
map.remove("grade");
System.out.println(map); // {name=lns, age=18}
// get方法 根据key获得value值
System.out.println(map.get("age")); // 18
// size方法 获取元素个数
System.out.println(map.size()); // 2
// isEmpty方法 判断元素是否为空
System.out.println(map.isEmpty()); // false
// containsKey 查找该键是否存在
System.out.println(map.containsKey("name")); // true
// clear 清空键值对]
map.clear();
System.out.println(map); // {}
```

----

#### Hashtable类

**Hashtable类特点**

- 保存具有映射关系的数据：Key - Value

- Hashtable的key和value都不允许是null，如果是，将会抛出空指针异常

    ![image-20220302085244120](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220302085244120.png) 

- Hashtable是线程安全的，与HashMap不同

    ```java
    // Hashtable的put方法
    public synchronized V put(K key, V value)
    ```

**Hashtable框架图**

![image-20220302135647398](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220302135647398.png) 

**Hashtable扩容机制**

```java
//Hashtable构造器初始化容量11
public Hashtable() {
    this(11, 0.75f); 
} 

// put方法
public synchronized V put(K key, V value) {
    // Make sure the value is not null
    if (value == null) {
        throw new NullPointerException();
    }

    // Makes sure the key is not already in the hashtable.
    Hashtable.Entry<?,?> tab[] = table;
    int hash = key.hashCode();
    int index = (hash & 0x7FFFFFFF) % tab.length; // 索引值的计算方式: 散列码（hash）% 散列表的长度（tab.length）
    @SuppressWarnings("unchecked") // 抑制警告
    Hashtable.Entry<K,V> entry = (Hashtable.Entry<K,V>)tab[index]; // 创建entry节点
    // 判断是否有相同的key的entry节点，如果有，就替换掉原来的value值；反之则添加entry节点
    for(; entry != null ; entry = entry.next) {
        if ((entry.hash == hash) && entry.key.equals(key)) {
            V old = entry.value;
            entry.value = value;
            return old;
        }
    }
    // 添加entry节点
    addEntry(hash, key, value, index);
    return null;
}

// addEntry方法
private void addEntry(int hash, K key, V value, int index) {
    Entry<?,?> tab[] = table; // 成员变量table: 用来存储之前添加的键值对
    if (count >= threshold) { // 判断是否需要扩容
        // Rehash the table if the threshold is exceeded
        rehash();

        tab = table;
        hash = key.hashCode();
        index = (hash & 0x7FFFFFFF) % tab.length;
    }

    // Creates the new entry.
    @SuppressWarnings("unchecked")
    Entry<K,V> e = (Entry<K,V>) tab[index];
    tab[index] = new Entry<>(hash, key, value, e);
    count++;
    modCount++;
}

// rehash方法 用于扩容
protected void rehash() {
    int oldCapacity = table.length; // 记录原来的散列表的长度(table.length)
    Entry<?,?>[] oldMap = table; // 记录原来的散列表（table）

    // overflow-conscious code
    int newCapacity = (oldCapacity << 1) + 1; // 新容量 = 旧容量 * 2 + 1
    if (newCapacity - MAX_ARRAY_SIZE > 0) {
        if (oldCapacity == MAX_ARRAY_SIZE)
            // Keep running with MAX_ARRAY_SIZE buckets
            return;
        newCapacity = MAX_ARRAY_SIZE;
    }
    Entry<?,?>[] newMap = new Entry<?,?>[newCapacity]; // 数组扩容

    modCount++;
    threshold = (int)Math.min(newCapacity * loadFactor, MAX_ARRAY_SIZE + 1);
    table = newMap;
    // 添加原来的数组数据
    for (int i = oldCapacity ; i-- > 0 ;) {
        for (Entry<K,V> old = (Entry<K,V>)oldMap[i] ; old != null ; ) {
            Entry<K,V> e = old;
            old = old.next;

            int index = (e.hash & 0x7FFFFFFF) % newCapacity;
            e.next = (Entry<K,V>)newMap[index];
            newMap[index] = e;
        }
    }
}
```

**细节说明**

![image-20220302155704520](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220302155704520.png) 

```java
// 源码说明
// addEntry方法
private void addEntry(int hash, K key, V value, int index) {
    Entry<?,?> tab[] = table; // 成员变量table: 用来存储之前添加的键值对
    if (count >= threshold) { // 判断是否需要扩容
        // Rehash the table if the threshold is exceeded
        rehash();

        tab = table;
        hash = key.hashCode();
        index = (hash & 0x7FFFFFFF) % tab.length;
    }

    // Creates the new entry.
    @SuppressWarnings("unchecked")
    Entry<K,V> e = (Entry<K,V>) tab[index]; // 该索引该的引用节点的引用赋值给e
    tab[index] = new Entry<>(hash, key, value, e); // 加入当前的节点，并且指向下一个节点e
    count++;
    modCount++;
}
// Entry内部类的构造器 说明e 为当前节点的下一个节点
protected Entry(int hash, K key, V value, Entry<K,V> next) {
    this.hash = hash;
    this.key =  key;
    this.value = value;
    this.next = next;
}
```

**Hashtable类和HashMap类的区别**

|           | 版本 | 线程（安全） | 效率 | 允许(null键  ，null值) |
| :-------: | :--: | :----------: | :--: | :--------------------: |
|  HashMap  | 1.2  |    不安全    |  高  |          允许          |
| Hashtable | 1.0  |     安全     | 较低 |         不允许         |

---

#### TreeMap类

**基本介绍**

使用`TreeMap`时，如果是调用无参构造器，则放入的Key对象必须实现`Comparable`接口。**String**、**Integer**这些类已经实现了`Comparable`接口，因此可以直接作为Key使用。作为Value的对象则没有任何要求。如果作为Key的class没有实现`Comparable`接口，那么，必须在创建`TreeMap`时同时指定一个自定义排序算法

TreeMap类的有序是按一定规则的有序，而非LinkedHashSet的插入和取出顺序一致

**红黑树的具体结构**

**红黑树是一种近似平衡的二叉查找树，它能够确保任何一个节点的左右子树的高度差不会超过二者中较低那个的一倍**

满足以下四种条件

1. 每个节点要么是红色，要么是黑色。
2. 根节点必须是黑色
3. 红色节点不能连续(也即是，红色节点的孩子和父亲都不能是红色)。
4. 对于每个节点，从该点至`null`(树尾端)的任何路径，都含有相同个数的黑色节点。

![image-20220809195954770](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220809195954770.png) 

如果加入/减少参数会影响到红黑树的结构，结构调整过程包含两个基本操作 : 左旋(Rotate Left)，右旋(RotateRight)

[图片取自darker](https://zhuanlan.zhihu.com/p/80647496)

![image-20220813201824447](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220813201824447.png)

**TreeMap源码分析**

1. 无参构造器

```java
// debug 代码示例
public class TreeMap01 {
    public static void main(String[] args) {
        TreeMap treeMap = new TreeMap();
        treeMap.put("name","罗念笙");
        treeMap.put("age",18);
        System.out.println(treeMap); // {age=18, height=192, name=罗念笙}
    }
}

// 无参构造器： new TreeMap();
public TreeMap() {
    comparator = null; // comparator：TreeMap中的属性（用来存储comparator内部类的对象）
}

// 传入第一个参数：put("name","罗念笙")；
// 跳转1
public V put(K key, V value) { //key: name  value: 罗念笙
    return put(key, value, true);
}
// 跳转2
private V put(K key, V value, boolean replaceOld) {
    Entry<K,V> t = root; // t指向根节点
    if (t == null) { // 如果根节点没数据
        addEntryToEmptyMap(key, value); // 增加Entry节点
        return null;
    }
    // 删除的一部分代码，在添加第一个节点不会遍历
}
// 跳转3 
private void addEntryToEmptyMap(K key, V value) {
    compare(key, key); // type (and possibly null) check
    root = new Entry<>(key, value, null); // 创建新的节点
    size = 1;
    modCount++;
}
// 跳转4
final int compare(Object k1, Object k2) {
    // 如果构造器没有传入comparator内部类的对象，则k1对象对应的类必须实现了compareTo方法
    // 就是实现了Comparable接口并且重写compareTo方法，并且k1和k2是可以比较的
    return comparator==null ? ((Comparable<? super K>)k1).compareTo((K)k2)
        : comparator.compare((K)k1, (K)k2);
}
// 跳转5  跳转到String类的compareTo方法
public int compareTo(String anotherString) {
    byte v1[] = value;
    byte v2[] = anotherString.value;
    byte coder = coder();
    if (coder == anotherString.coder()) {
        return coder == LATIN1 ? StringLatin1.compareTo(v1, v2)
            : StringUTF16.compareTo(v1, v2);
    }
    return coder == LATIN1 ? StringLatin1.compareToUTF16(v1, v2)
        : StringUTF16.compareToLatin1(v1, v2);
}

// 传入第二数：put("age",18)；
// 跳转1
public V put(K key, V value) { // key: age  value: 18
    return put(key, value, true);
}
// 跳转2
private V put(K key, V value, boolean replaceOld) {
    Entry<K,V> t = root;
    if (t == null) { // 跳过
        addEntryToEmptyMap(key, value);
        return null;
    }
    // 辅助变量
    int cmp; 
    Entry<K,V> parent;
    // split comparator and comparable paths
    // 无参构造器中没有是实现该匿名内部类，所以comparator = null
    Comparator<? super K> cpr = comparator;
    if (cpr != null) { // 跳过
        do {
            parent = t;
            cmp = cpr.compare(key, t.key);
            if (cmp < 0)
                t = t.left;
            else if (cmp > 0)
                t = t.right;
            else {
                V oldValue = t.value;
                if (replaceOld || oldValue == null) {
                    t.value = value;
                }
                return oldValue;
            }
        } while (t != null);
    } else {
        Objects.requireNonNull(key); // 检查key是否为null
        @SuppressWarnings("unchecked") // 抑制警告
        // 强转key为Comparable接口（接口多态）：判断key是否实现了Comparable接口，如果不是将会抛出               ClassCastException异常
        Comparable<? super K> k = (Comparable<? super K>) key;
        do {
            parent = t; // 根节点变成了父节点
            cmp = k.compareTo(t.key); // 比较规则
            if (cmp < 0) 
                t = t.left;
            else if (cmp > 0)
                t = t.right;
            else {
                V oldValue = t.value;
                if (replaceOld || oldValue == null) {
                    t.value = value;
                }
                return oldValue;
            }
        } while (t != null);
    }
    addEntry(key, value, parent, cmp < 0);
    return null;
}
// 跳转3 
public static <T> T requireNonNull(T obj) {
    if (obj == null)
        throw new NullPointerException();
    return obj;
}
// 跳转4 跳转到String类的compareTo方法
public int compareTo(String anotherString) {
    byte v1[] = value;
    byte v2[] = anotherString.value;
    byte coder = coder();
    if (coder == anotherString.coder()) {
        return coder == LATIN1 ? StringLatin1.compareTo(v1, v2)
            : StringUTF16.compareTo(v1, v2);
    }
    return coder == LATIN1 ? StringLatin1.compareToUTF16(v1, v2)
        : StringUTF16.compareToLatin1(v1, v2);
}
// 跳转5
private void addEntry(K key, V value, Entry<K, V> parent, boolean addToLeft) {
    Entry<K,V> e = new Entry<>(key, value, parent); // 创建新节点
    if (addToLeft)
        parent.left = e;
    else
        parent.right = e;
    fixAfterInsertion(e);
    size++;
    modCount++;
}
// 跳转6：设置节点颜色：红和黑
/** From CLR */
private void fixAfterInsertion(Entry<K,V> x) {
    x.color = RED;

    while (x != null && x != root && x.parent.color == RED) {
        if (parentOf(x) == leftOf(parentOf(parentOf(x)))) {
            Entry<K,V> y = rightOf(parentOf(parentOf(x)));
            if (colorOf(y) == RED) {
                setColor(parentOf(x), BLACK);
                setColor(y, BLACK);
                setColor(parentOf(parentOf(x)), RED);
                x = parentOf(parentOf(x));
            } else {
                if (x == rightOf(parentOf(x))) {
                    x = parentOf(x);
                    rotateLeft(x);
                }
                setColor(parentOf(x), BLACK);
                setColor(parentOf(parentOf(x)), RED);
                rotateRight(parentOf(parentOf(x)));
            }
        } else {
            Entry<K,V> y = leftOf(parentOf(parentOf(x)));
            if (colorOf(y) == RED) {
                setColor(parentOf(x), BLACK);
                setColor(y, BLACK);
                setColor(parentOf(parentOf(x)), RED);
                x = parentOf(parentOf(x));
            } else {
                if (x == leftOf(parentOf(x))) {
                    x = parentOf(x);
                    rotateRight(x);
                }
                setColor(parentOf(x), BLACK);
                setColor(parentOf(parentOf(x)), RED);
                rotateLeft(parentOf(parentOf(x)));
            }
        }
    }
    root.color = BLACK;
}
```

2.有参构造器

```java
public class TreeMap02 {
    public static void main(String[] args) {
        // 通过key中的字符大小进行排序 降序: name > height > age
        TreeMap treeMap1 = new TreeMap(new Comparator() {
            @Override
            public int compare(Object o1, Object o2) {
                return ((car)o2).compareName((car)o1);
            }
        });
        treeMap1.put(new car("e"),"LNS");
        treeMap1.put(new car("da"),18);
        treeMap1.put(new car("dwes"),185);
        // {com.Al_tair.map_.treeMap_.car@27d6c5e0=185,
        //  com.Al_tair.map_.treeMap_.car@4f3f5b24=18,
        //  com.Al_tair.map_.treeMap_.car@15aeb7ab=LNS}
        System.out.println(treeMap1);
    }
}

class car{
    String name;
    public car(String name) {
        this.name = name;
    }
    public String getName() {
        return name;
    }
    public int compareName(Object o) {
        return this.getName().length()-((car)o).getName().length();
    }
}
```

![](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220302231332592.png) 

---

#### Properties类

**基本介绍**

![image-20220302141600899](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220302141600899.png) 

**Properties类特点**

- 保存具有映射关系的数据：Key - Value，注意键值对不需要有空格，值不需要用引号引起来，默认为String
- Hashtable的key和value都不允许是null，如果是，将会抛出空指针异常

**常用方法**

```java
// 常用方法
Properties properties = new Properties();
// put方法 添加数据,修改数据
properties.put("name","罗念笙");
properties.put("age",18);
properties.put("grade",99);
properties.put("grade",98); //修改数据
System.out.println(properties); // {grade=98, name=罗念笙, age=18}

// 通过key获取value
System.out.println(properties.get("name")); // 罗念笙

// remove方法 删除数据
properties.remove("grade");
System.out.println(properties); // {name=罗念笙, age=18}

load：加载配置文件的键值对到Properties对象
list：将数据显示到指定设备
getProperty(key)：根据键获取值
getProperty(key，value)：设置键值对到Properties对象
store:将Properties中的键值对存储到配置文件中，如果含有中文，会存储为unicode码
```

**Properties类的使用**

```java
public class Properties_ {
    public static void main(String[] args) throws IOException {
        // 读取Properties配置文件
        // 创建properties对象
        Properties pro = new Properties();
        // 加载数据到Properties对象中
        pro.load(new FileReader("E:\\Java_training\\Java_code\\JavaIdea03\\java\\Javase_HSping\\src\\com\\Al_tair\\ioStream_\\mysql.properties"));
        pro.list(System.out);
        String root = pro.getProperty("root");
        String pwd = pro.getProperty("pwd");
        System.out.println("root: " + root + " pwd: " + pwd);

        // 转存配置文件到mysql.properties
        Properties pro2 = new Properties();
        // 配置文件数据
        pro2.setProperty("charset","utf-8");
        pro2.setProperty("name","lns");
        pro2.setProperty("lover","zlr");
        // 存储到文件
        pro2.store(new FileWriter("E:\\Java_training\\Java_code\\JavaIdea03\\java\\Javase_HSping\\src\\com\\Al_tair\\ioStream_\\mysql2.properties"),null);
    }
}
```

**结果**

![image-20220317090850727](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220317090850727.png) 



### 如何选择集合实现类

1. 先判断存储的数据类型（一组对象或者一组键值对）
2. 一组对象【单列集合】：Collection接口
    - 允许重复并且有序：List接口
        - 线程安全：Vector【底层是一个Object类型的可变数组】
        - 线程不安全：
            - 增删多：LinkedList【底层是一个双向链表】
            - 改查多：ArrayLIst【底层是一个Object类型的可变数组】
    - 不允许重复：Set接口
        - 无序并且线程不安全：HashSet【底层就是HashMap，数组+链表+红黑数】
        - 定制排序并且线程不安全：TreeSet
        - 插入和取出顺序一致，并且线程不安全: LinkedHashSet 【数组+双向链表】 
3. 一组键值对：Map接口
    - 线程不安全：
        - 键无序：HashMap类 【底层就是：数组+链表+红黑数】
        - 定制排序：TreeMap类
        - 键插入和取出顺序一致：LinkedHashMap类
    - 线程安全：读取配置文件：Properties类



###  Colleactions工具类

Collections是一个操作Set，List，Map等集合的工具类，提供了一系列静态的方法对集合元素进行排序，查找和修改等操作

```java
// Collections工具类中常用方法
// 创建测试类
ArrayList arrayList = new ArrayList();
arrayList.add("cyj");
arrayList.add("lns");
arrayList.add("zlr");
System.out.println(arrayList); // [cyj, lns, zlr]
// reverse(List集合) 反转List中元素的顺序
Collections.reverse(arrayList);
System.out.println(arrayList); // [zlr, lns, cyj]
// shuffle(List集合) 对List集合元素进行随机排序
for (int i = 0; i < 3; i++) {
    Collections.shuffle(arrayList);
    System.out.println(arrayList); // 随机出现
}
// shuffle方法的源码
public static void shuffle(List<?> list) {
    Random rnd = r;
    if (rnd == null)
        r = rnd = new Random(); // harmless race.
    shuffle(list, rnd);
}
//  sort(List集合) 根据元素的自然排序对List集合进行升序 比如：字符串比较的是字符大小
arrayList.add("aaa");
Collections.sort(arrayList);
System.out.println(arrayList); // [aaa, cyj, lns, zlr]
// 用比较器Comparator自定义规则进行排序 sort(arrayList,new Comparator(){});
Collections.sort(arrayList,new Comparator(){
    @Override
    public int compare(Object o1, Object o2) {
        return ((String)o2).compareTo((String)o1);
    }
});
System.out.println(arrayList); // [zlr, lns, cyj, aaa]
// swap(List集合,int i,int j) 交换集合索引为i和j的位置
Collections.swap(arrayList,1,2);
System.out.println(arrayList); // [zlr, cyj, lns, aaa]
// max(Collection集合) 返回给定集合中自然排序最大的元素
System.out.println(Collections.max(arrayList)); // zlr
// max(Collection集合,new Comparator(){}) 返回给定集合中自治排序最大的元素
System.out.println(Collections.max(arrayList,new Comparator(){
    @Override
    public int compare(Object o1, Object o2) {
        return ((String)o2).compareTo((String)o1);
    }
})); // aaa
// frequency(Collection集合,集合中的元素) 返回该元素在集合中出现的频率
System.out.println(Collections.frequency(arrayList,"aaa")); // 1
// copy（List dest,List src） 复制src的元素到dest集合中
// 注意: 目标集合元素个数必须大于等于原来集合元素的个数
ArrayList dest = new ArrayList();
for (int i = 0; i < 6; i++) {
    dest.add(i);
}
Collections.copy(dest,arrayList);
System.out.println(dest); // [zlr, cyj, lns, aaa, 4, 5]
```



## 泛型

### 基本介绍

Java 泛型（generics）是 JDK 5 中引入的一个新特性, 泛型提供了**编译时类型安全检测机制**，该机制允许程序员在编译时检测到非法的类型

泛型的本质是参数化类型，也就是说所操作的数据类型被指定为一个参数

泛型特点

- 可以使用任意字母A-Z  T 是 type的缩写，比较常用

    ```java
    // 自定义泛型
    class Template<E>{
        E filed;
    
        @Override
        public String toString() {
            return "Template{" +
                    "filed=" + filed +
                    '}';
        }
    
        public E method(){
            return filed;
        }
    
        public Template(E filed) {
            this.filed = filed;
        }
    }
    ```

- 只能指代引用类型的数据

- 在给泛型指定具体类型后，可以传入该类型或者其子类类型

    ```java
    public class Generic02 {
        public static void main(String[] args) {
            C<A> C = new C<A>(new A());
            C<A> C2 = new C<A>(new B());
        }
    }
    class A{}
    class B extends A{}
    class C<E>{
        E c;
    
        public C(E c) {
            this.c = c;
        }
    } 
    ```

- 泛型的使用形式

    ```java
    ArrayList<Integer> arrayList = new ArrayList<Integer>();
    ArrayList<Integer> arrayList2 = new ArrayList<>(); // 推荐
    ArrayList arrayList = new ArrayList(); // 默认泛型为Object
    ```




**分析泛型编译后的文件**

java里面的泛型只存在于源代码里面，一旦经过编译之后，所有的泛型都会被擦除掉，全部被替换为原来的裸类型，并在对元素进行访问和修改的时候，才会加上强制类型转换。

```java
// （所谓的裸类型指的是，ArrayList<Integer>() 他的裸类型就是ArrayList()）
public class Test {
    public static void main(String[] args) {
        ArrayList<String> sList = new ArrayList<String>();
        ArrayList<Integer> iList = new ArrayList<Integer>();
        // getClass()方法 表示此对象的运行时类的Class对象
        System.out.println(sList.getClass() == iList.getClass()); // true
    }
}
```

```java
// 代码
public class Generic02 {
    public static void main(String[] args) {
        C<A> C = new C<A>(new A());
        C<A> C2 = new C<A>(new B());
        A a = C.c;
    }
}
class A{}
class B extends A{}
class C<E>{
    E c ;
    E[] e;
    public C(E c) {
        this.c = c;
    }
}
// 反编译代码  IDEA 选中代码 -> View -> Show Bytecode 或者 cmd 输入 javap -c XXX.class
// 我删除了一些不必要的代码
public class com/Al_tair/generic_/Generic02 {
  // 省略始化Generic02类
  public static main([Ljava/lang/String;)V
   L0  //   C<A> C = new C<A>(new A());
    LINENUMBER 9 L0
    NEW com/Al_tair/generic_/C 
    DUP 
    NEW com/Al_tair/generic_/A 
    DUP 
    INVOKESPECIAL com/Al_tair/generic_/A.<init> ()V
    // Ljava/lang/Object; （L开头 内容是对象 ;结尾 ） 传入是Object对象
    // 原本默认传进去就是Object类的对象，使用的时候使用自动强转换成对应传入的类型（现象如下）
    INVOKESPECIAL com/Al_tair/generic_/C.<init> (Ljava/lang/Object;)V 
    ASTORE 1
   L1  //   C<A> C2 = new C<A>(new B());
    LINENUMBER 10 L1
    NEW com/Al_tair/generic_/C
    DUP
    NEW com/Al_tair/generic_/B
    DUP
    INVOKESPECIAL com/Al_tair/generic_/B.<init> ()V
    INVOKESPECIAL com/Al_tair/generic_/C.<init> (Ljava/lang/Object;)V
    ASTORE 2
   L2
    LINENUMBER 11 L2
    RETURN
    GETFIELD com/Al_tair/generic_/C.c : Ljava/lang/Object;
    // 此处有一个checkcast指令，checkcast 用于检查类型强制转换是否可以进行，也就是泛型在获取值的时候进行了强制类型转换。
    CHECKCAST com/Al_tair/generic_/A
   L3
    ......
}                            
```

**类型擦除的缺点**

1.使用类型擦除直接导致了对于原始的数据类型无法支持，比如int，long这种，因为java不支持Object类型和基本数据类型之间的强制类型转换，也就是说一旦类型擦除之后，就没法在进行类型转换了。也正是这样，现在的泛型都是不支持原始类型的，比如ArrayList<Integer>，而不能使用ArrayList<int>。

2.运行期间无法获得泛型类型信息。因为泛型都被擦除了，都被替换成了裸类型。这样就导致了下面的程序都会报错，比如无法使用泛型来创建对象，或者数组。



### 自定义泛型

#### 自定义泛型类

基本语法

```java
class 类名<泛型>{}
```

**注意细节**

- 泛型类的类型是在创建对象时确定的（因为创建对象时，需要指定确定的类型）所以在类加载就创建的成员无法使用泛型

    - 普通成员可以使用泛型（属性和方法）但是成员变量不能赋值
    - 静态方法中不能使用类的泛型

    - 使用泛型的数组不能直接初始化 [不能初始化的原因](https://blog.csdn.net/lexang1/article/details/49565617)

        ``` java
        //  E[] e = new E[3]; 报错
        ```

#### 自定义泛型接口

基本语法

```java
interface 接口名<泛型>{}
```

注意细节

- 静态成员中不能使用类的泛型
- 泛型接口的类型是在实现接口的时候确定的
- 没有指定类型，则默认为Object类型

#### 自定义方法

基本语法

```java
// 一般参数列表和泛型对应
修饰符<泛型>返回类型 方法名(参数列表){} 
// 以下非泛型方法,而是使用了泛型
public void XXX(E e){}
```

注意细节

- 泛型方法可以放在普通类或者泛型类中
-  方法在使用之前，类型必须确定



### 泛型的继承和同配符

- 泛型不具有继承性
- <?> : 支持任意类型
- <? extends A> ：支持A 类以及A类的子类，规定了泛型的上限
- <> super A>  ；支持A类以及A类的父类，规定了泛型的下限



## 线程

### 进程和线程的概念

进程概念：进程是指运行中的程序，是程序的一次执行过程或是正在运行的一个程序。动态过程：产生，存在，消亡的过程  

线程概念：线程由进程创建，是进程的一个实体，一个进程可以拥有多个线程

- 单线程：同一个时刻只允许一个线程
- 多线程：同一个时刻，可以执行多个线程

并发：同一个时刻，多个任务交替执行，单核cpu实现多任务

并行：同一个时刻，多个任务同时执行，多核cpu可以实现并行执行多任务

**为什么需要多线程？**

众所周知，CPU、内存、I/O 设备的速度是有极大差异的，为了合理利用 CPU 的高性能，平衡这三者的速度差异，计算机体系结构、操作系统、编译程序都做出了贡献，主要体现为:

- CPU 增加了缓存，以均衡与内存的速度差异；// 导致 `可见性`问题
- 操作系统增加了进程、线程，以分时复用 CPU，进而均衡 CPU 与 I/O 设备的速度差异；// 导致 `原子性`问题
- 编译程序优化指令执行次序，使得缓存能够得到更加合理地利用。// 导致 `有序性`问题

**那我们为什么要用多线程而不是多进程呢？** 

线程间的切换和调度成本远小于进程



### 线程的生命周期

```java
public enum State {
    // 创建进程，但是资源条件未满足
    NEW,
    // 运行进程
    RUNNABLE,
    // 阻塞进程
    BLOCKED,
    // 无时间限制等待notify()方法唤醒
    WAITING,
    // 有时间限制等待notify()方法唤醒
    TIMED_WAITING,
    // 结束进程
    TERMINATED;
}
```

 ![image-20220309092226604](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220309092226604.png)

**线程有哪几种状态? 分别说明从一种状态到另一种状态转变有哪些方式?**

五种状态：新建线程、线程可运行状态、线程阻塞状态、线程等待状态、线程死亡状态

![image-20220309205604317](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220309205604317.png)



### **创建线程的三种方式**

1. 继承Thread类，重写run方法（本质：Thread类也实现了Runable接口）

    ```java
    // 调用方法启动线程
    // MyThread mt = new MyThread();  
    // mt.start();
    public class MyThread extends Thread {
        @Override
        public void run() {
            // ...
        }
    }
    ```

    ![image-20220912113005898](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220912113005898.png) 

2. 实现 Runable 接口，重写run方法

    ```java
    // 使用Thread构造接受实现了Runnable的类，可以调用start()方法
    public Thread(Runnable target) {
        this(null, target, "Thread-" + nextThreadNum(), 0);
    }
    
    // 调用方法，将实现了 MyRunnable 接口的对象作为参数传入 Thread 的有参构造器中，再调用 start() 方法进行创建线程
    public class MyRunnable implements Runnable {
        @Override
        public void run() {
            // ...
        }
    }
    ```

3. 实现 Callable 接口，重写 run 方法（与实现 runable 接口的区在于是否返回结果值）

    ```java
    // 实现该接口
    public class MyCallable implements Callable<Integer> {
     	@Override
        public String call() {
            return "可以返回结果值";
        }
    }
    
    // 调用类 
    public static void main(String[] args) throws ExecutionException, InterruptedException {
        MyCallable mc = new MyCallable();
        // FutureTask 对实现该接口的对象进行了封装，可以通过调用 get() 方法来调用返回结果值
        FutureTask<Integer> ft = new FutureTask<>(mc);
        Thread thread = new Thread(ft);
        thread.start();
        System.out.println(ft.get()); // 可以返回结果值
    }
    ```

**实现接口  VS  继承 Thread**

- Java 不支持多重继承，因此继承了 Thread 类就无法继承其它类，但是可以实现多个接口
- 类可能只要求可执行就行，继承整个 Thread 类开销过大
- 继承 Thread 类操作更加简便



### 基本线程机制

#### Executor

Executor 管理多个异步任务的执行，而无需程序员显式地管理线程的生命周期。这里的异步是指多个任务的执行互不干扰，不需要进行同步操作。

主要有三种 Executor:

- CachedThreadPool: 一个任务创建一个线程
- FixedThreadPool: 所有任务只能使用固定大小的线程
- SingleThreadExecutor: 相当于大小为 1 的 FixedThreadPool

```java
public static void main(String[] args) {
    ExecutorService executorService = Executors.newCachedThreadPool();
    for (int i = 0; i < 5; i++) {
        executorService.execute(new MyRunnable());
    }
    executorService.shutdown();
}
```

#### 用户线程和守护线程

用户线程：又称工作线程，当执行的任务执行完或通知方式结束

守护线程：一般是为工作线程服务，当所有线程结束，守护线程自动结束（比如：垃圾回收机制）

```java
public class ThreadMethod {
    public static void main(String[] args) {
        MyDaemonThread md  = new MyDaemonThread();
        // 设置为守护线程
        md.setDaemon(true);
        md.start();
        for (int i = 0; i < 10; i++) {
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.getMessage();
            }
            System.out.println("用户线程在此");
        }
    }
}

class MyDaemonThread extends Thread{
    @Override
    public void run() {
        while(true){
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.getMessage();
            }
            System.out.println("守护线程在此");
        }
    }
}
```

#### yeild()

概念：线程的礼让，让出cpu让其他进程执行，但是礼让的时间不确定，也不一定礼让成功，还有就是当前处理器是否忙碌，如果处理器完成处理的过来，就不会进行礼让

使用场景：当你觉得这个线程不重要或者优先级很低，那适当让出cpu给那些更重要的线程是否是一个明智之举

```java
public void run() {
    Thread.yield();
}
```



### 源码解析多线程机制

**多线程机制说明**

  ![image-20220307111422720](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220307111422720.png) 

用例代码

```java
// 疑问：为什么调用start()方法而不是直接调用run()方法，不都是实现run()方法吗？
// 本质区别有没有创建新的线程，直接调用run方法就是和使用普通方法一样没什么区别，并没有创建线程
public class Thread01 extends Thread{
    int times = 0;
    public static void main(String[] args) throws InterruptedException {
        Thread01 thread01 = new Thread01();
        thread01.start();

        for (int i = 0; i < 60; i++) {
            System.out.println(Thread.currentThread().getName()+i);
            Thread.sleep(1000);
        }
    }

    @Override
    public void run() {
        while(true){
            try {
                Thread.sleep(1000);
            }catch (Exception e){
                System.out.println(e.getMessage());
            }
            System.out.println("喵喵，我是小猫咪"+ ++times );
            if(times == 80){
                break;
            }
        }
    }
}
```

使用Terminal  --  jconsole工具观察进程

注意要main方法和其他进程要持续较长时间。这样子才好观测

![image-20220307112032227](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220307112032227.png) 

**源码分析**

![image-20220307194551556](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220307194551556.png) 

```java
// 调用线程start方法：thread01.start();
// 源码分析
public synchronized void start() {
    if (threadStatus != 0)
        throw new IllegalThreadStateException();
    group.add(this);
    boolean started = false;
    try {
        start0();
        started = true;
    } finally {
        try {
        if (!started) {
            group.threadStartFailed(this);
        }
        } catch (Throwable ignore) {}
    }
}

// 本地方法，开辟线程
private native void start0();
```



### 进程中断

#### stop()方法(不推荐)

为什么stop()方法被废弃而不推荐使用呢？

因为stop()方法太过于暴力，强行把执行到一半的程序强行退出，会导致数据不一致的问腿

---

#### 自制设置标志位退出

```java
public class StopThread {
    public static void main(String[] args) throws InterruptedException {
        Thread1 thread1 = new Thread1();
        thread1.start();
        Thread.sleep(10000);
        thread1.setFlag(false);
    }
}

class Thread1 extends Thread{
    private int count = 0;
    // 设置标志位来判断线程终止时间
    private boolean flag = true;
    @Override
    public void run() {
        while (flag){
            try {
                Thread.sleep(50);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            System.out.println(++count);
        }
    }

    public void setFlag(boolean flag) {
        this.flag = flag;
    }
}
```

---

#### 中断方式退出程序

中断方式类似于之前通过标志位方式退出线程的方法，但是中断更加强劲一些，它可以让处于阻塞、限期等待或者无限期等待状态的线程引发异常退出 ，但是不能中断 I/O 阻塞和 synchronized 锁阻塞

```java
public class InterruptThread {
    public static void main(String[] args) throws InterruptedException {
        Interrupt thread1 = new Interrupt();
        thread1.start();
        Thread.sleep(10000);
        thread1.interrupt();
    }
}

class Interrupt extends Thread{
    private int count = 0;
    private boolean flag = true;
    @Override
    public void run() {
        while (true){
            if(this.isInterrupted()){
                System.out.println("Interrupted");
                break;
            }
            try {
                Thread.sleep(50);
            } catch (InterruptedException e) {
                e.printStackTrace();
                // 为什么这里还需要中断一次
                // 因为sleep()方法中断抛出的异常会清除中断标志位，因此还需要再中断一次
                this.interrupt();
            }
            System.out.println(++count);
        }
    }
}
```

---

#### Executor 的中断操作

调用 Executor 的 shutdown() 方法会等待线程都执行完毕之后再关闭，但是如果调用的是 shutdownNow() 方法，则相当于调用每个线程的 interrupt() 方法。

```java
public static void main(String[] args) {
    ExecutorService executorService = Executors.newCachedThreadPool();
    // 使用 Lambda 创建线程，相当于创建了一个匿名内部线程
    executorService.execute(() -> {
        try {
            Thread.sleep(2000);
            System.out.println("Thread run");
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    });
    executorService.shutdownNow();
    System.out.println("Main run");
}
  
// 异常打印信息
Main run
java.lang.InterruptedException: sleep interrupted
	// ...
```

如果只想中断 Executor 中的一个线程，可以通过使用 submit() 方法来提交一个线程，它会返回一个 Future<?> 对象，通过调用该对象的 cancel(true) 方法就可以中断线程

```java
Future<?> future = executorService.submit(() -> {
    // ..
});
future.cancel(true);
```



### 线程的常用方法

#### sleep()

Thread.sleep(millisec) 方法会休眠当前正在执行的线程，millisec 单位为毫秒。

sleep() 可能会抛出 InterruptedException，因为异常不能跨线程传播回 main() 中，因此必须在本地进行处理。线程中抛出的其它异常也同样需要在本地进行处理。

```java
public void run() {
    try {
        Thread.sleep(3000);
    } catch (InterruptedException e) {
        e.printStackTrace();
    }
}
```

---

#### wait()、notify()、notifyAll()

调用 wait() 使得线程等待某个条件满足，线程在等待时会被挂起，当其他线程的运行使得这个条件满足时，其它线程会调用 notify() 或者 notifyAll() 来唤醒挂起的线程；它们都属于 Object 的一部分，而不属于 Thread

```java
public final void wait() throws InterruptedException {
    wait(0L);
}
// 当多个线程在等待，则随机通知其中一个等待线程
public final native void notify();
// 通知所有等待线程
public final native void notifyAll();
```

**Object.wait()方法和Thread.sleep()方法的区别**

- wait()方法可以被唤醒，使用wait方法之后会释放目标对象的锁

- sleep()方法不会释放任何的资源  


---

#### await() signal() signalAll()

java.util.concurrent 类库中提供了 Condition 类来实现线程之间的协调，可以在 Condition 上调用 await() 方法使线程等待，其它线程调用 signal() 或 signalAll() 方法唤醒等待的线程。相比于 wait() 这种等待方式，await() 可以指定等待的条件，因此更加灵活

```java
public class AwaitSignalExample {
    private Lock lock = new ReentrantLock();
    // 使用 Lock 来获取一个 Condition 对象
    private Condition condition = lock.newCondition();

    public void before() {
        lock.lock();
        try {
            System.out.println("before");
            condition.signalAll();
        } finally {
            lock.unlock();
        }
    }

    public void after() {
        lock.lock();
        try {
            // 等待状态下会释放资源
            condition.await();
            System.out.println("after");
        } catch (InterruptedException e) {
            e.printStackTrace();
        } finally {
            lock.unlock();
        }
    }
}

// 调用者
public static void main(String[] args) {
    ExecutorService executorService = Executors.newCachedThreadPool();
    AwaitSignalExample example = new AwaitSignalExample();
    executorService.execute(() -> example.after());
    executorService.execute(() -> example.before());
}
```

---

#### join()

概念：线程的插队，如果插队的线程一旦插入成功，则肯定先执行完插入的线程的所有任务、

```java
// 无线等待，直到目标线程的任务执行完成
public final void join() throws InterruptedException
// 给出一个最大的等待时间
public final synchronized void join(long millis, int nanos) throws InterruptedException
```

**示例代码**

```java
public class Join {
    public static void main(String[] args) throws InterruptedException {
        Thread3 t = new Thread3();
        t.start();
        for (int i = 1; i <= 20; i++) {
            if(i == 5){
                System.out.println("让Thread3先完成");
                t.join();
                System.out.println("main继续执行");
            }
            System.out.println("main: " + i);
            Thread.sleep(1000);
        }
    }
}

class Thread3 extends Thread{
    private int count;
    @Override
    public void run() {
        while(true){
            if(count++ == 20){
                System.out.println("Thread3结束了");
                break;
            }
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            System.out.println("Thread3: "+count);
        }
    }
}
```

**join()方法的底层源码**

```java
// join方法的本质就是调用wait方法在当前对象实例进行等待
// 被等待的线程会在执行完成后调用notifyAll()方法唤醒等待的进程进程
public final synchronized void join(final long millis)
    throws InterruptedException {
    if (millis > 0) {
        if (isAlive()) {
            final long startTime = System.nanoTime();
            long delay = millis;
            do {
                wait(delay);
            } while (isAlive() && (delay = millis -
                   TimeUnit.NANOSECONDS.toMillis(System.nanoTime() - startTime)) > 0);
        }
    } else if (millis == 0) 
        // 测试此线程是否存在。如果线程已启动且尚未死亡，则该线程处于活动状态 RUNNABLE状态
        while (isAlive()) {
            wait(0);
        }
    } else {
        throw new IllegalArgumentException("timeout value is negative");
    }
}
```



### 线程同步机制

同步概念：当有多个线程同时在对内存进行操作，在某一个时刻只允许一个线程对该内存进行操作（比如：写操作）

#### synchronized

关键字synchronized的作用是实现线程的同步，它的工作是对同步代码加锁，使得每一次只能有一个线程进入同步块，从而保证了线程的安全

```java
// 指定锁对象  默认锁对象就是this
synchronized(对象){} // 需要得到对象的锁，才能操作同步代码
// 直接作用于实例方法  默认锁对象就是this
public synchronized void method(){}
// 直接作用于静态方法  默认锁对象就是当前类
public static synchronized void method(){}
```

```java
// 测试静态锁和对象锁锁住的范围
public class increase01 implements Runnable{
    static int count = 0;
    static int count2 = 0;

    public static synchronized void increase(){
        count++;
    }
    public synchronized void increase2(){
        count2++;
    }
    public static void main(String[] args) throws InterruptedException {
        // 如果同一类传入的对象不同，对象锁就无法启到作用了，必须使用类的锁才可以锁住
        Thread t1 = new Thread(new increase01());
        Thread t2 = new Thread(new increase01());
        t1.start();t2.start();
        t1.join(); t2.join();
        System.out.println(count); // 20000000
        System.out.println(count2); // 小于20000000
        
        System.out.println("-------");
        increase01.count2 = 0;
        increase01.count = 0;
        // 传入了相同对象，就不需要使用静态锁，对象锁就可以实现
        increase01 inc = new increase01();
        Thread thread = new Thread(inc);
        Thread thread1 = new Thread(inc);
        thread.start(); thread1.start();
        thread.join(); thread1.join();
        System.out.println(count);  // 20000000
        System.out.println(count2); // 20000000
    }

    @Override
    public void run() {
        for (int i = 0; i < 10000000; i++) {
            increase();
        }
    }
}
```

**练习一下**

1.在main方法中启动两个线程，在第一个线程循环随机打印100 以内的整数，直到第二个线程从键盘中读取了‘Q’命令就终止了第一个线程

```java
public class Homework01 {
    public static void main(String[] args) throws InterruptedException {
        RandomNum randomNum = new RandomNum();
        Thread thread = new Thread(randomNum);
        Thread thread2 = new Thread(new Input(randomNum));
        thread.start();
        thread2.start();
    }
}

// 线程1
class RandomNum implements Runnable{
    private boolean loop = true;

    public void setLoop(boolean loop) {
        this.loop = loop;
    }

    @Override
    public void run() {
        while(loop){
            System.out.println((int)(Math.random()*100));
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.getMessage();
            }
        }
        System.out.println("RandomNum退出程序");
    }
}

// 线程2
class Input implements Runnable{

    private  RandomNum r;

    public Input(RandomNum r) {
        this.r = r;
    }

    @Override
    public void run() {
        Scanner sc = new Scanner(System.in);
        while(true){
            char c = sc.nextLine().charAt(0);
            if(c == 'Q'){
                r.setLoop(false);
            }
            System.out.println(c);
        }
    }
}
```

2.有两个用户分别从同一个卡上取钱（总金额10000）.每次只能取1000元，当金额不足够时，就不能取款了，不能出现超额取款

```java
public class Homework02 {
    public static void main(String[] args) {
        // 同一个对象 指代的是从同一个卡上取款
        withdrawals withdrawals = new withdrawals();
        // 不用线程指代的是不用用户取款
        Thread user1 = new Thread(withdrawals);
        Thread user2 = new Thread(withdrawals);
        user1.start();
        user2.start();
    }
}

class withdrawals implements Runnable{
    static int moneySum = 10000;
    @Override
    public void run() {
        while(true){
            synchronized(this){
                if(moneySum>= 1000){
                    moneySum -= 1000;
                    System.out.println(Thread.currentThread().getName() +": 取款1000元 ");
                    System.out.println("余额剩余: "+moneySum);
                }else{
                    System.out.println("余额不足...");
                    break;
                }
                try {
                    Thread.sleep(1000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }
}
```

#### ReentrantLock

ReentrantLock 是 java.util.concurrent(J.U.C)包中的锁

```java
public class LockExample {
    private Lock lock = new ReentrantLock();
    public void func() {
        // 上锁
        lock.lock();
        try {
            for (int i = 0; i < 10; i++) {
                System.out.print(i + " ");
            }
        } finally {
            // 确保释放锁，从而避免发生死锁
            lock.unlock(); 
        }
    }
}

// 调用 func() 方法
public static void main(String[] args) {
    LockExample lockExample = new LockExample();
    ExecutorService executorService = Executors.newCachedThreadPool();
    executorService.execute(() -> lockExample.func());
    executorService.execute(() -> lockExample.func());
}
```

#### 两者之间的区别

**1. 锁的实现** ：synchronized 是 JVM 实现的，而 ReentrantLock 是 JDK 实现的

**2. 性能**：新版本 Java 对 synchronized 进行了很多优化，例如自旋锁等，synchronized 与 ReentrantLock 大致相同

**3. 等待可中断**

当持有锁的线程长期不释放锁的时候，正在等待的线程可以选择放弃等待，改为处理其他事情

ReentrantLock 可中断，而 synchronized 不行

**4. 公平锁**

公平锁是指多个线程在等待同一个锁时，必须按照申请锁的时间顺序来依次获得锁

synchronized 中的锁是非公平的，ReentrantLock 默认情况下也是非公平的，但是也可以是公平的

**5. 锁绑定多个条件**：一个 ReentrantLock 可以同时绑定多个 Condition 对象。

**使用选择**

除非需要使用 ReentrantLock 的高级功能，否则优先使用 synchronized。这是因为 synchronized 是 JVM 实现的一种锁机制，JVM 原生地支持它，而 ReentrantLock 不是所有的 JDK 版本都支持。并且使用 synchronized 不用担心没有释放锁而导致死锁问题，因为 JVM 会确保锁的释放



### 释放锁

四种情况释放锁

- 当前线程的同步方法和同步代码块执行结束
- 当前的线程在同步代码块和同步方法中遇到break，return
- 当前线程在同步代码块中出现了未处理的Error或者Exception导致被迫退出
- 当前的线程在同步代码块或者同步方法中执行了wait房啊，暂停当前的线程同时释放资源

二种情况不释放锁

- 线程执行同步代码块或者同步方法时，程序调用Thread.sleep()和Thread.yield()方法不会释放锁
- 线程执行同步代码块或者同步方法时，其他线程调用suspend方法将它挂起，此时它并不会释放该锁（不推荐使用挂起方法）



## JUC 

### 原子

### 锁



### 集合

#### CopyOnWriteArrayList

##### 引出

**ArrayList 集合是线程安全的吗？**

```java
// 报错：java.util.ConcurrentModificationException 并发修改异常
public static void main(String[] args) {
	// 创建 ArrayList 列表
    List<Integer> list = new ArrayList<>();
	
    // 启动十个线程
    for (int i = 0; i < 10; i++) {
        new Thread(()->{
            list.add((int)(Math.random()*5+5));
            System.out.println(list);
        },String.valueOf(i)).start();
    }
}
```

**有什么解决方案吗？**

1. 使用 Vector 集合，因为使用 synchronized 锁关键字，解决并发问题，但是效率低

2. Collections.synchronizedList 对 ArrayList 进行加锁

    ```java
    // 使用工具类 
    List<Integer> list = Collections.synchronizedList(new ArrayList<>());
    ```

3. 上述本质都是使用了 synchronized 锁来进行控制并发，推荐使用 **CopyOnWriteArrayList** 来解决并发问题

    ```java
    import java.util.concurrent.CopyOnWriteArrayList;
    // 创建 CopyOnWriteArrayList 类
    CopyOnWriteArrayList<Object> objects = new CopyOnWriteArrayList<>();
    ```

---

##### 概述

写入时复制集合

```java
// 实现了RandomAccess接口，可以随机访问；实现了Cloneable接口，可以复制；实现了Serializable接口，可串行化
public class CopyOnWriteArrayList<E>
    implements List<E>, RandomAccess, Cloneable, java.io.Serializable {
     // 版本序列号
    private static final long serialVersionUID = 8673264195747942595L;
    // 可重入锁
    final transient ReentrantLock lock = new ReentrantLock();
    // 对象数组，用于存放元素
    private transient volatile Object[] array;
    // 反射机制
    private static final sun.misc.Unsafe UNSAFE;
    // lock域的内存偏移量
    private static final long lockOffset;
    static {
        try {
            UNSAFE = sun.misc.Unsafe.getUnsafe();
            Class<?> k = CopyOnWriteArrayList.class;
            lockOffset = UNSAFE.objectFieldOffset
                (k.getDeclaredField("lock"));
        } catch (Exception e) {
            throw new Error(e);
        }
    }
}
```

通过 Lock 来解决并发问题

```java
// 使用 add() 方法举例说明
public boolean add(E e) {
    final ReentrantLock lock = this.lock;
    lock.lock();
    try {
        Object[] elements = getArray();
        int len = elements.length;
        // 复制数据
        Object[] newElements = Arrays.copyOf(elements, len + 1);
        newElements[len] = e;
        setArray(newElements);
        return true;
    } finally {
        lock.unlock();
    }
}
```











### 线程池

### 工具类



## IO 流

### 概述

IO 流的分类(流的本质就是运输者：**运输数据**)

- 按数据类型不同分为：字节流（8bit）、字符流（按字符）

    （字节流用来处理二进制文件(图片、MP3、视频文件)，字符流用来处理文本文件(可以看做是特殊的二进制文件，使用了某种编码，人可以阅读)）

    ![img](https://use-typora.oss-cn-hangzhou.aliyuncs.com/java-io-1.png) 

- 按数据流的流向不同分为：输入流、输出流

    输入就是将数据从各种输入设备（包括文件、键盘等）中读取到内存中，输出则正好相反，是将数据写入到各种输出设备（比如文件、显示器、磁盘等）

    ![image-20220911143551587](C:/Users/Ushop/AppData/Roaming/Typora/typora-user-images/image-20220911143551587.png) 

- 按数据流的功能不同分为：节点流/低级流、处理流/包装流/高级流

    - 节点流是底层流，直接跟数据源相接
    - 处理流包装节点流，既可以消除不同节点流的实现差异，也可以提供更方便的方法来完成输入输出
    - 处理流采用了修饰器设计模式，不会直接与数据源相连

### 框架图

**字节流和字符流的框架图**

![image-20220911154455112](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220911154455112.png)

根据命名很容易理解各个流的作用：

- 以File开头的文件流用于访问文件
- 以ByteArray/CharArray开头的流用于访问内存中的数组
- 以Piped开头的管道流用于访问管道，实现进程之间的通信
- 以String开头的流用于访问内存中的字符串
- 以Buffered开头的缓冲流，用于在读写数据时对数据进行缓存，以减少IO次数
- InputStreamReader、InputStreamWriter是转换流，用于将字节流转换为字符流
- 以Object开头的流是对象流，用于实现对象的序列化
- 以Print开头的流是打印流，用于简化打印操作
- 以Pushback开头的流是推回输入流，用于将已读入的数据推回到缓冲区，从而实现再次读取
- 以Data开头的流是特殊流，用于读写Java基本类型的数据

**节点流和处理流的框架图**

![image-20220317092617813](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220317092617813.png)



### 字节流

概述：以字节的方式进行传输数据，抽象基类包括 InputStream 、OutputStream

作用：可以用于传输图片、文件等二进制数据（因为数据的本质就是二进制，其实就是可以传输任何数据）

#### FileInputStream（读取文件数据）

##### 文件概述

概述：文件就是保存数据的地方（文件在程序中是以流的方式来操作的）

**常见文件的操作**

```java
// 构造器
File(File parent, String child)  // 从父抽象路径名和子路径名字符串创建新的File实例
// 代码实现
File parentFile = new File("C:\\Users\\Ushop\\Desktop\\JavaLoad");
String fileName = "w.txt";
File file = new File(parentFile, fileName);
file.createNewFile();
    
File(String pathname)  // 通过将给定的路径名字符串转换为抽象路径名来创建新的File实例
// 代码实现
String filePath = "C:\\Users\\Ushop\\Desktop\\JavaLoad\\w.txt";
File file = new File(filePath);
file.createNewFile();    
```

**常见文件信息**

```java
public static void main(String[] args) throws IOException {
    // 目录可以理解为文件夹
    String filePath = "C:\\Users\\Ushop\\Desktop\\JavaLoad\\w.txt";
    File file = new File(filePath);
    System.out.println("文件名: "+file.getName()); // 文件名: w.txt
    System.out.println("绝对路劲: "+file.getAbsolutePath()); // 绝对路劲: C:\Users\Ushop\Desktop\JavaLoad\w.txt
    System.out.println("父级路径: "+file.getParent()); // 父级路径: C:\Users\Ushop\Desktop\JavaLoad
    System.out.println("文件大小: "+file.length()); // 0
    System.out.println("文件是否存在: "+file.exists()); // false
    file.createNewFile(); // 创建文件
    System.out.println("文件是否存在: "+file.exists()); // true
}
```

**文件夹的使用**

```java
// 注意文件和文件夹的细微区别
// 文件夹就是用来存放文件以及文件夹的，但是文件是真正用来存储数据的（可以把文件夹理解成是引用对象名称，文件就是真正堆中的数据）
public static void main(String[] args) throws IOException {
    String filePath = "C:\\Users\\Ushop\\Desktop\\JavaLoad\\test";
    File file = new File(filePath);
    file.createNewFile(); // 创建文件
    file.mkdir(); // 创建单极目录文件夹
    file.mkdirs(); // 创建多级目录的文件夹
    // 删除文件或者文件夹
    if(file.exists()){
        if(file.delete()){
            System.out.println("删除成功");
        }else{
            System.out.println("删除失败");
        }
    }else{
        System.out.println("该文件不存在");
    }
}
```

##### 文件读取方法

```java
// 创建文件输入流
FileInputStream(File file)         // 构造函数1：创建“File对象”对应的“文件输入流”
FileInputStream(FileDescriptor fd) // 构造函数2：创建“文件描述符”对应的“文件输入流”
FileInputStream(String path)       // 构造函数3：创建“文件(路径为path)”对应的“文件输入流”
    
// 常用读取的方法
read() // 从该输入流读取一个字节的数据，返回的是读取到的数据
read(byte[] b) // 从该输入流读取最多b.length个字节的数据为字节数组，返回的是读取到字节数组的长度
read(byte[] b,int off,int len)  // 从该输入流读取最多1en字节的数据为字节数组
```

##### 文件读取实操

```java
// 文件输入流输入以字节的方式
// 当前存在问题：1.读取效率低 2.无法解决中文乱码的问题
String filePath = "C:\\Users\\Ushop\\Desktop\\JavaLoad\\test\\hello.txt";
FileInputStream fis = new FileInputStream(filePath);
int data = 0;
while((data = fis.read()) != -1){
    System.out.print((char)data);
}
fis.close();

// 优化后: 读取速度加快
String filePath = "C:\\Users\\Ushop\\Desktop\\JavaLoad\\test\\hello.txt";
FileInputStream fis = new FileInputStream(filePath);
int readLen = 0;
// 字节数组 一次读取8字节
byte[] bytes = new byte[8];
// 读入缓冲区的总字节数，如果没有更多数据，则返回-1
while((readLen = fis.read(bytes)) != -1){
    System.out.print(new String(bytes,0,readLen));
}
fis.close();

// 读操作是本地方法
private native int readBytes(byte b[], int off, int len) throws IOException;
```



#### FileOutputStream（写入文件数据）

##### 文件写入方法

![image-20220911151914115](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220911151914115.png)

```java
write(byte[]b) // 将b.length个字节从指定的字节数组写入此文件输出流
write(byte[]b,int off,int len) // 将len字节从位于偏移量off的指定字节数组写入此文件输出流
write(int b) // 将指定的字节写入此文件输出流
```

##### 文件读取实操

```java
String fileName = "C:\\Users\\Ushop\\Desktop\\JavaLoad\\test\\hello.txt";
// 得到文件输出流对象
FileOutputStream fos = new FileOutputStream(fileName);
// 如果找到文件则进行写操作，否则将创建该文件
fos.write('a');
fos.close();

// 性能优化 写字符串(本质就是字节数组的形式)
String fileName = "C:\\Users\\Ushop\\Desktop\\JavaLoad\\test\\hello.txt";
// 得到文件输出流对象
FileOutputStream fos = new FileOutputStream(fileName);
// 如果找到文件则进行写操作，否则将创建该文件
String fileContent = "我又回来了大家!!";
fos.write(fileContent.getBytes());
fos.close();
```

##### 文件读取写入实操

**txt文件读写**

```java
// 从hello.txt读出内容
String fileName = "C:\\Users\\Ushop\\Desktop\\JavaLoad\\test\\hello.txt";
FileInputStream fis = new FileInputStream(fileName);
int len = 0;
byte[] reader = new byte[1024];
String copyContent = "";
while((len = fis.read(reader)) != -1){
    copyContent += new  String(reader,0,len);
}
// 将读出的内容写入到copyFile.txt
String outFileName = "C:\\Users\\Ushop\\Desktop\\JavaLoad\\test\\copyFile.txt";
FileOutputStream fos = new FileOutputStream(outFileName);
fos.write(copyContent.getBytes());
fis.close();
fos.close();

// 优化代码：边读边写，防止一次性读入过大文件导致内存溢出
String fileName = "C:\\Users\\Ushop\\Desktop\\JavaLoad\\test\\hello.txt";
String outFileName = "C:\\Users\\Ushop\\Desktop\\JavaLoad\\test\\copyFile.txt";
FileInputStream fis = new FileInputStream(fileName);
FileOutputStream fos = new FileOutputStream(outFileName);
int len = 0;
byte[] reader = new byte[9];
while((len = fis.read(reader)) != -1){
    fos.write(new  String(reader,0,len).getBytes());
}
fis.close();
fos.close();
```

**图片文件读写**

```java
// 本质和上面的文件传输没有什么区别
String filePath = "C:\\Users\\Ushop\\Desktop\\JavaLoad\\test\\1.png";
String outFilePath= "C:\\Users\\Ushop\\Desktop\\JavaLoad\\test\\2.png";
FileInputStream fis = new FileInputStream(filePath);
FileOutputStream fos = new FileOutputStream(outFilePath);
int len = 0;
byte[] data = new byte[1024];
while((len = fis.read(data)) != -1){
    fos.write(data,0,len);
}
// 关闭资源（实战中最好放在 finally 中确保资源的关闭）
fis.close();
fos.close();
```

---



#### Buffered+（缓冲流）

缓冲流就是处理流中的一种，讲到处理流，我们需要介绍一下装饰者模式

![image-20220911160440108](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220911160440108.png) 

##### 缓冲输入输出流实操

```java
// 图片的拷贝
FileInputStream fis = new FileInputStream("C:\\Users\\Ushop\\Desktop\\JavaLoad\\test\\3.png");
FileOutputStream fos = new FileOutputStream("C:\\Users\\Ushop\\Desktop\\JavaLoad\\test\\4.png");
BufferedInputStream bis = new BufferedInputStream(fis);
BufferedOutputStream bos = new BufferedOutputStream(fos);
byte[] b = new byte[1024];
int len = 0;
while((len = bis.read(b)) != -1){
    bos.write(b,0,len);
}
bis.close();
bos.close();

// 拷贝视频
FileInputStream fis = new FileInputStream("C:\\Users\\Ushop\\Desktop\\JavaLoad\\test\\1.avi");
FileOutputStream fos = new FileOutputStream("C:\\Users\\Ushop\\Desktop\\JavaLoad\\test\\2.avi");
BufferedInputStream bis = new BufferedInputStream(fis);
BufferedOutputStream bos = new BufferedOutputStream(fos); 
byte[] b = new byte[1024];
int len = 0;
while((len = bis.read(b)) != -1){
    bos.write(b,0,len);
}
bis.close();
bos.close();
```

---



##### ObjectInputStream（反序列化）

反序列化：在恢复数据时，恢复数据的值和数据类型

```java
class ObjectInputStream_ {
    public static void main(String[] args) throws IOException, ClassNotFoundException {
        // 传入文件不管后缀是什么，都会以特点的文件格式存储
        String filePath = "C:\\Users\\Ushop\\Desktop\\JavaLoad\\test\\hello.txt";
        ObjectInputStream ois = new ObjectInputStream(new FileInputStream(filePath));
        // 反序列化的顺序和原文件数据顺序需要一致
        System.out.println( ois.readByte());
        System.out.println( ois.readUTF());
        System.out.println( ois.readFloat());
        // 需要能访问到自己的类，访问不到将会出现异常 ClassNotFoundException
        System.out.println(ois.readObject().toString());
        ois.close();
    }
}

// 需要实现 Serializable 接口才能实现序列化
class car implements Serializable {
    String name;
    int age;
    public car(String name, int age) {
        this.name = name;
        this.age = age;
    }
    @Override
    public String toString() {
        return "name: "+ name + " age: " + age;
    }
}
```

![image-20220316161318072](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220316161318072.png)



#### ObjectOutputStream（序列化）

序列化：保存时，保存数据的值和数据类型

```java
// 代码实现
public class ObjectOutputStream_ {
    public static void main(String[] args) throws IOException {
        // 传入文件不管后缀是什么，都会以特点的文件格式存储
        String filePath = "C:\\Users\\Ushop\\Desktop\\JavaLoad\\test\\hello";
        ObjectOutputStream obs = new ObjectOutputStream(new FileOutputStream(filePath));

        obs.writeByte(100);
        obs.writeChars("100");;
        obs.writeFloat(100.0f);
        obs.writeObject(new car("小黄",18));
        obs.close();
    }
}

// 需要实现 Serializable 接口才能实现序列化
class car implements Serializable {
    String name;
    int age;
    public car(String name, int age) {
        this.name = name;
        this.age = age;
    }
    @Override
    public String toString() {
        return super.toString();
    }
}
```

![image-20220316154453432](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220316154453432.png)

**注意事项**

- 序列化数据读写顺序需要一致
- 序列化的类中添加SerialVersionUID,为了提高版本的兼容性
- 序列化对象时，默认将对象里面所有属性进行序列化，但除了static或transient修饰的成员
- 序列化对象时，要求对象里面的属性（比如其他对象）必须也要序列化，数据才会被保存
- 序列化具备可继承性，当父类实现了串行化接口，该父类的所有子类默认实现了序列化

---



#### 常见其他字节流

|    方法    |    类型     | 默认设备 |
| :--------: | :---------: | :------: |
| System.in  | InputStream |   键盘   |
| System.out |  OutStream  |  显示器  |

######  printstream : 打印流

默认输出到显示屏，可以通过setOut方法修改显示地址

![image-20220317082339399](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220317082339399.png) 





### 字符流

#### 转换流

编码就是把字符转换为字节，而解码是把字节重新组合成字符；如果编码和解码过程使用不同的编码方式那么就出现了乱码

- GBK 编码中，中文字符占 2 个字节，英文字符占 1 个字节
- UTF-8 编码中，中文字符占 3 个字节，英文字符占 1 个字节
- UTF-16be 编码中，中文字符和英文字符都占 2 个字节

Java 使用双字节编码 UTF-16be，这不是指 Java 只支持这一种编码方式，而是说 char 这种类型使用 UTF-16be 进行编码。char 类型占 16 位，也就是两个字节，Java 使用这种双字节编码是为了让一个中文或者一个英文都能使用一个 char 来存储

以下用InputStreamReader举例

文件保存编码

![image-20220316204213177](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220316204213177.png) 

```java
// 代码示例
public static void main(String[] args) throws IOException {
    // 解决乱码问题
    String filePath = "C:\\Users\\Ushop\\Desktop\\JavaLoad\\test\\copyFile.txt";
    // 设置转码的编码
    InputStreamReader isr = new InputStreamReader(new FileInputStream(filePath),"gbk");
    char[] c = new char[1024];
    int len = 0;
    while ((len = isr.read(c)) != -1) {
        System.out.println(new String(c,0,len));
    }
}
```

![image-20220911164657622](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220911164657622.png)

---



#### FileReader（字符输入流）

**构造器**

![image-20220314160733620](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220314160733620.png) 

```java
// 读操作
String fileName = "C:\\Users\\Ushop\\Desktop\\JavaLoad\\test\\hello.txt";
FileReader fileReader = new FileReader(fileName);
char c = ' ';
// 寻换读取 使用read
while((c = (char)fileReader.read()) != (char)-1 ){
    System.out.print(c);
}

// 优化读取的一次性的量 字符 => 字符数组
String fileName = "C:\\Users\\Ushop\\Desktop\\JavaLoad\\test\\hello.txt";
FileReader fileReader = new FileReader(fileName);
char[] c = new char[1024];
int len = 0;
// 寻换读取 使用read
while((len = (char)fileReader.read(c)) != (char)-1 ){
    System.out.print(new String(c,0,len));
}

// 注意String 和char数组的转换
new String(char[]);
new String(char[],off,len) // 将索引从off开始len个字符的转换成字符串
```



#### FileWriter（字符输出流）

**构造器**

![image-20220314164040574](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220314164040574.png) 

注意：FileWriter使用，必须要关闭（close）或者 刷新（flush）,否则写入不到指定的文件！

```java
// 写操作 ： 输出字符串到文件
String writerFileName = "C:\\Users\\Ushop\\Desktop\\JavaLoad\\test\\copyFile.txt";
String content = "嘿嘿，打我呀!!";
FileWriter fileWriter = new FileWriter(writerFileName);
fileWriter.write(content);
fileWriter.flush();
fileWriter.close();

// 字符输出流为什么要关闭或者刷新才可以真正的写入文件中
// 源码解读：都调用writeBytes()方法来真正的输出
private void writeBytes() throws IOException {
    bb.flip();
    int lim = bb.limit();
    int pos = bb.position();
    assert (pos <= lim);
    int rem = (pos <= lim ? lim - pos : 0);

    if (rem > 0) {
        if (ch != null) {
            if (ch.write(bb) != rem)
                assert false : rem;
        } else {
            // 本质上还是用了字节输出
            out.write(bb.array(), bb.arrayOffset() + pos, rem);
        }
    }
    bb.clear();
}
```

---



#### BufferedReader（缓冲字符输入流）

```java
// 优化后的fileReader => 处理流
FileReader fileReader = new FileReader("C:\\Users\\Ushop\\Desktop\\JavaLoad\\test\\hello.txt");
BufferedReader br = new BufferedReader(fileReader);
String content = "";
while((content = br.readLine()) != null){
    System.out.print(content);
}
// 注意：关闭流只需要关闭外层流(处理流)就可以了 
br.close();
} 

// 源码解读
public void close() throws IOException {
    synchronized (lock) {
        if (in == null)
            return;
        try {
            in.close(); // in就是节点流FileReader,在底层关闭了
        } finally {
            in = null;
            cb = null;
        }
    }
}
```

#### BufferedWriter（缓冲字符输出流）

```java
String fileName = "C:\\Users\\Ushop\\Desktop\\JavaLoad\\test\\hello.txt";
//  new FileWriter(fileName,true) 后面为true是追加数据，默认false不追加
FileWriter fileWriter = new FileWriter(fileName);
BufferedWriter writer = new BufferedWriter(fileWriter);
// 当前写入都是覆盖而不是追加
writer.write("大家好呀，我是小笙!"); 
writer.newLine(); // 换行符，与操作系统相关的换行操作
writer.write("换行符的使用");
writer.close();
```



## NIO









## 网络编程

### 网络基础知识

#### 概念

- 概念：两台或者多台设备之间通过网络实现数据传输
- Java.net包下提供了一系列的类和接口用来实现网络通信
- 网络的覆盖范围
    - 局域网：一个机房或者教室
    -   城域网：一个城市
    - 广域网：全国甚至全球范围

#### IP地址

- 概念：用来标识每一台电脑主机 <=> 地址
- 查看ip地址：ipconfig
- 组成：网络地址+主机地址    如 192.168.16.22

![](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20211113142138057.png) 

IPv6的地址长度为128位，16个字节是IPv4的四倍

![image-20211113143303713](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20211113143303713.png)

![image-20211113145529149](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20211113145529149.png)

#### 域名

概念：将ip地址映射成域名

目的：解决记忆ip地址困难的问题

www.baidu.com  <=>  180.101.49.11

![image-20211113150218328](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20211113150218328.png) 

#### 端口号

概念：用于标识特定的网络服务程序（注意是网络服务需要端口，普通程序并不一定需要占用端口）

范围：以整数形式 0~65535（2个字节） （**注意0~1024通常被占用**）

![image-20211113152710508](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20211113152710508.png) 

![image-20211113151846001](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20211113151846001.png) 

#### 网络通讯协议

数据，在网络编程中，数据的组织形式就是协议（需要按照规定好的协议方式）

![image-20211113154345000](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20211113154345000.png) 

![image-20220317184548885](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220317184548885.png) 



### 	TCP 和 UDP

![image-20211113170033305](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20211113170033305.png) 



### InetAddress

**实现功能**

![image-20211113173703985](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20211113173703985.png) 

**方法：**(**InetAddress**对象： 主机名/IP地址)

- 获取本机的**InetAddress**对象 ---  **localHost**
- 根据指定主机名获取**InetAddress**对象 --- **InetAddress.getByName("主机名")**
- 根据域名返回**InetAddress**对象 --- **InetAddress.getByName("域名")**
- 通过**InetAddress**对象，获取对应的IP地址 ---  **InetAddress对象.getHostAddress()**
- 通过**InetAddress**对象 获取对应的主机名或者域名 ---  **InetAddress对象.getByName("主机名")**

**操作代码示例**

**需要捕获异常，可能会出现异常**

比如找不到local host 或者不允许找

![image-20211113182725146](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20211113182725146.png) 

```java
// 需要捕获异常，可能会出现异常
try {
    // 1.获取本机的InetAddress对象  --- LAPTOP-EINLAL7G/192.168.56.1
    InetAddress InetObject1 = InetAddress.getLocalHost();
    System.out.println("InetObject1: "+ InetObject1);

    // 2.根据指定主机名获取InetAddress对象  --- LAPTOP-EINLAL7G/192.168.56.1
    InetAddress InetObject2 = InetAddress.getByName("LAPTOP-EINLAL7G");
    System.out.println("InetObject2: "+ InetObject2);

    // 3.根据域名返回InetAddress对象  --- www.taobao.com/60.163.129.165
    InetAddress InetObject3 = InetAddress.getByName("www.taobao.com");
    System.out.println("InetObject3: "+ InetObject3);

    // 4.通过InetAddress对象，获取对应的IP地址  --- 180.101.49.11
    InetAddress InetObject = InetAddress.getByName("www.baidu.com");
    System.out.println(InetObject.getHostAddress());

    // 5.通过InetAddress对象 获取对应的主机名或者域名 --- www.jd.com/60.165.115.3
    InetObject = InetAddress.getByName("www.baidu.com");
    System.out.println(InetObject.getByName("www.jd.com"));

}catch(Exception e){}
```



### Socket 

编程方式：1.TCP编程 可靠  2.UDP编程 不可靠

#### TCP网络通信编程

客户端 <==> 服务端

![image-20211114133940621](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20211114133940621.png) 

![image-20211114134611442](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20211114134611442.png) 

##### 发送一次数据案例(字节流)

题目要求如下

1. 编写一个服务端和一个客户端
2. 服务端在9999端口监听
3. 客户端连接服务端并发送一串字符串（字节数组）  然后退出
4. 服务端接收到客户端发送的信息 输出并退出

![image-20211114140531301](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20211114140531301.png) 

**实现代码**

客户端

```java
public class ClientTCP {
    /**
     * 客户端
     * 思路：
     * 1.连接服务端（ip,端口）
  
     */
    public static void main(String[] args) throws IOException {
        //  1.连接服务端（ip,端口）
        Socket socket = new Socket(InetAddress.getLocalHost(),9999);

        // 2.连接上服务端，生成socket 并通过socket.getOutputStream()写入数据
        OutputStream outputStream = socket.getOutputStream();
        // 输入想要传输的字符串进行传输
        System.out.println("请你输入想要传输的字符串");
        String str = new Scanner(System.in).next();
        byte[] out = str.getBytes();
        outputStream.write(out) ;
        System.out.println("传输成功!!");

        // 3.最后要释放流 and socket
        outputStream.close();
        socket.close();
        System.out.println("客户端结束传输");
    }
}
```

服务端

```java
public class TCPServer {
    /**
     * 服务端
     * 思路：
     * 1.设置监听端口为9999
     * 2.监听客户端，是否有建立连接
     *   如果建立连接则通过socket.getInputStream()接受数据
     *   如果没有建立连接则一直等待直到建立连接
     * 3.最后要释放流 and socket serverSocket
     */
    public static void main(String[] args) throws IOException {
        // 1.设置监听端口为9999
        ServerSocket serverSocket = new ServerSocket(9999);

        // 2.监听客户端，是否有建立连接
        // 如果没有建立连接则一直等待直到建立连接
        System.out.println("开始接收数据....");
        Socket socket = serverSocket.accept();

        // 如果建立连接则通过socket.getInputStream()接受数据
        // 如果没有传入数据则等待数据的传入
        InputStream inputStream = socket.getInputStream();
        byte[] buf = new byte[1024];
        int readLength = 0;
        while((readLength = inputStream.read(buf)) != -1){
            System.out.println("接收到数据:"+new String(buf,0,readLength));
        }

        // 3.最后要释放流 and socket serverSocket
        inputStream.close();
        socket.close();
        serverSocket.close();
        System.out.println("服务端结束传输");
    }
}
```

实现结果

![image-20211114164525198](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20211114164525198.png) 

![image-20211114164612412](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20211114164612412.png) 



##### 数据往返传输案例   (字节流)

题目要求如下

1. 编写一个服务端和一个客户端
2. 服务端在9999端口监听
3. 客户端连接服务端并发送一串字符串（字节数组）并且接收到服务端传来的数据并且显示 然后退出
4. 服务端接受到客户端发送的信息并传送回一串字符串（字节数组） 然后退出

![image-20211114171311526](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20211114171311526.png) 

**注意点：socket传输完需要添加结束标记 如：socket.shutdownInput(); // 关闭输入流    socket.shutdownOutput();  // 关闭输出流**

客户端

```java
public class ClientTCP {
    /**
     * 客户端
     * 思路：
     * 1.连接服务端（ip,端口）
     * 2.连接上服务端，生成socket 并通过socket.getOutputStream()写入数据
     * 3.接收服务器传来的数据并显示
     * 4.最后要释放流 and socket
     */
    public static void main(String[] args) throws IOException {
        //  1.连接服务端（ip,端口）
        Socket socket = new Socket(InetAddress.getLocalHost(),9999);

        // 2.连接上服务端，生成socket 并通过socket.getOutputStream()写入数据
        OutputStream outputStream = socket.getOutputStream();
        // 输入想要传输的字符串进行传输
        System.out.println("请你输入想要传输的字符串");
        String str = new Scanner(System.in).next();
        byte[] out = str.getBytes();
        outputStream.write(out) ; 
        System.out.println("传输成功!!");
        socket.shutdownOutput();  // 关闭输出流

        // 3.接收服务器传来的数据并显示
        InputStream inputStream = socket.getInputStream();
        byte[] buf = new byte[1024];
        int readLength = 0;
        while((readLength = inputStream.read(buf)) != -1){
            System.out.println("接收到数据:"+new String(buf,0,readLength));
        }

        // 4.最后要释放流 and socket
        inputStream.close();
        outputStream.close();
        socket.close();
        System.out.println("客户端结束传输");
    }
}
```

服务端

```java
public class TCPServer {
    /**
     * 服务端
     * 思路：
     * 1.设置监听端口为9999
     * 2.监听客户端，是否有建立连接
     *   如果建立连接则通过socket.getInputStream()接受数据
     *   如果没有建立连接则一直等待直到建立连接
     * 3.接受到数据并且传送回一串字符串
     * 4.最后要释放 流 and socket and serverSocket
     */
    public static void main(String[] args) throws IOException {
        // 1.设置监听端口为9999
        ServerSocket serverSocket = new ServerSocket(9999);

        // 2.监听客户端，是否有建立连接
        // 如果没有建立连接则一直等待直到建立连接
        System.out.println("开始接收数据....");
        Socket socket = serverSocket.accept();

        // 如果建立连接则通过socket.getInputStream()接受数据
        // 如果没有传入数据则等待数据的传入
        InputStream inputStream = socket.getInputStream();
        byte[] buf = new byte[1024];
        int readLength = 0;
        while((readLength = inputStream.read(buf)) != -1){
            System.out.println("接收到数据:"+new String(buf,0,readLength));
        }
        socket.shutdownInput(); // 关闭输入流

        // 3.接受到数据并且传送回一串字符串
        System.out.println("想要输出撒？");
        OutputStream outputStream = socket.getOutputStream();
        String str = new Scanner(System.in).next();
        outputStream.write(str.getBytes());
        System.out.println("输出成功!!!");


        // 4.最后要释放流 and socket serverSocket
        outputStream.close();
        inputStream.close();
        socket.close();
        serverSocket.close();
        System.out.println("服务端结束传输");
    }
}
```

实现结果

![image-20211114175421041](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20211114175421041.png) 

![image-20211114175511636](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20211114175511636.png) 

##### 数据往返传输案例   (字符流)

题目要求如下

1. 编写一个服务端和一个客户端
2. 服务端在9999端口监听
3. 客户端连接服务端并发送一串字符串并且接收到服务端传来的数据并且显示 然后退出
4. 服务端接受到客户端发送的信息并传送回一串字符串 然后退出

![image-20211114214701218](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20211114214701218.png) 

演示核心代码

```java
// 客户端
String str = new Scanner(System.in).next();
//  转换流重点:An OutputStreamWriter is a bridge from character streams to byte streams
BufferedWriter bufferedWriter = new BufferedWriter(new OutputStreamWriter(outputStream));
bufferedWriter.write(str) ;
bufferedWriter.newLine(); // 换行符 表示写入的内容结束  注意对方必须是使用readline()
bufferedWriter.flush();  // 如果使用的是字符流,需要手动去刷新,否则数据将无法写入数据通道 
System.out.println("传输成功!!");

// 服务端
BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(inputStream));
System.out.println(bufferedReader.readLine());

// 注意关闭外层流
bufferedWriter.close();
bufferedReader.close();
```



##### 发送一张图片

题目要求如下

1. 编写一个服务端和一个客户端
2. 服务端在8899端口监听
3. 客户端连接到服务端，发送一张图片 地址：C:\Users\Ushop\Desktop\mess\Java\Al_tair.png
4. 服务端接受到客户端发送的图片，保存到src下，然后再发送“收到图片”再退出
5. 客户端接受到“收到图片”再退出

![image-20211116173938490](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20211116173938490.png) 

我遇到了一点小问题，暂时还不清楚原因：只能传输.jpg图片，不能传输.png图片

![image-20211118200241060](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20211118200241060.png) 

代码如下

**客户端**

```java
public class TCPFileuploadClient {
    /**
     * 客户端
     * 1. 编写一个服务端和一个客户端
     * 2. 服务端在8899端口监听
     * 3. 客户端连接到服务端，发送一张图片 地址：C:\Users\Ushop\Desktop\mess\Java\Al_tair.png
     * 4. 服务端接受到客户端发送的图片，保存到src下，然后再发送“收到图片”再退出
     * 5. 客户端接受到“收到图片”再退出
     */
    public static void main(String[] args) throws Exception {
        // 1. 连接到服务端8899端口
        Socket socket = new Socket(InetAddress.getLocalHost(), 9999);

        // 2.创建读取磁盘文件放入输入流
        String filePath = "C:\\Users\\Ushop\\Desktop\\JavaLoad\\JavaSe\\Image\\pandas.jpg";
        BufferedInputStream bis = new BufferedInputStream(new FileInputStream(filePath));

        // 3.通过socket获取到输入流，将byte数据发送到服务端
        byte[] bytes = StreamUtils.streamToByteArray(bis);
        BufferedOutputStream bos = new BufferedOutputStream(socket.getOutputStream());
        bos.write(bytes);
        socket.shutdownOutput(); // 结束输出流

        // 4.接受服务端发来的“收到图片”

        BufferedReader reader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        System.out.println(reader.readLine());

        // 5.关闭相关资源
        reader.close();
        bis.close(); 
        bos.close();
        socket.close();
    }
}
```

**服务端**

```java
public class TCPFileuploadServer {
    /**
     * 服务端
     * 1. 编写一个服务端和一个客户端
     * 2. 服务端在8899端口监听
     * 3. 客户端连接到服务端，发送一张图片 地址：C:\Users\Ushop\Desktop\mess\Java\Al_tair.png
     * 4. 服务端接受到客户端发送的图片，保存到src下，然后再发送“收到图片”再退出
     * 5. 客户端接受到“收到图片” 再退出
     */
    public static void main(String[] args) throws Exception {
        // 1.服务端在本地监听8899端口
        ServerSocket serverSocket = new ServerSocket(9999);

        // 2.服务端等待连接
        System.out.println("等待客户端发送数据.....");
        Socket socket = serverSocket.accept();

        // 3.读取客户端发送的数据 通过Socket得待输入流
        BufferedInputStream bis = new BufferedInputStream(socket.getInputStream());
        byte[] bytes = StreamUtils.streamToByteArray(bis);

        // 4.将得到的byte数组，写入到指定的路径，就得到一个文件了
        String descFilePath = "E:\\Java_training\\Java_code\\JavaIdea03\\java\\Javase_HSping\\src\\com\\Al_tair\\socket\\upload\\pandas.jpg";
        BufferedOutputStream bos = new BufferedOutputStream(new FileOutputStream(descFilePath));
        bos.write(bytes);


        // 5.向客户端发送“收到图片”
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(socket.getOutputStream()));
        writer.write("收到图片");
        writer.newLine();
        writer.flush();

        // 6.最后关闭其他资源
        bis.close();
        bos.close();
        writer.close();
        socket.close();
        serverSocket.close();

    }
}
```

工具类 ：将.转换成byte[]字节数组

```      JAVA
public class StreamUtils {
    /**
     * 功能：将输入流转换成byte[]字节数组
     */
    public static byte[] streamToByteArray(InputStream inputstream) throws Exception{
        ByteArrayOutputStream byteArrayOutputStream = new ByteArrayOutputStream(); // 创建输出流对象
        byte[] b = new byte[1024]; // 字节数组
        int len;
        while((len = inputstream.read(b))!= -1){
            byteArrayOutputStream.write(b,0,len);
        }
        byte[] array = byteArrayOutputStream.toByteArray(); // 将输出流转换成字节数组
        byteArrayOutputStream.close();
        return array;
    }
}
```

#### netstat 指令（补充）

1. netstat -an 可以查看当前主机网络情况，包括端口监听和网络连接情况

2. netstat -an | more 可以分页显示  ctrl+c退出该指令

    ![image-20211119114947310](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20211119114947310.png)  

3. dos控制行以管理员身份打开 netstat -anb 可以查看哪个应用软件监听该端口

4. 当客户端连接到服务端后实际上客户 TCP/IP随机分配的端口（验证：netstat观测） 

    ![image-20211119122203549](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20211119122203549.png)       

    

#### UDP网络通信编程[了解]

基本介绍

- 类DatagramSocket 和 DatagramPacke[数据包/数据报] 实现了基于UDP 协议网络程序
- UDP数据报套接字DatagramSocket 发送和接受数据，系统不保证UDP数据报一定能安全送达目的地也不能确定什么时候可以送到
- DatagramPacket 对象封装了UDP数据报，在数据报中包含了**发送端的IP 地址和端口号以及接收端的IP地址和端口号**
- UDP协议中每个数据报都给出了完整的地址信息. 因此无需建立连接

![image-20211119172349275](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20211119172349275.png) 

##### UDP网络通信编程案例

任务要求：

1. 编写一个接受端A和一个发送端B
2. 接受端A 在9999端口等待接收数据报
3. 发送端B向接收端A发送数据“hello~”
4. 接收端A接收到发送端B发送的数据回复“hello , Im fine”,再退出
5. 发送端B接收到回复的数据再退出

但是注意程序启动顺序还是有区别的，接收方要先启动程序！！！

```java
public class udpNodeB {
    /**
     * Node B
     * 1. 编写一个接受端A和一个发送端B
     * 2. 接受端A 在9999端口等待接收数据报
     * 3. 发送端A向接收端B发送数据“hello~”
     * 4. 接收端B接收到发送端A发送的数据回复“hello , Im fine”,再退出
     * 5. 发送端A接收到回复的数据再退出
     */
    public static void main(String[] args) throws IOException {
        // 1.创建一个DatagramSocket对象,准备在9998端口接收数据
        DatagramSocket socket = new DatagramSocket(9998);

        // 2.将需要发送的数据封装到 DatagramPacket对象 （UDP协议 数据包MAX 64K）
        System.out.println("开始聊天界面...");
        String str = new Scanner(System.in).next();
        byte[] data = str.getBytes();

        // 3.封装的 DatagramPacket对象组成: data 数据 | data.length 数据长度 | 主机(IP) | 端口(port)
        // send 方法发送数据
        DatagramPacket packet = new DatagramPacket(data, data.length, InetAddress.getByName("192.168.56.1"), 9999);
        socket.send(packet);
        System.out.println("数据发送成功!!");
        
        // 复制接受端A的j数据的方式
        byte[] buf = new byte[64*1024];
        packet = new DatagramPacket(buf,buf.length);
        socket.receive(packet);
        String s = new String(packet.getData(), 0, packet.getLength());
        System.out.println(s);

        // 5.释放资源
        socket.close();

    }
}
```

```java
public class udpNodeA {
    /**
     * Node A
     * 1. 编写一个接受端A和一个发送端B
     * 2. 接受端A 在9999端口等待接收数据报
     * 3. 发送端B向接收端A发送数据“hello~”
     * 4. 接收端A接收到发送端B发送的数据回复“hello , Im fine”,再退出
     * 5. 发送端B接收到回复的数据再退出
     */
    public static void main(String[] args) throws IOException {
        // 1.创建一个DatagramSocket对象,准备在9999端口接收数据
        DatagramSocket socket = new DatagramSocket(9999);

        // 2.创建一个 DatagramPacket对象,准备接收数据 （UDP协议 数据包MAX 64K）
        byte[] buf = new byte[64*1024];
        DatagramPacket packet = new DatagramPacket(buf,buf.length);

        // 3.调用接收方法,将通过网络传输的DatagramPacket对象填充到packet对象
        // receive方法会在9999端口一直等待直到接收到数据
        System.out.println("开始接受数据...");
        socket.receive(packet);

        // 4.可以把packet进行拆包,取出数据并显示
        String s = new String(packet.getData(), 0, packet.getLength());
        System.out.println(s);
        System.out.println("数据接收成功...");
        
        // 复制发送端B的发送数据的方式
        String str = new Scanner(System.in).next();
        byte[] data = str.getBytes();
        packet = new DatagramPacket(data, data.length, InetAddress.getByName("192.168.56.1"), 9998);
        socket.send(packet);

        // 5.释放资源
        socket.close();
    }
}
```



### 相关面试题

**1.讲一下TCP/IP协议**

1. TCP/IP协议定义

      **TCP/IP**（Transmission Control Protocol/Internet Protocol，传输控制协议/网际协议）是指能够在多个不同网络间实现信息传输的协议簇。TCP/IP协议不仅仅指的是TCP和IP两个协议，而是指一个由FTP、SMTP、TCP、UDP、IP等协议构成的协议簇， 只是因为在TCP/IP协议中TCP协议和IP协议最具代表性，所以被称为TCP/IP协议。

2. TCP/IP协议组成

    TCP/IP结构模型分为**应用层、传输层、网络层、链路层（网络接口层）**四层，以下是各层的详细介绍：

    **（1）应用层**

      应用层是TCP/IP协议的第一层，是直接为应用进程提供服务的。

      a. 对不同种类的应用程序它们会根据自己的需要来使用应用层的不同协议，邮件传输应用使用了SMTP协议、万维网应用使用了HTTP协议、远程登录服务应用使用了有TELNET协议。

      b. 应用层还能加密、解密、格式化数据。

      c. 应用层可以建立或解除与其他节点的联系，这样可以充分节省网络资源。

    **（2）传输层**

      作为TCP/IP协议的第二层，运输层在整个TCP/IP协议中起到了中流砥柱的作用。且在运输层中，TCP和UDP也同样起到了中流砥柱的作用。

    **（3）网络层**

      网络层在TCP/IP协议中的位于第三层。在TCP/IP协议中网络层可以进行网络连接的建立和终止以及IP地址的寻找等功能。

    **（4）链路层（网络接口层）**

      在TCP/IP协议中，网络接口层位于第四层。由于网络接口层兼并了物理层和数据链路层。所以，网络接口层既是传输数据的物理媒介，也可以为网络层提供一条准确无误的线路。

3. TCP/IP协议特点

      TCP/IP协议能够迅速发展起来并成为事实上的标准，是它恰好适应了世界范围内数据通信的需要。它有以下特点：

    （1）协议标准是完全开放的，可以供用户免费使用，并且独立于特定的计算机硬件与操作系统；

    （2）独立于网络硬件系统，可以运行在广域网，更适合于互联网；

    （3）网络地址统一分配，网络中每一设备和终端都具有一个唯一地址；

    （4）高层协议标准化，可以提供多种多样可靠网络服务。

    

    

    **2.介绍一下tcp的三次握手**

    1. 第一次握手：建立连接时，客户端发送syn包（syn=x）到服务器，并进入**SYN_SENT**状态，等待服务器确认；SYN：同步序列编号（Synchronize Sequence Numbers）。
    2. 第二次握手：服务器收到syn包，必须确认客户的SYN（ack=x+1），同时自己也发送一个SYN包（syn=y），即SYN+ACK包，此时服务器进入**SYN_RECV**状态；
    3. 第三次握手：客户端收到服务器的SYN+ACK包，向服务器发送确认包ACK(ack=y+1），此包发送完毕，客户端和服务器进入**ESTABLISHED**（TCP连接成功）状态，完成三次握手。

    ![image-20220319172024779](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220319172024779.png) 



**3.介绍一下TCP和UDP的区别**

TCP和UDP有如下区别：

1. 连接：TCP面向连接的传输层协议，即传输数据之前必须先建立好连接；UDP无连接。
2. 服务对象：TCP点对点的两点间服务，即一条TCP连接只能有两个端点；UDP支持一对一，一对多，多对一，多对多的交互通信。
3. 可靠性：TCP可靠交付：无差错，不丢失，不重复，按序到达；UDP尽最大努力交付，不保证可靠交付。
4. 拥塞控制/流量控制：有拥塞控制和流量控制保证数据传输的安全性；UDP没有拥塞控制，网络拥塞不会影响源主机的发送效率。
5. 报文长度：TCP动态报文长度，即TCP报文长度是根据接收方的窗口大小和当前网络拥塞情况决定的；UDP面向报文，不合并，不拆分，保留上面传下来报文的边界。
6. 首部开销：TCP首部开销大，首部20个字节；UDP首部开销小，8字节（源端口，目的端口，数据长度，校验和）。
7. 适用场景（由特性决定）：数据完整性需让位于通信实时性，则应该选用TCP 协议（如文件传输、重要状态的更新等）；反之，则使用 UDP 协议（如视频传输、实时通信等）。



## 反射

### 反射机制

#### 什么是反射？

反射就是Reflection，Java的反射是指程序在运行期间可以拿到一个对象的所有信息。这种动态获取的信息以及动态调用对象的方法的功能称为java语言的反射机制

反射就是把java类中的各种成分（成员变量，方法，构造器等等类的成员）映射成一个个的Java对象

#### 反射的优缺点

优点：可以动态的创建和使用对象，使用灵活（框架底层核心）

缺点：使用反射基本是解释执行，对执行的效率有很大的影响

### Class类

Class类的实例表示java应用运行时的类或接口（每个java类运行时都在JVM里表现为一个class对象，可通过类名.class、类型.getClass()、Class.forName("类名")等方法获取class对象

```java
// 总结
// 1.注意Class类和class关键字的区别
// 2.私有构造函数，只有 Java 虚拟机会创建 Class 对象
// 3.每个通过关键字class标识的类，在内存中有且只有一个与之对应的Class对象来描述其类型信息，无论创建多少个实例对象，其依据的都是用一个Class对象
public final class Class<T> implements java.io.Serializable,
                              GenericDeclaration,
                              Type,
                              AnnotatedElement,
                              TypeDescriptor.OfField<Class<?>>,
                              Constable {
    private static final int ANNOTATION= 0x00002000;
    private static final int ENUM      = 0x00004000;
    private static final int SYNTHETIC = 0x00001000;

    private static final ClassDesc[] EMPTY_CLASS_DESC_ARRAY = new ClassDesc[0];

    private static native void registerNatives();
    static {
        registerNatives();
    }

    /*
     * Private constructor. Only the Java Virtual Machine creates Class objects.
     * This constructor is not used and prevents the default constructor being
     * generated.
     * 私有构造函数，只有 Java 虚拟机会创建 Class 对象。不使用此构造函数并阻止生成默认构造函数。
     */
    private Class(ClassLoader loader, Class<?> arrayComponentType) {
        // Initialize final field for classLoader.  The initialization value of non-null
        // prevents future JIT optimizations from assuming this final field is null.
        classLoader = loader;
        componentType = arrayComponentType;
    }
```



### 类加载阶段

```java
// 代码示例
class Cat{
	private String name;
	public Cat(){}
	public void hi(){}
}
```

![image-20220320195240128](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220320195240128.png)

#### 类加载的生命周期

类加载的过程包括了`加载`、`验证`、`准备`、`解析`、`初始化`五个阶段

注意：`加载`、`验证`、`准备`、`初始化`四个阶段的开始顺序是依次如此，但是在运行中会交叉运行程序（如：相互调用）；解析阶段可能会出现在初始化之后（为了支持动态绑定）

![image-20220323143344970](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220323143344970.png) 

类的加载示例（[图片](https://pdai.tech/md/java/basic/java-basic-x-reflection.html)）

![image-20220323143659380](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220323143659380.png)



### 反射的使用

#### Class类的对象获取

- 根据类名：类名.class
- 根据对象：对象.getClass()
- 根据全限定类名：Class.forName(全限定类名)

```java
public class Reflection01 {
    public static void main(String[] args) throws ClassNotFoundException, IllegalAccessException, InstantiationException {
        // 测试用例
        // 1.forName()
        // (1)获取Class对象的一个引用，但引用的类还没有加载(该类的第一个对象没有生成)就加载了这个类。
        // (2)为了产生Class引用，forName()立即就进行了初始化
        System.out.println("forName: " + Class.forName("com.Al_tair.reflection.Cat")); // forName: class com.Al_tair.reflection.Cat
        
        // 2.Object-getClass() 获取Class对象的一个引用，返回表示该对象的实际类型的Class引用
        System.out.println("getClass: " + new Cat().getClass()); // getClass: class com.Al_tair.reflection.Cat
        
        // 3.getName() 取全限定的类名(包括包名)，即类的完整名字
        System.out.println("getName: " + com.Al_tair.reflection.Cat.class); // getName: class com.Al_tair.reflection.Cat
        
        // 4.getSimpleName() 获取类名(不包括包名)
        System.out.println("getSimpleName: "+ new Cat().getClass().getSimpleName()); // getSimpleName: Cat
        
        // 5.getCanonicalName() 获取全限定的类名(包括包名)
        System.out.println("getCanonicalName: "+ new Cat().getClass().getCanonicalName()); // getCanonicalName: com.Al_tair.reflection.Cat
        
        // 6.isInterface() 判断Class对象是否是表示一个接口
        System.out.println("isInterface: "+ new Cat().getClass().isInterface()); // isInterface: false
        System.out.println("isInterface: "+ Fly.class.isInterface()); // isInterface: true
        
        // 7.getInterfaces() 返回Class对象数组，表示Class对象所引用的类所实现的所有接口。
        for (Class list:new Cat().getClass().getInterfaces()){
            System.out.println(list); // interface com.Al_tair.reflection.Fly
        }
       
        // 8.getSuperclass() 返回Class对象，表示Class对象所引用的类所继承的直接基类。应用该方法可在运行时发现一个对象完整的继承结构。
        System.out.println("getSuperclass"+new Cat().getClass().getSuperclass()); // getSuperclassclass com.Al_tair.reflection.Animal
        
        // 9. getFields() 获得某个类的所有的公共（public）的字段，包括继承自父类的所有公共字段。 类似的还有getMethods和getConstructors。
        //    getDeclaredFields 获得某个类的自己声明的字段，即包括public、private和proteced，默认但是不包括父类声明的任何字段
        Cat  cat = Cat.class.newInstance();
        for (Field f: cat.getClass().getFields()) {
            System.out.print(f.getName()+" "); // name color age 
        }
    }
}
interface Fly{
}
class Animal{
    public int age;
}
class Cat extends Animal implements Fly {
    public String name = "";
    public String color;

    public Cat() {
    }

    public Cat(String name, String color, int age) {
        this.name = name;
        this.color = color;
        this.age = age;
    }

    @Override
    public String toString() {
        return "cat{" +
                "name='" + name + '\'' +
                ", color='" + color + '\'' +
                ", age=" + age +
                '}';
    }
}
```



#### Constructor类及其用法

Class类与Constructor相关的主要方法如下：

![image-20220323172016983](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220323172016983.png) 

关于**Constructor类本身一些常用方法**如下(仅部分，其他可查API)

![image-20220323172033657](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220323172033657.png)

我在这里就不大篇幅的讲述Constructor类的大量方法，用代码举例一些常用方法如下

```java
public class Constructor01 {
    public static void main(String[] args) throws IllegalAccessException, InstantiationException, NoSuchMethodException, InvocationTargetException {
        Class cls = new Person().getClass();
        Person p = (Person)cls.newInstance(); // 调用无参构造器
        System.out.println(p); // User{age=18, name='lns'}

        // 调用public修饰的有参构造器
        Constructor con = cls.getConstructor(String.class);
        Person p2 = (Person)con.newInstance("zlr");
        System.out.println(p2); // User{age=18, name='zlr'}

        // 调用非public修饰的有参构造器
        Constructor decCon = cls.getDeclaredConstructor(int.class,String.class);
        decCon.setAccessible(true); // 设置爆破，突破访问权限
        Person p3 = (Person)decCon.newInstance(12,"zlr"); 
        System.out.println(p3); // User{age=12, name='zlr'}
    }
}

class Person {
    private int age = 18;
    private String name = "lns";
    public Person() {
        super();
    }
    public Person(String name) {
        super();
        this.name = name;
    }

    private Person(int age, String name) {
        super();
        this.age = age;
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    @Override
    public String toString() {
        return "User{" +
                "age=" + age +
                ", name='" + name + '\'' +
                '}';
    }
}
```



####  Field类及其用法

Class类与Field对象相关方法如下：

![image-20220323172124461](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220323172124461.png) 

关于Field类还有其他常用的方法如下：

![image-20220323172204939](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220323172204939.png) 

我在这里就不大篇幅的讲述Field类的大量方法，用代码举例一些常用方法如下

```java
public class Field01 {
    public static void main(String[] args) throws ClassNotFoundException, IllegalAccessException, InstantiationException, NoSuchFieldException {
        Class<?> cls = Class.forName("com.Al_tair.reflection.Student");
        Student s = (Student)cls.newInstance();
        Field age = cls.getField("age");
        // 设置age属性值（public修饰）
        age.set(s,12);
        System.out.println(s.toString()); // Student{age=12, name='lns'}

        Field name = cls.getDeclaredField("name");
        name.setAccessible(true); // 爆破私有属性
        // 设置name属性（私有属性）
        name.set(s,"zlr");
        System.out.println(s.toString()); // Student{age=12, name='zlr'}

    }
}

class Student {
    public int age = 18;
    private String name = "lns";

    @Override
    public String toString() {
        return "Student{" +
                "age=" + age +
                ", name='" + name + '\'' +
                '}';
    }
}
```



#### Method类及其用法

Class类获取Method对象相关的方法：

![image-20220323203449786](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220323203449786.png)

常用方法如下：

![image-20220323203525186](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220323203525186.png) 

我在这里就不大篇幅的讲述Method类的大量方法，用代码举例一些常用方法如下

```java
public class Method01 {
    public static void main(String[] args) throws ClassNotFoundException, IllegalAccessException, InstantiationException, NoSuchMethodException, InvocationTargetException {
        // method.setAccessible(true) 私有方法爆破
        // 访问： method.invoke(object,实参列表) 注意：静态方法的话object对象可以填写成null
        Class<?> cls = Class.forName("com.Al_tair.reflection.car");
        car c = (car)cls.newInstance();
        System.out.println(c.toString()); // car{OilPer=0.6, name='玛莎拉蒂'}
        // 获取的方法的名字和形参类型
        Method name = cls.getMethod("setName", String.class);
        // 传入形参（该方法是公有方法）
        name.invoke(c, "红旗");
        System.out.println(c.toString()); // car{OilPer=0.6, name='红旗'}

        //  getDeclaredMethod 可以是公有的方法也可以是私有的方法
        Method addOil = cls.getDeclaredMethod("addOil", double.class);
        // 私有方法爆破
        addOil.setAccessible(true);
        // 传入形参（该方法是公有方法）
        addOil.invoke(c,1.0);
        System.out.println(c.toString()); // car{OilPer=1.0, name='红旗'}


    }
}

class car{
    private double OilPer = 0.6; // 油量60%
    private String name = "玛莎拉蒂";

    private void addOil(double oilPer){
        this.OilPer = oilPer;
    }

    public void setName(String name){
        this.name = name;
    }

    @Override
    public String toString() {
        return "car{" +
                "OilPer=" + OilPer +
                ", name='" + name + '\'' +
                '}';
    }
}
```



### 相关面试题

**1. Java反射在实际项目中有哪些应用场景？**

- 使用JDBC时，如果要创建数据库的连接，则需要先通过反射机制加载数据库的驱动程序；
- 多数框架都支持注解/XML配置，从配置中解析出来的类是字符串，需要利用反射机制实例化；
- 面向切面编程（AOP）的实现方案，是在程序运行时创建目标对象的代理类，这必须由反射机制来实现。



## 设计模式(23种)

[设计模式示意图](https://refactoringguru.cn/design-patterns/singleton)

### 单例设计模式

所谓类的单例设计模式，就是采取一定的方法保证在整个的软件系统中，对某个类只能存在一个对象实例，并且该类只提供一个取得其对象实力的方法

种类：饿汉式 和 懒汉式

```java
public class SingleTon {
    /*
     * 饿汉式(类加载了对象就创建了) 
     * 步骤如下:
     *  1.构造器私有化 => 防止new对象
     *  2.类的内部创建对象（该对象是static）
     *  3.提供一个静态的公共方法 getInstance
     *
     * 懒汉式(只有当使用该方法时才创建对象)
     * 步骤如下:
     *  1.构造器私有化 => 防止new对象
     *  2.定义一个私有的static静态属性对象
     *  3.提供一个公共的static方法，返回Dog对象
     *
     * 总结 饿汉式和懒汉式的区别
     * 1.创建对象的时机不同：饿汉式是在类加载就创建了对象的实例，而懒汉式是在使用时才创建
     * 2.饿汉式不存在线程安全的问题，懒汉式存在线程安全的问题
     * 3.饿汉式存在浪费资源的可能，懒汉式并不存在这种问题
     *
     *  Runtime函数用到了饿汉式 源代码如下
     *  private static final Runtime currentRuntime = new Runtime();
     *  private static Runtime.Version version;
     *  public static Runtime getRuntime() {
     *     return currentRuntime;
     *  }
     *  // Don't let anyone else instantiate this class
     *  private Runtime() {}
     */
    public static void main(String[] args) {
        // 用来区别饿汉式和懒汉式的核心区别
        GirlFriend.age = 18;
        Dog.age = 3; 

//        GirlFriend girlFriend = GirlFriend.getInstance();
//        System.out.println(girlFriend);
//
//        Dog dog = Dog.getInstance();
//        System.out.println(dog.toString());
    }
}

// just one girlfriend
class GirlFriend{
    private String name;

    public  static int age;

    // 构造器私有化
    private GirlFriend(String name){
        System.out.println("调用了GirlFriend的构造器");
        this.name = name;
    }

    // 类的内部创建对象
    private static GirlFriend zsr = new GirlFriend("张申蕊");

    @Override
    public String toString() {
        return "My girlfriend is " + name;
    }
}

// just one dog
class Dog{
    private String name;

    public  static int age;

    // 构造器私有化
    private Dog(String name){
        System.out.println("调用了Dog的构造器");
        this.name = name;
    }

    // 定义一个私有的static静态属性对象
    private static Dog dog;

    // 提供一个公共的static方法，返回Dog对象
    public static Dog getInstance(){
        if(dog == null){
            dog = new Dog("小黄");
        }
        return dog;
    }

    @Override
    public String toString() {
        return "My dog is " + name;
    }

}
```



### 模板设计模式

```java
package design_patterns.Template;
public class TemplateDesign {
    /**
     * 模板设计模式（抽象类）
     * 设计一个抽象类如下:
     * 1）编写方法calculateTime() 用于计算某段代码的耗时时间
     * 2）编写抽象方法job()
     * 3）编写一个子类sub,继承抽象类Template,并实现job方法
     * 4）编写一个测试类TestTemplate,看看是否好用
     */
    public static void main(String[] args) {
        A a = new A();
        a.calculateTime();

        B b = new B();
        b.calculateTime();
    }
}
// 抽象模板类 
abstract class Template{ // 抽象类
    public abstract void job();  // 抽象方法

    public void calculateTime(){
        // 得到开始的时间
        long start = System.currentTimeMillis();
        job();
        // 得到开始的时间
        long end = System.currentTimeMillis();
        System.out.println("执行时间 " + (end-start));
    }
}
 
class A extends Template{
    @Override
    public void job() {
        // 计算 1+2+3+...+2000000
        long sum = 0;
        for (long i = 1; i <= 2000000; i++) {
            sum += i;
        }
    }
}

class B extends Template{
    @Override
    public void job() {
        // 计算 1*2*3*...*2000000
        long sum = 1;
        for (long i = 1; i <= 2000000; i++) {
            sum *= i;
        }
    }
}
```



### 代理模式

#### 静态代理

```java
// 线程代理类，模拟一个简易的Thread类
public class ThreadProxy implements Runnable{
    private Runnable target = null;

    @Override
    public void run() {
        if(target != null){
            target.run();
        }
    }

    public ThreadProxy() {
    }

    public ThreadProxy(Runnable target) {
        this.target = target;
    }

    public void start(){
        start0();
    }

    private void start0(){
        run();
    }
}

class test implements Runnable{
    public static void main(String[] args) {
        test test = new test();
        ThreadProxy tp = new ThreadProxy(test);
        tp.start();

    }

    @Override
    public void run() {
        System.out.println("开启线程"); // 开启线程
    }
}
```



### 修饰器设计模式

```java
// 基抽象类
public abstract class Reader_ {
    public  void readFile(){}
    public  void readString(){}
}
// 节点流模型
class FileReader_ extends Reader_{

    @Override
    public void readFile() {
        System.out.println("读取文件...");
    }
}
// 节点流模型
class StringReader_ extends Reader_{
    @Override
    public void readString() {
        System.out.println("读取字符串...");
    }
}

// 处理流模型
class BufferReader_ extends Reader_{
    private Reader_ in;

    public BufferReader_(Reader_ in) {
        this.in = in;
    }

    public void ReadFiles(int num){
        for (int i = 0; i < num; i++) {
            in.readFile();
        }
    }
}

class test{
    public static void main(String[] args) {
        BufferReader_ bufferReader_ = new BufferReader_(new FileReader_());
        bufferReader_.ReadFiles(3);
    }
}
```



## 正则表达式

正则表达式是对字符串执行模式匹配的技术 

### 底层实现分析

**局部匹配**

```java
public class RegexpDemo01 {
    public static void main(String[] args) {
         String str = "在1958 年,一位名叫Stephen Kleene的数学科学家博尔特，" +
                 "1963,他在Warren McCulloch和Walter Pitts早期工作的基础之上，发表了一篇题目是" +
                 "《神经网事件的表示法》的论文，1969利用称之为正则集合的数学符号来描述此模型，引入" +
                 "了正则表达式的概念。1971正则表达式被作为用来描述其称之为“正则集的代数”的一种表达式，" +
                 "因而采用了“正则表达式”这个术语。";

         // 匹配正则表达式字符 匹配四个数字
         String regexp = "\\d\\d\\d\\d";
         // 生成模式对象
         Pattern pattern = Pattern.compile(regexp);
         // 匹配字符
         Matcher matcher = pattern.matcher(str);
        
        /*
         * matcher.find()
         * 1. 根据 pattern 的规则, 定位满足规则的字符串(比如:1958) 在str的开始索引位置(1)和结束索引位置+1(5)
         * 2. 将索引位置记录到数组groups; 的下标 groups[0] = 0 groups[1] = 4
         * 3. 并且下一次索引开始等于当前的结束索引位置+1 （设置为 5, 表示下一次匹配从5开始）
         * 4. 下次找到数字1963 始索引位置(36)和结束索引位置+1(40)
         * 5. 将索引位置记录到数组groups;的下标groups[0] = 0 groups[1] = 4 记住会覆盖之前的数组下标0,1的数组
         *
         *     特别说明: 当在正则表达式中有()(如(\\d\\d)(\\d\\d) ),则表示分组
         *     第1个() 表示第一组  第2个() 表示第2组
         *     2.1 groups[0] groups[1] 记录匹配到的完整结果 如: 1958
         *     2.2 groups[2] groups[3] 记录匹配到的结果的第一个()的内容的开始索引和结束索引+1 即0和2
         *     2.3 groups[4] groups[5] 记录匹配到的结果的第2个()的内容的开始索引和结束索引+1 即2和4
         *
         * ----------------------------------------------------------------------------------------
         *
         * matcher.group(index)
         *     源码分析
         *     public String group(int group) {
         *         if (first < 0)
         *             throw new IllegalStateException("No match found");
         *         if (group < 0 || group > groupCount())
         *             throw new IndexOutOfBoundsException("No group " + group);
         *         if ((groups[group*2] == -1) || (groups[group*2+1] == -1))
         *             return null;
         *         return getSubSequence(groups[group * 2], groups[group * 2 + 1]).toString();
         *     }
         * 1. 如果matcher.group(1)从字符串截取下标 groups[0] 到 groups[1]-1 的子字符串
         * 2. 如果matcher.group(1) 截取 groups[2] 到 groups[3] 对应索引的子字符串
         * 2. 如果matcher.group(2) 截取 groups[4] 到 groups[5] 对应索引的子字符串
         *
         * 然后循环的执行find和group的方法
         */
         while(matcher.find()){ // 如果查找数组找到的值为-1即没有存入数据则返回false
             System.out.print(matcher.group(0) + "  "); // 1958  1963  1969  1971
         }
    }
}
```

**整体匹配**

```java
public static void main(String[] args) {
    String str = "12345";
    // 匹配正则表达式字符 匹配四个数字
    String regexp = "\\d\\d\\d\\d";
    // 匹配字符 完成匹配，不
    boolean isMatch = Pattern.matches(pattern,content);
    System.out.println(isMarch); // false
}
```



### 正则表达式语法

#### 元字符

##### 转义符

```java
// 转义符:\\ 
public static void main(String[] args) {
    String str = "在1958 年,一位名叫Stephen Kle(ene的(数学科学家博尔特(";
    String regexp = "\\("; // ( 会报错
    Pattern pattern = Pattern.compile(regexp);
    Matcher matcher = pattern.matcher(str);
    while (matcher.find()){
        System.out.println(matcher.group(0)); // 3个 (
    }
}
```

##### 限定符

用于指定其前面的字符和组合项连续出现多少次

| 符号  |                             含义                             | 示例        |                             说明                             |         匹配输入         |
| :---: | :----------------------------------------------------------: | ----------- | :----------------------------------------------------------: | :----------------------: |
|   *   |             指定字符重复0次或n次（无要求)零到多              | (abc)*      |              仅包含任意个abc的字符串，等效于\w*              |      abc，abcabcabc      |
|   +   |               指定字符重复1次或n次（至少一次)                | m+(abc)*    |            以至少1个m开头，后接任意个abc的字符串             |     m，mabc，mabcabc     |
|  ？   |               指定字符重复0次或1次（最多一次)                | m+abc?      |             以至少1个m开头，后接ab或abc的字符串              |     mab，mabc，mmmab     |
|  {n}  |                       只能输入n个字符                        | [abcd]{3}   |            由abcd中字母组成的任意长度为3的字符串             |      abc，dbc，adc       |
| {n,}  |                       指定至少n个匹配                        | [abcd]{3,}  |          由abcd中字母组成的任意长度不小于3的字符串           |     aab，dbc，aaabdc     |
| {n,m} |                  指定至少n个但不多于m个匹配                  | [abcd]{3,5} |      由abcd中字母组成的任意长度不小于3，不大于5的字符串      | abc，abcd，aaaaaa，bcdab |
|   ?   | 匹配模式是"非贪心的"。"非贪心的"模式匹配搜索到的、尽可能短的字符串 |             | 当此字符紧随任何其他限定符（*、+、?、{n}、{n,}、{n,m}）之后时， |                          |

注意：java匹配默认贪婪匹配，即尽可能匹配多的数量 如 a{3,4} ： aaaa优先级 > aaa优先级

##### 选择匹配符

在选择匹配某个字符串的时候是选择性的（ | ）

| 符号 |            含义            |  示例  |   解释   |
| :--: | :------------------------: | :----: | :------: |
|  \|  | 匹配“\|”之前或之后的表达式 | ab\|bc | ab或者bc |

##### 分组组合

**常用分组**

|  常用分组构造形式  |                             说明                             |
| :----------------: | :----------------------------------------------------------: |
|    （pattern）     | 非命名捕获。捕获匹配的子字符串。编号为零的第一个捕获是由整个正则表达式模式匹配的文本，其它捕获结果则根据左括号的顺序从1开始自动编号 |
| (?< name >pattern) | 命名捕获。将匹配的子字符串捕获到一个组名称或编号名称中。用于name的字符串不能包含任何标点符号，并且不能以数字开头。可以使用单引号替代尖括号，例如(？'name') |

```java
public static void main(String[] args) {
    String str = "在1958 年,一位名叫Stephen Kleene的数学科学家博尔特，" +
        "1963,他在Warren McCulloch和Walter Pitts早期工作的基础之上，发表了一篇题目是" +
        "《神经网事件的表示法》的论文，1969利用称之为正则集合的数学符号来描述此模型，引入" +
        "了正则表达式的概念。1971正则表达式被作为用来描述其称之为“正则集的代数”的一种表达式，" +
        "因而采用了“正则表达式”这个术语。";

    // 匹配正则表达式字符 匹配四个数字
    // 非命名分组
    String regexp = "(\\d\\d)(\\d\\d)";
    // 生成模式对象
    Pattern pattern = Pattern.compile(regexp);
    // 匹配字符
    Matcher matcher = pattern.matcher(str);
    while(matcher.find()){
        //  1958  19  58
        //  1963  19  63
        //  1969  19  69
        //  1971  19  71
        System.out.print(matcher.group(0) + "  ");
        System.out.print(matcher.group(1) + "  ");
        System.out.print(matcher.group(2) + "  ");
        System.out.println();
    }

    System.out.println("=====================");

    // 命名分组
    regexp = "(?<group1>\\d\\d)(?<group2>\\d\\d)";
    pattern = Pattern.compile(regexp);
    // 匹配字符
    matcher = pattern.matcher(str);
    while(matcher.find()){
        //  1958  19  58
        //  1963  19  63
        //  1969  19  69
        //  1971  19  71
        System.out.print(matcher.group(0) + "  ");
        System.out.print(matcher.group("group1") + "  ");
        System.out.print(matcher.group("group2") + "  ");
        System.out.println();
    }
}
```

**特别分组**

| 常用分组构造形式 |                             说明                             |
| :--------------: | :----------------------------------------------------------: |
|  （?:pattern）   | 匹配pattern但不捕获该匹配的子表达式，即它是一个非捕获匹配，不存储供以后使用的匹配。这对于用"o"字符()组合模式部件的情况很有用。例如，'industr(?yies)是比'industryindustries'更经济的表达式 |
|   (?=pattern)    | 它是一个非捕获匹配。例如，Windows(?=9598NT2000)'匹配"Windows2000"中的"Vindows",但不匹配"Vindows3.1"中的"Windows" |
|   (?!pattern)    | 该表达式匹配不处于匹配pattern的字符串的起始点的搜索字符串。它是一个非捕获匹配。例如，"Nindows(?!9598NT2000)'匹配"Windows3.1"中的"Windows",但不匹配"Windows2000"中的"Vindows" |

```java
// （?:pattern）
String str = "罗念笙同学和罗念笙父亲以及罗念笙母亲要一起出席会场";
String regexp = "罗念笙(?:同学|父亲|母亲)"; // 等价于 "罗念笙同学 | 罗念笙父亲 | 罗念笙母亲)"
Pattern pattern = Pattern.compile(regexp);
Matcher matcher = pattern.matcher(str);
while(matcher.fins()){
    // 不能使用group(1)捕获分组，但是整体是可以用group(0)捕获
}

// (?=pattern) 和 (?!pattern) 取反关系
```

##### 字符匹配符

| 符号  |                         含义                         |        示例        |                         解释                         |
| :---: | :--------------------------------------------------: | :----------------: | :--------------------------------------------------: |
|  [ ]  |                   可接受的字符列表                   |       [efgh]       |               e,f,g,h中的任意一个字符                |
|  [^]  |                   不接收的字符列表                   |       [^abc]       |     a,b,c之外的任意一个字符，包括数字和特殊字符      |
|   -   |                        连字符                        |        A-Z         |                   任意一个大写字母                   |
|   .   |                匹配除\n以外的任何字符                |        a..b        | 以a开头，b结尾，中间包括2个任意字符的长度为4的字符串 |
| \ \d  |            匹配单个数字字符，相当于[0-9]             |   \ \d{3}(\ \d)?   |               包含3个或4个数字的字符串               |
| \ \D  |         匹配单个非数字字符，相当于[ ^ 0-9]]          |    \ \D(\ \d)*     |      以单个非数字字符开头，后接任意个数字字符串      |
| \ \w  |    匹配单个数字、大小写字母字符相当于[0-9a-zA-Z]     |   \ \d{3}\ \w{4}   |      以3个数字字符开头的长度为7的数字字母字符串      |
| \ \\W | 匹配单个非数字、大小写字母字符相当于[ ^   0-9a-zA-Z] |   \ \W+\  \d{2}    | 以至少1个非数字字母字符开头，2个数字字符结尾的字符串 |
| \ \ s |          匹配任何空白字符（空格，制表符等）          |    空格，制表符    |                          无                          |
| \ \ S |                  匹配任何非空白字符                  | 除空格，制表符之外 |                          无                          |

``` java
// 细节说明
// 不区分大小写
(?!)abc  //  abc都不区分大小写
a(?!)bc  //  abc都不区分大小写
a((?!)b)c // 只有b不区分大小写
Pattern pattern = Pattern.compile(regexp,Pattern.CASE_INSENSITIVE);
```

##### 定位符

规定要匹配的字符出现的位置

| 符号  | 含义                   | 示例                  | 说明                                                         | 匹配输入      |
| ----- | ---------------------- | --------------------- | ------------------------------------------------------------ | ------------- |
| ^     | 指定起始字符           | ^[0-9] + [a- z]*      | 以至少1个数字开头，后 串                                     | 123， 6aa     |
| $     | 指定结束字符           | ^[0-9]\ \ - [a-z] + $ | 以1个数字开头后接连字符“-”，并以至少1个小写字母结尾的字符串  | 1-a           |
| \ \ b | 匹配目标字符串的边界   | lns\ \ b              | 这里说的字符串的边界指的是子串间有空格，或者是目标字符串的结束位置 | splns，hallns |
| \ \ B | 匹配目标字符串的非边界 | lns \ \ B             | 和b的含义刚刚相反                                            | lnssp，lnsfh  |



### 常用正则表达式（取自菜鸟教程）

**一、校验数字的表达式**

- 数字：**^[0-9]\*$**
- n位的数字：**^\d{n}$**
- 至少n位的数字**：^\d{n,}$**
- m-n位的数字：**^\d{m,n}$**
- 零和非零开头的数字：**^(0|[1-9][0-9]\*)$**
- 非零开头的最多带两位小数的数字：**^([1-9][0-9]\*)+(\.[0-9]{1,2})?$**
- 带1-2位小数的正数或负数：**^(\-)?\d+(\.\d{1,2})$**
- 正数、负数、和小数：**^(\-|\+)?\d+(\.\d+)?$**
- 有两位小数的正实数：**^[0-9]+(\.[0-9]{2})?$**
- 有1~3位小数的正实数：**^[0-9]+(\.[0-9]{1,3})?$**
- 非零的正整数：**^[1-9]\d\*$ 或 ^([1-9][0-9]\*){1,3}$ 或 ^\+?[1-9][0-9]\*$**
- 非零的负整数：**^\-[1-9][]0-9"\*$ 或 ^-[1-9]\d\*$**
- 非负整数：**^\d+$ 或 ^[1-9]\d\*|0$**
- 非正整数：**^-[1-9]\d\*|0$ 或 ^((-\d+)|(0+))$**
- 非负浮点数：**^\d+(\.\d+)?$ 或 ^[1-9]\d\*\.\d\*|0\.\d\*[1-9]\d\*|0?\.0+|0$**
- 非正浮点数：**^((-\d+(\.\d+)?)|(0+(\.0+)?))$ 或 ^(-([1-9]\d\*\.\d\*|0\.\d\*[1-9]\d\*))|0?\.0+|0$**
- 正浮点数：**^[1-9]\d\*\.\d\*|0\.\d\*[1-9]\d\*$ 或 ^(([0-9]+\.[0-9]\*[1-9][0-9]\*)|([0-9]\*[1-9][0-9]\*\.[0-9]+)|([0-9]\*[1-9][0-9]\*))$**
- 负浮点数：**^-([1-9]\d\*\.\d\*|0\.\d\*[1-9]\d\*)$ 或 ^(-(([0-9]+\.[0-9]\*[1-9][0-9]\*)|([0-9]\*[1-9][0-9]\*\.[0-9]+)|([0-9]\*[1-9][0-9]\*)))$**
- 浮点数：**^(-?\d+)(\.\d+)?$ 或 ^-?([1-9]\d\*\.\d\*|0\.\d\*[1-9]\d\*|0?\.0+|0)$**

------

**二、校验字符的表达式**

- 汉字：**^[\u4e00-\u9fa5]{0,}$**
- 英文和数字：**^[A-Za-z0-9]+$ 或 ^[A-Za-z0-9]{4,40}$**
- 长度为3-20的所有字符：**^.{3,20}$**
- 由26个英文字母组成的字符串：**^[A-Za-z]+$**
- 由26个大写英文字母组成的字符串：**^[A-Z]+$**
- 由26个小写英文字母组成的字符串：**^[a-z]+$**
- 由数字和26个英文字母组成的字符串：**^[A-Za-z0-9]+$**
- 由数字、26个英文字母或者下划线组成的字符串：**^\w+$ 或 ^\w{3,20}$**
- 中文、英文、数字包括下划线：**^[\u4E00-\u9FA5A-Za-z0-9_]+$**
- 中文、英文、数字但不包括下划线等符号：**^[\u4E00-\u9FA5A-Za-z0-9]+$ 或 ^[\u4E00-\u9FA5A-Za-z0-9]{2,20}$**
- 可以输入含有^%&',;=?$\"等字符：**[^%&',;=?$\x22]+**
- 禁止输入含有~的字符：**[^~]+**

------

**三、特殊需求表达式**

- Email地址：**^\w+([-+.]\w+)\*@\w+([-.]\w+)\*\.\w+([-.]\w+)\*$**
- 域名：**[a-zA-Z0-9][-a-zA-Z0-9]{0,62}(\.[a-zA-Z0-9][-a-zA-Z0-9]{0,62})+\.?**
- InternetURL：**[a-zA-z]+://[^\s]\* 或 ^http://([\w-]+\.)+[\w-]+(/[\w-./?%&=]\*)?$**
- 手机号码：**^(13[0-9]|14[5|7]|15[0|1|2|3|4|5|6|7|8|9]|18[0|1|2|3|5|6|7|8|9])\d{8}$**
- 电话号码("XXX-XXXXXXX"、"XXXX-XXXXXXXX"、"XXX-XXXXXXX"、"XXX-XXXXXXXX"、"XXXXXXX"和"XXXXXXXX)：**^(\(\d{3,4}-)|\d{3.4}-)?\d{7,8}$**
- 国内电话号码(0511-4405222、021-87888822)：**\d{3}-\d{8}|\d{4}-\d{7}**
- 电话号码正则表达式（支持手机号码，3-4位区号，7-8位直播号码，1－4位分机号）: **((\d{11})|^((\d{7,8})|(\d{4}|\d{3})-(\d{7,8})|(\d{4}|\d{3})-(\d{7,8})-(\d{4}|\d{3}|\d{2}|\d{1})|(\d{7,8})-(\d{4}|\d{3}|\d{2}|\d{1}))$)**
- 身份证号(15位、18位数字)，最后一位是校验位，可能为数字或字符X：**(^\d{15}$)|(^\d{18}$)|(^\d{17}(\d|X|x)$)**
- 帐号是否合法(字母开头，允许5-16字节，允许字母数字下划线)：**^[a-zA-Z][a-zA-Z0-9_]{4,15}$**
- 密码(以字母开头，长度在6~18之间，只能包含字母、数字和下划线)：**^[a-zA-Z]\w{5,17}$**
- 强密码(必须包含大小写字母和数字的组合，不能使用特殊字符，长度在 8-10 之间)：**^(?=.\*\d)(?=.\*[a-z])(?=.\*[A-Z])[a-zA-Z0-9]{8,10}$**
- 强密码(必须包含大小写字母和数字的组合，可以使用特殊字符，长度在8-10之间)：**^(?=.\*\d)(?=.\*[a-z])(?=.\*[A-Z]).{8,10}$**
- 日期格式：**^\d{4}-\d{1,2}-\d{1,2}**
- 一年的12个月(01～09和1～12)：**^(0?[1-9]|1[0-2])$**
- 一个月的31天(01～09和1～31)：**^((0?[1-9])|((1|2)[0-9])|30|31)$**
- 钱的输入格式：
    1. 有四种钱的表示形式我们可以接受:"10000.00" 和 "10,000.00", 和没有 "分" 的 "10000" 和 "10,000"：**^[1-9][0-9]\*$**
    2. 这表示任意一个不以0开头的数字,但是,这也意味着一个字符"0"不通过,所以我们采用下面的形式：**^(0|[1-9][0-9]\*)$**
    3. 一个0或者一个不以0开头的数字.我们还可以允许开头有一个负号：**^(0|-?[1-9][0-9]\*)$**
    4. 这表示一个0或者一个可能为负的开头不为0的数字.让用户以0开头好了.把负号的也去掉,因为钱总不能是负的吧。下面我们要加的是说明可能的小数部分：**^[0-9]+(.[0-9]+)?$**
    5. 必须说明的是,小数点后面至少应该有1位数,所以"10."是不通过的,但是 "10" 和 "10.2" 是通过的：**^[0-9]+(.[0-9]{2})?$**
    6. 这样我们规定小数点后面必须有两位,如果你认为太苛刻了,可以这样：**^[0-9]+(.[0-9]{1,2})?$**
    7. 这样就允许用户只写一位小数.下面我们该考虑数字中的逗号了,我们可以这样：**^[0-9]{1,3}(,[0-9]{3})\*(.[0-9]{1,2})?$**
    8. 1到3个数字,后面跟着任意个 逗号+3个数字,逗号成为可选,而不是必须：**^([0-9]+|[0-9]{1,3}(,[0-9]{3})\*)(.[0-9]{1,2})?$**
    9. 备注：这就是最终结果了,别忘了"+"可以用"*"替代如果你觉得空字符串也可以接受的话(奇怪,为什么?)最后,别忘了在用函数时去掉去掉那个反斜杠,一般的错误都在这里
- xml文件：**^([a-zA-Z]+-?)+[a-zA-Z0-9]+\\.[x|X][m|M][l|L]$**
- 中文字符的正则表达式：**[\u4e00-\u9fa5]**
- 双字节字符：**[^\x00-\xff] (包括汉字在内，可以用来计算字符串的长度(一个双字节字符长度计2，ASCII字符计1))**
- 空白行的正则表达式：**\n\s\*\r (可以用来删除空白行)**
- HTML标记的正则表达式：**<(\S\*?)[^>]\*>.\*?|<.\*? /> ( 首尾空白字符的正则表达式：^\s\*|\s\*$或(^\s\*)|(\s\*$) (可以用来删除行首行尾的空白字符(包括空格、制表符、换页符等等)，非常有用的表达式)**
- 腾讯QQ号：**[1-9][0-9]{4,} (腾讯QQ号从10000开始)**
- 中国邮政编码：**[1-9]\d{5}(?!\d) (中国邮政编码为6位数字)**
- IPv4地址：**((2(5[0-5]|[0-4]\d))|[0-1]?\d{1,2})(\.((2(5[0-5]|[0-4]\d))|[0-1]?\d{1,2})){3}**
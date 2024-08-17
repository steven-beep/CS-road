# HTML

---

**JavaWeb技术体系图**

![image-20220415164848485](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220415164848485.png)



## 基本概念

[W3school HTML教程](https://www.w3school.com.cn/html/index.asp)

概念：HTML 是用来描述网页的一种语言，可以理解为网页内容的载体（包含文字、图片、视频等）

- HTML 指的是超文本标记语言 (**H**yper **T**ext **M**arkup **L**anguage)
- HTML 不是一种编程语言，而是一种标记语言
- 标记语言是一套标记标签

**实战效果**

![image-20220415170233878](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220415170233878.png) 

```html
<!DOCTYPE html>
<html lang="en">
	<head>
		<meta charset="utf-8">
		<title></title>
	</head>
	<body>
		<h1>Hello,html</h1>
	</body>
</html>
```

**HTML基本结构**

```html
<!-- 文档类型：html -->
<!DOCTYPE html>
<!-- 整个html页面的开始  -->
<html lang="en">
    <!-- 头信息 -->
    <head>
        <!-- 字符集 -->
        <meta charset="utf-8">
        <!-- 标题 -->
        <title></title>
    </head>
    <!-- body页面的内容 -->
    <body>
        <!-- 网页内容 -->
        <h1>Hello,html</h1>
    </body>
 <!-- 整个html页面的结束 -->
</html>
```

**标签使用细节**

- 标签不能交叉嵌套
- 标签必须正确关闭
- 注释不能嵌套



## 字符实体

概念：在网页上显示一些特殊的符号，称为字符实体（也叫符号实体）

| 显示结果 | 描述              | 实体名称          | 实体编号 |
| :------- | :---------------- | :---------------- | :------- |
|          | 空格              | &nbsp;            | &#160;   |
| <        | 小于号            | &lt;              | &#60;    |
| >        | 大于号            | &gt;              | &#62;    |
| &        | 和号              | &amp;             | &#38;    |
| "        | 引号              | &quot;            | &#34;    |
| '        | 撇号              | &apos; (IE不支持) | &#39;    |
| ￠       | 分（cent）        | &cent;            | &#162;   |
| £        | 镑（pound）       | &pound;           | &#163;   |
| ¥        | 元（yen）         | &yen;             | &#165;   |
| €        | 欧元（euro）      | &euro;            | &#8364;  |
| §        | 小节              | &sect;            | &#167;   |
| ©        | 版权（copyright） | &copy;            | &#169;   |
| ®        | 注册商标          | &reg;             | &#174;   |
| ™        | 商标              | &trade;           | &#8482;  |
| ×        | 乘号              | &times;           | &#215;   |
| ÷        | 除号              | &divide;          | &#247;   |



## 标题标签

![image-20220415174642654](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220415174642654.png) 

```html
<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title></title>
	</head>
	<body>
         <!-- 标题标签 -->
		<h1>h1</h1>
		<h2>h2</h2>
		<h3>h3</h3>
		<h4>h4</h4>
		<h5>h5</h5>
		<h6>h6</h6>
	</body>
</html>
```



## 超链接标题

```html
<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8">
        <title></title>
    </head>
    <body>
        <!-- 超链接标题 -->
        <!-- href: url链接地址 -->
        <!-- target打开来链接的位置 _self:当前页面 _blank:打开新的页面 -->
        <a href="http://www.bai.com" target="_self"></a>
    </body>
</html>
```



## 列表标签

### 无序列表

![image-20220415194807075](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220415194807075.png) 

```html
<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8">
        <title></title>
    </head>
    <!-- ul:表示无序列表 -->
    <!-- type = "disc" 实心圆点 -->
    <!-- type = "circle" 空心圆 -->、
    <!-- type = "square" 空心正方形 -->
    <ul type="circle">
        <li>1</li>
        <li>2</li>
        <li>3</li>
    </ul>
    <body>
    </body>
</html>
```

### 有序列表

![image-20220415194900154](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220415194900154.png) 

```html
<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8">
        <title></title>
    </head>
    <body>
        <ol type="A">
            <li>1</li>
            <li>2</li>
            <li>3</li>
        </ol>
    </body>
</html>
```



## 图像标签

![image-20220415195455625](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220415195455625.png) 

```html
<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8">
        <title></title>
    </head>
    <body>
        <!-- img:标签是图片标签,用来显示图片 -->
        <!-- src:属性可以设置图片的路径 -->
        <!-- width:属性设置图片的宽度 -->
        <!-- height:属性设置图片的高度 -->
        <!-- border:属性设置图片边框大小 -->
        <!-- alt:属性设置当指定路径找不到图片时,用来代替显示的文本内容 -->
        <img src="image/耦合.png" />
    </body>
</html>
```



## 表格标签

![image-20220415200811981](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220415200811981.png) 

```html
<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8">
        <title></title>
    </head>
    <body>
        <!-- table：标签是表格标签 -->
        <!-- border：设置表格标签 -->
        <!-- width：设置表格宽度 -->
        <!-- height：设置表格高度 -->
        <!-- align：设置表格相对于页面的对齐方式 -->
        <!-- cellspacing：设置单元格间距 -->
        <table border="3px" cellspacing="3px" align="center">
            <!-- tr：是行标签 -->
            <tr>
                <!-- th：是表头标签 -->
                <th>Header</th>
                <th>Header</th>
                <th>Header</th>
            </tr>
            <tr>
                <!-- td：是单元格标签 -->
                <td>Data</td>
                <td>Data</td>
                <td>Data</td>
            </tr>
            <tr>
                <!-- td：是单元格标签 -->
                <td>Data</td>
                <td>Data</td>
                <td>Data</td>
            </tr>
        </table>
    </body>
</html>
```

**升级版表格**

![image-20220415202413859](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220415202413859.png) 

```html
<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title></title>
	</head>
	<body>
		<table border="1px" cellspacing="0px" align="center" width="500px" height="100px" bordercolor="#b686b3">
			<tr>
				<!-- 合并三列 -->
				<td colspan="3" align="center">星期一：菜谱</td>
			</tr>
			<tr>
				<!-- 合并行 -->
				<td rowspan="2">素菜</td>
				<td>青草茄子</td>
				<td>花椒扁豆</td>
			</tr>
			<tr>
				<td>小葱豆腐</td>
				<td>炒白菜</td>
			</tr>
			<tr>
				<!-- 合并行 -->
				<td rowspan="2">荤菜</td>
				<td>油闷大虾</td>
				<td>海参鱼翅</td>
			</tr>
			<tr>
				<td>红烧肉<img src="image/1.png"/></td>
				<td>烤全羊</td>
			</tr>
		</table>
	</body>
</html>
```

**表格练习**

![image-20220416142924287](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220416142924287.png) 

```html
<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title></title>
		<style type="text/css">
			tr{
				text-align: center;
			}
		</style>
	</head>
	<body>
		<table border="2px" align="center" bordercolor="#7aabb8">
			<div align="center">成绩表</div>
			<tr>
				<th>项目</th>
				<th colspan="5">上课</th>
				<th colspan="2">休息</th>
			</tr>
			<tr>
				<td>星期</td>
				<td>星期一</td>
				<td>星期二</td>
				<td>星期三</td>
				<td>星期四</td>
				<td>星期五</td>
				<td>星期六</td>
				<td>星期日</td>
			</tr>
			<tr>
				<td rowspan="5">上午</td>
				<td>语文</td>
				<td>数学</td>
				<td>英语</td>
				<td>英语</td>
				<td>物理</td>
				<td>计算机</td>
				<td rowspan="5">休息</td>
			</tr>
			<tr>
				<td>数学</td>
				<td>数学</td>
				<td>地理</td>
				<td>历史</td>
				<td>化学</td>
				<td>计算机</td>
			</tr>
			<tr>
				<td>化学</td>
				<td>语文</td>
				<td>体育</td>
				<td>计算机</td>
				<td>英语</td>
				<td>计算机</td>
			</tr>
			<tr>
				<td>化学</td>
				<td>语文</td>
				<td>体育</td>
				<td>计算机</td>
				<td>英语</td>
				<td>计算机</td>
			</tr>
			<tr>
				<td>政治</td>
				<td>英语</td>
				<td>体育</td>
				<td>历史</td>
				<td>地理</td>
				<td>计算机</td>
			</tr>
			<tr>
				<td rowspan="2">下午</td>
				<td>语文</td>
				<td>数学</td>
				<td>英语</td>
				<td>英语</td>
				<td>物理</td>
				<td>计算机</td>
				<td rowspan="2">休息</td>
			</tr>
			<tr>
				<td>数学</td>
				<td>数学</td>
				<td>地理</td>
				<td>历史</td>
				<td>化学</td>
				<td>计算机</td>
			</tr>
		</table>
	</body>
</html>
```



## 表单标签

![image-20220415205848661](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220415205848661.png) 

```html
<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8">
        <title></title>
    </head>
    <body>
        <!-- url表示定位一个web资源的路径 -->
        <!-- method主要有两种get,pos -->
        <!-- form表示表单 -->
        <form action="other/200OK.html" method="get">
            <!-- input type=text 输入框 -->
            <!-- input type=password 密码框 -->
            <!-- inputtype=reset重置按钮 -->
            <!-- input type=submit 提交按钮-->
            <h1>登录系统</h1>
            用户名<input type="text" name="username"/><br>
            密  码<input type="password" name="pwd"/><br>
            <input type="submit"/>
        </form>
    </body>
</html>
```

**升级版表单**

![image-20220415233309531](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220415233309531.png) 

```html
<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8">
        <title></title>
    </head>
    <body>
        <!-- url表示定位一个web资源的路径 -->
        <!-- method主要有两种get,post 默认get -->
        <!-- form表示表单 -->
        <!-- 表单提交的时候，数据没有发送给服务器的三种情况： -->
        <!-- (1)表单某个元素项(比如text,password)没有name属性值 -->
        <!-- (2)单选、复选（下拉列表中的option标签）都需要添加value属性，以便发送给服务器 -->
        <!-- (3)表单项不在提交的form标签中 -->
        <form action="other/200OK.html" method="get">
            <!-- input type=text 输入框 -->
            <!-- input type=password 密码框 -->
            <!-- input type=radio 是单选框,name属性可以对其进行分组 -->
            <!-- checked ="checked" 表示默认选中 -->
            <!-- input type=checkbox 复选框 -->
            <!-- select标签是下拉列表框 -->
            <!-- option标签是下拉列表框中的选项 -->
            <!-- textarea表示多行文本输入框（起始标签和结束标签中的内容是默认值） -->
            <!-- rows属性设置可以显示几行的高度 -->
            <!-- cols属性设置每行可以显示几个字符宽度 -->
            <!-- input type=hidden 隐藏域 -->
            <!-- input type=file 文件上传域 -->
            <!-- inputtype=reset重置按钮 -->
            <!-- input type=submit 提交按钮-->		
            <table border="1px" align="center">
                <tr>
                    <th colspan="2">用户注册</th>
                </tr>
                <tr>
                    <td>用户名称:</td>
                    <td align="center"><input type="text" name="username"/></td>
                </tr>
                <tr>
                    <td>用户密码:</td>
                    <td align="center"><input type="password" name="pwd"/></td>
                </tr>
                <tr>
                    <td>确认密码</td>
                    <td align="center"><input type="password" name="pwd"/></td>
                </tr>
                <tr>
                    <td>运动项目</td>
                    <td align="center">
                        <!-- checkbox是复选框，如果希望是同一组保证name属性一致 -->
                        <input type="checkbox" name ="sport" checked="checked"/>篮球
                        <input type="checkbox" name="sport"/>足球
                        <input type="checkbox" name="sport"/>排球

                    </td>
                </tr>
                <tr>
                    <td>性别</td>
                    <td align="center">
                        <input type="radio" name="sex" checked="checked"/>男
                        <input type="radio" name="sex"/>女
                    </td>
                </tr>
                <tr>
                    <td>你喜欢的城市</td>
                    <td align="center">
                        <select >
                            <option>-请选择-</option>
                            <option value ="bj">北京</option>
                            <option value ="zj">浙江</option>
                            <option value ="sx">山西</option>
                            <option value ="sh">上海</option>
                        </select>
                    </td>
                </tr>
                <tr>
                    <td>自我介绍</td>
                    <td align="center"><textarea arows="5"cols="20"></textarea></td>
                </tr>
                <tr>
                    <td>头像</td>
                    <td><input type="file"/></td>
                </tr>
                <tr>
                    <td>提交</td>
                    <td align="center"><input type="submit"/></td>
                </tr>
            </table>
        </form>
    </body>
</html>
```

**GET和POST的区别**

GET请求特点：

- 数据不安全（数据显示在地址栏）
- 它有数据长度的限制(不同的浏览器规定不一样，一般 2k)

POST请求特点：

- 相对于 GET 请求要安全 
- 理论上没有数据长度的限制



## 块级元素和内联元素

< div >是一个块级标签,他的内容自动会换行

< p > 段落标签,他的内容自动会换行 ，并且会自动在其前后创建一些空白

< span > 标签是内联元素，不像块级元素（如：div 标签、p 标签等）有换行的效果

![image-20220416140436157](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220416140436157.png) 

```html
<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8">
        <title></title>
    </head>
    <body>
        <!-- div标签 会自动换行 -->
        <div>
            <h1>div</h1>
        </div>
        nb
        <!-- span标签 不会换行 -->
        <span>span</span>
        nb
        <!-- p标签 会自动换行并且前后创建一些空白 -->
        <p>p</p>
    </body>
</html>
```








































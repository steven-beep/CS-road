# javascript	

---

## 基本概念

[W3school教程](https://www.w3school.com.cn/js/index.asp)

概念：JavaScript能改变 HTML内容，能改变 HTML属性，能改变 CSS 样式，能完成页面的数据验证

特点:

- JavaScript 是一种解释型的脚本语言，C、C++等语言先编译后执行，而 JavaScript 是在程序 的运行过程中逐行进行解释

- JavaScript 是一种基于对象的脚本语言，可以创建对象，也能使用现有的对象(有对象)

- JavaScript 是弱类型的，对变量的数据类型不做严格的要求，变量的数据类型在运行过程可以变化

    ![image-20220417173823958](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220417173823958.png) 

    ```html
    <!DOCTYPE html>
    <html>
        <head>
            <meta charset="utf-8">
            <title></title>
            <!-- js 代码可以写在 script 标签中 -->
            <!-- type="text/javascript" 表示这个脚本(script)类型是 javascript -->
            <script type="text/javascript">
                var age = 80;
                console.log(typeof age);
                age = "罗念笙";
                console.log(typeof age);
            </script>
        </head>
        <body>
        </body>
    </html>
    ```

- 跨平台性（只要是可以解释 JS 的浏览器都可以执行，和平台无关）



## 两种方式使用javascript语句

### 1.方式一：在script中书写

![image-20220417191354123](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220417191354123.png) 

```html
<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title></title>
		<!-- 方式一：在script中书写：可以在head标签，body标签以及html标签之外 推荐放在head标签里 -->
		<script type="text/javascript">
			console.log("head内")
		</script>
	</head>
	<body>
		<script type="text/javascript">
			console.log("body内")
		</script>
	</body>
</html>
<script type="text/javascript">
	console.log("html外")
</script>
```

### 2.方式二：外部引入

![image-20220417191648046](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220417191648046.png) 

```javascript
// js文件
alert("外部引入");
```

```html
<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title></title>
		<!-- 2.方式二：外部引入  -->
		<script type="text/javascript" src="js/demo.js"></script>
	</head>
	<body>
	</body>
</html>
```



## 变量

概念:变量表示存储数据的容器

**数据类型介绍**

- 数值类型： number 
- 字符串类型： string 
- 对象类型：object 
- 布尔类型： boolean 
- 函数类型： function 

![image-20220417193625311](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220417193625311.png) 

```html
<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8">
        <title></title>
        <script type="text/javascript">
            var test = 100;
            console.log(typeof test);
            //注意：String 字符串可以双引号括起来，也可以单引号括起来 "a book of JavaScript"、'abc'、 "a"、""
            test = "100";
            console.log(typeof test);
            test = document.getElementById("body");
            console.log(typeof test);
            test = true;
            console.log(typeof test);
            test = new Function();
            console.log(typeof test);
        </script>
    </head>
    <body id="body">
    </body>
</html>
```

**特殊值**

- undefined 变量未赋初始值时，默认 undefined 
- null 空值 
- NaN Not a Number 非数值

![image-20220417194016458](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220417194016458.png) 

```html
<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8">
        <title></title>
        <script type="text/javascript">
            var test;
            console.log(test);
            console.log(typeof test);
            test = 1 + 'age';
            console.log(test);
            console.log(typeof test);
            test = null;
            console.log(test);
            console.log(typeof test);
        </script>
    </head>
    <body>
    </body>
</html>
```



## 运算符

### 算术运算符

![image-20220417194351416](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220417194351416.png) 

### 赋值运算符

![image-20220417194427526](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220417194427526.png) 

### 关系运算符

![image-20220417194516319](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220417194516319.png) 

**注意区别 == 和 ===**

 ![image-20220417195132449](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220417195132449.png)

```html
<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8">
        <title></title>
        <script type="text/javascript">
            a = "100";
            b = 100;
            // 等于： == 是简单的做字面值的比较
            console.log(a == b);
            // 全等于： === 除了做字面值的比较之外，还会比较两个变量的数据类型
            console.log(a === b)
        </script>
    </head>
    <body>
    </body>
</html>
```



### 逻辑运算符

![image-20220417194552441](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220417194552441.png) 

**注意 && 和 | | 的使用**

![image-20220417200849458](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220417200849458.png) 

```html
<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title></title>
		<script type="text/javascript">
			// 在 JavaScript 语言中，所有的变量，都可以做为一个 boolean 类型的变量去使用
			// 0 、null、 undefined、NaN、""(空串) 都认为是 false
			if(!0) console.log(0);
			if(!null) console.log(null);
			if(!undefined) console.log(undefined);
			if(!"") console.log("");
			
			// && 且运算，有两种情况 => 老韩解读(即 && 返回值是遵守短路与的机制)
			// (1)当表达式全为真的时候,返回最后一个表达式的值
			// (2)当表达式有假的时候,返回第一个为假的表达式的值
			console.log(1 && 2); // 2
			console.log(0 && null); // 0
			console.log(1 && null); // null
			// || 或运算, 有两种情况 => 老韩解读(即|| 返回值是遵守短路或的机制)
			// (1)当表达式全为假的时候，返回最后一个表达式的值
			// (2)当表达式有真的时候。返回第一个为真的表达式的值
			console.log(0 || null); // null
			console.log(1 || 2); // 1
			console.log(0 || 2); // 2
		</script>
	</head>
	<body>
	</body>
</html>
```



### 条件符运算

类似Java的三元运算符

```html
<script type="text/javascript">
    varres = 5 > 0?"hello":"ok";
    alert(res); // hello
</script>
```



## 数组

**javascript数组定义使用的4种方式**

![image-20220417210657275](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220417210657275.png) 

```html
<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8">
        <title></title>
        <script type="text/javascript">
            // 方式一
            var cars = ["byd","xd","bwm"];
            console.log(cars);
            console.log(cars[0]);

            // 方式二
            var cars2 = []; // 空数组
            cars2[0] = "byd";
            cars2[1] = "xd";
            cars2[2] = "bwm";
            console.log(cars2);

            // 方式三
            var cars3 = new Array("byd","xd","bwm");
            console.log(cars3)

            // 方式四
            var cars4 = new Array();
            cars4[0] = "byd";
            cars4[1] = "xd";
            cars4[2] = "bwm";
            console.log(cars4);
        </script>
    </head>
    <body>
    </body>
</html>
```

**数组使用和遍历**

![htnml](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220417210944067.png) 

```html
<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8">
        <title></title>
        <script type="text/javascript">
            var cars = ["byd","xd","bwm"];
            console.warn("数组长度: " + cars.length)
            for(i = 0;i< cars.length;i++){
                console.log(cars[i]);
            }
        </script>
    </head>
    <body>
    </body>
</html>
```



## 函数

### 函数概念

概念：函数是由事件驱动的，或者当它被调用时，执行的可重复使用的代码

在 js 中如果要执行函数，有两种方式 

1. 主动调用函数
2.  通过事件去触发该函数

![image-20220418143017594](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220418143017594.png) 

```html
<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8">
        <title></title>
        <script type="text/javascript">
            function f(){
                alert("调用方法f()");
            }
            // 主动调用f()
            f();
        </script>
    </head>
    <body>
        <!-- 通过按钮事件去触发该函数 -->
        <button type="button" onclick="f()">按钮</button>
    </body>
</html>
```

### 函数定义方式

方式 1: **function 关键字来定义函数**

```javascript
// 格式
function 函数名(形参列表){
    函数体
    return 表达式
}
```

![image-20220418144429728](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220418144429728.png) 

```html
<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title></title>
		<script type="text/javascript">
			function f(){
				console.log("调用方法f()");
			}
			function f2(item){
				console.log("调用方法f(item)"+item);
			}
			f();
			f2(100);
			
		</script>
	</head>
	<body>
	</body>
</html>
```

方式 2: **将函数赋给变量**

```javascript
// 格式
var 函数名 = function(形参列表){
    函数体
    return 参数列表
}
```

![image-20220418144814953](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220418144814953.png) 

```html
<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title></title>
		<script type="text/javascript">
			var f = function(){
				console.log("f()被调用")
			}
			var f2 = function(item){
				console.log("f(item)被调用")
			}
			f();
			f2(100);
			var f3 = f;
			f3();
		</script>
	</head>
	<body>
	</body>
</html>
```

**JavaScript 函数注意事项和细节**

- 如果函数的函数名相同，形参列表个数最多的会覆盖掉其他相同名字的函数

    ![image-20220418145308524](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220418145308524.png) 

    ```html
    <!DOCTYPE html>
    <html>
    	<head>
    		<meta charset="utf-8">
    		<title></title>
    		<script type="text/javascript">
    			function f(){
    				console.log("f()");
    			}
    			function f(item1){
    				console.log("f(item1)");
    			}
    			function f(item1,item2){
    				console.log("f(item1,item2)");
    			}
    			// 结果都是调用了f(item1,item2)函数
    			f();
    			f(1);
    			f(1,1);
    		</script>
    	</head>
    	<body>
    	</body>
    </html>
    ```

- 函数的 arguments 隐形参数（作用域在 function 函数内）

    - 隐形参数: 在 function 函数中不需要定义，可以直接用来获取所有参数的变量
    - 隐形参数特别像 java 的可变参数一样（例如：void fun(int... args) ）

    ![image-20220418150748312](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220418150748312.png) 

    ```html
    <!DOCTYPE html>
    <html>
    	<head>
    		<meta charset="utf-8">
    		<title></title>
    		<script type="text/javascript">
                // 不管形参是否能接收传入的参数，arguments数组会接收所有传入进来的数据
                // 如果形参个数大于传入的参数，多余的形参默认undefined
    			function f(){
    				// 遍历函数的隐形参数
    				var sum = 0;
    				for(i = 0;i < arguments.length;i++){
    					sum += arguments[i];
    				}
    				console.log(sum);
    			}
    			f(100,200,300);
    		</script>
    	</head>
    	<body>
    	</body>
    </html>
    
    ```

    函数课堂练习: 编写一个函数,用于计算所有参数相加的和并返回,如果实参不是number, 就过滤掉

    ```html
    <!DOCTYPE html>
    <html>
        <head>
            <meta charset="utf-8">
            <title></title>
            <script type="text/javascript">
                function sum(){
                    var sum = 0;
                    for(i = 0;i < arguments.length;i++){
                        if(!isNaN(arguments[i])){
                            sum += arguments[i];
                        }
                    }
                    alert(sum);
                }
                sum(25,54,65,98,52,41,51,-5,0,"asd");
            </script>
        </head>
        <body>
        </body>
    </html>
    ```




## 自定义对象

自定义对象方式 1：Object 形式

```javascript
// 格式
var 对象 = new Object();
对象名.属性名 = 值;
对象名.函数名 = function();
```

```html
<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title></title>
		<script type="text/javascript">
             // person 是一个空对象，没有自定义的函数和属性
			var person = new Object();
			person.name = "罗念笙";
			person.eat = function(){
				console.log("eating");
			}
			person.eat();
		</script>
	</head>
	<body>
	</body>
</html>

```

自定义对象方式 2：{} 形式

```javascript
var 对象名 = { 
    属性名：值, // 属性名：值;注意有逗号间隔
    函数名：function(){} // 定义函数 
};
```

```html
<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title></title>
		<script type="text/javascript">
			var person = {     
				name:"张洛融", 
				run:function(){
					alert("running")
				} 
			}
			console.log(person.name);
			person.run();
		</script>
	</head>
	<body>
	</body>
</html>
```



## 事件

概念:事件是电脑输入设备与页面进行交互的响应 (事件通常与函数配合使用)

### 常见的事件

|    事件     |             描述             |
| :---------: | :--------------------------: |
|  onchange   |      HTML 元素已被改变       |
|   onclick   |     用户点击了 HTML 元素     |
| onmouseover | 用户把鼠标移动到 HTML 元素上 |
| onmouseout  |   用户把鼠标移开 HTML 元素   |
|  onkeydown  |       用户按下键盘按键       |
|   onload    |    浏览器已经完成页面加载    |
|   onblur    |         元素失去焦点         |

### 事件分类

事件注册(绑定)：当事件响应(触发)后要浏要览器执行哪些操作代码，叫 事件注册或事件绑定

静态注册事件:  通过 html 标签的事件属性直接赋于事件响应后的代码，这种方式叫 静态注册

![image-20220418163927623](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220418163927623.png) '

```html
<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title></title>
		<script type="text/javascript">
			function f(){
				console.log("f()被调用")
			}
		</script>
	</head>
	<body>
		<!-- 静态注册onclick="f()" -->
		<button type="button" onclick="f()">按钮</button>
	</body>
</html>
```

动态注册事件: 通过 js 代码得到标签的 dom 对象，然后再通过 dom 对象.事件名 = function(){} 这种形式叫 动态注册

```html
<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title></title>
		<script type="text/javascript">
			// 在js中,将页面窗口映射成window dom对象（window 就是动态注册的dom对象）
			// window.onload 表示页面被加载完毕,可以取到dom对象d
			window.onload = function(){
				// function函数内的代码 表示加载完毕后要执行
				// 简单的来说就是执行的顺序：先加载完所有代码，然后再执行当前函数内的代码
				var btn01 = document.getElementById("btn");
				btn01.onclick = function(){
					alert("点击按钮");
				}
			}
		</script>
	</head>
	<body>
		<button type="button" id="btn">按钮</button>
	</body>
</html>
```

**练习表单提交事件**

![image-20220418174434011](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220418174434011.png) 

```html
<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title></title>
		<script type="text/javascript">
			window.onload = function(){
				var from = document.getElementById(form);
				form.onsubmit = function(){
					if(form.text.value.length <  4 || form.text.value.length > 6){
						alert("用户名不正确");
						return false;
					}
					if(form.pwd1.value.length != 6){
						alert("密码不正确");
						return false;
					}
					if(form.pwd2.value.length != 6){
						alert("确认密码不正确");
						return false;
					}
					if(form.pwd1.value != form.pwd2.value){
						alert("密码和确认密码不相同");
						return false;
					}
					
					var emailPattern = /^[\w-]+@([a-zA-Z]+\.)+[a-zA-Z]+$/;
					if(!(emailPattern.test(form.email.value))){
						alert("电子邮件格式不匹配");
						return false;
					}	
				}
			}
		</script>
	</head>
	<body>
		<table align="center">
			<form action="404.html" method="get" id="form">
				<tr><th colspan="2">注册用户</th></tr>
				<tr>
					<td>用户名</td>
					<td><input type="text" name="text"/></td>
				</tr>
				<tr>
					<td>密码</td>
					<td><input type="password" name="pwd1"/></td>
				</tr>
				<tr>
					<td>确认</td>
					<td><input type="password" name="pwd2"/></td>
				</tr>
				<tr>
					<td>邮箱</td>
					<td><input type="text" name="email"/></td>
				</tr>
				<tr align="center">
					<td colspan="2"><input type="submit" value="注册用户" /></td>
				</tr>
			</form>
		</table>
	</body>
</html>
```



# DOM

## 基本概念

[W3school在线教程](https://www.w3school.com.cn/js/js_htmldom.asp)

DOM 全称是 Document Object Model **文档对象模型**

![image-20220418194422808](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220418194422808.png) 

当网页被加载时，浏览器会创建页面的文档对象模型

![image-20220418194536452](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220418194536452.png) 



## document 对象

document 它是一种树结构的文档,有层级关系 在 dom 中把所有的标签都对象化

**document 常用方法**

![image-20220418194949220](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220418194949220.png) 

**getElementById**

![image-20220418195947100](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220418195947100.png) 

```HTML
<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title></title>
		<script type="text/javascript">
		window.onload = function(){
			var name = document.getElementById("name");
			name.onclick = function(){
				console.log(name.innerText); // 罗念笙
				console.log(name.innerHTML); // <i>罗念笙</i>
			}
		}
		</script>
	</head>
	<body>
		<h1 id="name"><i>罗念笙</i></h1>
	</body>
</html>
```

**getElementsByName**

![image-20220418201901564](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220418201901564.png) 

```html
<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title></title>
		<script type="text/javascript">
			window.onload = function(){
                 // 注意：getElementsByName中传入的值需要带引号
				var btn1 = document.getElementById("btn1");
				var btn2 = document.getElementById("btn2");
				var btn3 = document.getElementById("btn3");
				var sports = document.getElementsByName("sport");
				btn1.onclick = function(){
					for(i = 0;i < sports.length;i++){
						sports[i].checked = !sports[i].checked;
					}
				}
				btn2.onclick = function(){
					for(i = 0;i < sports.length;i++){
						sports[i].checked = true;
					}
				}
				btn3.onclick = function(){
					for(i = 0;i < sports.length;i++){
						sports[i].checked = false;
					}
				}
			}
		</script>
	</head>
	<body>
		<input type="checkbox" name="sport" id="" value="soccer" />足球
		<input type="checkbox" name="sport" id="" value="basketball" />篮球
		<input type="checkbox" name="sport" id="" value="volleyball" />排球
		<br/>
		<button type="button" id="btn1">反选</button>
		<button type="button" id="btn2">全选</button>
		<button type="button" id="btn3">全不选</button>
	</body>
</html>
```

**createElement**

![image-20220419150907622](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220419150907622.png) 

```html
<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title></title>
		<script type="text/javascript">
			window.onload = function(){
				var btn = document.getElementById("btn01");
				btn.onclick = function(){
					// 添加图片标签
					var img = document.createElement("img");
					img.src = "./imgs/1.png";
					img.width = 100;
					document.body.appendChild(img);
				}
			}
		</script>
	</head>
	<body>
		<input type="button" id="btn01" value="按钮" />
	</body>
</html>
```



## HTML DOM节点

[W3school文档](https://www.w3school.com.cn/jsref/dom_obj_all.asp)

在 HTML DOM（文档对象模型）中，每个部分都是节点

- 文档本身是文档节点
- 所有 HTML 元素是元素节点
- 所有 HTML 属性是属性节点
- HTML 元素内的文本是文本节点
- 注释是注释节点

**实战练习**

![image-20220419161911992](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220419161911992.png)

```css
/* .css文件 */
@CHARSET "UTF-8";

body {
	width: 800px;
	margin-left: auto;
	margin-right: auto;
	韩顺平 Java 工程师
}

button {
	width: 200px;
	margin-bottom: 10px;
	text-align: left;
}

#btnList {
	float: left;
}

#total {
	width: 450px;
	float: left;
}

ul {
	list-style-type: none;
	margin: 0px;
	韩顺平 Java 工程师 padding: 0px;
}

.inner li {
	border-style: solid;
	border-width: 1px;
	padding: 5px;
	margin: 5px;
	float: left;
}

.inner {
	width: 400px;
	border-width: 1px;
	margin-bottom: 10px;
	padding: 10px;
	float: left;
}
```

```html
<!DOCTYPE html>
<html>
	<head>
		<meta charset="UTF-8">
		<title>演示 HTML DOM 相关方法</title>
		<link rel="stylesheet" type="text/css" href="./css/test.css" />
		<script type="text/javascript">
			window.onload = function(){
				// 查找 id=java 节点
				var btn1 = document.getElementById("btn01");
				btn1.onclick = function(){
					console.log("查找 id = java的节点");
					var java = document.getElementById("java");
					console.log(java.innerText);
				}
				
				// 查找所有 option 节点
				var btn2 = document.getElementById("btn02");
				btn2.onclick = function(){
					console.log("查找所有 option 节点");
					var optionAll = document.getElementsByTagName("option");
					for(i = 0;i < optionAll.length;i++){
						console.log(optionAll[i].innerText);
					}
				}
				
				// 查找 name=sport 的节点
				var btn3 = document.getElementById("btn03");
				btn3.onclick = function(){
					console.log("查找 name=sport 的节点");
					var sports = document.getElementsByName("sport");
					for(i = 0;i < sports.length;i++){
						console.log(sports[i].value);
					}
				}
				
				// 查找 id=language 下所有li节点
				var btn4 = document.getElementById("btn04");
				btn4.onclick = function(){
					console.log("查找 id=language 下所有li节点");
					var liAll = document.getElementById("language").getElementsByTagName("li");
					for(i = 0;i < liAll.length;i++){
						console.log(liAll[i].innerText);
					}
				}
				
				// 返回 id=sel01 的所有子节点
				var btn5 = document.getElementById("btn05");
				btn5.onclick = function(){
					console.log("返回 id=sel01 的所有子节点");
					var sel01_Child = document.getElementById("sel01").childNodes;
					for(i = 0;i < sel01_Child.length;i++){
						console.log(sel01_Child[i].innerText); // 11 个子节点
					}
				}
				
				// 返回 id=sel01 的第一个子节点
				var btn6 = document.getElementById("btn06");
				btn6.onclick = function(){
					console.log("返回 id=sel01 的第一个子节点");
					var sel01_First_Child = document.getElementById("sel01").childNodes;
					console.log(sel01_First_Child.firstChild); // undefined 
				}
				
				// 返回 id=java 的父节点
				var btn7 = document.getElementById("btn07");
				btn7.onclick = function(){
					console.log("返回 id=java 的父节点");
					var java_Parent = document.getElementById("java").parentElement;
					console.log(java_Parent);
				}
				
				// 返回 id=ct 的前后兄弟节点
				var btn8 = document.getElementById("btn08");
				btn8.onclick = function(){
					console.log("返回 id=ct 的前后兄弟节点");
					// previousSibling属性，获取当前节点的上一个节点(前一个)
					var ct_Brother = document.getElementById("ct").previousSibling;
					console.log(ct_Brother.innerText); // undefined 
					// nextSibling属性，获取当前节点的下一个节点(后一个)
					var ct_Brother = document.getElementById("ct").nextSibling;
					console.log(ct_Brother.innerText); // undefined 
				}
				
				// 读取 id=ct 的 value 属性值
				var btn9 = document.getElementById("btn09");
				btn9.onclick = function(){
					console.log("读取 id=ct 的 value属性值");
					var ct_Value = document.getElementById("ct");
					console.log(ct_Value.value);
				}
				
				// 设置 #person 的文本域
				var btn10 = document.getElementById("btn10");
				btn10.onclick = function(){
					console.log("设置 #person 的文本域");
					var person = document.getElementById("person");
					person.value = "大家好呀，我是小笙";
					console.log(person.value);
				}
				
			}
		</script>
	</head>
	<body>
		<div id="total">
			<div class="inner">
				<P> 你会的运动项目： </P> 
				<input type="checkbox" name="sport" value="zq" checked="checked">足球 
				<input type="checkbox" name="sport" value="tq">台球 
				<input type="checkbox" name="sport" value="ppq">乒乓球
				<br />
				<hr />
				<P> 你当前女友是谁： </P> <select id="sel01">
					<option>---女友---</option>
					<option>艳红</option>
					<option id="ct" value="春桃菇凉">春桃</option>
					<option>春花</option>
					<option>桃红</option>
				</select>
				<hr />
				<p> 你的编程语言? </p>
				<ul id="language">
					<li id="java">Java</li>
					<li>PHP</li>
					<li>C++</li>
					<li>Python</li>
				</ul> <br> <br>
				<hr />
				<p> 个人介绍: </p> <textarea name="person" id="person">个人介绍</textarea>
			</div>
		</div>
		<div id="btnList">
			<div><button id="btn01">查找 id=java 节点</button> </div>
			<div><button id="btn02">查找所有 option 节点</button> </div>
			<div><button id="btn03">查找 name=sport 的节点</button> </div>
			<div><button id="btn04">查找 id=language 下所有 li 节点</button> </div>
			<div><button id="btn05">返回 id=sel01 的所有子节点</button> </div>
			<div><button id="btn06">返回 id=sel01 的第一个子节点</button> </div>
			<div><button id="btn07">返回 id=java 的父节点</button></div>
			<div><button id="btn08">返回 id=ct 的前后兄弟节点</button> </div>
			<div><button id="btn09">读取 id=ct 的 value 属性值</button> </div>
			<div><button id="btn10">设置#person 的文本域</button> </div>
		</div>
	</body>
</html>

```



## XML DOM

### 概述

[W3school在线教程](https://www.w3school.com.cn/xml/index.asp)

概念：可扩展标记语言

**XML技术可以用于解决什么问题**

- 解决程序间数据传输的问题 => json
- xml现在主要用来做配置文件(比如我们的tomcat服务器的server.xml，web.xml )
- xml可以充当小型的数据库 => 程序自己的数据格式存放

```xml
<?xml version="1.0" encoding="utf-8" ?>
<!-- 
    xml dom
	文档声明
    xml 表示xml文件
    version 表示版本
    encoding 表示文件编码
 -->
<!--
    students 根目录
    <student></student> 表示子元素
    name，gender，sge 属性
-->
<students>
    <student id="01">
        <name>tom</name>
        <gender>男</gender>
        <sge>18</sge>
    </student>
    <student id="02">
        <name>marry</name>
        <gender>女</gender>
        <sge>28</sge>
    </student>
</students>
<!--
    元素语法要求
    每个XML文档必须有且只有一个根元素
    根元素是一个完全包括文档中其他所有元素的元素
 	一个标签中也可以嵌套若干子标签。但所有标签必须合理的嵌套，绝对不允许交叉嵌套
-->
```

**XML 元素命名规则**

- 区分大小写
- 不能以数字开头
- 不能包含空格
- 名字中间不能包含冒号
- 如果标签需要间隔，建议使用下划线



### CDATA 节

概念：有些内容不想让解析引擎执行，而是当作原始内容处理(即当做普通文本)，可 以使用 CDATA 包括起来，CDATA 节中的所有字符都会被当作简单文本，而不是 XML 标记

```xml
<?xml version="1.0" encoding="UTF-8" ?>
<students>
    <student id="01">
        <name>tom</name>
        <gender>男</gender>
        <sge>18</sge>
    </student>
    <code> 
        <!-- 如果希望把某些字符串,当做普通文本，使用 CDATA 包括 --> 
        <![CDATA[ 
            <script data-compress=strip> 
            function h(obj){ 
                obj.style.behavior='url(#default#homepage)'; 
                var a = obj.setHomePage('//www.baidu.com/');
            }
            </script>
        ]]> 
    </code>
</students>
```



### 转义字符

![image-20220420143458974](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220420143458974.png) 



### DOM4j

[DOM4j在线文档](https://dom4j.github.io/javadoc/1.6.1/)

概念：Dom4j 是一个简单、灵活的开放源代码的库(用于解析/处理 XML 文件)。Dom4j 是由早期 开发 JDOM 的人分离出来而后独立开发的

Dom4j 是一个非常优秀的 Java XML API，具有性能优异、功能强大和极易使用的特点。 现在很多软件采用的 Dom4j

**测试代码**

```java
public class dom4j {
    public static void main(String[] args) throws DocumentException {
        // 创建一个解析器
        SAXReader reader = new SAXReader();
        Document document = reader.read(new File("src/student.xml")); // XML Document
        System.out.println();
    }
}
```

**debug生成document树**

![](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220420150630250.png)

**使用 DOM4J 对 students.xml 文件进行增删改查**

#### 查找/获取

```java
public class dom4j {
    public static void main(String[] args) throws DocumentException {
        // 创建一个解析器
        SAXReader reader = new SAXReader();
        Document document = reader.read(new File("src/student.xml")); // XML Document
        // 得到rootElement
        Element rootElement = document.getRootElement();
        // 得到rootElement中students元素
        List<Element> students = rootElement.elements("student");
        for (Element student:students
             ) {
            Element name = student.element("name");
            Element gender = student.element("gender");
            Element age = student.element("age");
            // 获取属性id
            String id = student.attributeValue("id");
            System.out.println(id);
            System.out.println(name.getText()+" "+gender.getText()+" "+age.getText()); // tom 男 18 \n marry 女 28
        }
    }
}
```

#### 增加元素

```java
public class Dom4jAddElement {
    public static void main(String[] args) throws DocumentException, IOException {
        // 得到解析器
        SAXReader saxReader = new SAXReader();
        Document document = saxReader.read(new File("src/student.xml"));
        // 首先我们来创建一个学生节点对象
        Element newStu = DocumentHelper.createElement("student");
        Element newStu_name = DocumentHelper.createElement("name");
        Element newStu_intro = DocumentHelper.createElement("resume");
        Element newStu_age = DocumentHelper.createElement("age");
        // 如何给元素添加属性
        newStu.addAttribute("id", "03");
        newStu_name.setText("jack");
        newStu_age.setText("23");
        newStu_intro.setText("计算机大佬");
        // 把三个子元素（节点）加到 newStu 下
        newStu.add(newStu_name);
        newStu.add(newStu_age);
        newStu.add(newStu_intro);
        // 再把 newStu 节点加到根元素
        document.getRootElement().add(newStu);
        
        // 直接输出会出现中文乱码
        OutputFormat output = OutputFormat.createPrettyPrint();
        // 设置编码 utf-8
        output.setEncoding("utf-8");
        // 更新 xml 文件
        // 使用到 io 编程 FileOutputStream 就是文件字节输出流
        XMLWriter writer = new XMLWriter( new FileOutputStream(new File("src/student.xml")), output);
        writer.write(document);
        writer.close();
        System.out.println("添加成功~");
    }
}
```

#### 删除元素

```java
public class Dom4jDeleteElement {
    public static void main(String[] args) throws DocumentException, IOException {
        // 得到解析器
        SAXReader saxReader = new SAXReader();
        Document document = saxReader.read(new File("src/student.xml"));
        // 找到该元素第三个学生
        Element stu = (Element) document.getRootElement().elements("student").get(2);
        // 删除元素
        stu.getParent().remove(stu);
        // 删除元素的某个属性
        stu.remove(stu.attribute("id"));
        
        // 直接输出会出现中文乱码
        OutputFormat output = OutputFormat.createPrettyPrint();
        // 设置编码 utf-8
        output.setEncoding("utf-8");
        // 更新 xml 文件
        XMLWriter writer = new XMLWriter( new FileOutputStream(new File("src/student.xml")), output);
        writer.write(document); writer.close();
        System.out.println("删除成功~");
    }
}
```

#### 更新元素

```java
public class Dom4jUpdateElement {
    public static void main(String[] args) throws DocumentException, IOException {
        // 得到解析器
        SAXReader saxReader = new SAXReader();
        Document document = saxReader.read(new File("src/student.xml"));
        // 得到所有学生的年龄
        List<Element> students = document.getRootElement().elements("student");
        // 遍历, 所有的学生元素的 age + 3
        for (Element student : students)
        {
            Element age = student.element("age");
            age.setText((Integer.parseInt(age.getText()) + 3) + "");
        }

        // 直接输出会出现中文乱码
        OutputFormat output = OutputFormat.createPrettyPrint();
        // 设置编码 utf-8
        output.setEncoding("utf-8");
        // 更新 xml 文件
        XMLWriter writer = new XMLWriter( new FileOutputStream(new File("src/student.xml")), output);
        writer.write(document); writer.close();
        System.out.println("更新成功~");
    }
}
```














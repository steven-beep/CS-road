# css

---

## 基础概念

[W3school学习文档](https://www.w3school.com.cn/css/index.asp)

概念：层叠样式表 (Cascading Style Sheets)'

![image-20220416153133571](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220416153133571.png) 

```html
<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title></title>
         <!-- CSS样式 -->
		<style type="text/css">
			div{
				color: aqua;
			}
		</style>
	</head>
	<body>
		<div>hello,CSS~</div>
	</body>
</html>
```



## 字体样式

![image-20220416154942114](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220416154942114.png) 

```html
<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8">
        <title></title>
        <!-- font-size: 指定大小，可以按照像素大小 -->
        <!-- font-weight : 指定是否粗体 -->
        <!-- font-family : 指定类型 -->
        <style type="text/css">
            div{
                font-size: 20px;
                font-family: 华文新魏;
                font-weight: bold;
            }
        </style>
    </head>
    <body>
        <div>font</div>
    </body>
</html>
```



## 文本居中

![image-20220416160308205](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220416160308205.png) 

```html
<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title></title> 
		<style type="text/css">
			div{
				border: 2px solid black;
				height: 200px;
				width: 200px;
				/* 指的是div块居中 */
				margin-left: auto;
				margin-right: auto;
				/* 文本居中 */
				text-align: center;
			}
		</style>
	</head>
	<body>
		<div>div-center</div>
	</body>
</html>
```



## 超链接去下划线

![image-20220416160714087](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220416160714087.png) 

```html
<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8">
        <title></title>
        <style type="text/css">
            a{
                text-decoration: none;
                color: #00FFFF;
            }
        </style>
    </head>
    <body>
        <a href="http://www.baidu.com">百度</a>
    </body>
</html>
```



## 无序列表去掉样式

![image-20220416161413067](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220416161413067.png) 

```html
<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8">
        <title></title>
        <style type="text/css">
            ol{
                list-style: none;
            }
        </style>
    </head>
    <body>
        <ol>
            <li>1</li>
            <li>2</li>
            <li>3</li>
            <li>4</li>
        </ol>
    </body>
</html>
```



## 三种方式

- 在标签的 style 属性上设置 CSS 样式

- 在 head 标签中，使用 style 标签来定义需要的 CSS 样式

- 把 CSS 样式写成单独的 CSS 文件，再通过 link 标签引入

![image-20220416162024177](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220416162024177.png) 

```html
<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title>三种方式</title>
		<link rel="stylesheet" type="text/css" href="css/mycss.css"/>
		<style type="text/css">
			span{
				color: #00FFFF;
			}
		</style>
	</head>
	<body>
		<div style="color: black;">方式一</div>
		<span>方式二</span>
		<p>方式三</span>
	</body>
</html>
```

```css
<!-- 方式三（推荐使用） -->
p{
	color: red;
}
```



## 选择器

### 元素选择器

概念：CSS 元素/标签选择器通常是某个 HTML 元素， 比如 p、h1、a div 等

![image-20220416162557267](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220416162557267.png) 

```html
<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title></title>
		<style type="text/css">
			p{
				color: #FF0000;
			}
			h1{
				color: #000000;
			}
			a{
				text-decoration: none;
			}
			div{
				color: aqua;
			}
		</style>
	</head>
	<body>
		<p>p</p>
		<h1>h1</h1>
		<a href="http://www.baidu.com">百度</a>
		<div>div</div>
	</body>
</html>
```

### ID 选择器

![image-20220416162930009](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220416162930009.png) 

```html
<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8">
        <title></title>
        <style type="text/css">
            /* id 选择器以 "#" 来定义 */
            #div1{
                color: #FF0000;
            }
            #div2{
                color: aqua;
            }
        </style>
    </head>
    <body>
        <!-- id 选择器可以为标有特定 id 的 HTML 元素指定特定的样式 -->
        <!-- id 是唯一的，不能重复 -->
        <div id="div1">
            div1
        </div>
        <div id="div2">
            div2
        </div>
    </body>
</html>
```

### class 选择器

![image-20220416163235371](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220416163235371.png) 

```HTML
<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title></title>
		<style type="text/css">
			/* .类选择器名称 */
			.class{
				color: #000000;
			}
		</style>
	</head>
	<body>
		<!-- 使用 class 选择器，需要在被修饰的元素上，设置 class 属性,属性值程序员指定 -->
		<!-- class 属性的值，可以重复 -->
		<div class="class">div1</div>
		<p class="class">div2</p>
	</body>
</html>
```

### 组合选择器

![image-20220416164108578](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220416164108578.png) 

```html
<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title></title>
		<style type="text/css">
			#div,.class{
				color: #FF0000;
			}
		</style>
	</head>
	<body>
		<div id="div">ID_div</div>
		<div>div</div>
		<div class="class">CLASS_div</div>
	</body>
</html>
```



### 优先级

行内样式 > ID 选择器> class选择器 > 元素选择器

```html
<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8">
        <title></title>
        <style type="text/css">
            div{
                color: #00FFFF;
            }
            #ID{
                color: #FF0000;
            }
            .class{
                color: antiquewhite;
            }
        </style>
    </head>
    <body>
        <!-- 优先级:行内样式 > ID 选择器> class选择器 > 元素选择器 -->
        <div style="color: #000000;" id="ID" class="class">test</div>
    </body>
</html>
```


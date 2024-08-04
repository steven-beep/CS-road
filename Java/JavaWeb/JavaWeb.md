# Tomcat

[Tomcat在线教程](https://tomcat.apache.org/tomcat-8.0-doc/)

**JavaWeb 开发技术栈图**

![image-20220421185821389](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220421185821389.png) 



## 概述

### BS 与 CS 开发介绍

![image-20220421193359742](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220421193359742.png) 

(1) 兼容性 , 浏览器的种类很多
(2) 安全性, 通常情况下，BS 安全性不如 CS 好控制 
(3) 易用性, BS 好于 CS, 浏览器方便在线使用
(4) 扩展性, BS 相对统一，只需要写 Server

### 常用服务器

1. Tomcat：由 Apache 组织提供的一种 Web 服务器，提供对 jsp 和 Servlet 的支持。它 是一种轻量级的 javaWeb 容器（服务器），也是当前应用最广的 JavaWeb 服务器（免费），Tomcat 本质就是一个 Java 程序, 但是这个 Java 程序可以处理来自浏览器的 HTTP 请求

    [Tomcat下载网址](http://tomcat.apache.org/)

2. Jboss：是一个遵从 JavaEE 规范的、它支持所有的 JavaEE 规范（免费）

3. GlassFish： 由 Oracle 公司开发的一款 JavaWeb 服务器，是一款商业服务器，达到产品级质量（应用很少）

4. Resin：是 CAUCHO 公司的产品，是一个非常流行的服务器，对 servlet 和 JSP 提供了 良好的支持， 性能也比较优良（收费）

1. WebLogic：是 Oracle 公司的产品，支持 JavaEE 规范， 而且不断的完善以适 应新的开发要求，适合大型项目（收费，用的不多，适合大公司）

### Tomcat 目录结构

![image-20220422164147589](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220422164147589.png) 

![image-20220422164414505](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220422164414505.png) 

启动Tomacat会默认打开index.html的原因？

```xml
<!-- web.xml -->
<!-- 默认查找根目录下的index.html -> index.htm -> index.jsp -->
<welcome-file-list>
    <welcome-file>index.html</welcome-file>
    <welcome-file>index.htm</welcome-file>
    <welcome-file>index.jsp</welcome-file>
</welcome-file-list>
```



## Web应用

 Tomcat 服务中部署 WEB 应用

概念：Web应用通常也称之为web应用程序（网站），WEB应用是多个web资源的集合  

组成

![image-20220422172300345](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220422172300345.png) 

在Tomcat 下的 conf 目录\Catalina\localhost\ 下,配置文件，比如XXX.xml(提醒：通过Tomcat配置，可以把一个web应用，映射到指定的目录，可以解决磁盘空间分配问题

```xml
<?xml version="1.0" encoding="utf-8"?>
<!-- Context 表示一个工程上下文 path表示工程的访问路径：/XXX dosBase表示目标工程位置 -->
<Context path:"/XXX" docBase="E:\Java\Java_software">
```



## 浏览器请求资源过程

![image-20220422233427103](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220422233427103.png) 

注意：http://localhost , 默 认 是 访 问 80 端 口 , 即 http://localhost 等 价 http://localhost:80



## IDEA 开发 JavaWeb 注意事项

1.热加载选项说明

![image-20220423160116209](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220423160116209.png) 

2.修改端口，只会影响当前的项目，但是不会去修改tomcat文件中server.xml文件的端口

3.当tomcat启动时，会生成out目录，该目录就是原项目资源的映射，我们浏览器访问的资源是 out 目录



## Maven

### 基本介绍

概述：一个项目管理工具，可以对 Java 项目进行构建、依赖管理

![image-20220428232713295](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220428232713295.png) 

### IDEA创建Maven项目说明

![image-20220428233851277](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220428233851277.png) 

![image-20220428234453569](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220428234453569.png) 

### pom.xml文件说明

![image-20220429164418392](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220429164418392.png) 

```xml
<dependencies>
    <!--
      1. dependency 表示依赖, 也就是我们这个项目需要依赖的jar包
      2. groupId 和 artifactId 被统称为坐标, 是为了去定位这个项目/jar
      3. groupId: 一般是公司比如:com.baidu , 这里是 javax.servlet
      4. artifactId 一般是项目名, 这里是javax.servlet-api
      5. version 表示你引入到我们项目的jar包的版本是 3.1.0
      6. scope: 表示作用域，也就是你引入的 jar 包的作用范围
        6.1.provided 表示在tomcat服务器中有这个jar包，因此在编译或者测试使用，但是在打包发布就不用要带上该jar包
    -->
    <dependency>
      <groupId>javax.servlet</groupId>
      <artifactId>javax.servlet-api</artifactId>
      <version>3.1.0</version>
      <scope>provided</scope>
    </dependency>
  </dependencies>
```



## 实现Tomcat底层机制

### 框架图

![image-20220430230402155](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220430230402155.png) 

### 实现案例

#### 题目要求

- 可以访问静态资源addSum.html

    ![image-20220430230514287](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220430230514287.png) 

- 可以通过提交按钮，跳转到求和解结果

    ![image-20220430230635344](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220430230635344.png) 

**文件目录说明**

![image-20220430231547050](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220430231547050.png) 

#### xml文件

```xml
<?xml version="1.0" encoding="UTF-8" ?>
<myTomcat>
  <myServlet>
    <Servlet-name>myTomcat</Servlet-name>
    <Servlet-class>com.al_tair.myTomcat.myServlet.CalServlet</Servlet-class>
  </myServlet>
  <myServlet-mapping>
    <Servlet-name>myTomcat</Servlet-name>
    <url-pattern>/myTomcat</url-pattern>
  </myServlet-mapping>
</myTomcat>
```

#### 静态资源

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Title</title>
</head>
<body>
<form action="http://localhost:9999/myTomcat" method="get">
    <h1>求和</h1>
    第一个数字:<input type="text" name="firstNum"><br>
    第二个数字:<input type="text" name="secondName"><br>
    <button type="submit">提交</button>
</form>
</body>
</html>
```

#### 网络监听

```java
public class Connector {
    // 存放<name,Servlet实例>
    public static final ConcurrentHashMap<String, MyHttpServlet>
            nameToServlet = new ConcurrentHashMap<>();

    // 存放<urlPattern,name>
    public static final ConcurrentHashMap<String, String>
            urlToName = new ConcurrentHashMap<>();

    public static void main(String[] args) throws IOException, InterruptedException {

        // 在端口9999监听
        ServerSocket serverSocket = new ServerSocket(9999);

        while(!serverSocket.isClosed()){
            init();
            // 创建套接字 socket
            System.out.println("listening...");
            Socket socket = serverSocket.accept();
            RequestHandler rh = new RequestHandler(socket);
            new Thread(rh).start();
        }
    }
    
    public static void init(){
        String path = Connector.class.getResource("/").getPath();
        SAXReader saxReader = new SAXReader();
        try {
            Document document = saxReader.read(new File(path + "web.xml"));
            // 得到根元素
            Element rootElement = document.getRootElement();
            // 得到根元素下的所有元素
            List<Element> myServlet = rootElement.elements();
            for (Element element: myServlet
                 ) {
                if("myServlet".equalsIgnoreCase(element.getName())){
                    Element element1 = element.element("Servlet-name");
                    Element element2 = element.element("Servlet-class");
                    nameToServlet.put(element1.getText(),(MyHttpServlet)Class.forName(element2.getText()).newInstance());
                }else if("myServlet-mapping".equalsIgnoreCase(element.getName())){
                    Element element1 = element.element("Servlet-name");
                    Element element2 = element.element("url-pattern");
                    urlToName.put(element2.getText(),element1.getText());
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
```

#### 线程处理请求和响应

```java
public class RequestHandler implements Runnable{
    private Socket socket = null;

    public RequestHandler(Socket socket) {
        this.socket = socket;
    }

    @Override
    public void run() {
        MyHttpRequest Request = null;
        MyHttpResponse Response = null;
        try {
            Request = new MyHttpRequest(socket.getInputStream());
            Response = new MyHttpResponse(socket.getOutputStream());
            String uri = Request.getUri();
            System.out.println(uri);
            String path = RequestHandler.class.getResource("/").getPath();
            if(Connector.urlToName.containsKey(uri)){
                String name = Connector.urlToName.get(uri);
                if(Connector.nameToServlet.containsKey(name)){
                    MyHttpServlet myHttpServlet = Connector.nameToServlet.get(name);
                    try {
                        myHttpServlet.service(Request,Response);
                    } catch (Exception e) {
                        e.printStackTrace();
                    }
                }else{
                    OutputStream outputStream = Response.getOutputStream();
                    int index = uri.indexOf(".");
                    if(uri.substring(index+1).equalsIgnoreCase("html")){
                        try {
                            FileReader fileReader = new FileReader(path + "/static" + uri);
                            BufferedReader br = new BufferedReader(fileReader);
                            String str = "";
                            outputStream.write(Response.getResponseHeader().getBytes());
                            while((str = br.readLine()) != null){
                                outputStream.write(str.getBytes());
                            }
                            outputStream.flush();
                            outputStream.close();
                        } catch (Exception e) {
                            e.printStackTrace();
                        }
                    }else{
                        outputStream.write((Response.responseHeader + "<h1>404,没有找到该资源</h1>").getBytes());
                        outputStream.flush();
                        outputStream.close();
                    }
                }
            }else{
                OutputStream outputStream = Response.getOutputStream();
                int index = uri.indexOf(".");
                if(uri.substring(index+1).equalsIgnoreCase("html")){
                    try {
                        FileReader fileReader = new FileReader(path + "/static" + uri);
                        BufferedReader br = new BufferedReader(fileReader);
                        String str = "";
                        outputStream.write(Response.getResponseHeader().getBytes());
                        while((str = br.readLine()) != null){
                            outputStream.write(str.getBytes());
                        }
                        outputStream.flush();
                        outputStream.close();
                    } catch (Exception e) {
                        e.printStackTrace();
                    }
                }else{
                    outputStream.write((Response.responseHeader + "<h1>404,没有找到该资源</h1>").getBytes());
                    outputStream.flush();
                    outputStream.close();
                }
            }
            socket.close();
        } catch (IOException e) {
            throw new RuntimeException();
        }
    }
}

```

#### 请求类和响应类

```java
/**
 * 封装http请求数据简化
 */
public class MyHttpRequest {
    private String uri;
    private String method;
    private HashMap<String,String> parameters = new HashMap<>();
    private InputStream inputStream = null;

    public MyHttpRequest(InputStream inputStream) {
       this.inputStream = inputStream;
       init();
    }

    public String getUri() {
        return uri;
    }

    public String getMethod() {
        return method;
    }

    public void init(){
        try {
            // 将字节流转换成字符流，方便读取数据
            BufferedReader bufferedReader =
                    new BufferedReader(new InputStreamReader(inputStream, "utf-8"));
            String request = bufferedReader.readLine();
            String[] requestLine = request.split(" ");
            // GET /servlet?name=18 HTTP/1.1
            method = requestLine[0];
            int index = requestLine[1].indexOf("?");
            if(index == -1){
                // uri后面没有数据
                uri = requestLine[1];
            }else{
                uri = requestLine[1].substring(0,index);
                String parameter = requestLine[1].substring(index+1);
                String[] params = parameter.split("&");
                if(parameter != null && !params.equals("")){
                    for (String param:params
                    ) {
                        String[] split = param.split("=");
                        if(split.length == 2){
                            parameters.put(split[0],split[1]);
                        }
                    }
                }
            }
        }catch (IOException e){
            throw new RuntimeException();
        }
    }

    public String Parameter(String name){
        if(parameters.containsKey(name)){
            return parameters.get(name);
        }else{
            return null;
        }
    }
}

/**
 * http响应头封装简化
 */
public class MyHttpResponse {
    private OutputStream outputStream = null;
    public String responseHeader = "HTTP/1.1 200OK\r\n" +
            "Content-Type:text/html;charset=utf-8\r\n\r\n";

    public MyHttpResponse(OutputStream outputStream) {
        this.outputStream = outputStream;
    }

    public OutputStream getOutputStream() {
        return outputStream;
    }

    public String getResponseHeader() {
        return responseHeader;
    }
}
```

#### Servlet接口实现

```java
// Servlet接口
public interface MyServlet {
    void init() throws Exception;
    void service(MyHttpRequest var1, MyHttpResponse var2) throws Exception;
    void destroy();
}

// 抽象类
public abstract class MyHttpServlet implements MyServlet{
    @Override
    public void service(MyHttpRequest request, MyHttpResponse response) throws Exception {
        if("GET".equals(request.getMethod())){
            this.doGet(request,response);
        }else if("POST".equals(request.getMethod())){
            this.doPost(request,response);
        }
    }

    @Override
    public void init() throws Exception {

    }

    @Override
    public void destroy() {

    }

    public abstract void doGet(MyHttpRequest request, MyHttpResponse response);

    public abstract void doPost(MyHttpRequest request, MyHttpResponse response);
}

// Servlet资源
public class CalServlet extends MyHttpServlet{
    @Override
    public void doGet(MyHttpRequest request, MyHttpResponse response) {
        String num1 = request.Parameter("firstNum");
        String num2 = request.Parameter("secondName");
        int sum = Utils.StringToInteger(num1, num2);
        OutputStream outputStream = response.getOutputStream();
        try {
            outputStream.write((response.responseHeader  + "<h1>求和: " + sum + "</h1>").getBytes());
            outputStream.flush();
            outputStream.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    @Override
    public void doPost(MyHttpRequest request, MyHttpResponse response) {
        doPost(request,response);
    }
}
```

#### 工具类

```java
public class Utils {
    /**
     * 字符串转成整数求和
     */
    public static int StringToInteger(String var1,String var2){
        try{
            return Integer.parseInt(var1) + Integer.parseInt(var2);
        }catch (Exception e){
            System.out.println("格式输入错误");
        }
        return 0;
    }
}
```

**注意细节**

 * 如果想要分割点号必须转义 split("\\\\.")

# Servlet

## 概述

[servlet在线文档](https://tomcat.apache.org/tomcat-8.0-doc/servletapi/index.html)

概述：Servlet（Server Applet），全称Java Servlet。是用Java编写的服务器端程序，其主要功能在于交互式地浏览和修改数据，生成动态Web内容

Servlet的特点

- 浏览器的多次请求Servlet资源 ，通常情况下，服务器只会创建一个 Servlet 实例对象， 也就是说 Servlet 实例对象一旦创建，它就会驻留在内存中，为后续的其它请求服务，直至 web 容器退出或者 redeploy web 应用，servlet 实例对象才会销毁

- 是由服务器调用和执行的Java 程序 ，不能独立运行

- 按照Servlet规范开发的（实现了Servlet接口）

- 在Servlet 的整个生命周期内，init 方法只被调用一次。而对每次请求都调用一次service 方法

    

## Servlet 基本使用

servlet3.0 前使用 web.xml , servlet3.0 版本以后(包括 3.0)支持注解， 同时支持 web.xml 配置

### 浏览器请求Servlet资源流程

![image-20220424165555740](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220424165555740.png)

**实例代码**

```xml
<?xml version="1.0" encoding="UTF-8"?>
<web-app xmlns="http://xmlns.jcp.org/xml/ns/javaee"
         xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
         xsi:schemaLocation="http://xmlns.jcp.org/xml/ns/javaee http://xmlns.jcp.org/xml/ns/javaee/web-app_4_0.xsd"
         version="4.0">

        <!--web.xml主要用于配置该web应用使用到的的Servlet-->
        <!--配置HelloServlet-->
        <!--
                servlet-class: Servlet所在的全类名路径
                url-pattern: 浏览器访问该Servlet的路径
                servlet-name: 启到桥梁的作用,名字可以自己定义，但是必须唯一
        -->
        <servlet>
                <servlet-name>helloServlet</servlet-name>
                <servlet-class>com.al_tair.servlet.HelloServlet</servlet-class>
        </servlet>
        <servlet-mapping>
                <servlet-name>helloServlet</servlet-name>
                <url-pattern>/helloServlet</url-pattern>
        </servlet-mapping>
</web-app>
```

```java
/**
 * 开发一个Servlet需要实现该接口
 */
public class HelloServlet implements Servlet {
    /**
     * 初始化Servlet
     * 当Tomcat创建HelloServlet示例时，会调用init方法
     * 该方法只能被嗲用一次
     *
     */
    @Override
    public void init(ServletConfig servletConfig) throws ServletException {
    }

    /**
     * 返回Servlet的配置
     */
    @Override
    public ServletConfig getServletConfig() {
        return null;
    }

    /**
     * Service方法 处理浏览器的请求（get或者post）
     * 当浏览器每次请求Servlet时候，就会调用该方法
     * 当tomcat调用该方法时，会把http请求的数据封装成实现了ServletRequest接口的request对象
     * @param servletRequest 通过servletRequest获取用户提交的数据
     * @param servletResponse 用于返回数据给tomcat,再返回给浏览器
     */
    @Override
    public void service(ServletRequest servletRequest, ServletResponse servletResponse) throws ServletException, IOException {

    }

    /**
     * 返回Servlet的信息
     */
    @Override
    public String getServletInfo() {
        return null;
    }

    /**
     * 该方法是在servlet销毁的时候的调用
     * 只能被调用一次
     */
    @Override
    public void destroy() {

    }
}
```



## Servlet 生命周期

**示意图**

![image-20220424174145856](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220424174145856.png) 

### init()初始化阶段

Servlet 容器(比如: Tomcat)加载 Servlet，加载完成后，Servlet 容器会创建一个 Servlet 实例 并调用 init()方法，init()方法只会调用一次,

Tomcat服务器在下面的情况装载 Servlet实例：

- Servlet 容器(Tomcat)启动时自动装载某些 servlet，实现这个需要在 web.xml 文件中添加 <load-on-startup>1</load-on-startup> 

    ```xml
    <servlet>
        <servlet-name>helloServlet</servlet-name>
        <servlet-class>com.al_tair.servlet.HelloServlet</servlet-class>
        <!-- 1 表示装载的顺序，默认为-1不会自动装载 -->
        <load-on-startup>1</load-on-startup>
    </servlet>
    <servlet-mapping>
        <servlet-name>helloServlet</servlet-name>
        <url-pattern>/helloServlet</url-pattern>
    </servlet-mapping>
    ```

- 在 Servlet 容器(Tomcat)启动后，浏览器首次向 Servlet资源发送http请求

### service()处理浏览器请求阶段

- Tomcat每收到一个http请求，将会产生一个新的线程去处理servlet实例

- 创建一个用于封装http请求消息的ServletRequest对象和一个代表http响应消息的ServletResponse对象

    ```java
    @Override
    public void service(ServletRequest servletRequest, ServletResponse servletResponse) throws ServletException, IOException {}
    ```

### destroy()终止阶段

当Servlet 容器终止运行，或者Servlet类重新装载时，会调用destroy() 方法



## HttpServlet

**框架图**

![image-20220425165456913](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220425165456913.png) 

**代码示例**

```xml
<?xml version="1.0" encoding="UTF-8"?>
<web-app xmlns="http://xmlns.jcp.org/xml/ns/javaee"
         xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
         xsi:schemaLocation="http://xmlns.jcp.org/xml/ns/javaee http://xmlns.jcp.org/xml/ns/javaee/web-app_4_0.xsd"
         version="4.0">
        <servlet>
                <servlet-name>hiHttpServlet</servlet-name>
                <servlet-class>com.al_tair.servlet.HiHttpServlet</servlet-class>
        </servlet>
        <servlet-mapping>
                <servlet-name>hiHttpServlet</servlet-name>
                <url-pattern>/hiHttpServlet</url-pattern>
        </servlet-mapping>
</web-app>
```

```java
public class HiHttpServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        System.out.println("HttpServletRequest doGet");
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        System.out.println("HttpServletRequest doPost");
    }
}

// 源码分析到底是如何调用doGet和doPost方法
// HttpServlet类重写了Servlet接口中的Service方法
// 本质还是调用Service方法，只不过底层封装了该方法
protected void service(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
    String method = req.getMethod();
    long lastModified;
    if (method.equals("GET")) {
        lastModified = this.getLastModified(req);
        if (lastModified == -1L) {
            // 根据动态绑定机制，会调用HiHttpServlet类中的doGet方法
            this.doGet(req, resp);
        } else {
            long ifModifiedSince;
            try {
                ifModifiedSince = req.getDateHeader("If-Modified-Since");
            } catch (IllegalArgumentException var9) {
                ifModifiedSince = -1L;
            }

            if (ifModifiedSince < lastModified / 1000L * 1000L) {
                this.maybeSetLastModified(resp, lastModified);
                this.doGet(req, resp);
            } else {
                resp.setStatus(304);
            }
        }
    } else if (method.equals("HEAD")) {
        lastModified = this.getLastModified(req);
        this.maybeSetLastModified(resp, lastModified);
        this.doHead(req, resp);
    } else if (method.equals("POST")) {
        this.doPost(req, resp);
    } else if (method.equals("PUT")) {
        this.doPut(req, resp);
    } else if (method.equals("DELETE")) {
        this.doDelete(req, resp);
    } else if (method.equals("OPTIONS")) {
        this.doOptions(req, resp);
    } else if (method.equals("TRACE")) {
        this.doTrace(req, resp);
    } else {
        String errMsg = lStrings.getString("http.method_not_implemented");
        Object[] errArgs = new Object[]{method};
        errMsg = MessageFormat.format(errMsg, errArgs);
        resp.sendError(501, errMsg);
    }
}
// 如果我们不重写doGet和doPost方法，就会去调用HttpServlet类中的这两个方法，显示效果如下
protected void doPut(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
    String protocol = req.getProtocol();
    String msg = lStrings.getString("http.method_put_not_supported");
    if (protocol.endsWith("1.1")) {
        resp.sendError(405, msg);
    } else {
        resp.sendError(400, msg);
    }
}
```

![image-20220425171505753](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220425171505753.png)



## Servlet 注解方式 

###  @WebServlet

**示例代码**

```java
// 可以配置多个访问地址urlPatterns = {"/annotationServlet","/annotationServlet2"}
// urlPatterns 对应web.xml文件中的url-pattern
@WebServlet(urlPatterns = {"/annotationServlet"})
public class AnnotationServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        super.doGet(req, resp);
    }
    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        super.doPost(req, resp);
    }
}

// @WebServlet注解源码
@Target({ElementType.TYPE})
@Retention(RetentionPolicy.RUNTIME)
@Documented
public @interface WebServlet {
    String name() default "";

    String[] value() default {};

    String[] urlPatterns() default {};

    int loadOnStartup() default -1;

    WebInitParam[] initParams() default {};

    boolean asyncSupported() default false;

    String smallIcon() default "";

    String largeIcon() default "";

    String description() default "";

    String displayName() default "";
}
        
/**
 * 可以通过配置web.xml找到该Servlet，同样也可以通过注解来实现
 * 模拟Tomcat通过反射来得到注解的数据，进而匹配Servlet
 */
public class TestAnnotation {
    public static void main(String[] args) throws ClassNotFoundException {
        // 首先通过扫描包的形式，得到Servlet类的全路径
        String filePath = "com.al_tair.servlet.annotation.AnnotationServlet";

        // 反射得到注解并获取注解中的urlPatterns的值
        Class cls = Class.forName(filePath);
        WebServlet webServlet = (WebServlet)cls.getAnnotation(WebServlet.class);
        String[] urls = webServlet.urlPatterns();

        // 遍历urlPatterns的值，与http请求资源路径进行匹配
        for (String url:urls
             ) {
            System.out.println(url); /// annotationServlet
        }
    }
}
```



## urlPattern 配置

### 精准匹配

```java
@WebServlet(urlPatterns = {"/annotationServlet"})
```

### 目录匹配

```java
// /annotationServlet/后添加任何字母都可以访问到
@WebServlet(urlPatterns = {"/annotationServlet/*"})
```

### 扩展名匹配

```java
// 以annotationServlet为后缀的可以匹配
@WebServlet(urlPatterns = {"*.annotationServlet"})
```

### 任意匹配

```java
// 任意匹配
@WebServlet(urlPatterns = {"/*"})
@WebServlet(urlPatterns = {"/"})
// 当Servlet配置了"/"或者"/*", 会覆盖tomcat的DefaultServlet,当其他的utl-pattern都匹配不上时，都会走DefaultServlet，一旦拦截，静态资源不能处理
```

```xml
<!-- DefaultServlet 在Tomcat/conf/web.xml中配置 -->
<!-- The default servlet for all web applications, that serves static resources -->
<servlet>
    <servlet-name>default</servlet-name>
    <servlet-class>org.apache.catalina.servlets.DefaultServlet</servlet-class>
    <init-param>
        <param-name>debug</param-name>
        <param-value>0</param-value>
    </init-param>
    <init-param>
        <param-name>listings</param-name>
        <param-value>false</param-value>
    </init-param>
    <!-- 默认自启动 -->
    <load-on-startup>1</load-on-startup>
</servlet>
```

### 优先级

精准匹配 >   目录匹配  > 扩展名匹配 > 任意匹配 > /* > / > 默认匹配（DefaultServlet）



## ServletConfig

ServletConfig类是为Servlet程序配置信息的类，ServletConfig对象由Tomcat创建

![image-20220427154315590](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220427154315590.png) 

```java
// GenericServlet父类
// 如果该init方法没有被重写，就会默认调用父类GenericServlet的该方法
// 这个时候Tomcat在初始化的时候传入了ServletConfig对象
public void init(ServletConfig config) throws ServletException {
    this.config = config;
    this.init();
}
```

**测试代码**

假设我们要读取配置文件中的数据库数据

```xml
<?xml version="1.0" encoding="UTF-8"?>
<web-app xmlns="http://xmlns.jcp.org/xml/ns/javaee"
         xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
         xsi:schemaLocation="http://xmlns.jcp.org/xml/ns/javaee http://xmlns.jcp.org/xml/ns/javaee/web-app_4_0.xsd"
         version="4.0">
        <servlet>
            <servlet-name>DBServlet</servlet-name>
            <servlet-class>com.al_tair.servletConfig.DBServlet</servlet-class>
            <!--配置连接数据库的用户名和密码-->
            <init-param>
                <param-name>username</param-name>
                <param-value>root</param-value>
            </init-param>
            <init-param>
                <param-name>pwd</param-name>
                <param-value>123456</param-value>
            </init-param>
        </servlet>
        <servlet-mapping>
            <servlet-name>DBServlet</servlet-name>
            <url-pattern>/dbServlet</url-pattern>
        </servlet-mapping>

</web-app>
```

```java
public class DBServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doGet(request,response);
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        ServletConfig servletConfig = getServletConfig();
        String username = servletConfig.getInitParameter("username");
        System.out.println(username);
        String pwd = servletConfig.getInitParameter("pwd");
        System.out.println(pwd);
    }
}

// getServletConfig()源码分析
// 初始化的时候默认传入了ServletConfig对象，并让属性config获取该对象地址的引用
// 然后通过get方法供子类调用获取该配置对象进而获取配置对象的数据
private transient ServletConfig config;
public ServletConfig getServletConfig() {
    return this.config;
}
```



## ServletContext

### 基本介绍

- ServletContext是一个接口，用来解决Servlet对象之间的数据交互，因此也被称作域对象

    ![image-20220427165315588](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220427165315588.png)

- 一个web工程，只有一个 ServletContext 对象实例，ServletContext 对象是在 web 工程启动的时候创建，在 web 工程停止的时销毁

- ServletContext 对象可以通过 ServletConfig.getServletContext 方法获得对 ServletContext 对象的引用

    ```java
    // 父类GenericServlet有该对象的引用
    // 因此也可以通过 this.getServletContext()来获得其对象的引用
    public ServletContext getServletContext() {
        return this.getServletConfig().getServletContext();
    }
    ```

**应用实例-获取工程相关信息**

- 获取 web.xml 中配置的上下文参数 context-param
- 获取当前的工程路径，格式: /工程路径
- 获取工程部署后在服务器硬盘上的绝对路径

```xml
<?xml version="1.0" encoding="UTF-8"?>
<web-app xmlns="http://xmlns.jcp.org/xml/ns/javaee"
         xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
         xsi:schemaLocation="http://xmlns.jcp.org/xml/ns/javaee http://xmlns.jcp.org/xml/ns/javaee/web-app_4_0.xsd"
         version="4.0">
        <!--ServletContext-->
        <servlet>
            <servlet-name>ServletContextDemo</servlet-name>
            <servlet-class>com.al_tair.servletContext.ServletContextDemo</servlet-class>
        </servlet>
        <servlet-mapping>
            <servlet-name>ServletContextDemo</servlet-name>
            <url-pattern>/servletContext</url-pattern>
        </servlet-mapping>
        <!-- 配置整个网站的信息 -->
        <context-param>
            <param-name>website</param-name>
            <param-value>https://github.com/steven-beep</param-value>
        </context-param>
        <context-param>
            <param-name>school</param-name>
            <param-value>XXXXXXX</param-value>
        </context-param>
</web-app>
```

```java
public class ServletContextDemo extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doGet(request,response);
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        ServletContext servletContext = this.getServletContext();
        // 1.获取 web.xml 中配置的上下文参数 context-param
        String website = servletContext.getInitParameter("website");
        String school = servletContext.getInitParameter("school");
        System.out.println(website);
        System.out.println(school);

        // 2.获取当前的工程路径，格式: /工程路径
        String contextPath = servletContext.getContextPath();
        System.out.println(contextPath);

        // 3.获取工程部署后在服务器硬盘上的绝对路径
        String realPath = servletContext.getRealPath("/");
        System.out.println(realPath);
    }
}
```

   **应用实例 2-简单的网站访问次数计数器**

 ![image-20220427194039331](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220427194039331.png) 

![image-20220427194042960](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220427194042960.png) 

```xml
<?xml version="1.0" encoding="UTF-8"?>
<web-app xmlns="http://xmlns.jcp.org/xml/ns/javaee"
         xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
         xsi:schemaLocation="http://xmlns.jcp.org/xml/ns/javaee http://xmlns.jcp.org/xml/ns/javaee/web-app_4_0.xsd"
         version="4.0">
        <!-- 两个Servlet -->
        <servlet>
            <servlet-name>Servlet1</servlet-name>
            <servlet-class>com.al_tair.servletContext.Servlet1</servlet-class>
        </servlet>
        <servlet-mapping>
            <servlet-name>Servlet1</servlet-name>
            <url-pattern>/servlet1</url-pattern>
        </servlet-mapping>
        <servlet>
            <servlet-name>Servlet2</servlet-name>
            <servlet-class>com.al_tair.servletContext.Servlet2</servlet-class>
        </servlet>
        <servlet-mapping>
            <servlet-name>Servlet2</servlet-name>
            <url-pattern>/servlet2</url-pattern>
        </servlet-mapping>
</web-app>

```

```java
// Servlet1 和 Servlet2的代码相同
public class Servlet1 extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doGet(request,response);
    }
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        ServletContext servletContext = getServletContext();
        Integer count = (Integer) servletContext.getAttribute("count");
        if(count == null){
            servletContext.setAttribute("count",1);
            count = 1;
        }else{
            servletContext.setAttribute("count",++count);
        }
        System.out.println("Servlet1访问，共访问次数: " + count);

        response.setContentType("text/html;charset=utf-8");
        PrintWriter writer = response.getWriter();
        writer.write("<h1>共访问次数: "+ count + "</h1>");
        writer.flush();
        writer.close();
    }
}
```



## HttpServletRequest

当客户端/浏览器通过 HTTP 协议访问服务器时，HTTP 请求头中的所有信息都封装在这个对象

![image-20220427195449563](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220427195449563.png) 

### 常用方法

**测试代码**

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>login</title>
</head>
<body>
    <form action="http://localhost:9999/servlet/requestMethod" method="get">
        <div align="center">
            <h1 align="center">表单</h1>
            用户名<input type="text" name="username"/><br>
            密 码<input type="password" name="pwd"/><br>
            <input type="checkbox" name="hobby" value="zq">足球
            <input type="checkbox" name="hobby" value="lq">篮球
            <input type="checkbox" name="hobby" value="pq">排球<br/>
            <button type="submit">提交表单</button>
        </div>
    </form>
</body>
</html>
```

```java
@WebServlet(urlPatterns = {"/requestMethod"})
public class RequestMethod extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        // getRequestURI() 获取请求的资源路径
        String requestURI = req.getRequestURI();
        System.out.println(requestURI); // /servlet/requestMethod

        // getRequestURL()获取请求的统一资源定位符（绝对路径）
        StringBuffer requestURL = req.getRequestURL();
        System.out.println(requestURL); // http://localhost:9999/servlet/requestMethod

        // getRemoteHost()获取客户端/浏览器的主机
        String remoteHost = req.getRemoteHost();
        System.out.println(remoteHost ); // 127.0.0.1

        // getHeader()获取请求头
        String header = req.getHeader("Accept");
        // text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,
        // image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9
        System.out.println(header);

        // getParameter()获取请求的参数
        // 注意解码url编码，不会会出现中文乱码(并且要写在接受数据前)
        req.setCharacterEncoding("utf-8");
        String username = req.getParameter("username");
        String pwd = req.getParameter("pwd");
        System.out.println(username); // Al_tair
        System.out.println(pwd); // 123456

        // getParameterValues()获取请求的参数（多个值的时候使用）, 比如checkbox,返回数组
        String[] hobbies = req.getParameterValues("hobby");
        for (String hobby: hobbies
             ) {
            System.out.println(hobby); // zq lq
        }

        // getMethod()获取请求的参数
        System.out.println(req.getMethod()); // GET

        // setAttribute(key, value)设置域数据
        req.setAttribute("count",2);

        // getAttribute(key)获取域数据
        Integer count = (Integer)req.getAttribute("count");
        System.out.println(count); // 2
    }
    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        super.doGet(req, resp);
    }
}
```

### 请求转发

概述：请求转发指一个 web 资源收到客户端请求后，通知服务器去调用另外一个 web 资源进行处理

- HttpServletRequest 对象提供了一个 getRequestDispatcher 方法，该方法返回一个 RequestDispatcher 对象，调用这个对象的 forward 方法可以实现请求转发
- HttpServletRequest 对象是一个域对象（共享对象），可以通过 HttpServletRequest 对象在实现转发时，把数据通过 HttpServletRequest 对象带给其它 web 资源处理，可以使用如下方法
    - setAttribute方法
    - getAttribute方法
    - removeAttribute方法
    - getAttributeNames方法

#### 请求转发原理

![image-20220428131521640](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220428131521640.png) 

#### 示例代码

![image-20220428151211405](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220428151211405.png) 

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Title</title>
</head>
<body>
    <form action="http://localhost:9999/servlet/checkServlet" method="get">
        <h1>检查是否该用户为管理员</h1>
        用户名<input type="text" name="username"><br/>
        <button type="submit">按钮</button>
    </form>
</body>
</html>
```

```xml
<?xml version="1.0" encoding="UTF-8"?>
<web-app xmlns="http://xmlns.jcp.org/xml/ns/javaee"
         xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
         xsi:schemaLocation="http://xmlns.jcp.org/xml/ns/javaee http://xmlns.jcp.org/xml/ns/javaee/web-app_4_0.xsd"
         version="4.0">
        <!-- 请求转发 -->
        <servlet>
            <servlet-name>CheckServlet</servlet-name>
            <servlet-class>com.al_tair.HttpServletRequest.CheckServlet</servlet-class>
        </servlet>
        <servlet-mapping>
            <servlet-name>CheckServlet</servlet-name>
            <url-pattern>/checkServlet</url-pattern>
        </servlet-mapping>
        <servlet>
            <servlet-name>ManageServlet</servlet-name>
            <servlet-class>com.al_tair.HttpServletRequest.ManageServlet</servlet-class>
        </servlet>
        <servlet-mapping>
            <servlet-name>ManageServlet</servlet-name>
            <url-pattern>/manageServlet</url-pattern>
        </servlet-mapping>
</web-app>

```

![image-20220428151429587](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220428151429587.png) 

```java
// CheckServlet
public class CheckServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doGet(request,response);
    }
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String username = request.getParameter("username");
        if(username.equals("tom")){
            request.setAttribute("role", "管理员");
        }else{
            request.setAttribute("role", "普通用户");
        }
        // 获取分发器
        RequestDispatcher requestDispatcher = request.getRequestDispatcher("/manageServlet");
        // 表示把当前CheckServlet的request对象和response对象，传递给ManageServlet使用
        requestDispatcher.forward(request, response);
    }
}

// ManageServlet
public class ManageServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doGet(request,response);
    }
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String username = request.getParameter("username");
        String role = (String)request.getAttribute("role");

        response.setContentType("text/html;charset=utf-8");
        PrintWriter writer = response.getWriter();
        writer.print("用户名: " + username + "<br/>");
        writer.print("角色 : " + role);
        writer.flush();
        writer.close();
    }
}
```

#### 注意事项

- 浏览器访问资源地址不会变化（都是第一个资源的url）
    - 因为浏览器地址栏会停止在第一个资源地址，如果你刷新页面，会再次发出请求(并且会带数据), 所以在支付页面的时候，不要使用请求转发，否则会造成重复支付的问题
- 在同一次 HTTP 请求中，进行多次转发，多个 Servlet 可以共享 request 域/对象的数据(因为始终是同一个 request 对象)
- 可以转发到 WEB-INF 目录下的资源（该目录资源无法通过浏览器直接访问）
- 不能访问当前 WEB 工程外的资源



## HttpServletResponse

概念：每次 HTTP 请求，Tomcat 会创建一个 HttpServletResponse 对象传递给Servlet

作用：主要用于响应浏览器，返回数据给浏览器

![image-20220428172925090](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220428172925090.png) 

### 常用方法

```java
// 父接口ServletResponse的方法
// 字节流，常用于下载文件
ServletOutputStream getOutputStream() throws IOException;
// 字符流，常用于传输字符串
PrintWriter getWriter() throws IOException;
// 注意：字节流和字符流在同一个时间段只能使用其中一个

// 用于处理中文乱码（本质没有区别）
// 方法一
response.setCharacterEncoding("utf-8"); // 设置服务器字符集为utf-8
response.setHeader("ContentType","text/html;charset=utf-8"); // 设置浏览器使用该字符集
// 方法二
response.setContentType("text/html;charset=utf-8");
```

**请求重定向**

概念：一个 web 资源收到客户端请求后，通知客户端去访问另外一个 web 资源

![image-20220428185228710](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220428185228710.png) 

**重定向的两种方式**

```java
// 方式1
response.sendRedirect("/servlet/xxServlet");

// 方式2
response.setStatus(302);
response.setHeader("Location","/servlet/xxServlet");
```

**示例代码**

- 编写一个 MyPayServlet , 能够接收到提交的数据 

- 编写一个简单的支付页面 pay.html

    ![image-20220428200852063](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220428200852063.png) 

- 如果支付金额大于 100, 则重定向到 payok.html, 否则重定向到原来的 pay.html

    ![image-20220428200830414](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220428200830414.png) 

```html
<!-- pay.html -->
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8">
        <title>支付页面</title></head>
    <body>
    <h1>支付页面</h1> <!--注意：这里 action="/servlet/myPayServlet"的第一/被浏览器解析从浏览器地址栏的 主机-->
    <form action="/homework/myPayServlet" method="get">
        用户编号: <input type="text" name="userid"><br/>
        支付金额: <input type="text" name="money"><br/>
        <input type="submit" value="点击支付"></form>
    </body>
</html>

<!-- payok.html -->
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>支付成功</title></head>
<body><h1>恭喜你，支付成功~</h1></body>
</html>
```

```java
@WebServlet(name = "HttpServletResponse",urlPatterns = {"/myPayServlet"})
public class myPayServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, javax.servlet.http.HttpServletResponse response) throws ServletException, IOException {
        doGet(request,response);
    }
    protected void doGet(HttpServletRequest request, javax.servlet.http.HttpServletResponse response) throws ServletException, IOException {
        String money = request.getParameter("money");
        String contextPath = getServletContext().getContextPath();
        if(Integer.parseInt(money) > 100){
            response.sendRedirect(contextPath + "/payok.html");
        }else{
            response.sendRedirect(contextPath + "/pay.html");
        }
    }
}
```

**注意细节**

- 最佳应用场景：网站迁移，比如原域名是 XXX.com 迁移到 XXX.cn ，但是百度抓取的还是原来网址

- 浏览器地址会发生变化，不能共享 Request 域中的数据，本质是两次 http 请求

- 不能重定向到 /WEB-INF 下的资源

- 可以重定向到 Web 工程以外的资源

    

    

# HTTP协议

概念：超文本传输协议，是互联网上应用广泛的一种网络协议，是工作在TCP/IP协议基础上

##  请求头

|       Header        |                             解释                             | 示例                                                         |
| :-----------------: | :----------------------------------------------------------: | ------------------------------------------------------------ |
|       Accept        |                 指定客户端能够接收的内容类型                 | Accept: text/plain, text/html                                |
|   Accept-Charset    |                 浏览器可以接受的字符编码集。                 | Accept-Charset: iso-8859-5                                   |
|   Accept-Encoding   |    指定浏览器可以支持的 web 服务器返回内容压缩编码类型。     | Accept-Encoding: compress, gzip                              |
|   Accept-Language   |                      浏览器可接受的语言                      | Accept-Language: en,zh                                       |
|    Accept-Ranges    |           可以请求网页实体的一个或者多个子范围字段           | Accept-Ranges: bytes                                         |
|    Authorization    |                     HTTP 授权的授权证书                      | Authorization: Basic QWxhZGRpbjpvcGVuIHNlc2FtZQ==            |
|    Cache-Control    |                 指定请求和响应遵循的缓存机制                 | Cache-Control: no-cache                                      |
|     Connection      |     表示是否需要持久连接。（HTTP 1.1 默认进行持久连接）      | Connection: close                                            |
|       Cookie        | HTTP 请求发送时，会把保存在该请求域名下的所有 cookie 值一起发送给 web 服务器。 | Cookie: $Version=1; Skin=new;                                |
|   Content-Length    |                        请求的内容长度                        | Content-Length: 348                                          |
|    Content-Type     |                 请求的与实体对应的 MIME 信息                 | Content-Type: application/x-www-form-urlencoded              |
|        Date         |                     请求发送的日期和时间                     | Date: Tue, 15 Nov 2010 08:12:31 GMT                          |
|       Expect        |                    请求的特定的服务器行为                    | Expect: 100-continue                                         |
|        From         |                    发出请求的用户的 Email                    | [From: user@email.com](mailto:user@email.com)                |
|        Host         |                指定请求的服务器的域名和端口号                | [Host: www.zcmhi.com](http://www.zcmhi.com/)                 |
|      If-Match       |                只有请求内容与实体相匹配才有效                | If-Match: “737060cd8c284d8af7ad3082f209582d”                 |
|  If-Modified-Since  | 如果请求的部分在指定时间之后被修改则请求成功，未被修改则返回 304 代码 | If-Modified-Since: Sat, 29 Oct 2010 19:43:31 GMT             |
|    If-None-Match    | 如果内容未改变返回 304 代码，参数为服务器先前发送的 Etag，与服务器回应的 Etag 比较判断是否改变 | If-None-Match: “737060cd8c284d8af7ad3082f209582d”            |
|      If-Range       | 如果实体未改变，服务器发送客户端丢失的部分，否则发送整个实体参数也为 Etag | 。 If-Range: “737060cd8c284d8af7ad3082f209582d”              |
| If-Unmodified-Since |           只在实体在指定时间之后未被修改才请求成功           | If-Unmodified-Since: Sat, 29 Oct 2010 19:43:31 GMT           |
|    Max-Forwards     |               限制信息通过代理和网关传送的时间               | Max-Forwards: 10                                             |
|       Pragma        |                    用来包含实现特定的指令                    | Pragma: no-cache                                             |
| Proxy-Authorization |                     连接到代理的授权证书                     | Proxy-Authorization: Basic QWxhZGRpbjpvcGVuIHNlc2FtZQ==      |
|        Range        |                 只请求实体的一部分，指定范围                 | Range: bytes=500-999                                         |
|       Referer       |         先前网页的地址，当前请求网页紧随其后,即来路          | [Referer: http://www.zcmhi.com/archives/71.html](http://www.zcmhi.com/archives/71.html) |
|         TE          |   客户端愿意接受的传输编码，并通知服务器接受接受尾加头信息   | TE: trailers,deflate;q=0.5                                   |
|       Upgrade       |    向服务器指定某种传输协议以便服务器进行转换（如果支持）    | Upgrade: HTTP/2.0, SHTTP/1.3, IRC/6.9, RTA/x11               |
|     User-Agent      |           User-Agent 的内容包含发出请求的用户信息            | User-Agent: Mozilla/5.0 (Linux; X11)                         |
|         Via         |            通知中间网关或代理服务器地址，通信协议            | Via: 1.0 fred, 1.1 nowhere.com (Apache/1.1)                  |
|       Warning       |                    关于消息实体的警告信息                    | Warn: 199 Miscellaneous warning                              |



### GET测试代码

```html
<!-- 提交表单页面 -->
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>login</title>
</head>
<body>
    <form action="http://localhost:9999/homework/pig1" method="get">
        <div align="center">
            <h1 align="center">表单</h1>
            用户名<input type="text" name="username"/><br>
            密 码<input type="password" name="pwd"/><br>
            <button type="submit">提交表单</button>
        </div>
    </form>
</body>
</html>
```

```java
@WebServlet(urlPatterns = {"/pig1","/pig2"})
public class PigServlet extends HttpServlet {
    private static int getCount;
    private static int postCount;
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
    }
    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
    }
}
```

![image-20220426232617224](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220426232617224.png) 

![image-20220426230624269](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220426230624269.png) 

**GET请求方式**

- form 标签的属性设置 method = "get"
- a标签（超链接）
- link标签引入CSS文件
- script标签引入js文件
- img标签引入图片
- iframe 引入html页面
- 在浏览器地址栏中输入地址并访问



### POST测试代码

```html
<!-- 提交表单页面 -->
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>login</title>
</head>
<body>
    <form action="http://localhost:9999/homework/pig1" method="post">
        <div align="center">
            <h1 align="center">表单</h1>
            用户名<input type="text" name="username"/><br>
            密 码<input type="password" name="pwd"/><br>
            <button type="submit">提交表单</button>
        </div>
    </form>
</body>
</html>
```

```java
@WebServlet(urlPatterns = {"/pig1","/pig2"})
public class PigServlet extends HttpServlet {
    private static int getCount;
    private static int postCount;
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
    }
    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
    }
}
```

![image-20220426232509739](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220426232509739.png) 

![image-20220426232234129](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220426232234129.png) 

**POST请求方式**

- form 标签的属性设置 method = "post"

### GET和POST的使用场景

- 当传输的数据量较小，使用get请求（小于2KB）；反之使用post请求来传输数据量
- 当文件不希望显示出来（登陆页面数据等）可以使用post请求，反之使用get请求
- 分享链接往往使用get请求方式，更好的分享和传播



## 响应头

|   Accept-Ranges    |      表明服务器是否支持指定范围请求及哪种类型的分段请求      | Accept-Ranges: bytes                                         |
| :----------------: | :----------------------------------------------------------: | ------------------------------------------------------------ |
|        Age         |     从原始服务器到代理缓存形成的估算时间（以秒计，非负）     | Age: 12                                                      |
|       Allow        |        对某网络资源的有效的请求行为，不允许则返回 405        | Allow: GET, HEAD                                             |
|   Cache-Control    |           告诉所有的缓存机制是否可以缓存及哪种类型           | Cache-Control: no-cache                                      |
|  Content-Encoding  |            web 服务器支持的返回内容压缩编码类型。            | Content-Encoding: gzip                                       |
|  Content-Language  |                         响应体的语言                         | Content-Language: en,zh                                      |
|   Content-Length   |                         响应体的长度                         | Content-Length: 348                                          |
|  Content-Location  |                请求资源可替代的备用的另一地址                | Content-Location: /index.htm                                 |
|    Content-MD5     |                    返回资源的 MD5 校验值                     | Content-MD5: Q2hlY2sgSW50ZWdyaXR5IQ==                        |
|   Content-Range    |                在整个返回体中本部分的字节位置                | Content-Range: bytes 21010-47021/47022                       |
|    Content-Type    |                     返回内容的 MIME 类型                     | Content-Type: text/html; charset=utf-8                       |
|        Date        |                   原始服务器消息发出的时间                   | Date: Tue, 15 Nov 2010 08:12:31 GMT                          |
|        ETag        |                  请求变量的实体标签的当前值                  | ETag: “737060cd8c284d8af7ad3082f209582d”                     |
|      Expires       |                     响应过期的日期和时间                     | Expires: Thu, 01 Dec 2010 16:00:00 GMT                       |
|   Last-Modified    |                    请求资源的最后修改时间                    | Last-Modified: Tue, 15 Nov 2010 12:45:26 GMT                 |
|      Location      | 用来重定向接收方到非请求 URL 的位置来完成请求或标识新的资源  | [Location: http://www.zcmhi.com/archives/94.html](http://www.zcmhi.com/archives/94.html) |
|       Pragma       |      包括实现特定的指令，它可应用到响应链上的任何接收方      | Pragma: no-cache                                             |
| Proxy-Authenticate |        它指出认证方案和可应用到代理的该 URL 上的参数         | Proxy-Authenticate: Basic                                    |
|      refresh       | 应用于重定向或一个新的资源被创造，在 5 秒之后重定向（由网景提出被大部分浏览器支持） | [Refresh: 5; url= http://www.zcmhi.com/archives/94.html](http://www.zcmhi.com/archives/94.html) |
|    Retry-After     |     如果实体暂时不可取，通知客户端在指定时间之后再次尝试     | Retry-After: 120                                             |
|       Server       |                      web 服务器软件名称                      | Server: Apache/1.3.27 (Unix) (Red-Hat/Linux)                 |
|     Set-Cookie     |                       设置 Http Cookie                       | Set-Cookie: UserID=JohnDoe; Max-Age=3600; Version=1          |
|      Trailer       |               指出头域在分块传输编码的尾部存在               | Trailer: Max-Forwards                                        |
| Transfer-Encoding  |                         文件传输编码                         | Transfer-Encoding:chunked                                    |
|        Vary        |        告诉下游代理是使用缓存响应还是从原始服务器请求        | Vary: *                                                      |
|        Via         |              告知代理客户端响应是通过哪里发送的              | Via: 1.0 fred, 1.1 nowhere.com (Apache/1.1)                  |
|      Warning       |                    警告实体可能存在的问题                    | Warning: 199 Miscellaneous warning                           |
|  WWW-Authenticate  |             表明客户端请求实体应该使用的授权方案             | WWW-Authenticate: Basic                                      |

**测试代码**

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>login</title>
</head>
<body>
    <form action="http://localhost:9999/homework/pig1" method="post">
        <div align="center">
            <h1 align="center">表单</h1>
            用户名<input type="text" name="username"/><br>
            密 码<input type="password" name="pwd"/><br>
            <button type="submit">提交表单</button>
        </div>
    </form>
</body>
</html>
```

![image-20220427121529381](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220427121529381.png)



## 状态码

概述：当浏览者访问一个网页时，浏览者的浏览器会向网页所在服务器发出请求。当浏览器接收并显示网页前，此网页所在的服务器会返回一个包含HTTP状态码的信息头（server header）用以响应浏览器的请求

### HTTP状态码分类

| 分类 | 分类描述                                       |
| ---- | ---------------------------------------------- |
| 1**  | 信息，服务器收到请求，需要请求者继续执行操作   |
| 2**  | 成功，操作被成功接收并处理                     |
| 3**  | 重定向，需要进一步的操作以完成请求             |
| 4**  | 客户端错误，请求包含语法错误或无法完成请求     |
| 5**  | 服务器错误，服务器在处理请求的过程中发生了错误 |

[状态码在线文档](https://www.runoob.com/http/http-status-codes.html)

### 常见的HTTP状态码

- 200 - 请求成功
- 301 - 资源（网页等）被永久转移到其它URL
- 404 - 请求的资源（网页等）不存在
- 500 - 内部服务器错误

#### 302重定向

![image-20220427135716058](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220427135716058.png)



## MIME类型

概念：HTTP协议中的数据类型，格式：大类型/小类型

![image-20220427142156306](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220427142156306.png)

### 常见的MIME类型

| 内容类型                                                     | 文件扩展名 | 描述                 |
| ------------------------------------------------------------ | ---------- | -------------------- |
| application/msword                                           | doc        | Microsoft Word       |
| application/pdf                                              | pdf        | Adobe Acrobat        |
| appication/powerpoint                                        | ppt        | Microsoft Powerpoint |
| application/xhtml+xml                                        | .xhtml     | XHTML                |
| application/xml 代码对普通用户来说不可读<br>text/xml 代码对普通用户来说可读 | .xml       | XML                  |
| image/png                                                    | .png       | PNG 图像             |
| text/plain                                                   | .txt       | TXT                  |
| text/html                                                    | .html      | HTML                 |
| audio/mpeg                                                   | .mp3       | MP3 audio            |



# Web路径专题

## 工程路径问题

```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8">
        <title>base 标签</title></head>
    <body>
        <h1>注册用户~</h1>
        <!-- http://localhost:10000/hspedu_servlet/ok 复杂 -->
        <form action="http://localhost:10000/hspedu_servlet/ok" method="post"> 
            u: <input type="text" name="username"/><br><br>
            <input type="submit" value="注册用户"/>
        </form>
        
        <h1>讨论区</h1>
        <form action="http://localhost:10000/hspedu_servlet/ok" method="post"> 
            讨论内容: <textarea cols="50" rows="5"></textarea><br><br>
            <input type="submit" value="发布讨论"/>
        </form>
        
        <h1>回复区</h1>
        <form action="http://localhost:10000/hspedu_servlet/ok" method="post"> 
            回复内容: <textarea cols="50" rows="5"></textarea><br><br>
            <input type="submit" value="回复"/>
        </form>
    </body>
</html>
```

### 解决方案：相对路径

使用相对路径来解决， 一个非常重要的规则：页面所有的相对路径，在默认情 况下，都会参考当前浏览器地址栏的路径 http://ip:port/web工程名/ + 资源来进行跳转

```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8">
        <title>base 标签</title></head>
    <body>
        <h1>注册用户~</h1>
        <!-- 相对路径可以写成 ok -->
        <!-- http://localhost:10000/hspedu_servlet/ + ok-->
        <form action="ok" method="post"> 
            u: <input type="text" name="username"/><br><br>
            <input type="submit" value="注册用户"/>
        </form>
        
        <h1>讨论区</h1>
        <form action="ok" method="post"> 
            讨论内容: <textarea cols="50" rows="5"></textarea><br><br>
            <input type="submit" value="发布讨论"/>
        </form>
        
        <h1>回复区</h1>
        <form action="ok" method="post"> 
            回复内容: <textarea cols="50" rows="5"></textarea><br><br>
            <input type="submit" value="回复"/>
        </form>
    </body>
</html>
```

**但是相对路径会存在其他问题**

如果从当前路径去寻找其他路径的资源，可能会出现更加复杂的路径情况，如图

![image-20220501120050863](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220501120050863.png) 

### 解决方案：base 标签

#### 基本介绍

1. base 标签是 HTML 语言中的基准网址标记，它是一个单标签，位于网页头部文件的 head 标签内
2. 一个页面最多只能使用一个 base 元素，用来提供一个指定的默认目标，是一种表达路径和连接网址的标记
3. 常见的 url 路径形式分别有相对路径与绝对路径，如果 base 标签指定了目标，浏览器将通过这个目标来解析当前文档中的所有相对路径，包括的标签有（a、img、link、form），也就是说，浏览器解析时会在路径前加上 base 给的目标，而页面中的相对路径也都转换成了绝对路径
4.  base 标签就应带上 href 属性和 target 属性

**实例代码**

```html
<!-- 相对路径 -->
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8">
        <title>a.html</title>
        <link rel="stylesheet" type="text/css" href="../../dir1/dir2/dir3/my.css">
    </head>
    <body>
        <h1>这是 a.html</h1>
        <a href="../../dir1/dir2/dir3/b.html">跳转到dir1/dir2/dir3/b.html</a>
        <br/><br/>
    </body>
</html>

<!-- 使用base标签 -->
<!-- my.css -->
h1{
    color: blue;
}

<!-- a.html -->
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8">
        <title>a.html</title>
        <!--
            / 在浏览器中解析就是 http://localhost:9999/
            / 在请求转发（web服务里）解析就是 http://localhost:9999/webPath/
            href="/webPath/" 在浏览器解析就是 http://localhost:9999/webPath/
        -->
        <base href="/webPath/">
        <link rel="stylesheet" type="text/css" href="dir1/dir2/dir3/my.css">
    </head>
    <body>
        <h1>这是 a.html</h1>
        <!-- 注意前面不能加/，否则解析成 http://localhost:9999/替换base路径 -->
        <a href="dir1/dir2/dir3/b.html">跳转到dir1/dir2/dir3/b.html</a>
        <br/><br/>
    </body>
</html>

<!-- b.html -->
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>a.html</title>
    <base href="/webPath/">
</head>
<body><h1>这是 b.html</h1>
<a href="d1/d2/a.html">跳转到d1/d2/a.html</a>
<br/><br/>
</body>
</html>
```



## 工程路径总结

假设 http://localhost:9999/webPath/dir1/a.html 提交表单给  http://localhost:9999/webPath/dir2/b.html

- 如果使用了base标签 <base href="/webPath/">
    - 如果使用了 / 开头，将解析成http://localhost:9999/ （base标签起不到作用） <form action="/webPath/dir2/b.html">
    - 如果未使用 / 开头，则默认以base标签路径为起点 <form action="dir2/b.html">
- 如果没有使用了base标签
    - 如果使用了 / 开头，将解析成http://localhost:9999/  <form action="/webPath/dir2/b.html">
    - 如果未使用 / 开头，则默认以自身路径为起点（相对路径） <form action="../dir2/b.html">



请求转发  http://localhost:9999/webPath/servlet 转发到  http://localhost:9999/webPath/dir2/b.html

```java
// 以下两者方式相同：在同目录/webPath/下进行查找dir2/b.html资源
request.getRequestDispatcher("dir2/b.html").forward(request,response);
request.getRequestDispatcher("/dir2/b.html").forward(request,response);
// 注意点
// a.html -> servlet资源转发给 -> b.html
// 如果b.html要跳转回a.html的时候尽量不要使用相对路径（因为请求转发的相对路径是相对Servlet资源来说的）
```



请求重定向   http://localhost:9999/webPath/servlet 转发到  http://localhost:9999/webPath/dir2/b.html

```java
// 方式一 动态获取工程目录（推荐）
String contextPath = getServletContext().getContextPath(); //  /webPath
response.sendRedirect(contextPath + "/dir2/b.html");  
// 方式二：/ 浏览器解析：http://localhost:9999/
response.sendRedirect("/webPath/dir2/b.html");
// 方式三 使用相对路径(不推荐)
request.sendRedirect("dir2/b.html");
// 方式四 全路径
request.sendRedirect("http://localhost:9999/webPath/dir2/b.html");
```



# Web 开发会话技术

 **什么是会话？** 

会话可简单理解为：用户开一个浏览器，点击多个超链接，访问服务器多个 web 资源，然后关闭浏览器，整个过程称之为一个会话

## 会话的两种技术 

### Cookie

概念：Cookie 是服务器在客户端保存用户的信息，比如登录名，浏览历史等, 就可以以 cookie 方式保存

**cookie框架图**

![image-20220502160718152](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220502160718152.png) 

**Cookie的作用**

- 保存上次登录时间等信息
- 保存用户名，密码, 在一定时间不用重新登录
- 网站的个性化，比如定制网站的服务，内容

#### 读取Cookie数据

1. 浏览器端创建email=1079936135qq.com的数据

    ![image-20220502135841666](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220502135841666.png) 

2. 浏览器向服务器传输Cookie数据

    ![image-20220502140445863](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220502140445863.png) 

3. 服务器读取到Cookie数据

    ```java
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        Cookie[] cookies = request.getCookies();
        if(cookies != null && cookies.length != 0){
            for (Cookie coke : cookies) {
                //  cookieName: email  cookieValue1079936135
                //  cookieName: Idea-6463f311  cookieValue6cb7445e-85d8-4a31-a12a-bcdbe5c375d9
                // 如果读取到中文名字
                // 可以通过URLDecoder.decode(coke.getName(),"utf-8")解码
                System.out.println("cookieName: " + coke.getName() + "  cookieValue" + coke.getValue());
            }
        }
    }
    ```

#### 创建Cookie实例

![image-20220502135401926](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220502135401926.png) 

```java
protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
    System.out.println("cookie被调用");
    // 创建Cookie对象
    // 解决不能存储中文的原因，需要进行url编码
    String data = URLEncoder.encode("罗念笙","UTF-8");
    Cookie cookie = new Cookie("username",data);
    //将Cookie发送给浏览器并保存
    response.addCookie(cookie);
    response.setContentType("text/html;charset=utf-8");
    PrintWriter writer = response.getWriter();
    writer.write("<h1>Cookie创建成功!</h1>");
    writer.flush();
    writer.close();
}
```

#### 修改Cookie值

![image-20220502155708934](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220502155708934.png) 

```java
protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
    Cookie[] cookies = request.getCookies();
    String cookieName = "email";
    Cookie cookie = CookieUtils.nameToGetCookie(cookieName, cookies);
    CookieUtils.IterCookie(cookies);
    if(cookie == null){
        System.out.println("没有该Cookie");
    }else{
        cookie.setValue("10799361@qq.com");
        CookieUtils.IterCookie(cookies);
        response.addCookie(cookie);
    }
}

// 工具类
public class CookieUtils {
    /**
     * 通过CookieName来获取对应的Cookie
     */
    public static Cookie nameToGetCookie(String cookieName,Cookie[] cookies){
        if(cookieName != null && !cookieName.equals("") && cookies != null && cookies.length != 0){
            for (Cookie cookie : cookies) {
                if(cookie.getName().equals(cookieName)){
                    return cookie;
                }
            }
        }
        return null;
    }

    /**
     * 遍历Cookie，显示Cookie的name-value 
     */
    public static void IterCookie(Cookie[] cookies){
        System.out.println();
        if(cookies != null && cookies.length != 0){
            for (Cookie cookie : cookies) {
                System.out.println("cookieName: " + cookie.getName() + "  cookieValue: " + cookie.getValue());
            }
        }
        System.out.println();
    }
}
```

#### cookie 生命周期 

**常用方法**

```java
// 正数，表示在指定的秒数后过期
// 负数，表示浏览器关闭 Cookie 就会被删除（默认值是-1）
// 0，表示马上删除 Cookie (可以用来删除Cookie)
setMaxAge()
```

**代码示例**

```java
protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
    // 创建一个新的Cookie对象
    Cookie cookie = new Cookie("age","18");
    // 设置Cookie的生命周期 20s
    cookie.setMaxAge(20);
    // 返回给浏览器存储20s 
    response.addCookie(cookie);
}
```

#### cookie 有效路径

Cookie 的 path 属性可以有效的过滤哪些 Cookie 可以发送给服务器,哪些不发。 path 属性是通过请求的地址来进行有效的过滤

```java
// 举例说明 (默认setPath:/工程路径 )
cookie1.setPath = /工程路径 
cookie2.setPath = /工程路径/aaa 
    
// url请求地址: http://ip:端口/工程路径/资源 
cookie1 会发给服务器 
cookie2 不会发给服务器 
    
// url请求地址: http://ip:端口/工程路径/aaa/资源 
cookie1 会发给服务器 
cookie2 会发给服务器
```

**Cookie 注意事项和细节**

1. 一个 Cookie 只能标识一种信息，它至少含有一个标识该信息的名称（NAME）和设置值 （VALUE）

2. 一个 WEB 站点可以给一个浏览器发送多个 Cookie，一个浏览器也可以存储多个 WEB 站点提供的 Cookie

3. Cookie 的总数量没有限制，但是每个域名的 Cookie 数量和每个 Cookie的大小是有限制的 (不同的浏览器限制不同) , Cookie 不适合存放数据量大的信息

4. 注意中文存入cookie的时候需要编码和解码

    ```java
    // url编码
    String data = URLEncoder.encode("想要存入的中文","UTF-8");
    Cookie cookie = new Cookie("username",data);
    //url解码
    URLDecoder.decode(cookie数据,"utf-8");
    ```

    

### Session 

#### 基本介绍

概念：Session 是服务器端技术，服务器在运行时为每一个用户的浏览器创建一个其独享的 session 对象/集合，由于 session 为各个用户浏览器独享，所以用户在访问服务器的不同页面时，可以从各自 的 session 中读取/添加数据

session 对象默认存在时间为 30min

```xml
<!-- ==================== Default Session Configuration ================= -->
<!-- You can set the default session timeout (in minutes) for all newly   -->
<!-- created sessions by modifying the value below.                       -->
<!-- Tomcat中web.xml文件可以配置时间,默认30min -->
<session-config>
    <session-timeout>30</session-timeout>
</session-config>
```

**Session的作用**

- 将数据放入到 Session 中，供用户在访问不同页面时，实现跨页面访问数据
- 保存登录用户的信息
- 防止用户非法登录到某个页面等等

**session 存储结构示意图**

| 名字（key） | 值（value） |
| :---------: | :---------: |
| String类型  | Object类型  |

#### 常用方法

```java
// 1.创建和获取 Session
// 第1次调用是创建 Session 会话， 之后调用是获取创建好的 Session 对象 
HttpSession hs=request.getSession(); 
// 2.向 session 添加属性 
hs.setAttribute(String name,Object val); 
// 3.从 session 得到某个属性 
Object obj=hs.getAttribute(String name);
// 4.从 session 删除调某个属性: 
hs.removeAttribute(String name); 
// 5.判断是不是刚创建出来的 Session
hs.isNew(); 
// 6.每个Session都有1个唯一标识Id值,通过getId()得到Session的会话id值(JSESSIONID)
```

#### 原理示意图

**JSESSIONID**

用于服务器来标识不同的会话，不同的会话，服务器会对应创建不同的JSESSIONID

![image-20220502144731606](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220502144731606.png)

**框架图**

![image-20220503185147684](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220503185147684.png)

#### 操作代码示例

**设置属性**

```java
protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
    response.setContentType("text/html;charset=utf-8");
    PrintWriter writer = response.getWriter();
    HttpSession session = request.getSession();
    session.setAttribute("id","1234956789");
    System.out.println("属性设置完成");
    writer.flush();
    writer.close();
}
```

**读取属性**

```java
protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
    response.setContentType("text/html;charset=utf-8");
    PrintWriter writer = response.getWriter();
    HttpSession session = request.getSession();
    Object s = session.getAttribute("id");
    if(s != null){
        System.out.println((String)s);
    }else{
        System.out.println("没有该属性");
    }
    writer.flush();
    writer.close();
}
```

#### session 生命周期

Session 的生命周期指的是 ：客户端/浏览器两次请求最大间隔时长，而不是累积时长。 即当客户端访问了自己的 session，session 的生命周期将从 0 开始重新计算。(同一个会话两次请求之间的间隔时间)

底层: Tomcat 用一个线程来轮询会话状态，如果某个会话的空闲时间超过设定的最大值， 则将该会话销毁

```java
// 设置 Session 的超时时间（以秒为单位）， 超过指定的时长，Session 就会被销毁
// 1.值为正数的时候，设定 Session 的超时时长
// 2.负数表示永不超时
// 3.如果没有调用 setMaxInactiveInterval() 来指定Session的生命时长，Tomcat 会以Session默认时长为准，Session 默认的超时为30分钟，可以在tomcat的web.xml设置；注意Cookie是累计时长，时间一到就会销毁
public void setMaxInactiveInterval(int interval)
// 获取 Session 的超时时间
public int getMaxInactiveInterval()
// 让当前 Session 会话立即无效
public void invalidate()
```

#### 经典案例

**防止非法进入管理页面** 

- login.html表单提交给LoginCheckServlet.java
- 如果验证成功（用户名不为空，密码为 666666,），则进入管理页面 ManageServelt.java，如果验证不成功，跳转到error.html页面
- 如果用户直接访问 ManageServet.java , 重定向到到 login.html

```html
<!-- login.html -->
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8">
        <title>用户登录</title></head>
    <body><h1>用户登录</h1>
    <form action="/session/loginCheck" method="post">
        用户名：<input type="text" name="username"/><br/><br/>
        密 码：<input type="password" name="password"><br><br/>
        <input type="submit" value="登录">
    </form>
    </body>
</html>

<!-- error.html -->
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Title</title>
</head>
<body>
    <h1>登录失败</h1>
    <a href="login.html" style="text-decoration: none">点击返回重新登录</a>
</body>
</html>
```

```java
// LoginCheckServlet.java
protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
    String username = request.getParameter("username");
    String password = request.getParameter("password");
    if(username != null && password != null){
        if(!"".equals(username) && "666666".equals(password)){
            HttpSession session = request.getSession();
            session.setAttribute("username",username);
            request.getRequestDispatcher("/manageServlet").forward(request,response);
        }else{
            request.getRequestDispatcher("/error.html").forward(request,response);
        }
    }else{
        response.sendRedirect("/login.html");
    }
}

// ManageServlet.java
protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
    HttpSession session = request.getSession();
    Object username = session.getAttribute("username");
    if(username != null){
        response.setContentType("text/html;charset=utf-8");
        PrintWriter writer = response.getWriter();
        writer.println("<h1>用户管理页面</h1>");
        writer.println("欢迎你，管理员: " + (String)username);
        writer.flush();
        writer.close();
    }else{
        response.sendRedirect("/session/login.html");
    }
}
```



# 服务器渲染技术

## JSP基本介绍

JSP 全称是 Java Server Pages，Java 的服务器页面,jsp 本质也是实现了Servlet接口

- 相比 html 而言，html 只能为用户提供静态数据，而 JSP 技术允许在页面中嵌套 java 代码， 为用户提供动态数据
- 相比 Servlet 而言，Servlet很难对数据进行排版，而 jsp很容易对数据进行排版

**代码示例**

![image-20220504160347861](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220504160347861.png) 

```jsp
<!-- 简易计算器 -->
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
    <head>
        <title>jsp计算器</title>
    </head>
    <body>
        <h1>
            <%
                int i = 20;
                int j = 70;
                int res = i + j;
                out.println(i + " + " + j + " = " + res);
            %>
        </h1>
    </body>
</html>
```

## 运行原理 

1. jsp 页面本质是一个 Servlet 程序

2. 第1次访问 jsp 页面的时候，Tomcat 服务器会把 jsp 页面解析成为一个 java源文件，并且对它进行编译成为 class 字 节码程序

    ![image-20220504163246538](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220504163246538.png)

    ```java
    // sum_jsp java的核心代码
    import javax.servlet.*;
    import javax.servlet.http.*;
    import javax.servlet.jsp.*;
    public final class sum_jsp extends org.apache.jasper.runtime.HttpJspBase
        implements org.apache.jasper.runtime.JspSourceDependent,
    org.apache.jasper.runtime.JspSourceImports {
     try {
          // 部分代码
          out.write("\n");
          out.write("\n");
          out.write("<html>\n");
          out.write("    <head>\n");
          out.write("        <title>jsp计算器</title>\n");
          out.write("    </head>\n");
          out.write("    <body>\n");
          out.write("        <h1>\n");
          out.write("            ");
    
                    int i = 20;
                    int j = 70;
                    int res = i + j;
                    out.println(i + " + " + j + " = " + res);
                
          out.write("\n");
          out.write("        </h1>\n");
          out.write("    </body>\n");
          out.write("</html>\n");
        }
    }
    ```

    **HttpJspBase 继承了HttpServlet类**

    ![image-20220504163552184](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220504163552184.png) 

## 常用指令和标签

```jsp
<%@ page import="java.util.HashMap" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" session="false" pageEncoding="utf-8" %>

1. language 表示支持 java 
2. contentType 表示jsp返回的数据类型
3. pageEncoding 表示当前 jsp 页面文件本身的字符集 
4. import 用于导包，导类
5. session 指的是是否会自动创建JSESSIONID

JSP 请求转发标签
<%--
    <jsp:forward page=""></jsp:forward> 是请求转发标签， 
        它的功能就是请求转发 page 属性设置请求转发的路径 
--%>
<jsp:forward page="/bb.jsp"></jsp:forward>
```

## 常用脚本

**声明脚本基本语法**

声明脚本的格式是： <%! 声明 java 代码 %>

作用：定义 jsp 的需要属性、方法、静态代码块和内部类等

**代码示例**

```jsp
<html>
    <head>
        <title>xxx</title>
    </head>
    <body>
        <h1>
            <%!
    		   // 定义属性
                private String name = "jack";
            	// 定义方法
                public String getName(){
                    return name;
                }
            	// 静态代码块
            	static{}
            	// 内部类等等
            %>
        </h1>
    </body>
</html>
```

**表达式脚本基本语法**

表达式脚本的格式是：<%=表达式%> 表达式后不能以分号结束

作用：在 jsp 页面上输出数据

**代码示例**

```jsp
<html>
    <head>
        <title>xxx</title>
    </head>
    <body>
        <h1>
            <%!
    		   // 定义属性
                String name = "jack";
            	// 定义方法
                public String getName(){
                    return name;
                }
            	// 静态代码块
            	static{}
            	// 内部类等等
            %>
            用户名:<%=name%>
            工作<%="java工程师"%>
        </h1>
    </body>
</html>
```

**代码脚本基本语法**

代码脚本的格式是：<%  java代码 %>

作用：可以在 jsp 页面中，编写我们需要的功能

**代码示例**

```java
public class Monster {
    private Integer id;
    private String name;
    private String skill;

    public Monster(Integer id, String name, String skill) {
        this.id = id;
        this.name = name;
        this.skill = skill;
    }

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getSkill() {
        return skill;
    }

    public void setSkill(String skill) {
        this.skill = skill;
    }
}
```

```jsp
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
    <head>
        <title>代码脚本基本语法</title>
    </head>
    <body>
        <%
            ArrayList<Monster> list = new ArrayList<>();
            Monster monster = new Monster(1, "牛魔王", "芭蕉扇");
            Monster monster1 = new Monster(2, "孙悟空", "金箍棒");
            list.add(monster);
            list.add(monster1);
        %>
    <table>
        <tr>
            <th>id</th>
            <th>name</th>
            <th>skill</th>
        </tr>
        <%
            for (int i = 0; i < list.size(); i++) {
                Monster monster2 = list.get(i);
        %>
            <tr>
                <td><%= monster2.getId() %></td>
                <td><%= monster2.getName() %></td>
                <td><%= monster2.getSkill() %></td>
            </tr>
        <%
            }
        %>
    </table>
    </body>
</html>
```

## JSP 注释

```jsp
<%-- jsp注释 --%>
<% 
// 单行注释
/* 多行注释 */ 
/** 文档注释 */ 
%>
<!-- html注释 -->
```

## JSP 内置对象

JSP 内置对象指的是已经创建好的对象, 直接使用 inbuild

**JSP 九大内置对象**

![image-20220505095947979](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220505095947979.png)  

## JSP 域对象

域对象的作用:保存数据,获取数据,共享数据

从作用域范围排序 pageContext < request < session < application

### pageContext

存放的数据只能在当前页面使用

![image-20220505100917593](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220505100917593.png)  

### request

存放的数据在一次 request 请求有效

![image-20220505103250560](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220505103250560.png) 

### session

存放的数据在一次会话有效

![image-20220505102705646](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220505102705646.png)

### application

存放的数据在整个 web 应用运行期间有效, 范围更大

![image-20220505103703658](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220505103703658.png)

### 代码示例

```jsp
<!-- areaObject1 -->
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>areaObject1</title>
</head>
<body>
<h1>areaObject1</h1>
<%
    pageContext.setAttribute("username","罗念笙");
    application.setAttribute("hobby","java");
    session.setAttribute("age","18");
    request.setAttribute("email","1079936125@qq.com ");
%>

<%
    out.println("pageContext: " + pageContext.getAttribute("username").toString());
    out.println("application: " + application.getAttribute("hobby").toString());
    out.println("session: " + session.getAttribute("age").toString());
    out.println("request: " + request.getAttribute("email").toString());
    // request.getRequestDispatcher("/areaObject2.jsp").forward(request,response);
    // response.sendRedirect("/jsp/areaObject2.jsp");
%>
</body>
</html>

<!-- areaObject2 -->
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>areaObject2</title>
</head>
<body>
<h1>areaObject2</h1>
<%
    // out.write(pageContext.getAttribute("username").toString()); 不在同一个页面，无法获取数据
    out.println("application: " + application.getAttribute("hobby").toString()); // 只有当web服务关才无法访问（重新发布就无法访问）
    // out.println("session: " + session.getAttribute("age").toString()); // 会话关闭则无法访问
    // out.println("request: " + request.getAttribute("email").toString()); // 重定向之后无法获取
%>
</body>
</html>
```



## EL 表达式

### 概述

EL 表达式全称：Expression Language，是表达式语言

EL 表达式主要是代替 jsp 页面的表达式脚本<%=%>（${}）

**代码示例**

![image-20220506143756482](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220506143756482.png) 

```jsp
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
</head>
<body>
    <%
        request.setAttribute("username","罗念笙");
    %>
    <h1>jsp表达式</h1>
    name:<%=request.getAttribute("username")%>
    <h1>el表达式</h1>
    name:${username}
</body>
</html>
<!--
	JSP 表达式在输出 null时，输出的时字符串null
	EL 表达式在输出 null 时，输出的是 ""
-->
```



### 常用输出形式

![image-20220506152006190](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220506152006190.png) 

```jsp
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Book</title>
</head>
<body>
    <%
        Book book = new Book();
        book.setName("你是我不及的梦");
        book.setWriter(new String[]{"三毛"});
        List<String> list = new ArrayList<>();
        list.add("罗念笙");
        list.add("张洛融");
        book.setReader(list);
        Map<String, String> map = new HashMap<>();
        map.put("1","很不错的一本书");
        map.put("2","nice");
        book.setTopics(map);
        request.setAttribute("book",book);
    %>
    book:${book}<br/>
    bookName:${book.name}<br/>
    bookWriter:${book.writer[0]}<br/>
    bookReader:${book.reader}<br/>
    bookTopics:${book.topics}<br/>
</body>
</html>
```

```java
public class Book {
    private String name;
    private String[] writer;//作者
    private List<String> reader;//读者
    private Map<String, String> topics;//话题

    @Override
    public String toString() {
        return "Book{" +
                "name='" + name + '\'' +
                ", writer=" + Arrays.toString(writer) +
                ", reader=" + reader +
                ", topics=" + topics +
                '}';
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String[] getWriter() {
        return writer;
    }

    public void setWriter(String[] writer) {
        this.writer = writer;
    }

    public List<String> getReader() {
        return reader;
    }

    public void setReader(List<String> reader) {
        this.reader = reader;
    }

    public Map<String, String> getTopics() {
        return topics;
    }

    public void setTopics(Map<String, String> topics) {
        this.topics = topics;
    }
}
```



###  运算操作

语法：${ 运算表达式 }

**关系运算符**

| 关系运算符 |   说明   |        例子        | 结果  |
| :--------: | :------: | :----------------: | :---: |
|  == 或 eq  |   等于   | ${5==5} 或 ${5eq5} | true  |
|  != 或 ne  |  不等于  | ${5!=5} 或 ${5ne5} | false |
|  < 或 lt   |   小于   | ${3<5} 或 ${3lt5}  | true  |
|  > 或 gt   |   大于   | ${3>5} 或 ${3gt5}  | false |
|  <= 或 le  | 小于等于 | ${3<=5} 或 ${3le5} | true  |
|  >= 或 ge  | 大于等于 | ${3>=5} 或 ${3ge5} | false |

**逻辑运算符**

| 逻辑运算符 |   说明   |                 例子                 | 结果  |
| :--------: | :------: | :----------------------------------: | :---: |
| && 或 and  |  与运算  | ${12=12&&12<11} 或 ${12=12and12<11}  | false |
| \|\| 或 or |  或运算  | ${12=12\|\|12<11} 或 ${12=12or12<11} | true  |
|  ！或 not  | 取反运算 |       ${!true} 或 ${not true}        | false |

**算术运算**

| 算术运算符 | 说明 |           例子           | 结果 |
| :--------: | :--: | :----------------------: | :--: |
|     +      | 加法 |         ${12+18}         |  30  |
|     -      | 减法 |         $(18-8}          |  10  |
|     *      | 乘法 |         $[12*12}         | 144  |
|  / 或 div  | 除法 | ${144/12} 或 ${144div12} |  12  |
|  % 或 mod  | 取模 | ${144%10} 或 ${144mod10} |  4   |

**三元运算**

表达式 1?表达式 2: 表达式 3 

如果表达式1的值为真，返回表达式2的值，反之返回表达式3的值。



### empty运算

**●** **值为** **null** 

**●** **值为空串** 

**●** **值是** **Object** **类型数组，长度为零** 

**● list** **集合，元素个数为零** 

**● map** **集合，元素个数为零**

```jsp
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
    <head>
        <title>EL empty运算</title>
    </head>
    <body><h1>EL 的 empty 运算</h1>
        <% 
        	request.setAttribute("k1", null);
            request.setAttribute("k2", "");
            request.setAttribute("k3", new Object[]{});
            request.setAttribute("k4", new ArrayList<String>());
            request.setAttribute("k5", new HashMap<String, Object>()); 
        %> 
        k1 是否为空= ${empty k1}<br/> 
        k2 是否为空= ${empty k2}<br/> 
        k3是否为空= ${empty k3}<br/> 
        k4 是否为空= ${empty k4}<br/> 
        k5 是否为空= ${empty k5}<br/> 
    </body>
</html>
```



### 内置对象

![image-20220506155254732](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220506155254732.png)

```jsp
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
	<head>
    	<title>EL 获取四个特定域中的属性</title>
    </head>
    <body><h1>EL 获取四个特定域中的属性</h1> 
        <% 
        	pageContext.setAttribute("k", "pageContext");
        	request.setAttribute("k", "request");
        	session.setAttribute("k", "session");
        	application.setAttribute("k", "application"); 
        %>
    <hr/>
    	application 的 key1: ${applicationScope.k}<br/> 
    	pageContext 的 key1: ${pageScope.k}<br/>
   	 	session 的 key1: ${sessionScope.k}<br/> 
        request 的 key1: ${requestScope.k}<br/>
    </body>
</html>
```

**pageContext 对象介绍**

```jsp
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
    <head>
        <title>pageContext 对象的使用</title>
    </head>
    <body>
        <h1>pageContext 对象的使用</h1> 
        <%--
            通过 request 对象来获取和 HTTP 协议相关的数据 
            request.getScheme() 它可以获取请求的协议 
            request.getServerName() 获取请求的服务器ip或域名 
            request.getServerPort() 获取请求的服务器端口号 
            request.getContextPath() 获取当前工程路径 
            request.getMethod() 获取请求的方式（GET或POST） 
            request.getRemoteHost() 获取客户端的ip地址 
            session.getId() 获取会话的唯一标识
		--%>
    <hr/>
    协议： ${pageContext.request.scheme}<br> 
    服务器 ip：${pageContext.request.serverName}<br>
    服务器端口：${pageContext.request.serverPort}<br> 
    工程路径：${pageContext.request.contextPath}<br>
    请求方法：${pageContext.request.method}<br> 
    客户端 ip 地址：${pageContext.request.remoteHost}<br> 
    会话 id：${pageContext.session.id}<br>
        
    <h1>简化pageContext.request获取</h1> 
    <% pageContext.setAttribute("req", request); %> 
    获取请求方法: ${req.method} <br>
    </body>
</html>
```



## JSTL

### 概述

JSTL 标签库 是指 JSP Standard Tag Library JSP 标准标签库

JSTL 是为了替换代码脚本

需要导入的jar包

![image-20220506162752940](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220506162752940.png) 

**JSTL 由五个标签库组成**

|        功能        | 前缀 |                  URI                   |
| :----------------: | :--: | :------------------------------------: |
| 核心标签库（重点） |  c   |   http://java.sun.com/jsp/jstl/core    |
|       格式化       | fmt  |    http://java.sun.com/jsp/jstl/fmt    |
|        函数        |  fn  | http://java.sun.com/jsp/jstl/functions |
|  数据库（不使用）  | sql  |    http://java.sun.com/jsp/jstl/sql    |
|   XML（不使用）    |  x   |    http://java.sun.com/jsp/jstl/xml    |

### 核心标签库

**<c:set />**

```jsp
<%@taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
    <head>
        <title>JSTL</title>
    </head>
    <body>
        <%--
            <c:set/> set 标签可以往域中保存数据 
            1. 等价于域对象.setAttribute(key,value); 
            2. scope 属性设置保存的域 
                page 表示 PageContext 域（默认值） 
                request 表示 Request 域 
                session 表示 Session 域 
                application 表示 ServletContext 域 
            3. var 属性设置key
        --%>
        <c:set scope="request" var="username" value="罗念笙"/>
        ${username}
    </body>
</html>
```

**<c:if />**

```jsp
<%@taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
    <head>
        <title>JSTL</title>
    </head>
    <body>
        <c:if test="${ 10 > 2 }">
            <h1>10 > 2 为真</h1>
        </c:if>
    </body>
</html>
```

**< c:choose > < c:when > < c:otherwise >**

多路判断，类似 switch ... case .... default

```jsp
<%@taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>jstl_choose 标签使用</title>
</head>
<body>
    <h1>jstl_choose 标签使用</h1>
<hr/>
	<% request.setAttribute("money", 100000); %> 
    <c:choose> 
        <c:when test="${ requestScope.money > 20000 }"> 有钱人</c:when>
        <c:when test="${ requestScope.money > 15000 }"> 比较有钱 </c:when> 
        <c:otherwise> 
            <c:choose>
                <c:when test="${ requestScope.money > 10000 }">没啥钱</c:when>
                <c:when test="${requestScope.money > 5000}"> 只够温饱了 </c:when>
                <c:otherwise>饿死</c:otherwise>
            </c:choose>
        </c:otherwise> 
    </c:choose>
</body>
</html>
```

**<c:forEach />**

**●** **普通遍历输出** **i** **到** **j** 

**●** **遍历数组** 

**●** **遍历** **Map** 

**●** **遍历** **List**

**代码示例**

```jsp
<%@ page import="java.util.HashMap" %>
<%@ page import="java.util.Map" %>
<%@taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
</head>
<body>
    <%--
        循环 等价 for (int n = 1; n <= 5; n++){}
        1. 遍历 1 到 5，
        2. 输出 begin 属性设置开始的索引 end 属性设置结束的索引
        3. step 每次遍历增加的值
        4. var 属性表示循环的变量
    --%>
    <h1>循环</h1>
    <c:forEach begin="1" end="5" step="1" var="n">
        ${n}<br>
    </c:forEach>

    <%--
        遍历数组 等价 for (Object item: arr){}
        1. items 遍历的数组或者集合
        2. var 遍历到的数据
    --%>
    <h1>遍历数组</h1>
    <%
        request.setAttribute("key",new String[]{"罗念笙","张洛融"});
    %>
    <c:forEach items="${requestScope.key}" var="item">
        ${item}<br>
    </c:forEach>

    <h1>遍历集合</h1>
    <%
        Map<String, Object> map = new HashMap<>();
        map.put("key1", "北京");
        map.put("key2", "上海");
        map.put("key3", "天津");
        request.setAttribute("map", map);
    %>
    <c:forEach items="${requestScope.map}" var="city">
        ${city.key} -- ${city.value}<br>
    </c:forEach>
</body>
</html>
```



# 监听器 Listener 

## 概述

Listener 监听器它是 JavaWeb 的三大组件之一，JavaWeb 的三大组件分别是：Servlet 程序、Listener 监听器、Filter 过滤器

监听器的作用：监听某种变化(一般就是对象创建/销毁, 属性变化), 触发对应方法完成相应的任务

JavaWeb 中有八个监听器, 目前最常用的是 ServletContextListener

## ServletContextListener

作用：监听 ServletContext 创建或销毁 (当我们 Web 应用启动时，就会创建 ServletContext）即生命周期监听

应用场景

- 加载初始化的配置文件 比如 spring 的配置文件 
- 任务调度（配合定时器 Timer/TimerTask)

方法

```java
void contextInitialized(ServletContextEvent sce)  // 创建 Servletcontext 时触发
void contextDestroyed(ServletContextEvent sce) // 销毁 Servletcontext 时触发
```

**代码示例**

```xml
<?xml version="1.0" encoding="UTF-8"?>
<web-app xmlns="http://xmlns.jcp.org/xml/ns/javaee"
         xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
         xsi:schemaLocation="http://xmlns.jcp.org/xml/ns/javaee http://xmlns.jcp.org/xml/ns/javaee/web-app_4_0.xsd"
         version="4.0">
    <listener>
        <listener-class>com.al_tair.listener.HttpServletContextListener</listener-class>
    </listener>
</web-app>
```

```java
public class HttpServletContextListener implements ServletContextListener {
    @Override
    public void contextInitialized(ServletContextEvent servletContextEvent) {
        System.out.println("ServletContext 被创建");
    }

    @Override
    public void contextDestroyed(ServletContextEvent servletContextEvent) {
        System.out.println("ServletContext 被销毁");
    }
}
```

## ServletContextAttributeListener

作用：监听 ServletContext 属性变化

方法

```java
void attributeAdded(ServletContextAttributeEvent event) // 添加属性
void attributeReplaced(ServletContextAttributeEvent event) // 替换属性 
void attributeRemoved(ServletContextAttributeEvent event)  // 移除属性
```

**示例代码**

![image-20220507133644059](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220507133644059.png) 

```java
// Servlet
@WebServlet(urlPatterns = {"/listener"})
public class ServletListenerDemo extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        System.out.println("doGet被调用");
        ServletContext servletContext = req.getServletContext();
        servletContext.setAttribute("name","罗念笙");
        servletContext.setAttribute("name","张洛融");
        servletContext.removeAttribute("name");
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        doGet(req, resp);
    }
}
// listener
public class HttpServletContextAttributeListener implements ServletContextAttributeListener {
    @Override
    public void attributeAdded(ServletContextAttributeEvent servletContextAttributeEvent) {
        Object name = servletContextAttributeEvent.getServletContext().getAttribute("name");
        if(name != null)
            System.out.println("添加属性" + name.toString());
        else
            System.out.println("添加属性");
    }

    @Override
    public void attributeRemoved(ServletContextAttributeEvent servletContextAttributeEvent) {
        System.out.println("移除属性...");
    }

    @Override
    public void attributeReplaced(ServletContextAttributeEvent servletContextAttributeEvent) {
        System.out.println("替换属性...");
    }
}
```

## HttpSessionListener

作用：监听 Session 创建或销毁，即生命周期监听

方法

```java
void sessionCreated(HttpSessionEvent se)  // 创建 session 时调用 
void sessionDestroyed(HttpSessionEvent se)  // 销毁 session 时调用
```

## HttpSessionAttributeListener

作用：监听 Session 属性的变化

方法

```java
void attributeAdded(ServletRequestAttributeEvent srae) // 添加属性
void attributeReplaced(ServletRequestAttributeEvent srae) // 替换属性
void attributeRemoved(ServletRequestAttributeEvent srae)  // 移除属性
```

## ServletRequestListener

作用：监听 Request 创建或销毁，即 Request 生命周期监听，可以用来监控, 某个 IP 访问我们网站的频率, 日志记录 ,访问资源的情况

方法

```java
void requestInitialized(ServletRequestEvent sre) // 创建 request 
void requestDestroyed(ServletRequestEvent sre) // 销毁 request 
```

## ServletRequestAttributeListener

 作用：监听 Request 属性变化

方法

```java
void attributeAdded(ServletRequestAttributeEvent srae) // 添加属性时
void attributeReplaced(ServletRequestAttributeEvent srae) // 替换属性
void attributeRemoved(ServletRequestAttributeEvent srae) // 移除属性 
```

## 其他监听器

**HttpSessionBindingListener 感知监听器**

**HttpSessionActivationListener 感知监听器**



# 过滤器 Filter

## 概述

Filter 过滤器它是 JavaWeb 的三大组件之一(Servlet 程序、Listener 监听器、Filter 过 滤器)

Filter 过滤器作用：拦截请求，过滤响应

应用场景：权限检查，日记操作，事务管理

Filter 过滤器是 JavaEE 的规范，是接口

```java
public interface Filter {
    void init(FilterConfig var1) throws ServletException;
    void doFilter(ServletRequest var1, ServletResponse var2, FilterChain var3) throws IOException, ServletException;
    void destroy();
}
```

## 框架图

![image-20220507152541754](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220507152541754.png) 

**示例代码**

登录页面

![image-20220507232807198](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220507232807198.png) 

```jsp
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>管理后台登录</title>
</head>
<body>
    <h1>管理后台登录</h1>
    <form action="<%=request.getContextPath() %>/loginCheckServlet" method="post">
        u：<input type="text" name="username"/> <br/>
        p：<input type="password" name="password"/> <br/><br/>
        <input type="submit" value="用户登录"/>
    </form>
</body>
</html>
```

登录检测

```java
@WebServlet(name = "LoginCheckServlet",urlPatterns = {"/loginCheckServlet"})
public class LoginCheckServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doGet(request,response);
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String username = request.getParameter("username");
        String password = request.getParameter("password");
        if("".equals(username) || "".equals(password)){
            System.out.println("登录失败");
            response.sendRedirect(getServletContext().getContextPath() + "/login.jsp");
            return;
        }
        HttpSession session = request.getSession();
        session.setAttribute("name",username);
        session.setAttribute("password",password);
        response.sendRedirect(getServletContext().getContextPath() + "/manage/admin.jsp");
        // request.getRequestDispatcher("/manage/admin.jsp").forward(request,response);
    }
}
```

过滤器

```xml
<?xml version="1.0" encoding="UTF-8"?>
<web-app xmlns="http://xmlns.jcp.org/xml/ns/javaee"
         xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
         xsi:schemaLocation="http://xmlns.jcp.org/xml/ns/javaee http://xmlns.jcp.org/xml/ns/javaee/web-app_4_0.xsd"
         version="4.0">
    <filter>
        <filter-name>FilterDemo</filter-name>
        <filter-class>com.al_tair.filter.FilterDemo</filter-class>
    </filter>
    <filter-mapping>
        <filter-name>FilterDemo</filter-name>
        <url-pattern>/manage/*</url-pattern>
    </filter-mapping>
</web-app>
```

```java
public class FilterDemo implements Filter {

    @Override
    public void init(FilterConfig filterConfig) throws ServletException {
        System.out.println("过滤器初始化成功");
    }

    @Override
    public void doFilter(ServletRequest servletRequest, ServletResponse servletResponse, FilterChain filterChain) throws IOException, ServletException {
        System.out.println("doFilter");
        HttpServletRequest request = (HttpServletRequest) servletRequest;
        HttpServletResponse response = (HttpServletResponse) servletResponse;
        if(request.getSession().getAttribute("name") != null)
            filterChain.doFilter(servletRequest,servletResponse);
        else
            response.sendRedirect(request.getContextPath() + "/login.jsp");
    }

    @Override
    public void destroy() {
        System.out.println("过滤器初销毁成功");
    }
}
```

登陆成功

```jsp
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>管理后台</title>
</head>
    <body>
    <h1>管理后台</h1>
    <h2>登录成功</h2>
    </body>
</html>
```

## Filter生命周期

```java
public class FilterDemo implements Filter {
    // 当web工程启动时，会执行构造器和init方法
    // 创建Filter对象也是单例模式，并且常驻内存直到web工程关闭
    @Override
    public void init(FilterConfig filterConfig) throws ServletException {}
	// 如果匹配到Filter的url-pattern就会调用该方法
    // 请求转发可以跳过过滤器
    @Override
    public void doFilter(ServletRequest servletRequest, ServletResponse servletResponse, FilterChain filterChain) throws IOException, ServletException {
        // FilterChain 接口的 doFilter 方法用于通知 Web 容器把请求交给 Filter 链中的下一个 Filter 去处理，如果当前调用此方法的 Filter 对象是Filter 链中的最后一个 Filter，那么将把请求交给目标 Servlet 程序去处理；如果没有调用该方法默认为拦截，不予通过
        filterChain.doFilter(servletRequest,servletResponse); 
    }
	// 当web工程停止时，会执行destroy方法
    @Override
    public void destroy() {}
}
```

## FilterConfig

FilterConfig 是 Filter 过滤器的配置类，Tomcat 每次创建 Filter 的时候，也会创建一个 FilterConfig 对象，这里包含了 Filter 配置文件的配置信息

FilterConfig 对象作用是获取 filter 过滤器的配置内容 	

FilterConfig接口

```java
public interface FilterConfig {
    // 获取配置的名称
    String getFilterName();
    // 获取ServletContext对象，以便于与Servlet进行数据交互
    ServletContext getServletContext();
    // 获取初始化参数值
    String getInitParameter(String var1);
    // 获取多个初始化参数值
    Enumeration<String> getInitParameterNames();
}
```

```xml
<filter>
    <filter-name>FilterConfig_</filter-name>
    <filter-class>XXX</filter-class>
    <init-param> <!-- 封杀 ip 段 -->
        <param-name>ip</param-name>
        <param-value>128.12</param-value>
    </init-param>
    <init-param>
        <param-name>port</param-name>
        <param-value>8888</param-value>
    </init-param>
</filter>
<filter-mapping>
    <filter-name>FilterConfig_</filter-name>
    <url-pattern>/abc/*</url-pattern>
</filter-mapping>
```

## FilterChain 过滤器链 

FilterChain: 在处理某些复杂业务时，一个过滤器不够，可以设计多个过滤器 共同完成过滤任务，形成过滤器链

### 框架图

![image-20220508151652446](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220508151652446.png)

**代码示例**

AFilter

```java
public class AFilter implements Filter {
    @Override
    public void init(FilterConfig filterConfig) throws ServletException {}

    @Override
    public void doFilter(ServletRequest servletRequest, ServletResponse servletResponse, FilterChain filterChain) throws IOException, ServletException {
        System.out.println("AFilter doFilter");
        filterChain.doFilter(servletRequest,servletResponse);
        System.out.println("AFilter doFilter end");
    }

    @Override
    public void destroy() {}
}
```

BFilter

```java
public class BFilter implements Filter{
    @Override
    public void init(FilterConfig filterConfig) throws ServletException {}

    @Override
    public void doFilter(ServletRequest servletRequest, ServletResponse servletResponse, FilterChain filterChain) throws IOException, ServletException {
        System.out.println("BFilter doFilter");
        filterChain.doFilter(servletRequest,servletResponse);
        System.out.println("BFilter doFilter end");
    }

    @Override
    public void destroy() {}
}
```

web.xml

```xml
<?xml version="1.0" encoding="UTF-8"?>
<web-app xmlns="http://xmlns.jcp.org/xml/ns/javaee"
         xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
         xsi:schemaLocation="http://xmlns.jcp.org/xml/ns/javaee http://xmlns.jcp.org/xml/ns/javaee/web-app_4_0.xsd"
         version="4.0">
    <!--FilterChain 过滤器链 -->
    <filter>
        <filter-name>AFilter</filter-name>
        <filter-class>com.al_tair.filter.AFilter</filter-class>
    </filter>
    <filter-mapping>
        <filter-name>AFilter</filter-name>
        <url-pattern>/index.jsp</url-pattern>
    </filter-mapping>
    <filter>
        <filter-name>BFilter</filter-name>
        <filter-class>com.al_tair.filter.BFilter</filter-class>
    </filter>
    <filter-mapping>
        <filter-name>BFilter</filter-name>
        <url-pattern>/index.jsp</url-pattern>
    </filter-mapping>
</web-app>
```

```jsp
<html>
  <head>
    <title>$Title$</title>
  </head>
  <body>
  <h1>FilterChain 过滤器链 完成</h1>
  </body>
</html>
```

显示顺序

![image-20220508154937305](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220508154937305.png) 

### 注意事项和细节 

- 多个 filter 和目标资源在一次 http 请求，在同一个线程中，使用同一个 request 对象
- 多个 filter 执行顺序，和 web.xml 配置顺序保持一致.



# 线程数据共享和安全 -ThreadLocal

## 概述

ThreadLocal是一个将在多线程中为每一个线程创建单独的变量副本的类; 当使用ThreadLocal来维护变量时, ThreadLocal会为每个线程创建单独的变量副本, 避免因多线程操作共享变量而导致的数据不一致的情况

每一个 ThreadLocal 对象，只能为当前线程关联一个数据，如果要为当前线程关联多个数 据，就需要使用多个 ThreadLocal 对象实例

![image-20220512211018686](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220512211018686.png) 

## 代码示例

![image-20220512234534965](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220512234534965.png) 

```java
public class Dog {}

// ThreadLocalDemo
public class ThreadLocalDemo implements Runnable{
    public static ThreadLocal<Object> threadLocal= new ThreadLocal<>();
    public static void main(String[] args) {
        // 创建进程
        new Thread(new ThreadLocalDemo()).start();
    }

    @Override
    public void run() {
        Dog dog = new Dog();
        threadLocal.set(dog);
        System.out.println("ThreadLocalDemo: " + Thread.currentThread().getName());
        new Service().update();
    }
}

// Service
public class Service {
    public void update() {
        Object o = ThreadLocalDemo.threadLocal.get();
        System.out.println(o.getClass()); // threadLocal.Dog
        String name = Thread.currentThread().getName();
        System.out.println("在 Service 的 update() 线程 name= " + name);
        new Dao().update();
    }
}

// Dao
public class Dao {
    public void update() {
        Object o = ThreadLocalDemo.threadLocal.get();
        System.out.println(o.getClass()); // threadLocal.Dog
        String name = Thread.currentThread().getName();
        System.out.println("在 Dao 的 update() 线程是= " + name);
    }
}
```

## 源码分析

```java
// ThreadLocal.get()方法
public T get() {
    // 获取当前进程t 
    Thread t = Thread.currentThread();
    // 从容器map中获取该线程的threadLocals
    ThreadLocalMap map = getMap(t);
    if (map != null) {
        ThreadLocalMap.Entry e = map.getEntry(this);
        if (e != null) {
            @SuppressWarnings("unchecked")
            T result = (T)e.value;
            return result;
        }
    }
    return setInitialValue();
}

// ThreadLocal.set(数据)方法
public void set(T value) {
    // 获取当前进程t 
    Thread t = Thread.currentThread();
    // 从容器map中获取该线程的threadLocals
    ThreadLocalMap map = getMap(t);
    /*
    ThreadLocalMap getMap(Thread t) {
        return t.threadLocals;
    }
    */
    if (map != null) {
        // 如果存在，则覆盖该 threadLocals对象对应的原来数据（可以是对象）
        map.set(this, value);
    } else {
        // 如果不存在，则创建t.threadLocals，存入ThreadLocalMap对象
        // key:this（调用该方法的threadLocal对象）value:需要存入的数据
        createMap(t, value);
        /*
        void createMap(Thread t, T firstValue) {
            t.threadLocals = new ThreadLocalMap(this, firstValue);
        }
        */
    }
}
```



# web 应用常用功能 -文件上传下载

##  文件上传

文件上传下载需要使用到两个包 , 需要导入

![image-20220512235336933](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220512235336933.png) 

**表单提交**

```html
<!-- 表单的 enctype 属性要设置为 multipart/form-data -->
<!-- 表单默认为url编码是用来传输文本的，文件（二进制数据）需要另外一种编码方式来提交，因此是multipart分多个部分提交-->
<form action="xxxx" method="POST" enctype="multipart/form-data">
    家居图: <img src="2.jpg" alt="" width="200" height="200" id="prevView"> 
    <input type="file" name="pic" id="" value="2xxx.jpg" onchange="prev(this)"/>
    家居名: <input type="text" name="name"><br/> 
    <input type="submit" value="上传"/>
</form>
```

**获取文件上传请求**

1. 判断表单类型（multipart/form-data或者application/x-www-form-urlencoded）
2. 假设是multipart/form-data类型
    1. 判断表单内的数据，是普通文本的表单项，则以文本形式处理
    2. 如果是文件表单项，则使用IO流保存到本地服务器的指定目录
3. application/x-www-form-urlencoded类型则统一都用url解码来处理

**代码示例**

![image-20220513195142871](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220513195142871.png) 

```jsp
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Title</title>
    <base href="<%=request.getContextPath()+"/"%>>">
    <style type="text/css"> input[type="submit"] {
        outline: none;
        border-radius: 5px;
        cursor: pointer;
        background-color: #31B0D5;
        border: none;
        width: 70px;
        height: 35px;
        font-size: 20px;
    }

    img {
        border-radius: 50%;
    }

    form {
        position: relative;
        width: 200px;
        height: 200px;
    }

    input[type="file"] {
        position: absolute;
        left: 0;
        top: 0;
        height: 200px;
        opacity: 0;
        cursor: pointer;
    } </style>
    <script type="text/javascript">
        function prev(event)
        {
            // 获取展示图片的区域
            var img = document.getElementById("prevView");
            // 获取文件对象
            let file = event.files[0];
            // 获取文件阅读器
            let reader = new FileReader();
            reader.readAsDataURL(file);
            reader.onload = function ()
            {
                // 给img的src设置图片url
                img.setAttribute("src", this.result);
            }
        }
    </script>
</head>
    <body>
        <!-- 表单的 enctype 属性要设置为 multipart/form-data -->
        <form action="fileServlet" enctype="multipart/form-data" method="post">
            家居图: <img src="2.jpg" alt="" width="200" height="200" id="prevView">
            <input type="file" name="pic" id="" value="2xxx.jpg" onchange="prev(this)"/><br>
            家居名: <input type="text" name="name"><br/><br/>
            <input type="submit" value="上传"/>
        </form>
    </body>
</html>
```

```java
// 工具类
public class Date {
    public static String getLocalDate(){
        LocalDateTime localDate = LocalDateTime.now();
        return String.valueOf(localDate.getYear()) + "-" + String.valueOf(localDate.getMonth())
                + "-" + String.valueOf(localDate.getDayOfMonth());
    }
}

// 文件上传类
@WebServlet(name = "FileUpload",urlPatterns = {"/fileServlet"})
public class FileUpload extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doGet(request,response);
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        // 判断请求格式是否是文件格式的
        if(ServletFileUpload.isMultipartContent(request)){
            System.out.println("文件传输");
            // 创建DiskFileItemFactory对象，用于构建一个解析上传数据的工具对象
            DiskFileItemFactory diskFileItemFactory = new DiskFileItemFactory();
            // 创建一个解析上传数据的工具对象
            ServletFileUpload servletFileUpload = new ServletFileUpload(diskFileItemFactory);
            servletFileUpload.setHeaderEncoding("utf-8");
            try {
                List<FileItem> list = servletFileUpload.parseRequest(request);
                // 遍历文件项
                for (FileItem fileItem : list) {
                    String name;
                    if(!fileItem.isFormField()){
                        // 文件名
                        name = fileItem.getName();

                        // 指定图片保存的路径
                        String filePath = getServletContext().getRealPath("/images/" + Date.getLocalDate() + "/");

                        File file = new File(filePath);
                        // 该文件目录是否存在
                        if(!file.exists()){
                            file.mkdirs();
                        }

                        // 将文件数据存入到指定目录,同时通过UUID来确定文件不会重名
                        name = UUID.randomUUID().toString() + name;
                        fileItem.write(new File(filePath + name));
                        // 页面显示
                        response.setContentType("text/html;charset=utf-8");
                        response.getWriter().write("<h1>上传成功!</h1>");
                    }else{
                        name = fileItem.getString("utf-8");
                        System.out.println(name);
                    }
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        }else{
            System.out.println("普通文本传输");
        }
    }
}
```

**注意事项**

- 一个完美的文件上传，要考虑的因素很多，比如断点续传、控制图片大小，尺寸，分片 上传，防止恶意上传等，在项目中，可以考虑使用 [WebUploader ](https://fex.baidu.com/webuploader/) 组件
- 文件上传功能，在项目中建议有限制的使用，一般用在头像、证明、合同、产品展示等， 如果不加限制，会造成服务器空间被大量占用



## 文件下载

 ![image-20220513231844910](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220513231844910.png)

```jsp
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8">
        <title>文件下载</title>
        <base href="<%=request.getContextPath()+"/"%>>">
    </head>
    <body>
        <h1>文件下载</h1>
        <a href="download?dir=/imgs/&resource=1.png">点击下载java图片</a><br/>
        <a href="download?dir=/word/&resource=2.doc">点击下载罗念笙笔记.doc</a>
    </body>
</html>
```

![image-20220513232217928](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220513232217928.png) 

```java
@WebServlet(name = "Download",urlPatterns = {"/download"})
public class Download extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doGet(request,response);
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        // 获取下载的文件名字
        request.setCharacterEncoding("utf-8");
        String dir = request.getParameter("dir");
        String fileName = request.getParameter("resource");
        System.out.println(fileName);
        String resourcePath = dir + fileName;

        // 给http响应设置响应头 Content-Type
        ServletContext servletContext = request.getServletContext();
        String mimeType = servletContext.getMimeType(resourcePath);
        response.setContentType(mimeType);
        // 给http响应设置响应头 Content-Disposition
        // 针对不同的浏览器对于下载的编码方式是不一样的
        // Content-Disposition 是指定下载的数据的展示形式 , 如果attachment 则使用文件下载方式
        if(request.getHeader("User-Agent").contains("Firefox")){
            // 火狐 Base64编码
        }else {
            // 其他(主流ie/chrome)使用URL编码操作
            response.setHeader("Content-Disposition", "attachment; filename=" +
                               URLEncoder.encode(fileName, "UTF-8"));
        }
        // 读取数据io流
        InputStream resourceAsStream = servletContext.getResourceAsStream(resourcePath);
        // 通过输出流输出
        ServletOutputStream outputStream = response.getOutputStream();
        // 通过IO工具类将读取到的文件输出
        IOUtils.copy(resourceAsStream,outputStream);
    }
}
```




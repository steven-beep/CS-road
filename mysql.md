# MySql基础

​                                                    																													---   Al_tair

---



## 数据库的初识

### 1.1数据库是什么？

数据库: 英文DataBase 简称DB

​	数据库，顾名思义就是存储数据的仓库，实际上就是一些文件，用来存储特定格式的数据！

### 1.2数据库管理系统是什么？

数据库管理系统：英文DataBaseManagement 简称 DBMS

​	数据库管理系统是专门用来管理数据库中的数据，可以对数据库中的数据进行增删改查

​	常见的数据库管理系统： MySql   Sqlserver  Oracle等等

### 1.3SQL是什么？

SQL 结构化查询语言

我们可以通过学习SQL语言对数据库管理系统进行操作来实现对数据库中的数据增删改查，并且SQL在不同的数据库管理系统中普遍使用

### 1.4三者有什么关系？

我们编写SQL数据库语言，通过数据管理系统实现对数据库中的数据增删改查

简述：DBMS  ----- 执行 --->  SQL ---- 操作 --->  DB  



## 常用数据类型

### 数据类型图

![image-20220325200013952](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220325200013952.png)

![image-20220325192334220](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220325192334220.png)

### 代码示例

```sql
# 文本类型
# 注意区别字符和字节的区别
# size 都指代字符（数字或者汉字）
CHAR(size) -- 固定字符串 最大存储 = 255字符（无论数字还是中文都是一个字符）
VARCHAR(size) -- 可变长度字符串 最大存储 = 65532字节（还有3字节用来记录该字符串长度）
# 如果VARCHAR 不够用，可以考虑使用 MEDIUMTEXT 或者 TEXT 或者 LONGTEXT

# 日期类型
CREATE TABLE `date`(
	birthday DATE, 
	job_time DATETIME,
	login_time TIMESTAMP 
					NOT NULL DEFAULT CURRENT_TIMESTAMP  # 默认当前时间戳
					ON UPDATE CURRENT_TIMESTAMP # 更新时间戳
)
# 插入语句
INSERT INTO `date`(birthday,job_time) 
					VALUES('2022-11-11','2022-11-11 10:10:10');
```



## 数据库的操作

### 三种注释方式

```sql
# 注释
-- 快捷键：ctrl + / ; 取消注释： ctrl + shift + / 
/*
多行注释
*/
```



### 创建和切换数据库

```sql
# 关键字create [if not exists]如果存在该数据库则不会再创建
create database[if not exists]db_name
[DEFAULT]character set:utf8 #默认字符集utf-8
[DEFAULT]collate:utf8_general_ci #默认不区分大小写；utf8_bin区分大小写

# 代码示例
# 解说：创建了一个字符集为utf8的区分大小写的数据库
CREATE DATABASE test CHARACTER SET utf8 COLLATE utf8_bin
# 创建数据库，表的名字的时候为了规避关键字可以使用反引号来解决
CREATE DATABASE `CREATE`

# 切换成test数据库
USE test
```

### 查看和删除数据库

```sql
# 显示数据库
SHOW DATABASES
# 删除数据库
Drop DATABASE xxx
```



### 创建和删除表

```sql
# 创建表
CREATE TABLE person
(
   #  列名  字段类型 
	field1 dataType,
    field1 dataType,
    field1 dataType,
)CHARACTER SET 字符集 COLLATE 校对规则 ENGINE 引擎
CHARACTER SET 字符集：默认为所在数据库字符集
COLLATE 校队规则：默认为所在数据库校对规则

# 代码示例
CREATE TABLE `person` 
(
         # 无符号整形
	`id` INT UNSIGNED,
 	`name` VARCHAR(255),
	`pwd`  VARCHAR(16),
	`birthday` DATE
)

# 删除表
DROP TABLE person
# 查看test表的结构
desc test;
```

### 修改表

```sql
# 修改表名 
RENAME TABLE test to new_test;

# 修改test表的字符集
ALTER TABLE test CHARACTER SET utf8;

# 添加列
ALTER TABLE test ADD col VARCHAR(10);

# 修改列
ALTER TABLE test MODIFY salary DOUBLE;

# 删除列中image列
ALTER TABLE test DROP image;

# 修改列名
ALTER TABLE test CHANGE `name` another_name VARCHAR(30); 
```

 

### 数据操作CRUD

```sql
# 操作表emp
CREATE TABLE emp(
	id INT, NOT NULL
	`name` VARCHAR(20),
	sex CHAR(1),
	birthday DATE,
	entry_date DATE,
	job VARCHAR(20),
	salary FLOAT, NOT NULL DEFAULT 2200 # 默认2200
	resume TEXT
)CHARACTER SET utf8
```

#### insert

```sql
# 注意细节 
# 1.'123' 可以放入到INT类型的数据里
# 2.列出的数据位置必须与列的排列顺序要一致
# 3.字符和日期类型插入的数据需要单引号或者双引号引上
INSERT INTO emp   # 添加全部数据
		VALUES(1,'罗念笙','男','2001-03-18','2022-03-26','XXX',20000,'加油');
INSERT INTO emp (id,`name`,sex) # 添加部分数据
		VALUES(2,'陈勇军','男');
		
# 复制表 将xxx表中的eid,ename,ejob的数据复制到yyy表中id,name,job
INSERT INTO yyy(id,name,job) SELECT eid,ename,ejob FROM xxx
```

#### update

```sql
UPDATE emp SET salary  = 2000; -- 把所有员工的工资改成2000
UPDATE emp SET salary  = 2000 WHERE id = 1; -- 把id=1的员工的工资改成2000 WHERE是条件语句
```

#### delete

```sql
DELETE FROM emp; -- 把所有员工记录删除
DELETE FROM emp WHERE id = 1; -- 把id=1的员工记录删除
```

#### select 

```sql
# 基本语法
# DISTINCT(可选)：去重 ; * 查找所有列  ;  column指的是列名
SELECT [DISTINCT] *|{column1,column2,column3...} FROM emp;

# 给列取别名 （可以分别对多个列名进行设置不同的别名）
# 格式：SELECT 列名 as 别名 FROM 表名;
```



##### 过滤

不进行过滤的数据非常大，导致通过网络传输了多余的数据，从而浪费了网络带宽。因此尽量使用 SQL 语句来过滤不必要的数据，而不是传输所有的数据到客户端中然后由客户端进行过滤。

###### where语句

![image-20220327154839507](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220327154839507.png)

注意：between  small and big  范围前面小于后面

###### 通配符

通配符也是用在过滤语句中，但它只能用于文本字段。

- **%** 匹配 >=0 个任意字符

- **_** 匹配 ==1 个任意字符

    ```sql
    # 使用 Like 来进行通配符匹配
    SELECT *FROM emp WHERE `name` LIKE '罗%'; -- 以罗开头的任意字符
    ```


##### 排序

使用**order by**语句进行排序（位置位于SELECT语句结尾）

- ASC[默认升序]
- DESC[降序]

```sql
#                显示的列                             根据哪个列来排序
# 格式：SELECT 列名或者别名 FROM  表名 WHERE... ORDER BY 列名或者别名 ASC或者DESC
```

##### 函数

###### 统计函数

MySql的主要函数

|  函 数  |      说 明       |
| :-----: | :--------------: |
|  AVG()  | 返回某列的平均值 |
| COUNT() |  返回某列的行数  |
|  MAX()  | 返回某列的最大值 |
|  MIN()  | 返回某列的最小值 |
|  SUM()  |  返回某列值之和  |

COUNT（行数）

```sql
# 查询所有记录的个数
SELECT COUNT(*) FROM emp
# 查询该列的所有行数（注意：排除null）
SELECT COUNT(`name`) FROM emp 
```

SUM（求和）

```sql
# 查询该列所有值之和
SELECT SUM(salary) FROM emp
```

AVG（平均值）

```sql
# 查询该列所有值的平均值
SELECT AVG(salary) FROM emp
```

MAX（最大值）

```sql
# 查询该列所有值的最大值
SELECT MAX(salary) FROM emp
# 查询该列所有值的最小值
SELECT MIN(salary) FROM emp
```

###### 字符串函数

![image-20220327203355592](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220327203355592.png)

```sql
SELECT CHARSET(`name`) FROM emp; -- 返回字符串的字符集
SELECT CONCAT(`name`,'job is',job) FROM emp; -- 连接字符串
# dual 亚元表，系统表，可以用来作为测试表
SELECT INSTR('woshiluoniansheng','sheng') FROM dual; -- 返回substring 在string中出现的位置，没有则返回0
SELECT UCASE(`name`) FROM emp; -- 转换成大写
SELECT LCASE(`name`) FROM emp; -- 转换成小写
SELECT LEFT(`name`,2) FROM emp; -- 从String2中的左边起取length个字符
SELECT LEFT(`name`,2) FROM emp; -- 从String2中的右边起取length个字符
SELECT LENGTH(`name`) FROM emp; -- string长度[按照占用字节]
SELECT REPLACE(`name`,'lns','zlr') FROM emp; -- 用replace_str替换search_str字符串
SELECT STRCMP('lns','zlr') FROM dual; -- 比较字符串
SELECT SUBSTRING(`name`,1,2) FROM emp; -- 从str的position开始[从1开始]，取length个字符
SELECT LTRIM(' LNS ') FROM dual;  -- 去掉前面的空格
SELECT RTRIM(' LNS ') FROM dual;  -- 去掉后面的空格
SELECT TRIM(' LNS ') FROM dual;  -- 去掉前后的空格
```

###### 数学函数

![image-20220328154559847](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220328154559847.png) 

```sql
SELECT ABS(-10) FROM dual; -- 10
SELECT CEILING(-1.1) FROM dual; -- -1
SELECT FLOOR(1.1) FROM dual; -- 1
SELECT FORMAT(78.2356,2) FROM dual; -- 78.24
SELECT RAND() FROM dual; -- 返回随机数 范围[0,1.0]
SELECT RAND(3) FROM dual; -- 返回随机数 范围[0,1.0] 但是seed = 3不变，该随机数也就不变了
```

###### 时间日期

![image-20220328163915061](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220328163915061.png)

```sql
SELECT CURRENT_DATE() FROM dual; -- 当前日期 2022-03-28
SELECT CURRENT_TIME() FROM dual; -- 当前时间 16:41:27
SELECT CURRENT_TIMESTAMP() FROM dual; -- 当前时间戳 2022-03-28 16:42:18
SELECT DATE(CURRENT_TIMESTAMP()) FROM dual; -- 显示日期 2022-03-28
SELECT NOW() FROM dual; -- 当前日期和时间 2022-03-28 16:50:55
SELECT DATE_ADD(CURRENT_TIMESTAMP(),INTERVAL 10 MINUTE) FROM dual; -- 2022-03-28 16:59:34 十分钟以后
SELECT DATEDIFF(NOW(),'2001-3-18') FROM dual; -- 我活了7680天
SELECT UNIX_TIMESTAMP FROM dual; -- 返回的是1970-1-1 到现在的秒数
# 意义：开发中，可以存放一个整数，然后表示，通过FROM_UNIXTIME转换
SELECT FROM_UNIXTIME(1618483408,'%Y-%m-%d %H:%i:%s') FROM dual;  -- 2021-04-15 18:43:28
```

###### 流程控制函数

![image-20220328190030824](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220328190030824.png)

```sql
# 说明
IF(expr1,expr2,expr3); -- 等价于java的三元运算
IFNULL(expr1,expr2); -- 等价于如果expr1不为NULL返回expr1,反之返回expr2
```

###### 加密函数（扩展）

```sql
# md5加密
SELECT MD5('LUO12345') FROM dual; -- 70e4a6f2316f83d10718b2d251ec8c58 32位十六进制密文
# PASSWORD(str)加密 MYSQL数据库密码就是用这个函数加密的
SELECT PASSWORD('LUO12345') FROM dual;  -- D0D23440C6FBE6CD05E079658CE805F8A3589D1C
```



**雇员系统表**

```sql
# 部门表
CREATE TABLE dept( 
deptno MEDIUMINT   UNSIGNED  NOT NULL  DEFAULT 0, 
dname VARCHAR(20)  NOT NULL  DEFAULT "",
loc VARCHAR(13) NOT NULL DEFAULT ""
);
 
INSERT INTO dept VALUES(10, 'ACCOUNTING', 'NEW YORK'), (20, 'RESEARCH', 'DALLAS'), (30, 'SALES', 'CHICAGO'), (40, 'OPERATIONS', 'BOSTON');

# 创建表EMP雇员
CREATE TABLE emp
(empno  MEDIUMINT UNSIGNED  NOT NULL  DEFAULT 0,  -- 编号
ename VARCHAR(20) NOT NULL DEFAULT "",  -- 名字
job VARCHAR(9) NOT NULL DEFAULT "", -- 工作
mgr MEDIUMINT UNSIGNED , -- 上级编号
hiredate DATE NOT NULL, -- 入职时间
sal DECIMAL(7,2)  NOT NULL, -- 薪水
comm DECIMAL(7,2) , -- 红利
deptno MEDIUMINT UNSIGNED NOT NULL DEFAULT 0  -- 部门编号
);
 
INSERT INTO emp VALUES(7369, 'SMITH', 'CLERK', 7902, '1990-12-17', 800.00,NULL , 20), 
(7499, 'ALLEN', 'SALESMAN', 7698, '1991-2-20', 1600.00, 300.00, 30),  
(7521, 'WARD', 'SALESMAN', 7698, '1991-2-22', 1250.00, 500.00, 30),  
(7566, 'JONES', 'MANAGER', 7839, '1991-4-2', 2975.00,NULL,20),  
(7654, 'MARTIN', 'SALESMAN', 7698, '1991-9-28',1250.00,1400.00,30),  
(7698, 'BLAKE','MANAGER', 7839,'1991-5-1', 2850.00,NULL,30),  
(7782, 'CLARK','MANAGER', 7839, '1991-6-9',2450.00,NULL,10),  
(7788, 'SCOTT','ANALYST',7566, '1997-4-19',3000.00,NULL,20),  
(7839, 'KING','PRESIDENT',NULL,'1991-11-17',5000.00,NULL,10),  
(7844, 'TURNER', 'SALESMAN',7698, '1991-9-8', 1500.00, NULL,30),  
(7900, 'JAMES','CLERK',7698, '1991-12-3',950.00,NULL,30),  
(7902, 'FORD', 'ANALYST',7566,'1991-12-3',3000.00, NULL,20),  
(7934,'MILLER','CLERK',7782,'1992-1-23', 1300.00, NULL,10);

# 工资级别表
CREATE TABLE salgrade
(
grade MEDIUMINT UNSIGNED NOT NULL DEFAULT 0, -- 工资级别
losal DECIMAL(17,2)  NOT NULL, -- 该级别的最低工资
hisal DECIMAL(17,2)  NOT NULL -- 该级别的最高工资
);

INSERT INTO salgrade VALUES (1,700,1200);
INSERT INTO salgrade VALUES (2,1201,1400);
INSERT INTO salgrade VALUES (3,1401,2000);
INSERT INTO salgrade VALUES (4,2001,3000);
INSERT INTO salgrade VALUES (5,3001,9999);
```

##### 分组查询

分组就是把具有相同的数据值的行放在同一组中。

```sql
# 显示每个部门的平均工资和最高工资 注意题目：每个部门
SELECT deptno,AVG(sal) AS avgSal, MAX(sal) AS maxSal FROM emp GROUP BY deptno

# WHERE 过滤行，HAVING 过滤分组，行过滤应当先于分组过滤 这就是为什么这里用 HAVING
# 显示平均工资低于2000的部门号和它的平均工资 注意题目：平均工资低于2000
SELECT deptno,AVG(sal) AS avgSal FROM emp GROUP BY deptno HAVING avgSal < 2000 
```

注意细节

1. 排列顺序：GROUP BY 子句出现在 WHERE 子句之后，ORDER BY  和 HAVING子句之前
2. NULL 的行会单独分为一组
3. 大多数 SQL 实现不支持 GROUP BY 列具有可变长度的数据类型 

##### 分页查询

```sql
# 基本语法：SELECT ... LIMIT start,rows 
# 限制返回的行数。可以有两个参数，第一个参数start为起始行，从 0 开始；第二个参数rows为返回的总行数。
SELECT * FROM 表名 ORDER BY 列名 LIMIT 每页显示记录数*（第n页数-1）,每页显示的记录数 
```

##### 语句顺序

**总结顺序：where -> group by -> having -> order by -> limit**

```sql
SELECT column1,column2,column3... FROM table
			WHERE ... -- 行过滤
			GROUP BY column -- 分组查询
			HAVING ... -- 分组过滤
			ORDER BY column -- 按字段排序 ASC DESC
			limit start,rows; -- 分页查询
```

#####  多表查询

顾名思义：查询两张及两张以上的表

```sql
# 查询雇员名，雇员工资以及部门的名字（分别来自emp和dept表）
# 注意：如果需要指定某个表的列名，可以采用表名.列名的方式进行查询
SELECT emp.ename,emp.sal,dept.dname FROM emp,dept
							WHERE emp.deptno = dept.deptno
```

##### 子查询

子查询也叫嵌套查询，嵌入在其他sql语句中的查询语句

###### 单行子查询

```sql
# 显示与'SMITH'同一个部门的员工
SELECT *FROM emp WHERE deptno = (
				  SELECT deptno FROM emp WHERE ename = 'SMITH'
		        ) AND ename != 'SMITH';
```

###### 多行子查询 

```sql
# 查询部门号为10的工作相同的雇员的名字，岗位，工资，部门号，但是不包括该部门号的员工
SELECT ename,job,sal,deptno 
				FROM emp	
				WHERE job IN (
                       SELECT DISTINCT job 
                    		   FROM emp 
                                WHERE deptno = 10
                 ) AND deptno != 10;
                 
 # 显示工资比部门30的所有员工的工资高的员工姓名，工资和部门号
 # 注意 ALL的使用
 SELECT ename,sal,deptno FROM emp
					WHERE sal > ALL(
							SELECT sal FROM emp 
                        		WHERE deptno = 30
					)
					
 # 显示工资比部门30的其中一个员工的工资高的员工姓名，工资和部门号
 # 注意 ANY的使用
 SELECT ename,sal,deptno FROM emp
					WHERE sal > ANY(
							SELECT sal FROM emp 
                        		WHERE deptno = 30
					)
```

###### 多列子查询

查询返回多个列数据的子查询

```sql
# 查询与'ALLEN'的部门和岗位完全相同的所有雇员（不包含'ALLEN'本人）
SELECT *FROM emp  WHERE (deptno,job) = (
						SELECT deptno,job FROM emp 
									WHERE ename = 'ALLEN'
					) AND ename != 'ALLEN';
```

#####  组合查询

使用 **UNION** 来组合两个查询，如果第一个查询返回 M 行，第二个查询返回 N 行，那么组合查询的结果一般为 M+N 行；默认会去除相同行，如果需要保留相同行，使用 UNION ALL

注意：每个查询必须包含相同的列、表达式和聚集函数；只能包含一个 ORDER BY 子句，并且必须位于语句的最后。

```sql
# 合并工资大于2500和职位是经理的员工表
SELECT ename,sal,job FROM emp WHERE sal > 2500 UNION
SELECT ename,sal,job FROM emp WHERE job = 'MANAGER'
```

##### 连接

###### 自连接

自连接可以看成内连接的一种，只是连接的表是自身而已。

可以理解为把一张表当成两张表来查询（员工和上级都在同一张表）

![image-20220330185145767](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220330185145767.png) 

```sql
SELECT worker.ename AS '职员名',boss.ename  AS '上级名'FROM emp worker,emp boss
													WHERE worker.mgr = boss.empno;
```

###### 外连接

- 左外连接 (LEFT JOIN … ON) 左边的表必须完全显示
- 右外连接 (RIGHT JOIN… ON) 右边的表必须完全显示

不管是左外连接还是右外连接，本质就是区分主表和次表

 stu表

|  id  |  name  |
| :--: | :----: |
|  1   |  Jack  |
|  2   | Marry  |
|  3   |  Tom   |
|  4   | Steven |

exam表

|  id  | grade |
| :--: | :---: |
|  1   |  85   |
|  2   |  68   |
|  5   |  98   |

左外连接

|  id  |  name  | grade |
| :--: | :----: | :---: |
|  1   |  Jack  |  85   |
|  2   | Marry  |  68   |
|  3   |  Tom   | NULL  |
|  4   | Steven | NULL  |

```sql
SELECT stu.id,`name`,grade FROM stu LEFT JOIN exam ON stu.id = exam.id 
```

右外连接

|  id  | name  | grade |
| :--: | :---: | :---: |
|  1   | Jack  |  85   |
|  2   | Marry |  68   |
| NULL | NULL  |  98   |

```sql
SELECT stu.id,`name`,grade FROM stu RIGHT JOIN exam ON stu.id = exam.id 
```



### 约束

用于确保数据库的数据满足特定的商业规则

包括：not null ，unique，primary key，foreign key，check

#### 主键（primary key）

概念：用于唯一的标识表行的数据，当定义主键约束时，该列数据值不能重复

格式：字段名 字段类型 primary key

注意细节

- 主键不能重复也不能为NULL的数据

- 一张表最多只有一个主键，但可以是复合主键（复合主键是指把多个字段设置为主键）

    ```sql
      SELECT TABLE `table`(
     		id INT PRIMARY KEY, -- 主键 
             `name` VARCHAR(32),
     )
     SELECT TABLE `table`(
     		id INT, 
             `name` VARCHAR(32),
             email VARCHAR(32),
             PRIMARY KEY(id,`name`), -- 复合主键
     )
    ```

#### 非空（not null）

如果在列上定义了not null约束，则该列字段数值不能为空

格式：字段名 字段类型 NOT NULL

#### 唯一（unique）

当定义了唯一约束后，该列字段数值不能重复（但是可以有多个字段值为NULL）

格式：字段名 字段类型 UNIQUE

#### 外键（foreign key）

如果我们把如下的表中的学生表里的class_id（依附于班级表里的id）将其作为外键，如果要添加学生就要先判断先学生中的class_id是否存在于班级表中的id里，如果没有则添加不成功

```sql
CREATE TABLE `class`( -- 主表
	id INT PRIMARY KEY,
    `name` VARCHAR(32) NOT NULL DEFAULT '',
     address VARCHAR(32)
);
INSERT INTO `class` VALUES(1,'java','杭州');
INSERT INTO `class` VALUES(2,'大数据','义乌');

CREATE TABLE stu( -- 外键所在表
	 id INT PRIMARY KEY,
     `name`VARCHAR(32),
     class_id INT ,
	FOREIGN KEY(class_id) REFERENCES `class`(id) -- 外键用法
)
INSERT INTO stu VALUES(31,'Steven',1);
INSERT INTO stu VALUES(30,'Jack',2);
/*
    Cannot add or update a child row: 
    a foreign key constraint fails 外键约束失败
*/
INSERT INTO stu VALUES(32,'Marry',3); -- error
```

班级表（主表）

|  id  | class_name | address |
| :--: | :--------: | :-----: |
|  1   |    java    |  杭州   |
|  2   |   大数据   |  义乌   |

学生表（外键所在表）

|  id  |  name  |    class_id     |
| :--: | :----: | :-------------: |
|  31  | Steven |        1        |
|  30  |  Jack  |        2        |
|  32  | Marry  | 3（添加不成功） |

注意细节

- 外键字段的类型必须和主表字段类型一样（长度可以不同）
- 外键字段的值必须在主表字段中出现，或者为null，否则无法添加该外键字段数据
- 添加数据主表要先于外键所在表；删除数据外键所在表要先于主表

#### check约束

用于强制数据必须满足的条件

注意：目前mysql5.7不支持check，但是oracle，sqlserver和mysql8.0均支持

格式：字段名 字段类型 CHECK (约束条件) 

#### 自增长

整型数据从1自增长（自增长修饰的一般都是整数型）

格式：字段名 整型 PRIMARY KEY   AUTO_INCREMENT

![image-20220402164050350](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220402164050350.png) 

```sql
# 创建表
CREATE TABLE test(
	id INT PRIMARY KEY AUTO_INCREMENT,
	`name` VARCHAR(32)
)
# 插入表(两种形式)
INSERT INTO test VALUES(NULL,'jack');
INSERT INTO test(name) VALUES('marry');
```

注意细节

- 自增长要么和主键要么和唯一配合

- 可以修改默认的自增长的开始值

    ```sql
    ALTER TABLE test AUTO_INCREMENT = 100
    ```



### 索引

#### 索引机制（简述）

索引底层就是B+Tree原理

![image-20220402190741727](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220402190741727.png) 

B Tree 指的是 Balance Tree，也就是平衡树。平衡树是一颗查找树，并且所有叶子节点位于同一层。

B+ Tree 是基于 B Tree 和叶子节点顺序访问指针进行实现，它具有 B Tree 的平衡性，并且通过顺序访问指针来提高区间查询的性能。

#### 索引的类型

- 主键索引，主键自动的为主索引（PRIMARY KEY）添加主键就默认添加了索引

- 唯一索引（UNIQUE）

- 普通索引（INDEX）（最常用）

- 全文索引（FULL TEXT）(关键字搜索)

    开发中全文索引一般使用的是Solr和ElasticSearch而不用MyISAM（Mysql自带的）

**创建索引**

```sql
# 创建索引
CREATE UNIQUE INDEX id_index ON emp(deptno); -- 唯一索引
CREATE INDEX id_index ON emp(deptno); -- 普通索引
ALTER TABLE emp ADD INDEX id_index (id); -- 普通索引添加方式2
ALTER TABLE emp ADD ADD PRIMARY KEY id_index (id); -- 主键索引
```

**删除索引**

```sql
# 根据索引名来删除
DROP INDEX id_index ON emp;
# 删除主键索引
ALTER TABLE emp	DROP PRIMARY KEY
```

**查询索引**

```sql
# 查询表是否有索引
SHOW INDEXES FROM emp; -- 方式一
SHOW INDEXES FROM emp; -- 方式二
SHOW KEYS FROM emp; -- 方式三
DESC emp; -- 方式四
```

**索引的应用场景**

- 比较频繁查询的字段应该创建索引；更新比较频繁的字段不适合建立索引
- 唯一性太差的字段不适合单独创建索引（比如性别）



### 事务

事务由一组dml（update,insert,delete）语句组成，用于保证数据的一致性

当执行事务操作时，mysql会在表上加锁，防止其他用户更改表的数据

#### 事务的基本操作 

- start transaction 开始一个事务（默认在开始事务处设置一个保存点）
- savepoint 设置保存点
- rollback to 回退事务
- rollback 回退所有事务
- commit 提交事务，不能再回退了

不能回退 SELECT 语句，回退 SELECT 语句也没意义；也不能回退 CREATE 和 DROP 语句

回退事务操作

```sql
# 开启事务
START TRANSACTION; -- 或者 SET autocommit = off; 也是开启事务
# 设置保存点m
SAVEPOINT m;
# 进行dml操作
INSERT INTO stu VALUES(32,'marry',1);
SELECT *FROM stu
# 设置保存点n
SAVEPOINT n;
# 进行dml操作
INSERT INTO stu VALUES(33,'tom',1);
# 回退事务m
ROLLBACK TO m
# 回退事务n
ROLLBACK TO n
```

![image-20220403142400675](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220403142400675.png) 

注意细节

- 如果不开始事务的时候，默认dml操作是自动提交的，不能进行回滚
- 如果开始事务，你没有创建保存点，但是你可以执行rollback（回退所有事务），默认就是回退到你事务开始的状态
- 如果从12：00回退到10：00，将删除10：00~12：00的保存点
- mysql的事务操作必须使用InnoDB存储引擎，MyISAM不支持

- 



#### 事务的隔离级别

概念：多个连接开启各自事务操作数据库中的数据时，数据库系统要负责隔离操作，以保证各个连接在获取数据时的准确性

|    种类    |                             概述                             |
| :--------: | :----------------------------------------------------------: |
|    脏读    | 当一个事务读取另一个事务尚**未提交**的修改数据（dml操作），称作脏读 |
| 不可重复读 | 由于其他**提交**事务所做的**修改或者删除**影响了当下事务的查询 |
|    幻读    |  由于其他**提交**事务所做的**插入**操作影响了当下事务的查询  |

![image-20220403145137550](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220403145137550.png)

```sql
# 设置事务隔离级别为读未提交
# 注意事务隔离一定要在事务开启之后谈隔离，不然就没有意义了
SET SESSION TRANSACTION ISOLATION LEVEL READ UNCOMMITTED;
# 查询事务隔离级别
SELECT @@tx_isolation;
```

#### 事务的ACID特性

- 原子性（Atomicity）：事务时一个不可分割的工作单位，事务中的操作要么都发生要么都不发生
- 一致性（Consistency）：事务必须使数据库从一个一致性状态转换成另外一个一致性状态
- 隔离性（Isolation）：多个用户访问数据库时，数据库为每一个用户开启事务，不能被其他事务的操作所影响
- 持久性（Durability）：一个事务一旦被提交，它对数据库中的数据改变是永久的，不能进行回滚 



### 存储引擎 

mysql数据库的表类型是由存储引擎决定

主要包括六种，分别是：

非事务安全性型：CSV，Memory，ARCHIVE，MRG_MYISAM，MYISAM

事务安全型：Inno`DB

```sql
# 查看所有的存储引擎
SHOW ENGINE;
# 修改表的存储引擎
ALTER TABLE `表名` ENGINE = 存储引擎；
```

#### 存储引擎特点

- memory 存储引擎

    数据存储在内存中【关闭数据库服务，数据丢失，但是表的结构还在】

    执行数度很快

    默认支持索引（hash表）

- InnoDB存储引擎

    - 支持事务
    - 支持外键

![image-20220403170505081](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220403170505081.png)

#### 应用场景

1. 不需要处理事务，只进行基本的CRUD操作，选择MYISAM
2. 需要事务处理，选择InnoDB
3. 不需要存储起来，就是短时间的实时状态（比如：用户状态：在线/离线等）,操作频繁，选择memory 



### 视图

视图是虚拟的表，本身不包含数据，其数据都来自对应的真实的表(基表)，也就不能对其进行索引操作。

视图特点

- 视图可以修改基表的数据，基表数据的改变会影响视图（因为视图的数据来自基表）

    ```java
    UPDATE view1 SET ename = '程序员' WHERE empno = 7499;
    ```

- 通过只给用户访问视图的权限，保证数据的安全性

- 简化复杂的 SQL 操作，比如复杂的连接

- 视图可以再使用视图（可以嵌套）

#### 视图的操作

```sql
# 创建视图
CREATE VIEW 视图名 AS SELECT ...
CREATE VIEW view1 AS SELECT empno,ename FROM emp;  -- 显示empno，ename在emp基表中的数据
# 更改视图数据
ALTER VIEW 视图名 AS SELECT ...
# 显示视图
SHOW CREATE VIEW 视图名
# 删除视图
DROP VIEW 视图名1，视图名2
```

### 存储过程

存储过程可以看成是对一系列 SQL 操作的批处理。

使用存储过程的好处:

- 代码封装，保证了一定的安全性；
- 代码复用；
- 由于是预先编译，因此具有很高的性能。

命令行中创建存储过程需要自定义分隔符，因为命令行是以 ; 为结束符，而存储过程中也包含了分号，因此会错误把这部分分号当成是结束符，造成语法错误。

包含 in、out 和 inout 三种参数。

给变量赋值都需要用 select into 语句。

每次只能给一个变量赋值，不支持集合的操作。



## 权限管理

权限表

![image-20220403203427992](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220403203427992.png) 

### 用户的管理

不同的数据库用户，登录到DBMS后，根据相应的权限，可以操作的数据库和数据对象都不一样

创建用户

```sql
#  创建用户 用户名 @ 登录的IP          password('123456')加密后的密码
CREATE USER 'lns'@'localhost' IDENTIFIED BY '123456'
```

查询用户

```sql
# 查询所有用户权限
SELECT *FROM mysql.user;
```

修改用户

```sql
# 修改r密码
SET PASSWORD FOR 'root'@'localhost' = PASSWORD('1234567')
```

删除用户

```sql
# 删除用户  用户名 @ 登录的IP
DROP USER 'lns'@'localhost'
```

### 授权

给用户授权

```sql
GRANT 权限列表 on 库.表名 to '用户名'@'登录IP' [IDENTIFIED BY '密码'] -- 密码可添加，如果存在该对象，则修改该表的密码
# 权限列表
GRANT SELECT ON ... -- 开放查询权限
GRANT SELECT,DELETE,UPDATE,CREATE ON ... -- 开放多个权限
GRANT ALL ON ... -- 开放所有权限

# 库.对象名 改成 *.* 代表所有数据库中的表（表，视图，存储过程）
# 库.对象名 改成 库.* 代表该库中的所有表
```

回收授权

GRANT 和 REVOKE 可在几个层次上控制访问权限:

- 整个服务器，使用 GRANT ALL 和 REVOKE ALL；
- 整个数据库，使用 ON database.*；
- 特定的表，使用 ON database.table；
- 特定的列；
- 特定的存储过程。

```sql
REVOKE 权限列表 ON 库.对象名 FROM '用户名'@'登录IP'
```

**注意细节**

1. 在创建用户的时候，如果不指定host，则为%，%表示所有IP都有连接权限
2. 在删除用户的时候，如果host不是%，必须要具体明确指定

# JDBC和连接池 

## JDBC

### JDBC概述

java程序代码通过使用JDBC可以连接任何提供了JDBC驱动的数据库，从而完成对数据库的操作

![image-20220405141547540](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220405141547540.png) 

#### JDBC基本原理图

JDBC API就是图中的接口规范，它统一了java应用程序和数据库的连接等操作

![image-20220405144420570](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220405144420570.png) 

#### JDBC程序编写

1. 注册驱动 - 加载Driver类
    - Driver ：每个驱动程序类必须实现的接口
    - DriverManage ：用于管理一组JDBC驱动程序的基本服务。
2. 获取连接 - 得到Connection
3. 执行增删改查 - 发送SQL语句给mysql数据库执行
4. 释放资源 - 关闭相关的连接

**连接数据库代码实现**

```java
// 方式一:静态加载
public static void main(String[] args) throws SQLException {
    // 1. 注册驱动 - 加载Driver类
    Driver driver = new Driver();

    // 2. 获取连接 - 得到Connection
    String url = "jdbc:mysql://localhost:3308/al_tair";
    // 将用户名和密码放入到Properties对象中
    Properties properties = new Properties();
    properties.setProperty("user","XXX"); // 用户
    properties.setProperty("password","XXXXXX"); // 密码
    Connection connect = driver.connect(url, properties);

    // 3. 执行增删改查 - 发送SQL语句给mysql数据库执行
    String sql = "insert into dog values(2,'steven')";
    // statement用于执行静态sql语句并返回其生成的结果对象,后面具体详讲
    Statement statement = connect.createStatement();
    int rows = statement.executeUpdate(sql); // 返回是否添加成功
    System.out.println(rows>0? "添加成功" : "添加失败");

    // 4. 释放资源 - 关闭相关的连接
    statement.close();
    connect.close();
}

// 方式二:动态加载
// 1. 注册驱动 - 使用反射加载Driver类
public static void main(String[] args) throws ClassNotFoundException, IllegalAccessException, InstantiationException, SQLException {
     // 1. 注册驱动 - 使用反射加载Driver类
     Class cls = Class.forName("com.mysql.jdbc.Driver");
     Driver driver = (Driver) cls.newInstance();

     // 2. 获取连接 - 得到Connection
     String url = "jdbc:mysql://localhost:3308/al_tair";
     // 将用户名和密码放入到Properties对象中
     Properties properties = new Properties();
     properties.setProperty("user","XXX"); // 用户
     properties.setProperty("password","XXXXXX"); // 密码
     Connection connect = driver.connect(url, properties);

     // 3. 执行增删改查 - 发送SQL语句给mysql数据库执行
     String sql = "insert into dog values(3,'marry')";
     // statement用于执行静态sql语句并返回其生成的结果对象
     Statement statement = connect.createStatement();
     int rows = statement.executeUpdate(sql); // 返回是否添加成功
     System.out.println(rows>0? "添加成功" : "添加失败");

     // 4. 释放资源 - 关闭相关的连接
     statement.close();
     connect.close();
 }

// 方式三:DriverManage 
public static void main(String[] args) throws ClassNotFoundException, IllegalAccessException, InstantiationException, SQLException {
    // 1. 注册驱动 - 加载Driver类 - DriverManage ：用于管理一组JDBC驱动程序的基本服务
    Class cls = Class.forName("com.mysql.jdbc.Driver");
    Driver driver = (Driver) cls.newInstance();
    String url = "jdbc:mysql://localhost:3308/al_tair";
    String root = "XXX";
    String pwd = "XXXXXX";
    // 注册驱动
    DriverManager.registerDriver(driver);

    // 2. 获取连接 - 得到Connection
    Connection connection = DriverManager.getConnection(url, root, pwd);

    // 3. 执行增删改查 - 发送SQL语句给mysql数据库执行
    String sql = "insert into dog values(4,'tony')";
    // statement用于执行静态sql语句并返回其生成的结果对象
    Statement statement = connection.createStatement();
    int rows = statement.executeUpdate(sql); // 返回是否添加成功
    System.out.println(rows>0? "添加成功" : "添加失败");

    // 4. 释放资源 - 关闭相关的连接
    statement.close();
    connection.close();
}

// 方式四：方式三的简化版（推荐）
/*
Driver 原码分析：注册Driver在静态代码块中已经实现
public class Driver extends NonRegisteringDriver implements java.sql.Driver {
    public Driver() throws SQLException {
    }
    static {
        try {
            DriverManager.registerDriver(new Driver());
        } catch (SQLException var1) {
            throw new RuntimeException("Can't register driver!");
        }
    }
}
*/
public static void main(String[] args) throws IllegalAccessException, InstantiationException, ClassNotFoundException, SQLException {
    Class cls = Class.forName("com.mysql.jdbc.Driver");
    String url = "jdbc:mysql://localhost:3308/al_tair";
    String root = "XXX";
    String pwd = "XXXXXX";

    // 1. 获取连接 - 得到Connection
    Connection connection = DriverManager.getConnection(url, root, pwd);

    // 2. 执行增删改查 - 发送SQL语句给mysql数据库执行
    String sql = "insert into dog values(5,'jack')";
    // statement用于执行静态sql语句并返回其生成的结果对象
    Statement statement = connection.createStatement();
    int rows = statement.executeUpdate(sql); // 返回是否添加成功
    System.out.println(rows > 0 ? "添加成功" : "添加失败");

    // 3. 释放资源 - 关闭相关的连接
    statement.close();
    connection.close();
}

// 方式五：mysql5.1.6可以无需手动反射Driver类，会自动调用驱动jar下的驱动包
public static void main(String[] args) throws SQLException {
    String url = "jdbc:mysql://localhost:3308/al_tair";
    String root = "root";
    String pwd = "luo1234567";

    // 1. 获取连接 - 得到Connection
    Connection connection = DriverManager.getConnection(url, root, pwd);

    // 2. 执行增删改查 - 发送SQL语句给mysql数据库执行
    String sql = "insert into dog values(6,'son')";
    // statement用于执行静态sql语句并返回其生成的结果对象
    Statement statement = connection.createStatement();
    int rows = statement.executeUpdate(sql); // 返回是否添加成功
    System.out.println(rows > 0 ? "添加成功" : "添加失败");

    // 3. 释放资源 - 关闭相关的连接
    statement.close();
    connection.close();
}
```

![image-20220405172744703](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220405172744703.png)

**使用配置文件读入来连接数据库**

```java
// Properties.properties
root = root
pwd = XXXXXX
url = jdbc:mysql://localhost:3308/al_tair
driver = com.mysql.jdbc.Driver
    
// package com.Al_tair.connectMySql.myJDBC;
public class JdbcDemo6 {
    public static void main(String[] args) throws IOException, SQLException {
        Properties properties = new Properties();
        String filePath = "E:\\Java_training\\Java_code\\JavaIdea03\\java\\Javase_HSping\\src\\com\\Al_tair\\connectMySql\\myJDBC\\Properties.properties";
        properties.load(new FileInputStream(filePath));
        String url = properties.getProperty("url");
        String root = properties.getProperty("root");
        String pwd = properties.getProperty("pwd");
        // 1. 获取连接 - 得到Connection
        Connection connection = DriverManager.getConnection(url, root, pwd);

        // 2. 执行增删改查 - 发送SQL语句给mysql数据库执行
        String sql = "insert into dog values(7,'Jason')";
        // statement用于执行静态sql语句并返回其生成的结果对象
        Statement statement = connection.createStatement();
        int rows = statement.executeUpdate(sql); // 返回是否添加成功
        System.out.println(rows > 0 ? "添加成功" : "添加失败");

        // 3. 释放资源 - 关闭相关的连接
        statement.close();
        connection.close();
    }
}
// 拓展：如果用idea编译器无法正确使用相对路径，检查：Run -> Edit Configurations -> 选中对应java程序修改Working directory，该地址就是相对位置的起点；如果不会就使用全路径
```



### Statement

Statement对象用于执行静态SQL语句并返回其生成的结果对象

在业务中，我们一般不使用Statement对象对数据库（存在SQL注入的风险：利用某些系统没有对用户输入的数据及逆行充分的过滤，注入非法的SQL语句，恶意攻击数据库）

进而我们使用 **PrepareStatement**（预处理，主要使用这个），CallableSatement(可以处理数据库的存储过程)

```java
// PrepareStatement 讲解
// ？ 占位符 可以通过set语句填充,如下图
String sql = "SELECT *FROM emp WHERE username = ? AND password = ?";
// 预处理的好处
// 1. 不再使用 + 拼接sql语句，减少语法错误
// 2. 有效的解决了sql注入问题
// 3. 大大减少了编译次数，效率较高

// executeUpdate() 方法无需再填入sql语句
public static void main(String[] args) throws IOException, SQLException {
    String admin_name = "";
    String admin_pwd = "";

    // 读取配置文件
    Properties properties = new Properties();
    String filePath = "src\\com\\Al_tair\\connectMySql\\myJDBC\\Properties.properties";
    properties.load(new FileInputStream(filePath));
    String url = properties.getProperty("url");
    String root = properties.getProperty("root");
    String pwd = properties.getProperty("pwd");
    // 1. 获取连接 - 得到Connection
    Connection connection = DriverManager.getConnection(url, root, pwd);

    // 2. 执行增删改查 - 发送SQL语句给mysql数据库执行
    String sql = "select `name`,pwd from admin where name = ? and pwd = ? ";
    // preparedStatement用于执行静态sql语句并返回其生成的结果对象
    PreparedStatement preparedStatement = connection.prepareStatement(sql);
    preparedStatement.setString(1,admin_name);
    preparedStatement.setString(2,admin_pwd);

    int rows = preparedStatement.executeUpdate();
    System.out.println(rows> 0 ? "成功" : "失败");
    // 3. 释放资源 - 关闭相关的连接
    preparedStatement.close();
    connection.close();
}
```

![image-20220406141403921](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220406141403921.png)  



### ResultSet（结果集）

概念：表示数据库结果集的数据表（通常通过执行查询数据库语句执行）

ResultSet对象保持一个光标指向当前的数据行，光标从第一行开始向下遍历，如果没有更多行的时候将会返回false，迭代器的用法

```java
public class ResultSetDemo1 {
    public static void main(String[] args) throws IOException, SQLException {\
        // 读取配置文件
        Properties properties = new Properties();
        String filePath = "src\\com\\Al_tair\\connectMySql\\myJDBC\\Properties.properties";
        properties.load(new FileInputStream(filePath));
        String url = properties.getProperty("url");
        String root = properties.getProperty("root");
        String pwd = properties.getProperty("pwd");
        // 1. 获取连接 - 得到Connection
        Connection connection = DriverManager.getConnection(url, root, pwd);

        // 2. 执行增删改查 - 发送SQL语句给mysql数据库执行
        String sql = "select *from dog";
        // statement用于执行静态sql语句并返回其生成的结果对象
        Statement statement = connection.createStatement();
        ResultSet resultSet = statement.executeQuery(sql);
        while (resultSet.next()){
            int index = 1;
            int id = resultSet.getInt(index++); // 获取第一列
            String name = resultSet.getString(index); // 获取第二列
            System.out.println("id: "+ id + "  name: "+name);
        }

        // 3. 释放资源 - 关闭相关的连接
        resultSet.close();
        statement.close();
        connection.close();
    }
}
```

![image-20220405203403926](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220405203403926.png) 



### JDBC API梳理

![image-20220406151018088](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220406151018088.png)



### JDBC自定义工具类

为了减少代码复用性，我们添加工具类来实现连接和关闭

```java
public class JDBCUtils {
    private static String user; // 用户名
    private static String password; // 密码
    private static String url; // url

    static {
        String filePath = "E:\\Java_training\\Java_code\\JavaIdea03\\java\\Javase_HSping" +
                "\\src\\com\\Al_tair\\connectMySql\\utils\\Properties.properties";
        Properties properties = new Properties();
        try {
            properties.load(new FileInputStream(filePath));
            user = properties.getProperty("root");
            password = properties.getProperty("pwd");
            url = properties.getProperty("url");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
    
    // 连接数据库
    public static Connection getConnection(){
        try {
            return DriverManager.getConnection(url,user,password);
        } catch (SQLException throwables) {
            throw new RuntimeException(throwables);
        }
    }
    
    // 查询语句关闭
    public static void closeQueryConnection(ResultSet rst, Statement statement,Connection connection){
        try {
            rst.close();
            statement.close();
            connection.close();
        } catch (SQLException throwables) {
            throw new RuntimeException(throwables);
        }
    }

    // dml语句操作关闭
    public static void closeDmlConnection(Statement statement,Connection connection){
        try {
            statement.close();
            connection.close();
        } catch (SQLException throwables) {
            throw new RuntimeException(throwables);
        }
    }
}
```



### 操作数据库的事务

概念：创建Connection默认是自动提交事务，每次执行sql语句都会默认自动提交commit,不能发生回滚

![image-20220406183335392](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220406183335392.png) 

![image-20220406183304922](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220406183304922.png) 

![image-20220406183318359](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220406183318359.png) 



### 批处理

作用：用来一次性插入多条sql语句，提高插入效率

JDBC批量处理（PreparedStatement接口）方法如下

```java
PreparedStatement preparedStatement = connection.prepareStatement(sql);
preparedStatement.addBatch(); // 增加批处理数据
preparedStatement.executeBatch(); // 进行批处理
preparedStatement.clearBatch(); // 清空批处理
```

![image-20220406184343391](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220406184343391.png) 

注意：JDBC连接Mysql时候，如果要使用批处理功能，必须在url路径中添加如下语句，并且往往和PreparedStatement一起使用，不仅减少编译次数，也可以减少运行次数，效率大大提高

```java
// 添加?rewriteBatchedStatements=true语句
root = xxxx
pwd = xxxxxxxx
url = jdbc:mysql://localhost:3308/al_tair?rewriteBatchedStatements=true
```

 测试代码（批量处理大大减少时间）

```java
// 批处理底层数据就是存放在ArrayList集合中batchedArgs对象数组中
public class BatchDemo {
    public static void main(String[] args) throws SQLException {
        Connection connection = JDBCUtils.getConnection();
        // ? 占位符
        String sql = "insert into admin values(?,?,?)";
        PreparedStatement preparedStatement = connection.prepareStatement(sql);
        long start = System.currentTimeMillis();
        for (int i = 0; i < 5000; i++) {
            preparedStatement.setInt(1,i);
            preparedStatement.setString(2,"jack"+i);
            preparedStatement.setString(3,"123456"+i);
            preparedStatement.addBatch();
            if((i+1)%1000 == 0) {
                // 批量处理1000条
                preparedStatement.executeBatch();
                preparedStatement.clearBatch();
            }
        }
        long end = System.currentTimeMillis();
        System.out.println(end - start);
        JDBCUtils.closeDmlConnection(connection,preparedStatement);
    }
}

// 源码
public void addBatch() throws SQLException {
    synchronized(this.checkClosed().getConnectionMutex()) {
        if (this.batchedArgs == null) {
            this.batchedArgs = new ArrayList();
        }

        for(int i = 0; i < this.parameterValues.length; ++i) {
            this.checkAllParametersSet(this.parameterValues[i], this.parameterStreams[i], i);
        }
        this.batchedArgs.add(new PreparedStatement.BatchParams(this.parameterValues, this.parameterStreams, this.isStream, this.streamLengths, this.isNull));
    }
}
```



## 连接池

概念：数据库连接池主要负责分配，管理和释放数据库的连接

![image-20220407194331691](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220407194331691.png) 

常见的数据库连接池（现在常用C3P0,Druid）

- C3P0连接池，速度相对慢，但是稳定性不错（hibernate,spring）
- DBCP连接池，速度相对比C3P0快，但是稳定性不好不常用
- Proxool连接池，有监控连接池状态的功能，但是稳定性没有C3P0好
- BoneCP连接池，速度快（不常用）
- Druid（德鲁伊）是阿里提供的数据库连接池，集DBCP,C3P0,Proxool优点于一身

### C3P0连接池

 我们接下来讲的主要是C3P0连接池，首先引入jar包

![image-20220407200446550](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220407200446550.png) [下载地址](https://sourceforge.net/projects/c3p0/)

详细说明 [Data Source](https://www.cnblogs.com/noteless/p/10319296.html)

![image-20220407222707755](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220407222707755.png) 



**方式一：自己传入配置参数**

```java
// ComboPooledDataSource 实现了DataSource接口
public class C3P0Demo {
    public static void main(String[] args) throws PropertyVetoException, SQLException {
        // 创建连接池
        ComboPooledDataSource comboPooledDataSource = new ComboPooledDataSource();

        String filePath = "E:\\Java_training\\Java_code\\JavaIdea03\\java\\Javase_HSping" +
                "\\src\\com\\Al_tair\\connectMySql\\utils\\Properties.properties";
        Properties properties = new Properties();
        String user,password,url,driver;
        try {
            properties.load(new FileInputStream(filePath));
            user = properties.getProperty("root");
            password = properties.getProperty("pwd");
            url = properties.getProperty("url");
            driver = properties.getProperty("driver");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

        // 给连接池 comboPooledDataSource 设置参数
        comboPooledDataSource.setDriverClass(driver);
        comboPooledDataSource.setUser(user);
        comboPooledDataSource.setPassword(password);
        comboPooledDataSource.setJdbcUrl(url);

        // 初始化连接数
        comboPooledDataSource.setInitialPoolSize(10); // 初始化连接数
        comboPooledDataSource.setMaxPoolSize(30); // 最大连接数，超过30个将进入等待队列
        // 连接
        Connection connection = comboPooledDataSource.getConnection();
        System.out.println("----------");
        // 关闭连接
        connection.close();
    }
}
```

**方式二：通过xml配置文件配置**

```xml
<!-- c3p0-config.xml配置文件 注意：要将xml配置文件放在src -->
<c3p0-config>
<!--    数据源名称   -->
  <named-config name="DataSource">
<!-- 驱动类 -->
  <property name="driverClass">com.mysql.jdbc.Driver</property>
  <!-- url-->
  	<property name="jdbcUrl">jdbc:mysql://localhost:3308/al_tair</property>
  <!-- 用户名 -->
  		<property name="user">root</property>
  		<!-- 密码 -->
  	<property name="password">luo1234567</property>
  	<!-- 每次增长的连接数-->
    <property name="acquireIncrement">5</property>
    <!-- 初始的连接数  -->
    <property name="initialPoolSize">10</property>
    <!-- 最小连接数 -->
    <property name="minPoolSize">5</property>
   <!-- 最大连接数 -->
    <property name="maxPoolSize">50</property>

	<!-- 可连接的最多的命令对象数 -->
    <property name="maxStatements">5</property> 
    
    <!-- 每个连接对象可连接的最多的命令对象数 -->
    <property name="maxStatementsPerConnection">2</property>
  </named-config>
</c3p0-config>
```

```java
// 测试代码
public class C3P0Demo2 {
    public static void main(String[] args) throws SQLException {
        // 通过配置文件获取连接数据库的信息
        ComboPooledDataSource comboPooledDataSource = new ComboPooledDataSource("DataSource");
        // 获取连接
        Connection connection = comboPooledDataSource.getConnection();
        System.out.println("-------");
        // 关闭连接
        connection.close();
    }
}
```



### Druid连接池

Druid（德鲁伊）是阿里提供的数据库连接池，集DBCP,C3P0,Proxool优点于一身,连接速度快

**druid配置类**

```properties
#key=value
driverClassName=com.mysql.jdbc.Driver
url=jdbc:mysql://localhost:3308/al_tair?rewriteBatchedStatements=true
username=root
password=XXXXXXX
#initial connection Size
initialSize=10
#min idle connecton size
minIdle=5
#max active connection size
maxActive=50
#max wait time (5000 mil seconds)
maxWait=5000
```

 **德鲁伊连接池工具类**

```java
public class JDBCUtilsByDruid {
    private static DataSource dataSource;

    static {
        String filePath = "E:\\Java_training\\Java_code\\JavaIdea03\\java\\Javase_HSping\\" +
                "src\\com\\Al_tair\\connectMySql\\druid\\druid.properties";
        Properties properties = new Properties();
        try {
            properties.load(new FileInputStream(filePath));
            dataSource = DruidDataSourceFactory.createDataSource(properties);
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

    // 连接数据库
    public static Connection getConnection(){
        try {
            // 创建一个指定参数的数据库连接池(德鲁伊连接池)
            return dataSource.getConnection();
        } catch (SQLException throwables) {
            throw new RuntimeException(throwables);
        }
    }

    // 查询语句关闭
    public static void closeQueryConnection(Connection connection, Statement statement, ResultSet rst){
        try {
            rst.close();
            statement.close();
            connection.close();
        } catch (SQLException throwables) {
            throw new RuntimeException(throwables);
        }
    }

    // dml语句操作关闭
    public static void closeDmlConnection(Connection connection,Statement statement){
        try {
            statement.close();
            connection.close();
        } catch (SQLException throwables) {
            throw new RuntimeException(throwables);
        }
    }

    public static void closeConnection(Connection connection){
        try {
            connection.close();
        } catch (SQLException throwables) {
            throwables.printStackTrace();
        }
    }
}
```

**测试类**

```java
public class DruidDemo {
    public static void main(String[] args) throws Exception {
        Connection connection = JDBCUtilsByDruid.getConnection();
        System.out.println("连接成功");
        JDBCUtilsByDruid.closeConnection(connection);
    }
}
```



## Apache - DBUtils

引出原因：

- resultSet合connection是关联的，如果关闭连接，就不能再使用resultSet
- resultSet来获取信息读取也不太方便，不利于数据管理

解决思路： 将数据库表中的每条记录用对象的形式（通常称作JavaBean，PoJo）,Domain) 保存在集合ArrayList中

**自己模拟源码测试代码**

```java
// 取出核心代码分析
ArrayList<Dog> list = new ArrayList<>();
while (resultSet.next()){
    int index = 1;
    // 以下四行就是一个记录
    int id = resultSet.getInt(index++); // 获取第一列
    String name = resultSet.getString(index++); // 获取第二列
    String color = resultSet.getString(index++); // 获取第三列
    Date birth = resultSet.Date(index++); // 获取第四列
    list.add(new Dog(id,name,color,birth)); // 将resultSet取出来放入到集合数组中
}

public class Dog {
    private int id;
    private String name;
    private String color;
    private Date birth;
    public Dog() {}
    public Dog(int id, String name, String color, Date birth) {
        this.id = id;
        this.name = name;
        this.color = color;
        this.birth = birth;
    }
}
```

Dog表如下

![image-20220408200441178](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220408200441178.png) 



**Apache - DBUtils工具的使用**

首先需要导入jar包[ commons-dbutils-1.3.jar](http://www.java2s.com/Code/Jar/c/Downloadcommonsdbutils13jar.htm)

commons_dbutils是Apache组织提供的一个开源的JDBC工具类库

|        方法        | 作用                                                         |
| :----------------: | ------------------------------------------------------------ |
|    ArrayHandler    | 把结果集中的第一行数据转成对象数组                           |
|  ArrayListHandler  | 把结果集中的每一行数据都转成一个数组，再存放到Lisr中         |
|    BeanHandler     | 把结果集中的每一行数据封装到一个对应的javaBean实例中         |
|  BeanListHandler   | 将结果集中的每一行数据都封装到一个对应的JavaBean实例中，存放到List里 |
| ColumnListHandler  | 将结果集中某一列的数据存放到List中                           |
| KeyedHandler(name) | 将结果集中的每行数据都封装到Map里，再把这些map再存到一个map里，其key为指定的key |
|     MapHandler     | 将结果集中的第一行数据封装到一个Map里，key是列名，value就是对应的值 |
|   MapListHandler   | 将结果集中的每一行数据都封装到一个Map里，然后再存放到List    |
|   ScalarHandler    | 将结果集中的某一行某一列的数据存放到Object对象中             |

**查询语句**

```JAVA
public static void main(String[] args) throws SQLException {
    // 得到连接
    Connection connection = JDBCUtilsByDruid.getConnection();
    // 创建QueryRunner
    QueryRunner queryRunner = new QueryRunner();
    String sql = "SELECT *FROM dog";
    // connection 连接 sql 操作语句 new BeanListHandler<>(Dog.class) 通过得到Dog类，进行反射封装成对象
    List<Dog> list = queryRunner.query(connection, sql, new BeanListHandler<>(Dog.class));
    for (Dog dog:list
        ) {
        System.out.println(dog);
    }
    JDBCUtilsByDruid.closeConnection(connection);
}

// 源码剖析 queryRunner 的 query方法
// connection 连接 sql 操作语句 new BeanListHandler<>(Dog.class) 通过得到Dog类，进行反射封装成对象 params 用来传入替代？占位符的数据
public <T> T query(Connection conn, String sql, ResultSetHandler<T> rsh, Object... params) throws SQLException {
    PreparedStatement stmt = null;
    ResultSet rs = null;
    Object result = null;

    try {
        // 创建预处理  PreparedStatement
        stmt = this.prepareStatement(conn, sql);
        // fillStatement(stmt, params) 主要是用于解决替换sql语句中？占位符
        this.fillStatement(stmt, params);
        // 得到结果集 resultSet
        rs = this.wrap(stmt.executeQuery());
        // 返回的 resultSet --> rsh对象 存储到ArrayList集合中
        result = rsh.handle(rs);
    } catch (SQLException var33) {
        this.rethrow(var33, sql, params);
    } finally {
        try {
            // 关闭结果集
            this.close(rs);
        } finally {
            // 关闭PreparedStatement
            this.close((Statement)stmt);
        }
    }

    return result;
}
```

**dml操作**

```java
// 测试删除语句，其他dml语句大同小异
public class DBUtilsDmlDemo {
    public static void main(String[] args) throws SQLException {
        // 建立连接
        Connection connection = JDBCUtilsByDruid.getConnection();
        // 创建 QueryRunner
        QueryRunner queryRunner = new QueryRunner();
        String sql = "DELETE FROM dog WHERE ID = ?";
        // update方法能统一处理增删改操作 返回的是影响的行数：0表示数据库中的表没有受到影响
        int deleteVictory = queryRunner.update(connection, sql, 1);
        System.out.println(deleteVictory > 0?"删除成功":"删除失败");
        JDBCUtilsByDruid.closeConnection(connection);
    }
}

// 源码如下
public int update(Connection conn, String sql, Object... params) throws SQLException {
    PreparedStatement stmt = null;
    int rows = 0;
    try {
        stmt = this.prepareStatement(conn, sql);
        this.fillStatement(stmt, params);
        rows = stmt.executeUpdate();
    } catch (SQLException var10) {
        this.rethrow(var10, sql, params);
    } finally {
        this.close((Statement)stmt);
    }

    return rows;
}
```



## BasicDao

概念：专门和数据交互，完成对数据库的CRUD操作

![image-20220409210413206](https://use-typora.oss-cn-hangzhou.aliyuncs.com/image-20220409210413206.png)

**测试Dog表代码**

```java
// BasicDao.java
public class BasicDao<T> {
    private QueryRunner qr = new QueryRunner();

    // dml操作语句
    public int DmlUpdate(String sql,Object...params){
        Connection connection = null;

        try {
            connection = JDBCUtilsByDruid.getConnection();
            return qr.update(connection,sql,params);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }finally {
            JDBCUtilsByDruid.closeConnection(connection);
        }
    }

    // 查询语句:返回集合（表）
    public List<T> SelectMultiLine(String sql, Class<T> cls, Object...params){
        Connection connection = null;
        try {
            connection = JDBCUtilsByDruid.getConnection();
            return qr.query(connection,sql,new BeanListHandler<T>(cls),params);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }finally {
            JDBCUtilsByDruid.closeConnection(connection);
        }
    }

    // 查询语句:返回单行数据
    public T SelectSingleLine(String sql, Class<T> cls, Object...params){
        Connection connection = null;
        try {
            connection = JDBCUtilsByDruid.getConnection();
            return qr.query(connection,sql,new BeanHandler<T>(cls),params);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }finally {
            JDBCUtilsByDruid.closeConnection(connection);
        }
    }

    // 查询语句:返回某行某列数据
    public Object SelectSingleLine(String sql, Object...params){
        Connection connection = null;
        try {
            connection = JDBCUtilsByDruid.getConnection();
            return qr.query(connection,sql,new ScalarHandler(),params);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }finally {
            JDBCUtilsByDruid.closeConnection(connection);
        }
    }
}

// DogDao.java
public class DogDao extends BasicDao<Dog> {}

// TestDog.java
public class TestDog {
    public static void main(String[] args) {
        DogDao dogDao = new DogDao();

        // dml操作测试
        String sql = "insert into dog values(3,'marry','blue',?)";
        int rows = dogDao.DmlUpdate(sql, "2021-3-19");
        System.out.println(rows > 0?"测试成功":"未添加数据到数据库'");

        // 查询表
        sql = "select *from dog where id = ?";
        Object o = dogDao.SelectSingleLine(sql, Dog.class, 2);
        System.out.println(o);
    }
}
```














































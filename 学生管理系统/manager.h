#pragma once  //防止头文件重复包含
#include <iostream>  //包含输入输出流
#include "person.h"
#include "student.h"
#include "teacher.h"
#include "headmaster.h"
#include "string.h"
#include <fstream>

#define FIFENAME "perFile.txt"
using namespace std; //使用标准的命名空间

class Manager {
public:
	// 构造函数
	Manager();

	//析构函数
	~Manager();

	//显示菜单
	void ShowMenu();

	//退出管理系统
	void ExitSystem();

	//记录登记人数
	int personNum;

	//人员数组指针
	Person **PersonArray;

	//增加人员
	void Add_person();

	//保存文件
	void FileSave(int newSize);

	//判断文件是否为空标志
	bool FileIsEmpty;

	//统计文件人数
	int get_PerNum();

	//初始化员工
	void init_Person();

	//显示人员
	void showPerson();

	//删除人员
	void delPerson();

	//判断人员是否存在 如果存在返回职工所在数组中的位置，不存在则返回-1
	int personIsExist(string name);

	//修改文件
	void modPerson();

	//清空文件
	void cleanFile();
};


/*
首先创建管理类
1.与用户的沟通菜单的界面
2.对学生增删改查的操作
3.与文件的读写

其次菜单功能
功能描述：与用户的沟通界面

添加人员
功能描述:批量添加人员，并且保存到文件中
用户在批量创建时，可能创建不同种类的人员（学生，老师，校长）
如果想要将所有种类人员都放入一个数组中，可以将所有人员的指针维护到一个数组里
如果想在程序中维护这个不定长度的数组，可以将数组创建在堆区，并利用Person**的指针来维护

文件交互-写文件
功能描述：对文件进行读写
在上一个添加功能中，我们只是将所有的数据添加到了内存中，一旦程序结束就无法保存
因此文件管理类需要一个与文件进行交互的功能，对于文件进行读写的功能

文件交互-读文件
功能描述：将文件中的内容读取到程序中
虽然我们能实现添加文件后的保存文件，但是每次开始运行程序，并没有将文件中的数据读取出来
而且我们程序的功能中还有清空文件的功能需求
1.第一次使用，文件未创建
2.文件存在，但是数据被清空
3.文件存在，并且保存人员的所有数据

获取记录人员人数

显示人员
功能描述：显示当前所有人员信息

删除人员
功能描述:按照人员的信息进行删除

修改人员信息
功能描述：能够按照人员的姓名对人员的信息进行修改

清空文件
功能描述:将文件记录的数据清空
*/

#include <iostream>
#include "Manager.h"
#include "person.h"
#include "student.h"
#include "teacher.h"
#include "headmaster.h"
using namespace std;

int main() {

	//实例化管理对象
	Manager manager;
	//选择功能
	int choice = 0;

	while (true) {
		//调用展示菜单成员函数
		manager.ShowMenu();

		cout<<"兄嘚姐妹，请你输入你的选择(1~6):";
		// 输入用户的选择
		cin >> choice; 

		switch(choice){
		// 1.显示人员信息
		case 1: manager.showPerson();
			    break;

		// 2.增加人员信息
		case 2: manager.Add_person();
				break;

		// 3.删除人员信息
		case 3: manager.delPerson();
			    break;

		// 4.修改人员信息
		case 4: manager.modPerson();
				break;

		// 5.退出管理系统
		case 5: manager.ExitSystem();
				break;

		// 6.清空所有文档
		case 6: manager.cleanFile();
				break;

		default: system("cls");
			     break;
		}
	}
}
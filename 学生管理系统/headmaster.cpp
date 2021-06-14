#include <iostream>
#include "headmaster.h"
using namespace std;

//构造函数
Headmaster::Headmaster(int  ID,string name, string schoolName, string schoolAim) {
	this->ID = ID;
	this->name = name;
	this->message = schoolAim;
	this->message2= schoolName;
};

//显示个人信息
void Headmaster::showInfo() {
	cout << "\n***********************************"
		 << "\n**\t校长编号:" << this->ID
		 << "\n**\t校长姓名:" << this->name
		 << "\n**\t学校名称:" << this->message2
		 << "\n**\t学校方向:" << this->message
		 << "\n***********************************" << endl;
};
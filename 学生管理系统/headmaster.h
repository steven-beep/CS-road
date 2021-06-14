#pragma once
#include <iostream>
#include <String>
#include "person.h"
using namespace std;

class Headmaster :public Person {
public:
    //构造函数
	Headmaster(int ID,string name,string schoolName,string schoolAim );

	//显示个人信息
	virtual void showInfo();
};
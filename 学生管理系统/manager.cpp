#include "Manager.h"

// 显示菜单
void Manager::ShowMenu() {
	cout << "***********************************" << endl;
	cout << "**									" << endl;
	cout << "**       欢迎使用学校管理系统！    " << endl;
	cout << "**									" << endl;
	cout << "**          1.显示人员信息         " << endl;
	cout << "**          2.增加人员信息			" << endl;
	cout << "**          3.删除在校人员			" << endl;
	cout << "**          4.修改人员信息			" << endl;
	cout << "**          5.退出管理系统			" << endl;
	cout << "**          6.清空所有文档			" << endl;
	cout << "**									" << endl;
	cout << "***********************************" << endl;
	cout << endl;
}

// 1.显示人员
void Manager::showPerson() {
	// 判断文件是否为空
	if (this->FileIsEmpty) {
		cout << "***********************************" << endl;
		cout << "**   数据没有？怎么显示？？" << endl;
		cout << "***********************************" << endl;
	}
	else {
		// 利用多态调用程序接口
		for (int i = 0; i < this->personNum; i++) {
			this->PersonArray[i]->showInfo();
		}
	}

	//按任意键清屏
	system("pause");
	system("cls");
}

// 2.增加人员
void Manager::Add_person() {
	int AddNum = 0;   //记录用户输入的人数
	cout << endl;
	cout << "***********************************" << endl;
	cout << "胖友，请你输入你需要添加多少人（包括学生，老师，校长）:" << endl;
	cin >> AddNum;

	//形式参数，无实际意义
	string content1;
	string content2;
	string content3;

	//判断数值是否有误
	if (AddNum > 0) {
		//动态扩展数组

		//计算开辟新空间大小
		int newSize = this->personNum + AddNum;

		//开辟新空间
		Person** newSpace = new Person * [newSize];

		//将原来空间的数据，拷贝到新空间下
		if (this->PersonArray != NULL) {
			for (int i = 0; i < this->personNum; i++) {
				newSpace[i] = this->PersonArray[i];
			}
		}

		//批量添加新数据
		for (int i = 0; i < AddNum; i++) {
			int select; //身份的选择
			cout << "***********************************" << endl;
			cout << "请你输入添加的第" << i + 1 << "个人员" << endl;
			cout << "请选择人员的身份:" << endl;
			cout << " 1.学生" << endl;
			cout << " 2.老师" << endl;
			cout << " 3.校长" << endl;
			cin >> select;
			while (select != 1 && select != 2 && select != 3) {
				cout << "兄弟，你是不是玩弄我的感情？" << endl;
				cout << "请你重新选择:" << endl;
				cin >> select;
			}

			Person* person = NULL;
			switch (select) {
			case 1:	   cout << "请问这位学生院系是？" << endl;
				cin >> content2;
				cout << "请问这位学生班级是？" << endl;
				cin >> content3;
				cout << "请问这位学生姓名是？" << endl;
				cin >> content1;
				person = new Student(1, content1, content2, content3);  //开辟堆区
				break;
			case 2:	   cout << "请问这位老师课程是？" << endl;
				cin >> content2;
				cout << "请问这位老师姓名是？" << endl;
				cin >> content1;
				cout << "请问这位老师布置任务是？" << endl;
				cin >> content3;
				person = new Teacher(2, content1, content2, content3);
				break;
			case 3:	   cout << "请问这位校长姓名是？" << endl;
				cin >> content1;
				cout << "请问这位校长管理的学校是？" << endl;
				cin >> content2;
				cout << "请问这位校长的学校大发展方向是？" << endl;
				cin >> content3;
				person = new Headmaster(3, content1, content2, content3);
				break;
			default:   break;
			}
			//保存到数组
			newSpace[this->personNum + i] = person;
		}
		//释放原有空间
		delete[] this->PersonArray;

		//更改新空间的指针
		this->PersonArray = newSpace;

		//保存数据到文件中
		this->FileSave(newSize);

		//更新新的人员人数
		this->personNum = newSize;

		//更新职工不为空标志
		this->FileIsEmpty = false;

		//提示添加成功
		cout << "成功添加" << AddNum << "个人员！！" << endl;

		system("pause");
		system("cls");

	}
	else {
		cout << "兄弟，你是不是欺骗我的感情？" << endl;
	}
	cout << "***********************************" << endl;
	cout << endl;
}

// 3.删除人员
void Manager::delPerson() {
	if (this->FileIsEmpty) {
		cout << "***********************************" << endl;
		cout << "**      文件都为空？删撒嘞？？" << endl;
		cout << "***********************************" << endl;
	}
	else {
		cout << "***********************************" << endl;
		// 按照人员姓名进行删除
		cout << "请输入想要删除人员的姓名: ";
		string name;
		cin >> name;
		int index = this->personIsExist(name);

		if (index != -1) {  //说明人员存在，并且要删除
			//数据前移
			for (int i = index; i < this->personNum - 1; i++) {
				this->PersonArray[i] = this->PersonArray[i + 1];
			}
			this->personNum--;  // 更新数组中记录的人员个数

			//数据同步更新到文件中
			this->FileSave(-1);
			cout << "删除成功！你真棒！" << endl;
		}
		else {
			cout << "     删撒嘞？？有木有？？" << endl;
		}
		cout << "***********************************" << endl;

	}
	system("pause");
	system("cls");
}

// 4.修改文件
void Manager::modPerson() {
	if (this->FileIsEmpty) {
		cout << "***********************************" << endl;
		cout << "**      文件都为空？删撒嘞？？" << endl;
		cout << "***********************************" << endl;
	}
	else {
		cout << "***********************************" << endl;
		int ID;  //存放人员的ID
		string name; //存放修改人的姓名
		cout << "请输入修改人员的姓名:";
		cin >> name;

		int index = this->personIsExist(name);
		if (index != -1) {
			cout << "请选择人员的身份:" << endl;
			cout << " 1.学生" << endl;
			cout << " 2.老师" << endl;
			cout << " 3.校长" << endl;
			cin >> ID;
			while (ID != 1 && ID != 2 && ID != 3) {
				cout << "兄弟，你是不是玩弄我的感情？" << endl;
				cout << "请你重新选择:" << endl;
				cin >> ID;
			}
			ID = this->PersonArray[index]->ID;
			delete this->PersonArray[index];

			string newMessage="";  //存放修改人的信息
			string newMessage2=""; //存放修改人的信息2

			Person* person = NULL;
			switch (ID) {
			case 1:	   cout << "请问这位学生院系是？" << endl;
					   cin >> newMessage;
					   cout << "请问这位学生班级是？" << endl;
				  	   cin >> newMessage2;
					   cout << "请问这位学生姓名是？" << endl;
					   cin >> name;
					   person = new Student(1, name, newMessage, newMessage2);  //开辟堆区
					   break;
			case 2:	   cout << "请问这位老师课程是？" << endl;
					   cin >> newMessage;
					   cout << "请问这位老师任务是？" << endl;
					   cin >> newMessage2;
					   cout << "请问这位老师姓名是？" << endl;
					   cin >> name;
					   person = new Teacher(2, name, newMessage, newMessage2);
					   break;
			case 3:	   cout << "请问这位校长管理的学校是？" << endl;
					   cin >> newMessage;
					   cout << "请问这位校长的学校大发展方向是？" << endl;
				  	   cin >> newMessage2;
					   cout << "请问这位校长姓名是？" << endl;
					   cin >> name;
					   person = new Headmaster(3, name, newMessage, newMessage2);
					   break;
			default:   break;
			}
			//更改数据到数组中
			this->PersonArray[index] = person;

			cout << "修改成功" << endl;

			//保存到文件中
			this->FileSave(-1);
		}
		else {
			cout << "兄弟，查无此人？？" << endl;
		}
		cout << "***********************************" << endl;
	}
	//按任意键清屏
	system("pause");
	system("cls");
}

// 5.退出管理系统
void Manager::ExitSystem() {
	cout << endl;
	cout << "***********************************" << endl;
	cout << "**    后会有期！兄弟们！" << endl;
	cout << "***********************************" << endl;
	cout << endl;
	system("pause");
	exit(0);
}

// 6.清空文件
void Manager::cleanFile() {
	cout << "***********************************" << endl;
	cout << "**\t确定清空文件数据？" << endl;
	cout << "**\t1.确定" << endl;
	cout << "**\t2.返回" << endl;

	int select;
	cin >> select;
	while (select != 1 && select != 2) {
		cout << "Are you really ?" << endl;
		cin >> select;
	}
	if (select == 1) {
		// 打开模式 ios::trunc 如果存在删除文件并重新创建
		ofstream ofs(FIFENAME, ios::trunc);
		ofs.close();
		for (int i = 0; i < this->personNum; i++){
			if (this->PersonArray[i] != NULL) {
				delete this->PersonArray[i];
			}
		}
		this->personNum = 0;
		delete[] this->PersonArray;
		this->PersonArray = NULL;
		this->FileIsEmpty = true;
		cout << "清除干净！" << endl;
	}
	cout << "***********************************" << endl;
	system("pause");
	system("cls");
}

// 保存文件
void  Manager::FileSave(int newSize) {
	ofstream ofs;

	if (newSize == -1) {
		ofs.open(FIFENAME, ios::out);   //用输出的方式打开文件 --写文件

		//将每个人的数据写入到文件中
		for (int i = 0; i < this->personNum; i++) {
			ofs << this->PersonArray[i]->ID << " "
				<< this->PersonArray[i]->name << " "
				<< this->PersonArray[i]->message << " "
				<< this->PersonArray[i]->message2 << endl;
		}
	}
	else {
		ofs.open(FIFENAME, ios::app);   //用输出的方式打开文件 --写文件

		//将每个人的数据写入到文件中
		for (int i = this->personNum; i < newSize; i++) {
			ofs << this->PersonArray[i]->ID << " "
				<< this->PersonArray[i]->name << " "
				<< this->PersonArray[i]->message << " "
				<< this->PersonArray[i]->message2 << endl;
		}
	}
	cout << "保存文件成功！" << endl;

	//关闭文件流
	ofs.close();
}

// 统计文件人数
int Manager::get_PerNum() {
	ifstream ifs;
	ifs.open(FIFENAME,ios::in);

	int ID;
	string name;
	string message;
	string message2;

	int num = 0;

	while (ifs >> ID && ifs >> name && ifs >> message && ifs >> message2) {
		//记录人数
		num++;
	}

	ifs.close();
	return num; 
}

// 初始化人员
void Manager::init_Person() {
	ifstream ifs;
	ifs.open(FIFENAME, ios::in);

	int index = 0; //下标
	int ID;
	string name;
	string message;
	string message2;
	
	while (ifs >> ID && ifs >> name && ifs >> message && ifs >> message2) {
		Person* person = NULL;
		if (ID == 1) {   //学生
			person = new Student(ID, name, message, message2);
		}
		else if (ID == 2) {   //老师
			person = new Teacher(ID, name, message, message2);
		}
		else {    //校长
			person = new Headmaster(ID, name, message, message2);
		}
		this->PersonArray[index] = person;
		index++;
	}

	// 关闭文件
	ifs.close();
}

//判断人员是否存在 如果存在返回职工所在数组中的位置，不存在则返回-1
int Manager::personIsExist(string name) {
	int index = -1;
	for (int i = 0; i < this->personNum; i++) {
		if (this->PersonArray[i]->name == name) {
			index = i;
			break;
		}
	}
	return index;
}

Manager::Manager() {
	ifstream ifs;
	ifs.open(FIFENAME,ios::in);

	// 1.文件不存在的情况
	if (!ifs.is_open()) {
		cout << "***********************************" << endl;
		cout << "**           文件不存在" << endl;
		cout << "***********************************" << endl;
		//初始化属性
		//初始化记录人数
		this->personNum = 0;
		//初始化数组指针
		this->PersonArray = NULL;
		//初始化文件是否为空
		this->FileIsEmpty = true;
		ifs.close();
		return;
	}

	// 2.文件存在，并且没有记录的情况
	char ch;
	ifs >> ch;  // 读取到文件txt第一个字节数据
	if (ifs.eof()) {    // eof为文件txt的末尾标志
		cout << "***********************************" << endl;
		cout << "**           文件为空" << endl;
		cout << "***********************************" << endl;
		//初始化属性
		//初始化记录人数
		this->personNum = 0;
		//初始化数组指针
		this->PersonArray = NULL;
		//初始化文件是否为空
		this->FileIsEmpty = true;
		ifs.close();
		return;
	}
	
	// 3.文件存在，并且记录数据的情况
	int num = this->get_PerNum();
	cout << "***********************************" << endl;
	cout << "**\t已经添加" << num << "个人员！" << endl;
	cout << "***********************************" << endl;
	this->personNum = num;
	//开辟空间
	this->PersonArray = new Person * [num];
	//将文件中的数据存储到数组中
	this->init_Person();


	//测试代码
	/*
	for (int i = 0; i < num; i++) {
		cout << "**      " ;
		switch (this->PersonArray[i]->ID) {
		case 1: cout << "学生编号:" << this->PersonArray[i]->ID << " * "
				     << "学生姓名:" << this->PersonArray[i]->name << " * "
					 << "学生院系:" << this->PersonArray[i]->message << " * "
					 << "学生班级:" << this->PersonArray[i]->message2 << endl;
				cout << "**" << endl;
				break;
		case 2: cout << "老师编号:" << this->PersonArray[i]->ID << " * "
			         << "老师姓名:" << this->PersonArray[i]->name << " * "
					 << "老师课程:" << this->PersonArray[i]->message << " * "
					 << "老师任务:" << this->PersonArray[i]->message2 << endl;
			    cout << "**" << endl;
				break;
		case 3: cout << "校长编号:" << this->PersonArray[i]->ID << " * "
					 << "校长姓名:" << this->PersonArray[i]->name << " * "
					 << "管理的学校:" << this->PersonArray[i]->message << " * "
					 << "学校的方向:" << this->PersonArray[i]->message2 << endl;
			    cout << "**" << endl;
				break;
		}
		
	}
	cout << "*********************************************************************************************" << endl;
	*/
};

Manager::~Manager() {
	if (this->PersonArray != NULL) {
		delete[] this->PersonArray;
		this->PersonArray = NULL;
	}
};
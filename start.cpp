#include <iostream>
#include <fstream>
#include <string>
#define MAX_VALUE 80

/*结构体设计_联系人*/
typedef struct person {
	std::string name;
	std::string sex;
	int age = 0;
	std::string telephoneNumber;
	std::string address;
}Person;

/*结构体设计_通讯录*/
typedef struct phonenumberList {
	Person capacity[MAX_VALUE];
	int size = 0;
}List;
/*菜单*/
void menu() {
	std::cout << "**** Telephone Number Manage System ****" << std::endl;
	std::cout << "    1.添加联系人" << std::endl;
	std::cout << "    2.显示联系人" << std::endl;
	std::cout << "    3.查找联系人" << std::endl;
	std::cout << "    4.删除联系人" << std::endl;
	std::cout << "    5.修改联系人" << std::endl;
	std::cout << "    6.清空联系人" << std::endl;
	std::cout << "    7.退出系统" << std::endl;
	std::cout << "    8.写入文件" << std::endl;
}

/*退出系统*/
void exitSystem() {
	exit(0);
}


/*通讯录_添加联系人*/
void addPhonenumberData(List* list) {
	if (list->size == MAX_VALUE) 
		std::cout << "当前通讯录已满，请删除后再添加" << std::endl;
	else {
		std::string name;
		std::string sex;
		int age;
		std::string telephoneNumber;
		std::string address;

		std::cout << "请输入姓名：" << std::endl;
		std::cin >> name;
		list->capacity[list->size].name = name;
		std::cout << "请输入性别：" << std::endl;
		std::cin >> sex;
		list->capacity[list->size].sex = sex;
		std::cout << "请输入年龄：" << std::endl;
		std::cin >> age;
		list->capacity[list->size].age = age;
		std::cout << "请输入电话号码：" << std::endl;
		std::cin >> telephoneNumber;
		list->capacity[list->size].telephoneNumber = telephoneNumber;
		std::cout << "请输入地址：" << std::endl;	
		std::cin >> address;
		list->capacity[list->size].address= address;

		list->size++;
		std::cout << "添加成功" << std::endl;
		system("pause");
		system("cls");
	}
}

/*通讯录_打印联系人*/
void printPhoneNumberData(List* list, int startIndex, int endIndex) {
	if (list->size == 0)
		std::cout << "通讯录中无信息！" << std::endl;
	else {
		for (int i = startIndex; i < endIndex; i++) {
			std::cout << i + 1 << "\t";
			std::cout << "姓名: " << list->capacity[i].name << "\t";
			std::cout << "性别: " << list->capacity[i].sex << "\t";
			std::cout << "年龄: " << list->capacity[i].age << "\t";
			std::cout << "电话: " << list->capacity[i].telephoneNumber << "\t";
			std::cout << "地址: " << list->capacity[i].address << std::endl;
		}
	}
	system("pause");
	system("cls");
}

/*通讯录_查找联系人*/
int phonenumberIsValid(List* list, std::string name, std::string phoneNumber) {
	for (int i = 0; i < list->size; i++) {
		if (list->capacity[i].name == name ||
			list->capacity[i].telephoneNumber == phoneNumber) {
			std::cout << "查找成功，查找到联系人信息:\n";
			printPhoneNumberData(list, i, i + 1);
			system("pause");
			system("cls");
			return i;
		}
	}
	std::cout << "查无此人" << std::endl;
	system("pause");
	system("cls");
	return -1; 
}

/*通讯录_删除联系人*/
void removePhonenumber(List* list) {
	std::string name, phonenumber;
	std::cout << "请输入联系人姓名：\n";
	std::cin >> name;
	std::cout << "请输入联系人电话号码（可选）：\n";
	std::cin >> phonenumber;
	int index = phonenumberIsValid(list, name, phonenumber);
	if (index == -1) {
		std::cout << "删除失败 [person not found]" << std::endl;
		return;
	}
	else {
		//用数组最后的数据替换当前的数据 不保留预先顺序
		list->capacity[index] = list->capacity[(list->size - 1)];
		list->size--;
		std::cout << "删除成功" << std::endl;
	}
}

/*通讯录_修改联系人*/
void alterPhonenumber(List* list) {
	std::string name, phonenumber;
	std::cout << "请输入联系人姓名：\n";
	std::cin >> name;
	std::cout << "请输入联系人电话号码（可选）：\n";
	std::cin >> phonenumber;
	int index = phonenumberIsValid(list, name, phonenumber);
	std::cout << "现在修改联系人" << std::endl;
	if (index == -1) {
		std::cout << "修改失败 [person not found]" << std::endl;
		return;
	}
	else {
		std::string name;
		std::string sex;
		int age;
		std::string telephoneNumber;
		std::string address;

		std::cout << "请输入姓名：" << std::endl;
		std::cin >> name;
		list->capacity[index].name = name;
		std::cout << "请输入性别：" << std::endl;
		std::cin >> sex;
		list->capacity[index].sex = sex;
		std::cout << "请输入年龄：" << std::endl;
		std::cin >> age;
		list->capacity[index].age = age;
		std::cout << "请输入电话号码：" << std::endl;
		std::cin >> telephoneNumber;
		list->capacity[index].telephoneNumber = telephoneNumber;
		std::cout << "请输入地址：" << std::endl;
		std::cin >> address;
		list->capacity[index].address = address;

		std::cout << "修改成功" << std::endl;
		system("pause");
		system("cls");
	}
}

/*通讯录_清空联系人*/
void dropAllPhonenumber(List* list) {
	list->size = 0;
	std::cout << "操作完成" << std::endl;
}

/*附加功能_文件保存*/
void writePersonArray(char filename[], List a[], int n) {
	int count = 0;
	std::ofstream out;
	out.open(filename);
	if (!out.is_open()) {
		std::cout << "Error:file open fail.";
		exit(1);
	}
	else {
		for (count = 0; count < n; count++) {
			out << a->capacity[count].name << " " << a->capacity[count].sex << " " << a->capacity[count].age << " " \
				<< a->capacity[count].telephoneNumber << " " << a->capacity[count].address << std::endl;
		}
		out.close();
	}
	system("pause");
	system("cls");
}

/*附加功能_文件读取*/
int readPersonArray(char filename[], List address_book[], int nmax) {
	std::ifstream in;
	in.open(filename);
	int count = 0;
	if (!in.is_open()) {
		std::cout << "Error: open file fail!!!" << std::endl;
		exit(1);
	}
	while (!in.eof() && count < nmax) {
		in >> address_book->capacity[count].name >> address_book->capacity[count].sex >> address_book->capacity[count].age  \
			>> address_book->capacity[count].telephoneNumber >> address_book->capacity[count].address;
		count++;
	}
	count--;			//eof()方法当读到文件结尾时，还会在进行一次读取操作，除去多计算的元素，暂时没想到更好的解决方案 
	in.close();
	return count;
	system("pause");
	system("cls");
}

void doNothing() {}

int main() {
	List list;
	//读取文件
	char filename[] = "phonenumber.txt";
	readPersonArray(filename, &list, list.size);
	//用户选择
	int userSelect = 0;
	while (true) {
		menu();
		std::cout << "请输入你的操作：" << std::endl;
		std::cin >> userSelect;
		switch (userSelect) {
			//添加联系人
		case 1:
			system("cls");
			addPhonenumberData(&list);
			break;
			//显示联系人
		case 2:
			system("cls");
			printPhoneNumberData(&list, 0, list.size);
			break;
			//查找联系人
		case 3:
			system("cls");
			{
				std::string name, phonenumber;
				std::cout << "请输入联系人姓名：\n";
				std::cin >> name;
				std::cout << "请输入联系人电话号码（可选）：\n";
				std::cin >> phonenumber;
				phonenumberIsValid(&list, name, phonenumber);
				break;
			}
			//删除联系人
		case 4:
			system("cls");
			removePhonenumber(&list);
			break;
			//修改联系人
		case 5:
			system("cls");
			alterPhonenumber(&list);
			break;
			//清空联系人
		case 6:
			system("cls");
			std::cout << "是否确定清空操作（Y）\n";
			char op;
			std::cin >> op;
			op == 'Y' ? dropAllPhonenumber(&list) : doNothing();
			system("pause");
			system("cls");
			break;
		case 7:
			std::cout << "正在退出系统..." << std::endl;
			exitSystem();
			break;
		case 8:
			std::cout << "正在写文件..." << std::endl;
			writePersonArray(filename, &list, list.size);
			break;
		default:
			std::cout << "请不要随意输入其他数据(●'_'●)" << std::endl;
			system("pause");
			system("cls");
			break;
		}
	}
}
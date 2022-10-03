#include <iostream>
#define MAX     1000
using namespace std;

struct Person
{
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_Phone;
	string m_Addr;
};
struct Addressbooks
{
	struct Person personArray[MAX];
	int m_Size;
};
void showMenu(void)
{
	cout << "**************************" << endl;
	cout << "*****  1.添加联系人  *****" << endl;
	cout << "*****  2.显示联系人  *****" << endl;
	cout << "*****  3.删除联系人  *****" << endl;
	cout << "*****  4.查找联系人  *****" << endl;
	cout << "*****  5.修改联系人  *****" << endl;
	cout << "*****  6.清空联系人  *****" << endl;
	cout << "*****  0.退出通讯录  *****" << endl;
	cout << "**************************" << endl;
}
void addPerson(struct Addressbooks* abs)
{
	if (abs->m_Size == MAX)
	{
		cout << "通讯录已满，无法再添加" << endl;
		return;
	}
	else
	{
		//姓名
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		//性别
		int sex;
		cout << "请输入性别" << endl;
		cout << "1----男" << endl;
		cout << "2----女" << endl;
		while (1)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}
		//年龄
		int age;
		cout << "请输入年龄" << endl;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;
		//电话
		string phone;
		cout << "请输入电话" << endl;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;
		//地址
		string address;
		cout << "请输入地址" << endl;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;
		cout << "添加成功" << endl;
		//更新通讯录人数
		abs->m_Size++;
		system("pause");
		system("cls");
	}
}
void showPerson(struct Addressbooks* abs)
{
	if (abs->m_Size == 0)
	{
		cout << "当前记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名：" << abs->personArray[i].m_Name << "  "
				 << "性别：" << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << "  "
				 << "年龄：" << abs->personArray[i].m_Age << "  "
				 << "电话：" << abs->personArray[i].m_Phone << "  "
				 << "地址：" << abs->personArray[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls");
}
int isExit(struct Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name)
		{
			return i;
		}			
	}
	return -1;
}
void deletePerson(struct Addressbooks* abs)
{
	string name;
	int ret;
	cout << "请输入要删除的人名" << endl;
	cin >> name;
	ret = isExit(abs, name);
	if (ret != -1)
	{
		for (int i = ret; i < abs->m_Size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
void findPerson(struct Addressbooks* abs)
{
	string name;
	int ret;
	cout << "请输入要查找的联系人" << endl;
	cin >> name;
	ret = isExit(abs, name);
	if (ret != -1)
	{
		cout << "姓名：" << abs->personArray[ret].m_Name << "  "
			 << "性别：" << (abs->personArray[ret].m_Sex == 1 ? "男" : "女") << "  "
			 << "年龄：" << abs->personArray[ret].m_Age << "  "
			 << "电话：" << abs->personArray[ret].m_Phone << "  "
			 << "地址：" << abs->personArray[ret].m_Addr << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
void modifyPerson(struct Addressbooks* abs)
{
	string name;
	int ret;
	cout << "请输入要修改的联系人" << endl;
	cin >> name;
	ret = isExit(abs, name);
	if (ret != -1)
	{
		//姓名
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;
		//性别
		int sex;
		cout << "请输入性别" << endl;
		cout << "1----男" << endl;
		cout << "2----女" << endl;
		while (1)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}
		//年龄
		int age;
		cout << "请输入年龄" << endl;
		cin >> age;
		abs->personArray[ret].m_Age = age;
		//电话
		string phone;
		cout << "请输入电话" << endl;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;
		//地址
		string address;
		cout << "请输入地址" << endl;
		cin >> address;
		abs->personArray[ret].m_Addr = address;
		cout << "修改成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
void cleanPerson(struct Addressbooks* abs)
{
	abs->m_Size = 0;
	cout << "清空成功" << endl;
	system("pause");
	system("cls");
}
int main(void)
{
	int select = 0;
	struct Addressbooks abs;
	abs.m_Size = 0;
	while (1)
	{
		showMenu();
		cin >> select;
		switch (select)
		{
			case 1:
				addPerson(&abs);
				break;
			case 2:
				showPerson(&abs);
				break;
			case 3:
				deletePerson(&abs);
				break;
			case 4:
				findPerson(&abs);
				break;
			case 5:
				modifyPerson(&abs);
				break;
			case 6:
				cleanPerson(&abs);
				break;
			case 0:
				cout << "欢迎下次继续使用" << endl;
				return 0;
		}
	}	
	return 0;
}
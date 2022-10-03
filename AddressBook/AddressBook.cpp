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
	cout << "*****  1.�����ϵ��  *****" << endl;
	cout << "*****  2.��ʾ��ϵ��  *****" << endl;
	cout << "*****  3.ɾ����ϵ��  *****" << endl;
	cout << "*****  4.������ϵ��  *****" << endl;
	cout << "*****  5.�޸���ϵ��  *****" << endl;
	cout << "*****  6.�����ϵ��  *****" << endl;
	cout << "*****  0.�˳�ͨѶ¼  *****" << endl;
	cout << "**************************" << endl;
}
void addPerson(struct Addressbooks* abs)
{
	if (abs->m_Size == MAX)
	{
		cout << "ͨѶ¼�������޷������" << endl;
		return;
	}
	else
	{
		//����
		string name;
		cout << "����������" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		//�Ա�
		int sex;
		cout << "�������Ա�" << endl;
		cout << "1----��" << endl;
		cout << "2----Ů" << endl;
		while (1)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "������������������" << endl;
		}
		//����
		int age;
		cout << "����������" << endl;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;
		//�绰
		string phone;
		cout << "������绰" << endl;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;
		//��ַ
		string address;
		cout << "�������ַ" << endl;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;
		cout << "��ӳɹ�" << endl;
		//����ͨѶ¼����
		abs->m_Size++;
		system("pause");
		system("cls");
	}
}
void showPerson(struct Addressbooks* abs)
{
	if (abs->m_Size == 0)
	{
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "������" << abs->personArray[i].m_Name << "  "
				 << "�Ա�" << (abs->personArray[i].m_Sex == 1 ? "��" : "Ů") << "  "
				 << "���䣺" << abs->personArray[i].m_Age << "  "
				 << "�绰��" << abs->personArray[i].m_Phone << "  "
				 << "��ַ��" << abs->personArray[i].m_Addr << endl;
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
	cout << "������Ҫɾ��������" << endl;
	cin >> name;
	ret = isExit(abs, name);
	if (ret != -1)
	{
		for (int i = ret; i < abs->m_Size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout << "ɾ���ɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
void findPerson(struct Addressbooks* abs)
{
	string name;
	int ret;
	cout << "������Ҫ���ҵ���ϵ��" << endl;
	cin >> name;
	ret = isExit(abs, name);
	if (ret != -1)
	{
		cout << "������" << abs->personArray[ret].m_Name << "  "
			 << "�Ա�" << (abs->personArray[ret].m_Sex == 1 ? "��" : "Ů") << "  "
			 << "���䣺" << abs->personArray[ret].m_Age << "  "
			 << "�绰��" << abs->personArray[ret].m_Phone << "  "
			 << "��ַ��" << abs->personArray[ret].m_Addr << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
void modifyPerson(struct Addressbooks* abs)
{
	string name;
	int ret;
	cout << "������Ҫ�޸ĵ���ϵ��" << endl;
	cin >> name;
	ret = isExit(abs, name);
	if (ret != -1)
	{
		//����
		string name;
		cout << "����������" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;
		//�Ա�
		int sex;
		cout << "�������Ա�" << endl;
		cout << "1----��" << endl;
		cout << "2----Ů" << endl;
		while (1)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "������������������" << endl;
		}
		//����
		int age;
		cout << "����������" << endl;
		cin >> age;
		abs->personArray[ret].m_Age = age;
		//�绰
		string phone;
		cout << "������绰" << endl;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;
		//��ַ
		string address;
		cout << "�������ַ" << endl;
		cin >> address;
		abs->personArray[ret].m_Addr = address;
		cout << "�޸ĳɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
void cleanPerson(struct Addressbooks* abs)
{
	abs->m_Size = 0;
	cout << "��ճɹ�" << endl;
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
				cout << "��ӭ�´μ���ʹ��" << endl;
				return 0;
		}
	}	
	return 0;
}
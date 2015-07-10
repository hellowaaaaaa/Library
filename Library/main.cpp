#include <iostream>
#include "User.h"
#include "Manager.h"
#include "DBUtil.h"
#include "Student.h"
#include "Book.h"
using namespace std;

int main()
{
	string strUserName = "";
	string strUserPWD = "";
	bool bIsLogin = false;
	User user;
	cout << "                      �������û�����";
	cin >> strUserName;
	cout << endl;
	cout << "                      ���������룺";
	cin >> strUserPWD;
	cout << endl;
	DBUtil dbUtil;
	dbUtil.OpenDB();
	user = dbUtil.ReadUser(strUserName, strUserPWD);
	if (user.m_nRole == 1)
	{
		Manager manager;
		manager.m_nID = user.m_nRole;
		manager.m_strName = user.m_strName;
		manager.m_nRole = user.m_nRole;
		int command = -1;		//ѡ������
		bIsLogin = true;
		while (bIsLogin)
		{
			system("cls");
			manager.ShowMenu();
			cout << "��ѡ�����";
			cin >> command;
			switch (command)
			{
			case 1:
				//ѡ������ͼ��
				manager.AddBook();			
				break;
			case 0:
				//ѡ���˳���¼
				bIsLogin = false;
				break;
			default:
				break;
			}
		}
		cout << "�����˳���¼����������˳�..." << endl;
	}
	else
	{
		Student student;
		student.m_nID = user.m_nRole;
		student.m_strName = user.m_strName;
		student.m_nRole = user.m_nRole;
		int command = -1;		//ѡ������
		bIsLogin = true;
		while (bIsLogin)
		{
			system("cls");
			student.ShowMenu();
			cout << "��ѡ�����";
			cin >> command;
			switch (command)
			{
			case 1:
				//ѡ������ͼ��
				//manager.AddBook();
				break;
			case 0:
				//ѡ���˳���¼
				bIsLogin = false;
				break;
			default:
				break;
			}
		}
		cout << "�����˳���¼����������˳�..." << endl;
	}
	cin.get();
	cin.get();
	return 0;
}
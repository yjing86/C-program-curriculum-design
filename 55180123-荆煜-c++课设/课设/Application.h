#pragma once
#include<iostream>
#include"Base_JY.h"
#include"QQ_JY.h"
#include"Friendmanage_JY.h"
#include"Groupmanage_JY.h"
using namespace std;

class Application
{
private:
public:
	void login();
	//��¼
	void how_sign_in();
	//�����ʺŵ�¼
	void menu_qq(long id);
	//Ӧ�ò˵�
	long creat_app();
	//ע��
};

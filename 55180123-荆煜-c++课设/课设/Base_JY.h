#pragma once
#include<iostream>
#include<vector>
#include"Date_JY.h"
#include"Friendmanage_JY.h"
#include"Groupmanage_JY.h"
using namespace std;
class Base_JY
{
private:
	//	long id;
		//��������
		//static vector<vector<bool> > friendlist;
		//static vector<vector<int> > grouplist;
public:
	Date_JY creatday;
	string name;
	Date_JY birthday;
	string location;
	int gender;
	//�Ա�
	//0Ů 1�� ��ֵ����
	bool online;
	//�Ƿ�����
	//0������ 1����
//	void get_id();
	//����˺�
	void get_name();
	//����ǳ�
	void get_gender();
	//����Ա�
	void get_location();
	//��þ�ס��
	void get_birthday();
	//�������
	void show();
	//��ʾ�˻���Ϣ
	void get_creatday();
	virtual void creat() {}
	virtual void print_friend() {}
	virtual void read_friend() {}
	virtual void add_friend() {}
	virtual void delete_friend() {}
};


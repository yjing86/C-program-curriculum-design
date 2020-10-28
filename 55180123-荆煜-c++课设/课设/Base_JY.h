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
		//创建日期
		//static vector<vector<bool> > friendlist;
		//static vector<vector<int> > grouplist;
public:
	Date_JY creatday;
	string name;
	Date_JY birthday;
	string location;
	int gender;
	//性别
	//0女 1男 负值保密
	bool online;
	//是否在线
	//0不在线 1在线
//	void get_id();
	//获得账号
	void get_name();
	//获得昵称
	void get_gender();
	//获得性别
	void get_location();
	//获得居住地
	void get_birthday();
	//获得生日
	void show();
	//显示账户信息
	void get_creatday();
	virtual void creat() {}
	virtual void print_friend() {}
	virtual void read_friend() {}
	virtual void add_friend() {}
	virtual void delete_friend() {}
};


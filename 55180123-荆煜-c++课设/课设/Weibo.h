#pragma once
#include"Base_JY.h"
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

class Weibo:Base_JY
{
private:
	long id;
public:
	Friendmanage_JY weibo_friendmanage;
	Groupmanage_JY weibo_groupmanage;
	int connect_wechat;
	//0 û����
	//1 �ѹ���
	int connect_weibo;
	long connect_wechat_id;
	string key;
	Weibo(long qid);
	Weibo();
	void creat();
	long return_id() {
		return id;
	}
	void show_all();
};


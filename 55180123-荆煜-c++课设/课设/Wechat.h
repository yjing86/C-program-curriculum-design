#pragma once
#include"Base_JY.h"
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

class Wechat:Base_JY
{
private:
	long id;
public:
	Friendmanage_JY wechat_friendmanage;
	Groupmanage_JY wechat_groupmanage;
	int connect_wechat;
	//0 没关联
	//1 已关联
	int connect_weibo;
	long connect_wechat_id;
	string key;
	Wechat(long qid);
	Wechat();
	void creat();
	long return_id() {
		return id;
	}
	void show_all();
};


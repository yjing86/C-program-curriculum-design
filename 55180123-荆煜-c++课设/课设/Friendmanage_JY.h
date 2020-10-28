#pragma once
#include<iostream>
#include <string>
#include <vector>
using namespace std;
class Friendmanage_JY
{
private:
public:
	vector<vector<int> >friendlist;
	void read_friendlist();
	//读入
	void save_friendlist();
	//保存
	void add_friend(long id);
	//添加好友
	void delete_friend(long id);
	//删除好友
	void search_friend(long id);
	//查询好友
	void watch_add(long id);
	//接受请求
};


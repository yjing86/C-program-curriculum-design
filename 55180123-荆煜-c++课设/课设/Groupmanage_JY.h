#pragma once
#include<iostream>
#include <string>
#include <vector>
using namespace std;
class Groupmanage_JY
{
private:
	long groupid;
public:
	string group_name;
	int type;
	//0为群
	//1为讨论组
	vector<vector<int> >grouplist;
	//1为申请
	//2为成员
	//3为管理员
	//4为群主
	void apply_zu(long id);
	//新建讨论组
	void apply_group(long id);
	//新建群
	void read_grouplist();
	//读入
	void save_grouplist();
	//保存
	void add_number(long id,long groupid);
	//添加
	void apply(long id);
	//申请
	void delete_number(long id, long groupid);
	//删除
	void search_number(long id, long groupid);
	//查询
	void watch_add(long id, long groupid);
	//接受申请
	void set(long id, long groupid);
	//设置
};


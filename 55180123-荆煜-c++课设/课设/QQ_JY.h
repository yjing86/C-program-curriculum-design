#pragma once
#include"Base_JY.h"
#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;
class QQ_JY :Base_JY {
private:
	//static vector<vector<bool> > friendlist ;
//	static vector<vector<int> > grouplist;
	long id;
public:
	Friendmanage_JY qq_friendmanage;
	Groupmanage_JY qq_groupmanage;
	int connect_wechat;
	//0 没关联
	//1 已关联
	int connect_weibo;
	long connect_wechat_id;
	string key;
	QQ_JY(long qid);
	QQ_JY();
	void creat();
	long return_id() {
		return id;
	}
	void show_all();
	//void print_friend();
	//	 void read_friend() {
	//		 char filename_id[30] = "./QQ/source/qq_id_max.txt";
		//	 long max_id = 0;
			// ifstream filein_id(filename_id, ios::in );
	//		 filein_id >> max_id;
	//		 vector<bool> temp_vector(max_id,0);
	////		 friendlist.resize(max_id, temp_vector);
	//		 filein_id.close();
	//	 }
	//void add_friend();
	//void delete_friend();
};
//第 行 id
//第一二三行 creatday
//第四五六行 birthday
//第7行name
//第8行location
//第9行gender
//第10行key
//第11行 0(online)
//第12行 connect_wechat
//第13行 connect_weibo
//第14行 connect_wechat_d



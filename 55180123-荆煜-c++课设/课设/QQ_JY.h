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
	//0 û����
	//1 �ѹ���
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
//�� �� id
//��һ������ creatday
//���������� birthday
//��7��name
//��8��location
//��9��gender
//��10��key
//��11�� 0(online)
//��12�� connect_wechat
//��13�� connect_weibo
//��14�� connect_wechat_d



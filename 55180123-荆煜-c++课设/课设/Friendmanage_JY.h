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
	//����
	void save_friendlist();
	//����
	void add_friend(long id);
	//��Ӻ���
	void delete_friend(long id);
	//ɾ������
	void search_friend(long id);
	//��ѯ����
	void watch_add(long id);
	//��������
};


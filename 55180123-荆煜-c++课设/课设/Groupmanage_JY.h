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
	//0ΪȺ
	//1Ϊ������
	vector<vector<int> >grouplist;
	//1Ϊ����
	//2Ϊ��Ա
	//3Ϊ����Ա
	//4ΪȺ��
	void apply_zu(long id);
	//�½�������
	void apply_group(long id);
	//�½�Ⱥ
	void read_grouplist();
	//����
	void save_grouplist();
	//����
	void add_number(long id,long groupid);
	//���
	void apply(long id);
	//����
	void delete_number(long id, long groupid);
	//ɾ��
	void search_number(long id, long groupid);
	//��ѯ
	void watch_add(long id, long groupid);
	//��������
	void set(long id, long groupid);
	//����
};


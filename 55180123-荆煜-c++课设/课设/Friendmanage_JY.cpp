#include "Friendmanage_JY.h"
#include<fstream>
#include<vector>
#include<string>
#include"Limit_JY.h"
using namespace std;
void Friendmanage_JY::read_friendlist() {
	char filename_id[30] = "./QQ/source/qq_id_max.txt";
	long max_id = 0;
	ifstream filein_id(filename_id, ios::in);
	filein_id >> max_id;
	vector<int> temp_vector(max_id+1, 0);
	friendlist.resize(max_id+1, temp_vector);
	filein_id.close();
	//��ȡ�����ʺ����ֵ

	char filename_friend[30] = "./QQ/source/qq_friend.txt";
	ifstream file_friend;
	file_friend.open(filename_friend);
	if (!file_friend)
		cout << "error";
	for (int i = 0; i <= max_id; i++) {
		for (int j = 0; j <= max_id; j++) {
			file_friend >> friendlist[i][j];
		}
	}
}
void Friendmanage_JY::save_friendlist() {
	char filename_id[30] = "./QQ/source/qq_id_max.txt";
	long max_id = 0;
	ifstream filein_id(filename_id, ios::in);
	filein_id >> max_id;
	filein_id.close();
	//��ȡ�����ʺ����ֵ

	char filename_friend[30] = "./QQ/source/qq_friend.txt";
	ofstream file_friend;
	file_friend.open(filename_friend);
	if (!file_friend)
		cout << "error";
	for (int i = 0; i < max_id; i++) {
		for (int j = 0; j < max_id; j++) {
			file_friend << friendlist[i][j]<<endl;
		}
		file_friend << "0"<<endl;
	}
	for (int i = 0; i <= max_id; i++) {
		file_friend << "0"<<endl;
	}
}
void Friendmanage_JY::add_friend(long id) {
	Limit_JY a;
	long max_id = friendlist.size();
	cout << "������������ӵĺ���id��";	
	long duifang_id=a.numberlimit(0,max_id,0);
	if (friendlist[id][duifang_id] == 1) {
		if (friendlist[duifang_id][id] == 1)
			cout << "�Է��Ѿ�Ϊ��ĺ���" << endl;
		else
			cout << "������Է�����" << endl;
	}
	else {
		cout << "����Է���������" << endl;
		friendlist[id][duifang_id] = 1;
	}
}
void Friendmanage_JY::delete_friend(long id) {
	Limit_JY a;
	long max_id = friendlist.size();
	cout << "����������ɾ���ĺ���id��";
	long duifang_id = a.numberlimit(0, max_id, 0);
	if (friendlist[id][duifang_id] == 1) {
		if (friendlist[duifang_id][id] == 1) {
			cout << "�ѳɹ�ɾ��" << endl;
			friendlist[id][duifang_id] = 0;
			friendlist[duifang_id][id] = 0;
		}
		else
			cout << "�Է�δ�����Ϊ����" << endl;
	}
	else {
		cout << "�Է�δ�����Ϊ����" << endl;
	}
}
void Friendmanage_JY::search_friend(long id) {
	long max_id = friendlist.size();
	for (int i = 0; i < max_id; i++) {
		if (friendlist[id][i] == 1 && friendlist[i][id] == 1) {
			cout << "���ĺ���id��" << i;
			char filename[30];
			sprintf(filename, "./QQ/person/qq_%ld.txt", i);
			FILE* filep = fopen(filename, "r");
			if (filep == NULL)
				cout << "./QQ/person/qq_%ld.txt can's found";
			int b1, b2, b3, d1, d2, d3;
			char t_name[30];

			fscanf(filep, "%d %d %d %d %d %d %s", &b1, &b2, &b3, &d1, &d2, &d3, t_name);
			fclose(filep);
			cout << "  �ǳƣ�" << t_name << endl;
		}
	}
	cout << "***************************************************" << endl;
}
void Friendmanage_JY::watch_add(long id) {
	Limit_JY a;
	long max_id = friendlist.size();
	for (int i = 0; i < max_id; i++) {
		if (friendlist[i][id] == 1 && friendlist[id][i] == 0) {
			char filename[30];
			sprintf(filename, "./QQ/person/qq_%ld.txt", i);
			FILE* filep = fopen(filename, "r");
			if (filep == NULL)
				cout << "./QQ/person/qq_%ld.txt can's found";
			int b1, b2, b3, d1, d2, d3;
			char t_name[30];
			fscanf(filep, "%d %d %d %d %d %d %s", &b1, &b2, &b3, &d1, &d2, &d3, t_name);
			fclose(filep);
			cout << "id:" << i << "  �ǳƣ�" << t_name << "���������������룬ͬ��������1���ܾ�������2��";
			int temp_queren = a.numberlimit(1,2,0);
			if (temp_queren == 1) {
				friendlist[id][i] == 1;
				cout << "����ͬ�� id:" << i << "  �ǳƣ�" << t_name << "�ĺ�������"<<endl;
			}
			else {
				friendlist[i][id] == 0;
				cout << "���Ѿܾ� id:" << i << "  �ǳƣ�" << t_name << "�ĺ�������" << endl;
			}
		}
	}
}
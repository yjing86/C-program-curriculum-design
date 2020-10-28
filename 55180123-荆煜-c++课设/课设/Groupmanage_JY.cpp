#include "Groupmanage_JY.h"
#include<fstream>
#include<vector>
#include<string>
#include"Limit_JY.h"
using namespace std;
void Groupmanage_JY::apply_group(long id) {	
	read_grouplist();

	FILE* open_file = fopen("./QQ/source/qq_group_max.txt", "r");
	long temp = 0;
	fscanf(open_file, "%ld", &temp);
	groupid = temp++;
	cout << "����ȺIDΪ" << groupid << endl;
	fclose(open_file);
	FILE* close_file = fopen("./QQ/source/qq_group_max.txt", "w");
	fprintf(close_file, "%ld", temp);
	fclose(close_file);
	cout << "������Ⱥ���ǳ�:";
	cin >> group_name;
	char filename[30];
	sprintf(filename, "./QQ/group/qq_%ld.txt",groupid );
	FILE* creatfile = fopen(filename, "w");
	fprintf(creatfile, "%s",group_name);
	fclose(creatfile);

	long id_max = grouplist[0].size();
	vector<int> temp_vector(id_max, 0);
	vector<vector<int> >b;
	b.resize(groupid, temp_vector);
	b = grouplist;
	grouplist.resize(groupid+1, temp_vector);
	for (int i = 0; i < groupid; i++) {
		for (int j = 0; j < id_max; j++) {
			grouplist[i][j] = b[i][j];
		}
	}

	grouplist[groupid][id] = 4;
	cout << "�ɹ�����Ⱥ"<<groupid<<"!\n��Ϊ��ȺȺ��\n";

}
//�½�Ⱥ
void Groupmanage_JY::apply_zu(long id) {
	read_grouplist();

	FILE* open_file = fopen("./QQ/source/qq_group_max.txt", "r");
	long temp = 0;
	fscanf(open_file, "%ld", &temp);
	groupid = temp++;
	cout << "����������IDΪ" << groupid << endl;
	fclose(open_file);
	FILE* close_file = fopen("./QQ/source/qq_group_max.txt", "w");
	fprintf(close_file, "%ld", temp);
	fclose(close_file);
	cout << "�����������������:";
	cin >> group_name;
	char filename[30];
	sprintf(filename, "./QQ/group/qq_%ld.txt", groupid);
	FILE* creatfile = fopen(filename, "w");
	fprintf(creatfile, "%s", group_name);
	fclose(creatfile);

	long id_max = grouplist[0].size();
	vector<int> temp_vector(id_max, 0);
	vector<vector<int> >b;
	b.resize(groupid, temp_vector);
	b = grouplist;
	grouplist.resize(groupid + 1, temp_vector);
	for (int i = 0; i < groupid; i++) {
		for (int j = 0; j < id_max; j++) {
			grouplist[i][j] = b[i][j];
		}
	}

	grouplist[groupid][id] = 4;
	cout << "�ɹ�����������" << groupid << "!\n";

}
	//�½�������
void Groupmanage_JY::read_grouplist() {

	char filename_id[30] = "./QQ/source/qq_id_max.txt";
	long max_id = 0;
	ifstream filein_id(filename_id, ios::in);
	filein_id >> max_id;	
	filein_id.close();

	char filename_number[30] = "./QQ/source/qq_number_max.txt";
	long max_number = 0;
	ifstream filein_number(filename_number, ios::in);
	filein_number >> max_number;
	filein_number.close();


	char filename_groupid[30] = "./QQ/source/qq_group_max.txt";
	long max_group = 0;
	ifstream filein_groupid(filename_groupid, ios::in);
	filein_groupid >> max_group;
	filein_groupid.close();

	vector<int> temp_vector(max_number + 1, 0);
	grouplist.resize(max_group + 1, temp_vector);
	//��ȡ�����ʺ����ֵ

	char filename_friend[30] = "./QQ/source/qq_group.txt";
	ifstream file_group;
	file_group.open(filename_friend);
	if (!file_group)
		cout << "error";
	for (int i = 0; i <= max_group; i++) {
		for (int j = 0; j < max_number; j++) {
			file_group >> grouplist[i][j];
		}
	}

}
//����
void Groupmanage_JY::save_grouplist() {
	
	long max_id = grouplist[0].size();
	long max_group = grouplist.size();

	char filename_number[30] = "./QQ/source/qq_number_max.txt";
	ofstream file_number;
	file_number.open(filename_number);
	if (!file_number)
		cout << "error"<<endl;
	file_number << max_id << endl;
	file_number.close();

	

	char filename_group[30] = "./QQ/source/qq_group.txt";
	ofstream file_group;
	file_group.open(filename_group);
	if (!file_group)
		cout << "error";
	for (int i = 0; i < max_group; i++) {
		for (int j = 0; j <max_id; j++) {
			file_group << grouplist[i][j] << endl;
		}
	}
	file_group.close();
}
//����
void Groupmanage_JY::apply(long id) {
	Limit_JY a;
	long max_id = grouplist[0].size();
	long max_group = grouplist.size();
	cout << "������������ӵ�Ⱥid��";
	long group_apply_id = a.numberlimit(0, max_group, 0);
	if (grouplist[group_apply_id][id] ==0 ) {
		cout << "�����Ⱥ��������" << endl;
		grouplist[group_apply_id][id] == 1;
	}
	if (grouplist[group_apply_id][id] == 1) {
		cout << "���������Ⱥ" << endl;
	}
	if (grouplist[group_apply_id][id] != 1 && grouplist[group_apply_id][id] != 0) {
		cout << "�����ڸ�Ⱥ��" << endl;
	}
}
//����
void Groupmanage_JY::add_number(long id,long groupid) {
	Limit_JY a;
	long max_id = grouplist[0].size();
	long max_group = grouplist.size();
	if (grouplist[groupid][id] == 0 || grouplist[groupid][id] == 1||grouplist[groupid][id]==2) {
		cout << "����Ȩ�ޣ�\n";
	}
	else{
		cout << "��������������ĳ�Աid��";	
		long group_invite_id = a.numberlimit(0, max_id, 0);
		if (grouplist[groupid][group_invite_id] == 0 || grouplist[groupid][id] == 1) {
			cout << "�Է��ѳɹ�����Ⱥ\n";
			grouplist[groupid][group_invite_id] = 2;
		}
		else {
			cout << "�Է�����Ⱥ��\n";
		}
	}
}
//���
void Groupmanage_JY::delete_number(long id, long groupid) {
	Limit_JY a;
	long max_id = grouplist[0].size();
	long max_group = grouplist.size();
	if (grouplist[groupid][id] == 0 || grouplist[groupid][id] == 1 || grouplist[groupid][id] == 2) {
		cout << "����Ȩ�ޣ�\n";
	}
	else {
		cout << "����������ɾ���ĳ�Աid��";
		long group_invite_id = a.numberlimit(0, max_id, 0);
		if (grouplist[groupid][group_invite_id] == 0 || grouplist[groupid][id] == 1) {
			cout << "�Է�����Ⱥ��\n";
		}
		else {
			if (grouplist[groupid][group_invite_id] == 2) {
				cout << "�ѳɹ�ɾ��\n";
				grouplist[groupid][group_invite_id] == 0;
			}
			else {
				if (grouplist[groupid][group_invite_id] == 3 && grouplist[groupid][id] == 4) {
					cout << "�ѳɹ�ɾ��\n";
					grouplist[groupid][group_invite_id] == 0;
				}
				else {
					cout << "����Ȩ�ޣ�\n";
				}
			}
		}
	}
}
//ɾ��
void Groupmanage_JY::search_number(long id, long groupid) {
	long max_id = grouplist[0].size();
	long max_group = grouplist.size();
	for (int i = 0; i < max_id; i++) {
		if (grouplist[groupid][i] != 0 && grouplist[groupid][i] != 1) {
			cout << "idΪ" << id << "���˻��ڸ�Ⱥ" << groupid << "��"<<endl;
		}
	}
	cout << "***************************************************" << endl;
}
//��ѯ
void Groupmanage_JY::watch_add(long id, long groupid) {
	Limit_JY a;
	long max_id = grouplist[0].size();
	long max_group = grouplist.size();
	for (int i = 0; i < max_id; i++) {
		if (grouplist[groupid][i] == 1) {
			cout << "idΪ" << id << "���˻���������Ⱥ" << groupid << ",ͬ��������1���ܾ�������0��" << endl;
			int panduan = a.numberlimit(0,1,0);
			if (panduan == 0) {
				cout << "���Ѿܾ�\n";
				grouplist[groupid][i] = 0;
			}
			if (panduan == 1) {
				cout << "����ͬ��\n";
				grouplist[groupid][i] = 2;
			}
		}
	}
}
//��������
void Groupmanage_JY::set(long id, long groupid) {
	Limit_JY a;
	long max_id = grouplist[0].size();
	long max_group = grouplist.size();
	if (grouplist[groupid][id] == 4) {
		cout << "�޸�Ⱥ��������0����ӹ���Ա������1��ɾ������Ա������2������������3��" << endl;
		int panduan = a.numberlimit(0, 3, 0);
		if (panduan == 0) {
			cout << "������Ⱥ���ƣ�";
			cin >> group_name;
		}
		if (panduan == 1) {
			search_number(id,groupid);
			cout << "������Է�id:";
			int temp_id = a.numberlimit(0,max_id,0);
			if (grouplist[groupid][temp_id] == 0|| grouplist[groupid][temp_id]==1) {
				cout << "�Է�����Ⱥ��"<<endl;
			}
			if (grouplist[groupid][temp_id] == 2) {
				cout << "�ɹ����Է�����Ϊ����Ա" << endl;
				grouplist[groupid][temp_id] == 3;
			}
			if (grouplist[groupid][temp_id] == 3) {
				cout << "�Է���Ϊ����Ա" << endl;
			}
			if (grouplist[groupid][temp_id] == 4) {
				cout << "��Ȩ��"<<endl;
			}
		}
		if (panduan == 2) {
			search_number(id, groupid);
			cout << "������Է�id:";
			int temp_id = a.numberlimit(0, max_id, 0);
			if (grouplist[groupid][temp_id] == 0 || grouplist[groupid][temp_id] == 1) {
				cout << "�Է�����Ⱥ��" << endl;
			}
			if (grouplist[groupid][temp_id] == 2) {
				cout << "�Է���Ϊ����Ա" << endl;
			}
			if (grouplist[groupid][temp_id] == 3) {
				cout << "�ѳ����Է�����ԱȨ��" << endl;
				grouplist[groupid][temp_id] == 2;
			}
			if (grouplist[groupid][temp_id] == 4) {
				cout << "��Ȩ��" << endl;
			}
		}
	}
	if (grouplist[groupid][id] == 3) {
		cout << "�޸�Ⱥ��������0������������1��" << endl;
		int panduan = a.numberlimit(0, 1, 0);
		if (panduan == 0) {
			cout << "������Ⱥ���ƣ�";
			cin >> group_name;
		}
	}
}
//����
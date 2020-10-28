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
	cout << "您的群ID为" << groupid << endl;
	fclose(open_file);
	FILE* close_file = fopen("./QQ/source/qq_group_max.txt", "w");
	fprintf(close_file, "%ld", temp);
	fclose(close_file);
	cout << "请输入群的昵称:";
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
	cout << "成功创建群"<<groupid<<"!\n您为该群群主\n";

}
//新建群
void Groupmanage_JY::apply_zu(long id) {
	read_grouplist();

	FILE* open_file = fopen("./QQ/source/qq_group_max.txt", "r");
	long temp = 0;
	fscanf(open_file, "%ld", &temp);
	groupid = temp++;
	cout << "您的讨论组ID为" << groupid << endl;
	fclose(open_file);
	FILE* close_file = fopen("./QQ/source/qq_group_max.txt", "w");
	fprintf(close_file, "%ld", temp);
	fclose(close_file);
	cout << "请输入讨论组的名称:";
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
	cout << "成功创建讨论组" << groupid << "!\n";

}
	//新建讨论组
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
	//读取所有帐号最大值

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
//读入
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
//保存
void Groupmanage_JY::apply(long id) {
	Limit_JY a;
	long max_id = grouplist[0].size();
	long max_group = grouplist.size();
	cout << "请输入您想添加的群id：";
	long group_apply_id = a.numberlimit(0, max_group, 0);
	if (grouplist[group_apply_id][id] ==0 ) {
		cout << "已向该群发出申请" << endl;
		grouplist[group_apply_id][id] == 1;
	}
	if (grouplist[group_apply_id][id] == 1) {
		cout << "您已申请该群" << endl;
	}
	if (grouplist[group_apply_id][id] != 1 && grouplist[group_apply_id][id] != 0) {
		cout << "您已在该群中" << endl;
	}
}
//申请
void Groupmanage_JY::add_number(long id,long groupid) {
	Limit_JY a;
	long max_id = grouplist[0].size();
	long max_group = grouplist.size();
	if (grouplist[groupid][id] == 0 || grouplist[groupid][id] == 1||grouplist[groupid][id]==2) {
		cout << "您无权限！\n";
	}
	else{
		cout << "请输入您想邀请的成员id：";	
		long group_invite_id = a.numberlimit(0, max_id, 0);
		if (grouplist[groupid][group_invite_id] == 0 || grouplist[groupid][id] == 1) {
			cout << "对方已成功加入群\n";
			grouplist[groupid][group_invite_id] = 2;
		}
		else {
			cout << "对方已在群众\n";
		}
	}
}
//添加
void Groupmanage_JY::delete_number(long id, long groupid) {
	Limit_JY a;
	long max_id = grouplist[0].size();
	long max_group = grouplist.size();
	if (grouplist[groupid][id] == 0 || grouplist[groupid][id] == 1 || grouplist[groupid][id] == 2) {
		cout << "您无权限！\n";
	}
	else {
		cout << "请输入您想删除的成员id：";
		long group_invite_id = a.numberlimit(0, max_id, 0);
		if (grouplist[groupid][group_invite_id] == 0 || grouplist[groupid][id] == 1) {
			cout << "对方不在群中\n";
		}
		else {
			if (grouplist[groupid][group_invite_id] == 2) {
				cout << "已成功删除\n";
				grouplist[groupid][group_invite_id] == 0;
			}
			else {
				if (grouplist[groupid][group_invite_id] == 3 && grouplist[groupid][id] == 4) {
					cout << "已成功删除\n";
					grouplist[groupid][group_invite_id] == 0;
				}
				else {
					cout << "您无权限！\n";
				}
			}
		}
	}
}
//删除
void Groupmanage_JY::search_number(long id, long groupid) {
	long max_id = grouplist[0].size();
	long max_group = grouplist.size();
	for (int i = 0; i < max_id; i++) {
		if (grouplist[groupid][i] != 0 && grouplist[groupid][i] != 1) {
			cout << "id为" << id << "的账户在该群" << groupid << "中"<<endl;
		}
	}
	cout << "***************************************************" << endl;
}
//查询
void Groupmanage_JY::watch_add(long id, long groupid) {
	Limit_JY a;
	long max_id = grouplist[0].size();
	long max_group = grouplist.size();
	for (int i = 0; i < max_id; i++) {
		if (grouplist[groupid][i] == 1) {
			cout << "id为" << id << "的账户申请加入该群" << groupid << ",同意请输入1，拒绝请输入0：" << endl;
			int panduan = a.numberlimit(0,1,0);
			if (panduan == 0) {
				cout << "您已拒绝\n";
				grouplist[groupid][i] = 0;
			}
			if (panduan == 1) {
				cout << "您已同意\n";
				grouplist[groupid][i] = 2;
			}
		}
	}
}
//接受申请
void Groupmanage_JY::set(long id, long groupid) {
	Limit_JY a;
	long max_id = grouplist[0].size();
	long max_group = grouplist.size();
	if (grouplist[groupid][id] == 4) {
		cout << "修改群名请输入0，添加管理员请输入1，删除管理员请输入2；返回请输入3：" << endl;
		int panduan = a.numberlimit(0, 3, 0);
		if (panduan == 0) {
			cout << "请输入群名称：";
			cin >> group_name;
		}
		if (panduan == 1) {
			search_number(id,groupid);
			cout << "请输入对方id:";
			int temp_id = a.numberlimit(0,max_id,0);
			if (grouplist[groupid][temp_id] == 0|| grouplist[groupid][temp_id]==1) {
				cout << "对方不在群中"<<endl;
			}
			if (grouplist[groupid][temp_id] == 2) {
				cout << "成功将对方设置为管理员" << endl;
				grouplist[groupid][temp_id] == 3;
			}
			if (grouplist[groupid][temp_id] == 3) {
				cout << "对方现为管理员" << endl;
			}
			if (grouplist[groupid][temp_id] == 4) {
				cout << "无权限"<<endl;
			}
		}
		if (panduan == 2) {
			search_number(id, groupid);
			cout << "请输入对方id:";
			int temp_id = a.numberlimit(0, max_id, 0);
			if (grouplist[groupid][temp_id] == 0 || grouplist[groupid][temp_id] == 1) {
				cout << "对方不在群中" << endl;
			}
			if (grouplist[groupid][temp_id] == 2) {
				cout << "对方不为管理员" << endl;
			}
			if (grouplist[groupid][temp_id] == 3) {
				cout << "已撤销对方管理员权限" << endl;
				grouplist[groupid][temp_id] == 2;
			}
			if (grouplist[groupid][temp_id] == 4) {
				cout << "无权限" << endl;
			}
		}
	}
	if (grouplist[groupid][id] == 3) {
		cout << "修改群名请输入0，返回请输入1：" << endl;
		int panduan = a.numberlimit(0, 1, 0);
		if (panduan == 0) {
			cout << "请输入群名称：";
			cin >> group_name;
		}
	}
}
//设置
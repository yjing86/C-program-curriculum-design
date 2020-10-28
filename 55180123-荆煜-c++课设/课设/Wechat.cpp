#include "Wechat.h"

#include"Limit_JY.h"
using namespace std;
void Wechat::creat() {
	Limit_JY a;
	wechat_friendmanage.read_friendlist();
	wechat_groupmanage.read_grouplist();

	FILE* open_file = fopen("./Wechat/source/wechat_id_max.txt", "r");
	long temp = 0;
	fscanf(open_file, "%ld", &temp);
	id = ++temp;
	cout << "您的帐号ID为" << id << endl;
	fclose(open_file);
	FILE* close_file = fopen("./Wechat/source/wechat_id_max.txt", "w");
	fprintf(close_file, "%ld", temp);
	fclose(close_file);
	get_name();
	get_gender();
	get_location();
	get_birthday();
	get_creatday();
	int panduan = 1;
	string temp_key1, temp_key2;
	while (panduan) {
		panduan = 0;
		cout << "请输入密码：";
		cin >> temp_key1;
		cout << "请再次输入密码：";
		cin >> temp_key2;
		if (temp_key1 != temp_key2)
		{
			panduan = 1;
			cout << "两次密码不一致！";
		}
	}
	key = temp_key1;
	connect_wechat = 0;
	connect_weibo = 0;
	connect_wechat_id = -1;
	char* temp_name = (char*)name.data();
	char* temp_location = (char*)location.data();
	char* temp_key = (char*)key.data();
	char filename[30];
	sprintf(filename, "./Wechat/person/wechat_%ld.txt", id);
	FILE* creatfile = fopen(filename, "w");
	bool temp_online = 0;
	fprintf(creatfile, "%d\n%d\n%d\n%d\n%d\n%d\n%s\n%s\n%d\n%s\n0\n%d\n%d\n%ld\n", birthday.year, birthday.month, birthday.day, creatday.year, creatday.month, creatday.day, temp_name, temp_location, gender, temp_key, connect_wechat, connect_weibo, connect_wechat_id);
	fclose(creatfile);

	wechat_friendmanage.save_friendlist();
	wechat_groupmanage.save_grouplist();
}
void Wechat::show_all()
{
	show();
	cout << "你的密码：" << key;

}
Wechat::Wechat() {
	creat();
}
Wechat::Wechat(long qid) {
	Limit_JY a;
	int panduan = 1;
	char filename[30];
	int temp = 100;
	FILE* fp = NULL;
	while (panduan) {
		panduan = 0;
		sprintf(filename, "./Wechat/person/wechat_%ld.txt", qid);
		fp = fopen(filename, "r");
		if (fp == NULL) {
			cout << "不存在该账号，创建账号请输入0，重试请输入1：";
			temp = a.numberlimit(0, 1, 0);
			if (temp == 0)
				creat();
			if (temp == 1) {
				panduan = 1;
				cout << "请输入ID：";
				cin >> qid;
			}
		}
	}
	if (temp != 0 && fp != NULL) {
		id = qid;
		fscanf(fp, "%d %d %d %d %d %d %s %s %d %s %d %d %d %ld", &creatday.year, &creatday.month, &creatday.day, &birthday.year, &birthday.month, &birthday.day, &name[0], &location[0], &gender, &key[0], &online, &connect_wechat, &connect_weibo, &connect_wechat_id);
	}
	fclose(fp);
	online = 1;
}

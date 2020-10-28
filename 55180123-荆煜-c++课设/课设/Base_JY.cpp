#include "Base_JY.h"
//void Base_JY::get_id() {
//	FILE* open_file = fopen("./source/id_max.txt","r");
//	long temp = 0;
//	fscanf(open_file, "%ld", &temp);
//	id = temp++;
//	cout << "您的帐号ID为" << id << endl;
//	fclose(open_file);
//	FILE* close_file = fopen("./source/id_max.txt", "w");
//	fprintf(close_file, "%ld", temp);
//	fclose(close_file);
//}

void Base_JY::get_name() {
	cout << "请输入您的昵称:";
	cin >> name;
}
void Base_JY::get_gender() {
	Limit_JY a;
	cout << "请输入您的性别(女性请输入0，男性请输入1，保密请输入2)：";
	gender = a.numberlimit(0, 2, 0);
}
void Base_JY::get_location() {
	cout << "请输入您的住址:";
	cin >> location;
}
void Base_JY::get_birthday() {
	birthday.set_time();
}
void Base_JY::show() {
	//	cout << "您的ID为：" <<id  << endl;
	cout << "您的昵称为：" << name << endl;
	cout << "您的地址为：" << location << endl;
	cout << "您的性别为：";
	if (gender == 0)
		cout << "女性";
	if (gender == 1)
		cout << "男性";
	if (gender == 2)
		cout << "保密";
	cout << endl << "您的生日为：";
	birthday.print_time();
	cout << endl << "您的创建日期为：";
	creatday.print_time();
	cout << endl;
}
void Base_JY::get_creatday() {
	creatday.set_system_time();
}
#include "Base_JY.h"
//void Base_JY::get_id() {
//	FILE* open_file = fopen("./source/id_max.txt","r");
//	long temp = 0;
//	fscanf(open_file, "%ld", &temp);
//	id = temp++;
//	cout << "�����ʺ�IDΪ" << id << endl;
//	fclose(open_file);
//	FILE* close_file = fopen("./source/id_max.txt", "w");
//	fprintf(close_file, "%ld", temp);
//	fclose(close_file);
//}

void Base_JY::get_name() {
	cout << "�����������ǳ�:";
	cin >> name;
}
void Base_JY::get_gender() {
	Limit_JY a;
	cout << "�����������Ա�(Ů��������0������������1������������2)��";
	gender = a.numberlimit(0, 2, 0);
}
void Base_JY::get_location() {
	cout << "����������סַ:";
	cin >> location;
}
void Base_JY::get_birthday() {
	birthday.set_time();
}
void Base_JY::show() {
	//	cout << "����IDΪ��" <<id  << endl;
	cout << "�����ǳ�Ϊ��" << name << endl;
	cout << "���ĵ�ַΪ��" << location << endl;
	cout << "�����Ա�Ϊ��";
	if (gender == 0)
		cout << "Ů��";
	if (gender == 1)
		cout << "����";
	if (gender == 2)
		cout << "����";
	cout << endl << "��������Ϊ��";
	birthday.print_time();
	cout << endl << "���Ĵ�������Ϊ��";
	creatday.print_time();
	cout << endl;
}
void Base_JY::get_creatday() {
	creatday.set_system_time();
}
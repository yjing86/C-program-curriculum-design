#pragma once
#include<iostream>
#include"Limit_JY.h"
class Date_JY
{
private:

public:
	int year;
	int month;
	int day;
	void set_system_time();
	//����ϵͳʱ��
	void set_time();
	//�ֶ�����ʱ��
	void print_time();
	//��ʾʱ��
	int get_year();
	//������
	int get_month();
	//������
	int get_day();
	//������
};


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
	//设置系统时间
	void set_time();
	//手动设置时间
	void print_time();
	//显示时间
	int get_year();
	//返回年
	int get_month();
	//返回月
	int get_day();
	//返回日
};


#include "Date_JY.h"
using namespace std;
#include<ctime>
#include<cstdlib>
void Date_JY::set_system_time() {
	struct tm* local;
	time_t temp;
	temp = time(NULL);
	local = localtime(&temp);
	day = local->tm_mday;
	month = local->tm_mon + 1;
	year = local->tm_year + 1900;
}
void Date_JY::set_time() {
	Limit_JY a;
	cout << "您的生日为    年" << "\b\b\b\b\b\b";
	year = a.numberlimit(1900, 2020, 0);
	cout << "              月" << "\b\b\b\b\b\b";
	month = a.numberlimit(1, 12, 0);
	cout << "              日" << "\b\b\b\b\b\b";
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	{
		day = a.numberlimit(1, 31, 0);
	}
	else
	{
		if (month == 2)
		{
			day = a.numberlimit(1, 28, 0);
		}
		else
		{
			day = a.numberlimit(1, 30, 0);
		}
	}
}
void Date_JY::print_time() {
	cout << year << "年" << month << "月" << day << "日";
}
int Date_JY::get_year() {
	return year;
}
int Date_JY::get_month() {
	return year;
}
int Date_JY::get_day() {
	return year;
}
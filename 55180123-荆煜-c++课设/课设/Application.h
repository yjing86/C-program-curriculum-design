#pragma once
#include<iostream>
#include"Base_JY.h"
#include"QQ_JY.h"
#include"Friendmanage_JY.h"
#include"Groupmanage_JY.h"
using namespace std;

class Application
{
private:
public:
	void login();
	//µÇÂ¼
	void how_sign_in();
	//ÓÐÎÞÕÊºÅµÇÂ¼
	void menu_qq(long id);
	//Ó¦ÓÃ²Ëµ¥
	long creat_app();
	//×¢²á
};

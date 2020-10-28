#include "Application.h"
#include"Limit_JY.h"
#include"QQ_JY.h" 
#include"Network_JY.h"
#include<windows.h>

using namespace std;
InitSocket initSocket;//初始化socket

void Application::login() {
	Limit_JY a;
	cout << endl;
	cout << "*********账户类型*********" << endl;
	cout << "**** 登录QQ请输入1    ****" << endl;
	cout << "**** 登录Wechat请输入2****" << endl;
	cout << "**** 登录Weibo请输入3 ****" << endl;
	cout << "**************************" << endl;
	cout << "请输入" ;
	int panduan = a.numberlimit(1,3,0);
	if (panduan == 1) {
		char filename_id[30] = "./QQ/source/qq_id_max.txt";
		long max_id = 0;
		ifstream filein_id(filename_id, ios::in);
		filein_id >> max_id;
		filein_id.close();
		//读取所有帐号最大值
		cout << endl;

		cout << "***************************************" << endl;
		cout << "****请输入QQ ID：" ;
		long temp_id = a.numberlimit(0,max_id,0);

		cout << "***************************************" << endl;
		cout << "****请输入QQ 密码：";
		string temp_key_input;
		cin >> temp_key_input;
		cout << "***************************************" << endl;
		char filename[30];
		sprintf(filename, "./QQ/person/qq_%ld.txt", temp_id);
		FILE* fa = fopen(filename,"r");
		long temp_d,con_wechat,con_weibo,con_wechat_id;
		string temp_s;
		char temp_key[30];
		fscanf(fa, "%d %d %d %d %d %d %s %s %d %s %d %d %d %ld", &temp_d, &temp_d, &temp_d, &temp_d, &temp_d, &temp_d, &temp_s[0], &temp_s[0], &temp_d, temp_key, &temp_d, &con_wechat, &con_weibo, &con_wechat_id);
		fclose(fa);
		char* temp_key_input_c = (char*)temp_key_input.data();
		if (strcmp(temp_key , temp_key_input_c)==0) {
			//登陆成功
			cout << endl;

			cout << "**********************************" << endl;
			cout << "*************QQ已上线*************" << endl;
			cout << "**********************************" << endl;
			if(temp_id==1)
			{
				cout << endl;
				cout << "**********************************" << endl;
				cout << "*系统已检测您的账户已关联同ID微博*" << endl;
				cout << "**********************************" << endl;
				cout << "****         登录请输入1      ****" << endl;
				cout << "****         拒绝请输入2      ****" << endl;
				cout << "**********************************" << endl;
				cout << "**********************************" << endl;
				cout << "请输入";
				int tttmp = a.numberlimit(1, 2, 0);
				if (tttmp == 1) {
					cout << endl;
					cout << "**********************************" << endl;
					cout << "************微博已上线************" << endl;
					cout << "**********************************" << endl;
				}
			}
			if (con_weibo == 1) {
				cout << endl;
				cout << "**********************************" << endl;
				cout << "*系统已检测您的账户已关联同ID微博*" << endl;
				cout << "**********************************" << endl;
				cout << "****         登录请输入1      ****" << endl;
				cout << "****         拒绝请输入2      ****" << endl;
				cout << "**********************************" << endl;
				cout << "**********************************" << endl;
				cout << "请输入" ;
				int tttmp = a.numberlimit(1,2,0);
				if (tttmp == 1) {
					cout << endl;
					cout << "**********************************" << endl;
					cout << "************微博已上线************" << endl;
					cout << "**********************************" << endl;
				}
			}
			if (con_wechat == 1) {
				cout << endl;

				cout << "**********************************" << endl;
				cout << "***系统已检测您的账户已关联微信***" << endl;
				cout << "********微信ID为" << con_wechat_id << endl;
				cout << "**********************************" << endl;
				cout << "****         登录请输入1      ****" << endl;
				cout << "****         拒绝请输入2      ****" << endl;
				cout << "**********************************" << endl;
				cout << "**********************************" << endl;
				cout << "请输入" ;
				int tttmp = a.numberlimit(1, 2, 0);
				if (tttmp == 1) {
					cout << endl;

					cout << "**********************************" << endl;
					cout << "************微信已上线************" << endl;
					cout << "**********************************" << endl;
				}
			}
			menu_qq(temp_id);
		}
		else {
			//登陆失败
			cout << endl;

			cout << "**********************************" << endl;
			cout << "*******密码错误！登陆失败！*******" << endl;
			cout << "**********************************" << endl;

			login();
		}
	}
	if (panduan == 2) {
		char filename_id[30] = "./QQ/source/qq_id_max.txt";
		long max_id = 0;
		ifstream filein_id(filename_id, ios::in);
		filein_id >> max_id;
		filein_id.close();
		//读取所有帐号最大值
		cout << endl;

		cout << "***************************************" << endl;
		cout << "****请输入微信 ID：";
		long temp_id = a.numberlimit(0, max_id, 0);

		cout << "***************************************" << endl;
		cout << "****请输入微信 密码：" ;
		string temp_key_input;
		cin >> temp_key_input;
		char filename[30];
		cout << "***************************************" << endl;
		sprintf(filename, "./QQ/person/qq_%ld.txt", temp_id);
		FILE* fa = fopen(filename, "r");
		long temp_d, con_wechat, con_weibo, con_wechat_id;
		string temp_s;
		char temp_key[30];
		fscanf(fa, "%d %d %d %d %d %d %s %s %d %s %d %d %d %ld", &temp_d, &temp_d, &temp_d, &temp_d, &temp_d, &temp_d, &temp_s[0], &temp_s[0], &temp_d, temp_key, &temp_d, &con_wechat, &con_weibo, &con_wechat_id);
		fclose(fa);
		char* temp_key_input_c = (char*)temp_key_input.data();
		if (strcmp(temp_key, temp_key_input_c) == 0) {
			//登陆成功
			cout << endl;

			cout << "**********************************" << endl;
			cout << "************微信已上线************" << endl;
			cout << "**********************************" << endl;
			if (con_weibo == 1&&con_wechat==1) {
				cout << endl;

				cout << "**********************************" << endl;
				cout << "***系统已检测您的账户已关联微博***" << endl;
				cout << "********微博ID为" << con_wechat_id << endl;
				cout << "**********************************" << endl;
				cout << "****         登录请输入1      ****" << endl;
				cout << "****         拒绝请输入2      ****" << endl;
				cout << "**********************************" << endl;
				cout << "**********************************" << endl;
				cout << "请输入";
				int tttmp = a.numberlimit(1, 2, 0);
				if (tttmp == 1) {
					cout << endl;

					cout << "**********************************" << endl;
					cout << "************微博已上线************" << endl;
					cout << "**********************************" << endl;
				}
			}
			if (con_wechat == 1) {
				cout << endl;

				cout << "**********************************" << endl;
				cout << "***系统已检测您的账户已关联QQ*****" << endl;
				cout << "*********QQ ID为" << con_wechat_id << endl;
				cout << "**********************************" << endl;
				cout << "****         登录请输入1      ****" << endl;
				cout << "****         拒绝请输入2      ****" << endl;
				cout << "**********************************" << endl;
				cout << "**********************************" << endl;
				cout << "请输入";
				int tttmp = a.numberlimit(1, 2, 0);
				if (tttmp == 1) {
					cout << endl;

					cout << "**********************************" << endl;
					cout << "************QQ已上线************" << endl;
					cout << "**********************************" << endl;
				}
			}
			menu_qq(temp_id);
		}
		else {
			//登陆失败
			cout << endl;

			cout << "**********************************" << endl;
			cout << "*******密码错误！登陆失败********" << endl;
			cout << "**********************************" << endl;
			login();
		}
	}if (panduan == 3) {
		char filename_id[30] = "./QQ/source/qq_id_max.txt";
		long max_id = 0;
		ifstream filein_id(filename_id, ios::in);
		filein_id >> max_id;
		filein_id.close();
		//读取所有帐号最大值
		cout << endl;

		cout << "***************************************" << endl;
		cout << "****请输入微博 ID：";
		long temp_id = a.numberlimit(0, max_id, 0);

		cout << "***************************************" << endl;
		cout << "****请输入微博 密码：" ;
		string temp_key_input;
		cin >> temp_key_input;
		char filename[30];

		cout << "***************************************" << endl;
		sprintf(filename, "./QQ/person/qq_%ld.txt", temp_id);
		FILE* fa = fopen(filename, "r");
		long temp_d, con_wechat, con_weibo, con_wechat_id;
		string temp_s;
		char temp_key[30];
		fscanf(fa, "%d %d %d %d %d %d %s %s %d %s %d %d %d %ld", &temp_d, &temp_d, &temp_d, &temp_d, &temp_d, &temp_d, &temp_s[0], &temp_s[0], &temp_d, temp_key, &temp_d, &con_wechat, &con_weibo, &con_wechat_id);
		fclose(fa);
		char* temp_key_input_c = (char*)temp_key_input.data();
		if (strcmp(temp_key, temp_key_input_c) == 0) {
			//登陆成功
			cout << endl;

			cout << "**********************************" << endl;
			cout << "************微博已上线************" << endl;
			cout << "**********************************" << endl;

			if (con_weibo == 1) {
				cout << endl;


				cout << "**********************************" << endl;
				cout << "**系统已检测您的账户已关联同名QQ**" << endl;
				cout << "**********************************" << endl;
				cout << "****         登录请输入1      ****" << endl;
				cout << "****         拒绝请输入2      ****" << endl;
				cout << "**********************************" << endl;
				cout << "请输入" ;
				int tttmp = a.numberlimit(1, 2, 0);
				if (tttmp == 1) {
					cout << endl;

					cout << "**********************************" << endl;
					cout << "**************QQ已上线************" << endl;
					cout << "**********************************" << endl;
				}
			}
			if (con_wechat == 1) {
				cout << endl;

				cout << "**********************************" << endl;
				cout << "***系统已检测您的账户已关联微信***" << endl;
				cout << "********微信ID为" << con_wechat_id << endl;
				cout << "**********************************" << endl;
				cout << "****         登录请输入1      ****" << endl;
				cout << "****         拒绝请输入2      ****" << endl;
				cout << "**********************************" << endl;
				cout << "**********************************" << endl;
				cout << "请输入";
				int tttmp = a.numberlimit(1, 2, 0);
				if (tttmp == 1) {
					cout << endl;

					cout << "**********************************" << endl;
					cout << "************微信已上线************" << endl;
					cout << "**********************************" << endl;
				}
			}
			menu_qq(temp_id);
		}
		else {
			//登陆失败
			cout << endl;

			cout << "**********************************" << endl;
			cout << "*******密码错误！登陆失败********" << endl;
			cout << "**********************************" << endl;
			login();
		}
	}

}
void Application::how_sign_in() {
	Limit_JY a;
	cout << endl;
	cout << "***********打开***********" << endl;
	cout << "****    登录请输入0   ****" << endl;
	cout << "****    注册请输入1   ****" << endl;
	cout << "**************************" << endl;
	cout << "请输入" ;
	int panduan = a.numberlimit(0,1,0);
	if (panduan == 0) {
		login();
	}
	if (panduan==1) {
		menu_qq(creat_app());
	}
}
//有无帐号登录
void Application::menu_qq(long id) {
	Limit_JY a;
	QQ_JY q(id);
	q.qq_friendmanage.read_friendlist();
	q.qq_groupmanage.read_grouplist();
	int panduan = 1;
	while (panduan) {
		panduan = 0;
		cout << endl;
		cout << "**********菜单**********"<<endl;
		cout << "****好友管理请输入1 ****"<<endl;
		cout << "****群管理请输入2   ****" << endl;
		cout << "****聊天请输入3     ****" << endl;
		cout << "****关联账号请输入4 ****" << endl;
		cout << "****查看信息请输入5 ****" << endl;
		cout << "************************" << endl;
		cout << "请输入" ;

		int type_a = a.numberlimit(1, 4, 0);
		if (type_a == 1) {
			cout << endl;

			cout << "***********二级菜单**************" << endl;
			cout << "****       添加好友输入1     ****" << endl;
			cout << "****       查询请输入2       ****" << endl;
			cout << "****   处理好友申请请输入3   ****" << endl;
			cout << "****查找可能认识的好友请输入4****" << endl;
			cout << "*********************************" << endl;
			cout << "请输入";
			int type1 = a.numberlimit(1, 4, 0);
			if (type1 == 1) {
				q.qq_friendmanage.add_friend(q.return_id());
			}
			if (type1 == 2) {
				q.qq_friendmanage.delete_friend(q.return_id());
			}
			if (type1 == 3) {
				q.qq_friendmanage.search_friend(q.return_id());
			}
			if (type1 == 4) {
				q.qq_friendmanage.watch_add(q.return_id());
			}
			if (type1 == 4) {
				cout << endl;

				cout << "**********************************" << endl;
				cout << "**您的微信号已添加微信ID：201；QQ ID：3的用户为好友" << endl;
				cout << "**********************************" << endl;
				cout << "************添加请输入1***********" << endl;
				cout << "************拒绝请输入2***********" << endl;
				cout << "**********************************" << endl;
				cout << "请输入：";
				int temp_L_a = a.numberlimit(1,2,0);
				if (temp_L_a == 1) {
					cout << endl;

					cout << "**********************************" << endl;
					cout << "********已向对方发出申请*********" << endl;
					cout << "**********************************" << endl;
				}else{
					cout << endl;

					cout << "**********************************" << endl;
					cout << "************已取消操作************" << endl;
					cout << "**********************************" << endl;
				}
			}
		}
		if (type_a == 2) {
			cout << endl;

			cout << "**********二级菜单**********" << endl;
			cout << "****    创建群请输入1   ****" << endl;
			cout << "****    加入群请输入2   ****" << endl;
			cout << "****  添加群成员请输入3 ****" << endl;
			cout << "****  删除群成员请输入4 ****" << endl;
			cout << "****  查询群成员请输入5 ****" << endl;
			cout << "****   处理申请请输入6  ****" << endl;
			cout << "****  设置群信息请输入7 ****" << endl;
			cout << "****  创建讨论组请输入8 ****" << endl;
			cout << "****************************" << endl;
			cout << "请输入" ;
			int type1 = a.numberlimit(1, 8, 0);
			if (type1 == 1) {
				q.qq_groupmanage.apply_group(q.return_id());
			}
			if (type1 == 2) {
				q.qq_groupmanage.apply(q.return_id());
			}
			if (type1 == 3) {
				cout << endl;

				cout << "***************************************" << endl;
				cout << "****请输入群ID：";
				char filename_group[30] = "./QQ/source/qq_group_max.txt";
				long max_group = 0;
				ifstream filein_group(filename_group, ios::in);
				filein_group >> max_group;
				filein_group.close();
				int temp_qun = a.numberlimit(0, max_group, 0);
				q.qq_groupmanage.add_number(q.return_id(), temp_qun);
			}
			if (type1 == 4) {
				cout << endl;

				cout << "***************************************" << endl;
				cout << "****请输入群ID：" ;
				char filename_group[30] = "./QQ/source/qq_group_max.txt";
				long max_group = 0;
				ifstream filein_group(filename_group, ios::in);
				filein_group >> max_group;
				filein_group.close();
				int temp_qun = a.numberlimit(0, max_group, 0);
				q.qq_groupmanage.delete_number(q.return_id(), temp_qun);
			}
			if (type1 == 5) {
				cout << endl;

				cout << "***************************************" << endl;
				cout << "****请输入群ID：" ;
				char filename_group[30] = "./QQ/source/qq_group_max.txt";
				long max_group = 0;
				ifstream filein_group(filename_group, ios::in);
				filein_group >> max_group;
				filein_group.close();
				int temp_qun = a.numberlimit(0, max_group, 0);
				q.qq_groupmanage.search_number(q.return_id(), temp_qun);
			}
			if (type1 == 6) {
				cout << endl;

				cout << "***************************************" << endl;
				cout << "****请输入群ID：";
				char filename_group[30] = "./QQ/source/qq_group_max.txt";
				long max_group = 0;
				ifstream filein_group(filename_group, ios::in);
				filein_group >> max_group;
				filein_group.close();
				int temp_qun = a.numberlimit(0, max_group, 0);
				q.qq_groupmanage.watch_add(q.return_id(), temp_qun);
			}
			if (type1 == 7) {
				cout << endl;

				cout << "***************************************" << endl;
				cout << "****请输入群ID：" ;
				char filename_group[30] = "./QQ/source/qq_group_max.txt";
				long max_group = 0;
				ifstream filein_group(filename_group, ios::in);
				filein_group >> max_group;
				filein_group.close();
				int temp_qun = a.numberlimit(0, max_group, 0);
				q.qq_groupmanage.set(q.return_id(), temp_qun);
			}
			if (type1 == 1) {
				q.qq_groupmanage.apply_group(q.return_id());
			}
		}
		if (type_a == 3) {
			cout << endl;

			cout << "**********二级菜单**********" << endl;
			cout << "****    公共聊天请输入1 ****" << endl;
			cout << "****      私聊请输入2   ****" << endl;
			cout << "****    接收消息请输入3 ****" << endl;
			cout << "****************************" << endl;
			cout << "请输入";
			int temp_type_net = a.numberlimit(1, 3, 0);
			if (temp_type_net == 1) {
				//公共聊天
				cout << endl;

				cout << "****************************" << endl;
				cout << "****   发送消息请输入1  ****" << endl;
				cout << "****   发送文件请输入2  ****" << endl;
				cout << "****************************" << endl;
				cout << "请输入" << endl;
				int c = a.numberlimit(1, 2, 0);
				if (c == 1) {
					SndTxt();
				}
				if (c == 2) {
					SndFil();
				}
				
			}
			if(temp_type_net == 2) {
				//私聊
				cout << endl;

				cout << "***************************************" << endl;
				cout << "****请输入对方ID：";
				char filename_id[30] = "./QQ/source/qq_id_max.txt";
				long max_id = 0;
				ifstream filein_id(filename_id, ios::in);
				filein_id >> max_id;
				filein_id.close();
				int temp_id = a.numberlimit(0,max_id,0);
				if (q.qq_friendmanage.friendlist[id][temp_id] == 1 && q.qq_friendmanage.friendlist[temp_id][id] == 1) {
					cout << endl;

					cout << "****************************" << endl;
					cout << "****   发送消息请输入1  ****" << endl;
					cout << "****   发送文件请输入2  ****" << endl;
					cout << "****************************" << endl;
					cout << "请输入" ;
					int c = a.numberlimit(1, 2, 0);
					if (c == 1) {
						SndTxt();
					}
					if (c == 2) {
						SndFil();
					}
				}
				else {
					cout << endl;

					cout << "****************************" << endl;
					cout << "****  对方不是您的好友！****" << endl;
					cout << "****      发送失败！    ****" << endl;
					cout << "****************************" << endl;
					
				}
			}
			if (temp_type_net == 3) {
				WinExec("reserve.exe", SW_MAXIMIZE);
			}
		}
		if (type_a == 4) {
			if (q.connect_wechat = 1) {
				cout << endl;

				cout << "***********************************************" << endl;
				cout << "**** 您已关联微信；ID：" << q.connect_wechat_id << endl;
				cout << "***********************************************" << endl;
			}
			else {
				cout << endl;

				cout << "****************************" << endl;
				cout << "****    您未关联微信    ****" << endl;
				cout << "****************************" << endl;
				cout << "****    关联请输入1     ****" << endl;
				cout << "****    取消请输入2     ****" << endl;
				cout << "****************************" << endl;
				cout << "请输入：";
				int tempguanlian = a.numberlimit(1, 2, 0);
				if (tempguanlian == 1) {
					cout << endl;

					cout << "***************************************" << endl;
					cout << "****请输入微信 ID：" ;
					q.connect_wechat_id = a.numberlimit(0, 99999, 0);
					cout << "***************************************" << endl;
					cout << "****请输入微信 密码：" ;
					string temp;
					cin >> temp;
					cout << endl;

					cout << "****************************" << endl;
					cout << "****  您已成功关联微信！****" << endl;
					cout << "****************************" << endl;
				}
			}
			if (q.connect_weibo = 1) {
				cout << endl;

				cout << "***********************************************" << endl;
				cout << "**** 您已关联同名微博；ID：" << q.return_id() << endl;
				cout << "***********************************************" << endl;

			}
			else {
				cout << endl;

				cout << "****************************" << endl;
				cout << "****    您未关联微博    ****" << endl;
				cout << "****************************" << endl;
				cout << "****    关联请输入1     ****" << endl;
				cout << "****    取消请输入2     ****" << endl;
				cout << "****************************" << endl;
				cout << "请输入：";
				int tempguanlian = a.numberlimit(1, 2, 0);
				if (tempguanlian == 1) {
					cout << endl;

					cout << "****************************" << endl;
					cout << "****  您已成功关联微博！****" << endl;
					cout << "****  QQ信息已导入微博！****" << endl;
					cout << "****************************" << endl;
				}
			}
		}
		if (type_a == 5) {
			q.show_all();
		}
		cout << endl;
		cout << "****************************" << endl;
		cout << "****  返回菜单请输入1   ****" << endl;
		cout << "****  退出程序请输入2   ****" << endl;
		cout << "****************************" << endl;
		cout << "请输入：";
		panduan = a.numberlimit(0,1,0);
	}

}
long Application::creat_app() {
	Limit_JY a;
	cout << endl;

	cout << "*********注册账户*********" << endl;
	cout << "**** 注册QQ请输入1    ****" << endl;
	cout << "**** 注册Wechat请输入2****" << endl;
	cout << "**** 注册Weibo请输入3 ****" << endl;
	cout << "**************************" << endl;
	cout << "请输入";
	int type = a.numberlimit(1, 3, 0);
	if (type==1) {
		QQ_JY qq;
		return qq.return_id();
	}
	if (type==2) {
		QQ_JY wechat;
		return wechat.return_id();
	}
	if (type==3) {
		QQ_JY weibo;
		return weibo.return_id();
	}
}
#include "Application.h"
#include"Limit_JY.h"
#include"QQ_JY.h" 
#include"Network_JY.h"
#include<windows.h>

using namespace std;
InitSocket initSocket;//��ʼ��socket

void Application::login() {
	Limit_JY a;
	cout << endl;
	cout << "*********�˻�����*********" << endl;
	cout << "**** ��¼QQ������1    ****" << endl;
	cout << "**** ��¼Wechat������2****" << endl;
	cout << "**** ��¼Weibo������3 ****" << endl;
	cout << "**************************" << endl;
	cout << "������" ;
	int panduan = a.numberlimit(1,3,0);
	if (panduan == 1) {
		char filename_id[30] = "./QQ/source/qq_id_max.txt";
		long max_id = 0;
		ifstream filein_id(filename_id, ios::in);
		filein_id >> max_id;
		filein_id.close();
		//��ȡ�����ʺ����ֵ
		cout << endl;

		cout << "***************************************" << endl;
		cout << "****������QQ ID��" ;
		long temp_id = a.numberlimit(0,max_id,0);

		cout << "***************************************" << endl;
		cout << "****������QQ ���룺";
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
			//��½�ɹ�
			cout << endl;

			cout << "**********************************" << endl;
			cout << "*************QQ������*************" << endl;
			cout << "**********************************" << endl;
			if(temp_id==1)
			{
				cout << endl;
				cout << "**********************************" << endl;
				cout << "*ϵͳ�Ѽ�������˻��ѹ���ͬID΢��*" << endl;
				cout << "**********************************" << endl;
				cout << "****         ��¼������1      ****" << endl;
				cout << "****         �ܾ�������2      ****" << endl;
				cout << "**********************************" << endl;
				cout << "**********************************" << endl;
				cout << "������";
				int tttmp = a.numberlimit(1, 2, 0);
				if (tttmp == 1) {
					cout << endl;
					cout << "**********************************" << endl;
					cout << "************΢��������************" << endl;
					cout << "**********************************" << endl;
				}
			}
			if (con_weibo == 1) {
				cout << endl;
				cout << "**********************************" << endl;
				cout << "*ϵͳ�Ѽ�������˻��ѹ���ͬID΢��*" << endl;
				cout << "**********************************" << endl;
				cout << "****         ��¼������1      ****" << endl;
				cout << "****         �ܾ�������2      ****" << endl;
				cout << "**********************************" << endl;
				cout << "**********************************" << endl;
				cout << "������" ;
				int tttmp = a.numberlimit(1,2,0);
				if (tttmp == 1) {
					cout << endl;
					cout << "**********************************" << endl;
					cout << "************΢��������************" << endl;
					cout << "**********************************" << endl;
				}
			}
			if (con_wechat == 1) {
				cout << endl;

				cout << "**********************************" << endl;
				cout << "***ϵͳ�Ѽ�������˻��ѹ���΢��***" << endl;
				cout << "********΢��IDΪ" << con_wechat_id << endl;
				cout << "**********************************" << endl;
				cout << "****         ��¼������1      ****" << endl;
				cout << "****         �ܾ�������2      ****" << endl;
				cout << "**********************************" << endl;
				cout << "**********************************" << endl;
				cout << "������" ;
				int tttmp = a.numberlimit(1, 2, 0);
				if (tttmp == 1) {
					cout << endl;

					cout << "**********************************" << endl;
					cout << "************΢��������************" << endl;
					cout << "**********************************" << endl;
				}
			}
			menu_qq(temp_id);
		}
		else {
			//��½ʧ��
			cout << endl;

			cout << "**********************************" << endl;
			cout << "*******������󣡵�½ʧ�ܣ�*******" << endl;
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
		//��ȡ�����ʺ����ֵ
		cout << endl;

		cout << "***************************************" << endl;
		cout << "****������΢�� ID��";
		long temp_id = a.numberlimit(0, max_id, 0);

		cout << "***************************************" << endl;
		cout << "****������΢�� ���룺" ;
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
			//��½�ɹ�
			cout << endl;

			cout << "**********************************" << endl;
			cout << "************΢��������************" << endl;
			cout << "**********************************" << endl;
			if (con_weibo == 1&&con_wechat==1) {
				cout << endl;

				cout << "**********************************" << endl;
				cout << "***ϵͳ�Ѽ�������˻��ѹ���΢��***" << endl;
				cout << "********΢��IDΪ" << con_wechat_id << endl;
				cout << "**********************************" << endl;
				cout << "****         ��¼������1      ****" << endl;
				cout << "****         �ܾ�������2      ****" << endl;
				cout << "**********************************" << endl;
				cout << "**********************************" << endl;
				cout << "������";
				int tttmp = a.numberlimit(1, 2, 0);
				if (tttmp == 1) {
					cout << endl;

					cout << "**********************************" << endl;
					cout << "************΢��������************" << endl;
					cout << "**********************************" << endl;
				}
			}
			if (con_wechat == 1) {
				cout << endl;

				cout << "**********************************" << endl;
				cout << "***ϵͳ�Ѽ�������˻��ѹ���QQ*****" << endl;
				cout << "*********QQ IDΪ" << con_wechat_id << endl;
				cout << "**********************************" << endl;
				cout << "****         ��¼������1      ****" << endl;
				cout << "****         �ܾ�������2      ****" << endl;
				cout << "**********************************" << endl;
				cout << "**********************************" << endl;
				cout << "������";
				int tttmp = a.numberlimit(1, 2, 0);
				if (tttmp == 1) {
					cout << endl;

					cout << "**********************************" << endl;
					cout << "************QQ������************" << endl;
					cout << "**********************************" << endl;
				}
			}
			menu_qq(temp_id);
		}
		else {
			//��½ʧ��
			cout << endl;

			cout << "**********************************" << endl;
			cout << "*******������󣡵�½ʧ��********" << endl;
			cout << "**********************************" << endl;
			login();
		}
	}if (panduan == 3) {
		char filename_id[30] = "./QQ/source/qq_id_max.txt";
		long max_id = 0;
		ifstream filein_id(filename_id, ios::in);
		filein_id >> max_id;
		filein_id.close();
		//��ȡ�����ʺ����ֵ
		cout << endl;

		cout << "***************************************" << endl;
		cout << "****������΢�� ID��";
		long temp_id = a.numberlimit(0, max_id, 0);

		cout << "***************************************" << endl;
		cout << "****������΢�� ���룺" ;
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
			//��½�ɹ�
			cout << endl;

			cout << "**********************************" << endl;
			cout << "************΢��������************" << endl;
			cout << "**********************************" << endl;

			if (con_weibo == 1) {
				cout << endl;


				cout << "**********************************" << endl;
				cout << "**ϵͳ�Ѽ�������˻��ѹ���ͬ��QQ**" << endl;
				cout << "**********************************" << endl;
				cout << "****         ��¼������1      ****" << endl;
				cout << "****         �ܾ�������2      ****" << endl;
				cout << "**********************************" << endl;
				cout << "������" ;
				int tttmp = a.numberlimit(1, 2, 0);
				if (tttmp == 1) {
					cout << endl;

					cout << "**********************************" << endl;
					cout << "**************QQ������************" << endl;
					cout << "**********************************" << endl;
				}
			}
			if (con_wechat == 1) {
				cout << endl;

				cout << "**********************************" << endl;
				cout << "***ϵͳ�Ѽ�������˻��ѹ���΢��***" << endl;
				cout << "********΢��IDΪ" << con_wechat_id << endl;
				cout << "**********************************" << endl;
				cout << "****         ��¼������1      ****" << endl;
				cout << "****         �ܾ�������2      ****" << endl;
				cout << "**********************************" << endl;
				cout << "**********************************" << endl;
				cout << "������";
				int tttmp = a.numberlimit(1, 2, 0);
				if (tttmp == 1) {
					cout << endl;

					cout << "**********************************" << endl;
					cout << "************΢��������************" << endl;
					cout << "**********************************" << endl;
				}
			}
			menu_qq(temp_id);
		}
		else {
			//��½ʧ��
			cout << endl;

			cout << "**********************************" << endl;
			cout << "*******������󣡵�½ʧ��********" << endl;
			cout << "**********************************" << endl;
			login();
		}
	}

}
void Application::how_sign_in() {
	Limit_JY a;
	cout << endl;
	cout << "***********��***********" << endl;
	cout << "****    ��¼������0   ****" << endl;
	cout << "****    ע��������1   ****" << endl;
	cout << "**************************" << endl;
	cout << "������" ;
	int panduan = a.numberlimit(0,1,0);
	if (panduan == 0) {
		login();
	}
	if (panduan==1) {
		menu_qq(creat_app());
	}
}
//�����ʺŵ�¼
void Application::menu_qq(long id) {
	Limit_JY a;
	QQ_JY q(id);
	q.qq_friendmanage.read_friendlist();
	q.qq_groupmanage.read_grouplist();
	int panduan = 1;
	while (panduan) {
		panduan = 0;
		cout << endl;
		cout << "**********�˵�**********"<<endl;
		cout << "****���ѹ���������1 ****"<<endl;
		cout << "****Ⱥ����������2   ****" << endl;
		cout << "****����������3     ****" << endl;
		cout << "****�����˺�������4 ****" << endl;
		cout << "****�鿴��Ϣ������5 ****" << endl;
		cout << "************************" << endl;
		cout << "������" ;

		int type_a = a.numberlimit(1, 4, 0);
		if (type_a == 1) {
			cout << endl;

			cout << "***********�����˵�**************" << endl;
			cout << "****       ��Ӻ�������1     ****" << endl;
			cout << "****       ��ѯ������2       ****" << endl;
			cout << "****   �����������������3   ****" << endl;
			cout << "****���ҿ�����ʶ�ĺ���������4****" << endl;
			cout << "*********************************" << endl;
			cout << "������";
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
				cout << "**����΢�ź������΢��ID��201��QQ ID��3���û�Ϊ����" << endl;
				cout << "**********************************" << endl;
				cout << "************���������1***********" << endl;
				cout << "************�ܾ�������2***********" << endl;
				cout << "**********************************" << endl;
				cout << "�����룺";
				int temp_L_a = a.numberlimit(1,2,0);
				if (temp_L_a == 1) {
					cout << endl;

					cout << "**********************************" << endl;
					cout << "********����Է���������*********" << endl;
					cout << "**********************************" << endl;
				}else{
					cout << endl;

					cout << "**********************************" << endl;
					cout << "************��ȡ������************" << endl;
					cout << "**********************************" << endl;
				}
			}
		}
		if (type_a == 2) {
			cout << endl;

			cout << "**********�����˵�**********" << endl;
			cout << "****    ����Ⱥ������1   ****" << endl;
			cout << "****    ����Ⱥ������2   ****" << endl;
			cout << "****  ���Ⱥ��Ա������3 ****" << endl;
			cout << "****  ɾ��Ⱥ��Ա������4 ****" << endl;
			cout << "****  ��ѯȺ��Ա������5 ****" << endl;
			cout << "****   ��������������6  ****" << endl;
			cout << "****  ����Ⱥ��Ϣ������7 ****" << endl;
			cout << "****  ����������������8 ****" << endl;
			cout << "****************************" << endl;
			cout << "������" ;
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
				cout << "****������ȺID��";
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
				cout << "****������ȺID��" ;
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
				cout << "****������ȺID��" ;
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
				cout << "****������ȺID��";
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
				cout << "****������ȺID��" ;
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

			cout << "**********�����˵�**********" << endl;
			cout << "****    ��������������1 ****" << endl;
			cout << "****      ˽��������2   ****" << endl;
			cout << "****    ������Ϣ������3 ****" << endl;
			cout << "****************************" << endl;
			cout << "������";
			int temp_type_net = a.numberlimit(1, 3, 0);
			if (temp_type_net == 1) {
				//��������
				cout << endl;

				cout << "****************************" << endl;
				cout << "****   ������Ϣ������1  ****" << endl;
				cout << "****   �����ļ�������2  ****" << endl;
				cout << "****************************" << endl;
				cout << "������" << endl;
				int c = a.numberlimit(1, 2, 0);
				if (c == 1) {
					SndTxt();
				}
				if (c == 2) {
					SndFil();
				}
				
			}
			if(temp_type_net == 2) {
				//˽��
				cout << endl;

				cout << "***************************************" << endl;
				cout << "****������Է�ID��";
				char filename_id[30] = "./QQ/source/qq_id_max.txt";
				long max_id = 0;
				ifstream filein_id(filename_id, ios::in);
				filein_id >> max_id;
				filein_id.close();
				int temp_id = a.numberlimit(0,max_id,0);
				if (q.qq_friendmanage.friendlist[id][temp_id] == 1 && q.qq_friendmanage.friendlist[temp_id][id] == 1) {
					cout << endl;

					cout << "****************************" << endl;
					cout << "****   ������Ϣ������1  ****" << endl;
					cout << "****   �����ļ�������2  ****" << endl;
					cout << "****************************" << endl;
					cout << "������" ;
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
					cout << "****  �Է��������ĺ��ѣ�****" << endl;
					cout << "****      ����ʧ�ܣ�    ****" << endl;
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
				cout << "**** ���ѹ���΢�ţ�ID��" << q.connect_wechat_id << endl;
				cout << "***********************************************" << endl;
			}
			else {
				cout << endl;

				cout << "****************************" << endl;
				cout << "****    ��δ����΢��    ****" << endl;
				cout << "****************************" << endl;
				cout << "****    ����������1     ****" << endl;
				cout << "****    ȡ��������2     ****" << endl;
				cout << "****************************" << endl;
				cout << "�����룺";
				int tempguanlian = a.numberlimit(1, 2, 0);
				if (tempguanlian == 1) {
					cout << endl;

					cout << "***************************************" << endl;
					cout << "****������΢�� ID��" ;
					q.connect_wechat_id = a.numberlimit(0, 99999, 0);
					cout << "***************************************" << endl;
					cout << "****������΢�� ���룺" ;
					string temp;
					cin >> temp;
					cout << endl;

					cout << "****************************" << endl;
					cout << "****  ���ѳɹ�����΢�ţ�****" << endl;
					cout << "****************************" << endl;
				}
			}
			if (q.connect_weibo = 1) {
				cout << endl;

				cout << "***********************************************" << endl;
				cout << "**** ���ѹ���ͬ��΢����ID��" << q.return_id() << endl;
				cout << "***********************************************" << endl;

			}
			else {
				cout << endl;

				cout << "****************************" << endl;
				cout << "****    ��δ����΢��    ****" << endl;
				cout << "****************************" << endl;
				cout << "****    ����������1     ****" << endl;
				cout << "****    ȡ��������2     ****" << endl;
				cout << "****************************" << endl;
				cout << "�����룺";
				int tempguanlian = a.numberlimit(1, 2, 0);
				if (tempguanlian == 1) {
					cout << endl;

					cout << "****************************" << endl;
					cout << "****  ���ѳɹ�����΢����****" << endl;
					cout << "****  QQ��Ϣ�ѵ���΢����****" << endl;
					cout << "****************************" << endl;
				}
			}
		}
		if (type_a == 5) {
			q.show_all();
		}
		cout << endl;
		cout << "****************************" << endl;
		cout << "****  ���ز˵�������1   ****" << endl;
		cout << "****  �˳�����������2   ****" << endl;
		cout << "****************************" << endl;
		cout << "�����룺";
		panduan = a.numberlimit(0,1,0);
	}

}
long Application::creat_app() {
	Limit_JY a;
	cout << endl;

	cout << "*********ע���˻�*********" << endl;
	cout << "**** ע��QQ������1    ****" << endl;
	cout << "**** ע��Wechat������2****" << endl;
	cout << "**** ע��Weibo������3 ****" << endl;
	cout << "**************************" << endl;
	cout << "������";
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
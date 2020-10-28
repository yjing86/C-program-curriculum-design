#pragma once


#include <stdio.h>
#include <Winsock2.h>
#include <WS2tcpip.h>
#include <string>
#include<iostream>
using namespace std;
class InitSocket {
public:
	InitSocket() {
#pragma region ��ʼ��Socket
		WORD wVersionRequested;
		WSADATA wsaData;
		int err;
		//ʹ��macro
		wVersionRequested = MAKEWORD(2, 2);
		err = WSAStartup(wVersionRequested, &wsaData);
		if (err != 0) {
			//Winsock DLL.    

			cout << "**************************" << endl;
			cout << "****  ������������  ****" << endl;
			cout << "**************************" << endl;
			return;
		}
		//ȷ��winsock

		if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2) {
			//�޷��ҵ�winsock dll
			cout << "**************************" << endl;
			cout << "****  ������������  ****" << endl;
			cout << "**************************" << endl;
			WSACleanup();
			return;
		}
		else {
			cout << "**************************" << endl;
			cout << "****  �������ӳɹ�    ****" << endl;
			cout << "**************************" << endl;
		}


#pragma endregion
	}
	~InitSocket() {
		WSACleanup();
	}
};
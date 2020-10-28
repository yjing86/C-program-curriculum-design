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
#pragma region 初始化Socket
		WORD wVersionRequested;
		WSADATA wsaData;
		int err;
		//使用macro
		wVersionRequested = MAKEWORD(2, 2);
		err = WSAStartup(wVersionRequested, &wsaData);
		if (err != 0) {
			//Winsock DLL.    

			cout << "**************************" << endl;
			cout << "****  请检查网络连接  ****" << endl;
			cout << "**************************" << endl;
			return;
		}
		//确定winsock

		if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2) {
			//无法找到winsock dll
			cout << "**************************" << endl;
			cout << "****  请检查网络连接  ****" << endl;
			cout << "**************************" << endl;
			WSACleanup();
			return;
		}
		else {
			cout << "**************************" << endl;
			cout << "****  网络连接成功    ****" << endl;
			cout << "**************************" << endl;
		}


#pragma endregion
	}
	~InitSocket() {
		WSACleanup();
	}
};
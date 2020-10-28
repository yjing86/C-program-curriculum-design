#pragma once
#include <mutex>
#include <stdio.h>
#include <Winsock2.h>
#include <WS2tcpip.h>
#include <windows.h>
#include <string>
#include<iostream>
class InitSocket {
public:
	InitSocket() {
#pragma region ≥ı ºªØSocket
		WORD wVersionRequested;
		WSADATA wsaData;
		int err;
		wVersionRequested = MAKEWORD(2, 2);
		err = WSAStartup(wVersionRequested, &wsaData);
		if (err != 0) {
			printf("WSAStartup failed with error: %d\n", err);
			return;
		}
		if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2) {
			printf("Could not find a usable version of Winsock.dll\n");
			WSACleanup();
			return;
		}
		else
			printf("The Winsock 2.2 dll was found okay\n");
#pragma endregion
	}
	~InitSocket() {
		WSACleanup();
	}
};
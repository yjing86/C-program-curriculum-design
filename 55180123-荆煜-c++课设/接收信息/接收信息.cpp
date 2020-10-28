// 接收信息.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <stdio.h>
#include <Winsock2.h>
#include <WS2tcpip.h>
#include <string>
#include<iostream>
#include"Network_resive_JY.h"
#pragma comment(lib,"ws2_32.lib")

DWORD WINAPI AcpThdProc(LPVOID lpparam);
DWORD WINAPI RevThdProc(LPVOID lpparam);
bool InitSevSock();
struct Head {
#define TYPE_SEND_TEXT 1
#define TYPE_SEND_FILE 2
	int type;//传输类型
	unsigned int len;//传输数据的大小
};

struct FileInfo {
	char name[100];
	unsigned int fileLen;//文件大小
};

void main() {
	system("color F0");

	InitSocket initSocket;//初始化socket
	InitSevSock();

	system("pause");
}

bool InitSevSock()
{
	SOCKET server = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);//服务器套接字  
	if (INVALID_SOCKET == server)
	{

		cout << "**************************" << endl;
		cout << "****  请检查网络连接  ****" << endl;
		cout << "**************************" << endl;
		return  false;
	}
	SOCKADDR_IN     addrServ;;      //服务器地址  
									//服务器套接字地址   
	addrServ.sin_family = AF_INET;
	addrServ.sin_port = htons(4999);
	addrServ.sin_addr.s_addr = INADDR_ANY;
	//绑定套接字  
	int retVal = bind(server, (LPSOCKADDR)&addrServ, sizeof(SOCKADDR_IN));
	if (SOCKET_ERROR == retVal)
	{

		cout << "**************************" << endl;
		cout << "****  请检查网络连接  ****" << endl;
		cout << "**************************" << endl;
		closesocket(server);   //关闭套接字  
		return false;
	}
	//开始监听   
	retVal = listen(server, 100);
	if (SOCKET_ERROR == retVal)
	{

		cout << "**************************" << endl;
		cout << "****  请检查网络连接  ****" << endl;
		cout << "**************************" << endl;
		closesocket(server);   //关闭套接字  
		return false;
	}
	//接受客户端连接
	CreateThread(NULL, 0, AcpThdProc, (LPVOID)server, 0, NULL);

	//cout << "**************************" << endl;
	//cout << "****  网络连接成功    ****" << endl;
	//cout << "**************************" << endl;
	return true;
}

DWORD WINAPI AcpThdProc(LPVOID lpparam)
{
	//传来的服务端套接字
	SOCKET  server = (SOCKET)lpparam;
	SOCKADDR_IN addrClient;
	int len = sizeof(addrClient);
	while (true) {
		cout << endl;
		cout << "********************消息********************" << endl;
		SOCKET handler = accept(server, (LPSOCKADDR)&addrClient, &len);
		if (INVALID_SOCKET == handler)
		{

			cout << "**************************" << endl;
			cout << "****  请检查网络连接  ****" << endl;
			cout << "**************************" << endl;
			closesocket(server);   //关闭套接字  
			return -1;
		}
		char addr[20];
		inet_ntop(AF_INET, &addrClient.sin_addr, addr, 20);
		printf("**%s 已连接 .", addr);
		//接收客户端发来的数据
		CreateThread(NULL, 0, RevThdProc, (LPVOID)handler, 0, NULL);
	}
	//closesocket(server);
	return 0;
}

DWORD WINAPI RevThdProc(LPVOID lpparam)
{
#define BUFFER_SIZE 1024
	//传来的连接套接字
	SOCKET  handler = (SOCKET)lpparam;
	Head head;
	int byteRecv;
	byteRecv = recv(handler, (char*)&head, sizeof(head), 0);
	if (byteRecv == SOCKET_ERROR) {

		cout << "**************************" << endl;
		printf("**连接失败;错误码 %d", WSAGetLastError());
		closesocket(handler);
		return -1;
	}
	char buffer[BUFFER_SIZE];
	ZeroMemory(buffer, BUFFER_SIZE);//相当于	memset
	int byteRead = 0;

	switch (head.type)
	{
	case TYPE_SEND_TEXT:
	{

		cout << "**************************" << endl;
		cout << "******   接收文本   ******" << endl;
		cout << "**************************" << endl;
		std::string strRecv;
		//接收到数据
		while (head.len - byteRead > 0 && (byteRecv = recv(handler, buffer, head.len - byteRead < BUFFER_SIZE ? head.len - byteRead : BUFFER_SIZE, 0)) > 0) {
			byteRead += byteRecv;
			strRecv.append(buffer);
			ZeroMemory(buffer, BUFFER_SIZE);
		}
		if (byteRecv == SOCKET_ERROR) {
			printf("**接收失败;错误码 %d", WSAGetLastError());
			closesocket(handler);
			return -1;
		}
		printf("**收到的数据为：\n%s\n", strRecv.c_str());
	}
	break;
	case TYPE_SEND_FILE:
	{

		cout << "**************************" << endl;
		cout << "******   接收文件   ******" << endl;
		cout << "**************************" << endl;
		//接收文件信息
		FileInfo fileInfo;
		while (byteRead != sizeof(fileInfo)) {
			byteRecv = recv(handler, (char*)&fileInfo, sizeof(fileInfo) - byteRead, 0);
			if (byteRecv == SOCKET_ERROR) {
				printf("**接收失败;错误码 %d", WSAGetLastError());
				closesocket(handler);
				return -1;
			}
			byteRead += byteRecv;
		}
		printf("**收到的文件名为：%s,文件大小为：%d Byte\n", fileInfo.name, fileInfo.fileLen);
		//如果目标文件已存在，则在其文件名后+ （i）
		FILE* pRecvFile = NULL;
		int i = 0;
		std::string fileName = fileInfo.name;
		char* p = strrchr(fileInfo.name, '.');
		while (!fopen_s(&pRecvFile, fileName.c_str(), "r")) {
			fclose(pRecvFile);
			i++; fileName = "";
			fileName.append(fileInfo.name, p)
				.append("(")
				.append(std::to_string(i))
				.append(")").append(p);
		}
		//以二进制写的方式打开二进制文件
		int retVal = fopen_s(&pRecvFile, fileName.c_str(), "wb");
		if (retVal != 0) {
			printf("**写文件时打开文件失败，文件名为：%s\n", fileName.c_str());
			fclose(pRecvFile);
			closesocket(handler);
			return -1;
		}
		while (head.len - byteRead > 0 && (byteRecv = recv(handler, buffer, head.len - byteRead < BUFFER_SIZE ? head.len - byteRead : BUFFER_SIZE, 0)) > 0) {
			byteRead += byteRecv;
			//将接收到的数据写入文件
			if (fwrite(buffer, sizeof(char), byteRecv, pRecvFile) != byteRecv) {
				printf("**写入文件错误，文件名为：%s\n", fileName.c_str());
				fclose(pRecvFile);
				closesocket(handler);
				return -1;
			}
			printf("**传输进度：%lf\n", (double)byteRead / head.len);
			ZeroMemory(buffer, BUFFER_SIZE);
		}
		fclose(pRecvFile);//关闭写入的文件  切记不要忘了这步
		if (byteRecv == SOCKET_ERROR) {
			printf("**接收失败;错误码 %d", WSAGetLastError());
			closesocket(handler);
			return -1;
		}
		printf("**文件写入成功！文件名为%s\n", fileName.c_str());
	}
	break;
	default:
		break;
	}

	char sendBuffer[] = "接收成功\n";
	send(handler, sendBuffer, strlen(sendBuffer) + 1, 0);//给客户端返回消息
	closesocket(handler);
	return 0;
}


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

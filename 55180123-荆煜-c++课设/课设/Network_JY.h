#pragma once
#define BUFFER_SIZE 1024
#pragma comment(lib,"ws2_32.lib")
#include <mutex>
#include <stdio.h>
#include <Winsock2.h>
#include <WS2tcpip.h>
#include <windows.h>
#include <string>
#include<iostream>
using namespace std;
class InitSocket {
public:
	InitSocket() {
		//初始化Socket
		WORD wVersionRequested;
		WSADATA wsaData;
		int err;
		wVersionRequested = MAKEWORD(2, 2);
		err = WSAStartup(wVersionRequested, &wsaData);
		if (err != 0) {
			cout << "**************************" << endl;
			cout << "****  请检查网络连接  ****" << endl;
			cout << "**************************" << endl;
			return;
		}
		if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2) {
			//找不到winsock dll
			cout << "**************************" << endl;
			cout << "****  请检查网络连接  ****" << endl;
			cout << "**************************" << endl;
			WSACleanup();
			return;
		}
		else
			printf("*************************欢迎使用荆煜的多功能聊天程序*************************\n");
	}
	~InitSocket() {
		WSACleanup();
	}
};
bool SndTxt(const char* text);
bool SndFil(const char* fileName);
std::string RevTxt(SOCKET sock);
bool RevFil(SOCKET sock);
void SndTxt();
void SndFil();

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
bool SndTxt(const char* text)
{
	Head head;
	SOCKET server;
	u_long lService;
	sockaddr_in addrServer;
	char buffer[BUFFER_SIZE];
	ZeroMemory(buffer, BUFFER_SIZE);
	head.type = 1;
	head.len = strlen(text) + 1;
	server = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	inet_pton(AF_INET, "127.0.0.1", &lService);
	addrServer.sin_family = AF_INET;

	addrServer.sin_addr.s_addr = lService;
	addrServer.sin_port = htons(4999);

	int retVal = connect(server, (sockaddr*)&addrServer, sizeof(addrServer));
	if (SOCKET_ERROR == retVal) {
		std::cout << "connect failed!" << std::endl;
		closesocket(server); 
		//关闭套接字  
		return false;
	}
	cout << "**************************" << endl;
	cout << "****    网络连接成功  ****" << endl;
	cout << "**************************" << endl;
	retVal = send(server, (char*)&head, sizeof(head), 0);
	//发送文本数据头
	if (retVal <= 0) {
		cout << "**************************" << endl;
		cout << "****     发送失败！   ****" << endl;
		cout << "****  请检查网络连接  ****" << endl;
		cout << "**************************" << endl;
		closesocket(server);
		return false;
	}
	retVal = send(server, text, strlen(text) + 1, 0);
	//发送文本数据
	if (retVal <= 0) {

		cout << "**************************" << endl;
		cout << "****     发送失败！   ****" << endl;
		cout << "****  请检查网络连接  ****" << endl;
		cout << "**************************" << endl;
		closesocket(server);
		return false;
	}
	retVal = recv(server, buffer, BUFFER_SIZE, 0);
	if (retVal <= 0) {

		cout << "**************************" << endl;
		cout << "****     接收失败！   ****" << endl;
		cout << "****  请检查网络连接  ****" << endl;
		cout << "**************************" << endl;
		closesocket(server);
		return false;
	}
	closesocket(server);
	printf(buffer);
	return true;
}
bool SndFil(const char* fileName)
{
	Head head;
	FileInfo fileInfo;
	FILE* fileSend = NULL;
	SOCKET server;
	u_long lService;
	sockaddr_in addrServer;
	char buffer[BUFFER_SIZE];
	ZeroMemory(buffer, BUFFER_SIZE);
	head.type = 2;
	strcpy_s(fileInfo.name, strrchr(fileName, '\\') + 1);
	if (fopen_s(&fileSend, fileName, "rb")) {


		cout << "**************************" << endl;

		cout << "****请输入文件名" << fileName ;
		return false;
	}
	//获取文件大小以及文件头的发送数据区的大小
	fseek(fileSend, 0L, SEEK_END);
	long size = ftell(fileSend);
	if (size <= 0) {

		cout << "**************************" << endl;
		cout << "****   文件读取失败！ ****" << endl;
		cout << "**************************" << endl;
		fclose(fileSend);
		return false;
	}
	fileInfo.fileLen = static_cast<unsigned int>(size);
	head.len = sizeof(fileInfo) + fileInfo.fileLen;
	//将光标移动到文件头
	fseek(fileSend, 0L, SEEK_SET);

	server = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	inet_pton(AF_INET, "127.0.0.1", &lService);
	addrServer.sin_family = AF_INET;
	addrServer.sin_addr.s_addr = lService;
	addrServer.sin_port = htons(4999);
	int retVal = connect(server, (sockaddr*)&addrServer, sizeof(addrServer));
	if (SOCKET_ERROR == retVal) {

		cout << "**************************" << endl;
		cout << "****     连接失败！   ****" << endl;
		cout << "****  请检查网络连接  ****" << endl;
		cout << "**************************" << endl;
		closesocket(server); //关闭套接字  
		return false;
	}

	cout << "**************************" << endl;
	cout << "****     连接成功！   ****" << endl;
	cout << "**************************" << endl;
	retVal = send(server, (char*)&head, sizeof(head), 0);//发送文件数据头
	if (retVal <= 0) {

		cout << "**************************" << endl;
		cout << "****     发送失败！   ****" << endl;
		cout << "****  请检查网络连接  ****" << endl;
		cout << "**************************" << endl;
		closesocket(server);
		return false;
	}
	retVal = send(server, (char*)&fileInfo, sizeof(fileInfo), 0);//发送文件信息
	if (retVal <= 0) {

		cout << "**************************" << endl;
		cout << "****     发送失败！   ****" << endl;
		cout << "****  请检查网络连接  ****" << endl;
		cout << "**************************" << endl;
		closesocket(server);
		return false;
	}
	//发送文件
	int nCount;
	while ((nCount = fread(buffer, 1, BUFFER_SIZE, fileSend)) > 0) {
		send(server, buffer, nCount, 0);
		ZeroMemory(buffer, BUFFER_SIZE);
	}
	fclose(fileSend);

	retVal = recv(server, buffer, BUFFER_SIZE, 0);
	if (retVal <= 0) {

		cout << "**************************" << endl;
		cout << "****     接收失败！   ****" << endl;
		cout << "****  请检查网络连接  ****" << endl;
		cout << "**************************" << endl;
		closesocket(server);
		return false;
	}
	printf(buffer);
	closesocket(server);
	return true;
}
std::string RevTxt(SOCKET sock)
{
	return std::string();
}
bool RevFil(SOCKET sock)
{
	return false;
}
void SndTxt()
{
	char buffer[BUFFER_SIZE];

	cout << "**************************" << endl;
	cout << "**请输入文本:" ;
	std::cin >> buffer;
	SndTxt(buffer);
}
void SndFil()
{
	char szBuffer[MAX_PATH] = { 0 };
	OPENFILENAMEA file = { 0 };
	file.hwndOwner = NULL;
	file.lStructSize = sizeof(file);
	file.lpstrFilter = "所有文件(*.*)\0*.*\0";//要选择的文件后缀 
	file.lpstrInitialDir = "C:\\";//默认的文件路径 
	file.lpstrFile = szBuffer;//存放文件的缓冲区 
	file.nMaxFile = sizeof(szBuffer) / sizeof(*szBuffer);
	file.nFilterIndex = 0;
	file.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_EXPLORER;//标志如果是多选要加上OFN_ALLOWMULTISELECT
	BOOL bSel = GetOpenFileNameA(&file);
	std::cout << file.lpstrFile << std::endl;
	SndFil(file.lpstrFile);
}
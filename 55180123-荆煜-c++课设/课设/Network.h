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
class InitSocket {
public:
	InitSocket() {
		//��ʼ��Socket
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
	int type;//��������
	unsigned int len;//�������ݵĴ�С
};
struct FileInfo {
	char name[100];
	unsigned int fileLen;//�ļ���С
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
	/*((CIPAddressCtrl*)GetDlgItem(IDC_IPADDRESS_IP))->GetAddress(dwIP);*/
	//addrServer.sin_addr.s_addr = htonl(dwIP);
	int retVal = connect(server, (sockaddr*)&addrServer, sizeof(addrServer));
	if (SOCKET_ERROR == retVal) {
		std::cout << "connect failed!" << std::endl;
		closesocket(server); //�ر��׽���  
		return false;
	}
	std::cout << "connect success...\n" << std::endl;
	retVal = send(server, (char*)&head, sizeof(head), 0);//�����ı�����ͷ
	if (retVal <= 0) {
		std::cout << "send text failed!" << std::endl;
		closesocket(server);
		return false;
	}
	retVal = send(server, text, strlen(text) + 1, 0);//�����ı�����
	if (retVal <= 0) {
		std::cout << "send text failed!" << std::endl;
		closesocket(server);
		return false;
	}
	retVal = recv(server, buffer, BUFFER_SIZE, 0);
	if (retVal <= 0) {
		std::cout << "receive failed!" << std::endl;
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
		std::cout << "open file failed,fileName is " << fileName << std::endl;
		return false;
	}
	//��ȡ�ļ���С�Լ��ļ�ͷ�ķ����������Ĵ�С
	fseek(fileSend, 0L, SEEK_END);
	long size = ftell(fileSend);
	if (size <= 0) {
		std::cout << "get file length failed" << std::endl;
		fclose(fileSend);
		return false;
	}
	fileInfo.fileLen = static_cast<unsigned int>(size);
	head.len = sizeof(fileInfo) + fileInfo.fileLen;
	//������ƶ����ļ�ͷ
	fseek(fileSend, 0L, SEEK_SET);

	server = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	inet_pton(AF_INET, "127.0.0.1", &lService);
	addrServer.sin_family = AF_INET;
	addrServer.sin_addr.s_addr = lService;
	addrServer.sin_port = htons(4999);
	int retVal = connect(server, (sockaddr*)&addrServer, sizeof(addrServer));
	if (SOCKET_ERROR == retVal) {
		std::cout << "connect failed!" << std::endl;
		closesocket(server); //�ر��׽���  
		return false;
	}
	std::cout << "connect success...\n" << std::endl;
	retVal = send(server, (char*)&head, sizeof(head), 0);//�����ļ�����ͷ
	if (retVal <= 0) {
		std::cout << "send text failed!" << std::endl;
		closesocket(server);
		return false;
	}
	retVal = send(server, (char*)&fileInfo, sizeof(fileInfo), 0);//�����ļ���Ϣ
	if (retVal <= 0) {
		std::cout << "send text failed!" << std::endl;
		closesocket(server);
		return false;
	}
	//�����ļ�
	int nCount;
	while ((nCount = fread(buffer, 1, BUFFER_SIZE, fileSend)) > 0) {
		send(server, buffer, nCount, 0);
		ZeroMemory(buffer, BUFFER_SIZE);
	}
	fclose(fileSend);

	retVal = recv(server, buffer, BUFFER_SIZE, 0);
	if (retVal <= 0) {
		std::cout << "receive failed!" << std::endl;
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
	std::cout << "please input text to send\n" << std::endl;
	std::cin >> buffer;
	SndTxt(buffer);
}
void SndFil()
{
	char szBuffer[MAX_PATH] = { 0 };
	OPENFILENAMEA file = { 0 };
	file.hwndOwner = NULL;
	file.lStructSize = sizeof(file);
	file.lpstrFilter = "�����ļ�(*.*)\0*.*\0";//Ҫѡ����ļ���׺ 
	file.lpstrInitialDir = "C:\\";//Ĭ�ϵ��ļ�·�� 
	file.lpstrFile = szBuffer;//����ļ��Ļ����� 
	file.nMaxFile = sizeof(szBuffer) / sizeof(*szBuffer);
	file.nFilterIndex = 0;
	file.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_EXPLORER;//��־����Ƕ�ѡҪ����OFN_ALLOWMULTISELECT
	BOOL bSel = GetOpenFileNameA(&file);
	std::cout << file.lpstrFile << std::endl;
	SndFil(file.lpstrFile);
}

#include "stdafx.h"
#include "InitSocket.h"
#pragma comment(lib,"ws2_32.lib")
/*
2017-10-09
����������⣺
1.���ͷ�û��ѡ��IP
2.����һ�μ��Ͽ�����
3.û��ʵ�ֶ��߳��ļ�����
.....
*/

DWORD WINAPI AcpThdProc(LPVOID lpparam);
DWORD WINAPI RevThdProc(LPVOID lpparam);
bool InitSevSock();
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

void main() {
	InitSocket initSocket;//��ʼ��socket
	InitSevSock();

	system("pause");
}

bool InitSevSock()
{
	SOCKET server = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);//�������׽���  
	if (INVALID_SOCKET == server)
	{
		printf("socket failed!");
		return  false;
	}
	SOCKADDR_IN     addrServ;;      //��������ַ  
									//�������׽��ֵ�ַ   
	addrServ.sin_family = AF_INET;
	addrServ.sin_port = htons(4999);
	addrServ.sin_addr.s_addr = INADDR_ANY;
	//���׽���  
	int retVal = bind(server, (LPSOCKADDR)&addrServ, sizeof(SOCKADDR_IN));
	if (SOCKET_ERROR == retVal)
	{
		printf("bind failed!");
		closesocket(server);   //�ر��׽���  
		return false;
	}
	//��ʼ����   
	retVal = listen(server, 100);
	if (SOCKET_ERROR == retVal)
	{
		printf("listen failed!");
		closesocket(server);   //�ر��׽���  
		return false;
	}
	//���ܿͻ�������
	CreateThread(NULL, 0, AcpThdProc, (LPVOID)server, 0, NULL);
	printf("��ʼ�������socket�ɹ�!\n");
	return true;
}

DWORD WINAPI AcpThdProc(LPVOID lpparam)
{
	//�����ķ�����׽���
	SOCKET  server = (SOCKET)lpparam;
	SOCKADDR_IN addrClient;
	int len = sizeof(addrClient);
	while (true) {
		printf("Waiting for a connection...");
		SOCKET handler = accept(server, (LPSOCKADDR)&addrClient, &len);
		if (INVALID_SOCKET == handler)
		{
			printf("accept failed!");
			closesocket(server);   //�ر��׽���  
			return -1;
		}
		char addr[20];
		inet_ntop(AF_INET, &addrClient.sin_addr, addr, 20);
		printf("%s connected .", addr);
		//���տͻ��˷���������
		CreateThread(NULL, 0, RevThdProc, (LPVOID)handler, 0, NULL);
	}
	//closesocket(server);
	return 0;
}

DWORD WINAPI RevThdProc(LPVOID lpparam)
{
#define BUFFER_SIZE 1024
	//�����������׽���
	SOCKET  handler = (SOCKET)lpparam;
	Head head;
	int byteRecv;
	byteRecv = recv(handler, (char*)&head, sizeof(head), 0);
	if (byteRecv == SOCKET_ERROR) {
		printf("received head failed, error code is %d", WSAGetLastError());
		closesocket(handler);
		return -1;
	}
	char buffer[BUFFER_SIZE];
	ZeroMemory(buffer, BUFFER_SIZE);//�൱��	memset
	int byteRead = 0;

	switch (head.type)
	{
	case TYPE_SEND_TEXT:
	{
		printf("��������ı�����\n");
		std::string strRecv;
		//���յ�����
		while (head.len - byteRead>0 && (byteRecv = recv(handler, buffer, head.len - byteRead < BUFFER_SIZE ? head.len - byteRead : BUFFER_SIZE, 0)) > 0) {
			byteRead += byteRecv;
			strRecv.append(buffer);
			ZeroMemory(buffer, BUFFER_SIZE);
		}
		if (byteRecv == SOCKET_ERROR) {
			printf("received data failed, error code is %d", WSAGetLastError());
			closesocket(handler);
			return -1;
		}
		printf("�յ�������Ϊ��\n%s\n", strRecv.c_str());
	}
	break;
	case TYPE_SEND_FILE:
	{
		printf("��������ļ�����\n");
		//�����ļ���Ϣ
		FileInfo fileInfo;
		while (byteRead != sizeof(fileInfo)) {
			byteRecv = recv(handler, (char*)&fileInfo, sizeof(fileInfo) - byteRead, 0);
			if (byteRecv == SOCKET_ERROR) {
				printf("received fileInfo failed, error code is %d", WSAGetLastError());
				closesocket(handler);
				return -1;
			}
			byteRead += byteRecv;
		}
		printf("�յ����ļ���Ϊ��%s,�ļ���СΪ��%d Byte\n", fileInfo.name, fileInfo.fileLen);
		//���Ŀ���ļ��Ѵ��ڣ��������ļ�����+ ��i��
		FILE * pRecvFile = NULL;
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
		//�Զ�����д�ķ�ʽ�򿪶������ļ�
		int retVal = fopen_s(&pRecvFile, fileName.c_str(), "wb");
		if (retVal != 0) {
			printf("д�ļ�ʱ���ļ�ʧ�ܣ��ļ���Ϊ��%s\n", fileName.c_str());
			fclose(pRecvFile);
			closesocket(handler);
			return -1;
		}
		while (head.len - byteRead > 0 && (byteRecv = recv(handler, buffer, head.len - byteRead < BUFFER_SIZE ? head.len - byteRead : BUFFER_SIZE, 0)) > 0) {
			byteRead += byteRecv;
			//�����յ�������д���ļ�
			if (fwrite(buffer, sizeof(char), byteRecv, pRecvFile) != byteRecv) {
				printf("д���ļ������ļ���Ϊ��%s\n", fileName.c_str());
				fclose(pRecvFile);
				closesocket(handler);
				return -1;
			}
			printf("������ȣ�%lf\n", (double)byteRead / head.len);
			ZeroMemory(buffer, BUFFER_SIZE);
		}
		fclose(pRecvFile);//�ر�д����ļ�  �мǲ�Ҫ�����ⲽ
		if (byteRecv == SOCKET_ERROR) {
			printf("received data failed, error code is %d", WSAGetLastError());
			closesocket(handler);
			return -1;
		}
		printf("�ļ�д��ɹ����ļ���Ϊ%s\n", fileName.c_str());
	}
	break;
	default:
		break;
	}

	char sendBuffer[] = "���ճɹ�\n";
	send(handler, sendBuffer, strlen(sendBuffer) + 1, 0);//���ͻ��˷�����Ϣ
	closesocket(handler);
	return 0;
}
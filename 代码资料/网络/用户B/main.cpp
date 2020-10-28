//#include "stdafx.h"
#include "networkJY.h"

void main() {
	InitSocket initSocket;//≥ı ºªØsocket
	char c;
	while (1) {
		//std::cout << "please input ip to send" << std::endl;
		//std::cin >> ip;
		std::cout << "please choose what to send (1 text,2 file,q quit)" << std::endl;
		std::cin >> c;
		switch (c)
		{
		case '1':
			SndTxt();
			break;
		case '2':
			SndFil();
			break;
		case 'q':
			return;
		default:
			break;
		}
	}
}

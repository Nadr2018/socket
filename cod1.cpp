#include <iostream>
#include <WS2tcpip.h>

#pragma comment (lib, "ws2_32.lib")

int main() { 

	WSADATA wsData;
	WORD ver = MAKEWORD(2, 2);

	int wsOK = WSAStartup(ver, &wsData);

	if (wsOK != 0) {
		std::cout << "Error1\n";
		return;
	}
	SOKET listening = soket(AF_INET, SOCK_STREAM, 0);
	if (listening == INVALID_SOCKET) {
		std::cout << "Error2\n";
		return;
	}

	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(54000);
	hint.sin_addr.S_un.S_addr = INADR_ANY;

	bind(listening, (sockaddr*)&hint, sizeof(hint));
	listen(listening, SOMAXCONN);

	sockaddr_in client;
	int clientSize = sizeof(client);

	SOCKET clientSocket = accept(liestining, (sock_addr*)&client, &clientSize);

	char host[NI_MAXHOST];
	char service[NI_MAXHOST];

	ZeroMemory(host, NI_MAXHOST);
	ZeroMemory(service, NI_MAXHOST);


	if (getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOTS, service, NI_MAXSERV) == 0) {
		std::cout << host << " conected on port" << std::endl;
	}
	else
	{
		inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
		std::cout<<host<<"conected on port" << std::endl;
		ntons(client.sin_port) << std::endl;
	}

	closesocket(listening);

	return 0;
}
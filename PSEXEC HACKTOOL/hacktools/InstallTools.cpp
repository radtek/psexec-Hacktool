#include "pch.h"
#include "ChangeColor.h"
#include "InstallTools.h"
void getPstools();
#include <Windows.h>
#include <iostream>
#include <string>
using namespace std;

void CheckForTool() {

	string autoDownload;
	// check if the user has psexec installed
	system("start C:\\windows\\system32\\psexec.exe");
	system("cls");
	std::cout << "\n\n\n\n";
	color('Y');
	std::cout << "          OH! did an error just accure?\n";
	std::cout << "          if the screen above says something like: \n\n\n";
	color('G');
	std::cout << "          The system cannot find the file C:\\windows\\system32\\psexec.exe.\n\n\n";
	color('Y');
	std::cout << "          you can either download the required tools manually, or i can do it for you.\n";
	std::cout << "          if you want me to auto-download it for you, type ";
	color('C');
	std::cout << "yes and press ENTER.";
	color('Y');
	std::cout << " or type ";
	color('C');
	std::cout << "NO and press ENTER\n";
	color('Y');
	std::cout << "          OR! if you already have PSTOOLS installed or i have already downloaded it for you, say ";
	color('G');
	std::cout << "HaveIt\n\n\n";
	std::cout << "          ";
	color('R');
	cin >> autoDownload;
	if (autoDownload == "yes" || autoDownload == "y" || autoDownload == "YES" || autoDownload == "Y") {
		color('C');
		getPstools();
	}
	else if (autoDownload == "HaveIt" || autoDownload == "haveit" || autoDownload == "ihaveit") {
		return;
	}
	else if (autoDownload == "N" || autoDownload == "n" || autoDownload == "no" || autoDownload == "NO") {
		color('Y');
		std::cout << "OK. then please go to:\n";
		color('C');
		std::cout << "\n\n";
		std::cout << "          https://docs.microsoft.com/en-us/sysinternals/downloads/pstools \n\n";
		color('Y');
		std::cout << "          and download PsTools.\n";
		std::cout << "          Then, move ALL of the files in the .ZIP folder to C:\\windows\\system32 \n";
		std::cout << "          Have you done that? GREAT! now you can proceed.\n\n\n\n\n\n\n\n\n\n";
		system("pause >nul");
		system("pause >nul");
		return;
		//main();
	}
	else {
		return;
	}
}

void getPstools() {
	system("cd C:\\windows\\system32 && curl https://download.sysinternals.com/files/PSTools.zip > pstools.zip && tar -xf pstools.zip");
	std::cout << "\n\n";
	color('Y');
	std::cout << "             I am done downloading and installing. i will now redirect you.\n\n\n\n";
	system("pause >nul");
	return;
}

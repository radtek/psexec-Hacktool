#include "pch.h"
#include "ChangeColor.h"
#include <Windows.h>

void color(char colorchar) {
	switch (colorchar) {
	case 'B':
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
		break;
	case 'b':
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
		break;

	case 'y':
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		break;
	case 'Y':
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		break;

	case 'c':
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		break;
	case 'C':
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11); //bright cyan
		break;

	case 'r':
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		break;
	case 'R':
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		break;

	case 'p':
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
		break;
	case 'P':
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		break;

	case 'g':
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		break;
	case 'G': // bright green
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		break;

	case 'w':
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		break;
	case 'W':
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		break;

	case 'l':
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
		break;
	}
}
#include "Chat.h"
#include<iostream>
#include<string>

using namespace std;

int main()
{
	Chat onChat;
	string outChat;
	int act;
	do
	{
		onChat.chat();
		cin >> act;
		cout << "\t\t\t\t";
		cout << act << " - is your choise: " << endl;
		switch (act)
		{
		case 1:
			onChat.logInAccount();
			break;
		case 2:
			onChat.addNewUser();
			break;
		default:
			cout << "\n\t\t\t\t" << "Good bye!!!" << endl;
		}
		cout << "\n\t\t\t\tPress any button to continue\n\t\t\t\t3 - Exit;" << endl;
		cout << "\t\t\t\t";
		cin >> outChat;
	} while (outChat != "3");
	cout << "\n\t\t\t\t" << "Exit";
	return 0;
};

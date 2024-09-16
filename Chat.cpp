#include "Chat.h"
#include "User.h"
#include "Message.h"
#include <vector>

void Chat::chat() // Main class with general output
{
	cout << "\t\t\t\t\===============Welcome to Chat=================== " << endl;
	cout << "\t\t\t\tChoose your action:\t\t\t\t" << endl;
	cout << "\t\t\t\t1 - Log in\n\t\t\t\t2 - Registration\n\t\t\t\t3 - Exit;\n\t\t\t\t";
}

void Chat::addNewUser() // This is class for creating new user.
{
	string name;
	string logIn;
	string password;
	char c;
	// It is possible to create several account. This block of code using a cycle function.
	do
	{
		cout << "\n\t\t\t\tPlease enter user name to create account: ";
		cin >> name;
		cout << "\n\t\t\t\tPlease enter your Log in: ";
		cin >> logIn;
		cout << "\n\t\t\t\tPlease enter password: ";
		cin >> password;
		// Using class user, write all input regarding to new user.
		User newUser;
		newUser.userName = name;
		newUser.userLogIn = logIn;
		newUser.userPassword = password;

		// Write all input regarding to new user to conteiner.
		users.push_back(newUser);
		cout << "\n\t\t\t\t=============Account for " << name << " was created succesfully============\t\t\t\t";
		cout << "\n\t\t\t\tY - Create one more account / N - Exit;\n\t\t\t\t";
		cin >> c;
	} while (c == 'Y' || c == 'y');
}

void Chat::inboxMessage() // This is class has a main method that provides all inbox messages from user to user or to all users
{
	for (int i = 0; i < userMessage.size(); ++i)
	{
		if (userMessage[i].userNameInbox == currentUser.userName)
		{
			cout << "\n\t\t\t\tYou have message from " << userMessage[i].userNameInbox << endl;
			cout << "\t\t\t\tMessage text: " << userMessage[i].userText << "\n";
		}
		else
		{
			cout << "\t\t\t\tYou have message from " << userMessage[i].userNameInbox << endl;
			cout << "\t\t\t\tMessage text: " << userMessage[i].userText << "\n";
		}
	}
}

void Chat::logInAccount() // this is method provides function to login into account
{
	int group;
	string logIn;
	string password;
	string name;
	string text;
	char y;
	do
	{
		cout << "\n\t\t\t\tPlease enter your Log in: ";
		cin >> logIn;
		for (int i = 0; i < users.size(); ++i)
		{
			if (users[i].userLogIn == logIn) // Check existing user's logins and compare with input login
			{
				cout << "\n\t\t\t\tPlease enter password: ";
				cin >> password;
				if (users[i].userPassword == password) // Check existing user's passwords and compare with input password
				{
					currentUser = users[i]; // Assign find user as current
					cout << "\t\t\t\tYou succesfully log in!\n\n";
					Chat::inboxMessage(); // Show all inbox messages for current user
					cout << "\n\t\t\t\t" << "Would you like to create a group chat? (1 - single; 2 - group) \n\t\t\t\t";
					cin >> group; // Switch function provides options of conversation
					switch (group)
					{
					case 1: // Conversation with one user
						Chat::sendSingleMessage();
						break;
					case 2:// Conversation with all users
						Chat::sendGroupMessage();
						break;
					default:
						cout << "\t\t\t\tThere is no action like this!" << endl;
					}
					return;
				}
			}
		}
		cout << "\n\t\t\t\tAccount has not been found";
		cout << "\n\t\t\t\tWould you like to try again? (Y/N)";
		cin >> y;
	} while (y == 'Y' || y == 'y');
	cout << "\n\t\t\t\t=========See you later!==============";
}

void Chat::sendSingleMessage() // Method of conversation with one user
{
	string name;
	string text;
	char x;
	cout << "\n\t\t\t\tChoose person ";
	cin >> name; // Type and find persone who you are going to send message
		for (int i = 0; i < users.size(); ++i) 
		{
			if (users[i].userName == name)
			{
				cout << "\n\t\t\t\tChat with " << name <<endl;
				do 
				{
					cout << "\n\t\t\t\t============Type your message===========\n\t\t\t\t";
					cin >> text;
					// using variables from class Message assign loged in user's name and message 
					Message inbox;
					inbox.userNameInbox = currentUser.userName;
					inbox.userText = text;
					userMessage.push_back(inbox); // Put all information regarding sender and text message to container
					cout << "\n\t\t\t\tYour message has been sent to " << name << endl;
					cout << "\n\t\t\t\tY - Continue / N - Exit;\n\t\t\t\t";
					cin >> x;
				} while (x == 'Y' || x == 'y');
				cout << "\t\t\t\t" << "Chat with " << name << " saved and closed" << endl;
			}
		}
}

void Chat::sendGroupMessage() // Method of conversation with all users
{
	string name;
	string text;
	char x;
	// using variables from class Message assign loged in user's name and message to all users
	Message inbox;
	inbox.userNameInbox = currentUser.userName;
	inbox.userText = text;
	userMessage.push_back(inbox);// Put all information regarding sender and text message to container
	do
	{
		cout << "\n\t\t\t\tChat with:\t\t\t\t " << endl;
		for (int i = 0; i < users.size(); ++i)
		{
			for (int i = 0; i < userMessage.size(); ++i)
			{
				userMessage[i].userNameInbox = users[i].userName;
				
			}
			cout << "\t\t\t\t" << users[i].userName << endl;
		}
	
		cout << "\n\t\t\t\t============Type your message to All===========\n\t\t\t\t";
		cin >> text;
			
		for (int i = 0; i < userMessage.size(); ++i)
		{
				userMessage[i].userText = text;
		}
		cout << "\n\t\t\t\tYour message has been sent to All" << endl;
		cout << "\n\t\t\t\tY - Continue / N - Exit;" << endl;
		cin >> x;
	} while (x == 'Y' || x == 'y');
}
	


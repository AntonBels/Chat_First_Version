#pragma once
#include "User.h"
#include "Message.h"
#include <iostream>
#include <vector>
using namespace std;

class Chat // This is the main class with all function/
{
public:
	void chat();
	void addNewUser();
	void logInAccount();
	void sendGroupMessage();
	void sendSingleMessage();
	void inboxMessage();
	User currentUser; 
	User currentMessage; 
	vector<User> users; // Container of users
	vector<Message> userMessage; // Container of inbox messages
	
};

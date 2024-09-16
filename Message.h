#pragma once
#include "User.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Message // This is clas that creat two variables when user send a message
{
public:
	string userNameInbox; // Variable for user who send message
	string userText; // Variable for inbox messages
};

#pragma once
#include <iostream>
#include <string>
#include <fstream>
class Bank
{
private:
	std::string m_userName;
	std::string m_password;

	std::string m_accountsFile;
	void appendAccount();
public:
	Bank(std::string, std::string, std::string);
	Bank();

	bool isCorrectUserName(std::string);
	bool isCorrectPassword(std::string);
	
	void signUp();
};


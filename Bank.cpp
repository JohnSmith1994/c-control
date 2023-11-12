#include "Bank.h"

using namespace std;

Bank::Bank(string name, string password, string file = "Accounts.txt") : m_userName{ name }, m_password{ password }, m_accountsFile{ file } {}

Bank::Bank(): Bank("", "") {}

bool Bank::isCorrectUserName(string name)
{
	if (name.length() >= 6 && name.length() <= 16)
	{
		for (int i = 0; i < name.length(); i++)
		{
			if (!isalpha(name[i]))
				return false;
		}
		return true;
	}
	return false;
}

bool Bank::isCorrectPassword(string password)
{
	bool upperLetter = false;
	bool lowerLetter = false;
	bool digit = false;
	if (password.length() >= 8 && password.length() <= 128)
	{
		for (int i = 0; i < password.length(); i++)
		{
			if (!upperLetter && isupper(password[i]))
				upperLetter = true;
			if (!lowerLetter && islower(password[i]))
				lowerLetter = true;
			if (!digit && isdigit(password[i]))
				digit = true;
		}
	}
	return upperLetter && lowerLetter && digit;
}

void Bank::appendAccount()
{
	ofstream file(m_accountsFile, ios::app);

	if (file.is_open() && isCorrectUserName(m_userName) && isCorrectPassword(m_password)) {
		file << "Name: " << m_userName << ". Password: " << m_password << '\n';
		file.close();
	}
}

void Bank::signUp()
{
	string name;
	string password;
	do
	{
		cout << "\t\t==========Welcome To \"Money Bank\"==========\n";
		cout << "Enter your name(name must contain letters ONLY): ";
		getline(cin, name);
		cout << "Enter your password(password must be between 8 and 128 characters long and contain at least one lowercase letter, one uppercase letter, and one number): ";
		getline(cin, password);
		system("cls");
	} while (!isCorrectUserName(name));
	m_userName = name;
	m_password = password;
	appendAccount();
}

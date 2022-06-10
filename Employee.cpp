#include "Employee.h"
#include<vector>
#include <iostream>
#include<string>
using namespace std;

Employee::Employee() 
{
	id = 0;
	is_signed = false;
}

bool Employee::signUp(string n, string pass) 
{
	if (name.size() == 0)
	{
		name.push_back(n);
		password.push_back(pass);
		id++;
		return true;
	}

	for (int i = 0; i < name.size(); i++)
	{
		if (n == name[i])
		{
			return false;
		}
		if (i == name.size() - 1 && n != name[i])
		{
			name.push_back(n);
			password.push_back(pass);
			id++;
			return true;
		}
	}
}

bool Employee::signIn(string n, string p) {
	if (name.size() == 0) {

		cout << "you are not signed.." << endl;
	}
	else {
		is_signed = true;
		for (int i = 0; i < name.size(); i++)
		{
			if (name[i] == n && password[i] == p)
			{
				cout <<"Hello," << name[i] << endl;
				return true;
			}
		}
	}
	cout << "Invalid Username Or Password" << endl;
	return false;
}


Employee::~Employee() {
	
}
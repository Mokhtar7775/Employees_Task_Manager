#pragma once
#include<vector>
#include<string>
#include "Task.h"
using namespace std;
class Employee
{
public:
	int id;
	vector<string> name;
	vector<string> password;
	Employee();
	bool signUp(string s, string t);
	bool signIn(string i, string u);
	~Employee();
	bool is_signed;
	
};
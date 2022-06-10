#include <iostream>
#include "Employee.h"
#include "Task.h"
using namespace std;

Employee e;
Task t;
string a = " ", b = " "; int choice;
void display();
int main()
{
	
	while (true)
	{
		cout << "Enter 1 to sign up or 2 to sign in : ";
		cin >> choice;
		if (choice == 1)
		{
			cout << "name : "; cin >> a;
			cout << "password : "; cin >> b;
			if (!e.signUp(a, b))
			{
				cout << "The username is already exists , please enter another one \n";
			}
		}
		else if (choice == 2)
		{
			cout << "name : "; cin >> a;
			cout << "password : "; cin >> b;
			bool sign = e.signIn(a, b);
			if (sign)
			{
				display();
			}
		}
		else
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input.  Try again: "<<endl;
			main();
		}
	}
	
}


void display()
{
	string choice;
	cout << "***********************\n";
	cout << "1- Insert task\n";
	cout << "2- Display All Tasks\n";
	cout << "3- Update task\n";
	cout << "4- Edit task\n";
	cout << "5- Postpone task\n";
	cout << "6- Sign out\n\n";
	cout << "Your choice is : ";cin >> choice;
	if (choice == "1")
	{
	insert:
		t.insert(a, e.name);
		char c;
		cout << "Do you need to add another task..?(y/n) : "; cin >> c;
		if (c == 'y' || c == 'Y')
		{
			goto insert;
		}
		else if (c == 'n' || c == 'N')
		{
			t.remind();
			display();
		}
	}
	else if (choice == "2")
	{	
		t.display();
		t.remind();
		display();
	}
	else if (choice == "3")
	{
		t.update();
		t.remind();
		display();
	}
	else if (choice == "4")
	{
		t.Edit();
		t.remind();
		display();
	}
	else if (choice == "5")
	{
		if (!t.display())
		{
			display();
		}
		
		string title;
		cout << "Enter the title of task to be postponed:";cin >> title;
		t.post_pone(title);
		t.remind();
		display();
	}
	else if (choice == "6")
	{
		system("CLS");
		main();
	}
	else
	{
		cout << "Invalid choice \n";
		display();
	}
}

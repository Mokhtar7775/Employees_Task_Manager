//#include <iostream>
//#include "Employee.h"
//#include "Task.h"
//using namespace std;
//
//Employee e;
//Task t;
//string a = " ", b = " ", int choice;
//
//int main()
//{
//	while (true)
//	{
//		cout << "Enter 1 to sign up or 2 to sign in :";
//		cin >> choice;
//		if (choice == 1)
//		{
//			cout << "name : "; cin >> a;
//			cout << "password : "; cin >> b;
//			e.signUp(a, b);
//		}
//		else if (choice == 2)
//		{
//			cout << "name : "; cin >> a;
//			cout << "password : "; cin >> b;
//			bool sign = e.signIn(a, b);
//			if (sign)
//			{
//				display();
//			}
//		}
//	}
//
//}
//
//
//void display()
//{
//	int c;
//	cout << "1- Insert task\n";
//	cout << "2- Display All Tasks\n";
//	cout << "3- Update task\n";
//	cout << "4- Edit task\n";
//	cout << "5- Postpone task\n";
//	cout << "6- Sign out\n";
//	cin >> c;
//	if (choice == 1)
//	{
//	insert:
//		t.insert(a, e.name);
//		char c;
//		cout << "Do you need to add another task..?(y/n) : "; cin >> c;
//		if (c == 'y' || c == 'Y')
//		{
//			goto insert;
//		}
//		else if (c == 'n' || c == 'N')
//		{
//			t.remind();
//			display();
//		}
//			
//	}
//	else if (choice == 2)
//	{
//		t.display();
//		t.remind();
//		display();
//	}
//	else if (choice == 3)
//	{
//		t.update();
//		display();
//	}
//	else if (choice == 4)
//	{
//		display();
//	}
//	else if (choice == 5)
//	{
//		t.display();
//		int x;
//		cout << "Enter the number of task to be postponed:";cin >> x;
//		t.post_pone(x);
//		t.remind();
//		display();
//	}
//	else if (choice == 6)
//	{
//		system("CLS");
//		main();
//	}
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//

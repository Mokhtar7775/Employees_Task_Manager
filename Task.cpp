#define _CRT_SECURE_NO_WARNINGS
#include "Task.h"
#include <iostream>
#include<string>
#include<ctime>
using namespace std;

Task::Task()
{
	vector_indx = 0;
	emp_name = " ";
	t.priority = 0;
	t.task_title = " ";
	t.description = " ";
	t.assigning_date.year="0";
	t.assigning_date.month = "0";
	t.assigning_date.day = "0";
	t.ending_date.year = "0";
	t.ending_date.day = "0";
	t.ending_date.month = "0";
}
void Task::check_year(int a)
{
	while (true)
	{
		if (a >= 2022)
		{
			break;
		}
		cout << "Invalid year , Enter year again\n";
		cout << "year:" << " ";
		cin >> a;
	}
}
void Task::check_month(int a)
{
	while (true)
	{
		if (a <= 12 && a >= 1)
		{
			break;
		}
		cout << "Invalid month , Enter month again\n";
		cout << "month:" << " ";
		cin >> a;
	}
}
void Task::check_day(int a)
{
	while (true)
	{
		if (a <= 31 && a >= 1)
		{
			break;
		}
		cout << "Invalid day , Enter day again\n";
		cout << "day:" << " ";
		cin >> a;
	}
}

typedef struct node
{
	Task::task_info data;

	int priority;

	struct node* next;

} Node;

Node* newNode(Task::task_info data, int priority)
{
	Node* temp = new Node();
	temp->data = data;
	temp->priority = priority;
	temp->next = NULL;

	return temp;
}
void push(Node** head, Task::task_info data, int priority)
{
	Node* start = (*head);

	Node* task_node = newNode(data, priority);

	if ((*head)->priority < priority)
	{
		task_node->next = *head;
		(*head) = task_node;
	}
	else
	{
		while (start->next != NULL && start->next->priority > priority)
		{
			start = start->next;
		}

		task_node->next = start->next;
		start->next = task_node;
	}
}

void pop(Node** head)
{
	Node* deleted_node = *head;
	(*head) = (*head)->next;
	free(deleted_node);
}

Task::task_info peek(Node** head)
{
	return (*head)->data;
}

int isEmpty(Node** head)
{
	return (*head) == NULL;
}
Node* deleteNode(Node** head, string key)
{

	Node* temp = *head;
	Node* prev = NULL;
	Node* return_node;
	if (temp != NULL && temp->data.task_title == key)
	{
		*head = temp->next;
		//delete temp;		 
		return temp;
	}

	else
	{
		while (temp != NULL && temp->data.task_title != key)
		{
			prev = temp;
			temp = temp->next;
		}

		if (temp == NULL)
			return NULL;

		prev->next = temp->next;
		//delete temp;
	}
	return temp;
}


Node* task[10];

void Task::insert(string name,vector<string>employee_name) 
{
	
	cout << "Name of Task : "; cin >> t.task_title;
	cout << "Description : ";cin >> t.description;
	int x;
	cout << "Priority : ";cin >> x;
	t.priority = x;
	cout << "assigning_date in yy mm dd format : " << endl;
	
	cout << "year:" << " ";
	cin >> t.assigning_date.year;
	check_year(stoi(t.assigning_date.year));
	cout << "month:" << " ";
	cin >> t.assigning_date.month;
	check_month(stoi(t.assigning_date.month));
	cout << "day:" << " ";
	cin >> t.assigning_date.day;
	check_day(stoi(t.assigning_date.day));
	

	cout << "ending_date in yy mm dd format : " << endl;
	cout << "year:" << " ";
	cin >> t.ending_date.year;
	check_year(stoi(t.ending_date.year));
	cout << "month:" << " ";
	cin >> t.ending_date.month;
	check_month(stoi(t.ending_date.month));
	cout << "day:" << " ";
	cin >> t.ending_date.day;
	check_day(stoi(t.ending_date.day));

	for (int i = 0; i < employee_name.size(); i++) 
	{
		if (employee_name[i] == name) 
		{
			emp_name = name;
			if (isEmpty(&task[i])) 
			{
				task[i] = newNode(t, t.priority);
			}
			else 
			{
				push(&task[i], t, t.priority);
			}
			indx = i;
		}
		
	}
}
bool Task::display() 
{
	Node* cpy_node = task[indx];
	
	if (isEmpty(&task[indx]))
	{
		cout << "No tasks to be displayed\n";
		return false;
	}
	else
	{
		cout << "***************************************" << endl;
		cout << "**************Display Tasks************" << endl;
		cout << emp_name << "'sTasks" << endl;
		cout << "***************************************" << endl;


		while (cpy_node !=NULL)
		{
			cout <<"task title : " << peek(&cpy_node).task_title<<endl;
			cout <<"Description : " << peek(&cpy_node).description << endl;
			cout << "assigning_date: "
				<< peek(&cpy_node).assigning_date.day << " / "
				<< peek(&cpy_node).assigning_date.month << " / "
				<< peek(&cpy_node).assigning_date.year << endl;

			cout << "ending_date: "
				<< peek(&cpy_node).ending_date.day << " / "
				<< peek(&cpy_node).ending_date.month << " / "
				<< peek(&cpy_node).ending_date.year << endl;
			cout << "***************************************" << endl;
			cpy_node = cpy_node->next;
		}

		return true;
	}
}
void printList(Node* node)
{
	while (node != NULL)
	{
		cout << node->data.task_title << " ";
		node = node->next;
	}
}

void Task::update()
{
	string task_name;
	int indx = vector_indx;
	char up;
	bool flag = true,empty=true;
	cout << "Enter the title of the task done : ";
	cin >> task_name;
	deleteNode(&task[indx], task_name);
	printList(task[indx]);
			
	if(isEmpty(&task[indx]))
		encourage();
}
void Task::remind()
{
	Node* cpy_node = task[indx];
	while(cpy_node !=NULL){
		string day = cpy_node->data.assigning_date.day;
		string month = cpy_node->data.assigning_date.month;
		string year = cpy_node->data.assigning_date.year;
		bool flag = cal_time(day, month, year);
		if (flag == true)
		{
			cout << "*************************\n";
			cout << "your next task is:" << cpy_node->data.task_title << endl;
			cout << "with assigning date:" << cpy_node->data.assigning_date.day<<"/"
			<< cpy_node->data.assigning_date.month<<"/"
			<< cpy_node->data.assigning_date.year << endl;
			cout << "and ending date:" << cpy_node->data.ending_date.day <<"/"
			<< cpy_node->data.ending_date.month <<"/"
			<< cpy_node->data.ending_date.year << endl;
			cout << "--------------------------" << endl;
		}
		cpy_node = cpy_node->next;
	}
}
void Task::encourage()
{
	cout << "Good job,all your tasks are done efficiently" << endl;
}
bool Task:: cal_time(string day, string month, string year)
{
	int y, m, d;
	time_t ttime = time(0);
	tm* local_time = localtime(&ttime);
	y = 1900 + local_time->tm_year;
	m = 1 + local_time->tm_mon;
	d = local_time->tm_mday;
	
	int mm = stoi(month) - m;
	int dd = stoi(day) - d;
	int yy = stoi(year) - y;
	
	if (dd < 0)
	{
		mm--;
		dd += 30;
	}
	if (mm < 0)
	{
		yy--;
		mm += 12;
	}
	if (dd == 1 && mm == 0 && yy == 0)
	{
		return true;
	}
	else
		return false;
}
void Task::post_pone(string index)
{

	string year, month, day;
	cout << "Enter the new Ending date in yy mm dd:";
	cout << "year : ";cin >> year;
	cout << " month : ";cin >> month;
	cout << "day : ";cin >> day;
	Node* temp = deleteNode(&task[indx], index);
	t = temp->data;
	t.assigning_date = temp->data.assigning_date;
	t.description = temp->data.description;
	t.ending_date.day = day;
	t.ending_date.month = month;
	t.ending_date.year = year;
	if (isEmpty(&task[indx]))
	{
		task[indx] = newNode(t, t.priority);
	}
	else
	{
		push(&task[indx], t, t.priority);
	}
}
void Task::Edit()
{
	string data;int choice;
	cout << "What is the title of task do you to edit?";cin >> data;
	cout << "What do you want to edit" << endl << "1-Title\n" << "2-Description\n" 
		<< "3-priority\n" << "4-Assigning date\n";
	Node* temp = deleteNode(&task[indx] , data);
	again:
	cin >> choice;
	t = temp->data;
	if (choice == 1)
	{
		cout << "Enter the new title\n";
		cin >> data;
		t.task_title = data;
	}
	else if (choice == 2)
	{
		cout << "Enter the new Description\n";
		cin >> data;
		t.description = data;
	}
	else if (choice == 3)
	{
		cout << "Enter the new priority\n";
		int p; cin >> p;
		t.priority = p;
	}
	else if (choice == 4)
	{
		cout << "Enter the new date yy mm dd\n";
		string y,m,d; 
		cout << "year : ";cin >> y;
		cout << " month : ";cin >> m;
		cout << "day : ";cin >> d;
		t.assigning_date.year = y;
		t.assigning_date.month = m;
		t.assigning_date.day = d;
	}
	else
	{
		cout << "Invalid choice , again\n";
		goto again;			
	}
	if (isEmpty(&task[indx]))
	{
		task[indx] = newNode(t, t.priority);
	}
	else
	{
		push(&task[indx], t, t.priority);
	}
	
	
}
Task::~Task(){

}

#pragma once
#include<vector>
#include<string>
#include "Employee.h"
#include<queue>
using namespace std;

class Task
{
public:

	Task();
	struct end_date
	{
		string year , month , day;
	}ending_date;

	struct task_info
	{
		int priority;
		string task_title, description;
		end_date ending_date,assigning_date;
	}t,tmp_t,tmp_task;
	int indx;
	int vector_indx;
	string emp_name;
	void insert(string ,vector<string>);
	void check_year(int);
	void check_month(int);
	void check_day(int);
	bool display();
	void update();
	void remind();
	void encourage();
	bool cal_time(string, string, string);
	void post_pone(string);
	void Edit();
	~Task();
};


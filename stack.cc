 ///
 /// @file    stack.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-07-28 17:21:30
 ///
 
#include <iostream>
#include<string.h>
#include<stdlib.h>
using std::cout;
using std::endl;
using std::string;
class Student
{
	public:
		Student(int id,const char *name)
		:_id(id)
		,_name(new char[strlen(name)+1]())
		{
			cout<<"Student (int,char *)"<<endl;
			strcpy(_name,name);
		}
		void print()const
		{
			cout<<"id:"<<_id<<endl
				<<"name:"<<_name<<endl;
		}
	private:
		static void *operator new(size_t sz);
		static void operator delete(void *ret);
	private:
		int _id;
		char *_name;
};
int main(void)
{
	Student s(101,"Alice");
	//Student *pstu=new Student(100,"Mike");
	//p->delete();
	s.print();
	return 0;
}

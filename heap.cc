 ///
 /// @file    head.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-07-28 14:54:14
 ///
 
#include <iostream>
#include<string.h>
#include<stdlib.h>
using std::cout;
using std::endl;
class Student
{
	public:
		//自定义传入参数的构造函数
		Student(int id,const char *name)//传入的name使用常量指针
		:_id(id)
		,_name(new char[strlen(name)+1]())
		{
			cout<<"Student(int,char*)"<<endl;
			strcpy(_name,name);
		}
		//添加的打印函数因为不需要改变故加const
		void print()const
		{
			cout<<"id:"<<_id<<endl
				<<"name:"<<_name<<endl;
		}
		void destroy()
		{
			delete this;
		}
		//下面的两个new()时调用的函数
		//隐式存在这里写出来帮助理解
		static void *operator new(size_t sz)
		{
			cout<<"void *operator new(size_t)"<<endl;
			void *ret=malloc(sz);
			return ret;
		}
		static void operator delete(void *ret)
		{
			free(ret);
			cout<<"void operator delete(void*)"<<endl;
		}
	private:
		//析构函数私有化
		~Student()
		{
			delete [] _name;
		}
	private:
		int _id;
		char *_name;
};
int main(void)
{
	//想申请一个堆空间存放对象
	Student * pstu=new Student(100,"Mike");
	pstu->print();
	pstu->destroy();
	return 0;
}
/*其实可以简单写成下面的形式
class Student
{
	public:
		//自定义传入参数的构造函数
		Student(int id,const char *name)//传入的name使用常量指针
		:_id(id)
		,_name(new char[strlen(name)+1]())
		{
			cout<<"Student(int,char*)"<<endl;
			strcpy(_name,name);
		}
		void destroy()
		{
			delete this;
		}
	private:
		//析构函数私有化
		~Student()
		{
			delete [] _name;
		}
	private:
		int _id;
		char *_name;
};*/
 

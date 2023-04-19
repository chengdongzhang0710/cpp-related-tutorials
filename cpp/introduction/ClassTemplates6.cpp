// 解决方式1：直接包含.cpp源文件
// #include "Person.cpp"

// 解决方式2：将声明和实现写到同一个文件中，并更改后缀名为.hpp，hpp是约定的名称，并不是强制
#include "Person.hpp"

void test1()
{
	Person<string, int> p("Tom", 10);
	p.show();
}

int main()
{
	test1();
	
	system("pause");
	return 0;
}

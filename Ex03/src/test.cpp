
#include <iostream>
#include "ex_01.h"

using namespace std;

int main()
{
CDArray<double> a;
cout<<a<<endl;
a.SetAt(0, 3.0);

cout<<a<<endl;


a.Pushback(3.0);
a.Pushback(3.1);
a.Pushback(3.2);
cout<<a<<endl;

a.DeleteAt(0);
cout<<a<<endl;

a.InsertAt(0, 4.1);
cout<<a<<endl;

CDArray<double> acopy = a;  //此处用到了拷贝构造函数
cout<<acopy<<endl;

CDArray<double> acopy2 (a);  //该语句等同于上面的语句，都是初始化
cout<<acopy2<<endl;

CDArray<double> acopy3;
acopy3 = a;					//此处用到了赋值操作符号"="的重载
cout<<acopy3<<endl;


CDArray<int> b;
b.Pushback(21);
cout<<b<<endl;
b.DeleteAt(0);
b.Pushback(22);
cout<<b<<endl;
b.SetSize(5);
cout<<b.GetSize()<<endl;

CDArray<char> c;
c.Pushback('a');
c.Pushback('b');
c.Pushback('c');
c.InsertAt(0, 'd');
cout<<c<<endl;

return 0;
}

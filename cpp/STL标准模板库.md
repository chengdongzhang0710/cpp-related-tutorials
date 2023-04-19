# STL标准模板库



## string容器

#### 基本概念

本质：

- string是C++风格的字符串，而string本质上是一个类

string和char\*的区别：

- char\*是一个指针
- string是一个类，类内部封装了char\*管理这个字符串，是一个char\*型的容器

特点：

- string类内部封装了很多成员方法，例如查找find，拷贝copy，删除delete，替换replace，插入insert等
- string管理char\*所分配的内存，不用担心复制越界和取值越界等，由类内部进行负责



#### 构造函数

函数原型：

```c++
string();  // 创建一个空的字符串，例如：string str;
string(const char* s);  // 使用字符串s初始化
string(const string& str);  // 使用一个string对象初始化另一个string对象
string(int n, char c);  // 使用n个字符c初始化
```

总结：

- string的多种构造方式没有可比性，灵活使用即可



#### 赋值操作

功能描述：

- 给string字符串进行赋值

函数原型：

```c++
string& operator=(const char* s);  // 把char*类型字符串赋值给当前的字符串
string& operator=(const string& str);  // 把字符串str赋值给当前的字符串
string& operator=(char c);  // 把字符赋值给当前的字符串
string& assign(const char* s);  // 把字符串s赋值给当前的字符串
string& assign(const char* s, int n);  // 把字符串s的前n个字符赋值给当前的字符串
string& assign(const string& str);  // 把字符串str赋值给当前的字符串
string& assign(int n, char c);  // 用n个字符c赋值给当前的字符串
```

总结：

- string的赋值方法很多，operator=这种方法是比较实用的



#### 字符串拼接

功能描述：

- 实现在字符串末尾拼接字符串

函数原型：

```c++
string& operator+=(const char* s);  // 重载+=操作符
string& operator+=(const char c);  // 重载+=操作符
string& operator+=(const string& str);  // 重载+=操作符
string& append(const char* s);  // 把字符串s连接到当前字符串结尾
string& append(const char* s, int n);  // 把字符串s的前n个字符连接到当前字符串结尾
string& append(const string& str);  // 同string& operator+=(const string& str)
string& append(const string& str, int pos, int n);  // 字符串str中从pos开始的n个字符连接到字符串结尾
```

总结：

- 字符串拼接的重载版本很多，初学阶段记住几种即可



#### 字符串查找和替换

功能描述：

- 查找：查找指定字符串是否存在
  - 如果指定字符串存在，返回该字符串的位置下标；如果指定字符串不存在，返回-1
  - rfind和find的区别：rfind从右往左查找，find从左往右查找
- 替换：在指定的位置替换字符串

函数原型：

```c++
int find(const string& str, int pos = 0) const;  // 查找str第一次出现的位置，从pos开始查找
int find(const char* s, int pos = 0) const;  // 查找s第一次出现的位置，从pos开始查找
int find(const char* s, int pos, int n) const;  // 从pos位置查找s的前n个字符第一次出现的位置
int find(const char c, int pos = 0) const;  // 查找字符c第一次出现的位置
int rfind(const string& str, int pos = npos) const;  // 查找str最后一次出现的位置，从pos开始查找
int rfind(const char* s, int pos = npos) const;  // 查找s最后一次出现的位置，从pos开始查找
int rfind(const char* s, int pos, int n) const;  // 从pos位置查找s的前n个字符最后一次出现的位置
int rfind(const char c, int pos = 0) const;  // 查找字符c最后一次出现的位置
string& replace(int pos, int n, const string& str);  // 替换从pos开始的n个字符为字符串str
string& replace(int pos, int n, const char* s);  // 替换从pos开始的n个字符为字符串s
```

总结：

- find查找是从左往右，rfind查找是从右往左
- find找到字符串后返回查找的第一个字符位置，找不到返回-1
- replace在替换时，要指定从哪个位置起，多少个字符，替换成什么样的字符串



#### 字符串比较

功能描述：

- 字符串之间的比较

比较方式：

- 字符串比较是按字符的ASCII码逐个进行对比
- =返回0，>返回1，<返回-1

函数原型：

```c++
int compare(const string& str) const;  // 与字符串str比较
int compore(const char* s) const;  // 与字符串s比较
```

总结：

- 字符串对比主要是用于比较两个字符串是否相等，判断谁大谁小的意义并不是很大



#### 字符存取

string中单个字符存取方式有两种：

```c++
char& operator[](int n);  //通过[]方法获取字符
char& at(int n);  // 通过at方法获取字符
```

总结：

- string字符串中单个字符存取有两种方式，利用[]或at



#### 字符串插入和删除

功能描述：

- 对string字符串进行插入和删除字符操作

函数原型：

```c++
string& insert(int pos, const char* s);  // 在指定位置插入字符串
string& insert(int pos, const string& str);  // 在指定位置插入字符串
string& insert(int pos, int n, char c);  // 在指定位置插入n个字符c
string& erase(int pos, int n = npos);  // 删除从pos开始的n个字符
```

总结：

- 插入和删除的起始下标都是从0开始的



#### 子串获取

功能描述：

- 从字符串中获取想要的子串

函数原型：

```c++
string substr(int pos = 0, int n = npos) const;  // 返回由pos开始的n个字符组成的字符串
```

实用案例：

```c++
#include <iostream>
#include <string>
using namespace std;

void func()
{
    string email = "hello@sina.com";
    
    // 从邮件地址中获取用户名信息
    int pos = email.find("@");
    string user = email.substr(0, pos);
    cout << "user = " << user << endl;
}

int main()
{
    func();
    system("pause");
    return 0;
}
```

总结：

- 灵活运用求子串的功能，可以在实际开发中获取有效的信息





## vector容器

#### 基本概念

功能：

- vector数据结构和数组非常相似，也称为单端数组

vector与普通数组的区别：

- 不同之处在于数组是静态空间，而vector可以动态扩展

动态扩展：

- 并不是在原空间之后续接新空间，而是找更大的内存空间，然后将原数据拷贝新空间，释放原空间
- vector容器的迭代器是支持随机访问的迭代器



#### 构造函数

功能描述：

- 创建vector容器

函数原型：

```C++
vector<T> v;  // 采用模板实现类实现，默认构造函数
vector(v.begin(), v.end());  // 将v[begin(), end())区间中的元素拷贝给本身，区间是前闭后开的
vector(n, elem);  // 构造函数将n个elem拷贝给本身
vector(const vector& vec);  // 拷贝构造函数
```

总结：

- vector的多种构造方式没有可比性，灵活使用即可



#### 赋值操作

功能描述：

- 给vector容器进行赋值

函数原型：

```c++
vector& operator=(const vector& vec);  // 重载等号操作符
assign(beg, end);  // 将[beg, end)区间中的数据拷贝赋值给本身
assign(n, elem);  // 将n个elem拷贝赋值给本身
```

总结：

- vector赋值方式比较简单，使用operator=或者assign都可以



#### 容量和大小

功能描述：

- 对vector容器的容量和大小操作

函数原型：

```c++
empty();  // 判断容器是否为空
capacity();  // 容器的容量
size();  // 返回容器中元素的个数
resize(int num);  // 重新指定容器的长度为num
				  // 如果容器变长，则以默认值填充新位置；如果容器变短，则末尾超出容器长度的元素被删除
resize(int num, elem);  // 重新指定容器的长度为num
						// 如果容器变长，则以elem值填充新位置；如果容器变短，则末尾超出容器长度的元素被删除
```

总结：

- 判断是否为空 - empty
- 返回元素个数 - size
- 返回容器容量 - capacity
- 重新指定大小 - resize



#### 插入和删除

功能描述：

- 对vector容器进行插入、删除操作

函数原型：

```c++
push_back();  // 尾部插入元素ele
pop_back();  // 删除最后一个元素
insert(const_iterator pos, ele);  // 迭代器指向位置pos插入元素ele
insert(const_iterator pos, int count, ele);  // 迭代器指向位置pos插入count个元素ele
erase(const_iterator pos);  // 删除迭代器指向的元素
erase(const_iterator start, const_iterator end);  // 删除迭代器从start到end之间的元素
clear();  // 删除容器中所有元素
```

总结：

- 尾插 - push_back
- 尾删 - pop_back
- 插入 - insert (位置迭代器)
- 删除 - erase (位置迭代器)
- 清空 - clear



#### 数据存取

功能描述：

- 对vector中的数据的存取操作

函数原型：

```c++
at(int idx);  // 返回索引idx所指的数据
operator[];  // 返回索引idx所指的数据
front();  // 返回容器中第一个数据元素
back();  // 返回容器中最后一个数据元素
```

总结：

- 除了用迭代器获取vector容器中的元素，[]和at也可以
- front返回容器第一个元素
- back返回容器最后一个元素



#### 互换容器

功能描述：

- 实现两个容器内元素进行互换

函数原型：

```c++
swap(vec);  // 将vec与本身的元素互换
```

实际用途：

```c++
// 巧用swap可以收缩内存空间
void func()
{
    vector<int> v;
    for (int i = 0; i < 100000; i++)
    {
        v.push_back(i);
    }
    cout << "v的容量为：" << v.capacity() << endl;
    cout << "v的大小为：" << v.size() << endl;
    
    // 重新指定大小后，容量不变
    v.resize(3);
    cout << "v的容量为：" << v.capacity() << endl;
    cout << "v的大小为：" << v.size() << endl;
    
    // 使用swap收缩空间
    // vector<int>(v) - 匿名对象，在当前行回收
    vector<int>(v).swap(v);
    cout << "v的容量为：" << v.capacity() << endl;
    cout << "v的大小为：" << v.size() << endl;
}
```

总结：

- swap可以使两个容器互换，可以达到实用的收缩内存的效果



#### 预留空间

功能描述：

- 减少vector在动态扩展容量时的扩展次数

函数原型：

```c++
reserve(int len);  // 容器预留len个元素长度，预留位置不初始化，元素不可访问
```

总结：

- 如果数据量较大，可以一开始利用reserve预留空间





## deque容器

#### 基本概念

功能：

- 双端数组，可以对头端进行插入删除操作

deque与vector区别：

- vector对于头部的插入删除效率低，数据量越大，效率越低
- deque相对而言，对头部插入删除速度会比vector快
- vector访问元素时的速度会比deque快，这和两者内部实现有关

deque内部工作原理：

- deque内部有个中控器，维护每段缓存区中的内容，缓存区中存放真实数据
- 中控器维护的是每个缓冲区的地址，使得使用deque时像一片连续的内存空间

注意：

- deque容器的迭代器也是支持随机访问的



#### 构造函数

功能描述：

- deque容器构造

函数原型：

```c++
deque<T> deqT;  // 默认构造形式
deque(beg, end);  // 构造函数将[beg, end)区间中的元素拷贝给自身
deque(n, elem);  // 构造函数将n个elem拷贝给自身
deque(const deque& deq);  // 拷贝构造函数
```

总结：

- deque容器和vector容器的构造方式几乎一致，灵活使用即可



#### 赋值操作

功能描述：

- 给deque容器进行赋值

函数原型：

```c++
deque& operator=(const deque& deq);  // 重载等号操作符
assign(beg, end);  // 将[beg, end)区间中的数据拷贝赋值给本身
assign(n, elem);  // 将n个elem拷贝赋值给本身
```

总结：

- deque赋值操作也与vector相同，需熟练掌握



#### 大小操作

功能描述：

- 对deque容器的大小进行操作

函数原型：

```c++
deque.empty();  // 判断容器是否为空
deque.size();  // 返回容器中元素的个数
deque.resize(num);  // 重新指定容器的长度为num
					// 如果容器变长，则以默认值填充新位置；如果容器变短，则末尾超出容器长度的元素被删除
deque.resize(num, elem);  // 重新指定容器的长度为num
						  // 如果容器变长，则以elem值填充新位置；如果容器变短，则末尾超出容器长度的元素被删除
```

总结：

- deque没有容量的概念
- 判断是否为空 - empty
- 返回元素个数 - size
- 重新指定个数 - resize



#### 插入和删除

功能描述：

- 向deque容器中插入和删除数据

函数原型：

```c++
// 两端插入操作
push_back(elem);  // 在容器尾部添加一个数据
push_front(elem);  // 在容器头部插入一个数据
pop_back();  // 删除容器最后一个数据
pop_front();  // 删除容器第一个数据

// 指定位置操作
insert(pos, elem);  // 在pos位置插入一个elem元素的拷贝，返回新数据的位置
insert(pos, n, elem);  // 在pos位置插入n个elem数据，无返回值
insert(pos, beg, end);  // 在pos位置插入[beg, end)区间的数据，无返回值
clear();  // 清空容器的所有数据
erase(beg, end);  // 删除[beg, end)区间的数据，返回下一个数据的位置
erase(pos);  // 删除pos位置的数据，返回下一个数据的位置
```

总结：

- 插入和删除提供的位置是迭代器！
- 尾插 - push_back
- 尾删 - pop_back
- 头插 - push_front
- 头删 - pop_front



#### 数据存取

功能描述：

- 对deque中的数据的存取操作

函数原型：

```c++
at(int idx);  // 返回索引idx所指的数据
operator[];  // 返回索引idx所指的数据
front();  // 返回容器中第一个数据元素
back();  // 返回容器中最后一个数据元素
```

总结：

- 除了用迭代器获取deque容器中的元素，[]和at也可以
- front返回容器的第一个元素
- back返回容器的最后一个元素



#### 排序操作

功能描述：

- 利用算法实现对deque容器进行排序

算法：

```c++
sort(iterator beg, iterator end);  // 对beg和end区间内元素进行排序，默认排序规则是从小到大升序
								   // 对于支持随机访问迭代器的容器都可以利用sort算法直接对其进行排序，vector容器也可以利用sort进行排序
```

总结：

- sort算法非常实用，使用时包含头文件algorithm即可





## stack容器

#### 基本概念

概念：

- stack是一种先进后出(First In Last Out, FILO)的数据结构，它只有一个出口
- 栈中只有顶端的元素才可以被外界使用，因此栈不允许有遍历行为
- 栈中进入数据称为入栈(push)，栈中弹出数据称为出栈(pop)



#### 常用接口

功能描述：

- 栈容器常用的对外接口

函数原型：

```c++
// 构造函数
stack<T> stk;  // stack采用模板类实现，stack对象的默认构造形式
stack(const stack& stk);  // 拷贝构造函数

// 赋值操作
stack& operator=(const stack& stk);  // 重载等号操作符

// 数据存取
push(elem);  // 向栈顶添加元素
pop();  // 从栈顶移除第一个元素
top();  // 返回栈顶元素

// 大小操作
empty();  // 判断栈是否为空
size();  // 返回栈的大小
```

总结：

- 入栈 - push
- 出栈 - pop
- 返回栈顶 - top
- 判断栈是否为空 - empty
- 返回栈大小 - size





## queue容器

#### 基本概念

概念：

- queue是一种先进先出(First In First Out, FIFO)的数据结构，它有两个出口
- 队列容器允许从一端新增元素，从另一端移除元素
- 队列中只有队头和队尾才可以被外界使用，因此队列不允许有遍历行为
- 队列中进数据称为入队(push)，队列中出数据称为出队(pop)



#### 常用接口

功能描述：

- 队列容器常用的对外接口

函数原型：

```c++
// 构造函数
queue<T> que;  // queue采用模板类实现，queue对象的默认构造形式
queue(const queue& que);  // 拷贝构造函数

// 赋值操作
queue& operator=(const queue& que);  // 重载等号操作符

// 数据存取
push(elem);  // 往队尾添加元素
pop();  // 从队头移除第一个元素
back();  // 返回最后一个元素
front();  // 返回第一个元素

// 大小操作
empty();  // 判断队列是否为空
size();  // 返回队列的大小
```

总结：

- 入队 - push
- 出队 - pop
- 返回队头元素 - front
- 返回队尾元素 - back
- 判断队列是否为空 - empty
- 返回队列大小 - size





## list容器

#### 基本概念

功能：

- 将数据进行链式存储

概念：

- 链表是一种物理存储单元上非连续的存储结构，数据元素的逻辑顺序是通过链表中的指针链接实现的
- 链表的组成：链表由一系列结点组成
- 结点的组成：一个是存储数据元素的数据域，另一个是存储下一个结点地址的指针域
- STL中的链表是一个双向循环链表
- 由于链表的存储方式并不是连续的内存空间，因此链表list中的迭代器只支持前移和后移，属于双向迭代器

list的优点：

- 采用动态存储分配，不会造成内存浪费和溢出
- 链表执行插入和删除操作十分方便，修改指针即可，不需要移动大量元素

list的缺点：

- 链表灵活，但是空间(指针域)和时间(遍历)额外耗费较大

注意：

- list有一个重要的性质，插入操作和删除操作都不会造成原有list迭代器的失效，这在vector是不成立的

总结：

- STL中list和vector是两个最常被使用的容器，各有优缺点



#### 构造函数

功能描述：

- 创建list容器

函数原型：

```c++
list<T> lst;  // list采用模板类实现，list对象的默认构造形式
list(beg, end);  // 构造函数将[beg, end)区间中的元素拷贝给本身
list(n, elem);  // 构造函数将n个elem拷贝给本身
list(const list& lst);  // 拷贝构造函数
```

总结：

- list构造方式同其他几个STL常用容器，熟练掌握即可



#### 赋值和交换

功能描述：

- 给list容器进行赋值，以及交换list容器

函数原型：

```c++
assign(beg, end);  // 将[beg, end)区间中的数据拷贝赋值给本身
assign(n, elem);  // 将n个elem拷贝赋值给本身
list& operator=(const list& lst);  // 重载等号操作符
swap(lst);  // 将lst与本身的元素互换
```

总结：

- list赋值和交换操作能够灵活运用即可



#### 大小操作

功能描述：

- 对list容器的大小进行操作

函数原型：

```c++
size();  // 返回容器中元素的个数
empty();  // 判断容器是否为空
resize(num);  // 重新指定容器的长度为num
			  // 如果容器变长，则以默认值填充新位置；如果容器变短，则末尾超出容器长度的元素被删除
resize(num, elem);  // 重新指定容器的长度为num
					// 如果容器变长，则以elem值填充新位置；如果容器变短，则末尾超出容器长度的元素被删除
```

总结：

- 判断是否为空 - empty
- 返回元素个数 - size
- 重新指定个数 - resize



#### 插入和删除

功能描述：

- 对list容器进行数据的插入和删除

函数原型：

```c++
push_back(elem);  // 在容器尾部加入一个元素
pop_back();  // 删除容器中最后一个元素
push_front(elem);  // 在容器开头插入一个元素
pop_front();  // 删除容器中第一个元素
insert(pos, elem);  // 在pos位置插入elem元素的拷贝，返回新数据的位置
insert(pos, n, elem);  // 在pos位置插入n个elem数据，无返回值
insert(pos, beg, end);  // 在pos位置插入[beg, end)区间的数据，无返回值
clear();  // 移除容器的所有数据
erase(beg, end);  // 删除[beg, end)区间的数据，返回下一个数据的位置
erase(pos);  // 删除pos位置的数据，返回下一个数据的位置
remove(elem);  // 删除容器中所有与elem值匹配的元素
```

总结：

- 尾插 - push_back
- 尾删 - pop_back
- 头插 - push_front
- 头删 - pop_front
- 插入 - insert
- 删除 - erase
- 移除 - remove
- 清空 - clear



#### 数据存取

功能描述：

- 对list容器中数据进行存取

函数原型：

```c++
front();  // 返回第一个元素
back();  // 返回最后一个元素
```

总结：

- 不可以用[]或者at方式访问list容器中的元素；原因是list本质是链表，不是用连续线性空间存储数据，迭代器也是不支持随机访问的
- 返回第一个元素 - front
- 返回最后一个元素 - back



#### 反转和排序

功能描述：

- 将容器中的元素反转，以及将容器中的数据进行排序

函数原型：

```c++
reverse();  // 反转链表
sort();  // 链表排序，默认排序规则是从小到大升序

// 指定规则从大到小
bool myCompare(int v1, int v2)
{
    return v1 > v2;
}
sort(myCompare);
```

注意：

- 所有不支持随机访问迭代器的容器不可以用标准算法
- 不支持随机访问迭代器的容器内部会提供一些算法

总结：

- 反转 - reverse
- 排序 - sort (成员函数)





## set/multiset容器

#### 基本概念

简介：

- 所有元素都会在插入时自动被排序

本质：

- set/multiset属于关联式容器，底层结构是用二叉树实现

set和multiset区别：

- set不允许容器中有重复的元素
- multiset允许容器中有重复的元素



#### 构造和赋值

功能描述：

- 创建set容器以及赋值

函数原型：

```c++
// 构造
set<T> st;  // 默认构造函数
set(const set& st);  // 拷贝构造函数

// 赋值
set& operator=(const set& st);  // 重载等号操作符
```

总结：

- set容器插入数据时用insert
- set容器插入数据时数据会自动排序



#### 大小和交换

功能描述：

- 统计set容器大小以及交换set容器

函数原型：

```c++
size();  // 返回容器中元素的数目
empty();  // 判断容器是否为空
swap(st);  // 交换两个集合容器
```

总结：

- 统计大小 - size
- 判断是否为空 - empty
- 交换容器 - swap



#### 插入和删除

功能描述：

- set容器进行插入数据和删除数据

函数原型：

```c++
insert(elem);  // 在容器中插入元素
clear();  // 清除所有元素
erase(pos);  // 删除pos迭代器所指的元素，返回下一个元素的迭代器
erase(beg, end);  // 删除区间[beg, end)的所有元素，返回下一个元素的迭代器
erase(elem);  // 删除容器中值为elem的元素
```

总结：

- 插入 - insert
- 删除 - erase
- 清空 - clear



#### 查找和统计

功能描述：

- 对set容器进行查找数据以及统计数据

函数原型：

```c++
find(key);  // 查找key是否存在，如果存在，返回该键的元素的迭代器，如果不存在，返回set.end()
count(key);  // 统计key的元素个数
```

总结：

- 查找 - find (返回的是迭代器)
- 统计 - count (对于set，结果为0或者1)



#### set和multiset区别

区别：

- set不可以插入重复数据，而multiset可以
- set插入数据的同时会返回插入结果，表示插入是否成功
- multiset不会检测数据，因此可以插入重复数据

实用案例：

```c++
set<int> s;
pair<set<int>::iterator, bool> result = s.insert(10);
if (result.second)
{
    cout << "插入成功" << endl;
}
else
{
    cout << "插入失败" << endl;
}
```

总结：

- 如果不允许插入重复数据可以利用set
- 如果需要插入重复数据利用multiset



#### pair对组创建

功能描述：

- 成对出现的数据，利用对组可以返回两个数据

创建方式：

```c++
pair<type, type> p(value1, value2);
pair<type, type> p = make_pair(value1, value2);
```

总结：

- 两种方式都可以创建对组，记住一种即可



#### 容器排序

学习目标：

- set容器默认排序规则为从小到大，掌握如何改变排序规则

主要技术点：

- 利用仿函数，可以改变排序规则

总结：

- 利用仿函数可以指定set容器的排序规则
- 对于自定义数据类型，set必须指定排序规则才可以插入数据





## map/multimap容器

#### 基本概念

简介：

- map中所有元素都是pair
- pair中第一个元素为key(键值)，起到索引作用，第二个元素为value(实值)
- 所有元素都会根据元素的键值自动排序

本质：

- map/multimap属于关联式容器，底层结构是用二叉树实现

优点：

- 可以根据key值快速找到value值

map和multimap区别：

- map不允许容器中有重复key值元素
- multimap允许容器中有重复key值元素



#### 构造和赋值

功能描述：

- 对map容器进行构造和赋值操作

函数原型：

```c++
// 构造
map<T1, T2> mp;  // map默认构造函数
map(const map& mp);  // 拷贝构造函数

// 赋值
map& operator=(const map& mp);  // 重载等号操作符
```

总结：

- map中所有元素都是成对出现，插入数据时要使用对组



#### 大小和交换

功能描述：

- 统计map容器大小以及交换map容器

函数原型：

```c++
size();  // 返回容器中元素的数目
empty();  // 判断容器是否为空
swap(mp);  // 交换两个集合容器
```

总结：

- 统计大小 - size
- 判断是否为空 - empty
- 交换容器 - swap



#### 插入和删除

功能描述：

- map容器进行插入数据和删除数据

函数原型：

```c++
insert(elem);  // 在容器中插入元素
clear();  // 清除所有元素
erase(pos);  // 删除pos迭代器所指的元素，返回下一个元素的迭代器
erase(beg, end);  // 删除[beg, end)的所有元素，返回下一个元素的迭代器
erase(key);  // 删除容器中值为key的元素
```

总结：

- map插入方式很多，记住其一即可
- 插入 - insert
- 删除 - erase
- 清空 - clear



#### 查找和统计

功能描述：

- 对map容器进行查找数据以及统计数据

函数原型：

```c++
find(key);  // 查找key是否存在，如果存在，返回该键的元素的迭代器；如果不存在，返回set.end()
count(key);  // 统计key的元素个数
```

总结：

- 查找 - find (返回的是迭代器)
- 统计 - count (对于map结果为0或者1)



#### 容器排序

学习目标：

- map容器默认排序规则为按照key值进行从小到大排序，掌握如何改变排序规则

主要技术点：

- 利用仿函数可以改变排序规则

总结：

- 利用仿函数可以指定map容器的排序规则
- 对于自定义数据类型，map必须要指定排序规则，同set容器





## 函数对象

#### 函数对象

概念：

- 重载函数调用操作符的类，其对象常称为函数对象
- 函数对象使用重载的()时，行为类似函数调用，也叫仿函数

本质：

- 函数对象(仿函数)是一个类，不是一个函数

特点：

- 函数对象在使用时，可以像普通函数那样调用，可以有参数，可以有返回值
- 函数对象超出普通函数的概念，函数对象可以有自己的状态
- 函数对象可以作为参数传递

总结：

- 仿函数写法非常灵活，可以作为参数进行传递



#### 谓词

概念：

- 返回bool类型的仿函数称为谓词
- 如果operator()接受一个参数，那么叫做一元谓词
- 如果operator()接受两个参数，那么叫做二元谓词



#### 内建函数对象

概念：

- STL内建了一些函数对象

分类：

- 算术仿函数
- 关系仿函数
- 逻辑仿函数

用法：

- 这些仿函数所产生的对象，用法和一般函数完全相同
- 使用内建函数对象，需要引入头文件`#include <functional>`



#### 算术仿函数

功能描述：

- 实现四则运算
- 其中negate是一元运算，其他都是二元运算

仿函数原型：

```c++
template<class T> T plus<T>  // 加法仿函数
template<class T> T minus<T>  // 减法仿函数
template<class T> T multiplies<T>  // 乘法仿函数
template<class T> T divides<T>  // 除法仿函数
template<class T> T modulus<T>  // 取模仿函数
template<class T> T negate<T>  // 取反仿函数
```

总结：

- 使用内建函数对象时，需要引入头文件`#include <functional>`



#### 关系仿函数

功能描述：

- 实现关系对比

仿函数原型：

```c++
template<class T> bool equal_to<T>  // 等于
template<class T> bool not_equal_to<T>  // 不等于
template<class T> bool greater<T>  // 大于
template<class T> bool greater_equal<T>  // 大于等于
template<class T> bool less<T>  // 小于
template<class T> bool less_equal<T>  // 小于等于
```

总结：

- 关系仿函数中最常用的就是greater<>大于



#### 逻辑仿函数

功能描述：

- 实现逻辑运算

仿函数原型：

```c++
template<class T> bool logical_and<T>  // 逻辑与
template<class T> bool logical_or<T>  // 逻辑或
template<class T> bool logical_not<T>  // 逻辑非
```

总结：

- 逻辑仿函数实际应用较少，了解即可





## 常用算法

概述：

- 算法主要是由头文件<algorithm>、<functional>、<numeric>组成
- <algorithm>是所有STL头文件中最大的一个，范围涉及到比较、交换、查找、遍历操作、复制、修改等等
- <numeric>体积很小，只包括几个在序列上面进行简单数学运算的模板函数
- <functional>定义了一些模板类，用以声明函数对象





## 常用遍历算法

学习目标：

- 掌握常用的遍历算法

算法简介：

```c++
for_each  // 遍历容器
transform  // 搬运容器到另一个容器中
```



#### for_each

功能描述：

- 实现遍历容器

函数原型：

```c++
for_each(iterator beg, iterator end, _func);  // 遍历算法 - 遍历容器
											  // beg - 开始迭代器，end - 结束迭代器，_func - 函数或者函数对象
```

总结：

- for_each在实际开发中是最常用的遍历算法，需要熟练掌握



#### transform

功能描述：

- 搬运一个容器到另一个容器中

函数原型：

```c++
transform(iterator beg1, iterator end1, iterator beg2, _func);  // beg1 - 源容器开始迭代器
																// end1 - 源容器结束迭代器
																// beg2 - 目标容器开始迭代器
																// _func - 函数或者函数对象
```

总结：

- 搬运的目标容器必须要提前开辟空间，否则无法正常搬运





## 常用查找算法

学习目标：

- 掌握常用的查找算法

算法简介：

```c++
find  // 查找元素
find_if  // 按条件查找元素
adjacent_find  // 查找相邻重复元素
binary_search  // 二分查找法
count  // 统计元素个数
count_if  // 按条件统计元素个数
```



#### find

功能描述：

- 查找指定元素，找到返回指定元素的迭代器，找不到返回结束迭代器end()

函数原型：

```c++
find(iterator beg, iterator end, value);  // 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
										  // beg - 开始迭代器，end - 结束迭代器，value - 查找的元素
```

总结：

- 利用find可以在容器中找指定的元素，返回值是迭代器



#### find_if

功能描述：

- 按条件查找元素

函数原型：

```c++
find_if(iterator beg, iterator end, _Pred);  // 按条件查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
											 // beg - 开始迭代器，end - 结束迭代器，_Pred - 函数或者谓词(返回bool类型的仿函数)
```



#### adjacent_find

功能描述：

- 查找相邻重复元素

函数原型：

```c++
adjacent_find(iterator beg, iterator end);  // 查找相邻重复元素，返回相邻元素的第一个位置的迭代器
											// beg - 开始迭代器，end - 结束迭代器
```

总结：

- 面试题中如果出现查找相邻重复元素，记得用STL中的adjacent_find算法



#### binary_search

功能描述：

- 查找指定元素是否存在

函数原型：

```c++
bool binary_search(iterator beg, iterator end, value);  // 查找指定的元素，查到返回true，否则false
														// 注意：在无序序列中不可用
														// beg - 开始迭代器，end - 结束迭代器，value - 查找的元素
```

总结：

- 二分查找法查找效率很高，值得注意的是查找的容器中元素必须为有序序列



#### count

功能描述：

- 统计元素个数

函数原型：

```c++
count(iterator beg, iterator end, value);  // 统计元素出现次数
										   // beg - 开始迭代器，end - 结束迭代器，value - 统计的元素
```

总结：

- 统计自定义数据类型时候，需要配合重载operator==



#### count_if

功能描述：

- 按条件统计元素个数

函数原型：

```c++
count_if(iterator beg, iterator end, _Pred);  // 按条件统计元素出现次数
											  // beg - 开始迭代器，end - 结束迭代器，_Pred - 谓词
```





## 常用排序算法

学习目标：

- 掌握常用的排序算法

算法简介：

```c++
sort  // 对容器内元素进行排序
random_shuffle  // 洗牌，指定范围内的元素随机调整次序
merge  // 容器元素合并，并存储到另一个容器中
reverse  // 反转指定范围的元素
```



#### sort

功能描述：

- 对容器内元素进行排序

函数原型：

```c++
sort(iterator beg, iterator end, _Pred);  // 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
										  // beg - 开始迭代器，end - 结束迭代器，_Pred - 谓词
```

总结：

- sort属于开发中最常用的算法之一，需熟练掌握



#### random_shuffle

功能描述：

- 洗牌，指定范围内的元素随机调整次序

函数原型：

```c++
random_shuffle(iterator beg, iterator end)  // 指定范围内的元素随机调整次序，beg - 开始迭代器，end - 结束迭代器
```

总结：

- random_shuffle洗牌算法比较实用，使用时记得加随机数种子



#### merge

功能描述：

- 两个容器元素合并，并存储到另一容器中

函数原型：

```c++
merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
// 注意：两个容器必须是有序的，返回容器也是有序的
// beg1 - 容器1开始迭代器，end1 - 容器1结束迭代器，beg2 - 容器2开始迭代器，end2 - 容器2结束迭代器
// dest - 目标容器开始迭代器
```

总结：

- merge合并的两个容器必须是有序序列



#### reverse

功能描述：

- 将容器内元素进行反转

函数原型：

```c++
reverse(iterator beg, iterator end);  // 反转指定范围的元素，beg - 开始迭代器，end - 结束迭代器
```

总结：

- reverse反转区间内元素，面试题可能涉及到





## 常用拷贝和替换算法

学习目标：

- 掌握常用的拷贝和替换算法

算法简介：

```c++
copy  // 容器内指定范围的元素拷贝到另一容器中
replace  // 将容器内指定范围的旧元素修改为新元素
replace_if  // 容器内指定范围满足条件的元素替换为新元素
swap  // 互换两个容器的元素
```



#### copy

功能描述：

- 容器内指定范围的元素拷贝到另一容器中

函数原型：

```c++
copy(iterator beg, iterator end, iterator dest);  // beg - 开始迭代器，end - 结束迭代器，dest - 目标起始迭代器
```

总结：

- 利用copy算法在拷贝时，目标容器记得提前开辟空间



#### replace

功能描述：

- 将容器内指定范围的旧元素修改为新元素

函数原型：

```c++
replace(iterator beg, iterator end, oldvalue, newvalue);  // 将区间内旧元素替换为新元素
														  // beg - 开始迭代器，end - 结束迭代器
														  // oldvalue - 旧元素，newvalue - 新元素
```

总结：

- replace会替换区间内满足条件的元素



#### replace_if

功能描述：

- 将区间内满足条件的元素替换成指定元素

函数原型：

```c++
replace_if(iterator beg, iterator end, _pred, newvalue);  // 按条件替换元素，满足条件的替换成指定元素
														  // beg - 开始迭代器，end - 结束迭代器
														  // _pred - 谓词，newvalue - 替换的新元素
```

总结：

- replace_if按条件查找，可以利用仿函数灵活筛选满足的条件



#### swap

功能描述：

- 互换两个容器的元素

函数原型：

```c++
swap(container c1, container c2);  // 互换两个容器的元素，c1 - 容器1，c2 - 容器2
```

总结：

- swap交换容器时，注意交换的容器要同种类型





## 常用算术生成算法

学习目标：

- 掌握常用的算术生成算法

注意：

- 算术生成算法属于小型算法，使用时包含的头文件为`#include <numeric>`

算法简介：

```c++
accumulate  // 计算容器元素累计总和
fill  // 向容器中添加元素
```



#### accumulate

功能描述：

- 计算区间内容器元素累计总和

函数原型：

```c++
accumulate(iterator beg, iterator end, value);  // 计算容器元素累计总和
												// beg - 开始迭代器，end - 结束迭代器，value - 起始值
```

总结：

- acculturate使用时头文件注意是numeric，这个算法很实用



#### fill

功能描述：

- 向容器中填充指定的元素

函数原型：

```c++
fill(iterator beg, iterator end, value);  // 向容器中填充元素
										  // beg - 开始迭代器，end - 结束迭代器，value - 填充的值
```

总结：

- 利用fill可以将容器区间内元素填充为指定的值





## 常用集合算法

学习目标：

- 掌握常用的集合算法

算法简介：

```c++
set_intersection  // 求两个容器的交集
set_union  // 求两个容器的并集
set_difference  // 求两个容器的差集
```



#### set_intersection

功能描述：

- 求两个容器的交集

函数原型：

```c++
set_intersection(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
// 求两个集合的交集，注意：两个集合必须是有序序列
// beg1 - 容器1开始迭代器，end1 - 容器1结束迭代器，beg2 - 容器2开始迭代器，end2 - 容器2结束迭代器
// dest - 目标容器开始迭代器
```

总结：

- 求交集的两个集合必须是有序序列
- 目标容器开辟空间需要从两个容器中取较小值
- set_intersection返回值即是交集中最后一个元素的位置



#### set_union

功能描述：

- 求两个容器的并集

函数原型：

```c++
set_union(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
// 求两个集合的并集，注意：两个集合必须是有序序列
// beg1 - 容器1开始迭代器，end1 - 容器1结束迭代器，beg2 - 容器2开始迭代器，end2 - 容器2结束迭代器
// dest - 目标容器开始迭代器
```

总结：

- 求并集的两个集合必须是有序序列
- 目标容器开辟空间需要两个容器相加
- set_union返回值即是并集中最后一个元素的位置



#### set_difference

功能描述：

- 求两个集合的差集

函数原型：

```c++
set_difference(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
// 求两个集合的差集，注意：两个集合必须是有序序列
// beg1 - 容器1开始迭代器，end1 - 容器1结束迭代器，beg2 - 容器2开始迭代器，end2 - 容器2结束迭代器
// dest - 目标容器开始迭代器
```

总结：

- 求差集的两个集合必须是有序序列
- 目标容器开辟空间需要从两个容器中取较大值
- set_difference返回值即是差集中最后一个元素的位置

# C++ STL 的常见用法
## C++中常用的头文件库&相应的函数
### 输出、输出
```C++
#include <iostream>
#include <cstdio>
//printf()
#include <sstream>
//ostringstream os; os << num; os.srt();
#include <iomanip>
//cout << fixed << setpercision(2)
```

### algorithm
```C++
#include <cmath>
// absf(); asin(); sin();
// fill(); max(); min(); abs();


#include <algorithm>

排序：
sort(myvector.begin(), myvector.begin()+4); 
bool myfunction (int i,int j) { return (i < j); }
sort(myvector.begin(), myvector.end(), compFunc); // 升序排序

容器搜索：
获取容器中最大值最小值：
/**
template <class ForwardIterator>
ForwardIterator max_element (ForwardIterator first, ForwardIterator last);

template <class ForwardIterator, class Compare>
ForwardIterator max_element (ForwardIterator first, ForwardIterator last,
                            Compare comp);
 * **/
*std::min_element(myints,myints+7); // 最小值
max_element()
自定义比较函数：


// reverse(); 
//make_heap(vector.begin(), vector.end()), pop_heap(..., ...);

其他常用：
std::accmulate(wall[0].begin(), wall[0].end(), 0); // 累加函数
```

### STL
#### 有序容器
在STL中，一般而言：
- empty() 函数用于判断当前容器中是否为空, clear()一般用于清空容器中的内容
- size()
- 查询函数的返回结果为迭代器类型，如果未查询到则对应end位置的迭代器。如果想要获取到迭代器对应元素的下标，在 It - begin()
- std::find()

```C++
// https://www.runoob.com/w3cnote/cpp-vector-container-analysis.html
#include <vector>
初始化：
vector<int> myVector(5); vector<int> myVector(5, 0); vector<int> myVector = { }; 
vector(begin,end);
//定义二维动态数组 N行 M列 
vector<vector<int> > obj(N, vector<int>(M)); 
obj = vector<vector<int> >(M, vector<int>(N))
traveled = new vector<vector<bool> >(M, vector<bool>(N, 0)); // M*N 的初始值均为 0 的二维数组
迭代器：
begin()/end(), rbegin()/rend(), cbegin()/cend(), crbegin()/crend()
增:
push_back() , insert()
删：
pop_back(), erase(), clear()
改：
myVector[i] = value
查：
front(), back(), at()
find() // 函数范围值为迭代器类型，如果没有查询到相关元素返回值为 container.end()

#include <list>
//list<int>
增:
push_back() , insert()
删：
pop_back(), pop_front(), erase(), clear()


#include <queue>
常用方法：
增： push()
删： pop()
查： front(), back(), size(), empty()

#include <deque>
deque更为实用一点, 相比 queue 其支持迭代器
增：push_back(), push_front(), insert()
删：pop_back(), pop_front() // 注意 pop_ 函数的返回值为空，通过 front() 来获取
查：operator[], at(), front(), back()

#include <stack>
// stack<int>
push()
top(), pop()

```
#### 无序容器
```C++
集合：
#include <set>

字典：
#include <map> // STL中的map就是字典，key通过hash方法进行索引
初始化：
std::map<char,int> mymap; mymap['a']=101;
插：
map.insert(make_pair(key, value)); // key，value的访问，pair -> first, pair -> second
查询：
map.find(key) == map.end;



#include <unorder_set> //元素位置基于hash值决定
常用方法（与STL其他容器的使用方法类似）：insert(), erase(), find(),
count() //
#include <unorder_map> // key-value

哈希表：数据的查询时间为 O(1) ， 最坏情况下为 O(n). unordered_set 和 unordered_map 的操作方式都和普通的 set 和 map 类似。这两者的只有正向迭代方法 begin()/cbegin()。在内部，unordered_set 中的元素未按任何特定顺序排序，而是根据它们的哈希值组织为存储桶，以允许直接通过它们的值快速访问各个元素（平均具有常数平均时间复杂度）。

在 STL 中 map 和
```

### 其他
#### 字符串
```C++
// http://c.biancheng.net/view/400.html
#include <string>
初始化：
常用方法：
size()
find(), string::npos; 
substr(int a, int b); // 字符串截取
replace() // 替换
string 类有一些查找子串和字符的成员函数，它们的返回值都是子串或字符在 string 对象字符串中的位置（即下标）。如果查不到，则返回 string::npos。
// 字符串按照空格划分

其他数值类型 <=>字符串
std::to_string() // C++11中新增的函数，将整数、浮点数转化为 string 对象
std::atoi(const char* str); // string::c_str() 将 string 类型转化为 C 风格的 char*
// atol() atof() strtol()

#include <cstring>
// strtok();

#define _MAX 21e+8
#define _MIN -21e+8
```

## 常见的使用错误
- C++11 中增添了foreach的特性，注意要对遍历元素的值进行修改需要是对元素的引用或者指针。
- STL deque容器中的 pop_front() pop_back() 范围值为void, 通过 front() 和 back() 来访问值
- 声明多个相同类型的指针时，正确的声明方式是：`TreeNode *p_x, *p_y;` 而不是 `TreeNode* p_x, p_y ;` !!!! 
- `INT_MAX` `INT_MIN` 在标准头文件limits.h中定义 
    ```C++
    #define INT_MAX 2147483647 // 2^31
    #define INT_MIN (-INT_MAX - 1)
    ```
- C++ STL中 map 和 unordered_map 之间的区别？ map 在内部实现上实际上是一种有序容器
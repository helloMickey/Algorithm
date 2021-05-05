# 说明
刷过的算法题：
- leetcode
- nowcoder
- fudan
- PAT
- lc-cn(leetcode-cn) 

easy难度的题目基本直接跳过；

有部分的还存在问题....没有实现或甚至编译错误。


# 笔记部分
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
#include <algorithm>

排序：
sort(myvector.begin(), myvector.begin()+4); 
bool myfunction (int i,int j) { return (i<j); }
sort(myvector.begin(), myvector.end(), compFunc); // 升序排序

reverse(); fill(); max(); min(); abs();
//make_heap(vector.begin(), vector.end()), pop_heap(..., ...);
```

### STL
```C++
// https://www.runoob.com/w3cnote/cpp-vector-container-analysis.html
#include <vector>
初始化：
vector<int> myVector(5); vector<int> myVector(5, 0); vector<int> myVector = { }; 
vector(begin,end): 
vector<vector<int> > obj(N, vector<int>(M)); //定义二维动态数组 N行 M列 
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

#include <list>
//list<int>
#include <queue>
//queue<int>; deque<int>
#include <stack>
// stack<int>
#include <map>
//map.insert(make_pair(key, value)); map.find(key) == map.end;
#include <set>


// http://c.biancheng.net/view/400.html
#include <string>
初始化：
常用方法：
find(), string::npos; 
substr(int a, int b); // 字符串截取
replace() // 替换
string 类有一些查找子串和字符的成员函数，它们的返回值都是子串或字符在 string 对象字符串中的位置（即下标）。如果查不到，则返回 string::npos。
// 字符串按照空格划分


#include <cstring>
// strtok();

#define _MAX 21e+8
#define _MIN -21e+8
```

## 常见的使用错误

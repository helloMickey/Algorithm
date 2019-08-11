#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <set>
#include <list>
#include <map>
using namespace std;

struct ListNode
{
	int data;
	ListNode* next;
	ListNode(int x = 0) :data(x), next(nullptr) {};
};
struct TreeNode
{
	int data;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x = 0) :data(x), left(nullptr) , right(nullptr){};
};

void string_test() {

	char* str = "chen";
	const char *str_p;
	string s = "string";
	//string to char *
	str_p = s.c_str();
	int c = stoi(s);

	cout << str_p << endl;
}

void io_test() {
	string path = "data.txt";
	//ios::app; ios::
	std::fstream file(path, ios::app|ios::in|ios::out);
	//for (int i = 1; i < 11; i++)
	//{
	//	openfile << " " << i;
	//}
	//openfile.close();
	
	fstream inf(path, ios::in);

	if (!inf.is_open())
	{
	std::cout << "Error opening file";
	}
	string s;
	while (inf>> s)
	{
		cout << s << endl;
	}
	//while (!file.eof())
	//{

	//	//char d[256];
	//	//inf.getline(d, 100);
	//	string line;
	//	file >> line;
	//	//file.getline(line, 10);
	//	cout << line << std::endl;
	//}
	file.close();
}

void data_struct(){
	stack<int> stk;
	stk.push(1);
	int r = stk.top();
	stk.pop();

	//cout << r << endl;

	queue <int> q;
	q.push(11);
	//cout << q.front() << endl;
	q.pop();

	vector<int> v, v2;
	v.push_back(10);
	v.push_back(2);
	v.push_back(5);
	v.push_back(23);
	//v.pop_back();
	//sort(v.begin(), v.end());
	v.erase(v.begin(), v.begin() + 2);
	
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		//cout << *it << endl;
	}
	//cout << v[0] << endl;

	set<int> myset;
	myset.insert(10);
	myset.insert(10);
	myset.insert(15);
	myset.insert(15);
	myset.insert(15);
	set<int>::iterator i =  myset.find(15);
	cout << myset.size() << endl;
	/*if (i == myset.end())
	{
		cout << "not find!!" << endl;
	}
	else {
		for (set<int>::iterator it = i; it != myset.end(); it++) {
			cout << *it << endl;
		}
	}*/

	map<string, int> mymap;
	string name = "chen";
	mymap.insert(pair<string, int>(name, 111));
	mymap.insert(pair<string, int>(name, 99));
	mymap.insert(pair<string, int>(name, 100));
	mymap[name] = 4;
	//cout << mymap[name] << endl;
	mymap.erase(mymap.find("chen"));
	//cout << mymap.size() << endl;


}

int main()
{
	//io_test();
	//data_struct();
	const string str = "12.4";
	istringstream is_str(str);
	int num;
	is_str >> num;
	cout << num;
	system("pause");
}

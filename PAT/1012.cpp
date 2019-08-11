#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

struct Student
{
    string ID;
    int C;
    int E;
    int M;
    int A;
    Student(string id, int c, int e, int m) : ID(id), C(c), E(e), M(m), A((c + e + m) / 3){};
};
struct Rank
{
    int rank;
    char flag;
    Rank(int i, char f) : rank(i), flag(f){};
};
//降序
bool compare_C(Student a, Student b)
{
    return a.C > b.C;
}
//降序
bool compare_M(Student a, Student b)
{
    return a.M > b.M;
}
//降序
bool compare_E(Student a, Student b)
{
    return a.E > b.E;
}
//降序
bool compare_A(Student a, Student b)
{
    return a.A > b.A;
}
void sort_fun(vector<Student> &s_l, char flag)
{
    switch (flag)
    {
    case 'C':
        sort(s_l.begin(), s_l.end(), compare_C);
        break;
    case 'E':
        sort(s_l.begin(), s_l.end(), compare_E);
        break;
    case 'M':
        sort(s_l.begin(), s_l.end(), compare_M);
        break;
    case 'A':
        sort(s_l.begin(), s_l.end(), compare_A);
        break;
    }
}
void fun1012()
{
    map<string, Student> student_map;
    int N, M;
    cin >> N >> M;
    vector<Student> student_list;
    int temp_M = M;
    while (N--)
    {
        string id;
        int c, e, m;

        cin >> id >> c >> e >> m;
        student_list.push_back(Student(id, c, e, m));
    }
    vector<string> search_list;
    while (M--)
    {
        string id;
        cin >> id;
        search_list.push_back(id);
    }
    vector<Student> s_C;
    s_C.assign(student_list.begin(), student_list.end());
    vector<Student> s_E(student_list);
    s_E.assign(student_list.begin(), student_list.end());
    vector<Student> s_M(student_list);
    s_M.assign(student_list.begin(), student_list.end());
    vector<Student> s_A(student_list);
    s_A.assign(student_list.begin(), student_list.end());

    sort_fun(s_C, 'C');
    sort_fun(s_E, 'E');
    sort_fun(s_M, 'M');
    sort_fun(s_A, 'A');
    map<string, Rank> rank;
    for (int i = 0; i < student_list.size(); i++)
    {
        // A > C > M > E
        rank.insert(pair<string, Rank>(s_A[i].ID, Rank(i+1, 'A')));
        rank.insert(pair<string, Rank>(s_C[i].ID, Rank(i+1, 'C')));
        rank.insert(pair<string, Rank>(s_M[i].ID, Rank(i+1, 'M')));
        rank.insert(pair<string, Rank>(s_E[i].ID, Rank(i+1, 'E')));
    }

    for (int i = 0; ; )
    {
        string id = search_list[i];
        map<string, Rank>::iterator f = rank.find(id);
        if (f == rank.end())
        { //没有该学生的ID
            cout << "N/A";
        }
        else
        {
            cout << f->second.rank << " " << f->second.flag ;
        }
        //确保最后一行输出时不换行
        i++;
        if (i < search_list.size()) {
            cout << endl;
        }else
        {
            break;
        }
    }
}
bool compare(int a, int b)
{
    //return a > b; //降序
    return a < b; //升序
}
int main()
{
    fun1012();
}

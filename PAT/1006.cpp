#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

struct Record{
    string id;
    string come;
    string out;
    Record(string i, string c, string o):id(i), come(c), out(o){};
};
// a < b ?
//来的越早越靠前
bool compareCome(Record a, Record b){
    string astr = a.come,  bstr = b.come;
    for(int i = 0; i < astr.size(); i++)
        if (astr[i] != bstr[i]) {
            return astr[i] < bstr[i];
        }
    return false;
}
//走的越晚越靠前
bool compareOut(Record a, Record b){
    string astr = a.out,  bstr = b.out;
    for(int i = 0; i < astr.size(); i++)
        if (astr[i] != bstr[i]) {
            return astr[i] > bstr[i];
        }
    return false;
}
int main(){
    int lns;
    cin >> lns;
    //std::cin.getline();//读回车
    vector<Record> list;
    while(lns--){
    	string id, come, out;
		cin >> id >> come >> out;
		//cin.getline()
		list.push_back(Record(id, come, out));
    }
    sort(list.begin(), list.end(),compareCome);
    string firstComeID = list[0].id;
    sort(list.begin(), list.end(),compareOut);
    string lastOutID = list[0].id;
    cout << firstComeID << " " << lastOutID;
}

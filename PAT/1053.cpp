#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

bool compare_vector(vector<int> a, vector<int> b){
	for(int i = 0; i < a.size() && i < b.size(); i++){
		if (a[i] > b[i]){
			return true;
		}else if(a[i] == b[i])
			continue;
		else
			return false;
	}
	return false;
}
int *node_wight;
map<int, vector<int> > inner_node_list;
vector<vector<int> > DFS(int path, int root){
	vector<vector<int> > path_lists;
	int root_wight = node_wight[root];
	if (root_wight == path && (inner_node_list.find(root) == inner_node_list.end())){//ΪҶ�ڵ㲢��·������
		vector<int> pl; pl.push_back(root_wight);
		path_lists.push_back(pl);
		return path_lists;//����{{*root}}
	}else if(inner_node_list.find(root) == inner_node_list.end()){//ΪҶ�ڵ�,��·����������
		return path_lists;
	}
	//��ΪҶ����
	//����ÿһ��child���б���
	vector<int> child_list = inner_node_list.find(root)->second;
	vector<int>::iterator it = child_list.begin();
	for(; it != child_list.end(); it++){
		//int child_wight = node_wight[(*it)];
		vector<vector<int> > temp = DFS(path - root_wight , *it);
		if(temp.size() != 0)
		{
			vector<int> single;
			for(int i = 0; i<temp.size();i++){
				single = temp[i];
				single.insert(single.begin(), root_wight);//��ǰ�����root��Ȩ��
				path_lists.push_back(single);//����·������
			}
		}
	}
	return path_lists;
}
void fun1053(){
	int inner_nodes;
	int nodes, path;
	cin >> nodes >> inner_nodes >> path;

	node_wight = new int[nodes];

	int temp = nodes;int count =0;
	while(temp--){
		int w; cin >> w;
		node_wight[count++] = w;
	}
	temp = inner_nodes;
	while(temp--){
		int node_id, node_childs, child_id;
		cin >> node_id >> node_childs;
		vector<int> child_list;
		while(node_childs--){
			cin >> child_id;
			child_list.push_back(child_id);
		}
		inner_node_list.insert(::make_pair(node_id,child_list));
	}
	//�����Ǵ�00��ʼ
	vector<vector<int> >result_paths = DFS(path, 0);
	//������ĿҪ����������
	::sort(result_paths.begin(), result_paths.end(), compare_vector);

	for(int i = 0;;)
	{
		for(int j = 0; ;)
		{
			cout << result_paths[i][j];
			//ÿ�����Ҫ����ո�
			j++;
			if(j < result_paths[i].size())
				cout << " ";
			else
				break;
		}
		//���һ�в�Ҫ�س�
		i++;
		if(i < result_paths.size())
			cout << endl;
		else
			break;
	}
}
//int main(){
//	fun1053();
//}

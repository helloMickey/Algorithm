#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct Node {
	int id;
	Node* left;
	Node* right;
	Node(int n) :id(n), left(nullptr), right(nullptr) {}
};
vector<int> post_order;
vector<int> in_order;
//由后序、中序构建树
Node* build_tree(int p_l, int p_h, int i_l, int i_h) {
	if (p_l > p_h || i_l > i_h) return nullptr;

	int root_id = post_order[p_h];
	Node* root = new Node(root_id);
	//对中序序列进行划分
	int divide_pos = 0;
	for (vector<int>::iterator it = in_order.begin(); it != in_order.end(); it++)
	{
		if ((*it) != root_id)
			divide_pos++;
		else
			break;
	}
	int len_left = divide_pos - i_l;
	int len_right = i_h - i_l - len_left;

	root->left = build_tree(p_l, p_l + len_left - 1, i_l, divide_pos - 1);
	root->right = build_tree(p_h - len_right, p_h - 1, divide_pos + 1, i_h);

	return root;
}
queue<Node*> q;
vector<int> result;
void layer_travel(Node* root) {
	q.push(root);
	while (!q.empty()) {
		Node* cur = q.front(); q.pop();
		result.push_back(cur->id);
		if ((cur->left) != nullptr)
			q.push(cur->left);
		if ((cur->right) != nullptr)
			q.push(cur->right);
	}
	int i;
	for (i = 0; i< (result.size() - 1); i++)
		cout << result[i] << " ";
	cout << result[i];

}
void fun1020() {
	int n;
	cin >> n;
	int temp = n, id;
	//post_order
	while (temp--)
	{
		cin >> id;
		post_order.push_back(id);
	}
	temp = n;
	while (temp--)
	{
		cin >> id;
		in_order.push_back(id);
	}
	Node* tree = build_tree(0, n - 1, 0, n - 1);
	layer_travel(tree);
}
//int main()
//{
//	//Node *tree = new Node(1);
//	//tree->right = new Node(3);
//	//tree->right->left = new Node(2);
//	fun1020();
//	//layer_travel(tree);
//	//system("pause");
//}
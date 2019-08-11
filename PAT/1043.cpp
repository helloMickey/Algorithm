#include<iostream>
#include<vector>
using namespace std;
struct Node{
	int id;
	Node* left;
	Node* right;
	Node(int n):id(n), left(nullptr), right(nullptr){}
};
vector<int> r;
vector<int> input;
vector<int> inorder;
void tracel_inOrder(Node* root)
{
	if(root == nullptr) return;
	tracel_inOrder(root->left);
	inorder.push_back(root->id);
	tracel_inOrder(root->right);
}
void travel_postOrder(Node* root)
{
	if(root == nullptr) return;
	travel_postOrder(root->left);
	travel_postOrder(root->right);
	r.push_back(root->id);
}
//������������Ķ���������
Node* build_tree(int L, int H){
	if(L > H) return nullptr;
	int root_id = input[L];
	Node* root = new Node(root_id);
	int index_pos = L;//index_pos���С��root�ı߽�
	for(int i = L +1; i <= H; i++)
	{
		if(input[i] < root_id)
			index_pos++;
		else
			break;
	}
	root->left = build_tree(L+1, index_pos);//С����Ϊ������
	root->right  = build_tree(index_pos+1, H);//�����Ϊ������
	return root;
}
//��������ݼ��Ķ���������
Node* build_tree_r(int L, int H){
	if(L > H) return nullptr;
	int root_id = input[L];
	Node* root = new Node(root_id);

	int index_pos = L;//index_pos��Ǵ��ڵ���root�ı߽�
	for(int i = L +1; i <= H; i++)
	{
		if(input[i] >= root_id)
			index_pos++;
		else
			break;
	}
	root->left = build_tree_r(L+1, index_pos);//�����Ϊ������
	root->right  = build_tree_r(index_pos+1, H);//С����Ϊ������
	return root;
}
//�ж�һ�����Ƿ�Ϊ����������
bool isBST(Node* root){
	if(!inorder.empty())
		inorder.clear();
	//�������
	tracel_inOrder(root);
	//�жϱ��������Ƿ����
	bool incre_order = true;
	int pre = inorder[0];
	for(int i = 1; i<inorder.size(); i++)
	{
		if(inorder[i] < pre)//����ı�ǰ��С
			incre_order = false;
		pre = inorder[i];
	}
	//�жϱ��������Ƿ�ݼ�
	bool descre_order = true;
	pre = inorder[0];
	for(int i = 1; i<inorder.size(); i++)
	{
		if(inorder[i] > pre)//����ı�ǰ���
			descre_order = false;
		pre = inorder[i];
	}
	return (incre_order || descre_order);
}
void fun1043(){
	Node* root;
	Node* root_m;

	int n;
	cin >> n;
	int temp = n;
	while(temp--){
		int node;
		cin >> node;
		input.push_back(node);
	}
	Node* tree  = build_tree(0, n-1);
	Node* tree_r = build_tree_r(0, n-1);

	if(isBST(tree))
	{
		//��������
		travel_postOrder(tree);
		cout << "YES" <<endl;
		//����������
		int i;
		for( i = 0; i< (r.size() - 1); i++)
			cout <<r[i] << " ";
		cout << r[i];
		return;
	}else if(isBST(tree_r)){
		//��������
		travel_postOrder(tree_r);
		cout << "YES" <<endl;
		//����������
		int i;
		for( i = 0; i< (r.size() - 1); i++)
			cout <<r[i] << " ";
		cout << r[i];
		return;
	}else
		cout<<"NO";
}
//int main()
//{
//	fun1043();
//}
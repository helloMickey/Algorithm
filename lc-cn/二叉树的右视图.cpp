// https://leetcode-cn.com/problems/binary-tree-right-side-view/

/*
方法1：层次序遍历（广度优先遍历），记录每层的最右端元素

方法2：深度优先遍历，在搜索过程中，我们总是先访问右子树。
那么对于每一层来说，我们在这层见到的第一个结点一定是最右边的结点。
可以存储在每个深度访问的第一个结点。
*/

vector<int> rightSideView(TreeNode* root) {
	vector<int> res;
	if (!root) return res;
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty())
	{
		int size = q.size(); // 当前队列长度，就是下一层的节点个数
		res.push_back(q.front()->val);
		while (size--)
		{
			TreeNode* temp = q.front();
			q.pop();
			if (temp->right) q.push(temp->right);
			if (temp->left) q.push(temp->left);
		}
	}
	return res;
}
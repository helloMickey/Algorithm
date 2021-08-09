// https://leetcode-cn.com/problems/house-robber-iii/

/*
https://leetcode-cn.com/problems/house-robber-iii/solution/da-jia-jie-she-iii-by-leetcode-solution/

题解给出的思路更为清晰 ！！！
*/

struct hashfunc { // 自定义key的hash，函数
	template<typename T, typename U>
	size_t operator()(const pair<T, U> &key) const {
		return hash<T>()(key.first);
	}
};
class Solution { //暴力搜索： 部分测试用例超时 ！ => 打表优化
    
    unordered_map<pair<TreeNode*, int>, int, hashfunc> tlb;
public:
    int _rob(TreeNode* root, bool root_select){
        // root_select 表示当前 root 节点是否被偷
        if(root == nullptr) return 0;
        
        auto key = make_pair(root, root_select);
        if(tlb.find(key) != tlb.end()) return tlb[key];

        int result;
        if(root_select){
            result = root->val + _rob(root->left, false) + _rob(root->right, false);
        }else{
            // 当前节点不投时，其子女有多种可选情况
            int res[] ={
                _rob(root->left, false) + _rob(root->right, false), // 子女都不偷
                _rob(root->left, false) + _rob(root->right, true), // 偷右
                _rob(root->left, true) + _rob(root->right, false), // 偷左
                _rob(root->left, true) + _rob(root->right, true) // 都偷
            };
            result = *max_element(res, res + 4);
        }
        tlb[key] = result;
        return result;
    }

    int rob(TreeNode* root) {
        if(!root) return 0;

        return max(
            _rob(root, true),
            _rob(root, false)
         );
    }
};
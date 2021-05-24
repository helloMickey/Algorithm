// https://leetcode-cn.com/problems/shu-de-zi-jie-gou-lcof/

/*
最直接想法：
遍历树A和树B，判断树B的遍历结果是不是树A遍历结果的字串

=》可以直接在递归遍历A的同时，判断当前节点的子树是否与树B匹配。
*/

class Solution {
public:
    bool equal(TreeNode *A, TreeNode *B){ // 从头节点开始，B中的值能匹配到A上
        if(B == nullptr) return true; // !!!! 考虑 [3,4,5,1,2] [4,1] 的情况
        if(A == nullptr) return false; //一个为空，另一个不为空

        return A->val == B->val && equal(A->left, B->left) && equal(A->right, B->right);
    }

    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(A==nullptr || B == nullptr) return false;
        return equal(A, B) || isSubStructure(A->left, B) ||  isSubStructure(A->right, B);
    }
};
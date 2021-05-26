// https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof/solution/

/*
递归解析：
    终止条件： 当 i \geq ji≥j ，说明此子树节点数量 \leq 1≤1 ，无需判别正确性，因此直接返回 truetrue ；
    递推工作：
        划分左右子树： 遍历后序遍历的 [i, j][i,j] 区间元素，寻找 第一个大于根节点 的节点，索引记为 mm 。此时，可划分出左子树区间 [i,m-1][i,m−1] 、右子树区间 [m, j - 1][m,j−1] 、根节点索引 jj 。
        判断是否为二叉搜索树：
        左子树区间 [i, m - 1] 内的所有节点都应 < postorder[j] 。而第 1.划分左右子树 步骤已经保证左子树区间的正确性，因此只需要判断右子树区间即可。
        右子树区间 [m, j - 1] 内的所有节点都应 > postorder[j] 。实现方式为遍历，当遇到 ≤ postorder[j] 的节点则跳出；则可通过 p = j 判断是否为二叉搜索树。

作者：jyd
链接：https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof/solution/mian-shi-ti-33-er-cha-sou-suo-shu-de-hou-xu-bian-6/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/


class Solution {
public:
    vector<int> _postorder;
    bool _verify(int i, int j){
        if(i+1 >= j) return true; // 剩余两个元素构建的书一定是二叉搜索树
        
        // 找到左右划分的子区间
        int idx = i;
        while(_postorder[idx] < _postorder[j]) idx++;
        
        // 左子树都小于根, 右子树都大于根
        int temp = idx+1;
        while(temp < j){
            if(_postorder[temp] < _postorder[j]) return false;
            temp++;
        }
        return _verify(i, idx-1) && _verify(idx, j-1);
    }
    bool verifyPostorder(vector<int>& postorder) {
        // 因为二叉搜索树的中序遍历是有序的,后续和前序遍历都是无序的 , 问题转化为，通过给定 中序 + 后序 看能否构成一棵树

        // 最开始的思路有问题，太过于复杂，该问题可以直接通过递归解决~~
        if(postorder.size() <= 2) return true;
        _postorder = postorder;
        return _verify(0, postorder.size()-1);
    }
};
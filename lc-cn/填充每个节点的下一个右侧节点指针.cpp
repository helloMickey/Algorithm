// https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node/

class Solution {
public:
    Node* connect(Node* root) {
        // 二叉树层次序遍历应用
        if(root == nullptr) return root;
        deque<Node*> layer_trv; layer_trv.push_back(root);
        int l_c = 1;

        // 层次遍历
        while(!layer_trv.empty()){
            int next_l_c = 0;
            Node* pre = nullptr;
            Node* cur;
            while(l_c--){ // 遍历该层，进行前后链接
                if(pre == nullptr){
                   pre = layer_trv.front(); layer_trv.pop_front();
                   cur = pre;
                }else{
                    cur = layer_trv.front(); layer_trv.pop_front();
                    pre->next = cur;
                }
                
                if(cur->left != nullptr) {
                    layer_trv.push_back(cur->left);
                    next_l_c++;
                }
                if(cur->right != nullptr){
                    layer_trv.push_back(cur->right);
                    next_l_c++;
                } 
                pre = cur;
            }
            l_c = next_l_c;
        }
        return root;
    }
};
// https://leetcode-cn.com/problems/next-greater-element-i/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> num_map; //哈希表，nums2中元素所对应的下一个更大元素的hash表；
        stack<int> s; //借助单调不增栈，完成num_map的记录
        int size = nums1.size();
        vector<int> vec_num; //存储下一个最大值的vector
        
        for(int i = 0;i < nums2.size();++i)
        {
            while(!s.empty() && nums2[i] > s.top())
            {
                num_map[s.top()] = nums2[i];
                s.pop();
            }
            s.push(nums2[i]);
        }
        
        while(!s.empty())
        {
            num_map[s.top()] = -1;
            s.pop();
        }
        
        for(int i = 0;i<size;++i)
        {
            vec_num.push_back(num_map[nums1[i]]);
        }
        
        return vec_num;
    }
};
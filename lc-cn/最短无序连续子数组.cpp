// https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/

    /*
    我的思路：借助栈，找到左右各自第一次出现逆序的情况，并确定逆序的值应该所处的位置，这样最终能够获取左右各自正确的边界

    和官方题解中的思路四类似，但是我的有一些测试用例无法通过
    https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/solution/zui-duan-wu-xu-lian-xu-zi-shu-zu-by-leetcode/

    最佳的解法还是题解中的方法5：
        无序子数组中最小元素的正确位置可以决定左边界，最大元素的正确位置可以决定右边界。
    */

class Solution {
    // 题解方法5
    public:
    int findUnsortedSubarray(vector<int>& nums) {
        int min = INT_MAX, max = INT_MIN;
        bool flag = false;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1])
                flag = true;
            if (flag)
                min = std::min(min, nums[i]);
        }
        flag = false;
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] > nums[i + 1])
                flag = true;
            if (flag)
                max = std::max(max, nums[i]);
        }
        int l, r;
        for (l = 0; l < nums.size(); l++) {
            if (min < nums[l])
                break;
        }
        for (r = nums.size() - 1; r >= 0; r--) {
            if (max > nums[r])
                break;
        }
        return r - l < 0 ? 0 : r - l + 1;
    }
};

class Solution_Error { // 存在一些问题
/*
[2,4,3,5,1] 用例无法通过
    错误的原因在于：找到第一个逆序的确定应该所处的左边界之后就 break 了，应当把遍历至结束的，应为后面还有可能有更小的元素出现
    
*/
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int l = -1; // 需要调整的左边界下标
        stack<int> incs_stk; incs_stk.push(nums[0]);
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < nums[i-1]){
                // 遇到第一个逆序的
                l = i;
                while( i < nums.size() && nums[i] < nums[i-1]){
                    i++;
                }
                if(i == nums.size()) i -= 1;
                else i--;

                while(!incs_stk.empty() && nums[i] < incs_stk.top()){
                    incs_stk.pop();
                    l--;
                }
                break;
            }else{
                incs_stk.push(nums[i]);
            }
        }
        if(l == -1) return 0;

        int r = nums.size(); // 需要调整的右边界下标
        stack<int> decs_stk; decs_stk.push(nums[r - 1]);
        for(int i = r - 2; i >= 0; i--){
            if(nums[i] > nums[i+1]){
                // 遇到第一个逆序的
                r = i;
                while( i >= 0 && nums[i] > nums[i+1]){
                    i--;
                }
                
                if(i == -1) i += 1;
                else i++;

                while(!decs_stk.empty() && nums[i] > decs_stk.top()){
                    decs_stk.pop();
                    r++;
                }
                break;
            }else{
                decs_stk.push(nums[i]);
            }
        }
        // cout << l << " " << r;
        return r-l+1;
    }
};
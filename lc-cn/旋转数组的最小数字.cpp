// https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/

/*
直觉方法：遍历，找当前值大于后一个元素的值

优化：旋转处的位置，一定是其前一个元素的值大于自身值的元素，通过二分法找到该位置

但是要注意重复元素的存在！！！！
*/
// 相同题目：
// https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/
// https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/  中所有整数互不相同，所以无需考虑重复元素的情况

class Solution {
public:
    int minArray(vector<int>& numbers) {
        int low = 0;
        int high = numbers.size() - 1;
        while (low < high) {
            int pivot = low + (high - low) / 2;
            if (numbers[pivot] < numbers[high]) {
                high = pivot;
            }
            else if (numbers[pivot] > numbers[high]) {
                low = pivot + 1;
            }
            else {
                high -= 1;
            }
        }
        return numbers[low];
    }
};

class Solution_old {
public:
    int minArray(vector<int>& numbers) {
        if(numbers.size() == 1) return numbers[0];
        for(auto p = numbers.begin(); (p+1) != numbers.end(); p++){
            if(*p > *(p+1)) return *(p+1);
        }
        return numbers[0];
    }
};
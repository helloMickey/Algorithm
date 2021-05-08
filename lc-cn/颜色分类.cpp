// https://leetcode-cn.com/problems/sort-colors/

// 这种题一般OA测试都不会考的，因为可以用函数库作弊。
class Solution {
public:
    void sortColors(vector<int>& nums) {
       //双指针法
       auto head = nums.begin(), rear = nums.end() - 1; //下一个待插入位置
       auto p = nums.begin();
       int temp;
       while (p <= rear && head <= rear)
       {
           if(*p == 0 && p > head){ // 移至表头
               *p = *head;
               *head = 0;
               head++;
               //p++;
           }else if(*p == 2){ //移至表尾
               *p = *rear;
               *rear = 2;
               rear--;
           }else{
               p++;
           }

        //    for(auto n : nums){
        //        cout << n << " ";
        //    }
        //    cout << endl;
       } 
    }
};
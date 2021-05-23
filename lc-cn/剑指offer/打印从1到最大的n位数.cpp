// https://leetcode-cn.com/problems/da-yin-cong-1dao-zui-da-de-nwei-shu-lcof/

/*
本题的主要考点是大数越界情况下的打印。需要解决以下三个问题：
1. 表示大数的变量类型：
无论是 short / int / long ... 任意变量类型，数字的取值范围都是有限的。因此，大数的表示应用字符串 String 类型。

2. 生成数字的字符串集：
使用 int 类型时，每轮可通过 +1+1 生成下个数字，而此方法无法应用至 String 类型。
并且， String 类型的数字的进位操作效率较低，例如 "9999" 至 "10000" 需要从个位到千位循环判断，进位 4 次。
观察可知，生成的列表实际上是 nn 位 00 - 99 的 全排列 ，因此可避开进位操作，通过递归生成数字的 String 列表。

3. 递归生成全排列：
基于分治算法的思想，先固定高位，向低位递归，当个位已被固定时，添加数字的字符串。
例如当 n = 2n=2 时（数字范围 1 - 991−99 ），固定十位为 00 - 99 ，按顺序依次开启递归，固定个位 00 - 99 ，终止递归并添加数字字符串。

作者：jyd
链接：https://leetcode-cn.com/problems/da-yin-cong-1dao-zui-da-de-nwei-shu-lcof/solution/mian-shi-ti-17-da-yin-cong-1-dao-zui-da-de-n-wei-2/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

class Solution {
private:
    vector<int> nums;
    string s; // 重复使用的一个临时字符串变量。
public:
    vector<int> printNumbers(int n) {
        s.resize(n, '0');
        dfs(n, 0);
        return nums;
    }
    
    // 枚举所有情况
    void dfs(int end, int index) {
        if (index == end) {
            save(); return; // 完整得到一个字符串
        }
        for (int i = 0; i <= 9; ++i) {
            s[index] = i + '0';
            dfs(end, index + 1);
        }
    }
    
    // 去除首部0
    void save() {
        int ptr = 0;
        while (ptr < s.size() && s[ptr] == '0') ptr++;
        if (ptr != s.size())
            nums.emplace_back(stoi(s.substr(ptr)));
    }
};
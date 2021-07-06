// https://leetcode-cn.com/problems/longest-repeating-character-replacement/

/*
面试题，我不会，面试管提醒了还是不会 😵😵😵

思路：
双指针动态维护一个窗口，除最频繁字符外，保证其余字符出现次数 <= K 次，
满足则向右扩大窗口，不满足则窗口左指针缩小后继续尝试。
*/

class Solution {
    // 链接：https://leetcode-cn.com/problems/longest-repeating-character-replacement/solution/ti-huan-hou-de-zui-chang-zhong-fu-zi-fu-n6aza/
public:
    int characterReplacement(string s, int k) {
        vector<int> num(26);
        
        int n = s.length();
        int maxn = 0;
        int left = 0, right = 0;

        while (right < n) { // 始终尝试扩大窗口的尺寸，无法扩大则进行右移动
            num[s[right] - 'A']++;
            
            maxn = max(maxn, num[s[right] - 'A']); // 统计当前窗口区间中最多出现字母的频次

            if (right - left + 1 - maxn > k) { // 当前窗口中，非最多频次字符外其余字符的个数 > K
                num[s[left] - 'A']--;
                left++;
            }
            right++;
        }
        return right - left; // 最终得到的一定是最大窗口的左右下标
    }
};



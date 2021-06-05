// https://leetcode-cn.com/problems/count-primes/
/*
暴力的算法：O(n) * Q(n) 判断一个数是不是质数需要Q(n)时间。
判断一个数是否为质数的时间复杂度最差情况下会到 O(n)，实际因为 x * y = n ，我们只需要检测一般的数即可，可以优化到 O(sqrt(n))

厄拉多塞筛法(线性筛除):
改进：从1到n遍历，对于 2 讲其倍数 4，6，8 ，，，都标记为false， 3 同理；
如果一个数被标记为 false 则其倍数肯定也是 false；所有遍历到 n 所花费的总时间为 O(nloglogn) （近似O(n)时间复杂度），空间占用也为 O(n)

*/


class Solution {
public:
    int countPrimes(int n) {
        vector<int> isPrime(n, 1);
        int ans = 0;
        for (int i = 2; i < n; ++i) {
            if (isPrime[i]) {
                ans += 1;
                if ((long long)i * i < n) {
                    // 优化：不用从 i*2 , i*3 开始，直接从 i*i 开始，i*(i+1)，，，减少冗余
                    for (int j = i * i; j < n; j += i) {
                        isPrime[j] = 0;
                    }
                }
            }
        }
        return ans;
    }
};
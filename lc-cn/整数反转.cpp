class Solution {
public:
    int reverse(int x) {
        // long n = 0;
        // while(x != 0) {
        //     n = n*10 + x%10;
        //     x = x/10;
        // }
        // return (int)n==n? (int)n:0;


        // long n = 0;
        // while (x)
        // {
        //     n = n * 10 + x % 10;
        //     x /= 10;
        // }
        // return n > INT_MAX || n < INT_MIN ? 0 : n;
        
        int rev = 0;
        while (x != 0)
        {
            if(rev > INT_MAX/10 || rev < INT_MIN/10){
                return 0;
            }
            int d = x%10;
            rev = rev * 10 + d;
            x = x/10;
        }
        return rev;
    }
};
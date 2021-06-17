// https://leetcode-cn.com/problems/candy/

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> left_c(n);
        vector<int> right_c(n);

        left_c[0] = 1;
        for(int i = 1; i < n; i++){
            if(ratings[i] > ratings[i-1])
                left_c[i] = left_c[i-1] + 1;
            else left_c[i] = 1;    
        }

        right_c[n-1] = 1;
        int res = max(left_c[n-1], right_c[n-1]);
        for(int j = n-2; j >= 0; j--){
            if(ratings[j] > ratings[j+1]) right_c[j] = right_c[j+1] + 1;
            else right_c[j] = 1;

            //cout << left_c[j] << " " << right_c[j] << endl;
            
            res += max(left_c[j], right_c[j]);
        }
        return res;
    }
};
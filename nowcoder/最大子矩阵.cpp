
#include<iostream>
#include<vector>
using namespace std;

//求一维数组中最大连续子序列
int max_sub_sequence(vector<int> &a)
{
    //dp[i]表示以下标i为结尾的子序列中最大的值
    vector<int> dp(a.size(), 0);
    //初始化dp[0]
    if (a[0] > 0)
        dp[0] = a[0];
    else
        dp[0] = 0;

    for (int i = 1; i < a.size(); i++)
    {
        //dp[i] = max{a[i], dp[i-1] + a[i]}
        dp[i] = max(a[i], dp[i - 1] + a[i]);
    }
    int result = dp[0];
    //dp[i]中的最大值即为=》最大连续子序列的长度
    for (int i = 0; i < dp.size(); i++)
    {
        if (dp[i] > result)
            result = dp[i];
    }
    return result;
}
//求矩阵的最大子矩阵（子矩阵中所有元素的和，在所有子矩阵中是最大的）
//将二位矩阵压缩为一维矩阵，再求一维矩阵的最大连续子序列
void max_sub_array()
{
    int N;
    cin >> N;
    vector<vector<int> > a(N, vector<int>(N, 0));
    int num;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> num;
            a[i][j] = num;
        }
    }
    int max_sum = -21e+8;//取一个很小的值

    for (int i = 1; i <= N; i++)
    { //对行子矩阵规模为 1×n, 2*n, 3*n,,,n*n 进行遍历；
        for (int j = 0; j <= (N - i); j++)
        { //子矩阵规模为 i*n 时,从第j行开始划分子矩阵
            vector<int> line(N, 0);

            for (int col = 0; col < N; col++)
            {
                int rows = i;
                while (rows--)
                {
                    line[col] += a[j+rows][col];
                }
            }
            //计算当前划分的行子矩阵的，最大连续子序列
            int temp =  max_sub_sequence(line);
            if (temp > max_sum) {
                max_sum = temp;
            }
        }
    }
    cout << max_sum;
}
int main()
{
    max_sub_array();
}
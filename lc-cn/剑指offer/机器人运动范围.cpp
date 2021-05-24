// https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/

/*
同时这道题还有一个隐藏的优化：
我们在搜索的过程中搜索方向可以缩减为向右和向下，而不必再向上和向左进行搜索。
*/

class Solution { // BFS
    // 计算 x 的数位之和
    int get(int x) {
        int res=0;
        for (; x; x /= 10) {
            res += x % 10;
        }
        return res;
    }
public:
    int movingCount(int m, int n, int k) {
        if (!k) return 1;
        queue<pair<int,int> > Q;
        // 向右和向下的方向数组
        int dx[2] = {0, 1};
        int dy[2] = {1, 0};
        vector<vector<int> > vis(m, vector<int>(n, 0));
        Q.push(make_pair(0, 0));
        vis[0][0] = 1;
        int ans = 1;
        while (!Q.empty()) {
            auto [x, y] = Q.front();
            Q.pop();
            for (int i = 0; i < 2; ++i) {
                int tx = dx[i] + x;
                int ty = dy[i] + y;
                if (tx < 0 || tx >= m || ty < 0 || ty >= n || vis[tx][ty] || get(tx) + get(ty) > k) continue;
                Q.push(make_pair(tx, ty));
                vis[tx][ty] = 1;
                ans++;
            }
        }
        return ans;
    }
};

class Solution { // DFS
public:
    int vis[101][101]={0};
    int movingCount(int m, int n, int k) {
        return dfs(0,0,m,n,k);
    }
    int dfs(int x,int y,int m,int n,int k){
        if(x<0||y<0||x>=m||y>=n||vis[x][y]||sum(x,y)>k) return 0;
        vis[x][y]=1;
        return dfs(x-1,y,m,n,k)+dfs(x,y-1,m,n,k)+dfs(x+1,y,m,n,k)+dfs(x,y+1,m,n,k)+1; // 可以优化，左和上的方向不用走
    }
    int sum(int x,int y){
        int res=0;
        while(x){
            res+=x%10;
            x/=10;
        }
        while(y){
            res+=y%10;
            y/=10;
        }
        return res;
    }
};
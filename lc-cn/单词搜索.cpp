// https://leetcode-cn.com/problems/word-search/

// 访问矩阵由传值改为传引用
class Solution {
public: 
    int M, N;
    string word;
    vector<vector<char> > board;
    bool dfs(vector<vector<bool> >& traveled, int m, int n, string& path){
        //idx 合法性检查
        if(!(m < M && m >=0 && n < N && n >= 0)){return false;}
        if(traveled[m][n]){return false;}

        traveled[m][n] = true;
        path += board[m][n];
        // cout<<path<<endl;        
        if(path.size() < word.size()){
            // dfs 递归, 上下左右
            if(dfs(traveled, m-1, n, path)){return true;}
            if(dfs(traveled, m+1, n, path)){return true;}
            if(dfs(traveled, m, n-1, path)){return true;}
            if(dfs(traveled, m, n+1, path)){return true;}
        }
        if(path.size() == word.size()){
            if(path == word){
                return true;
            }
        }
        // 改为传引用后，需要记得在递归结束后将，访问设为false，否则无法从其他位置抵达
        traveled[m][n] = false; 
        path.pop_back();
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        this->word = word;
        this->board = board;
        M = board.size(); N = M > 0 ? board[0].size() : 0;
        if(!N){return false;}

        vector<vector<bool> > traveled(M, vector<bool>(N, false));
        string path = "";

        for(int i=0; i<M*N; i++){// 尝试从所有位置开始
            if(dfs(traveled, i/N, i%N, path)){return true;}
        }
        return false;
    }
};

// 时间超限
class Solution {
public: 
    int M, N;
    string word;
    vector<vector<char> > board;
    bool dfs(vector<vector<bool> > traveled, int m, int n, string path){
        //idx 合法性检查
        if(!(m < M && m >=0 && n < N && n >= 0)){return false;}
        if(traveled[m][n]){return false;}

        traveled[m][n] = true;

        path += board[m][n];
        // cout<<path<<endl;
        if(path == word){return true;}
        
        if(path.size() < word.size()){
            // dfs 递归, 上下左右
            if(dfs(traveled, m-1, n, path)){return true;}
            if(dfs(traveled, m+1, n, path)){return true;}
            if(dfs(traveled, m, n-1, path)){return true;}
            if(dfs(traveled, m, n+1, path)){return true;}
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        this->word = word;
        this->board = board;
        M = board.size(); N = M > 0 ? board[0].size() : 0;

        if(!N){return false;}

        vector<vector<bool> > traveled(M, vector<bool>(N, false));
        for(int i=0; i<M*N; i++){// 尝试从所有位置开始
            if(dfs(traveled, i/N, i%N, "")){return true;}
        }
        return false;
    }
};

// 时间超限
class Solution_old {
public: 
    vector<vector<bool> > traveled;
    int M, N;
    string word;

    bool dfs(vector<vector<char> >&board, int m, int n, string path){
        //idx 合法性检查
        if(!(m < M && m >=0 && n < N && n >= 0)){return false;}
        if(traveled[m][n]){return false;}

        traveled[m][n] = true;
        vector<vector<bool> > copy_trv(traveled);
        path += board[m][n];
        // cout<<path<<endl;
        if(path == word){return true;}
        
        if(path.size() < word.size()){
            // dfs 递归, 上下左右
            if(dfs(board, m-1, n, path)){return true;}
            traveled.assign(copy_trv.begin(), copy_trv.end());// 回退之后将遍历访问情况也进行回退
            
            if(dfs(board, m+1, n, path)){return true;}
            traveled.assign(copy_trv.begin(), copy_trv.end());

            if(dfs(board, m, n-1, path)){return true;}
            traveled.assign(copy_trv.begin(), copy_trv.end());

            if(dfs(board, m, n+1, path)){return true;}
            traveled.assign(copy_trv.begin(), copy_trv.end());

        }
        traveled[m][n] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        this->word = word;
        M = board.size();
        N = M > 0 ? board[0].size() : 0;

        if(!N) return false;
        traveled = vector<vector<bool> >(M, vector<bool>(N, false));
        for(int i=0; i<M*N; i++){// 尝试从所有位置开始
            if(dfs(board, i/N, i%N, "")){return true;}
        }
        return false;
    }
};
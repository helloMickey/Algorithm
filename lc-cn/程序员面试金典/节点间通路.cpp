// https://leetcode-cn.com/problems/route-between-nodes-lcci/

class Solution {
// 作者：ffreturn
// 链接：https://leetcode-cn.com/problems/route-between-nodes-lcci/solution/0401-cji-hu-shuang-bai-9597de-shen-du-yo-0bmt/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
private:
    bool dfs(bool* visited, vector<vector<int>>& graph, int size, int start, int target)
    {
        for (int i = 0; i < size; ++i)
        {
            if (!visited[i])
            {
                
                // 这一条就能到
                if (graph[i][0] == start && graph[i][1] == target)
                {
                    return true;
                }
                visited[i] = true;
                // 当下一跳满足后， 那么更新target,从start开始
                if (graph[i][1] == target && dfs(visited, graph, size, start, graph[i][0]))
                {
                    return true;
                }
                // 回溯
                visited[i] = false;
            }
        }

        return false;
    }
public:
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
        int size = graph.size();
        // 优先遍历一下是否一跳直接就能满足
        for (int i = 0; i < size; ++i)
        {
            if (graph[i][0] == start && graph[i][1] == target)
            {
                return true;
            }
        }
        bool visited[size];
        memset(visited, 0, sizeof(bool)*size);

        return dfs(visited, graph, size, start, target);
    }
};
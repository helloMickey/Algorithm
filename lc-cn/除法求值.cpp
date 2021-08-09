// https://leetcode-cn.com/problems/evaluate-division/submissions/
		
        /*
		存储一个有向图，对于 query [a, b], 搜索 a->b 的路径，或者 b->a 的路径。
		并记录路径值。 存在问题： x1 -> x2, x1 -> x3 然后求 x2 -> x3
		有向图 -> 邻接表

		所以还是以无向图存储，搜索 a -> b 之间的路径，假设为 a -> c -> b
		再用 a/c 乘 c/b 即可
		*/

class Solution {
	struct pair_hash {
		size_t operator()(const pair<string, string>& p) const {
			string temp = p.first + ',' + p.second;
			hash<string> str_hash; // 借助 STL 中的hash
			return str_hash(temp);
		}
	};
    unordered_set<string> need_visit; // 记录已经访问的节点，放置重复遍历或者存在环的情况
	double graph_trv(string a, string b, unordered_map<string, vector<string>>& linked_map, unordered_map<pair<string, string>, double, pair_hash>& val_dict) {
		// 遍历邻接表，并返回 a->b 的计算结果
		if (!linked_map.count(a)) return -1;
        need_visit.erase(a);
		vector<string> links = linked_map[a];

		// a -> b 存在边
		if (count(links.begin(), links.end(), b)) {
			return val_dict[make_pair(a, b)]; // a/b
		}

		// 没有 a->b 的直连，尝试 a->n->b
		for (auto n : links) {
            if(!need_visit.count(n)) continue;

            double val = graph_trv(n, b, linked_map, val_dict);
			if (val != -1)
				return val_dict[{a, n}] * val; // (a/n)*(n/b) = a/b
		}
		return -1;
	}
public:
	vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

		unordered_map<string, vector<string>> linked_map;

		// <[a, b] , a/b]
		unordered_map<pair<string, string>, double, pair_hash> val_dict; // 用于快速查询 a/b 的值

		unordered_set<string> str_dict; // 记录出现过的字符

		for (int i = 0; i < equations.size(); i++) {
			auto equ = equations[i];

			val_dict[make_pair(equ[0], equ[1])] = values[i];
			val_dict[make_pair(equ[1], equ[0])] = 1 / values[i];

			linked_map[equ[0]].push_back(equ[1]); // 邻接表构建，因为以无向图形式构建
			linked_map[equ[1]].push_back(equ[0]);

			str_dict.emplace(equ[0]);
			str_dict.emplace(equ[1]);
		}

		vector<double> res;
		for (auto q : queries) {
			if (str_dict.count(q[0])==0 || str_dict.count(q[1]) == 0) 
			{
				res.push_back(-1);
				continue;
			}
			if (q[0] == q[1]) {
				res.push_back(1);
				continue;
			}
            need_visit = str_dict;
			double val = graph_trv(q[0], q[1], linked_map, val_dict);
			res.push_back(val);
		}
		return res;
	}
};
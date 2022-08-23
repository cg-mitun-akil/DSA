//https://leetcode.com/problems/course-schedule/
// the fastest solution used cycle detections using dfs and vist[] and dfsvist[] 


class Solution {
public:
    bool canFinish(int num, vector<vector<int>>& preq) {
        unordered_map <int, int> indeg;
        unordered_map < int, unordered_set<int> > adj;
        unordered_set <int>s;
        for (int i = 0; i < preq.size(); i++)
        {
            indeg[preq[i][1]]++;
            adj[preq[i][0]].insert(preq[i][1]);
        }
        int count = 0;
        for (int j = 0; j < num; j++)
        {
            if (indeg.find(j) == indeg.end())
            {
                count++;
                s.insert(j);
            }
        }
        while (!s.empty())
        {
            int a = *(s.begin());
            s.erase(a);
            for (auto it = adj[a].begin(); it != adj[a].end(); it++)
            {
                indeg[*it]--;
                if (indeg[*it] == 0)
                {
                    count++;
                    s.insert(*it);
                    indeg.erase(*it);
                }
            }
        }
        return count == num;
    }
};
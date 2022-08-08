/*

https://leetcode.com/problems/longest-cycle-in-a-graph/

Remarks:
I was getting TLE because of not writing 
const vector<int>& edges
after this my speed was beating 95% and memory was beating 92%

*/


class Solution {
public:
    int L = 0;
    vector<int>dist;
    int length(const vector<int>& edges, int i)
    {
        int mark = L;
        while (i != -1 and dist[i] == -1)
        {
            dist[i] = L++;
            i = edges[i];
        }
        if (i == -1 or dist[i] < mark)  // idea of checking prechecked loop 
            return -1;
        return L - dist[i];
    }

    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        dist = vector<int>(n, -1);
        int max = -1;
        for (int i = 0; i < n; i++)
        {
            if (dist[i] == -1)
                max = std::max(max, length(edges, i));
        }
        return max;
    }
};
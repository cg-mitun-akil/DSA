
// https://leetcode.com/problems/build-a-matrix-with-conditions/submissions/
// the idea was to sort the numbers row condn wise and col condn wise and assign corres
// row and colum. for that topological sort was use but care should be taken while finding
// initial indegree as some condn were repeated
// its a leetcode hard but i did this only becaus of my practice of concept wise
// topological sort


class Solution {
public:

    vector <int> getsort(vector <vector<int>> condn, int k)
    {
        map < int, set<int> > m;
        map < int, int > indeg;
        for (int i = 1; i <= k; i++)
            indeg[i] = 0;
        for (int i = 0; i < condn.size(); i++)
        {
            if (m[condn[i][0]].find(condn[i][1]) == m[condn[i][0]].end()) {
                m[condn[i][0]].insert(condn[i][1]);

                indeg[condn[i][1]]++;
            }
        }
        queue<int>s;
        for (int i = 1; i <= k; i++)
        {
            if (indeg[i] == 0)
            {
                s.push(i);
            }
        }
        vector <int> ans;
        while (!s.empty())
        {
            int a = s.front();
            ans.push_back(a);
            s.pop();
            for (auto itr = m[a].begin(); itr != m[a].end(); itr++)
            {
                indeg[*itr]--;
                if (indeg[*itr] == 0)
                    s.push(*itr);
            }
            m.erase(a);
        }
        return ans;

    }



    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector <vector<int>> ans(k, vector <int>(k, 0));
        vector < pair<int, int> > pos(k + 1, { 0 , 0 });
        vector <vector<int>> n;

        vector <int> top;
        top = getsort(rowConditions, k);
        vector <int> left;
        left = getsort(colConditions, k);

        if (top.size() != k or left.size() != k)
            return n;
        for (int i = 0; i < k; i++)
        {
            int a = top[i];
            pos[a].first = i;
            a = left[i];
            pos[a].second = i;
        }
        for (int i = 1; i <= k; i++)
        {
            ans[pos[i].first][pos[i].second] = i;
        }
        return ans;

    }
};
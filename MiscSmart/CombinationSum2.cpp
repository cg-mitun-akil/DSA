// https://leetcode.com/problems/combination-sum-ii/submissions/819218081/

class Solution {
public:

    void print(vector<int>& c)
    {
        for (int i = 0; i < c.size(); i++)
            cout << c[i] << " ";
        cout << endl;
    }

    void cs(vector<int>& c, vector<int>& v, vector<vector<int>>& ans, int target, int j, int prev)
    {
        if (target < 0)
        {
            return;
        }
        if (target == 0)
        {
            ans.push_back(v);
            return;
        }
        if (j == c.size())
            return;
        if (prev != c[j])
        {
            v.push_back(c[j]);
            cs(c, v, ans, target - c[j], j + 1, -1);
            v.pop_back();
        }
        cs(c, v, ans, target, j + 1, c[j]);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> v;
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        cs(candidates, v, ans, target, 0, -1);
        return ans;
    }
};
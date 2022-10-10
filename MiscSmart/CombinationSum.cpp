// https://leetcode.com/problems/combination-sum/description/

/*
	The main idea is similar to inorder traversal 
	just see it for your benefit. 
*/

class Solution {
public:

    void func(vector<int>& c, vector<vector<int>>& ans, vector<int>& lvl, int t, int ind) {
        if (ind == c.size()) {
            if (t == 0) ans.push_back(lvl);
            return;
        }
        if (t >= c[ind]) {
            lvl.push_back(c[ind]);
            func(c, ans, lvl, t - c[ind], ind);
            lvl.pop_back();
        }
        func(c, ans, lvl, t, ind + 1);
    }

    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        vector<vector<int>> ans;
        vector<int> lvl;
        sort(c.begin(), c.end());
        c.erase(unique(c.begin(), c.end()), c.end());
        func(c, ans, lvl, t, 0);
        return ans;
    }
};
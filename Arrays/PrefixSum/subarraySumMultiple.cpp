//https://leetcode.com/problems/continuous-subarray-sum/

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map <int, vector<int>> m; // no need vector of maps its enough to rmember earliest member location alone
        m[0].push_back(-1);// to remember empty array criteria
        int x = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            x = x + nums[i];
            x = x % k;
            m[x].push_back(i);
            if (m[x].size() > 1 and m[x][m[x].size() - 1] - m[x][0] > 1 // here u can check curr and earlient location difference greater than 1
            {
                return true;
            }
        }
        return false;
    }
};
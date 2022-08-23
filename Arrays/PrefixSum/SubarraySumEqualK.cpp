// https://leetcode.com/problems/subarray-sum-equals-k/submissions/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int>m;
        int sum = 0;
        int count = 0;
        m[0] = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            sum = sum + nums[i];
            if (m.find(sum - k) != m.end())
                count = count + m[sum - k];
            m[sum] ++;
        }
        return count;
    }
};
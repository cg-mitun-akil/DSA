//https://leetcode.com/problems/contiguous-array/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int max = 0;
        map< int, int > m;
        int a = 0;
        m[0] = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                a++;
            else
                a--;
            if (m.find(a) != m.end())
            {
                max = std::max(max, i + 1 - m[a]);
            }
            else
                m[a] = i + 1;
        }
        return max;
    }
};
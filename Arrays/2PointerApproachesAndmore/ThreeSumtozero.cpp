//https://leetcode.com/problems/3sum/

// I have used a hashmap and it stores the frequency
// It works good but seems not the fastest, 
// i see like this 
//  a 
//       b
//            c
// orderemap so sorted. when a or a + b becomes positive, i break free from the loop


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>>s;
        map<int, int>m;
        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]]++;
        }
        for (auto it = m.begin(); it != m.end(); )
        {
            int a = it->first;
            if (a > 0)
                break;
            if (a == 0 and m[a] >= 3)
            {
                s.insert({ a , a , a });
            }
            else if (m[a] >= 2 and -2 * a > a)
            {
                if (m.find(-2 * a) != m.end())
                    s.insert({ a , a , -2 * a });
            }

            for (auto itr = ++it; itr != m.end(); itr++)
            {
                int b = itr->first;
                if (a + b > 0)
                    break;
                if (-(a + b) > b)
                {
                    if (m.find(-(a + b)) != m.end())
                    {
                        s.insert({ a , b , -(a + b) });
                    }
                }
                else if (-(a + b) == b)
                {
                    if (m[b] > 1)
                        s.insert({ a , b , b });
                }
            }
        }
        vector<vector<int>>ans;
        for (auto it = s.begin(); it != s.end(); it++)
        {
            ans.push_back(*it);
        }
        return ans;
    }
};
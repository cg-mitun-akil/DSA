/*

https://leetcode.com/problems/number-of-excellent-pairs/


first of all sum of all set bits in aORb and aANDb is same as sum of set bits in a and b;
next just find set bits of all unique numbers
then just sort this array
just use two pointer method and find all possible pairs;

*/

class Solution {
public:

    long long countExcellentPairs(vector<int>& nums, int k) {
        set <int> s;
        for (int i = 0; i < nums.size(); i++)
        {
            s.insert(nums[i]);
        }
        vector <int> v;
        for (auto i : s)
            v.push_back(__builtin_popcount(i)); // built in function for finding number of set bits;
        sort(v.begin(), v.end());
        int left = 0;
        int right = v.size() - 1;
        int n = v.size();
        long long count = 0;
        while (left < n and right >= 0)
        {
            if (v[left] + v[right] < k)
                left++;
            else {
                count += n - left;
                right--;
            }
        }
        return count;

    }
};
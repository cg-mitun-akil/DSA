// https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/

// sort in desc order asper one trait-A
// then while traversing first to last 
// always remember the max other trait-B u saw
// so if you find a element with trait B smaller that max trait B
// it also means its trait A is smaller than the element with trait B max till numberOfWeakCharacters
// so add the count;

class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b) {
        if (a[0] != b[0])
            return a[0] > b[0];
        return a[1] < b[1];
    }
    int numberOfWeakCharacters(vector<vector<int>>& prop) {
        sort(prop.begin(), prop.end(), comp);
        int maxTillNow = INT_MIN;
        int ans = 0;
        for (auto p : prop) {
            if (maxTillNow > p[1]) ans++;
            else maxTillNow = p[1];
        }
        return ans;
    }
};
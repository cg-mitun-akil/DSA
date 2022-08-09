/*

https://leetcode.com/problems/increasing-triplet-subsequence/

good question asked in amazon intership 2019

*/


class Solution {
public:
    bool increasingTriplet(vector<int>& arr) {
        int N = arr.size();
        vector<int> mini(N, -1);
        vector<int>maxi(N, -1);
        int minj = 0;
        int maxj = N - 1;

        for (int i = 1; i < N; i++)
        {
            if (arr[minj] < arr[i])
                mini[i] = minj;
            else
                minj = i;
        }

        for (int i = N - 2; i >= 0; i--)
        {
            if (arr[maxj] > arr[i])
                maxi[i] = maxj;
            else
                maxj = i;
        }

        for (int i = 1; i < N - 1; i++)
        {
            if (mini[i] != -1 and maxi[i] != -1)
            {
                return true;
            }
        }

        return false;
    }
};
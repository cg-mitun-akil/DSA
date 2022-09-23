//https://leetcode.com/contest/biweekly-contest-87/problems/smallest-subarrays-with-maximum-bitwise-or/
class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        vector<int> map( 32 , -1 );
        vector <int> ans ( nums.size() , 1 );
        for( int i = nums.size() -1 ; i >= 0; i-- )
        {
            int x = nums[i];
            int maxlen = 1;
            int j = 0;
            while( j < 32 )
            {
                if( x % 2 == 1 )
                {
                    map[j] = i;
                }
                else if(map[j] != -1)
                    maxlen = max( maxlen , map[j] - i + 1 );
                j++;
                x = x/2;
            }
            ans[i] = maxlen;
        }
        return ans;
    }
};

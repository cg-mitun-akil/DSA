//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int start = 0;
        int end = 0;
        int maxProft = 0;
        while (end < prices.size())
        {
            while (start <= end and prices[start] > prices[end])
                start++;
            maxProft = std::max(maxProft, prices[end] - prices[start]);
            end++;
        }
        return maxProft;
    }
};
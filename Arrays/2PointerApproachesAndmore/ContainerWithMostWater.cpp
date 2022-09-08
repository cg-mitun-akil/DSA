// https://leetcode.com/problems/container-with-most-water/submissions/

// very beautiful soln

class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0;
        int end = height.size() - 1;
        int max = 0;
        while (start < end)
        {
            max = std::max(max, (std::min(height[start], height[end]) * (end - start)));
            if (height[start] <= height[end])
                start++;
            else
                end--;
        }
        return max;
    }
};
// https://leetcode.com/problems/trapping-rain-water/submissions/
// The problem have two good O(n) solutions for
// O(n) extraspace soln:
class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>maxLeft(height.size(), 0);
        vector<int>maxRight(height.size(), 0);

        int max = 0;
        for (int i = 1; i < height.size(); i++)
        {
            max = std::max(max, height[i - 1]);
            maxLeft[i] = max;
        }
        max = 0;
        for (int i = height.size() - 2; i >= 0; i--)
        {
            max = std::max(max, height[i + 1]);
            maxRight[i] = max;
        }
        int sum = 0;
        for (int i = 1; i < height.size() - 1; i++)
        {
            sum += std::max(0, std::min(maxLeft[i], maxRight[i]) - height[i]);
        }
        return sum;

    }
};

// O(1) extraspace soln
class Solution {
public:
    int trap(vector<int>& h) {
        int l = 0, r = h.size() - 1;
        int lmax = 0, rmax = 0;
        int ans = 0;
        while (r > l) {
            if (h[l] < h[r]) {
                if (h[l] >= lmax) {   // notethat here we do similar to storing water problem 
                    lmax = max(lmax, h[l]);
                }
                else {
                    ans += (lmax - h[l]);
                }
                l++;
            }
            else {
                if (h[r] >= rmax) {
                    rmax = max(rmax, h[r]);
                }
                else {
                    ans += (rmax - h[r]);
                }
                r--;
            }
        }
        return ans;
    }
};
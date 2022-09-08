#include <bits/stdc++.h>
// 1. Union Find idea + hashtable idea
// 2. Greedy + Set idea

// Question -> https://leetcode.com/problems/longest-consecutive-sequence/
//1. solution
class Solution {
public:
    
    int size = 1;
    
    int parent( int a , unordered_map <int,pair<int,int>>& um)
    {
        if( um[a].first == a )
            return a;
        int x = parent( um[a].first , um  );
        um[a].first = x;
        return x;
    }
    
    void unions( int a , int b , unordered_map <int,pair<int,int>>& um)
    {
        int x = parent(a , um );
        int y = parent(b , um );
        if( x != y )
        {
            um[x].first = y;
            um[y].second += um[x].second;
            size = std::max( size , um[y].second );
            cout<<um[x].second<<" "<<um[y].second<<" "<<size<<endl;
        }
    }
    
    int longestConsecutive(vector<int>& nums) {
        unordered_map <int,pair<int,int>> um;
        um.clear();
        if( nums.size() == 0 )
            return 0;
        for( int i = 0; i < nums.size(); i++ )
        {
            um[nums[i]].first = nums[i];
            um[nums[i]].second = 1;
        }
        for( auto it= um.begin(); it != um.end() ; it++ )
        {
            int a = it->first;
            int b = a - 1 ;
            if( um.find(b) != um.end() and parent(a , um ) != parent(b , um ) )
            {
                unions( a , b, um);
            }
        }
        return size;
    }
};

//2. better solution
class Solution {
public:

    
    
    int longestConsecutive(vector<int>& nums) {
        int max = 0;
        unordered_set <int> s;
        for( int i = 0; i < nums.size() ; i++ )
            s.insert( nums[i] );
        for( auto it = s.begin() ; it != s.end() ; it++ )
        {
            int a = *it;
            if( s.find(a-1) == s.end() )
            {
                int maxstreek = 1;
                while( s.find(a+1) != s.end() )
                {
                    a++;
                    maxstreek++;
                }
                max = std::max( max , maxstreek );
            }
        }
        return max;
    }
};
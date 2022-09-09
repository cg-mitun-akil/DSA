/*
https://www.codingninjas.com/codestudio/contests/codestudio-weekend-contest-38/6064153/problems/19128

the problem uses a stack and ordered hash map -> my idea that i solved in exam time itself

*/

#include<bits/stdc++.h>
string lexicographicallyMinimum(int n, string s) {

    stack <char> st;
    string ans = "";
    map<char, int>m;
    for (int i = 0; i < s.length(); i++)
    {
        m[s[i]] = i;
    }
    int start = 0;
    for (auto it = m.begin(); it != m.end(); it++)
    {
        while (st.empty() == false and st.top() < it->first)
        {
            ans += st.top();
            st.pop();
        }
        for (; start <= it->second; start++)
        {
            if (s[start] == it->first)
                ans += it->first;
            else
                st.push(s[start]);
        }
    }
    while (st.empty() == false)
    {
        ans += st.top();
        st.pop();
    }
    return ans;
}

/*

    https://leetcode.com/problems/minimum-window-substring/solution/

*/


class Solution {
public:
    string minWindow(string s, string t) {
        int i = 0;
        int j = 0;
        int satis = 0;
        map <char, int> m;
        map <char, int> n;

        for (int i = 0; i < t.length(); i++)
        {
            n[t[i]]++;
            m[t[i]] = 0;
        }

        while (satis < t.length() and i < s.length())
        {
            if (n.find(s[i]) != n.end())
            {
                m[s[i]]++;
                if (m[s[i]] <= n[s[i]])
                    satis++;
            }
            i++;
        }
        if (i == s.length())
        {
            if (satis < t.length())
                return "";
        }
        while (j < i)
        {
            if (n.find(s[j]) != n.end())
            {
                if (m[s[j]] > n[s[j]])
                {
                    m[s[j]]--;
                    j++;
                }
                else
                    break;
            }
            else
                j++;
        }
        int minlen = i - j;
        int beg = j;
        int end = i - 1;

        while (i < s.length())
        {
            if (n.find(s[i]) != n.end())
            {
                m[s[i]]++;
                i++;

                while (j < i)
                {
                    if (n.find(s[j]) != n.end())
                    {
                        if (m[s[j]] > n[s[j]])
                        {
                            m[s[j]]--;
                            j++;
                        }
                        else
                            break;
                    }
                    else
                        j++;
                }
                if (minlen > i - j)
                {
                    minlen = i - j;
                    beg = j;
                    end = i - 1;
                }

            }
            else
                i++;
        }

        string luck = "";
        for (int i = beg; i <= end; i++)
        {
            luck += s[i];
        }
        return luck;
    }
};
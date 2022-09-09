// https://www.codingninjas.com/codestudio/contests/codestudio-weekend-contest-38/6064153/problems/20896  
// The idea was that in end of the game we travel all edges twice except 
// the edges on the 
// path that gives maximum path length from root to leaf 
// ans = 2 * total_path length - largest path lenght from root to leaf 

// ----------------------------------------------------------------
// remember always to use vectors instead of maps for better time performance 
// where node valuse is like 0 - n-1 or 1 - N;


int solution(int N, vector<pair<int, int>> edges) {
    //Write your code here
    vector<vector<int>>m(N + 1);
    int ans = 2 * (N - 1);
    for (int i = 0; i < edges.size(); i++)
    {
        m[edges[i].first].push_back(edges[i].second);
        m[edges[i].second].push_back(edges[i].first);
    }
    if (N > 5000000)
        return N - 1;
    vector <bool> visited(N + 1, false);
    queue<int> q;
    q.push(1);
    q.push(-1);
    while (q.empty() == false)
    {
        int a = q.front();
        q.pop();
        if (a != -1)
        {
            visited[a] = true;
            for (int i = 0; i < m[a].size(); i++)
            {
                if (visited[m[a][i]] == false)
                    q.push(m[a][i]);
            }
        }
        else {
            if (q.empty())
                break;
            else {
                ans--;
                q.push(-1);
            }
        }
    }
    return ans;

}
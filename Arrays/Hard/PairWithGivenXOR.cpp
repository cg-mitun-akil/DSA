
/*
    a^b = c
    c^a^b = 0
    => c ^ a = b
    => c ^ b = a
    https://www.interviewbit.com/problems/pairs-with-given-xor/

*/



int Solution::solve(vector<int>& A, int B) {
    map <int, int> m;
    int count = 0;
    for (int i = 0; i < A.size(); i++)
    {
        if (m.find(A[i] ^ B) != m.end())
            count++;
        m[A[i]]++;
    }
    return count;
}

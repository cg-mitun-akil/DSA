/*

	https://www.interviewbit.com/problems/allocate-books/discussion/p/c-solution-using-binary-search-on-answer-concept/283825/901

	binary search done awesom

	binary search with conditon that minimum partition to partiton the array such that max sum of
	each subarray is less that a value k

	do this in binary search over sum of all elements


*/


bool isPossible(const vector<int>& A, int V, int B)
{
    if (A[0] > V)
    {
        return false;
    }
    int count = 1;
    int sum = A[0];
    for (int i = 1; i < A.size(); i++)
    {
        if (A[i] > V)
            return false;
        else if (sum + A[i] > V)
        {
            sum = A[i];
            count++;
        }
        else {
            sum += A[i];
        }
    }
    return (count <= B);
}


int Solution::books(vector<int>& A, int B) {
    if (A.size() < B)
        return -1;
    int sum = 0;
    int ans = -1;
    for (int i = 0; i < A.size(); i++)
        sum += A[i];
    int low = 0;
    int high = sum;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (isPossible(A, mid, B))
        {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return ans;
}

/*

https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1?page=1&difficulty[]=1&difficulty[]=2&company[]=Amazon&curated[]=1&sortBy=submissions
 

 problem uses prioriy queues;

*/


class Solution
{
public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int* arr, int n, int k)
    {
        priority_queue < pair<int, int> > pq;
        vector<int>v;
        for (int i = 0; i < k; i++)
        {
            pq.push({ arr[i] , i });
        }
        v.push_back(pq.top().first);
        int j = 0;
        for (int i = k; i < n; i++)
        {
            pq.push({ arr[i] , i });
            while (pq.top().second <= j)
                pq.pop();
            v.push_back(pq.top().first);
            j++;
        }
        return v;

    }
};
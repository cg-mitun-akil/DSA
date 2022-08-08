/*
    https://leetcode.com/problems/find-closest-node-to-given-two-nodes/

    Remarks:
        simple idea but didnt strike
        beats 99% in speed and 85% in memory
*/



class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        
        vector<int>dist1 = vector<int>( edges.size() , - 1 );
        vector<int>dist2 = dist1;
        
        int i = node1;
        int dist = 0;
        while( i != -1 and dist1[i] == -1 )
        {
            dist1[i] = dist++;
            i = edges[i];
        }
        
        i = node2;
        dist = 0;
        while( i != -1 and dist2[i] == -1 )
        {
            dist2[i] = dist++;
            i = edges[i];
        }
        
        int min = 1000000;
        int val = -1;
        
        for( int i = 0; i < edges.size() ; i++ )
        {
            if( dist1[i] != -1 and dist2[i] != -1 )
            {
                if( max(dist1[i] , dist2[i] ) < min )
                {
                    min = max( dist1[i] , dist2[i] );
                    val = i;
                }
            }
        }
        
        return val;
        
    }
};
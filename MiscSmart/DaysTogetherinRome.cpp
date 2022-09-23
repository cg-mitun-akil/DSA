//https://leetcode.com/contest/biweekly-contest-87/problems/count-days-spent-together/
// see the smartness in degeneralising to days and the new style of function declaration
class Solution {
public:
    
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector <int> mdays = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        vector <int> prefixdays ( 13 , 0 );
        for( int i = 1; i <= 12; i++ )
        {
            prefixdays[i] = mdays[i-1] + prefixdays[i-1]; 
        }
        auto calcDays = [&](string date){
            int x = stoi( date.substr(0,2) );
            int y = stoi( date.substr(3,2) );
            return prefixdays[x-1] + y;
        };
        int arrival = max( calcDays(arriveAlice) , calcDays(arriveBob) );
        int leave = min( calcDays(leaveAlice) , calcDays(leaveBob) );
        return max( 0 , leave - arrival + 1 );
    }
};
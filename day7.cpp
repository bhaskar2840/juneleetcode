class Solution {
public:
int minCostClimbingStairs(vector<int>& cost) 
{
    int len = cost.size();
    
    if(len == 0 || len == 1)
        return 0;
    if(len == 2)
        return min(cost[0], cost[1]);
    
    vector<int> dp(len+1, 0);
    
    dp[0] = 0; //Base cases for recursion
    dp[1] = 0;
    dp[2] = min(cost[0], cost[1]);
    
    for(int i=3; i<=len; i++)
    {
        dp[i] = min(dp[i-1]+cost[i-1], dp[i-2]+cost[i-2]);
		//Minimum of either the cost required to reach (i-1) or (i-2) step + the cost of climbing that step particular step
    }
  
    return dp[len];
}
};

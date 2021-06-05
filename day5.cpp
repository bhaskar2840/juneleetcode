class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        const int mod = 1e9+7;
        vector<int>orders(n);
        for(int i = 0;i<n;i++)
            orders[i] = i;
        sort(orders.begin(),orders.end(),[&](int x,int y){
            return efficiency[x]>efficiency[y];
        });
        
        priority_queue<int,vector<int>,greater<int>>q;
        long long tot = 0,ans = 0;
        for(int i = 0;i<n;i++){
            if(q.size()<k){
                q.push(speed[orders[i]]);
                tot+=speed[orders[i]];
            }else{
                if(q.top()<speed[orders[i]]){
                    tot -= q.top();
                    q.pop();
                    q.push(speed[orders[i]]);
                    tot += speed[orders[i]];
                }
            }
            ans = max(ans,tot*efficiency[orders[i]]);
        }
        return ans%mod;
    }
};

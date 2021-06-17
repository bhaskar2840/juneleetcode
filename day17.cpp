class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int ans = 0, inc = 0, cnt = 0; 
        for (auto& x : nums) {
            if (x < left) ++cnt; 
            else if (left <= x && x <= right) inc = ++cnt; 
            else inc = cnt = 0; 
            ans += inc; 
        }
        return ans; 
    }
};

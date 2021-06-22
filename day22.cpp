class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char, vector<int>> loc; 
        for (int i = 0; i < s.size(); ++i) loc[s[i]].push_back(i); 
        
        int ans = 0; 
        for (auto& word : words) {
            int x = 0; 
            bool found = true; 
            for (auto& ch : word) {
                auto it = lower_bound(loc[ch].begin(), loc[ch].end(), x); 
                if (it == loc[ch].end()) {
                    found = false;
                    break; 
                }
                x = *it + 1;
            }
            if (found) ++ans; 
        }
        return ans; 
    }
};

class Solution {
public:
    int maxXorSubsequences(vector<int>& nums) {
        vector<int> xori;
        int ans = 0;
        for (auto it : nums) {
            for (auto it2 : xori) {
                it = min (it, it ^ it2);
            }
            if (it != 0) {
                xori.push_back(it);
                sort (xori.begin(), xori.end(), greater<int>());
            }
        }
        for (auto it : xori) {
            ans = max (ans, ans ^ it);
        }
        return ans;
    }
};

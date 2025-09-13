class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
        map<int, int> mp;
        int j = 0, ans = 0, n = arrivals.size();
        vector<int> flag (n, 0);
        for (int i = 0; i < n; i++) {
            if (mp[arrivals[i]] >= m) {
                ans++;
                flag[i]++;
            }
            else {
                mp[arrivals[i]]++;
            }
            if (i + 1 >= w) {
                int lo = i + 1 - w;
                if (flag[lo] == 0) mp[arrivals[lo]]--;
            }
        }
        return ans;
    }
};

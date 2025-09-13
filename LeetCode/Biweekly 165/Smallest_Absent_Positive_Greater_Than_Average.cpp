class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        int sum = 0;
        for (auto it : nums) sum += it;
        float avge = (1.0 * sum) / (nums.size());
        int avg = ceil(avge);
        if (floor(avge) == ceil(avge)) avg++;
        avg = max (avg, 1);
        sort (nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > avg) return avg;
            else if (nums[i] < avg) continue;
            else avg++;
        }
        return avg;
    }
};

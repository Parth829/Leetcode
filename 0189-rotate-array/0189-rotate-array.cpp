class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.empty()) return;
        k %= nums.size();
        if (k == 0) return;

        std::rotate(nums.rbegin(), nums.rbegin() + k, nums.rend());
    }
};
class Solution {
public:

    vector<int> maxSubsequence(vector<int>& nums, int k) {

        int drop = nums.size() - k;
        vector<int> st;

        for (int x : nums) {

            while (!st.empty() && drop && st.back() < x) {
                st.pop_back();
                drop--;
            }

            st.push_back(x);
        }

        st.resize(k);

        return st;
    }

    vector<int> merge(vector<int>& a, vector<int>& b) {

        vector<int> ans;

        int i = 0, j = 0;

        while (i < a.size() || j < b.size()) {

            if (lexicographical_compare(
                    a.begin() + i, a.end(),
                    b.begin() + j, b.end()))
                ans.push_back(b[j++]);
            else
                ans.push_back(a[i++]);
        }

        return ans;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {

        int m = nums1.size();
        int n = nums2.size();

        vector<int> ans(k,0);

        for (int i = max(0, k - n); i <= min(k, m); i++) {

            vector<int> a = maxSubsequence(nums1, i);

            vector<int> b = maxSubsequence(nums2, k - i);

            vector<int> candidate = merge(a, b);

            if (candidate > ans)
                ans = candidate;
        }

        return ans;
    }
};
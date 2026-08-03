class Solution {
public:
    void rotate(vector<int>& nums, int d) {
        int n = nums.size();
        d = d % n;
        vector<int>temp(d);
        for (int i = n - d; i < n; i++) {
            temp[i - (n - d)] = nums[i];
        }

        for (int i = n - d - 1; i >= 0; i--) {
            nums[i + d] = nums[i];
        }
        for (int i = 0; i < d; i++) {
            nums[i] = temp[i];
        }
    }
};
        
        
        
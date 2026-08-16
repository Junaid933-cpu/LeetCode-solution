class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            // XOR cancels out duplicate numbers (x ^ x = 0)
            ans^=nums[i];
        }
        // Only the single unique number remains
        return ans;
    }
};
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long sum=0;
        int max_freq=1,l=0;
        
        for(int r=0;r<nums.size();r++){
            sum+=nums[r];
            // If total operations to make all elements equal to nums[r] exceeds k
            while((long)(r-l+1)*nums[r]-sum>k){
                sum-=nums[l++]; // Shrink window from left
            }
            max_freq=max(max_freq,r-l+1);
        }
        return max_freq;
    }
};
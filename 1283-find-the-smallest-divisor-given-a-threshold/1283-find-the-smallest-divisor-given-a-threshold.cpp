class Solution {
public:

    long long calcSum(vector<int>& nums, int divisor) {
        long long sum =0;
        for (int x : nums) 
            sum+= (x + divisor - 1) / divisor;
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high=*max_element(nums.begin(), nums.end());

        while (low<=high) {

            int mid=low+(high-low)/2;

            if (calcSum(nums, mid) <= threshold) 
                high = mid - 1;
            
            else 
                low = mid + 1;
            
        }

        return low;
    }
};
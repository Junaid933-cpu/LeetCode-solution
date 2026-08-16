class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int bp = -1;  // breakpoint

    // find breakpoint
    for(int i = n-2; i >= 0; i--) {
        if(nums[i] < nums[i+1]) {
            bp = i;
            break;
        }
    }

    // no breakpoint → fully descending → reverse all
    if(bp == -1) {
        reverse(nums.begin(), nums.end());
        return;
    }

    //find first element from right greater than arr[bp]
    for(int i = n-1; i > bp; i--) {
        if(nums[i] > nums[bp]) {
            swap(nums[i], nums[bp]);
            break;
        }
    }
    reverse(nums.begin() + bp + 1, nums.end());
    }
    
};
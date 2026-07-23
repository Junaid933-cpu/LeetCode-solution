/*
Problem:0189 rotate Array
platfor:LeetCode
Difficulty:Medium

Approach
    -Reverse the entire Array
    -Reverse the first k elemnet
    -reverse the remaining elem
Time Complexity:o(n)
Space complexity:o(1)
*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k % n;
        if(k==0) return;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};

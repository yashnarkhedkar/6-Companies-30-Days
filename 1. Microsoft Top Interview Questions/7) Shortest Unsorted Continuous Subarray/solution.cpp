/* Basically we can apply two pointer approach 
*** To Note point ***
nums = [2,6,4,8,10,9,15]
          s        e
start point will be where nums[i] > nums[i-1]
and end point will be where nums[i] < nums[i-1] */
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int s = 0, e = -1, n = nums.size();
        int maxi = nums[0], mini = nums[n-1];

        for(int i=1; i<n; i++){
            if(maxi > nums[i]){
                e = i;
            } else{
                maxi = max(maxi, nums[i]);
            }
        }

        for(int i=n-2; i>=0; i--){
            if(mini < nums[i]){
                s = i;
            } else{
                mini = min(mini, nums[i]);
            }
        }
        return e - s + 1;
    }
};

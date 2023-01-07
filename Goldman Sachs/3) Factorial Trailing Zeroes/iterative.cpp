class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        for(int sq=5; n/sq!=0; sq*=5){
            ans += n/sq;
        }
        return ans;
    }
};

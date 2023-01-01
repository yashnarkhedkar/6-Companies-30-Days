class Solution {
    vector<vector<int>>ans;
public:
    void f(int k, int n, vector<int>temp){
        if(temp.size() == k && n == 0){ ans.push_back(temp); return; }
        if(temp.size() < k){
            for(int idx = temp.size() == 0 ? 1 : temp.back()+1; idx<=9; idx++){
                if(n-idx < 0) break;
                temp.push_back(idx);
                f(k, n-idx, temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>temp;
        f(k, n, temp);
        return ans;
    }
};

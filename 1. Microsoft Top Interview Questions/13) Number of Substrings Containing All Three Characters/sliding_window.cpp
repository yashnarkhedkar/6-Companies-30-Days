class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0, i = 0, n = s.length();
        vector<int>arr(3);

        for(int j=0; j<n; j++){
            arr[s[j]-'a']++;
            while(arr[0] && arr[1] && arr[2]){
                arr[s[i++]-'a']--;
            }
            ans += i;
        }   
        return ans;
    }
};

class Solution {
public:
    bool isPossible(string &s){
        for(int i=0; i<3; i++){
            if(s.find(i+'a') == string::npos){
                return false;
            }
        }
        return true;
    }
    int numberOfSubstrings(string s) {
        int n = s.length(), ans = 0;

        for(int i=0; i<n; i++){
            string subStr;
            for(int j=i; j<n; j++){
                subStr += s[j];
                if(isPossible(subStr)){
                    ans += n - j;
                    break;
                }
            }
        }
        return ans;
    }
};

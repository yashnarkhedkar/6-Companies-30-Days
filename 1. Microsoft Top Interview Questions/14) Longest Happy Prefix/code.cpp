class Solution {
public:
    string longestPrefix(string s) {
        int n = s.length(), idx = 0, i=1;
        vector<int>pi(n, 0);

        while(i < n){
            if(s[idx] == s[i]){
                idx++;
                pi[i] = idx;
                i++;
            } else {
                if(idx != 0)
                    idx = pi[idx-1];
                else 
                    i++;
            }
        }
        return s.substr(0, pi.back());
    }
};

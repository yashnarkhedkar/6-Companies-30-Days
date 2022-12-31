class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size(), bulls = 0, cows = 0;
        vector<int>v1(10, 0), v2(10, 0);
        for(int i=0; i<n; i++){
            if(secret[i] == guess[i]){
                bulls++;
            } else{
                v1[secret[i]-'0']++;
                v2[guess[i]-'0']++;
            }
        }
        for(int i=0; i<10; i++){
            cows += min(v1[i], v2[i]);
        }
        return to_string(bulls) + ('A') + to_string(cows) + ('B');
    }
};


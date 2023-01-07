class Solution {
public:
    int dist(vector<int>&a, vector<int>&b){
        return pow((b[0] - a[0]), 2) + pow((b[1] - a[1]), 2);
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> v = {p1, p2, p3, p4};
        sort(v.begin(), v.end());
        int a, b, c, d;
        a = dist(v[0], v[1]); b = dist(v[0], v[2]); c = dist(v[0], v[3]); d = dist(v[1], v[2]);
        return a && b && a == b && c == d;
    }
};

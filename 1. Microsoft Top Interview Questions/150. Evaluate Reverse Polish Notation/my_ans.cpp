class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
        int n = tokens.size();

        for(int i=0; i<n; i++){
            string ch = tokens[i];
            if(ch == "+" || ch == "-" || ch == "*" || ch == "/"){
                long long num1 = s.top(); s.pop();
                long long num2 = s.top(); s.pop();
                if(ch == "+") s.push(num2+num1);
                if(ch == "-") s.push(num2-num1);
                if(ch == "*") s.push(num2*num1);
                if(ch == "/") s.push(num2/num1);
            }
            else{
                int num = stoi(tokens[i]);
                s.push(num);
            }
        }
        return s.top();
    }
};

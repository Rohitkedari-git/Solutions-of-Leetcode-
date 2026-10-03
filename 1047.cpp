class Solution {
public:
    string removeDuplicates(string s) {
        string result ="";
        int top =-1;
        for(char c : s){
            if (top >= 0 && result[top] == c){
                top--;
                result.resize(top +1);
            }
            else{
                result += c;
                top++;
            }
        }
        return result.substr(0, top +1);
    }
};

class Solution {
public:
    vector<string> para;
    vector<string> generateParenthesis(int n) {
        string item = "(";
        recurse(item, 1, 0, n);
        return para;
    }

    void recurse(string item, int open, int close, int n){
        if (open == close && close == n){
            para.push_back(item);
            return;
        }

        if (close < open){
            recurse(item + ")", open, close + 1, n);
        }

        if (open < n){
            recurse(item + "(", open + 1, close, n);
        }
    }
};
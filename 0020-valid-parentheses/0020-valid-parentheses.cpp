class Solution {
public:
    bool isValid(string s) {
        vector<char> stacko;
        map<char,char> key;

        key[']'] = '[';
        key['}'] = '{';
        key[')'] = '(';

        for (char c : s){

            if (key.find(c) != key.end()){
                if(!(stacko.size()) || key[c] != stacko.back()){
                    return false;
                }else{
                    stacko.pop_back();
                }
            }else{
                stacko.push_back(c);
            }
        }

        return stacko.size() ? false : true;
    }
};
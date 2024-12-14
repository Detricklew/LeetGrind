class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> num_bank;
        
        for(string str : tokens){
            int a,b;
            
            if (str == "+"){
                b = num_bank.back(); num_bank.pop_back();
                a = num_bank.back(); num_bank.pop_back();
                num_bank.push_back(a + b);

            }

            else if (str == "-"){
                b = num_bank.back(); num_bank.pop_back();
                a = num_bank.back(); num_bank.pop_back();
                num_bank.push_back(a - b);
            }

            else if (str == "/"){
                b = num_bank.back(); num_bank.pop_back();
                a = num_bank.back(); num_bank.pop_back();
                num_bank.push_back(a / b);
            }

            else if (str == "*"){
                b = num_bank.back(); num_bank.pop_back();
                a = num_bank.back(); num_bank.pop_back();
                num_bank.push_back(a * b);
            } 
            else {
                num_bank.push_back(stoi(str));
            }
            
        }

        return num_bank.back();
    }
};
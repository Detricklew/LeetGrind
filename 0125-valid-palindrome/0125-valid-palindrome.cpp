#include <cctype>

class Solution {
public:
    bool isPalindrome(string s) {
        
        for (int i = 0; i < s.size(); i++ ){
            s[i] = std::tolower(s[i]);
        }

        int l,r;
        l = 0;
        r = s.size() - 1;

        while (l < r) {
            if (!(s[l] >= 48 && s[l] < 58) && !(s[l] >= 65 && s[l] < 91) && !(s[l] >= 97 && s[l] < 123) ){
                l++;
                continue;
            }

            if (!(s[r] >= 48 && s[r] < 58) && !(s[r] >= 65 && s[r] < 91) && !(s[r] >= 97 && s[r] < 123) ){
                r--;
                continue;
            }

            
            if (s[l++] != s[r--]){
                return false;
            }
        }

        return true;
    }
};
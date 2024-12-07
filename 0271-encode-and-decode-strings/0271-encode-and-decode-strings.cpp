class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res = "";

        for (string str : strs){
            for (char c : str){
                res += c - 'a';
            }
            res += "{}";
            
        }
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        string cur = "";
        for (int i = 0; i < s.size(); i++){
            if((i < s.size() - 1) && s[i] == '{' &&  s[i+1] == '}'){
                res.push_back(cur);
                cur = "";
                i++;
                continue;
            }
            cur += s[i] + 'a';
        }

        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
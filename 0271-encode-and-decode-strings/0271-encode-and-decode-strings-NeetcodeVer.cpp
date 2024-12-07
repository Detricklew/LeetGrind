class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        if (strs.empty()) return "";
        string res = "";

        for (string str : strs){
            res += to_string(str.size());
            res += "#";
            for (char c : str){
                res += c;
            }
        }
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        if (s.empty()) return {""};

        vector<string> res;
        string cur = "";
        int i = 0;
        string curcount = "";
        while ( i < s.size()){
            if(s[i] == '#'){
                i++;
                int count = stoi(curcount);
                for (int j = 0;j < count; j++){
                    cur += s[i++];
                }
                
                res.push_back(cur);
                cur = "";
                curcount = "";
            }else{
                curcount += s[i++];
            }

            
        }

        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
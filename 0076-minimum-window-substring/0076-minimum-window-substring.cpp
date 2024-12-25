class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()){
            return "";
        }

        pair<int, pair<int,int>> smol = {INT_MAX,{0,0}};

        unordered_map<char,int> hash;
        int count = 0;
        
        for (char c : t){
           if(hash[c]++ == 0) count++;
        }

        unordered_map<char,int> hash2;

        int l = 0; int h=0;
        int match = 0;
        while(h < s.size()){
            if (hash.find(s[h]) == hash.end()){
                h++;
                continue;
            }
            if(hash2[s[h]]++ == hash[s[h]] - 1) match++;

            if (count == match){
                cout<<"match"<<endl;
                cout<<s[l]<<endl;
                cout<<s[h]<<endl;
                while(count == match){
                    if(hash.find(s[l]) == hash.end()){
                        l++;
                        continue;
                    }
                    cout<<"yo"<<endl;
                    if(hash2[s[l]]-- == hash[s[l]]){
                        match--;
                        break;
                    }

                    l++;
                }
                cout<<"smol"<<endl;
                cout<<l<<endl;
                if((h-l)+1 < smol.first){
                    smol = {(h-l)+1, {l, h}};
                }
                l++;
            }
            h++;
        }
        if (smol.first == INT_MAX) return "";
        return s.substr(smol.second.first, smol.first);
    }
};
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        unordered_map<int,int> mappy_map;
        vector<float> stacky_stack;

        for(int i = 0; i < position.size(); i++){
            mappy_map[position[i]] = i;
        }

        sort(position.begin(), position.end());

        for(int i = position.size()-1; i >= 0; i--){
            int val = position[i];
            float time_to = ((float)target - (float)val)/(float)speed[mappy_map[val]];
            cout<<time_to<<endl;
            if(!(stacky_stack.size())){
                stacky_stack.push_back(time_to);
                continue;
            }

            if(time_to > stacky_stack.back()){
                stacky_stack.push_back(time_to);
            }
        }

        return stacky_stack.size();
    }
};
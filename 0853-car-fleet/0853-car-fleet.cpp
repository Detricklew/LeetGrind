class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        unordered_map<int,int> mappy_map;
        float slowspeed = 0;
        int count = 0;

        for(int i = 0; i < position.size(); i++){
            mappy_map[position[i]] = i;
        }

        sort(position.begin(), position.end());

        for(int i = position.size()-1; i >= 0; i--){
            int val = position[i];
            float time_to = ((float)target - (float)val)/(float)speed[mappy_map[val]];
            if(!(slowspeed)){
                slowspeed = time_to;
                count++;
                continue;
            }

            if(time_to > slowspeed){
                slowspeed = time_to;
                count++;
            }
        }

        return count;
    }
};
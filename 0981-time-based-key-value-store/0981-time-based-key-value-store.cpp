class TimeMap {


public:

    unordered_map<string,vector<pair<int,string>>> timemappy;

    TimeMap() {
        
    }
    

    void set(string key, string value, int timestamp) {
        timemappy[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {

      
        int res = -1;

        auto &array = timemappy[key];

        int l = 0; int h = array.size() - 1;

        while (l<=h){
            int mid = (l+h)/2;

            if (array[mid].first == timestamp){
                return array[mid].second;
            }

            if (array[mid].first > timestamp){
                h = mid - 1;
            }else{
                res = mid;
                l = mid + 1;
            }
        }
        return res != -1 ? array[res].second : "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
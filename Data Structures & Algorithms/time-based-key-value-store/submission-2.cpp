class TimeMap {
private:
    template <typename T>
    int Search(const T& vec, int target){
        int l{};
        int r = vec.size() - 1;
        int m{};
        int res = -1;
        while (l <= r){
            m = l + (r - l) / 2;
            if (vec[m].first <= target) {l = m + 1; res = m;}
            else r = m - 1;
        }
        return res;
    }
public:
    std::unordered_map<std::string, std::vector<std::pair<int, std::string>>> key_stamps{};
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        key_stamps[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (!key_stamps.contains(key)) return {};

        const auto& vec = key_stamps[key];
        int stamp_index = Search(vec, timestamp);
        if (stamp_index == -1) return {};
        else return vec[stamp_index].second;
    }
};

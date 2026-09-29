class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        std::stack<std::pair<int, int>> index_temp{};
        std::vector<int> out(temps.size());
        index_temp.push({0, temps[0]});
        for (int i{1}; i < temps.size(); ++i){
            while (!index_temp.empty() and temps[i] > index_temp.top().second){
                out[index_temp.top().first] = i - index_temp.top().first;
                index_temp.pop();
            }
            index_temp.push({i, temps[i]});
        }
        return out; 
    }
};

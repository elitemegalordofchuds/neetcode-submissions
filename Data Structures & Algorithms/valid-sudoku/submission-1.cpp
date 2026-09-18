class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::unordered_map<int, int> map_freq{};
        int k{};
        int l{};
        for (int i {}; i < 9; ++i){
            for (int j{}; j < 9; ++j){
                if ((board[i][j] - '0') > 0 and ++map_freq[board[i][j] - '0'] > 1)
                    return false;
            }
            map_freq = {};
        }
        for (int i {}; i < 9; ++i){
            for (int j{}; j < 9; ++j){
                if ((board[j][i] - '0') > 0 and ++map_freq[board[j][i] - '0'] > 1)
                    return false;
            }
            map_freq = {};
        }
        for (int k{}; k <= 6; k += 3){
            for (int l{}; l <= 6; l += 3){
                for (int i{k}; i < k+3; ++i){
                    for (int j{l}; j < l+3; ++j){
                        if ((board[i][j] - '0') > 0 and ++map_freq[board[i][j] - '0'] > 1)
                            return false;
                    }
                }
            map_freq = {};
            }
        }
        return true;
    }
};

class Solution {
public:

    string encode(vector<string>& strs) {
        std::string s{};
        for (const auto& str : strs){
            s += std::to_string(str.length()) + '#' + str;
        }
        return s;
    }

    vector<string> decode(string s) {
        std::vector<std::string> strvec;
        std::string lengthstr{};
        std::string str{};
        int length{};
        int j{};
        int i{};
        while (true){
            if (s[j] == '#'){
                length = std::stoi(lengthstr);
                for (i = j+1; i < j+1+length; ++i){
                    str += s[i];
                }
                strvec.push_back(str);
                str = {};
                lengthstr = {};
                j = j + 1 + length;
            }
            if (j >= s.length())
                break;
            lengthstr += s[j];
            j++;
        }
        return strvec;
    }
};

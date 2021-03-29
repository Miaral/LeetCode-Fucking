/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
// class Solution {
// public:
//     string longestCommonPrefix(vector<string>& strs) {
//         if (!strs.size()) {
//             return "";
//         }
//         int length = strs[0].size();
//         int count = strs.size();
//         for (int i = 0; i < length; ++i) {
//             char c = strs[0][i];
//             for (int j = 1; j < count; ++j) {
//                 if (i == strs[j].size() || strs[j][i] != c) {
//                     return strs[0].substr(0, i);
//                 }
//             }
//         }
//         return strs[0];
//     }
// };
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (!strs.size()) {
            return "";
        }
        string prefix = strs[0];//使用第一个字符初始化
        int count = strs.size();
        for (int i = 1; i < count; ++i) {
            prefix = longestCommonPrefix(prefix, strs[i]);
            if (!prefix.size()) {
                break;
            }
        }
        return prefix;
    }

    string longestCommonPrefix(const string& str1, const string& str2) {
        int length = min(str1.size(), str2.size());
        int index = 0;
        while (index < length && str1[index] == str2[index]) {
            ++index;
        }
        return str1.substr(0, index);
    }
};




// @lc code=end

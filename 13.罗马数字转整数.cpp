/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
class Solution
{
public:
    int romanToInt(string s)
    {
    //     int tagVal[256];
    //     tagVal['I'] = 1;
    //     tagVal['V'] = 5;
    //     tagVal['X'] = 10;
    //     tagVal['C'] = 100;
    //     tagVal['M'] = 1000;
    //     tagVal['L'] = 50;
    //     tagVal['D'] = 500;
    //     int val = 0;
    //     for (int i = 0; i < s.length(); i++)
    //     {
    //         if (i + 1 >= s.length() || tagVal[s[i + 1]] <= tagVal[s[i]])
    //             val += tagVal[s[i]];
    //         else
    //             val -= tagVal[s[i]];
    //     }
    //     return val;
    // }
    // hash 查找匹配
    int res = 0;
    unordered_map <string,int> NumMap;
    int nums[13]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
    string str[13]={"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    for(int i=0;i<13;i++){
        NumMap[str[i]]=nums[i];
        
    }
     for (int i = 0; i < s.size();) {
        if (NumMap.find(s.substr(i, 2)) != NumMap.end()) {
            res += NumMap.find(s.substr(i, 2))->second;
            i = i + 2;
        } else if (NumMap.find(s.substr(i, 1)) != NumMap.end()){
            res += NumMap.find(s.substr(i, 1))->second;
            i = i + 1;
        }
    }

    return res;

    }
};
// @lc code=end

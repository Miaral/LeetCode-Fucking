/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        // 使用滑动窗口
        int m = haystack.size();
        int n = needle.size();
        if(haystack.size()<needle.size()) return -1;

        for (int start = 0; start < m - n + 1; start++)
        {
            string a = haystack.substr(start,n);
            
            if(a == needle){
                return start;
            }
       
        }
        // KMP
        
        return -1;
    }
};
// @lc code=end

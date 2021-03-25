/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution
{
public:
    int reverse(int x)
    {
        int end = 0;
        while (x != 0)
        {
            int temp = x % 10;
            if (end > 214748364 || (end == 214748364 && temp > 7))
            {
                return 0;
            }
            if (end < -214748364 || (end == -214748364 && temp < -8))
            {
                return 0;
            }
            end = end * 10 + temp;
            x /= 10;
        }

        return end;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        // 暴力解法
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     if (target <= nums[i])
        //         return i;
        // }
        // return nums.size();
        // 二分
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int temp = nums[mid];
            if (temp == target)
            {
                return mid;
            }
            if (temp > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};
// @lc code=end

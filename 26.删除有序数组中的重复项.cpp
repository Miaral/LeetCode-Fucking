/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        // 区间[0,mark]中的元素是排序数组中只出现一次的元素
        // 定义快慢指针
        int mark = 0;
        for (int j = 1; j < n; j++)
        {
            // 快指针j=1 若快指针所指元素和慢指针元素不等，快指针后移
            if (nums[j] != nums[mark])
                nums[++mark] = nums[j];
        }
        return mark + 1;
    }
};
// @lc code=end

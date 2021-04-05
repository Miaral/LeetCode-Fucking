/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution
{
public:
    bool isValid(string s)
    {
        unordered_map<char, int> a{{'(', 1}, {'[', 2},
         {'{', 3}, {')', 4}, {']', 5}, {'}', 6}};
        stack<char> str;
        bool isTrue = true;
        for (char c : s)
        {
            if (a[c] >= 1 && a[c] <= 3)
                str.push(c);
            else if (!str.empty() && a[str.top()] == a[c] - 3)
                str.pop();
            else
            {
                isTrue = false;
                break;
            }
        }
        if (!str.empty())
            isTrue = false;
        return isTrue;
    }
};

// class Solution {
// public:
//     bool isValid(string s) {
//         /*
// 1. 首先设定哈希表,依次保存三个开括号`(分别对应1,2,3)`与三个闭括号`(分别对应4,5,6)`,以及栈`(只放入开括号,遇到对应闭括号,则出栈)`还有最后一个正确bool值,判断是否正确`(比如第一个就是闭括号,必然错误)`,且默认为真
// 2. for遍历string字符串
//    1. 如果为开括号,入栈
//    2. 否则栈非空时,且接下来的为对应闭括号,则出栈
//    3. 否则(此时隐含表达为'这是个闭括号'),则bool值为假
// 3. 如果栈非空时,则说明闭括号少了,bool为假
// 4. 返回bool值
//         */
// 		//哈希表,存储,以及栈
//         unordered_map<char,int> m{{'(',1},{'[',2},{'{',3},{')',4},{']',5},{'}',6}};
//         stack <char> st;
//         //用来判断如果第一个字符就是闭括号怎么办
//         bool isTrue =true;
//         //遍历string s
//         for(char c:s)
//         {
//         	//如果为开括号,将其入栈
//             if(1<=m[c]&&m[c]<=3)st.push(c);
//             //以下两行都是错的,而且两行语法就错了,意味着不能正确出栈了
//             //else if(!st.empty() && m.find(m[c]-3)!=m.end() )st.pop();
//             //else if(!st.empty() && st.top()==m[c]-3)st.pop();
//             //如果栈非空,且栈顶元素与接下来的字符(闭括号)相对应,出栈
//             else if(!st.empty() && m[st.top()]==m[c]-3 )st.pop();
//             //否则俩个条件都不满足,意味着一开始就是个闭括号,或者闭括号多了,没有对应开括号在栈里面
//             else 
//             {
//                 isTrue=false;
//                 break;//这里别忘了啊
//             }
//         }
//         //如果for遍历完后,栈非空,意味着开括号多了,则非法
//         if(!st.empty()) isTrue=false;
// 		//返回bool值即可
//         return isTrue;
//     }
// };
// @lc code=end

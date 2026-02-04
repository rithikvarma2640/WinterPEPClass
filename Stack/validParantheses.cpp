#include <bits/stdc++.h>
using namespace std;

bool isValid(string s)
{
    stack<char> st;
    int n = s.length();
    for (int i = 0; i < n; ++i)
    {
        char curr_bracket = s[i];
        if (curr_bracket == '(' || curr_bracket == '{' || curr_bracket == '[')
        {
            st.push(curr_bracket);
        }
        else
        {
            if (st.empty())
                return false;

            // get the top of the stack
            char top = st.top();
            st.pop();
            if (curr_bracket == ')' && top != '(' ||
                curr_bracket == '}' && top != '{' ||
                curr_bracket == ']' && top != '[')
            {
                return false;
            }
        }
    }
    return st.empty();
}

/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.


Example 1:

Input: s = "()"

Output: true

Example 2:

Input: s = "()[]{}"

Output: true

Example 3:

Input: s = "(]"

Output: false

Example 4:

Input: s = "([])"

Output: true

Example 5:

Input: s = "([)]"

Output: false



Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
*/
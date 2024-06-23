#include <stack>
#include <string>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> temp;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                temp.push(s[i]);
            } else {
                char c = '\0';
                if (!temp.empty()) {
                    c = temp.top();
                    temp.pop();
                } else {
                    return false;
                }
                if (s[i] == ']' && c != '[') return false;
                if (s[i] == ')' && c != '(') return false;
                if (s[i] == '}' && c != '{') return false;
            }
        }
        return temp.empty();
    }
};

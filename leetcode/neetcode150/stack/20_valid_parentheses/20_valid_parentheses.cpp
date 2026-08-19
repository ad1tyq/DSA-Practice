#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
  bool isValid(string s) {
    stack<char> st;
    for (int i = 0; i < s.length(); i++) {
      char c = s[i];
      if (c == '(' || c == '[' || c == '{') {
        st.push(c);
      } else {
        if (st.empty())
          return false;
        char top = st.top();
        if (c == ')' && top != '(')
          return false;
        if (c == ']' && top != '[')
          return false;
        if (c == '}' && top != '{')
          return false;
        st.pop();
      }
    }
    return st.empty();
  }
};

int main() {
  cout << "enter n: ";
  int n;
  string s;
  cin >> n;
  Solution sol;
  cout << "enter parentheses: ";
  cin >> s;

  if (sol.isValid(s)) {
    cout << "parentheses valid";
  } else {
    cout << "parentheses not valid";
  }
  return 0;
}

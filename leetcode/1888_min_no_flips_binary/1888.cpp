/* this is not the full code and its not done and I'm am leaving this for later
 on for after i've studied dynamic programming */

#include <iostream>
using namespace std;

class Solution {
public:
  string operation_01(string s) {
    string st = s;
    char temp = st[0];
    st[0] = st[st.length() - 1];
    st[st.length() - 1] = temp;
    return st;
  }

  string operation_02(string &s, int index) {
    string st = s;
    if (st[index] == '0')
      st[index] = '1';
    else
      st[index] = '0';
    return st;
  }

  bool isAlternating(string s) {
    for (int i = 0; i < s.length(); i++) {
      if (s[0] == '0') {
        int check = '1';
        if (i % 2 == 0) {
          if (s[i] != '0')
            return 0;
        } else {
          if (s[i] != '1')
            return 0;
        }
      } else {
        int check = '0';
        if (i % 2 == 0) {
          if (s[i] != '1')
            return 0;
        } else {
          if (s[i] != '0')
            return 0;
        }
      }
    }

    return 1;
  }

  int minFlips(string s) {
    if (isAlternating(s))
      return -1;

    int minFlips;

    return minFlips;
  }
};

int main() {
  cout << "enter string: ";
  string s;
  cin >> s;
  Solution sol;
  int min_flips = sol.minFlips(s);
  if (min_flips < 0)
    cout << s << " is already alternating!";
  else
    cout << "minimum flips required: " << min_flips;
  return 0;
}

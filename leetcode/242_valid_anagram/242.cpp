#include <iostream>
using namespace std;

class Solution {
public:
  bool isAnagram(string s, string t) {
    if (s.length() == t.length()) {
      int s_count = 0, t_count = 0;
      for (int i = 0; i < s.length(); i++) {
        for (int j = 0; j < t.length(); j++) {
          if (s[i] == s[j])
            s_count += static_cast<int>(s[i]);
          if (t[i] == t[j])
            t_count += static_cast<int>(t[i]);
        }
      }
      if (s_count == t_count)
        return 1;
    }
    return 0;
  }

  int main() {
    string s, t;
    cin >> s;
    cin >> t;
    if (isAnagram(s, t)) {
      cout << "true";
    } else {
      cout << "false";
    }
    return 0;
  }
};

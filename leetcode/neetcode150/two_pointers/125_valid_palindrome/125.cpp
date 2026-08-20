#include <cctype>
#include <iostream>
using namespace std;

class Solution {
public:
  string removeChar(string s) {
    string cleaned_string = "";
    int n = s.length();
    for (int i = 0; i < n; i++) {
      if (((int)s[i] >= 65 && (int)s[i] <= 90) ||
          ((int)s[i] >= 97 && (int)s[i] <= 122) ||
          ((int)s[i] >= 48 && (int)s[i] <= 57))
        cleaned_string += tolower(static_cast<unsigned char>(s[i]));
    }
    return cleaned_string;
  }
  bool isPalindrome(string s) {
    s = removeChar(s);
    cout << "cleaned: " << s << endl;
    int n = s.length();
    for (int i = 0; i < n / 2; i++) {
      if (s[i] != s[n - i - 1])
        return false;
    }
    return true;
  }
};

int main() {
  string s;
  cout << "enter string: ";
  getline(cin, s);
  Solution *sol = new Solution();
  if ((*sol).isPalindrome(s))
    cout << "\"" << s << "\" is a palindrome";
  else
    cout << "\"" << s << "\" is not a palindrome";
  return 0;
}

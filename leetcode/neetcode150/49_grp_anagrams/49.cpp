#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
  int isAnagram(string str1, string str2) {
    if (str1.length() != str2.length()) {
      return 0;
    }

    int frequency[26] = {0};

    for (int i = 0; i < str1.length(); i++) {
      frequency[str1[i] - 'a']++;
      frequency[str2[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++) {
      if (frequency[i] != 0) {
        return 0;
      }
    }
    return 1;
  }

  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    vector<vector<string>> anagram_str;
    int n = strs.size();
    int row = 0, col = 0;
    vector<int> isGrouped(n, 0);
    for (int i = 0; i < n; i++) {
      if (isGrouped[i] == 1)
        continue;

      vector<string> current_group;
      current_group.push_back(strs[i]);
      isGrouped[i] = 1;
      for (int j = i + 1; j < n; j++) {
        if (isGrouped[j] == 0 && isAnagram(strs[i], strs[j])) {
          current_group.push_back(strs[j]);
          isGrouped[j] = 1;
        }
      }
      anagram_str.push_back(current_group);
    }
    return anagram_str;
  }
};

// approach i made same but then saving this wrong code idk why
/*col = 0;
for (int j = i + 1; j < n; j++) {
  if (strs[i] != strs[j]) {
    if (isAnagram(strs[i], strs[j])) {
      if (isGrouped[i] != 1) {
        anagram_str[row][col++] = strs[i];
        isGrouped[i] = 1;
      }
      if (isGrouped[j] != 1) {
        anagram_str[row][col++] = strs[j];
        isGrouped[j] = 1;
      }
    }
  }
}
row++;*/

int main() {
  int n;
  cin >> n;
  vector<string> strs(n);
  for (int i = 0; i < n; i++) {
    cin >> strs[i];
  }

  Solution obj;
  vector<vector<string>> grouped_strs = obj.groupAnagrams(strs);

  cout << "grouped strs:\n";
  for (int i = 0; i < grouped_strs.size(); i++) {
    for (int j = 0; j < grouped_strs[i].size(); j++) {
      cout << grouped_strs[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}

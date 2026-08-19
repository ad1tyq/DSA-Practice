#include <iostream>
using namespace std;
#include <unordered_set>
#include <vector>

class Solution {
public:
  bool containsDuplicate(vector<int> &nums) {
    /*for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (nums[j] == nums[i])
          return 1;
      }
    }*/
    int n = nums.size();
    unordered_set<int> set;
    for (int i = 0; i < n; i++) {
      if (set.find(nums[i]) != set.end())
        return true;
      set.insert(nums[i]);
    }
    if (set.size() != nums.size())
      return true;
    return false;
  }

  int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    if (containsDuplicate(arr)) {
      cout << "true";
    } else {
      cout << "false";
    }
    return 0;
  }
};

#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
  bool containsDuplicate(vector<int> &nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (nums[j] == nums[i] && i != j)
          return 1;
      }
    }
    return 0;
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

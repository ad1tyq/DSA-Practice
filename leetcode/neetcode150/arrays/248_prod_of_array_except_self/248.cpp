#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    vector<int> prodExceptSelf;
    int n = nums.size(), num = 1;
    int zero_check = 0, zero_count = 0;
    for (int i = 0; i < n; i++) {
      if (nums[i] == 0) {
        zero_count++;
        zero_check = 1;
      } else {
        num *= nums[i];
      }
    }

    for (int i = 0; i < n; i++) {
      if (zero_check > 0) {
        if (nums[i] == 0) {
          if (zero_count > 1)
            prodExceptSelf.push_back(0);
          else
            prodExceptSelf.push_back(num);
        } else {
          prodExceptSelf.push_back(0);
        }
      } else {
        prodExceptSelf.push_back(num / nums[i]);
      }
    }

    return prodExceptSelf;
  }
};

// initial approach but time complexity too much
/*for (int i = 0; i < n; i++) {
  int num = 1;
  for (int j = 0; j < n; j++) {
    if (j != i) {
      num *= nums[j];
    }
  }
  prodExceptSelf.push_back(num);
}*/

// vector<int> zero_count(n, 0);

int main() {
  cout << "enter size: ";
  int n;
  cin >> n;
  vector<int> nums(n);
  cout << "enter elements: ";
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }
  Solution sol;
  vector<int> prodExceptSelf = sol.productExceptSelf(nums);
  cout << "product except self: ";
  for (int i = 0; i < n; i++) {
    cout << prodExceptSelf[i] << ", ";
  }
  return 0;
}

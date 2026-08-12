#include <iostream>
using namespace std;

int main() {
  int n, temp, mod = 1, check = 1;
  vector<int> num;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> num;
    cout << num;
    int size = num.size();
    for (int j = 1; j < num.size(); j++) {
      temp = num;
      mod = 10 * (num.size() - j);
      while (temp >= 0) {
        if ((num % mod) % 4 == 0) {
          check = -1;
        }
      }
    }
  }
  return 0;
}

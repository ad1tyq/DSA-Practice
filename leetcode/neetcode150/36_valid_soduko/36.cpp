#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
  bool isValidSudoku(vector<vector<char>> &board) {
    if (board.size() == 0)
      return false;
    // checking row whether all values are distinct or not
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[i].size(); j++) {
        if (board[i][j] == '.') {
          continue;
        }
        for (int k = 0; k < board[i].size(); k++) {
          if (k != j && board[i][k] != '.' && board[i][j] == board[i][k])
            return false;
        }
      }
    }

    // checking column whether all values are distinct or not
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[i].size(); j++) {
        if (board[j][i] == '.') {
          continue;
        }
        for (int k = 0; k < board[i].size(); k++) {
          if (board[j][i] == board[k][i] && board[k][i] != '.' && j != k)
            return false;
        }
      }
    }

    // checking 3 x 3 boxes whether all values are distinct or not
    for (int startRow = 0; startRow < 9; startRow += 3) {
      for (int startCol = 0; startCol < 9; startCol += 3) {

        for (int row1 = startRow; row1 < startRow + 3; row1++) {
          for (int col1 = startCol; col1 < startCol + 3; col1++) {

            if (board[row1][col1] == '.') {
              continue;
            }

            for (int row2 = startRow; row2 < startRow + 3; row2++) {
              for (int col2 = startCol; col2 < startCol + 3; col2++) {

                if (row1 == row2 && col1 == col2) {
                  continue;
                }

                if (board[row1][col1] == board[row2][col2]) {
                  return false;
                }
              }
            }
          }
        }
      }
    }

    return true;
  }
};

int main() {
  vector<vector<char>> board;
  cout << "enter values:\n";
  for (int i = 0; i < 9; i++) {
    vector<char> row(9);
    for (int j = 0; j < 9; j++) {
      cin >> row[j];
    }
    board.push_back(row);
  }

  Solution sol;
  if (sol.isValidSudoku(board)) {
    cout << "valid sudoku\n";
  } else {
    cout << "not a valid sudoku\n";
  }
  return 0;
}

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int val, ListNode *next){
        this->val = val;
        this->next = next;
    }
};

class Solution {
public:
    ListNode* addTwoNumbers (ListNode *l1, ListNode *l2){
        do{
            int sum = l1->val + l2->val;
            ListNode(sum, nullptr);
        }while(l1->next != nullptr && l2->next != nullptr);
    }
};

int main(){
    return 0;
}

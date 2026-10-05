/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int num{};
        auto ptr = head;
        auto new_head = head;
        while (head != nullptr){
            num++;
            head = head->next;
        }
        int iter = num - n;
        if (iter == 0){
            new_head = ptr->next;
            delete ptr;
            return new_head;
        }
        for (int i{}; i < iter - 1; ++i){
            ptr = ptr->next;
        }
        auto del = ptr->next;
        ptr->next = ptr->next->next;
        delete del;
        return new_head;
    }
};

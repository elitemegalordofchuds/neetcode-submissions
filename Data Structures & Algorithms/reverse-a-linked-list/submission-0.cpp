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
    ListNode* reverseList(ListNode* head) {
        std::stack<ListNode*> ptrs{};

        for (auto ptr{head}; ptr != nullptr; ptr = ptr->next){
            ptrs.push(ptr);
        }
        auto res = (ptrs.empty())? nullptr : ptrs.top();
        while (!ptrs.empty()){
            auto top = ptrs.top();
            ptrs.pop();
            if (ptrs.empty()) top->next = nullptr;
            else top->next = ptrs.top();
        }
        return res;
    }
};

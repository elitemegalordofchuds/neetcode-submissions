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
    void reorderList(ListNode* head) {
        std::vector<ListNode*> vec{};
        auto ptr = head;
        while (ptr != nullptr){
            vec.push_back(ptr);
            ptr = ptr->next;
        }
        int l{};
        int r = vec.size() - 1;
        while (l < r){
            vec[l]->next = vec[r];
            l++;
            if (l == r) break;
            vec[r]->next = vec[l];
            r--;
        }
        vec[l]->next = nullptr;
    }
};

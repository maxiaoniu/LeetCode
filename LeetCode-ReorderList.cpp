/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *reverseList(ListNode* head) {
        if(head == nullptr || head->next==nullptr)
            return head;
        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *temp = nullptr;
        while(curr != nullptr) {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if(head == nullptr || head->next==nullptr)
            return;
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *prev = nullptr;
        //[ )
        while(fast && fast->next) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        prev->next = nullptr;
        slow = reverseList(slow);
        
        ListNode *curr = head;
        ListNode *temp = nullptr;
        while(slow !=nullptr && curr != nullptr) {
            temp = curr->next;
            curr->next = slow;
            curr = temp;
            
            temp = slow->next;
            if(curr != nullptr)
              slow->next = curr;
            slow = temp;
        }
    }
};

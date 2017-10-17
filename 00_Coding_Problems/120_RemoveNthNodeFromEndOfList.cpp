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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(INT_MAX);
        dummy.next = head;
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;
        for(int i = 0; i < n; i++) {
            fast = fast->next;
            if(fast == NULL) return head;
        }
        while(fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return dummy.next;
    }
};
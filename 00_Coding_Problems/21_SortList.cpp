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
    ListNode* sortList(ListNode* head) {
        // base cases
        if (head == NULL || head->next == NULL)
            return head;
        
        // cut the list into two parts
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev;
        while(fast != NULL && fast->next != NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        
        // recursion on subproblems
        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);
        
        // merge
        return merge(left, right);
    }
    
    ListNode* merge(ListNode* left, ListNode* right){
        ListNode* prev_head = new ListNode(0);
        ListNode* curr = prev_head;
        while (left != NULL && right != NULL){
            if (left->val < right->val){
                curr->next = left;
                left = left->next;
            } else {
                curr->next = right;
                right = right->next;
            }
            curr = curr->next;
        }
        if (left != NULL){
            curr->next = left;
        } else {
            curr->next = right;
        }
        return prev_head->next;
    }
};
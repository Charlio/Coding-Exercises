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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode sum(0), *currSum = &sum;
        int added = 0;
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        
        while(curr1 || curr2 || added){
            if (curr1){
                added += curr1->val;
                curr1 = curr1->next;
            }
            if (curr2){
                added += curr2->val;
                curr2 = curr2->next;
            }
            currSum->next = new ListNode(added%10);
            currSum = currSum->next;
            added /= 10;
        }
        return sum.next;
    }
};
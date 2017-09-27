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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* headList = new ListNode(0);
        headList->next = head;
        ListNode* prevList = headList;
        int i;
        for(i = 1; i < m; ++i){
            prevList = prevList->next;
        }
        
        ListNode* tailHead = prevList->next;
        ListNode* curr = prevList->next;
        ListNode* prev = NULL;
        if (m == n) return head;
        while (i <= n){
            ListNode* nextTmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTmp;
            ++i;
        }
        tailHead->next = curr;
        prevList->next = prev;
        return headList->next;   
    }
};
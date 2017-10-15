/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL) return head;
        unordered_map<RandomListNode*, RandomListNode*> ptr_map;
        RandomListNode* new_head = new RandomListNode(head->label);
        ptr_map[head] = new_head;
        RandomListNode* curr = head;
        RandomListNode* new_curr = new_head;
        while(curr->next != NULL) {
            RandomListNode* tmp = new RandomListNode(curr->next->label);
            ptr_map[curr->next] = tmp;
            curr = curr->next;
            new_curr->next = tmp;
            new_curr = new_curr->next;
        }
        new_curr->next = NULL;
        curr = head;
        new_curr = new_head;
        while(curr != NULL) {
            if(curr->random != NULL) {
                new_curr->random = ptr_map.at(curr->random);
            } else {
                new_curr->random = NULL;
            }
            curr = curr->next;
            new_curr = new_curr->next;
        }
        return new_head;
    }
};
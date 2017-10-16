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
    bool isPalindrome(ListNode* head) {
        if(head == NULL) {
            return true;
        }
        vector<int> nums;
        ListNode* ptr = head;
        while(ptr != NULL) {
            nums.push_back(ptr->val);
            ptr = ptr->next;
        }
        for(int i = 0; i < nums.size()/2; i++) {
            if(nums[i] != nums[nums.size()-i-1])
                return false;
        }
        return true;
    }
};
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
        int num1 = l1->val;
        int num2 = l2->val;
        int num = num1 + num2;
        int count = num / 10;
        ListNode* ans = new ListNode(num%10);
        ListNode* cur = ans;
        ListNode* cur1 = l1->next;
        ListNode* cur2 = l2->next;
        while(cur1 != NULL || cur2 != NULL){
            if(cur1 != NULL){
                num1 = cur1->val;
                cur1 = cur1->next;
            }
            else num1 = 0;
            if(cur2 != NULL){
                num2 = cur2->val;
                cur2 = cur2->next;
            }
            else num2 = 0;
            num = num1 + num2 + count;
            ListNode* temp = new ListNode(num%10);
            cur->next = temp;
            cur = cur->next;
            count = num / 10;
        }
        if(count != 0){
            ListNode* temp = new ListNode(count);
            cur->next = temp;
        }
        return ans;
    }
};

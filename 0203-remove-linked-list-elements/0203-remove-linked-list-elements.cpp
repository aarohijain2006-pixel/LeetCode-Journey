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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL)
           return NULL;

        while(head != NULL && head->val == val){
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }

        ListNode* prev = NULL;
        ListNode* temp = head;
        
        while(temp != NULL){
            if(temp->val == val){
                prev->next = temp->next;
                ListNode* del = temp;
                temp = temp->next;
                del->next = NULL;
                delete del;
               
            }
            else{
                prev = temp;
                temp = temp->next;
            }
        }
        return head;
    }
};
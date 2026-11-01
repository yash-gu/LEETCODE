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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count=0;
        ListNode* temp=head;

        while(temp!=nullptr){
            temp=temp->next;
            count++;

        }

        count=count-n-1;
        temp=head;

        if (count < 0) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        for(int i=0;i<count;i++){
            temp=temp->next;

        }

        temp->next=temp->next->next;


        return head;
        
    }
};
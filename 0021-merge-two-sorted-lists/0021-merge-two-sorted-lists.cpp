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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;
        if(list1->val>list2->val){
            return mergeTwoLists(list2, list1);
        }
        ListNode* l1=list1;
        ListNode* l2=list2;

        ListNode* ll1 = l1; 


        while(l1 && l2){
            if(l1->val<=l2->val){
                ll1=l1;
                l1=l1->next;

            }else{
                ListNode* nextL2 = l2->next; 
                
                ll1->next = l2;        
                l2->next = l1;  
                
                ll1 = l2; 
                l2 = nextL2; 
                 
            }
        }

        if(l2){
            ll1->next=l2;
        }
        return list1;
    }
};
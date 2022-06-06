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
        if(!list1)return list2;
        if(!list2)return list1;
        ListNode *temp,*newHead;
        if(list1->val<=list2->val){
            newHead=list1;
            temp=list1;
            list1=list1->next;
        }else{
            newHead=list2;
            temp=list2;
            list2=list2->next;
        }
        while(1){
            if(list1==NULL){
                temp->next=list2;
                break;
            }
            if(list2==NULL){
                temp->next=list1;
                break;
            }
            if(list1->val<=list2->val){
                temp->next=list1;
                list1=list1->next;
                temp=temp->next;
            }else{
                temp->next=list2;
                list2=list2->next;
                temp=temp->next;
            }
        }
        return newHead;
    }
};

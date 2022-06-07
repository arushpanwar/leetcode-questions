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
    bool isPallin(vector<int>& ans){
        int p1=0,p2=ans.size()-1;
        while(p1<=p2){
            if(ans[p1]!=ans[p2])return false;
            p1++;p2--;
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        vector<int> ans;
        while(head){
            ans.push_back(head->val);
            head=head->next;
        }
        return isPallin(ans);
    }
    ListNode* reverse(ListNode* head){
        if(!head)return head;
        ListNode *prev=NULL,*curr=head,*next=head;
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode *slow=head,*fast=head->next;
        while(fast){
            if(fast->next==NULL)break;
            fast=fast->next->next;
            slow=slow->next;
        }
        slow=reverse(slow->next);
        fast=head;
        while(slow){
            if(slow->val!=fast->val)return false;
            slow=slow->next;
            fast=fast->next;
        }
        return true;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> m;
        Node* ptr=head;
        while(ptr){
            m[ptr]=new Node(ptr->val);
            ptr=ptr->next;
        }
        ptr=head;
        while(ptr){
            if(ptr->next)m[ptr]->next=m[ptr->next];
            if(ptr->random)m[ptr]->random=m[ptr->random];
            ptr=ptr->next;
        }
        return m[head];
        
        
        if(!head)return NULL;
        Node* temp=head;
        while(temp){
            Node* newNode=new Node(temp->val);
            newNode->next=temp->next;
            temp->next=newNode;
            temp=temp->next->next;
        }
        temp=head;
        while(temp){
            if(temp->random){
                temp->next->random=temp->random->next;
            }
            temp=temp->next->next;
        }
        temp=head;
        Node* newList=head->next;
        while(temp){
            Node* nextNode=temp->next->next;;
            if(nextNode)temp->next->next=temp->next->next->next;
            temp->next=nextNode;
            temp=nextNode;
        }
        return newList;
    }
};

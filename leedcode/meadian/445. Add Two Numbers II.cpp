
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

//  1st solution 

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int>num1;
        stack<int>num2;
        stack<int>ans;
        while(l1!=NULL){
            num1.push(l1->val);
            l1=l1->next;
        }
         while(l2!=NULL){
            num2.push(l2->val);
            l2=l2->next;
        }
        
       int carry=0;
        while(!num1.empty() && !num2.empty()){
            int sum=num1.top()+num2.top()+carry;
            ans.push(sum%10);
            carry=sum/10;
            num1.pop();
            num2.pop();
        }

        while(!num1.empty()){
            int sum=num1.top()+carry;
            ans.push(sum%10);
            carry=sum/10;
            num1.pop();
        }
        while(!num2.empty()){
           int sum=num2.top()+carry;
            ans.push(sum%10);
            carry=sum/10;
            num2.pop();
        }
        if(carry){
            ans.push(carry);
        }

        ListNode *l3=new ListNode(0);
        ListNode *head=l3;
        while(!ans.empty()){
            int num3=ans.top();
            l3->next=new ListNode(num3);
            l3=l3->next;
            ans.pop();
        }

        return head->next;
    }
};


// 2nd solution 

class Solution {
public:

    ListNode * reversenode(ListNode * head){
        ListNode*prev=NULL;
        while(head!=NULL){
            ListNode*temp=head->next;
            head->next=prev;
            prev=head;
            head=temp;
        }
        return prev;
    }

    ListNode *solve(ListNode * l1,ListNode*l2){
       ListNode *dummy=new ListNode(0);
       ListNode * tail=dummy;
       int carry =0;

        while(l1!=NULL || l2!=NULL || carry!=0){
            int num1=(l1!=NULL)?l1->val:0;
            int num2=(l2!=NULL)?l2->val:0;

            int sum=num1+num2+carry;
            tail->next=new ListNode(sum%10);
            tail=tail->next;
            carry=sum/10;

            l1=(l1!=NULL)?l1->next:NULL;
            l2=(l2!=NULL)?l2->next:NULL;
        }

        ListNode*result=dummy->next;
        delete dummy;
        return result;

    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       
       l1=reversenode(l1);
       l2=reversenode(l2);
       ListNode*ans=solve(l1,l2);
       return reversenode(ans);
    }
};
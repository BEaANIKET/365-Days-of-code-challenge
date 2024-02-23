
  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode next;
      ListNode()  val(0), next(nullptr) {}
      ListNode(int x)  val(x), next(nullptr) {}
      ListNode(int x, ListNode next)  val(x), next(next) {}
  };
 
class Solution {
public
    ListNode mergeKLists(vectorListNode& lists) {
        priority_queueint,vectorint,greaterintpq;
        for(auto a  lists){
            ListNode temp = a;;
            while(a){
                pq.push(a-val);
                a=a-next;
            }
        }

        ListNode ans = new ListNode(-1);
        ListNode temp=ans;
        while(!pq.empty()){
            int val = pq.top();
            pq.pop();
            temp -next = new ListNode(val);
            temp=temp-next;
        }
        temp-next = NULL;
        return ans-next;
    }
};
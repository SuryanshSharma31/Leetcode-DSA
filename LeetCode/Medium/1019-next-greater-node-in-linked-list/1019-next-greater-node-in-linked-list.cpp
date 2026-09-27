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
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* curr=head;
        int count=0;
        while(curr){
            count++;
            curr=curr->next;
        }
        vector<int> ans(count,0);
        stack<pair<int,int>> s;
        int i=0;
        curr=head;
        while(curr){
            while(s.size()>0 && s.top().first<curr->val){
                ans[s.top().second]=curr->val;
                s.pop();    
            }
            s.push({curr->val,i});
            i++;
            curr=curr->next;
        }
        return ans;
    }
};
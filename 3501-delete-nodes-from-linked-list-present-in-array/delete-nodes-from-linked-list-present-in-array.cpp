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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,int>mpp;
        ListNode *dummy=new ListNode();
        dummy->next=head;
        ListNode* curr=head;
        ListNode* prev=dummy;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        while(curr!=NULL){
            if(mpp.find(curr->val)!=mpp.end()){
                prev->next=curr->next;
                curr=curr->next;
            }
            else{
                prev=curr;
                curr=curr->next;
            }
            
        }
        return dummy->next;

    }
};
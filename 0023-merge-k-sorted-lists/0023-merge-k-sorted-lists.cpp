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
ListNode* f(ListNode* l1, ListNode* l2){
    ListNode dummy;
    ListNode* tail = &dummy;
    while(l1 != nullptr && l2 != nullptr){
        if(l1->val < l2->val){
            tail->next = l1;
            l1 = l1->next;
        }
        else{
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    if(l1 != nullptr)tail->next = l1;
    else tail->next = l2;
    return dummy.next;
}
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()){
            return nullptr;
        }
        int step = 1;
        int n = lists.size();
        while(step < n){
            for(int i = 0 ; i + step < n ; i += step * 2){
                lists[i] = f(lists[i], lists[i + step]);
            }
            step *= 2;
        }
        return lists[0];
    }
};
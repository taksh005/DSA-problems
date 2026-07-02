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
    void reorderList(ListNode* head) {
        int n = 0;
        ListNode* temp = head;
        stack<ListNode*> st;
        while(temp != nullptr){
            st.push(temp);
            temp = temp->next;
            n++;
        }
        ListNode* ans = head;
        for(int i = 0;i < n/2; i++){
            ListNode* element = st.top();
            st.pop();
            element->next = ans->next;
            ans->next = element;
            ans = ans->next->next;
        }
        ans->next= NULL;
    }
};
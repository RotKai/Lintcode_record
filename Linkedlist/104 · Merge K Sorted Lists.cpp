/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */

    struct comp {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // write your code here
        priority_queue<ListNode*, vector<ListNode*>, comp>q;
        for (auto list:lists){
           if (list) q.push(list);
        }
        
        ListNode *head = new ListNode();
        ListNode *cur = head;
        while (!q.empty()){
            auto tp = q.top(); q.pop();
            cur->next = tp;
            cur = cur->next;
            if (tp->next) q.push(tp->next);
        }

        return head->next;
        }
};

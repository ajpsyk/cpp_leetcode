#include <vector>
#include <tuple>
#include <queue>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        typedef std::tuple<int, int, ListNode*> Tuple;
        std::priority_queue<Tuple, std::vector<Tuple>, std::greater<Tuple>> min_heap;
        int i = 0;
        for (ListNode* head : lists)
        {
            if (head)
            {
                min_heap.push(std::make_tuple(head->val, i++, head));
            }
        }

        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        while (!min_heap.empty())
        {
            auto [val, i, node] = min_heap.top();
            min_heap.pop();
            curr->next = node;
            curr = curr->next;
            if (node->next)
            {
                min_heap.push(std::make_tuple(node->next->val, i, node->next));
            }
        }

        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};
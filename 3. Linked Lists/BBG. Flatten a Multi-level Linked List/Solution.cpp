struct MultiLevelListNode {
    int val;
    MultiLevelListNode *next;
    MultiLevelListNode *child;
    MultiLevelListNode() : val(0), next(nullptr), child(nullptr) {}
    MultiLevelListNode(int x) : val(x), next(nullptr), child(nullptr) {}
    MultiLevelListNode(int x, MultiLevelListNode *next, MultiLevelListNode *child)
        : val(x), next(next), child(child) {}
};


MultiLevelListNode* flatten_multi_level_list(MultiLevelListNode* head) {
    if (!head) return nullptr;

    MultiLevelListNode* tail = head;
    while (tail->next) {
        tail = tail->next;
    }

    MultiLevelListNode* curr = head;
    while (curr) {
        if (curr->child) {
            tail->next = curr->child;
            curr->child = nullptr;

            while (tail->next) {
                tail = tail->next;
            }
        }
        curr = curr->next;
    }

    return head;
}

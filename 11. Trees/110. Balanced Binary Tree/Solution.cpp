#include <cmath>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return recurse(root) != -1;
    }

    int recurse(TreeNode* root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        int left = recurse(root->left);
        int right = recurse(root->right);

        if (std::abs(left - right) > 1)
        {
            return -1;
        }

        if (left == -1 || right == -1)
        {
            return -1;
        }

        return std::max(left, right) + 1;
    }
};
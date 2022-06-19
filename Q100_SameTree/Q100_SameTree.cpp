#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p != nullptr && q != nullptr) {
        if (p->val != q->val) {
            return false;
        }
        else if (p->val == q->val) {
            if (isSameTree(p->left, q->left) == false) {
                return false;
            }
            if (isSameTree(p->right, q->right) == false) {
                return false;
            }
        }
    }

    if (p == nullptr && q != nullptr) {
        return false;
    }

    if (q == nullptr && p != nullptr) {
        return false;
    }

    return true;
}

int main()
{
    TreeNode p3(3, nullptr, nullptr);
    TreeNode p2(2, nullptr, nullptr);
    TreeNode p1(1, &p3, &p2);

    TreeNode p32(3, nullptr, nullptr);
    TreeNode p22(3, nullptr, nullptr);
    TreeNode p12(1, &p32, &p22);

    cout << isSameTree(&p1, &p12) << endl;

    return 0;
}

// Nazbii
// 1123547
// 24.11.28

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode
{

    int v;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : v(x), left(nullptr), right(nullptr) {}
};

TreeNode *Treeb(vector<int> &level)
{
    if (level.empty() || level[0] == -1)
        return nullptr;

    TreeNode *root = new TreeNode(level[0]);
    queue<TreeNode *> q;
    q.push(root);
}

// Q3 Given a non-empty binary tree, find the maximum path sum. A path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.The function should return an integer representing the maximum path sum.


#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
int maxPathSum(node *root, int &maxi)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftSum = max(0, maxPathSum(root->left, maxi));
    int rightSum = max(0, maxPathSum(root->right, maxi));
    maxi = max(maxi, leftSum + rightSum + root->data);
    return max(leftSum, rightSum) + root->data;
}
int main()
{
    int maxi = INT_MIN;
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    maxPathSum(root,maxi);
    cout <<maxi;
    return 0;
}

    //       1 
    //     /   \
    //    2     3

//Max path sum is 2 + 1 + 3 = 6
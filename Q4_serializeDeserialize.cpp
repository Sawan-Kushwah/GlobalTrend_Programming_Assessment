// Q4 Design an algorithm to serialize and deserialize a binary tree. Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment. Implement the serialize and deserialize methods

#include <iostream>
#include <string>
#include <queue>
#include <sstream>
#include <algorithm> 

using namespace std;

class Codec {
public:
    int getValue(const string& str) {
        if (str[0] == 'N') {
            string s = str;
            s.erase(remove(s.begin(), s.end(), 'N'), s.end());
            return -stoi(s);
        } else {
            return stoi(str);
        }
    }

    string serialize(TreeNode* root) {
        if (root == NULL) {
            return "#";
        }

        queue<TreeNode*> q;
        q.push(root);
        stringstream sb;

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr == NULL) {
                sb << "#,";
            } else {
                if (curr->val < 0) {
                    sb << "N" << -curr->val << ",";
                } else {
                    sb << curr->val << ",";
                }
                q.push(curr->left);
                q.push(curr->right);
            }
        }

        string result = sb.str();
        while (!result.empty() && (result[result.size() - 1] == '#' || result[result.size() - 1] == ',')) {
            result.pop_back();
        }
        return result;
    }

    TreeNode* deserialize(const string& data) {
        stringstream ss(data);
        string value;
        getline(ss, value, ',');

        if (value == "#") {
            return NULL;
        }

        int rootValue = getValue(value);
        TreeNode* root = new TreeNode(rootValue);
        queue<TreeNode*> q;
        q.push(root);

        while (getline(ss, value, ',')) {
            TreeNode* curr = q.front();
            q.pop();

            if (value != "#") {
                int leftVal = getValue(value);
                curr->left = new TreeNode(leftVal);
                q.push(curr->left);
            }

            if (!getline(ss, value, ',')) break;

            if (value != "#") {
                int rightVal = getValue(value);
                curr->right = new TreeNode(rightVal);
                q.push(curr->right);
            }
        }

        return root;
    }
};

 

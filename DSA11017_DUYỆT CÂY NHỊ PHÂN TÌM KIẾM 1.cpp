#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define pf push_front
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

struct node {
    int val;
    node* right;
    node* left;
    node(int x) {
        val = x;
        left = right = NULL;
    }
};


void insertNode(node* &root, int x) {
    if (root == NULL) {
        root = new node(x);
        return;
    }
    else {
        if (root -> val > x)
            insertNode(root -> left, x);
        else
            insertNode(root -> right, x);
    }
}

void postOrder(node* root) {
    if (root == NULL) return;
    if (root -> left) postOrder(root->left);
    if (root -> right) postOrder(root->right);
    cout << root -> val << ' ';
}

int main() {
    fast_io;
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        node* root = NULL;
        while (n--) {
            int x; cin >> x;
            insertNode(root, x);
        }
        postOrder(root);
        cout << endl;
    }
    return 0;
}
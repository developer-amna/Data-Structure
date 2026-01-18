// Program # 1

#include <iostream>
#include <windows.h>   
using namespace std;

struct node {
    int n;
    node *left;
    node *right;
};

class BST {
private:
    node *s, *c, *t;
public:
    BST(void) {
        s = NULL;
    }
    void create(int);
};

// gotoxy function (Windows API)
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void BST::create(int data) {
    int col = 40, row = 1;
    if(s == NULL) {
        s = new node;
        s->n = data;
        s->left = s->right = NULL;
        gotoxy(col,row);
        cout << data;
    }
    else {
        node *p;
        c = s;
        while(c != NULL) {
            if(c->n == data) {
                cout << "\nData already exists.";
                return;
            }
            else if(c->n < data) {
                p = c;
                c = c->right;
                row += 2;
                col += 6;
            }
            else {
                p = c;
                c = c->left;
                row += 2;
                col -= 6;
            }
        }
        t = new node;
        t->n = data;
        t->left = t->right = NULL;
        gotoxy(col,row);
        cout << data;
        if(p->n > data)
            p->left = t;
        else
            p->right = t;
    }
}

int main() {
    BST obj;
    int x[] = {22,33,21,76,88,43,34,11,89,55};
    for(int i=0; i < 10; i++)
        obj.create(x[i]);
    return 0;
}

// program # 2

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

static int idx = -1;

Node* buildTree(int preorder[], int n) {
    idx++;
    if (idx >= n || preorder[idx] == -1) {
        return NULL;
    }
    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder, n);
    root->right = buildTree(preorder, n);
    return root;
}
void preOrder(Node* root) {
	if (root == NULL) {
		return;
	}
	cout << root->data << " ";
	preOrder(root->left);
	preOrder(root->right);
}


int main() {
    int preorder[] = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    int n = sizeof(preorder) / sizeof(preorder[0]);

    Node* root = buildTree(preorder, n);

    
    
    preOrder(root);
    cout << endl;

    return 0;
}
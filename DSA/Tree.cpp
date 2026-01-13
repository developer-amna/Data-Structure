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
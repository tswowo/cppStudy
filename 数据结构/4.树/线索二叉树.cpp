#include <iostream>
#include <string>

typedef struct Node
{
    char data;
    struct Node *lchild, *rchild;
    int ltag, rtag;
    Node(char data) : data(data), lchild(NULL), rchild(NULL), ltag(0), rtag(0) {};
} node, *tree;

tree createTree()
{
    char in;
    std::cin >> in;
    if (in == '@')
        return NULL;
    tree root = new node(in);
    root->lchild = createTree();
    root->rchild = createTree();
    return root;
}

tree copyTree(tree tarRoot)
{
    if (!tarRoot)
        return NULL;
    tree root = new node(tarRoot->data);
    root->lchild = copyTree(tarRoot->lchild);
    root->rchild = copyTree(tarRoot->rchild);
    return root;
}

void inThreadHelper(tree root, tree &pre)
{
    if (!root)
        return;
    inThreadHelper(root->lchild, pre);
    if (!root->lchild)
    {
        root->lchild = pre;
        root->ltag = 1;
    }
    if (pre && !pre->rchild)
    {
        pre->rchild = root;
        pre->rtag = 1;
    }
    pre = root;
    inThreadHelper(root->rchild, pre);
}

tree inThread(tree t)
{
    tree root = copyTree(t);
    tree pre = NULL;
    inThreadHelper(root, pre);
    return root;
}

void preThreadHelper(tree root, tree &pre)
{
    if (!root)
        return;
    if (!root->lchild)
    {
        root->lchild = pre;
        root->ltag = 1;
    }
    if (pre && !pre->rchild)
    {
        pre->rchild = root;
        pre->rtag = 1;
    }
    pre = root;
    if (root->ltag == 0)
        preThreadHelper(root->lchild, pre);
    if (root->rtag == 0)
        preThreadHelper(root->rchild, pre);
}

tree preThread(tree t)
{
    tree root = copyTree(t);
    tree pre = NULL;
    preThreadHelper(root, pre);
    return root;
}

void postThreadHelper(tree root, tree &pre)
{
    if (!root)
        return;
    if (root->ltag == 0)
        postThreadHelper(root->lchild, pre);
    if (root->rtag == 0)
        postThreadHelper(root->rchild, pre);
    if (!root->lchild)
    {
        root->lchild = pre;
        root->ltag = 1;
    }
    if (pre && !pre->rchild)
    {
        pre->rchild = root;
        pre->rtag = 1;
    }
    pre = root;
}

tree postThread(tree t)
{
    tree root = copyTree(t);
    tree pre = NULL;
    postThreadHelper(root, pre);
    return root;
}

std::string inOrder(tree p)
{
    if (!p)
        return "empty tree";
    std::string res = "";
    while (p && p->ltag == 0)
        p = p->lchild;
    while (p)
    {
        res += p->data;
        if (p->rtag == 1)
        {
            p = p->rchild;
        }
        else
        {
            p = p->rchild;
            while (p && p->ltag == 0)
                p = p->lchild;
        }
    }
    return res;
}

int main()
{
    // AB@D@@C@@
    tree t = createTree();
    std::string in = inOrder(inThread(t));
    std::cout << "中序遍历: " << in << std::endl;   // 输出 BDAC
    return 0;
}

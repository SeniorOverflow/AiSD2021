#include<iostream>
using namespace std;
struct nodetree {
	int value;
	struct nodetree* parent;
	struct nodetree* child;
	struct nodetree* left;
	struct nodetree* right;
};
struct nodetree  *addnode(int x, nodetree* tree) {
    if (tree == NULL) { // Если дерева нет, то формируем корень
        tree = new nodetree; // память под узел
        tree->value = x;   // поле данных
        tree->left = NULL;
        tree->right = NULL; // ветви инициализируем пустотой
    }
    else  if (x < *&(tree)->value)   // условие добавление левого потомка
        tree->left = addnode(x, tree->left);
    else    // условие добавление правого потомка
        tree->right = addnode(x, tree->right);
    return(tree);
}
struct nodetree* searchtree(int x, nodetree* tree) {
    if (tree == NULL) return NULL;
    if (tree->value == x) return tree;
    if (x < *&(tree)->value) return searchtree(x,tree->left);
    else  return searchtree(x, tree->right);

}
struct nodetree* findmaxnode(nodetree* tree) {
    if (tree == NULL) return NULL;
    nodetree* max;
    max = 0;
    while (max->right != NULL) {
        max = max->right;
    }
    return max;
}
struct nodetree* findminnode(nodetree* tree) {
    if (tree == NULL) return NULL;
    nodetree* min;
    min = tree;
    while (min->left != NULL) {
        min = min->left;
    }
    return min;
}
struct nodetree* insert(nodetree** tree, int x, nodetree* parent) {
    nodetree* p;
    if (*tree != NULL) {
        p = malloc(sizeof(tree));
        p->value = x;
        p->left = p->right = NULL;
        p->parent = parent;
        *tree = p;
    }
    if (x < (*(tree))->value) return insert(&((*tree)->left), x, *tree);
    else  return insert(&((*tree)->right), x,*tree);
}
void DeleteNodeFromBinary(nodetree* node, int value)
{
    if (node == NULL)
        return;

    if (value < node->value)
        return DeleteNodeFromBinary(node->left, value);
    else if (value > node->value)
        return DeleteNodeFromBinary(node->right, value);
    else {
        if (node->left == NULL && node->right == NULL) {
            if (node->parent->left == node)
                node->parent->left = NULL;
            else
                node->parent->right = NULL;
            delete node;
        }
        else {
            nodetree* newnode = NULL;
            if (node->left != NULL) {
                newnode = Rightmost(node->left);
            }
            else
               * newnode = Leftmost(node->right);

            if (node->parent->left == node)
                node->parent->left = newnode;
            else
                node->parent->right = newnode;

            newnode->parent = node->parent;
            newnode->right = node->right;
            newnode->left = node->left;

            delete node;
        }
    }
}
nodetree Leftmost(nodetree* node) {
    if (node == NULL)
        return ;
    if (node->left != NULL) {
        return Leftmost(node->left);
    }
    return *node;
}
nodetree* Rightmost(nodetree* node) {
    if (node == NULL)
        return NULL;
    if (node->right != NULL) {
        return Rightmost(node->right);
    }
    return node;
}
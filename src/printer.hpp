#ifndef PRINTER_HPP
#define PRINTER_HPP
#include "ast.hpp"
#include <iostream>

static void printTree(ASTNode* n, int depth=0) {
    if (!n) return;
    printTree(n->right, depth+1);
    for(int i=0;i<depth;i++) std::cout << "   ";
    std::cout << n->value << std::endl;
    printTree(n->left, depth+1);
}

static void printPrefix(ASTNode* n) {
    if(!n) return;
    std::cout << n->value << " ";
    printPrefix(n->left);
    printPrefix(n->right);
}

static void printPostfix(ASTNode* n) {
    if(!n) return;
    printPostfix(n->left);
    printPostfix(n->right);
    std::cout << n->value << " ";
}
#endif

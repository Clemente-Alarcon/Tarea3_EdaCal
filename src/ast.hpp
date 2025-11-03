#ifndef AST_HPP
#define AST_HPP
#include <string>

struct ASTNode {
    std::string value;
    ASTNode* left;
    ASTNode* right;
    ASTNode(std::string v) : value(v), left(nullptr), right(nullptr) {}
    bool isLeaf() const { return !left && !right; }
};
#endif

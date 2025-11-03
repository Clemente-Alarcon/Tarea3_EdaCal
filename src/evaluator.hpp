#ifndef EVALUATOR_HPP
#define EVALUATOR_HPP
#include "ast.hpp"
#include "utils.hpp"
#include <cmath>
#include <cctype>

static double eval(ASTNode* n, VarMap& vars) {
    if (!n) return 0;
    if (n->isLeaf()) {
        if (std::isdigit(static_cast<unsigned char>(n->value[0])) ||
           ((n->value[0]=='-'||n->value[0]=='+') && n->value.size()>1 && std::isdigit(static_cast<unsigned char>(n->value[1]))))
            return std::stod(n->value);
        return getVar(n->value, vars);
    }
    std::string op = n->value;
    if (op=="sqrt") return std::sqrt(eval(n->right, vars));
    double L = eval(n->left, vars);
    double R = eval(n->right, vars);
    if (op=="+") return L+R;
    if (op=="-") return L-R;
    if (op=="*") return L*R;
    if (op=="/") return L/R;
    if (op=="^") return std::pow(L,R);
    return 0;
}
#endif

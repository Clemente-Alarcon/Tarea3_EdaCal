#include <iostream>
#include <string>
#include "parser.hpp"
#include "evaluator.hpp"
#include "printer.hpp"
#include "utils.hpp"

int main() {
    VarMap vars;
    setVar("ans", 0, vars);
    ASTNode* last = nullptr;
    std::string line;

    while (true) {
        std::cout << "Bienvenido a EdaCal";
        std::cout << ">> ";
        if (!std::getline(std::cin, line)) break;
        if (line=="exit") break;

        if (line=="tree") { if(last) printTree(last); continue; }
        if (line=="postfix") { if(last){ printPostfix(last); std::cout<<std::endl; } continue; }
        if (line=="prefix") { if(last){ printPrefix(last); std::cout<<std::endl; } continue; }

        if (line.rfind("show ",0)==0) {
            std::string var = line.substr(5);
            std::cout << var << " -> " << getVar(var, vars) << std::endl;
            continue;
        }

        LinkedList<Token> tokens = tokenize(line);
        Node<Token>* h = tokens.getHead();

        if (h && h->next && h->next->data.type==ASSIGN) {
            std::string var = h->data.value;
            LinkedList<Token> rest;
            for(Node<Token>* p=h->next->next; p; p=p->next) rest.insertBack(p->data);

            LinkedList<Token> post = infixToPostfix(rest);
            ASTNode* tree = buildAST(post);
            double val = eval(tree, vars);
            setVar(var, val, vars);
            setVar("ans", val, vars);
            last = tree;
            std::cout << var << " -> " << val << std::endl;
            std::cout << "ans -> " << val << std::endl;
        } else {
            LinkedList<Token> post = infixToPostfix(tokens);
            ASTNode* tree = buildAST(post);
            double val = eval(tree, vars);
            setVar("ans", val, vars);
            last = tree;
            std::cout << "ans -> " << val << std::endl;
        }
    }
    return 0;
}

#ifndef PARSER_HPP
#define PARSER_HPP
#include "stack.hpp"
#include "linkedlist.hpp"
#include "token.hpp"
#include "ast.hpp"
#include <cctype>
#include <sstream>
#include <map>
#include <string>

static std::map<std::string,int> prec = {
    {"+",1}, {"-",1}, {"*",2}, {"/",2}, {"^",3}, {"sqrt",4}
};

static bool rightAssoc(const std::string& op) {
    return op == "^";
}

static bool isNumberToken(const std::string& s){
    if (s.empty()) return false;
    if (std::isdigit(static_cast<unsigned char>(s[0]))) return true;
    if ((s[0]=='-' || s[0]=='+') && s.size()>1 && std::isdigit(static_cast<unsigned char>(s[1]))) return true;
    return false;
}

static LinkedList<Token> tokenize(const std::string& expr) {
    LinkedList<Token> tokens;
    std::stringstream ss(expr);
    std::string t;
    while (ss >> t) {
        if (isNumberToken(t)) tokens.insertBack(Token(NUMBER,t,std::stod(t)));
        else if (std::isalpha(static_cast<unsigned char>(t[0]))) {
            if (t == "sqrt") tokens.insertBack(Token(FUNC,t));
            else tokens.insertBack(Token(IDENT,t));
        }
        else if (t == "(") tokens.insertBack(Token(LPAREN,t));
        else if (t == ")") tokens.insertBack(Token(RPAREN,t));
        else if (t == "=") tokens.insertBack(Token(ASSIGN,t));
        else tokens.insertBack(Token(OP,t));
    }
    return tokens;
}

static LinkedList<Token> infixToPostfix(LinkedList<Token>& list) {
    LinkedList<Token> output;
    Stack<Token> ops;
    for (Node<Token>* p = list.getHead(); p; p = p->next) {
        Token tk = p->data;
        if (tk.type==NUMBER || tk.type==IDENT) {
            output.insertBack(tk);
        } else if (tk.type==FUNC) {
            ops.push(tk);
        } else if (tk.type==OP) {
            while(!ops.isEmpty()) {
                Token top = ops.top();
                if (top.type==OP || top.type==FUNC) {
                    int pt = prec[top.value], pc = prec[tk.value];
                    bool cond = (pt > pc) || (pt == pc && !rightAssoc(tk.value));
                    if (cond) { output.insertBack(ops.pop()); continue; }
                }
                break;
            }
            ops.push(tk);
        } else if (tk.type==LPAREN) {
            ops.push(tk);
        } else if (tk.type==RPAREN) {
            while(!ops.isEmpty() && ops.top().type!=LPAREN)
                output.insertBack(ops.pop());
            if(!ops.isEmpty() && ops.top().type==LPAREN) ops.pop();
            if(!ops.isEmpty() && ops.top().type==FUNC)
                output.insertBack(ops.pop());
        }
    }
    while(!ops.isEmpty()) output.insertBack(ops.pop());
    return output;
}

static ASTNode* buildAST(LinkedList<Token>& post) {
    Stack<ASTNode*> st;
    for (Node<Token>* p = post.getHead(); p; p = p->next) {
        Token tk = p->data;
        if (tk.type==NUMBER || tk.type==IDENT) {
            st.push(new ASTNode(tk.value));
        } else if (tk.type==FUNC) {
            ASTNode* a = st.pop();
            ASTNode* node = new ASTNode(tk.value);
            node->right = a;
            st.push(node);
        } else if (tk.type==OP) {
            ASTNode* b = st.pop();
            ASTNode* a = st.pop();
            ASTNode* node = new ASTNode(tk.value);
            node->left = a;
            node->right = b;
            st.push(node);
        }
    }
    return st.pop();
}
#endif

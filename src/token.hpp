#ifndef TOKEN_HPP
#define TOKEN_HPP
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <cctype>
#include <vector>
#include <map>
#include <algorithm>
#include <stdexcept>

enum TokenType { NUMBER, IDENT, OP, FUNC, LPAREN, RPAREN, ASSIGN };

struct Token {
    TokenType type;
    std::string value;
    double numValue;
    Token(TokenType t = NUMBER, std::string v = "", double n = 0.0)
        : type(t), value(v), numValue(n) {}
};
#endif

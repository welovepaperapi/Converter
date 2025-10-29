#pragma once
#include <string>
#include <vector>

enum class TokenType { Keyword, Identifier, Symbol, Literal };

struct Token {
    TokenType type;
    std::string value;
    int line;
};

class Lexer {
public:
    Lexer(const std::string& src);
    std::vector<Token> tokenize();

private:
    std::string source;
    size_t pos;
    int line;

    bool isKeyword(const std::string& word);
};

#include "Lexer.h"
#include <cctype>

Lexer::Lexer(const std::string& src) : source(src), pos(0), line(1) {}

std::vector<Token> Lexer::tokenize() {
    std::vector<Token> tokens;
    while (pos < source.size()) {
        char c = source[pos];
        if (isspace(c)) {
            if (c == '\n') line++;
            pos++;
        } else if (isalpha(c) || c == '_') {
            std::string word;
            while (isalnum(source[pos]) || source[pos] == '_') {
                word += source[pos++];
            }
            tokens.push_back({isKeyword(word) ? TokenType::Keyword : TokenType::Identifier, word, line});
        } else if (c == '{' || c == '}' || c == '(' || c == ')' || c == ';') {
            tokens.push_back({TokenType::Symbol, std::string(1, c), line});
            pos++;
        } else {
            pos++; // Skip unknown characters
        }
    }
    return tokens;
}

bool Lexer::isKeyword(const std::string& word) {
    return word == "class" || word == "public" || word == "void" || word == "int" ||
           word == "String" || word == "static";
}

#include "JavaToCppConverter.h"
#include "Lexer.h"
#include "AST.h"
#include "CodeGenerator.h"
#include <fstream>
#include <sstream>

std::string JavaToCppConverter::convertFile(const std::string& filepath) {
    std::ifstream file(filepath);
    if (!file) return "// Error: Could not open file\n";

    std::ostringstream buffer;
    buffer << file.rdbuf();
    std::string source = buffer.str();

    Lexer lexer(source);
    auto tokens = lexer.tokenize();

    ClassNode cls;
    for (size_t i = 0; i < tokens.size(); ++i) {
        if (tokens[i].type == TokenType::Keyword && tokens[i].value == "class") {
            if (i + 1 < tokens.size() && tokens[i + 1].type == TokenType::Identifier) {
                cls.name = tokens[i + 1].value;
                break;
            }
        }
    }

    CodeGenerator generator;
    return generator.generate(&cls);
}

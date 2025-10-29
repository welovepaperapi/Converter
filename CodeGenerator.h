#pragma once
#include <string>
#include "AST.h"

class CodeGenerator {
public:
    std::string generate(const ClassNode* cls);
};

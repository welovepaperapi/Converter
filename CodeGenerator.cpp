#include "CodeGenerator.h"
#include <sstream>

std::string CodeGenerator::generate(const ClassNode* cls) {
    std::ostringstream oss;
    oss << "#include <iostream>\n\n";
    oss << "class " << cls->name << " {\npublic:\n    // Methods go here\n};\n";
    return oss.str();
}

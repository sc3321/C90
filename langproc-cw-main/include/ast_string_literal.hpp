#ifndef AST_STRING_LITERAL_HPP
#define AST_STRING_LITERAL_HPP

#include "ast_node.hpp"

class StringLiteral : public Node {
private:
    char value_;

public:
    StringLiteral(char value) : value_(value) {}

    void EmitRISC(std::ostream &stream, Context &context) const override; 
    void Print(std::ostream &stream) const override;

};

#endif

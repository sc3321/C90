#ifndef AST_INITIALIZER_HPP
#define AST_INITIALIZER_HPP

#include "ast_node.hpp"

class Initializer : public Node {
public:
    Node* declarator_;
    Node* value_;

    Initializer(Node* declarator) : declarator_(declarator), value_(nullptr) {}
    Initializer(Node* declarator, Node* value) : declarator_(declarator), value_(value) {}

    void EmitRISC(std::ostream &stream, Context &context) const override;
    void Print(std::ostream &stream) const override;
    std::string getname(Context &context) const override;

    // Other necessary methods...
};


#endif
#ifndef AST_DECLARATION_HPP
#define AST_DECLARATION_HPP

#include "ast_node.hpp"

class Declaration : public Node {
public:
    Node* declaration_specifier_;
    Node* declarator_list_;

    Declaration(Node* declarationspecifier, Node* declarator_list) : declaration_specifier_(declarationspecifier), declarator_list_(declarator_list) {}

    ~Declaration()
    {
        delete declaration_specifier_;
        delete declarator_list_ ;
    };
    void EmitRISC(std::ostream &stream, Context &context) const override;
    void Print(std::ostream &stream) const override;
    std::string getname(Context &context) const override;

    // Other necessary methods...
};


#endif
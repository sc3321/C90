#ifndef AST_FUNCTION_DEFINITION_HPP
#define AST_FUNCTION_DEFINITION_HPP

#include "ast_node.hpp"

class FunctionDefinition : public Node
{
private:
    Node *declaration_specifiers_;
    Node *declarator_;
    NodeList *declaration_list;
    NodeList *compound_statement_;

public:
    FunctionDefinition(Node *declaration_specifiers, Node *declarator,  NodeList *compound_statement) : declaration_specifiers_(declaration_specifiers), declarator_(declarator), declaration_list(nullptr), compound_statement_(compound_statement){};
    FunctionDefinition(Node *declaration_specifiers, Node *declarator, NodeList *declaration_list, NodeList *compound_statement) : declaration_specifiers_(declaration_specifiers), declarator_(declarator), declaration_list(declaration_list), compound_statement_(compound_statement){};
    ~FunctionDefinition()
    {
        delete declaration_specifiers_;
        delete declarator_;
       // delete declaration_list;
        delete compound_statement_;
    };
    void EmitRISC(std::ostream &stream, Context &context) const override;
    void Print(std::ostream &stream) const override;
};

#endif

#ifndef AST_PARAMETER_HPP
#define AST_PARAMETER_HPP

#include "ast_node.hpp"

// Assuming you have classes or structures for type specifiers and declarators
// Include them here. Adjust includes according to your project structure.
#include "ast_type_specifier.hpp"
#include "ast_identifier.hpp"
#include "ast_direct_declarator.hpp"

class Parameter : public Node {
private:
    Node* type_; // Or use the actual class name for type specifiers
   // DirectDeclarator* declarator_; // Or use the actual class name for declarators
    Node* identifier_;

public:
    Parameter(Node* type, Node* identifier)
        : type_(type), identifier_(identifier) {}

    ~Parameter() {
        delete type_;
        delete identifier_;
    }

    // Implement virtual methods from Node or specific methods for this class
    void Print(std::ostream &stream) const override;

    void EmitRISC(std::ostream &stream, Context &context) const override;
};

#endif // AST_PARAMETER_HPP

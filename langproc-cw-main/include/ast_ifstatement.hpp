#ifndef AST_IFSTATEMENT_HPP
#define AST_IFSTATEMENT_HPP

#include "ast_node.hpp"

class IfStatement : public Node {
public:
    Node* cond_;
    Node* res_;
  //  bool integer;

   // IfStatement(Node* declarator) : declarator_(declarator), value_(nullptr) {}
    IfStatement(Node* cond, Node* res) : cond_(cond), res_(res) {}
   // Assignment(Node* declarator, Node* value, bool integer) : declarator_(declarator), value_(value), integer(integer) {}

    void EmitRISC(std::ostream &stream, Context &context) const override;
    void Print(std::ostream &stream) const override;
    std::string getname(Context &context) const override;

    // Other necessary methods...
};


#endif
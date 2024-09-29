#ifndef AST_WHILE_HPP
#define AST_WHILE_HPP

#include "ast_node.hpp"

class While : public Node {
public:
    Node* cond_;
    Node* res_;
  //  Node* elsecond_;
  //  bool integer;

   // IfStatement(Node* declarator) : declarator_(declarator), value_(nullptr) {}
    While(Node* cond, Node* res) : cond_(cond), res_(res) {}
   // Assignment(Node* declarator, Node* value, bool integer) : declarator_(declarator), value_(value), integer(integer) {}

    void EmitRISC(std::ostream &stream, Context &context) const override;
    void Print(std::ostream &stream) const override;
    std::string getname(Context &context) const override;

    // Other necessary methods...
};


#endif
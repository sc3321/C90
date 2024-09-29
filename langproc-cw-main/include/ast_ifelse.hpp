#ifndef AST_IFELSE_HPP
#define AST_IFELSE_HPP

#include "ast_node.hpp"

class IfElse : public Node {
public:
    Node* cond_;
    Node* res_;
    Node* elsecond_;
  //  bool integer;

   // IfStatement(Node* declarator) : declarator_(declarator), value_(nullptr) {}
    IfElse(Node* cond, Node* res, Node* elsecond) : cond_(cond), res_(res), elsecond_(elsecond) {}
   // Assignment(Node* declarator, Node* value, bool integer) : declarator_(declarator), value_(value), integer(integer) {}

    void EmitRISC(std::ostream &stream, Context &context) const override;
    void Print(std::ostream &stream) const override;
    std::string getname(Context &context) const override;

    // Other necessary methods...
};


#endif
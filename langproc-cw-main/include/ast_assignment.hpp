#ifndef AST_ASSIGNMENT_HPP
#define AST_ASSIGNMENT_HPP

#include "ast_node.hpp"

class Assignment : public Node {
public:
    Node* declarator_;
    Node* value_;
  //  bool integer;

    Assignment(Node* declarator) : declarator_(declarator), value_(nullptr) {}
    Assignment(Node* declarator, Node* value) : declarator_(declarator), value_(value) {}
   // Assignment(Node* declarator, Node* value, bool integer) : declarator_(declarator), value_(value), integer(integer) {}

    void EmitRISC(std::ostream &stream, Context &context) const override;
    void Print(std::ostream &stream) const override;
    std::string getname(Context &context) const override;

    // Other necessary methods...
};


#endif
#ifndef AST_DIRECT_DECLARATOR_HPP
#define AST_DIRECT_DECLARATOR_HPP

#include "ast_node.hpp"


class DirectDeclarator : public Node
{
private:
    Node *identifier_;
    NodeList *parameters_;
    std::string varname;

public:
    DirectDeclarator(Node *identifier) : identifier_(identifier), parameters_(nullptr) {}
    DirectDeclarator(Node *identifier, NodeList *parameters) : identifier_(identifier), parameters_(parameters) {}
    ~DirectDeclarator()
    {
        delete identifier_;
        if (parameters_ != nullptr) { 
            delete parameters_;
        }
    };
    void EmitRISC(std::ostream &stream, Context &context) const override;
    void Print(std::ostream &stream) const override;
    // std::string getname(Context &context) const override {
    //     const Identifier* temp = dynamic_cast<const Identifier*>(identifier_);
    //     return temp->getname();
    // }
   // void getname(void);
    std::string getname(Context &context) const override;

};

#endif

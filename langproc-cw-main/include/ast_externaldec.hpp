#ifndef AST_EXTERNALDEC_HPP
#define AST_EXTERNALDEC_HPP

#include "ast_node.hpp"

class ExternalDec : public Node
{
private:
    //std::string identifier_;

public:
    Node* externaldec_;
    ExternalDec(Node* identifier) : externaldec_(identifier){};

    ~ExternalDec(){};
    void EmitRISC(std::ostream &stream, Context &context) const override;
    void Print(std::ostream &stream) const override;
    std::string getname(Context &context) const override{
        return externaldec_->getname(context);
    }
    //void Return(std::ostream &stream, Context &context);
};

#endif

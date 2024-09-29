#ifndef AST_IDENTIFIER_HPP
#define AST_IDENTIFIER_HPP

#include "ast_node.hpp"

class Identifier : public Node
{
private:
    //std::string identifier_;

public:
    std::string identifier_;
    Identifier(std::string identifier) : identifier_(identifier){};

    ~Identifier(){};
    void EmitRISC(std::ostream &stream, Context &context) const override;
    void Print(std::ostream &stream) const override;
    std::string getname(Context &context) const override{
        return identifier_ ;
    }
    //void Return(std::ostream &stream, Context &context);
};

#endif

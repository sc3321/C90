#ifndef AST_RETURNINT_HPP
#define AST_RETURNINT_HPP

#include "ast_node.hpp"

class Returnint : public Node
{
private:
    //std::string identifier_;

public:
    int identifier_;
    Returnint(int identifier) : identifier_(identifier){};

    ~Returnint(){};
    void EmitRISC(std::ostream &stream, Context &context) const override;
    void Print(std::ostream &stream) const override;
    std::string getname(Context &context) const override;
    //void Return(std::ostream &stream, Context &context);
};

#endif
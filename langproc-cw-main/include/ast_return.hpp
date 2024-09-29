#ifndef AST_RETURN_HPP
#define AST_RETURN_HPP

#include "ast_node.hpp"

class Return : public Node
{
private:
    //std::string identifier_;

public:
    std::string identifier_;
    Return(std::string identifier) : identifier_(identifier){};

    ~Return(){};
    void EmitRISC(std::ostream &stream, Context &context) const override;
    void Print(std::ostream &stream) const override;
    std::string getname(Context &context) const override;
    //void Return(std::ostream &stream, Context &context);
};

#endif
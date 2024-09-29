#include "ast_returnint.hpp"

void Returnint::EmitRISC(std::ostream &stream, Context &context) const
{
    stream << "li x10, " << identifier_;
}

void Returnint::Print(std::ostream &stream) const
{
    stream << identifier_ ;
}

std::string Returnint::getname(Context &context) const {



    return std::to_string(identifier_) ;

}

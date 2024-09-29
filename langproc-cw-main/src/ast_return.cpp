#include "ast_return.hpp"

void Return::EmitRISC(std::ostream &stream, Context &context) const
{
    int var = context.getRegisterForVariable(identifier_);

    stream << "mv x10, " << "x" << var;
}

void Return::Print(std::ostream &stream) const
{
    stream << identifier_ ;
}

std::string Return::getname(Context &context) const {

    return identifier_ ;

}

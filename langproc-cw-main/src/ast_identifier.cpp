#include "ast_identifier.hpp"

void Identifier::EmitRISC(std::ostream &stream, Context &context) const
{
    stream << identifier_ ;
}

void Identifier::Print(std::ostream &stream) const
{
    stream << identifier_ ;
}

// void Identifier::Return(std::ostream &stream, Context &context) {

//     int varreg = context.getRegisterForVariable(identifier_);

//     stream << "mv a0 " << "a" << varreg << std::endl;

// }
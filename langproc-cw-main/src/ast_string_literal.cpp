#include "ast_string_literal.hpp"

void StringLiteral::EmitRISC(std::ostream &stream, Context &context) const  
{
    stream << "li a0, " << /*static_cast<int>(value_)*/ value_ << std::endl;
}

void StringLiteral::Print(std::ostream &stream) const
{
    stream << value_;
}

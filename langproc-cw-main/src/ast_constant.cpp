#include "ast_constant.hpp"

void IntConstant::EmitRISC(std::ostream &stream, Context &context) const
{
    stream << "li x10, " << value_ << std::endl;
}

void IntConstant::Print(std::ostream &stream) const
{
    stream << value_;
}

std::string IntConstant::getname(Context &context) const {

    std::string myStr = std::to_string(value_);
    return myStr;

}

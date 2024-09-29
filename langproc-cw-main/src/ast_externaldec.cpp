#include "ast_externaldec.hpp"

void ExternalDec::EmitRISC(std::ostream &stream, Context &context) const
{
    std::string varname = externaldec_->getname(context);
    int reg = context.allocateRegister();
    context.mapVariableToRegister(varname, reg);

}

void ExternalDec::Print(std::ostream &stream) const
{
    stream << "" ;
}

// void DirectDeclarator::getname(void) {
    
//     identifier_->

// }


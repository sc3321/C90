#include "ast_parameter.hpp"



void Parameter::EmitRISC(std::ostream &stream, Context &context) const
{
    
    std::string paramname = identifier_->getname(context);
    int reg = context.allocateParamRegister();
    context.mapVariableToRegister(paramname,reg);



    
}





void Parameter::Print(std::ostream &stream) const {
    // Example print implementation. Adjust to your needs.
    type_->Print(stream);
    stream << " ";
    identifier_->Print(stream);
}


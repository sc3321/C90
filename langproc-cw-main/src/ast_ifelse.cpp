#include "ast_ifelse.hpp"

void IfElse::EmitRISC(std::ostream &stream, Context &context) const {

    std::string varname = cond_->getname(context);

    int reg1;

    if(context.getRegisterForVariable(varname) == -1){
        reg1 = context.allocateRegister();
        context.mapVariableToRegister(varname, reg1);
    }
    else{
        reg1 = context.getRegisterForVariable(varname);
    }

    cond_->EmitRISC(stream, context);

   // int tmpreg = context.allocateRegister();

   // stream << std::endl << "li x10" << ", " << 1 << std::endl;
    stream << std::endl << "beqz x10" << ", ELSE" << std::endl;
    res_->EmitRISC(stream, context);
    stream << "J NEXT" << std::endl;
    stream << "ELSE: " << std::endl;
    elsecond_->EmitRISC(stream, context);
    stream << "NEXT: " << std::endl;


}

void IfElse::Print(std::ostream &stream) const {
    stream << "" ;
}

std::string IfElse::getname(Context &context) const{
    return " ";
}
#include "ast_while.hpp"

void While::EmitRISC(std::ostream &stream, Context &context) const {

    // std::string varname = cond_->getname(context);

    // int reg1;

    // if(context.getRegisterForVariable(varname) == -1){
    //     reg1 = context.allocateRegister();
    //     context.mapVariableToRegister(varname, reg1);
    // }
    // else{
    //     reg1 = context.getRegisterForVariable(varname);
    // }
    stream << "START: " << std::endl;
    cond_->EmitRISC(stream, context);

   // int tmpreg = context.allocateRegister();

   // stream << std::endl << "li x10" << ", " << 1 << std::endl;
    //stream << "START: " << std::endl;
    stream << std::endl << "beqz x10" << ", ELSE" << std::endl;
    res_->EmitRISC(stream, context);
    stream << "J START" << std::endl;
    stream << "ELSE: " << std::endl;



}

void While::Print(std::ostream &stream) const {
    stream << "" ;
}

std::string While::getname(Context &context) const{
    return " ";
}
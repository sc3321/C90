#include "ast_initializer.hpp"

void Initializer::EmitRISC(std::ostream &stream, Context &context) const
{
    std::string variablename = declarator_->getname(context);

    int reg = context.getRegisterForVariable(variablename);
    if (reg == -1) { // If the variable is not yet associated with a register
        reg = context.allocateRegister(); // Allocate a new register
        context.mapVariableToRegister(variablename, reg); // Map the variable to the new register
    }

    if(value_ != nullptr) {
        int varval = std::stoi(value_->getname(context));

        if(varval > 12288){
            int tmp = varval - 12288;
            stream << "li x" << reg << "," << " " << varval-tmp << std::endl;
            stream << "addi x" << reg << "," << "x" << reg << "," << " " << tmp << std::endl;

        }
        else{
            stream << "li x" << reg << "," << " " << varval << std::endl;
        }
    }

    else {
        stream << "li x" << reg << "," << 0 << std::endl;
    }



}

void Initializer::Print(std::ostream &stream) const
{
    stream << "" ;
}

std::string Initializer::getname(Context &context) const {
    return declarator_->getname(context);
}



// void DirectDeclarator::getname(void) {
    
//     identifier_->

// }


#include "ast_assignment.hpp"

void Assignment::EmitRISC(std::ostream &stream, Context &context) const
{
    std::string variablename = declarator_->getname(context);

    int reg = context.getRegisterForVariable(variablename);
    if (reg == -1) { // If the variable is not yet associated with a register
        reg = context.allocateRegister(); // Allocate a new register
        context.mapVariableToRegister(variablename, reg); // Map the variable to the new register
    }


    std::string rhs = value_->getname(context);

    if(rhs == "false") {
        value_->EmitRISC(stream, context);
        stream << std::endl << "mv x" << reg << "," << " x10" << std::endl;
    }

    else{
        int reg2 = context.getRegisterForVariable(rhs);
        if(reg2 == -1) {
        
            int varval = std::stoi(rhs);
            if(varval > 12288){
                int tmp = varval - 12288;
                stream << "li x" << reg << "," << " " << varval-tmp << std::endl;
                stream << "addi x" << reg << "," << "x" << reg << "," << " " << tmp << std::endl;
            }
            else{
                stream << "li x" << reg << "," << " " << varval << std::endl;
            }
            
        }

        else{
            stream << "mv x" << reg << "," << " " << "x" << reg2 << std::endl;
        }

    }




    //int reg2 = context.getRegisterForVariable(rhs);

    // if (reg2 == -1) { 
    //     int varval = std::stoi(rhs);

    //     if(varval > 12288){
    //         int tmp = varval - 12288;
    //         stream << "li x" << reg << "," << " " << varval-tmp << std::endl;
    //         stream << "addi x" << reg << "," << "x" << reg << "," << " " << tmp << std::endl;

    //     }
    //     else{
    //         stream << "li x" << reg << "," << " " << varval << std::endl;
    //     }
    // }

    // else{
    //     if(rhs != "false"){
    //         stream << "mv x" << reg << "," << " x" << reg2 << std::endl;
    //     }
    //     else{
    //         value_->EmitRISC(stream, context);
    //         stream << "mv x" << reg << "," << " x10" << std::endl;
    //     }
    // }





}

void Assignment::Print(std::ostream &stream) const
{
    stream << "" ;
}

std::string Assignment::getname(Context &context) const {
    return declarator_->getname(context);
}



// void DirectDeclarator::getname(void) {
    
//     identifier_->

// }


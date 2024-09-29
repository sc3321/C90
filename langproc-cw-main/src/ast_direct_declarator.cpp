#include "ast_direct_declarator.hpp"
#include "ast_initializer.hpp"

void DirectDeclarator::EmitRISC(std::ostream &stream, Context &context) const
{
    identifier_->EmitRISC(stream, context);
    if(parameters_ != nullptr) {
        stream << ":" << std::endl;
        for (auto param : parameters_->GetNodes()){
            if (param == nullptr){
                continue;
            }
            // std::string paramname = identifier_->getname(context);
            param->EmitRISC(stream, context);
        }

    }
    else{
        stream << ":" << std::endl;
    }
}

void DirectDeclarator::Print(std::ostream &stream) const
{
    identifier_->Print(stream);
    if (parameters_ != nullptr) {
        stream << "(";
        parameters_->Print(stream);
        stream << ")";
    }
}

std::string DirectDeclarator::getname(Context &context) const{

    identifier_->getname(context);
}

// void DirectDeclarator::getname(void) {
    
//     identifier_->

// }


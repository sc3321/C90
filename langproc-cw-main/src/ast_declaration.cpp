#include "ast_declaration.hpp"



void Declaration::EmitRISC(std::ostream &stream, Context &context) const {

    declarator_list_->EmitRISC(stream, context);

    std::string var = declarator_list_->getname(context);

    int output = context.getRegisterForVariable(var);

    stream << "mv x0 " << "x" << output << std::endl;

}

void Declaration::Print(std::ostream &stream) const {

    declaration_specifier_->Print(stream);
    stream << " " ;

    declarator_list_->Print(stream);



}

std::string Declaration::getname(Context &context) const {
    return declarator_list_->getname(context);
}


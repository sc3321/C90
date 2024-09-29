#include "ast_binoperator.hpp"
#include <iostream>

void Operators::EmitRISC(std::ostream &stream, Context &context) const {}

void AddOperator::EmitRISC(std::ostream &stream, Context &context) const {
    
    std::string leftop = left->getname(context);

    int reg1, reg2;
    
    if(context.getRegisterForVariable(leftop) == -1){
        reg1 = context.allocateRegister();
        context.mapVariableToRegister(leftop, reg1);
    }
    else{
        reg1 = context.getRegisterForVariable(leftop);
    }

    std::string rightop = right->getname(context);

    if(context.getRegisterForVariable(rightop) == -1){
        reg2 = context.allocateRegister();
        context.mapVariableToRegister(rightop, reg2);
        right->EmitRISC(stream, context);
        stream << "add x" << reg2 << ", x10, x0" << std::endl;
    }
    else{
        reg2 = context.getRegisterForVariable(rightop);
    }

    stream << "add " << "x10, " << "x" << reg1 << ", " << "x" << reg2 ;


}

void SubOperator::EmitRISC(std::ostream &stream, Context &context) const {


    std::string leftop = left->getname(context);

    int reg1, reg2;
    
    if(context.getRegisterForVariable(leftop) == -1){
        reg1 = context.allocateRegister();
        context.mapVariableToRegister(leftop, reg1);
    }
    else{
        reg1 = context.getRegisterForVariable(leftop);
    }

    std::string rightop = right->getname(context);

    if(context.getRegisterForVariable(rightop) == -1){
        reg2 = context.allocateRegister();
        context.mapVariableToRegister(rightop, reg2);
        right->EmitRISC(stream, context);
        stream << std::endl;
        stream << "add x" << reg2 << ", x10, x0" << std::endl;
    }
    else{
        reg2 = context.getRegisterForVariable(rightop);
    }

    stream << "sub " << "x10, " << "x" << reg1 << ", " << "x" << reg2 ;


}

void MulOperator::EmitRISC(std::ostream &stream, Context &context) const {


    std::string leftop = left->getname(context);

    int reg1, reg2;
    
    if(context.getRegisterForVariable(leftop) == -1){
        reg1 = context.allocateRegister();
        context.mapVariableToRegister(leftop, reg1);
    }
    else{
        reg1 = context.getRegisterForVariable(leftop);
    }

    std::string rightop = right->getname(context);

    if(context.getRegisterForVariable(rightop) == -1){
        reg2 = context.allocateRegister();
        context.mapVariableToRegister(rightop, reg2);
    }
    else{
        reg2 = context.getRegisterForVariable(rightop);
    }

    stream << "mul " << "x10, " << "x" << reg1 << ", " << "x" << reg2 ;


}

void DivOperator::EmitRISC(std::ostream &stream, Context &context) const {

    std::string leftop = left->getname(context);

    int reg1, reg2;
    
    if(context.getRegisterForVariable(leftop) == -1){
        reg1 = context.allocateRegister();
        context.mapVariableToRegister(leftop, reg1);
    }
    else{
        reg1 = context.getRegisterForVariable(leftop);
    }

    std::string rightop = right->getname(context);

    if(context.getRegisterForVariable(rightop) == -1){
        reg2 = context.allocateRegister();
        context.mapVariableToRegister(rightop, reg2);
    }
    else{
        reg2 = context.getRegisterForVariable(rightop);
    }

    stream << "div " << "x10, " << "x" << reg1 << ", " << "x" << reg2 ;
}

void EqualOperator::EmitRISC(std::ostream &stream, Context &context) const {

    std::string leftop = left->getname(context);

    int reg1, reg2;
    
    if(context.getRegisterForVariable(leftop) == -1){
        reg1 = context.allocateRegister();
        context.mapVariableToRegister(leftop, reg1);
    }
    else{
        reg1 = context.getRegisterForVariable(leftop);
    }

    std::string rightop = right->getname(context);

    if(context.getRegisterForVariable(rightop) == -1){
        reg2 = context.allocateRegister();
        context.mapVariableToRegister(rightop, reg2);
    }
    else{
        reg2 = context.getRegisterForVariable(rightop);
    }

    int reg3 = context.allocateRegister();
    stream << "sub x" << reg3 << ", x" << reg1 << ", " << "x" << reg2 << std::endl;
    stream << "seqz x" << reg1 << ", x" << reg3 << std::endl;
}

void LessThanOperator::EmitRISC(std::ostream &stream, Context &context) const {

    std::string leftop = left->getname(context);

    int reg1, reg2;
    
    if(context.getRegisterForVariable(leftop) == -1){
        reg1 = context.allocateRegister();
        context.mapVariableToRegister(leftop, reg1);
    }
    else{
        reg1 = context.getRegisterForVariable(leftop);
    }

    std::string rightop = right->getname(context);

    if(context.getRegisterForVariable(rightop) == -1){
        reg2 = context.allocateRegister();
        context.mapVariableToRegister(rightop, reg2);
        right->EmitRISC(stream, context);
        stream << std::endl;
        stream << "add x" << reg2 << ", x10, x0" << std::endl;
    }
    else{
        reg2 = context.getRegisterForVariable(rightop);
    }

    stream << "slt " << "x10, " << "x" << reg1 << ", " << "x" << reg2 << std::endl;
    //stream << "seqz " << "x" << reg2 << ", x10" << std::endl;
}

void BiggerThanOperator::EmitRISC(std::ostream &stream, Context &context) const {

    std::string leftop = left->getname(context);

    int reg1, reg2;
    
    if(context.getRegisterForVariable(leftop) == -1){
        reg1 = context.allocateRegister();
        context.mapVariableToRegister(leftop, reg1);
    }
    else{
        reg1 = context.getRegisterForVariable(leftop);
    }

    std::string rightop = right->getname(context);

    if(context.getRegisterForVariable(rightop) == -1){
        reg2 = context.allocateRegister();
        context.mapVariableToRegister(rightop, reg2);
        right->EmitRISC(stream, context);
        stream << std::endl;
        stream << "add x" << reg2 << ", x10, x0" << std::endl;
    }
    else{
        reg2 = context.getRegisterForVariable(rightop);
    }

    stream << "slt " << "x10, " << "x" << reg2 << ", " << "x" << reg1 << std::endl;
    //stream << "seqz " << "x" << reg2 << ", x10" << std::endl;
}


void LessThanEqualOperator::EmitRISC(std::ostream &stream, Context &context) const {

    std::string leftop = left->getname(context);

    int reg1, reg2;
    
    if(context.getRegisterForVariable(leftop) == -1){
        reg1 = context.allocateRegister();
        context.mapVariableToRegister(leftop, reg1);
    }
    else{
        reg1 = context.getRegisterForVariable(leftop);
    }

    std::string rightop = right->getname(context);

    if(context.getRegisterForVariable(rightop) == -1){
        reg2 = context.allocateRegister();
        context.mapVariableToRegister(rightop, reg2);
    }
    else{
        reg2 = context.getRegisterForVariable(rightop);
    }
    
    int reg3 = context.allocateRegister();
    stream << "slt " << "x10, " << "x" << reg1 << ", " << "x" << reg2 << std::endl;
    stream << "seqz x10, " << "x" << reg1 << std::endl;
}


void AndOperator::EmitRISC(std::ostream &stream, Context &context) const {


    std::string leftop = left->getname(context);

    int reg1, reg2;
    
    if(context.getRegisterForVariable(leftop) == -1){
        reg1 = context.allocateRegister();
        context.mapVariableToRegister(leftop, reg1);
    }
    else{
        reg1 = context.getRegisterForVariable(leftop);
    }

    std::string rightop = right->getname(context);

    if(context.getRegisterForVariable(rightop) == -1){
        reg2 = context.allocateRegister();
        context.mapVariableToRegister(rightop, reg2);
    }
    else{
        reg2 = context.getRegisterForVariable(rightop);
    }

    stream << "and " << "x10, " << "x" << reg1 << ", " << "x" << reg2 ;
}

void OrOperator::EmitRISC(std::ostream &stream, Context &context) const {


    std::string leftop = left->getname(context);

    int reg1, reg2;
    
    if(context.getRegisterForVariable(leftop) == -1){
        reg1 = context.allocateRegister();
        context.mapVariableToRegister(leftop, reg1);
    }
    else{
        reg1 = context.getRegisterForVariable(leftop);
    }

    std::string rightop = right->getname(context);

    if(context.getRegisterForVariable(rightop) == -1){
        reg2 = context.allocateRegister();
        context.mapVariableToRegister(rightop, reg2);
    }
    else{
        reg2 = context.getRegisterForVariable(rightop);
    }

    stream << "or " << "x10, " << "x" << reg1 << ", " << "x" << reg2 ;
}

void XOrOperator::EmitRISC(std::ostream &stream, Context &context) const {


    std::string leftop = left->getname(context);

    int reg1, reg2;
    
    if(context.getRegisterForVariable(leftop) == -1){
        reg1 = context.allocateRegister();
        context.mapVariableToRegister(leftop, reg1);
    }
    else{
        reg1 = context.getRegisterForVariable(leftop);
    }

    std::string rightop = right->getname(context);

    if(context.getRegisterForVariable(rightop) == -1){
        reg2 = context.allocateRegister();
        context.mapVariableToRegister(rightop, reg2);
    }
    else{
        reg2 = context.getRegisterForVariable(rightop);
    }

    stream << "xor " << "x10, " << "x" << reg1 << ", " << "x" << reg2 ;


}

void LogAndOperator::EmitRISC(std::ostream &stream, Context &context) const {

    std::string leftop = left->getname(context);

    int reg1, reg2;
    
    if(context.getRegisterForVariable(leftop) == -1){
        reg1 = context.allocateRegister();
        context.mapVariableToRegister(leftop, reg1);
    }
    else{
        reg1 = context.getRegisterForVariable(leftop);
    }

    std::string rightop = right->getname(context);

    if(context.getRegisterForVariable(rightop) == -1){
        reg2 = context.allocateRegister();
        context.mapVariableToRegister(rightop, reg2);
    }
    else{
        reg2 = context.getRegisterForVariable(rightop);
    }

    int reg3 = context.allocateRegister();
    stream << "li x" << reg3 << ", " << 0 << std::endl;
    stream << "beqz x" << reg1 << ", end" << std::endl;
    stream << "beqz x" << reg2 << ", end" << std::endl;
    stream << "li x" << reg3 << ", " << 1 << std::endl;
    stream << "end: " << std::endl;
    stream << "mv x10, " << "x" << reg3;
}

void LogOrOperator::EmitRISC(std::ostream &stream, Context &context) const {

    std::string leftop = left->getname(context);

    int reg1, reg2;
    
    if(context.getRegisterForVariable(leftop) == -1){
        reg1 = context.allocateRegister();
        context.mapVariableToRegister(leftop, reg1);
    }
    else{
        reg1 = context.getRegisterForVariable(leftop);
    }

    std::string rightop = right->getname(context);

    if(context.getRegisterForVariable(rightop) == -1){
        reg2 = context.allocateRegister();
        context.mapVariableToRegister(rightop, reg2);
    }
    else{
        reg2 = context.getRegisterForVariable(rightop);
    }

    int reg3 = context.allocateRegister();
    stream << "li x" << reg3 << ", " << 0 << std::endl;
    stream << "bnez x" << reg1 << ", L1" << std::endl;
    stream << "bnez x" << reg2 << ", L1" << std::endl;
    stream << "j end" << std::endl;
    stream << "L1: " << std::endl;
    stream << "li x" << reg3 << ", " << 1 << std::endl;
    stream << "end: " << std::endl;
    stream << "mv x10, " << "x" << reg3;
}

void Operators::Print(std::ostream &stream) const {}


void AddOperator::Print(std::ostream &stream) const {
    stream << "(";
    left->Print(stream);
    stream << " + ";
    right->Print(stream);
    stream << ")";
}

void SubOperator::Print(std::ostream &stream) const {
    stream << "(";
    left->Print(stream);
    stream << " - ";
    right->Print(stream);
    stream << ")";
}

// void SubOperator::getname(Context const) const {

// }

void MulOperator::Print(std::ostream &stream) const {
    stream << "(";
    left->Print(stream);
    stream << " * ";
    right->Print(stream);
    stream << ")";
}

void DivOperator::Print(std::ostream &stream) const {
    stream << "(";
    left->Print(stream);
    stream << " / ";
    right->Print(stream);
    stream << ")";
}

void EqualOperator::Print(std::ostream &stream) const {
    stream << "(";
    left->Print(stream);
    stream << " == ";
    right->Print(stream);
    stream << ")";
}

void LessThanOperator::Print(std::ostream &stream) const {
    stream << "(";
    left->Print(stream);
    stream << " < ";
    right->Print(stream);
    stream << ")";
}

void BiggerThanOperator::Print(std::ostream &stream) const {
    stream << "(";
    left->Print(stream);
    stream << " > ";
    right->Print(stream);
    stream << ")";
}
void LessThanEqualOperator::Print(std::ostream &stream) const {
    stream << "(";
    left->Print(stream);
    stream << " > ";
    right->Print(stream);
    stream << ")";
}
void AndOperator::Print(std::ostream &stream) const {
    stream << "(";
    left->Print(stream);
    stream << " and ";
    right->Print(stream);
    stream << ")";
}

void OrOperator::Print(std::ostream &stream) const {
    stream << "(";
    left->Print(stream);
    stream << " or ";
    right->Print(stream);
    stream << ")";
}

void XOrOperator::Print(std::ostream &stream) const {
    stream << "(";
    left->Print(stream);
    stream << " xor ";
    right->Print(stream);
    stream << ")";
}

void LogAndOperator::Print(std::ostream &stream) const {
    stream << "(";
    left->Print(stream);
    stream << " && ";
    right->Print(stream);
    stream << ")";
}

void LogOrOperator::Print(std::ostream &stream) const {
    stream << "(";
    left->Print(stream);
    stream << " || ";
    right->Print(stream);
    stream << ")";
}

// void Operators::compile(std::ostream &stream, Context &context, int destReg) const {}


// void AddOperator::compile(std::ostream &stream, Context &context, int destReg) const {

//     int LeftReg = context.allocateRegister();
// //    context.mapVariableToRegister("x", LeftReg);
//     left->compile(stream, context, LeftReg);

//     int RightReg = context.allocateRegister();
// //    context.mapVariableToRegister("y", RightReg);
//     right->compile(stream, context, RightReg);
    
// //    int LeftReg = getLeft(stream, context, destReg);
// //    int RightReg = getRight(stream, context, destReg);
//     stream << "add a0, a" << LeftReg << ", a" << RightReg << std::endl;
//     context.freeRegister(LeftReg);
//     context.freeRegister(RightReg);
// }
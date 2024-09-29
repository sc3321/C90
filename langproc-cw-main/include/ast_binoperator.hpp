#ifndef AST_OPERATORS_HPP
#define AST_OPERATORS_HPP

#include "ast.hpp"
#include "ast_node.hpp"
#include "ast_context.hpp"

#include <string>
#include <iostream>
#include <cmath>


class Operators : public Node
{
private:

public:
    Node* left;
    Node* right;
    Operators( Node* _left, Node* _right) : left(_left), right(_right) {}
//    virtual ~Operators() = default;
    virtual ~Operators() {delete left; delete right;}

    virtual const std::string getOpcode() const = 0;

    void Print(std::ostream &stream) const override;
    void EmitRISC(std::ostream &stream, Context &context) const override;
    std::string getname(Context &context) const override{
        return "false";
    };

};

class AddOperator : public Operators 
{
private:

protected:
    virtual const std::string getOpcode() const override
        { return "+"; }
public:
    AddOperator(Node* _left,Node* _right) : Operators(_left,_right) {}

    void EmitRISC(std::ostream &stream, Context &context) const override;
    void Print(std::ostream &stream) const override;

};

class SubOperator : public Operators 
{
private:
protected:
    virtual const std::string getOpcode() const override
        { return "-"; }
public:
    SubOperator(Node* _left, Node* _right) : Operators(_left,_right) {}
    void Print(std::ostream &stream) const override;
    void EmitRISC(std::ostream &stream, Context &context) const override;
    // std::string getname(Context &context) {
    //     return "false";
    // }
};

class MulOperator : public Operators 
{
private:
protected:
    virtual const std::string getOpcode() const override
        { return "-"; }
public:
    MulOperator(Node* _left, Node* _right) : Operators(_left,_right) {}
    void Print(std::ostream &stream) const override;
    void EmitRISC(std::ostream &stream, Context &context) const override;
};

class DivOperator : public Operators 
{
private:
protected:
    virtual const std::string getOpcode() const override
        { return "-"; }
public:
    DivOperator(Node* _left, Node* _right) : Operators(_left,_right) {}
    void Print(std::ostream &stream) const override;
    void EmitRISC(std::ostream &stream, Context &context) const override;
};

class EqualOperator : public Operators 
{
private:
protected:
    virtual const std::string getOpcode() const override
        { return "-"; }
public:
    EqualOperator(Node* _left, Node* _right) : Operators(_left,_right) {}
    void Print(std::ostream &stream) const override;
    void EmitRISC(std::ostream &stream, Context &context) const override;
};

class LessThanOperator : public Operators 
{
private:
protected:
    virtual const std::string getOpcode() const override
        { return "-"; }
public:
    LessThanOperator(Node* _left, Node* _right) : Operators(_left,_right) {}
    void Print(std::ostream &stream) const override;
    void EmitRISC(std::ostream &stream, Context &context) const override;
};

class BiggerThanOperator : public Operators 
{
private:
protected:
    virtual const std::string getOpcode() const override
        { return "-"; }
public:
    BiggerThanOperator(Node* _left, Node* _right) : Operators(_left,_right) {}
    void Print(std::ostream &stream) const override;
    void EmitRISC(std::ostream &stream, Context &context) const override;
};

class LessThanEqualOperator : public Operators 
{
private:
protected:
    virtual const std::string getOpcode() const override
        { return "-"; }
public:
    LessThanEqualOperator(Node* _left, Node* _right) : Operators(_left,_right) {}
    void Print(std::ostream &stream) const override;
    void EmitRISC(std::ostream &stream, Context &context) const override;
};

class AndOperator : public Operators 
{
private:
protected:
    virtual const std::string getOpcode() const override
        { return "-"; }
public:
    AndOperator(Node* _left, Node* _right) : Operators(_left,_right) {}
    void Print(std::ostream &stream) const override;
    void EmitRISC(std::ostream &stream, Context &context) const override;
};

class OrOperator : public Operators 
{
private:
protected:
    virtual const std::string getOpcode() const override
        { return "-"; }
public:
    OrOperator(Node* _left, Node* _right) : Operators(_left,_right) {}
    void Print(std::ostream &stream) const override;
    void EmitRISC(std::ostream &stream, Context &context) const override;
};


class XOrOperator : public Operators 
{
private:
protected:
    virtual const std::string getOpcode() const override
        { return "-"; }
public:
    XOrOperator(Node* _left, Node* _right) : Operators(_left,_right) {}
    void Print(std::ostream &stream) const override;
    void EmitRISC(std::ostream &stream, Context &context) const override;
};

class LogAndOperator : public Operators 
{
private:
protected:
    virtual const std::string getOpcode() const override
        { return "-"; }
public:
    LogAndOperator(Node* _left, Node* _right) : Operators(_left,_right) {}
    void Print(std::ostream &stream) const override;
    void EmitRISC(std::ostream &stream, Context &context) const override;
};

class LogOrOperator : public Operators 
{
private:
protected:
    virtual const std::string getOpcode() const override
        { return "-"; }
public:
    LogOrOperator(Node* _left, Node* _right) : Operators(_left,_right) {}
    void Print(std::ostream &stream) const override;
    void EmitRISC(std::ostream &stream, Context &context) const override;
};






#endif
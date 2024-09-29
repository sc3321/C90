#ifndef AST_CONTEXT_HPP
#define AST_CONTEXT_HPP

#include <vector>
#include <string>
#include <map>
#include <stdexcept>


class Context {
public:
    // Keeps track of registers currently in use; true if in use, false otherwise.
    std::vector<bool> registersInUse;

    // Maps variable names to their corresponding registers, if any.
    std::map<std::string, int> variableRegisterMap;
    std::map<std::string, int> variableStackOffset;

    Context() : registersInUse(32, false) { // Example: for a CPU with 32 general-purpose registers.
        // Initialize registers specific to the calling convention as in use if needed
    }

    // Marks a register as in use and returns the register number.
    int allocateRegister() {
        const std::array<int, 12> availableRegisters = {5, 6, 7, 28, 29, 30, 31};
        for (int reg : availableRegisters) {
            if (!registersInUse[reg]) {
                registersInUse[reg] = true;
                return reg;
            }
        }
        throw std::runtime_error("No free registers available");
    }

    int allocateParamRegister()
    {
        const std::array<int, 8> paramRegisters = {10, 11, 12, 13, 14, 15, 16, 17};
        for (int reg : paramRegisters)
        {
            if (!registersInUse[reg])
            {
                registersInUse[reg] = true;
                return reg;
            }
        }

        return -1;
    }


    // Frees a register, making it available for use again.
    void freeRegister(int reg) {
        if (reg >= 0 && reg < registersInUse.size()) {
            registersInUse[reg] = false;
        }
    }

    // Associates a variable with a register.
    void mapVariableToRegister(const std::string& variable, int reg) {
        variableRegisterMap[variable] = reg;
    }

    // Gets the register associated with a variable, if any.
    int getRegisterForVariable(const std::string& variable) const {
        auto it = variableRegisterMap.find(variable);
        if (it != variableRegisterMap.end()) {
            return it->second;
        }
        return -1; // Indicates no register associated
    }

    int bindVariableToStack(const std::string &variable, const std::string &variable_type)
    {
        static int stack_offset = -16;
        if (variable_type == "int")
        {
            stack_offset -= 4;
        }
        else if (variable_type == "double" || variable_type == "float")
        {
            stack_offset -= 8;
        }
        variableStackOffset[variable] = stack_offset;
        return stack_offset;
    }

};

    // Additional context management functions as needed...


#endif


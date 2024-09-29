#ifndef AST_HPP
#define AST_HPP

#include <iostream>
#include <string>
#include <vector>

#include "ast_direct_declarator.hpp"
#include "ast_function_definition.hpp"
#include "ast_identifier.hpp"
#include "ast_jump_statement.hpp"
#include "ast_node.hpp"
#include "ast_type_specifier.hpp"
#include "ast_constant.hpp"
#include "ast_string_literal.hpp"
#include "ast_context.hpp"
#include "ast_initializer.hpp"
#include "ast_parameter.hpp"
#include "ast_return.hpp"
#include "ast_externaldec.hpp"
#include "ast_assignment.hpp"
#include "ast_returnint.hpp"
#include "ast_binoperator.hpp"
#include "ast_ifstatement.hpp"
#include "ast_ifelse.hpp"
#include "ast_while.hpp"

extern Node *ParseAST(std::string file_name);

#endif

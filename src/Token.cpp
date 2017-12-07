/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Token.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <akaplyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 16:20:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/12/01 16:20:00 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Token.hpp"

// * STATICS **************************************************************** //
// * CONSTRUCTORS *********************************************************** //

Token::Token(const int line, const Token::eTokenType type,
			 const std::string &value, const IOperand::eOperandType &operand) :
		line(line), type(type), value(value), operandType(operand) {}

// * DESTRUCTORS ************************************************************ //
// * OPERATORS ************************************************************** //
// * GETTERS **************************************************************** //

Token::eTokenType Token::getType() const {
	return type;
}

const std::string &Token::getValue() const {
	return value;
}

IOperand::eOperandType Token::getOperandType() const {
	return operandType;
}

int Token::getLine() const {
	return line;
}

// * SETTERS **************************************************************** //
// * MEMBER FUNCTIONS / METHODS ********************************************* //
// * NESTED_CLASSES ********************************************************* //

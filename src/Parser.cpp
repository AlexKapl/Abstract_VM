/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <akaplyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 17:06:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/12/01 17:06:00 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Parser.hpp"

Parser::Pptr Parser::instructions[]{
		&Parser::push, &Parser::pop, &Parser::dump, &Parser::assert,
		&Parser::add, &Parser::sub, &Parser::mul, &Parser::div, &Parser::mod,
		&Parser::print, &Parser::exit
};

// * STATICS **************************************************************** //
// * CONSTRUCTORS *********************************************************** //

Parser::Parser(Lexer *lexer) :
		isExit(false), lexer(lexer), stack(), sstream() {
	lexer->tokenize();
}

// * DESTRUCTORS ************************************************************ //

Parser::~Parser() {
	for (IOperand const *operand: stack) {
		delete (operand);
	}
	delete(lexer);
}

// * OPERATORS ************************************************************** //
// * GETTERS **************************************************************** //
// * SETTERS **************************************************************** //
// * MEMBER FUNCTIONS / METHODS ********************************************* //

void Parser::printResult() {
	std::cout << lexer->getOut() << std::endl;
	if (ErrorHandler::isError()) {
		ErrorHandler::printErrors();
		ErrorHandler::clearErrors();
	}
	else {
		std::cout << sstream.str();
	}
}

void Parser::parse() {
	for (Token *token: lexer->getTokens()) {
		try {
			(this->*(instructions[token->getType()]))(token);
		}
		catch (std::exception &e) {
			std::stringstream ss;
			ss << "Parser: Line " << token->getLine() << ": " << e.what();
			ErrorHandler::addError(ss.str());
		}
		if (isExit)
			return;
	}
	throw NoExitException();
}

void Parser::push(Token *token) {
	this->stack.push(OperandFactory::makeOperand(
		token->getOperandType(), token->getValue()));
}

void Parser::pop(Token *) {
	if (stack.empty()) {
		throw PopException();
	}
	else {
		stack.pop();
	}
}

void Parser::dump(Token *) {
	if (stack.empty()) {
		throw DumpException();
	}
	std::for_each(stack.rbegin(), stack.rend(), [this](IOperand const *op) {
		this->sstream << op->toString() << std::endl;
	});
}

void Parser::getFromStack(IOperand const *&ptr) {
	if (stack.empty()) {
		throw StackException();
	}
	else {
		ptr = stack.top();
	}
}

void Parser::getFromStack(IOperand const *&lhs, IOperand const *&rhs) {
	if (stack.size() < 2) {
		throw StackException();
	}
	else {
		rhs = stack.top();
		stack.pop();
		lhs = stack.top();
		stack.pop();
	}
}

void Parser::assert(Token *token) {
	IOperand const *lhs, *rhs;

	getFromStack(lhs);
	rhs = OperandFactory::makeOperand(
			token->getOperandType(), token->getValue());
	if (lhs->getType() != rhs->getType() ||
			lhs->toString() != rhs->toString()) {
		delete(rhs);
		throw AssertException();
	}
	delete(rhs);
}

void Parser::add(Token *) {
	IOperand const *lhs, *rhs;

	getFromStack(lhs, rhs);
	stack.push(*lhs + *rhs);
	delete(lhs);
	delete(rhs);
}

void Parser::sub(Token *) {
	IOperand const *lhs, *rhs;

	getFromStack(lhs, rhs);
	stack.push(*lhs - *rhs);
	delete(lhs);
	delete(rhs);
}

void Parser::mul(Token *) {
	IOperand const *lhs, *rhs;

	getFromStack(lhs, rhs);
	stack.push(*lhs * *rhs);
	delete(lhs);
	delete(rhs);
}

void Parser::div(Token *) {
	IOperand const *lhs, *rhs;

	getFromStack(lhs, rhs);
	stack.push(*lhs / *rhs);
	delete(lhs);
	delete(rhs);
}

void Parser::mod(Token *) {
	IOperand const *lhs, *rhs;

	getFromStack(lhs, rhs);
	stack.push(*lhs % *rhs);
	delete(lhs);
	delete(rhs);
}

void Parser::print(Token *) {
	IOperand const *lhs;

	getFromStack(lhs);
	if (lhs->getType() != IOperand::Int8) {
		throw AssertException();
	}
	else {
		sstream << static_cast<char>(std::stoi(lhs->toString())) << std::endl;
	}
}

void Parser::exit(Token *) {
	isExit = true;
}

// * NESTED_CLASSES ********************************************************* //

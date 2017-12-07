/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <akaplyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 17:06:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/12/01 17:06:00 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_HPP
# define PARSER_HPP

#include "Lexer.hpp"
#include "OperandFactory.hpp"

class Parser {

public:
	typedef void (Parser::*Pptr)(Token *);

	Parser() = delete;

	Parser(Parser const &) = delete;

	explicit Parser(Lexer *lexer);

	Parser &operator=(Parser const &) = delete;

	~Parser();

	void parse();

	void printResult();

private:
	bool isExit;
	Lexer *lexer;
	MutantStack<IOperand const *> stack;
	std::stringstream sstream;

	static Pptr instructions[11];

	void getFromStack(IOperand const *&lhs, IOperand const *&rhs);

	void getFromStack(IOperand const *&ptr);

	void push(Token *token);

	void pop(Token *token);

	void dump(Token *token);

	void assert(Token *token);

	void add(Token *token);

	void sub(Token *token);

	void mul(Token *token);

	void div(Token *token);

	void mod(Token *token);

	void print(Token *token);

	void exit(Token *token);
};

#endif

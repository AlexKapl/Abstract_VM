/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Token.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <akaplyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 16:20:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/12/01 16:20:00 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef TOKEN_HPP
# define TOKEN_HPP

#include "IOperand.hpp"

class Token {

public:

	enum eTokenType {
		push, pop, dump, assert, add, sub, mul, div, mod, print, exit
	};

	Token() = delete;

	Token(Token const &) = delete;

	Token &operator=(Token const &) = delete;

	Token(const int line, const eTokenType type,
		  const std::string &value, const IOperand::eOperandType &operand);

	~Token() = default;

	eTokenType getType() const;

	const std::string &getValue() const;

	int getLine() const;

	IOperand::eOperandType getOperandType() const;

private:
	const int line;
	const eTokenType type;
	const std::string value;
	const IOperand::eOperandType operandType;
};


#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <akaplyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 15:34:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/12/01 15:34:00 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef LEXER_HPP
# define LEXER_HPP

#include "Token.hpp"

class Lexer {

public:
	Lexer();

	Lexer(Lexer const &) = delete;

	Lexer(const std::string &file, std::ifstream &ifstream);

	Lexer &operator=(Lexer const &assign) = delete;

	~Lexer();

	const std::vector<Token *> &getTokens() const;

	const std::string &getOut() const;

	void tokenize();

private:
	int num;
	std::string line;
	const std::string out;
	const bool isStd;
	std::istream &istream;
	std::vector<Token *> tokens;
	static const std::map<std::string, Token::eTokenType> tokenMap;
	static const std::map<std::string, IOperand::eOperandType> operandMap;

	void checkLine();

	void checkValue(std::string &str, IOperand::eOperandType &type);

	bool trimComment(std::string &str, size_t &pos);

	bool contain(const std::string &find) const;
};


#endif

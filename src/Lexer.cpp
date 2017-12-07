/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <akaplyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 15:34:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/12/01 15:34:00 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Lexer.hpp"

// * STATICS **************************************************************** //

const std::map<std::string, Token::eTokenType> Lexer::tokenMap = {
	std::pair<std::string, Token::eTokenType> ("push", Token::push),
	std::pair<std::string, Token::eTokenType> ("pop", Token::pop),
	std::pair<std::string, Token::eTokenType> ("dump", Token::dump),
	std::pair<std::string, Token::eTokenType> ("assert", Token::assert),
	std::pair<std::string, Token::eTokenType> ("add", Token::add),
	std::pair<std::string, Token::eTokenType> ("sub", Token::sub),
	std::pair<std::string, Token::eTokenType> ("mul", Token::mul),
	std::pair<std::string, Token::eTokenType> ("div", Token::div),
	std::pair<std::string, Token::eTokenType> ("mod", Token::mod),
	std::pair<std::string, Token::eTokenType> ("print", Token::print),
	std::pair<std::string, Token::eTokenType> ("exit", Token::exit)
};

const std::map<std::string, IOperand::eOperandType> Lexer::operandMap = {
	std::pair<std::string, IOperand::eOperandType> ("int8", IOperand::Int8),
	std::pair<std::string, IOperand::eOperandType> ("int16", IOperand::Int16),
	std::pair<std::string, IOperand::eOperandType> ("int32", IOperand::Int32),
	std::pair<std::string, IOperand::eOperandType> ("float", IOperand::Float),
	std::pair<std::string, IOperand::eOperandType> ("double", IOperand::Double)
};

// * CONSTRUCTORS *********************************************************** //

Lexer::Lexer() : num(0), line(), out("Stdin: "), isStd(true),
				 istream(std::cin), tokens() {}

Lexer::Lexer(const std::string &file, std::ifstream &ifstream) :
		num(0), line(), out("File: " + file), isStd(false),
		istream(ifstream), tokens() {
	ifstream.open(file);
	if (!ifstream) {
		throw OpenFileException();
	}
}

// * DESTRUCTORS ************************************************************ //

Lexer::~Lexer() {
	if (!isStd) {
		auto &ifstream = dynamic_cast<std::ifstream&>(istream);
		ifstream.close();
	}
}

// * OPERATORS ************************************************************** //
// * GETTERS **************************************************************** //

const std::string &Lexer::getOut() const {
	return this->out;
}

const std::vector<Token *> &Lexer::getTokens() const {
	return this->tokens;
}

// * SETTERS **************************************************************** //
// * MEMBER FUNCTIONS / METHODS ********************************************* //

bool Lexer::contain(const std::string &find) const {
	return Lexer::tokenMap.find(find) != Lexer::tokenMap.end();
}

void Lexer::tokenize() {
	bool end = false;

	while (!this->istream.eof()) {
		std::getline(this->istream, this->line);
		if (this->isStd && this->line == ";;") {
			end = true;
			break;
		}
		this->num++;
		try {
			checkLine();
		}
		catch (std::exception &e) {
			std::stringstream ss;
			ss << "Lexer: Line " << this->num << ": " << e.what();
			ErrorHandler::addError(ss.str());
		}
	}
	if (this->isStd && !end) {
		throw NoEndException();
	}
}

bool Lexer::trimComment(std::string &str, size_t &pos) {
	size_t tmp = str.find(';');

	if (tmp != std::string::npos) {
		pos = tmp;
		str = str.substr(0, pos);
		return true;
	}
	else {
		return false;
	}
}

void Lexer::checkValue(std::string &str, IOperand::eOperandType &type) {
	std::regex rx(
			R"(((?:int(?:8|16|32))|(?:float)|(?:double))\(([+-]?\d+(?:.?\d+)?)\))");
	std::cmatch results;
	if (!std::regex_match(str.c_str(), results, rx)) {
		throw ValueException();
	}
	else {
		type = Lexer::operandMap.at(results[1]);
		str = results[2];
	}
}

void Lexer::checkLine() {
	size_t i, comm = 0;
	Words words = split(this->line);
	std::string ins = words[0], val;
	IOperand::eOperandType type = IOperand::Int8;

	if ((trimComment(ins, comm) && comm == 0) || this->line.empty()) {
			return;
	}
	if (!contain(ins)) {
		throw InstructionException();
	}
	else if (ins == "push" || ins == "assert") {
		if (comm != 0 || words.size() < 2) {
			throw ValueException();
		}
		trimComment((val = words[1]), comm);
		checkValue(val, type);
	}
	for (i = 2; i < words.size() && words[i][0] != ';'; ++i) {
		if (!words[i].empty()) {
			throw CharsException();
		}
	}
	tokens.push_back(new Token(this->num, Lexer::tokenMap.at(ins), val, type));
}

// * NESTED_CLASSES ********************************************************* //

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <akaplyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 15:42:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/12/03 15:42:00 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef OPERAND_HPP
# define OPERAND_HPP

#include <utility>

#include "../includes/IOperand.hpp"
#include "../includes/OperandFactory.hpp"

class OperandFactory;

template<typename T>
class Operand : public IOperand {

public:
// * CONSTRUCTORS *********************************************************** //

	Operand() = delete;

	explicit Operand<char>(std::string const &str, char) :
				str_val(str), type(Int8), precision(type) {
		flow(std::stoll(str), type);
	};

	explicit Operand<short>(std::string const &str, short) :
				str_val(str), type(Int16), precision(type) {
		flow(std::stoll(str), type);
	};

	explicit Operand<int>(std::string const &str, int) :
				str_val(str), type(Int32), precision(type) {
		flow(std::stoll(str), type);
	};

	explicit Operand<float>(std::string const &str, float) :
				str_val(str), type(Float), precision(type) {
		flow(std::stold(str), type);
	};

	explicit Operand<double>(std::string const &str, double) :
				str_val(str), type(Double), precision(type) {
		flow(std::stold(str), type);
	};

	Operand(Operand const &) = delete;

// * DESTRUCTORS ************************************************************ //

	~Operand() override = default;

// * OPERATORS ************************************************************** //

	Operand &operator=(Operand const &) = delete;

	IOperand const *operator+(IOperand const &rhs) const override {
		eOperandType types = (type < rhs.getType() ? rhs.getType() : type);

		if (types < Float) {
			auto res = std::stoll(str_val) + std::stoll(rhs.toString());
			flow<long long>(res, types);
			return OperandFactory::makeOperand(types, std::to_string(res));
		}
		else {
			auto res = std::stold(str_val) + std::stold(rhs.toString());
			flow<long double>(res, types);
			return OperandFactory::makeOperand(types, std::to_string(res));
		}
	}

	IOperand const *operator-(IOperand const &rhs) const override {
		eOperandType types = (type < rhs.getType() ? rhs.getType() : type);

		if (types < Float) {
			auto res = std::stoll(str_val) - std::stoll(rhs.toString());
			flow<long long>(res, types);
			return OperandFactory::makeOperand(types, std::to_string(res));
		}
		else {
			auto res = std::stold(str_val) - std::stold(rhs.toString());
			flow<long double>(res, types);
			return OperandFactory::makeOperand(types, std::to_string(res));
		}
	}

	IOperand const *operator*(IOperand const &rhs) const override {
		eOperandType types = (type < rhs.getType() ? rhs.getType() : type);

		if (types < Float) {
			auto res = std::stoll(str_val) * std::stoll(rhs.toString());
			flow<long long>(res, types);
			return OperandFactory::makeOperand(types, std::to_string(res));
		}
		else {
			auto res = std::stold(str_val) * std::stold(rhs.toString());
			flow<long double>(res, types);
			return OperandFactory::makeOperand(types, std::to_string(res));
		}
	}

	IOperand const *operator/(IOperand const &rhs) const override {
		eOperandType types = (type < rhs.getType() ? rhs.getType() : type);

		if (std::stof(rhs.toString()) == 0.0) {
			throw ByZeroException();
		}
		if (types < Float) {
			auto res = std::stoll(str_val) / std::stoll(rhs.toString());
			flow<long long>(res, types);
			return OperandFactory::makeOperand(types, std::to_string(res));
		}
		else {
			auto res = std::stold(str_val) / std::stold(rhs.toString());
			flow<long double>(res, types);
			return OperandFactory::makeOperand(types, std::to_string(res));
		}
	}

	IOperand const *operator%(IOperand const &rhs) const override {
		eOperandType types = (type < rhs.getType() ? rhs.getType() : type);

		if (std::stof(rhs.toString()) == 0.0) {
			throw ByZeroException();
		}
		if (types < Float) {
			auto res = std::stoll(str_val) % std::stoll(rhs.toString());
			flow<long long>(res, types);
			return OperandFactory::makeOperand(types, std::to_string(res));
		}
		else {
			auto res = fmod(std::stold(str_val), std::stold(rhs.toString()));
			flow<long double>(res, types);
			return OperandFactory::makeOperand(types, std::to_string(res));
		}
	}

// * GETTERS **************************************************************** //

	int getPrecision() const override {
		return (this->precision);
	}

	eOperandType getType() const override {
		return (this->type);
	}

// * MEMBER FUNCTIONS / METHODS ********************************************* //

	template<typename L>
	void flow(L val, eOperandType type) const {
		switch (type) {
			case Int8:
				val > SCHAR_MAX ? throw OverflowException() : 0;
				val < SCHAR_MIN ? throw UnderflowException() : 0;
			case Int16:
				val > SHRT_MAX ? throw OverflowException() : 0;
				val < SHRT_MIN ? throw UnderflowException() : 0;
			case Int32:
				val > INT_MAX ? throw OverflowException() : 0;
				val < INT_MIN ? throw UnderflowException() : 0;
			case Float:
				val > FLT_MAX ? throw OverflowException() : 0;
				val < -FLT_MAX ? throw UnderflowException() : 0;
			case Double:
				val > DBL_MAX ? throw OverflowException() : 0;
				val < -DBL_MAX ? throw UnderflowException() : 0;
		}
	}

	std::string const &toString() const override {
		return (this->str_val);
	}

private:
	std::string str_val;
	const eOperandType type;
	const int precision;

};

#endif

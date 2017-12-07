/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandFactory.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <akaplyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 13:40:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/11/17 13:40:00 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/OperandFactory.hpp"
#include "Operand.cpp"

// * STATICS **************************************************************** //

OperandFactory::Optr OperandFactory::factories[] = {
		&OperandFactory::createInt8,
		&OperandFactory::createInt16,
		&OperandFactory::createInt32,
		&OperandFactory::createFloat,
		&OperandFactory::createDouble
};

const IOperand *OperandFactory::makeOperand(IOperand::eOperandType type,
									 std::string const &value) {
	static OperandFactory factory;

		return factory.createOperand(type, value);
}

// * CONSTRUCTORS *********************************************************** //
// * DESTRUCTORS ************************************************************ //
// * OPERATORS ************************************************************** //
// * GETTERS **************************************************************** //
// * SETTERS **************************************************************** //
// * MEMBER FUNCTIONS / METHODS ********************************************* //

IOperand const *OperandFactory::createOperand(IOperand::eOperandType type,
											  std::string const &value) const {
	return (this->*(factories[type]))(value);
}

IOperand const *OperandFactory::createInt8(std::string const &value) const {
	return new Operand<char>(value, '\0');
}

IOperand const *OperandFactory::createInt16(std::string const &value) const {
	return new Operand<short>(value, static_cast<short>(0));
}

IOperand const *OperandFactory::createInt32(std::string const &value) const {
	return new Operand<int>(value, 0);
}

IOperand const *OperandFactory::createFloat(std::string const &value) const {
	return new Operand<float>(value, 0.0f);
}

IOperand const *OperandFactory::createDouble(std::string const &value) const {
	return new Operand<double>(value, 0.0);
}

// * NESTED_CLASSES ********************************************************* //

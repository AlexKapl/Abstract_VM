/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandFactory.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <akaplyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 13:40:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/11/17 13:40:00 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef OPERANDFACTORY_HPP
# define OPERANDFACTORY_HPP

#include "IOperand.hpp"

class OperandFactory {

public:
	typedef IOperand const *(OperandFactory::*Optr)(std::string const &) const;

	OperandFactory() = default;

	static IOperand const *
	makeOperand(IOperand::eOperandType type, std::string const &value);

	OperandFactory(OperandFactory const &) = delete;

	OperandFactory &operator=(OperandFactory const &) = delete;

	~OperandFactory() = default;

private:
	static Optr factories[5];

	IOperand const *
	createOperand(IOperand::eOperandType type, std::string const &value) const;

	IOperand const *createInt8(std::string const &value) const;

	IOperand const *createInt16(std::string const &value) const;

	IOperand const *createInt32(std::string const &value) const;

	IOperand const *createFloat(std::string const &value) const;

	IOperand const *createDouble(std::string const &value) const;

};


#endif

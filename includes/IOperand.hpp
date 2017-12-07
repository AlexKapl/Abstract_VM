/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IOperand.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <akaplyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 13:36:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/11/17 13:36:00 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef IOPERAND_HPP
# define IOPERAND_HPP

#include "vm.h"

class IOperand {

public:

	enum eOperandType {Int8, Int16, Int32, Float, Double};

	virtual int getPrecision() const = 0;

	virtual eOperandType getType() const = 0;

	virtual IOperand const *operator+(IOperand const &rhs) const = 0;

	virtual IOperand const *operator-(IOperand const &rhs) const = 0;

	virtual IOperand const *operator*(IOperand const &rhs) const = 0;

	virtual IOperand const *operator/(IOperand const &rhs) const = 0;

	virtual IOperand const *operator%(IOperand const &rhs) const = 0;

	virtual std::string const &toString() const = 0;

	virtual ~IOperand() = default;
};

#endif

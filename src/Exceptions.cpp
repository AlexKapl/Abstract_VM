/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exceptions.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <akaplyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 18:56:18 by akaplyar          #+#    #+#             */
/*   Updated: 2017/12/06 18:56:19 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Exceptions.hpp"

const char *OpenFileException::what() const noexcept {
	return ("Can't open file: ");
};

const char *InstructionException::what() const noexcept {
	return ("Invalid instruction");
};

const char *ValueException::what() const noexcept {
	return ("Invalid instruction value");
};

const char *CharsException::what() const noexcept {
	return ("Invalid characters value");
};

const char *NoEndException::what() const noexcept {
	return ("Missing end characters");
}

const char *NoExitException::what() const noexcept {
	return ("Missing exit instruction");
}

const char *StackException::what() const noexcept {
	return ("Not enough operands in stack");
}

const char *ByZeroException::what() const noexcept {
	return ("Division/Modulo by zero");
}

const char *AssertException::what() const noexcept {
	return ("Types or values for assert don't match");
}

const char *PopException::what() const noexcept {
	return ("Pop on empty stack");
}

const char *UnderflowException::what() const noexcept {
	return ("Value Underflow");
}

const char *OverflowException::what() const noexcept {
	return ("Value Overflow");
}

const char *DumpException::what() const noexcept {
	return ("Dump on empty stack");
}

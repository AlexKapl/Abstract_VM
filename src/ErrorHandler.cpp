/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ErrorHandler.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <akaplyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 20:03:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/12/03 20:03:00 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ErrorHandler.hpp"

// * STATICS **************************************************************** //

auto ErrorHandler::errors = std::vector<std::string>();

void ErrorHandler::addError(std::string const &str) {
	errors.push_back(str);
}

void ErrorHandler::printErrors() {
	std::for_each(errors.begin(), errors.end(), [](std::string &str){
		std::cout << str << std::endl;
	});
}

void ErrorHandler::clearErrors() {
	errors.clear();
}

bool ErrorHandler::isError() {
	return (!errors.empty());
}

// * CONSTRUCTORS *********************************************************** //
// * DESTRUCTORS ************************************************************ //
// * OPERATORS ************************************************************** //
// * GETTERS **************************************************************** //
// * SETTERS **************************************************************** //
// * MEMBER FUNCTIONS / METHODS ********************************************* //
// * NESTED_CLASSES ********************************************************* //

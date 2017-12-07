/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ErrorHandler.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <akaplyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 20:03:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/12/03 20:03:00 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ERRORHANDLER_HPP
# define ERRORHANDLER_HPP

#include "vm.h"

class ErrorHandler {

public:
	ErrorHandler() = delete;

	ErrorHandler(ErrorHandler const &) = delete;

	~ErrorHandler() = delete;

	ErrorHandler &operator=(ErrorHandler const &) = delete;

	static void addError(std::string const &str);

	static void printErrors();

	static void clearErrors();

	static bool isError();

private:
	static std::vector<std::string> errors;

};


#endif

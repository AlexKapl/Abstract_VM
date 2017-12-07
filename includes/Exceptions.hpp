/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exceptions.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <akaplyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 14:00:03 by akaplyar          #+#    #+#             */
/*   Updated: 2017/12/03 14:00:04 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>

class OpenFileException : public std::exception {
public:
	const char* what() const noexcept override;
};

class InstructionException : public std::exception {
public:
	const char* what() const noexcept override;
};

class ValueException : public std::exception {
public:
	const char* what() const noexcept override;
};

class CharsException : public std::exception {
public:
	const char* what() const noexcept override;
};

class NoEndException : public std::exception {
public:
	const char* what() const noexcept override;
};

class NoExitException : public std::exception {
public:
	const char* what() const noexcept override;
};

class StackException : public std::exception {
public:
	const char* what() const noexcept override;
};

class ByZeroException : public std::exception {
public:
	const char* what() const noexcept override;
};

class AssertException : public std::exception {
public:
	const char* what() const noexcept override;
};

class PopException : public std::exception {
public:
	const char* what() const noexcept override;
};

class UnderflowException : public std::exception {
public:
	const char* what() const noexcept override;
};

class OverflowException : public std::exception {
public:
	const char* what() const noexcept override;
};

class DumpException : public std::exception {
public:
	const char* what() const noexcept override;
};

#endif

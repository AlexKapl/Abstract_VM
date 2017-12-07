/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <akaplyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 15:16:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/12/01 15:16:00 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

#include <stack>
#include <map>
#include <vector>

#include <algorithm>
#include <cmath>
#include <limits>
#include <cfloat>
#include <regex>

#include "ErrorHandler.hpp"
#include "../src/MutantStack.cpp"
#include "Exceptions.hpp"

typedef std::vector<std::string> Words;

class Lexer;

Words split(const std::string &text, const char sub = ' ');

#endif

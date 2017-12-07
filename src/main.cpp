/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <akaplyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 15:18:45 by akaplyar          #+#    #+#             */
/*   Updated: 2017/12/01 15:18:46 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Parser.hpp"

Words split(const std::string &text, const char sub) {
	size_t j = 0;
	std::string str(text);
	Words words;

	while (true) {
		if ((j = str.find(sub)) != std::string::npos) {
			if (j != 0)
				words.push_back(str.substr(0, j));
			str = str.substr(j + 1);
		}
		else {
			words.push_back(str);
			return (words);
		}
	}
}

static void read_input(std::string const &file = "") {
	std::ifstream ifstream;
	Parser parser(file.empty() ? new Lexer() : new Lexer(file, ifstream));

	try {
		parser.parse();
	}
	catch (NoExitException &e) {
		std::stringstream ss;
		ss << "Parser: " << e.what();
		ErrorHandler::addError(ss.str());
	}
	parser.printResult();
}

int main(int ac, char **av) {
	if (ac < 2) {
		try {
			read_input();
		}
		catch (NoEndException &e) {
			std::cout << e.what() << std::endl;
		}
	}
	else {
		for (int i = 1; i < ac; ++i) {
			try {
				read_input(av[i]);
//				std::cout << "-----------------------------------" << std::endl;
			}
			catch (OpenFileException &e) {
				std::cout << e.what() << av[i] << std::endl;
			}
		}
	}
	return 0;
}

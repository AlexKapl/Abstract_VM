/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <akaplyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 19:51:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/12/03 19:51:00 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template<typename T>
class MutantStack : public std::stack<T> {

public:
	typedef typename std::deque<T>::iterator iterator;
	typedef typename std::deque<T>::const_iterator const_iterator;
	typedef typename std::deque<T>::reverse_iterator reverse_iterator;

	MutantStack() = default;

	MutantStack(MutantStack const &copy) = delete;

	~MutantStack() = default;

	MutantStack &operator=(MutantStack const &assign) = delete;

	MutantStack<T>::iterator begin() { return this->c.begin(); };

	const MutantStack<T>::const_iterator
	begin() const { return this->c.begin(); };

	MutantStack<T>::reverse_iterator
	rbegin() { return this->c.rbegin(); };

	MutantStack<T>::iterator end() { return this->c.end(); };

	const MutantStack<T>::const_iterator end() const { return this->c.end(); };

	MutantStack<T>::reverse_iterator
	rend() { return this->c.rend(); };

private:

};

#endif

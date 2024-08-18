#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

# include "MutantStack.hpp"

template <typename T, class container>
MutantStack<T, container>::MutantStack()
	//std::stack<T, container>()
{
}

template <typename T, class container>
MutantStack<T, container>::~MutantStack()
{
}

template <typename T, class container>
MutantStack<T, container>::MutantStack(MutantStack const &rhs)
{
	*this = rhs;
}

template <typename T, class container>
MutantStack<T, container> &MutantStack<T, container>::operator=(MutantStack const &rhs)
{
	if (this != rhs)
		*this = rhs;
	return *this;
}

template <typename T, class container>
typename container::iterator	MutantStack<T, container>::begin()
{
	return this->c.begin();
}

template <typename T, class container>
typename container::iterator	MutantStack<T, container>::end()
{
	return this->c.end();
}

#endif

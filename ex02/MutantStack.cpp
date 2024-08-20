#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

# include "MutantStack.hpp"

template <typename T, class container>
MutantStack<T, container>::MutantStack()
{
}

template <typename T, class container>
MutantStack<T, container>::~MutantStack()
{
}

template <typename T, class container>
MutantStack<T, container>::MutantStack(MutantStack const &rhs):
	std::stack<T, container>(rhs)
{
}

template <typename T, class container>
MutantStack<T, container> &MutantStack<T, container>::operator=(MutantStack const &rhs)
{
	if (this != &rhs)
		std::stack<T, container>::operator=(rhs);
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

template <typename T, class container>
typename container::reverse_iterator	MutantStack<T, container>::rbegin()
{
	return this->c.rbegin();
}

template <typename T, class container>
typename container::reverse_iterator	MutantStack<T, container>::rend()
{
	return this->c.rend();
}

template <typename T, class container>
typename container::const_iterator	MutantStack<T, container>::cbegin() const
{
	return this->c.cbegin();
}

template <typename T, class container>
typename container::const_iterator	MutantStack<T, container>::cend() const
{
	return this->c.cend();
}

template <typename T, class container>
typename container::const_reverse_iterator	MutantStack<T, container>::crbegin() const
{
	return this->c.crbegin();
}

template <typename T, class container>
typename container::const_reverse_iterator	MutantStack<T, container>::crend() const
{
	return this->c.crend();
}

#endif

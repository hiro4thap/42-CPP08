#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <deque>

template <typename T, class container = std::deque<T> >
class	MutantStack : public std::stack<T>
{
public:
	MutantStack();
	~MutantStack();
	MutantStack(MutantStack const &rhs);
	MutantStack &operator=(MutantStack const &rhs);

	typedef typename container::iterator iterator;
	typedef typename container::reverse_iterator reverse_iterator;
	typedef typename container::const_iterator const_iterator;
	typedef typename container::const_reverse_iterator const_reverse_iterator;

	iterator				begin();
	iterator				end();

	reverse_iterator		rbegin();
	reverse_iterator		rend();

	const_iterator			cbegin() const;
	const_iterator			cend() const;

	const_reverse_iterator	crbegin() const;
	const_reverse_iterator	crend() const;

};

# include "MutantStack.cpp"

#endif

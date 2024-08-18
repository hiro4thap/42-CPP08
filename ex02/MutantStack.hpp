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

	iterator	begin();
	iterator	end();

private:
};

# include "MutantStack.cpp"

#endif

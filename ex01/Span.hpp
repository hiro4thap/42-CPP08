#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <iostream>
# include <vector>

class	Span
{
public:
	Span();
	~Span();
	Span(Span const &rhs);
	Span &operator=(Span const &rhs);
	Span(unsigned int N);

	unsigned int	getSize() const;
	int				getNumbers(unsigned int i) const;
	void			addNumber(int n);
	int				shortestSpan() const;
	int				longestSpan() const;

	class IsFullException : public std::exception
	{
	public:
		char const *what() const throw();
	};

	class NoSpanFoundException : public std::exception
	{
	public:
		char const *what() const throw();
	};

private:
	unsigned int		_size;
	std::vector<int>	_numbers;
};

#endif

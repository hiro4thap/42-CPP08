#include "Span.hpp"

Span::Span()
{
}

Span::~Span()
{
}

Span::Span(Span const &rhs):
	_size(rhs.getSize())
{
	//for (unsigned int i = 0; i < _size; i++)
	//	_numbers.push_back(rhs.getNumbers(i));
	*this = rhs;
}

Span &Span::operator=(Span const &rhs)
{
	if (this != &rhs)
	{
		_size = rhs.getSize();
		for (unsigned int i = 0; i < _size; i++)
			_numbers.push_back(rhs.getNumbers(i));
	}
	return *this;
}

Span::Span(unsigned int N):
	_size(N)
{
}

unsigned int	Span::getSize() const
{
	return _size;
}

int	Span::getNumbers(unsigned int i) const
{
	return _numbers[i];
}

void	Span::addNumber(int n)
{
	if (_numbers.size() == _size)
		throw IsFullException();
	_numbers.push_back(n);
	std::sort(_numbers.begin(), _numbers.end());
}

int	Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw NoSpanFoundException();
	int	min = -1;
	for (unsigned int i = 1; i < _size; i++)
	{
		if (min == -1 || _numbers[i] - _numbers[i - 1] < min)
			min = _numbers[i] - _numbers[i - 1];
	}
	return min;
}

int	Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw NoSpanFoundException();
	return *(_numbers.end() - 1) - *_numbers.begin();
}

char const *Span::IsFullException::what() const throw()
{
	return "Span is full";
}

char const *Span::NoSpanFoundException::what() const throw()
{
	return "No span can be found";
}

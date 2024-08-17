#include "Span.hpp"
#include "Log.hpp"

int main()
{
	Span sp = Span(5);
	try
	{
		sp.shortestSpan();
	}
	catch (std::exception &e)
	{
		Log::nl(e.what(), RED);
	}
	try
	{
		sp.longestSpan();
	}
	catch (std::exception &e)
	{
		Log::nl(e.what(), RED);
	}
	sp.addNumber(6);
	try
	{
		sp.shortestSpan();
	}
	catch (std::exception &e)
	{
		Log::nl(e.what(), RED);
	}
	try
	{
		sp.longestSpan();
	}
	catch (std::exception &e)
	{
		Log::nl(e.what(), RED);
	}
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	try
	{
		sp.addNumber(100);
	}
	catch (std::exception &e)
	{
		Log::nl(e.what(), RED);
	}

	unsigned int size = 100000;
	Span span = Span(size);
	for (unsigned int i = 0; i < size; i++)
	{
		span.addNumber(i * 2);
	}
	std::cout << span.shortestSpan() << std::endl;
	std::cout << span.longestSpan() << std::endl;
	return 0;
}

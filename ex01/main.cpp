#include "Span.hpp"
#include "Log.hpp"

int main()
{
	Span sp = Span(5);
	Log::nl("Try to find span with no numbers stored", CYAN);
	Log::out("shortestSpan : ", YELLOW);
	try
	{
		sp.shortestSpan();
	}
	catch (std::exception &e)
	{
		Log::nl(e.what(), RED);
	}
	Log::out("longestSpan  : ", YELLOW);
	try
	{
		sp.longestSpan();
	}
	catch (std::exception &e)
	{
		Log::nl(e.what(), RED);
	}
	Log::nl();

	Log::nl("Try to find span with 1 number stored", CYAN);
	sp.addNumber(6);
	Log::out("shortestSpan : ", YELLOW);
	try
	{
		sp.shortestSpan();
	}
	catch (std::exception &e)
	{
		Log::nl(e.what(), RED);
	}
	Log::out("longestSpan  : ", YELLOW);
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
	Log::nl();

	Log::nl("Try to find span with 5 numbers stored", CYAN);
	Log::out("shortestSpan : ", YELLOW);
	std::cout << sp.shortestSpan() << std::endl;
	Log::out("longestSpan  : ", YELLOW);
	std::cout << sp.longestSpan() << std::endl;
	Log::nl();

	Span sp2(sp);
	Log::nl("Try to find span with 5 numbers stored in copy-constructed Span", CYAN);
	Log::out("shortestSpan : ", YELLOW);
	std::cout << sp.shortestSpan() << std::endl;
	Log::out("longestSpan  : ", YELLOW);
	std::cout << sp.longestSpan() << std::endl;
	Log::nl();

	Span sp3;
	sp3 = sp;
	Log::nl("Try to find span with 5 numbers stored in copy-assigned Span", CYAN);
	Log::out("shortestSpan : ", YELLOW);
	std::cout << sp.shortestSpan() << std::endl;
	Log::out("longestSpan  : ", YELLOW);
	std::cout << sp.longestSpan() << std::endl;
	Log::nl();

	Log::nl("Try to add number to full Span", CYAN);
	try
	{
		sp.addNumber(100);
	}
	catch (std::exception &e)
	{
		Log::nl(e.what(), RED);
	}
	Log::nl();

	Log::nl("Find span with 100000 numbers stored", CYAN);
	unsigned int size = 100000;
	Span span = Span(size);
	for (unsigned int i = 0; i < size; i++)
	{
		span.addNumber(i * 2);
	}
	Log::out("shortestSpan : ", YELLOW);
	std::cout << span.shortestSpan() << std::endl;
	Log::out("longestSpan  : ", YELLOW);
	std::cout << span.longestSpan() << std::endl;
	return 0;
}

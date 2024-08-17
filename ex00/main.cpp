#include "easyfind.hpp"
#include "Log.hpp"
#include <array>
#include <vector>
#include <list>

std::ostream &operator<<(std::ostream &os, std::vector<int>::iterator const &i)
{
	return (os << &i);
}

void	print(int &i)
{
	std::cout << "address: " << &i << ", value: " << i << "\n";
}

int	main()
{
	Log::nl("array test", CYAN);
	std::array<int, 3> arr = {10, 20, 30};
	Log::nl("array contains", YELLOW);
	std::for_each(arr.begin(), arr.end(), print);
	Log::nl("easyfind 10", YELLOW);
	print(*easyfind(arr, 10));
	Log::nl("easyfind 11", YELLOW);
	print(*easyfind(arr, 11));
	Log::nl();

	Log::nl("vector test", CYAN);
	std::vector<int> vect;
	vect.push_back(100);
	vect.push_back(200);
	vect.push_back(300);
	Log::nl("vector contains", YELLOW);
	std::for_each(vect.begin(), vect.end(), print);
	Log::nl("easyfind 200", YELLOW);
	print(*easyfind(vect, 200));
	Log::nl("easyfind 201", YELLOW);
	print(*easyfind(vect, 201));

	return 0;
}


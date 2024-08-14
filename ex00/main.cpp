#include "easyfind.hpp"
#include "Log.hpp"
#include <array>
#include <vector>
#include <list>

int	main()
{
	//std::array<int, 3> arr = {1, 2, 3};
	//std::vector<int> vect;
	//vect.push_back(10);
	//vect.push_back(20);
	//vect.push_back(30);
	std::list<int> lst;
	easyfind(lst, 10);
	return 0;
}


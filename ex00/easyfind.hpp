#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>

template <typename T>
void easyfind(const T &src, const int target)
{
	std::find(src.begin(), src.end(), target);
}

#endif

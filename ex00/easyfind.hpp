#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>

template <typename T>
typename T::iterator easyfind(T &src, int const target)
{
	return std::find(src.begin(), src.end(), target);
}

#endif

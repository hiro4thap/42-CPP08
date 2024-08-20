#include "MutantStack.hpp"
#include "Log.hpp"
#include <vector>
#include <list>
#include <iomanip>

template <typename T>
void	printContainer(T const &container)
{
	for (typename T::const_iterator i = container.cbegin(); i != container.cend(); i++)
	{
		std::cout << *i << ' ';
	}
	std::cout << std::endl;
}

int main()
{
	Log::nl("Test with MutantStack<int>", CYAN);
	Log::nl("Test functions inherited from std::stack", CYAN);
	{
		MutantStack<int> mstack;
		Log::out("Stack is empty: ", YELLOW);
		std::cout << std::boolalpha << mstack.empty() << std::endl;
		Log::nl("pushed 11", PURPLE);
		mstack.push(11);
		Log::out("Stack is empty: ", YELLOW);
		std::cout << std::boolalpha << mstack.empty() << std::endl;
		Log::nl("pushed 12", PURPLE);
		mstack.push(12);
		Log::out("Stack top: ", YELLOW);
		std::cout << mstack.top() << std::endl;
		Log::out("Stack size: ", YELLOW);
		std::cout << mstack.size() << std::endl;
		Log::nl("pop", PURPLE);
		mstack.pop();
		Log::out("Stack top: ", YELLOW);
		std::cout << mstack.top() << std::endl;
		Log::out("Stack size: ", YELLOW);
		std::cout << mstack.size() << std::endl;
		Log::nl("pushed 13", PURPLE);
		mstack.push(13);
		Log::nl("pushed 14", PURPLE);
		mstack.push(14);
		Log::nl("pushed 15", PURPLE);
		mstack.push(15);

		Log::nl("mstack2 has been copy-constructed and pushed 2", PURPLE);
		MutantStack<int> mstack2(mstack);
		mstack2.push(2);
		Log::nl("mstack3 has been copy-assigned and pushed 3", PURPLE);
		MutantStack<int> mstack3;
		mstack3 = mstack;
		mstack3.push(3);
		Log::out("Values stored in mstack  : ", YELLOW);
		printContainer<MutantStack<int> >(mstack);
		Log::out("Values stored in mstack2 : ", YELLOW);
		printContainer<MutantStack<int> >(mstack2);
		Log::out("Values stored in mstack3 : ", YELLOW);
		printContainer<MutantStack<int> >(mstack3);
		Log::nl("swap mstack2 and mstack3", PURPLE);
		mstack2.swap(mstack3);
		Log::out("Values stored in mstack  : ", YELLOW);
		printContainer<MutantStack<int> >(mstack);
		Log::out("Values stored in mstack2 : ", YELLOW);
		printContainer<MutantStack<int> >(mstack2);
		Log::out("Values stored in mstack3 : ", YELLOW);
		printContainer<MutantStack<int> >(mstack3);
		std::stack<int> s(mstack);
		Log::nl();

		Log::nl("Test relational operator", CYAN);
		Log::out("mstack == mstack2: ", YELLOW);
		std::cout << std::boolalpha << (mstack == mstack2) << std::endl;
		Log::out("mstack != mstack2: ", YELLOW);
		std::cout << std::boolalpha << (mstack != mstack2) << std::endl;
		Log::out("mstack <  mstack2: ", YELLOW);
		std::cout << std::boolalpha << (mstack <  mstack2) << std::endl;
		Log::out("mstack <= mstack2: ", YELLOW);
		std::cout << std::boolalpha << (mstack <= mstack2) << std::endl;
		Log::out("mstack >  mstack2: ", YELLOW);
		std::cout << std::boolalpha << (mstack >  mstack2) << std::endl;
		Log::out("mstack >= mstack2: ", YELLOW);
		std::cout << std::boolalpha << (mstack >= mstack2) << std::endl;
		Log::nl();

		Log::nl("Test iterators", CYAN);
		Log::out("Increment values using iterator", PURPLE);
		for (MutantStack<int>::iterator it = mstack.begin(); it < mstack.end(); it++)
			*it += 1;
		std::cout << std::endl;
		Log::out("Read with iterator: ", YELLOW);
		for (MutantStack<int>::iterator it = mstack.begin(); it < mstack.end(); it++)
			std::cout << *it << ' ';
		std::cout << std::endl;
		Log::out("Read with const_iterator: ", YELLOW);
		for (MutantStack<int>::const_iterator it = mstack.cbegin(); it < mstack.cend(); it++)
			std::cout << *it << ' ';
		std::cout << std::endl;
		Log::out("Decrement values using reverse_iterator", PURPLE);
		for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it < mstack.rend(); it++)
			*it -= 1;
		std::cout << std::endl;
		Log::out("Read with reverse_iterator: ", YELLOW);
		for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it < mstack.rend(); it++)
			std::cout << *it << ' ';
		std::cout << std::endl;
		Log::out("Read with const_reverse_iterator: ", YELLOW);
		for (MutantStack<int>::const_reverse_iterator it = mstack.crbegin(); it < mstack.crend(); it++)
			std::cout << *it << ' ';
		std::cout << std::endl;
	}
	Log::nl();
	Log::nl("Test with std::list<int>", CYAN);
	Log::nl("Test functions", CYAN);
	{
		std::list<int> mlist;
		Log::out("List is empty: ", YELLOW);
		std::cout << std::boolalpha << mlist.empty() << std::endl;
		Log::nl("pushed 11", PURPLE);
		mlist.push_back(11);
		Log::out("List is empty: ", YELLOW);
		std::cout << std::boolalpha << mlist.empty() << std::endl;
		Log::nl("pushed 12", PURPLE);
		mlist.push_back(12);
		Log::out("List back: ", YELLOW);
		std::cout << mlist.back() << std::endl;
		Log::out("List size: ", YELLOW);
		std::cout << mlist.size() << std::endl;
		Log::nl("pop back", PURPLE);
		mlist.pop_back();
		Log::out("List back: ", YELLOW);
		std::cout << mlist.back() << std::endl;
		Log::out("List size: ", YELLOW);
		std::cout << mlist.size() << std::endl;
		Log::nl("pushed 13", PURPLE);
		mlist.push_back(13);
		Log::nl("pushed 14", PURPLE);
		mlist.push_back(14);
		Log::nl("pushed 15", PURPLE);
		mlist.push_back(15);

		Log::nl("mlist2 has been copy-constructed and pushed 2", PURPLE);
		std::list<int> mlist2(mlist);
		mlist2.push_back(2);
		Log::nl("mlist3 has been copy-assigned and pushed 3", PURPLE);
		std::list<int> mlist3;
		mlist3 = mlist;
		mlist3.push_back(3);
		Log::out("Values stored in mlist  : ", YELLOW);
		printContainer<std::list<int> >(mlist);
		Log::out("Values stored in mlist2 : ", YELLOW);
		printContainer<std::list<int> >(mlist2);
		Log::out("Values stored in mlist3 : ", YELLOW);
		printContainer<std::list<int> >(mlist3);
		Log::nl("swap mlist2 and mlist3", PURPLE);
		mlist2.swap(mlist3);
		Log::out("Values stored in mlist  : ", YELLOW);
		printContainer<std::list<int> >(mlist);
		Log::out("Values stored in mlist2 : ", YELLOW);
		printContainer<std::list<int> >(mlist2);
		Log::out("Values stored in mlist3 : ", YELLOW);
		printContainer<std::list<int> >(mlist3);
		std::list<int> s(mlist);
		Log::nl();

		Log::nl("Test relational operator", CYAN);
		Log::out("mlist == mlist2: ", YELLOW);
		std::cout << std::boolalpha << (mlist == mlist2) << std::endl;
		Log::out("mlist != mlist2: ", YELLOW);
		std::cout << std::boolalpha << (mlist != mlist2) << std::endl;
		Log::out("mlist <  mlist2: ", YELLOW);
		std::cout << std::boolalpha << (mlist <  mlist2) << std::endl;
		Log::out("mlist <= mlist2: ", YELLOW);
		std::cout << std::boolalpha << (mlist <= mlist2) << std::endl;
		Log::out("mlist >  mlist2: ", YELLOW);
		std::cout << std::boolalpha << (mlist >  mlist2) << std::endl;
		Log::out("mlist >= mlist2: ", YELLOW);
		std::cout << std::boolalpha << (mlist >= mlist2) << std::endl;
		Log::nl();

		Log::nl("Test iterators", CYAN);
		Log::out("Increment values using iterator", PURPLE);
		for (std::list<int>::iterator it = mlist.begin(); it != mlist.end(); it++)
			*it += 1;
		std::cout << std::endl;
		Log::out("Read with iterator: ", YELLOW);
		for (std::list<int>::iterator it = mlist.begin(); it != mlist.end(); it++)
			std::cout << *it << ' ';
		std::cout << std::endl;
		Log::out("Read with const_iterator: ", YELLOW);
		for (std::list<int>::const_iterator it = mlist.cbegin(); it != mlist.cend(); it++)
			std::cout << *it << ' ';
		std::cout << std::endl;
		Log::out("Decrement values using reverse_iterator", PURPLE);
		for (std::list<int>::reverse_iterator it = mlist.rbegin(); it != mlist.rend(); it++)
			*it -= 1;
		std::cout << std::endl;
		Log::out("Read with reverse_iterator: ", YELLOW);
		for (std::list<int>::reverse_iterator it = mlist.rbegin(); it != mlist.rend(); it++)
			std::cout << *it << ' ';
		std::cout << std::endl;
		Log::out("Read with const_reverse_iterator: ", YELLOW);
		for (std::list<int>::const_reverse_iterator it = mlist.crbegin(); it != mlist.crend(); it++)
			std::cout << *it << ' ';
		std::cout << std::endl;
	}
	return 0;
}

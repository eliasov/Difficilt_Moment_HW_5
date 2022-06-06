#include <algorithm>
#include <deque>
#include <stdlib.h>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;
//Template function that takes an iterator to the beginning and end of the list of words.
//And displays a list of unique words
template<typename Vcol>
void PrintUniqueWirds(Vcol v_begin, Vcol v_end)
{
	set<typename Vcol::value_type> uniqueWords(v_begin, v_end);
	for_each(uniqueWords.begin(), uniqueWords.end(), [](const auto& it)
		{
			cout << it << " ";
		});
	cout << endl;

}

int main()
{
	//Task_1
	std::cout << std::endl << "  ==========  Task_1 ========== " << std::endl << std::endl;

	std::cout << std::endl << "Vector:" << std::endl;

	// Word vector
	const vector<string> v_catalog = { "green", "blue", "red", "grey", "orange",
								"white", "grey", "white", "red", "red",
								"gold", "orange", "white", "silver", "blue",
								"coral", "red", "snow", "blue", "coral", };

	//The function displays a list of unique words
	PrintUniqueWirds(v_catalog.begin(), v_catalog.end());

	std::cout << std::endl << "List:" << std::endl;

	// Word list
	list<string> l_catalog = { "one", "two", "tree", "four", "five",
								"six", "two", "one", "seven", "five",
								"eigth", "nine" "ten", "seven", "seven",
								"nine", "ten", "six", "two", "eigth", };

	//The function displays a list of unique words
	PrintUniqueWirds(l_catalog.begin(), l_catalog.end());

	std::cout << std::endl << "Deque:" << std::endl;

	// Dec words
	deque<string> d_catalog = { "green", "blue", "red", "grey", "orange",
								"white", "grey", "white", "red", "red",
								"gold", "orange", "white", "silver", "blue",
								"coral", "red", "snow", "blue", "coral", };

	//The function displays a list of unique words
	PrintUniqueWirds(d_catalog.begin(), d_catalog.end());

	std::cout << std::endl << "Map:" << std::endl;
	// Word map (orders words by key)
	map<int, string> numbers = {
		{1, "blue"},
		{3, "green"},
		{4, "gray"},
		{2, "black"},
		{4, "white"},
		{2, "orange"},
		{3, "orange"},
	};
	for_each(numbers.begin(), numbers.end(),
		[](pair<int, string> item) {
			cout << item.first << " " << item.second << "\n";
		});
	return 0;
}
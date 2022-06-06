#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <iterator>

//Task_2

/* Russian
Используя ассоциативный контейнер, напишите программу,
которая будет считывать данные введенные пользователем из стандартного потока ввода и 
разбивать их на предложения.Далее программа должна вывести пользователю все предложения,
а также количество слов в них, отсортировав предложения по количеству слов.

  English
Using an associative container, write a program
which will read the data entered by the user from the standard input stream and
break them into sentences. Next, the program should display to the user all the sentences
as well as the number of words in them, sorting the sentences by the number of words.
*/
using namespace std;


int main()
{
	

	multimap<uint32_t, string> inp_str; // create an associative container

	string in_text;
	string temp;
	const string punct_sings = "!?."; // end - of - sentence
	cout << "Put a space at the beginning of a sentence\n" << "Enter the text:";
	getline(cin, in_text); //read text from given string

	//Sort the sentence by the number of words and count their number in the sentence
	for (auto iter = in_text.begin(); iter != in_text.end(); iter++)
	{
		auto first_ch = find_first_of(iter, in_text.end(), punct_sings.begin(), punct_sings.end());
		if (first_ch != in_text.end())
		{
			auto chBegin = distance(in_text.begin(), iter);
			auto chEnd = distance(in_text.begin(), first_ch);
			temp = in_text.substr(chBegin, chEnd - chBegin + 1);
			iter = first_ch;
			if (temp.empty()) { continue; }
			const auto key = count_if(temp.begin(), temp.end(),
				[](const char ch) {return isspace(ch); });
			inp_str.emplace(key, temp);

		}
	}

	//Display the result on the screen
	int i = 0;
	for (const auto& n : inp_str)
	{

		cout << "(Word count " << n.first << ')' << "String " << ++i << "." << " " << n.second << endl;
	}
	return 0;
}

using namespace std;
#include <iostream>
#include <fstream>
#include "List.h"
//#include "timer.h"
#include <string>
#include <cctype>
string cleanWord(string h);

int main() {
	//Timer Watch;
	//Watch.stop();
	string dictWord;
	string bookWord;
	string corBookWord;
	
	long long int spelledCor = 0;
	long long int notSpelledCor = 0;
	long long int skipped = 0;
	
	myList<string> dictionary;
	
	ifstream book;
	ifstream dict;
	//ofstream misspelledWords;

	dict.open("dict.txt");
	if (dict.is_open()) {
		cout << "Dict is open." << endl;
		while (!dict.eof()) {
			dict >> dictWord;
			cout << "Next word is " << dictWord << ".";
			dictionary.insert(dictWord);
			cout << " Added " << dictWord << " to dictionary." << endl;
		}
	}

	book.open("book.txt");
	//Watch.start();
	if (book.is_open()) {
		cout << "Book is open." << endl;
		while (!book.eof()) {
			book >> bookWord;
			cout << bookWord;
			corBookWord = cleanWord(bookWord);
			cout << " ==> " << corBookWord;

			if (corBookWord.empty()) {
				continue;
			}
			else if (!isalpha(corBookWord[0])) {
				skipped += 1;
				cout << " Skipped" << endl;
				continue;
			}
			else if (dictWord.find(corBookWord)) {
				spelledCor++;
				cout << " Spelled correctly" << endl;
			}
			else {
				notSpelledCor++;
				cout << " Spelled incorrectly " << endl;
			}
		}
	}

	book.close();
	//Watch.stop();
	dict.close();

	long long int avgCor = spelledCompares / spelledCor;
	long long int avgNotCor = notSpelledCompares / notSpelledCor;

	cout << "Dictionary size " << dictionary.getSize() << endl;
	cout << "Done checking and these are the results: " << endl;
	//cout << "Finsihed in time " << Watch.Time() << endl;
	cout << "There are " << spelledCor << " words found in the dictionary" << endl;
	cout << "    " << spelledCompares << " compares. Average: " << avgCor << endl;
	cout << "    " << spelledCompares << " compares. Average: " << avgCor << endl;
	cout << "There are " << notSpelledCor << " words NOT found in the dictionary" << endl;
	cout << "    " << notSpelledCompares << " compares. Average: " << avgNotCor << endl;
	cout << "There are " << skipped << "words not checked." << endl;

	return 0;
}

string cleanWord(string h) {
	for (int i = 0; i < h.size(); i++) {
		cout << h[i];
		if (isalnum(h[i])) {
			if (isalpha(h[i])) {
				if (isupper(h[i])) {
					//if the char is an alpha numeric
					h[i] = tolower(h[i]);
				}
			}

		}
		else if (h[i] == '\'') {
			//if the word is an apostrophe
			//keep the apostrophe
			h[i] = '\'';
		}
		else {

			h.erase(h.begin() + i);
			i--;
		}

	}
	return h;
}

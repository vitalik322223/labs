// labs.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum Type {ART, TECH};

class Book {
public:
	Book(string author, string name, Type type) {
		if (author.empty() or name.empty()) {
			throw invalid_argument("error");
		}
		_type = type;
		_name = name;
		_author = author;
	};
	~Book() {};
	Type get_type() { return _type; };
	string get_name() { return _name; };
	string get_author() { return _author; };
private:
	Type _type;
	string _name;
	string _author;
};

class Library {
	
public:
	vector<Book> books;
	void new_book(Book book) {
		books.push_back(book);
	}
};

void Switch(const vector<Book>& books) {
	int technical = 0, artistic = 0;
	for (Book book:books) {
		switch (book.get_type()) {
		case ART:
			++artistic;
			break;
		case TECH:
			++technical;
			break;
		}
	}
	cout << "Technical: " << technical << "\n";
	cout << "Artistic: " << artistic << "\n";
}

void NoSwitch(const vector<Book>& books) {
	int technical = 0, artistic = 0;
	for (Book book : books) {
		if (book.get_type() == ART) ++artistic;
		else ++technical;
	}
	cout << "Technical: " << technical << "\n";
	cout << "Artistic: " << artistic << "\n";
}

int main() {
	Library library;
	Book book1("Gabriel Garcia Marquez", "One hundred years of solitude", ART);
	Book book2("Bjorn Stroustrup", "The C++ Programming Language", TECH);
	Book book3("Leo Tolstoy", "War and Peace", ART);
	library.new_book(book1);
	library.new_book(book2);
	library.new_book(book3);
	Switch(library.books);
	NoSwitch(library.books);
	return 0;
}
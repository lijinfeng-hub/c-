#pragma once
#include"Book.h"
#include<vector>
#include<string>
class Book;
class Library
{
private:
	std::vector<Book> _books;//存放书籍的容器
public:
	Library();
	~Library();
	void addBook(Book& book);
	void showBooks();
	void searchBook(const std::string& name);
	void borrowBook(const std::string& name);
	void returnBook(const std::string& name);
	void loadBook();
};


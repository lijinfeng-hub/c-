#include "Library.h"
#include <sstream>
Library::Library()
{
	loadBook();
}
Library::~Library()
{

}
void Library::addBook(Book& book)
{
	_books.push_back(book);
	book.saveRecord();
}
void Library::showBooks()
{
	for (auto& it : _books)
	{
		it.show();
	}
}
void Library::loadBook() {
	std::ifstream ifs("book.csv");
	if (!ifs.is_open()) {
		std::cout << "文件打开失败！" << std::endl;
		return;
	}

	std::string line;
	while (std::getline(ifs, line)) {
		if (line.empty()) continue; // 跳过空行

		std::istringstream iss(line);
		std::string name, idStr, priceStr, statusStr;
		if (!std::getline(iss, name, ',') ||
			!std::getline(iss, idStr, ',') ||
			!std::getline(iss, priceStr, ',') ||
			!std::getline(iss, statusStr)) {
			std::cerr << "跳过无效行: " << line << std::endl;
			continue;
		}

		try {
			int id = std::stoi(idStr);
			int price = std::stoi(priceStr);
			int status = std::stoi(statusStr);

			Book book;
			book._name = name;
			book._id = id;
			book._price = price;
			book._status = status;
			_books.push_back(book);
		}
		catch (const std::exception& e) {
			std::cerr << "无效数据行: " << line << "，错误: " << e.what() << std::endl;
		}
	}

	ifs.close();
}
void Library::searchBook(const std::string& name)
{
	for (auto& it : _books)
	{
		if (it.getName() == name)
		{
			std::cout << "查找到了该书的信息：" << std::endl;
			it.show();
			return;
		}
	}
}

void Library::borrowBook(const std::string& name)
{
	for (auto& book : _books)
	{
		if (book.getName() == name)
		{
			if (book._status == 1)
			{
				book._status = 0;
				std::cout << "借阅成功。";
			}
			else { std::cout << "书籍已借出。"; }
			return;
		}
	}
	std::cout << "未找到书籍。";
}

void Library::returnBook(const std::string& name)
{
	for (auto& it : _books)
	{
		if (it.getName() == name)
		{
			std::cout << "你可以归还这本书" << std::endl;
			it.show();
			it._status = true;
			return;
		}
		else if (it.getName() == name && it._status == true)
		{
			std::cout << "这本书没有借出" << std::endl;
			return;
		}
		else if (it.getName() == name && it._status == false)
		{
			std::cout << "你可以归还这本书" << std::endl;
			it.show();
			return;
		}
		else
		{
			std::cout << "没有找到这本书" << std::endl;
			return;
		}
	}
}

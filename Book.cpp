#include "Book.h"
int Book::_count = 0;
Book::Book()
{
}
Book::Book(std::string name, int id, int price) :_name(name), _id(id), _price(price)
{
	_status = 1;
	++_count;
}
Book::~Book()
{
}
void Book::show()
{
	std::cout << "书名: " << _name << ", 序号: " << _id << ", 价格: " << _price
		<< ", 状态:" << (_status == 0 ? "借出" : "在馆") << std::endl;
}
std::string Book::getName()
{
	return _name;
}
int Book::getId()
{
	return _id;
}
int Book::getPrice()
{
	return _price;
}

void Book::saveRecord()
{
	std::ofstream ofs;
	ofs.open("book.csv", std::ios::app);
	if (ofs.is_open())
	{
		ofs << _name << "," << _id << "," << _price << "," << _status << std::endl;
	}
	else
	{
		std::cout << "文件打开失败！" << std::endl;
	}
	ofs.close();
}
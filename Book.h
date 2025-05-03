#pragma once
#include <iostream>
#include <string>
#include"Library.h"
#include<fstream>
class Book
{
	std::string _name;
	int _id;
	int _price;
	int _status;
	static int _count;
public:
	Book();
	Book(std::string name, int id, int price);
	~Book();
	void show();
	std::string getName();
	int getId();
	int getPrice();
	void saveRecord();
	friend class Library;
};


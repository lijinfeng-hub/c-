//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//class B
//{
//	int x, y;
//public:
//	B() {
//		x = y = 0;
//		std::cout << "con1\t";
//	}
//	B(int i) {
//		x = i; y = 0;
//		std::cout << "con2\t";
//	}
//	B(int i, int j) {
//		x = i; y = j;
//		std::cout << "con3\t";
//	}
//	~B() {
//		std::cout << "DES\t";
//	}
//};
//int main()
//{
//	B* ptr;
//	ptr = new B[3];
//	ptr[0] = B();
//	ptr[1] = B(1);
//	ptr[2] = B(2, 3);
//	delete[]ptr;
//	return 0;
//}
//#include<iostream>
//#include<vector>
//#include<map>
//#include<string>
//#include<algorithm>
//#include<deque>
//#include<numeric>
//#include<fstream>
//class Speaker;
//class speechManager
//{
//public:
//	std::vector<int>v1;
//	std::vector<int>v2;
//	std::vector<int>vVictory;
//	std::map<int, Speaker>m_Speaker;
//	int m_index;
//	void creatSpeaker();
//	speechManager();
//	~speechManager();
//	void initSpeech();
//	void startSpeech();
//	void speechDraw();
//	void speechContest();
//	void showMenu();
//	void showScore();
//	void exitsystem();
//	void saveRecord();
//	void loadRecord();
//	bool fileState;
//	void clearReport();
//	std::map<int, std::vector<std::string>>m_record;
//};
//class Speaker
//{
//public:
//	std::string _name;
//	std::vector<double>_score;
//};
//void speechManager::speechDraw()
//{
//	std::cout << "第" << this->m_index << "轮比赛选手正在抽签" << std::endl;
//	std::cout << "------------------------------------" << std::endl;
//	std::cout << "抽签后演讲的顺序：" << std::endl;
//	if (this->m_index == 1)
//	{
//		std::random_shuffle(this->v1.begin(), this->v1.end());
//		for (int i = 0; i < this->v1.size(); i++)
//		{
//			std::cout << "选手" << this->m_Speaker[this->v1[i]]._name << "抽到的签号是：" << this->v1[i] << std::endl;
//		}
//	}
//	else
//	{
//		std::random_shuffle(this->v2.begin(), this->v2.end());
//		for (int i = 0; i < this->v2.size(); i++)
//		{
//			std::cout << "选手" << this->m_Speaker[this->v2[i]]._name << "抽到的签号是：" << this->v2[i] << std::endl;
//		}
//	}
//	std::cout << "------------------------------------" << std::endl;
//	system("pause");
//}
//void speechManager::saveRecord()
//{
//	std::ofstream ofs;
//	ofs.open("speech.csv", std::ios::out | std::ios::app);
//	for (auto it = vVictory.begin(); it != vVictory.end(); it++)
//	{
//		ofs << "序号：" << *it << " , " << "姓名：" << this->m_Speaker[*it]._name << " , " << this->m_Speaker[*it]._score[1] << "," << std::endl;
//	}ofs << std::endl;
//	ofs.close();
//}
//void speechManager::clearReport()
//{
//	std::cout << "是否清空比赛记录？" << std::endl;
//	std::cout << "1.是" << std::endl;
//	std::cout << "2.否" << std::endl;
//	int choice;
//	std::ofstream ofs("speech.csv", std::ios::out | std::ios::trunc);
//	std::cin >> choice;
//	switch (choice)
//	{
//	case 1:
//		ofs.clear();
//		ofs.close();
//		std::cout << "比赛记录已清空！" << std::endl;
//		break;
//	case 2:
//		ofs.close();
//		break;
//	}
//}
//void speechManager::showScore()
//{
//	std::cout << "第" << this->m_index << "轮晋级选手信息如下：" << std::endl;
//	std::vector<int>v;
//	if (this->m_index == 1)
//	{
//		v = v2;
//	}
//	else
//	{
//		v = vVictory;
//	}
//	for (auto it = v.begin(); it != v.end(); ++it)
//	{
//		std::cout << "编号：" << *it << " 选手" << this->m_Speaker[*it]._name << " 得分：" << this->m_Speaker[*it]._score[this->m_index - 1] << std::endl;
//	}
//}
//void speechManager::loadRecord()
//{
//	std::ifstream ifs;
//	ifs.open("speech.csv", std::ios::in);
//	if (ifs.is_open())
//	{
//		char ch;
//		ifs >> ch;
//		if (ifs.eof())
//		{
//			std::cout << "文件为空！" << std::endl;
//			fileState = true;
//			ifs.close();
//			return;
//		}
//		fileState = false;
//		ifs.putback(ch);
//		std::string line;
//		while (std::getline(ifs, line))
//		{
//			std::cout << line << std::endl;
//		}
//	}
//	else
//	{
//		std::cout << "文件打开失败！" << std::endl;
//		fileState = true;
//		ifs.close();
//		return;
//	}
//}
//void speechManager::speechContest()
//{
//	std::cout << "-------------------------------第" << this->m_index << "轮比赛开始------------------------------" << std::endl;
//	std::vector<int>v_src;
//	std::multimap<double, int, std::greater<double>>groupSocre;
//	int num = 0;
//	if (this->m_index == 1)
//	{
//		v_src = this->v1;
//	}
//	else
//	{
//		v_src = this->v2;
//	}
//	for (auto it = v_src.begin(); it != v_src.end(); ++it)
//	{
//		std::deque<double>dq;
//		num++;
//		for (int i = 0; i < 10; i++)
//		{
//			double score = (rand() % 401 + 600) / 10.f;
//			std::cout << "分数为：" << score << " ";
//			dq.push_back(score);
//		}
//		std::cout << std::endl;
//		std::sort(dq.begin(), dq.end(), std::greater<double>());
//		dq.pop_back();
//		dq.pop_front();
//		double sum = std::accumulate(dq.begin(), dq.end(), 0.0);
//		double avg = sum / (double)dq.size();
//		std::cout << "选手" << this->m_Speaker[*it]._name << "的平均分为：" << avg << std::endl;
//		this->m_Speaker[*it]._score[this->m_index - 1] = avg;
//		groupSocre.insert(std::make_pair(avg, *it));
//		if (num % 6 == 0)
//		{
//			std::cout << "第" << num / 6 << "小组比赛名次：" << std::endl;
//			for (auto it = groupSocre.begin(); it != groupSocre.end(); ++it)
//			{
//				std::cout << "编号：" << it->second << "选手" << this->m_Speaker[it->second]._name << "得分：" << it->first << std::endl;
//			}
//			int count = 0;
//			for (auto it = groupSocre.begin(); it != groupSocre.end() && count < 3; ++it, count++)
//			{
//				if (this->m_index == 1)
//				{
//					this->v2.push_back(it->second);
//				}
//				else
//				{
//					this->vVictory.push_back(it->second);
//				}
//			}
//			groupSocre.clear();
//			std::cout << std::endl;
//		}
//	}
//	std::cout << "--------------------------第" << this->m_index << "轮比赛完毕------------------------------" << std::endl;
//}
//void speechManager::startSpeech()
//{
//	this->speechDraw();
//	this->speechContest();
//	this->showScore();
//	this->m_index++;
//	this->speechDraw();
//	this->speechContest();
//	this->showScore();
//	this->saveRecord();
//	std::cout << "本届比赛完毕，欢迎下届比赛！" << std::endl;
//}
//void speechManager::creatSpeaker()
//{
//	std::string nameSeed = "ABCDEFGHIJKL";
//	for (int i = 0; i < nameSeed.size(); i++)
//	{
//		std::string name = "选手";
//		name += nameSeed[i];
//		Speaker sp;
//		sp._name = name;
//		for (int j = 0; j < 7; j++)
//		{
//			sp._score.push_back(0);
//		}
//		this->v1.push_back(i + 10001);
//		this->m_Speaker.insert(std::make_pair(i + 10001, sp));
//	}
//}
//void speechManager::initSpeech()
//{
//	this->v1.clear();
//	this->v2.clear();
//	this->vVictory.clear();
//	this->m_Speaker.clear();
//	this->m_index = 1;
//}
//speechManager::speechManager()
//{
//	this->initSpeech();
//	this->creatSpeaker();
//}
//speechManager::~speechManager()
//{
//}
//void speechManager::exitsystem()
//{
//	std::cout << "退出成功！欢迎下次使用" << std::endl;
//	exit(0);
//}
//void speechManager::showMenu()
//{
//	std::cout << "***********************欢迎参加演讲比赛*********************" << std::endl;
//	std::cout << "***************请选择你的操作，输入序号即可：***************" << std::endl;
//	std::cout << "**********************1.开始演讲比赛************************" << std::endl;
//	std::cout << "**********************2.查看往届记录************************" << std::endl;
//	std::cout << "**********************3.退出演讲比赛************************" << std::endl;
//	std::cout << "**********************4.退出比赛程序************************" << std::endl;
//}
//int main()
//{
//	speechManager sm;
//	while (true)
//	{
//		sm.showMenu();
//		int choice;
//		std::cout << "请输入你的选择" << std::endl;
//		std::cin >> choice;
//		switch (choice)
//		{
//		case 1:
//			sm.startSpeech();
//			system("pause");
//			system("cls");
//			break;
//		case 2:
//			sm.loadRecord();
//			system("pause");
//			system("cls");
//			break;
//		case 3:
//			sm.clearReport();
//			system("pause");
//			system("cls");
//			break;
//		case 4:
//			sm.exitsystem();
//			break;
//		default:
//			std::cout << "输入有误，请重新选择！" << std::endl;
//			system("pause");
//			system("cls");
//			break;
//		}
//	}
//	return 0;
//}
//#include<iostream>
//#include<memory>
//int main()
//{
//	std::string* str = new std::string ("abc");
//	std::shared_ptr<std::string>sp{ str };
//	return 0;
//}
#include<iostream>
#include"Library.h"
void showMenu()
{
	std::cout << "*************************************************************************" << std::endl;
	std::cout << "*************************欢迎来到图书馆管理系统**************************" << std::endl;
	std::cout << "***********************选择你的操作，输入序号即可************************" << std::endl;
	std::cout << "****************************** 1.添加图书 *******************************" << std::endl;
	std::cout << "****************************** 2.查看图书 *******************************" << std::endl;
	std::cout << "****************************** 3.查询图书 *******************************" << std::endl;
	std::cout << "****************************** 4.借阅图书 *******************************" << std::endl;
	std::cout << "****************************** 5.归还图书 *******************************" << std::endl;
	std::cout << "****************************** 6.退出系统 *******************************" << std::endl;
	std::cout << "*************************************************************************" << std::endl;
}
int main()
{
	Library lib;
	while (true)
	{
		showMenu();
		int choice;
		std::cout << "请输入你的选择" << std::endl;
		std::cin >> choice;
		switch (choice)
		{
		case 1:
		{
			std::string _name;
			int _id;
			int _price;
			std::cout << "请输入图书名称" << std::endl;
			std::cin >> _name;
			std::cout << "请输入图书编号" << std::endl;
			std::cin >> _id;
			std::cout << "请输入图书价格" << std::endl;
			std::cin >> _price;
			Book bk(_name, _id, _price);
			lib.addBook(bk);
			system("pause");
			system("cls");
			break;
		}
		case 2:
			lib.showBooks();
			system("pause");
			system("cls");
			break;
		case 3:
		{
			std::string _name;
			std::cout << "请输入你要查询的图书名称" << std::endl;
			std::cin >> _name;
			lib.searchBook(_name);
			system("pause");
			system("cls");
			break;
		}
		case 4:
		{
			std::string _name;
			std::cout << "请输入你要借阅的图书名称" << std::endl;
			std::cin >> _name;
			lib.borrowBook(_name);
			system("pause");
			system("cls");
			break;
		}
		case 5:
		{
			std::string _name;
			std::cout << "请输入你要借阅的图书名称" << std::endl;
			std::cin >> _name;
			lib.returnBook(_name);
			system("pause");
			system("cls");
		}
		break;
		case 6:
			std::cout << "退出成功！欢迎下次使用" << std::endl;
			exit(0);
			break;
		default:
			std::cout << "输入有误，请重新选择！" << std::endl;
			system("pause");
			system("cls");
			break;
		}
	}
	return 0;
}
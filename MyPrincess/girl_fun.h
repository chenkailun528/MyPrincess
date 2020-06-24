#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <array>
#include <string>
#include <cstdlib>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::left;
using std::setw;
using std::array;



void show_girl_info(const string, const int, const int, const int, const int, const string, const int, const int, const  array<string, 5>, const array<int, 5>);
void do_job_info(int &, array<int, 5> &, int &);
void get_game_final_info(const int, array<int, 5>);
void talk_to_girl(array<int, 5>& );

/** 显示女儿相关信息*/
void show_girl_info(const string d_girl_name, const int c_open_year, const int d_girl_month, const int d_girl_date, const string d_girl_constell, const int d_girl_gold, const int c_array_len, const array<string, 5> d_arrays_name, const array<int, 5> d_girl_arrays)
{
	cout << "女儿的信息：" << endl << endl;
	cout << "姓名： " << d_girl_name << endl;
	cout << "生日： " << c_open_year << "-" << d_girl_month << "-" << d_girl_date << endl;
	cout << "星座： " << d_girl_constell << endl;
	cout << "金币： " << d_girl_gold << endl;
	// 打印核心属性
	cout << left;
	for (int i = 0; i < c_array_len; i++)
	{
		cout << d_arrays_name[i] << ":" << setw(2) << d_girl_arrays[i];
		// 计算实心方框的数量
		int solidCount = d_girl_arrays[i] / 10;

		for (int j = 0; j < 10; j++)
		{
			if (j < solidCount)
				cout << "■";
			else
				cout << "□";
		}
		cout << endl;
	}
}

/** 根据不同的选择修改女儿对应的属性*/
void do_job_info(int &month, array<int,5> &d_girl_arrays, int &d_girl_gold)
{
	/** 临时变量定义*/
	int choice, temp1, temp2, temp3, temp4;
	string month_parts[]{ "上旬", "中旬", "下旬" };
	for (int i = 0; i < 3; i++)
	{
		cout << "--" << month << "--" << month_parts[i] << endl;
		cout << "1、学习武艺\n2、上私塾\n3、学习礼法\n4、出城修行\n5、打工赚钱" << endl;
		cout << "请选择：";
		cin >> choice;
		/** 检测是否有钱  体力、智力、魅力、道德、气质*/
		srand(time(NULL));
		switch (choice)
		{
		case 1:	// 学习武艺 +体力、+魅力、-金钱
			d_girl_arrays[0] += temp1 = rand() % 10;
			d_girl_arrays[2] += temp2 = rand() % 10; 
			d_girl_gold -= temp3 = rand() % 10;
			cout << "在花果山修行武艺";
			cout << "体力:+" << temp1 << ", 魅力:+" << temp2 << "金钱:-" << temp3 << endl;
			break;
		case 2:	// 上私塾 +智力、+道德、-金钱
			d_girl_arrays[1] += temp1 = rand() % 10;
			d_girl_arrays[3] += temp2 = rand() % 10;
			d_girl_gold -= temp3 = rand() % 10;
			cout << "在哈佛大学学习";
			cout << "智力:+" << temp1 << ", 道德:+" << temp2 << "金钱:-" << temp3 << endl;
			break;
		case 3:	// 学习礼法 +道德、+气质、-金钱 
			d_girl_arrays[3] += temp1 = rand() % 10;
			d_girl_arrays[4] += temp2 = rand() % 10;
			d_girl_gold -= temp3 = rand() % 10;
			cout << "自学孔子礼法";
			cout << "道德:+" << temp1 << ", 气质:+" << temp2 << "金钱:-" << temp3 << endl;
			break;
		case 4:	// 出城修行 +体力、+智力  -金钱
			d_girl_arrays[0] += temp1 = rand() % 11;
			d_girl_arrays[1] += temp2 = rand() % 11;
			d_girl_gold -= temp3 = rand() % 51;
			cout << "大闹天宫";
			cout << "体力:+" << temp1 << ",智力:+" << temp2 << "金钱:-" << temp3 << endl;
			break;
		case 5:	// 打工赚钱  +金钱
			d_girl_gold += temp3 = rand() % 1000;
			cout << "吹空调等下班";
			cout << "体力:+" << temp1 << ", 魅力:+" << temp2 << "金钱:-" << temp3 << endl;
			break;
		default:
			break;
		}
	}
}

/** 游戏年份结束，根据各项属性获得不同结果*/
void get_game_final_info(const int c_array_len, array<int, 5> d_girl_arrays)
{
	int sum = 0;
	for (int i = 0; i < c_array_len; i++)
	{
		sum += d_girl_arrays[i];
	}
	if (sum >= 2000)
	{
		cout << "最优游戏结果:登基为女王陛下" << endl;
	}
	else if (sum >= 1800 && sum < 2000)
	{
		cout << "次优游戏结果:登基为女王陛下" << endl;
	}
	else
	{
		cout << "成为了富二代，加油吧老爹" << endl;
	}
}

/** 跟女儿谈话*/
void talk_to_girl(array<int, 5> &d_girl_arrays)
{
	/** 临时变量定义*/
	int temp1, temp2, temp3, temp4;
	cout << "经过认真详细的父女交流，女儿更加完美了" << endl;
	d_girl_arrays[1] += temp1= rand() % 10;
	d_girl_arrays[2] += temp2 = rand() % 10;
	d_girl_arrays[3] += temp3 = rand() % 10;
	d_girl_arrays[4] += temp4 = rand() % 10;
	/** 检测是否有钱  体力、智力、魅力、道德、气质*/
	cout << "智力:+" << temp1 << ", 魅力:+" << temp2 << "道德:+" << temp3 << "气质:+" << temp4<< endl;
}
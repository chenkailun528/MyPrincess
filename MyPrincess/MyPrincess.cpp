// MyPrincess.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

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
using std::array;
using std::left;
using std::setw;
int main()
{
	/** 游戏开始的年份*/
	const int c_open_year = 2019;
	/** 游戏结束的年份*/
	const int c_end_year = 2219;
	/** 游戏开始的月份*/
	const int c_open_month = 6;
	/** 游戏开始的金币*/
	int d_girl_gold = 20000;
	/** 游戏角色具有的属性长度*/
	const int c_array_len = 5;
	/** 父亲的名字*/
	string d_father_name;
	/** 女儿的名字*/
	string d_girl_name;
	/** 女儿的出生月份*/
	int d_girl_month;
	/** 女儿的出生日期*/
	int d_girl_date;
	/** 女儿的星座*/
	string d_girl_constell;
	/** 女儿的各项属性（体力、智力、魅力、道德、气质）*/
	array<int, c_array_len> d_girl_arrays;
	array<string, c_array_len> d_arrays_name = { "体力", "智力",  "魅力", "道德", "气质" };
	/** 星座二维数组 */
	string constell_name[12][2]{
	{"山羊座", "水瓶座"},        //一月
	{ "水瓶座", "双鱼座" },      //二月
	{ "双鱼座", "白羊座" },      //三月
	{ "白羊座", "金牛座" },      //四月
	{ "金牛座", "双子座" },      //五月
	{ "双子座", "巨蟹座" },      //六月
	{ "巨蟹座", "狮子座" },      //七月
	{ "狮子座", "处女座" },      //八月
	{ "处女座", "天枰座" },      //九月
	{ "天枰座", "天蝎座" },      //十月
	{ "天蝎座", "射手座" },      //十一月
	{ "射手座", "山羊座" }       //十二月
	};
	/** 各月份的跨星座日期 */
	int constell_dates[]{ 20, 19, 21, 20, 21, 22, 23, 23, 23, 24, 23, 22 };

	/** 临时变量定义*/
	int choice, temp1, temp2, temp3;

	cout << "请输入父亲的名字：";
	cin >> d_father_name;
	cout << "请输入女儿的名字：";
	cin >> d_girl_name;
	cout << "请输入女儿的出生年月：";
	cin >> d_girl_month >> d_girl_date;

	/** 计算出女儿的星座 */
	d_girl_constell = constell_name[d_girl_month - 1][d_girl_date / constell_dates[d_girl_month - 1]];
	/** 初始化女儿的基本属性*/
	srand(time(NULL));
	
	d_girl_arrays[0] = rand() % 50;	// 体力
	d_girl_arrays[1] = rand() % 50;	// 智力
	d_girl_arrays[2] = rand() % 50;	// 魅力
	d_girl_arrays[3] = rand() % 50;	// 道德
	d_girl_arrays[4 ] = rand() % 50;	//	气质

	cout << "女儿的信息：" << endl << endl;
	cout << "姓名： " << d_girl_name << endl;
	cout << "生日： " << c_open_year << "-" << d_girl_month << "-" << d_girl_date << endl;
	cout << "星座： " << d_girl_constell << endl;
	cout << "金币： " << d_girl_gold << endl;
	cout << "体力： " << d_girl_arrays[0] << "\t"<< "智力： " << d_girl_arrays[1] << "\t" << "魅力： " << d_girl_arrays[2] << "\t" << "道德： " << d_girl_arrays[3] << "\t" << "气质： " << d_girl_arrays[4] << endl;

	for (int year = c_open_year; year <= c_end_year; year++)
	{
		for (int month = (year == c_open_year) ? c_open_month : 1; month <= 12; month++)
		{
			// 判断本月是否女儿生日
			if (month == d_girl_month)
			{
				cout << "本月是" << d_girl_name << "生日，要不要送礼物呢？" << endl;
				// 根据用户的输入判断
			}
			cout << "\n1、查看状态\n2、安排行程\n3、亲自谈话\n4、存档\n5、读档 " << endl;
			cin >> choice;
			switch (choice)
			{
			case 1: // 查看状态
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
				break;

			case 2:  //安排行程: 一个月最多安排三次行程
			{
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
			break;
			case 3: //亲自谈话
				break;
			case 4: //存档
				break;
			case 5: //读档
				break;
			default:
				break;
			}
		}
	}

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

	




	// 1、为父女取名字
	// 2、为女儿录入初始信息生日、星座
	//	  根据女儿的星座，设置游戏的基本参数（体力、智力、魅力、道德、气质）
	// 3、开始游戏大循环
	// 游戏从2019年7月份开始
	// 4、根据各项参数，判定游戏结果
}


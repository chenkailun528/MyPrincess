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

/** ��ʾŮ�������Ϣ*/
void show_girl_info(const string d_girl_name, const int c_open_year, const int d_girl_month, const int d_girl_date, const string d_girl_constell, const int d_girl_gold, const int c_array_len, const array<string, 5> d_arrays_name, const array<int, 5> d_girl_arrays)
{
	cout << "Ů������Ϣ��" << endl << endl;
	cout << "������ " << d_girl_name << endl;
	cout << "���գ� " << c_open_year << "-" << d_girl_month << "-" << d_girl_date << endl;
	cout << "������ " << d_girl_constell << endl;
	cout << "��ң� " << d_girl_gold << endl;
	// ��ӡ��������
	cout << left;
	for (int i = 0; i < c_array_len; i++)
	{
		cout << d_arrays_name[i] << ":" << setw(2) << d_girl_arrays[i];
		// ����ʵ�ķ��������
		int solidCount = d_girl_arrays[i] / 10;

		for (int j = 0; j < 10; j++)
		{
			if (j < solidCount)
				cout << "��";
			else
				cout << "��";
		}
		cout << endl;
	}
}

/** ���ݲ�ͬ��ѡ���޸�Ů����Ӧ������*/
void do_job_info(int &month, array<int,5> &d_girl_arrays, int &d_girl_gold)
{
	/** ��ʱ��������*/
	int choice, temp1, temp2, temp3, temp4;
	string month_parts[]{ "��Ѯ", "��Ѯ", "��Ѯ" };
	for (int i = 0; i < 3; i++)
	{
		cout << "--" << month << "--" << month_parts[i] << endl;
		cout << "1��ѧϰ����\n2����˽��\n3��ѧϰ��\n4����������\n5����׬Ǯ" << endl;
		cout << "��ѡ��";
		cin >> choice;
		/** ����Ƿ���Ǯ  ���������������������¡�����*/
		srand(time(NULL));
		switch (choice)
		{
		case 1:	// ѧϰ���� +������+������-��Ǯ
			d_girl_arrays[0] += temp1 = rand() % 10;
			d_girl_arrays[2] += temp2 = rand() % 10; 
			d_girl_gold -= temp3 = rand() % 10;
			cout << "�ڻ���ɽ��������";
			cout << "����:+" << temp1 << ", ����:+" << temp2 << "��Ǯ:-" << temp3 << endl;
			break;
		case 2:	// ��˽�� +������+���¡�-��Ǯ
			d_girl_arrays[1] += temp1 = rand() % 10;
			d_girl_arrays[3] += temp2 = rand() % 10;
			d_girl_gold -= temp3 = rand() % 10;
			cout << "�ڹ����ѧѧϰ";
			cout << "����:+" << temp1 << ", ����:+" << temp2 << "��Ǯ:-" << temp3 << endl;
			break;
		case 3:	// ѧϰ�� +���¡�+���ʡ�-��Ǯ 
			d_girl_arrays[3] += temp1 = rand() % 10;
			d_girl_arrays[4] += temp2 = rand() % 10;
			d_girl_gold -= temp3 = rand() % 10;
			cout << "��ѧ������";
			cout << "����:+" << temp1 << ", ����:+" << temp2 << "��Ǯ:-" << temp3 << endl;
			break;
		case 4:	// �������� +������+����  -��Ǯ
			d_girl_arrays[0] += temp1 = rand() % 11;
			d_girl_arrays[1] += temp2 = rand() % 11;
			d_girl_gold -= temp3 = rand() % 51;
			cout << "�����칬";
			cout << "����:+" << temp1 << ",����:+" << temp2 << "��Ǯ:-" << temp3 << endl;
			break;
		case 5:	// ��׬Ǯ  +��Ǯ
			d_girl_gold += temp3 = rand() % 1000;
			cout << "���յ����°�";
			cout << "����:+" << temp1 << ", ����:+" << temp2 << "��Ǯ:-" << temp3 << endl;
			break;
		default:
			break;
		}
	}
}

/** ��Ϸ��ݽ��������ݸ������Ի�ò�ͬ���*/
void get_game_final_info(const int c_array_len, array<int, 5> d_girl_arrays)
{
	int sum = 0;
	for (int i = 0; i < c_array_len; i++)
	{
		sum += d_girl_arrays[i];
	}
	if (sum >= 2000)
	{
		cout << "������Ϸ���:�ǻ�ΪŮ������" << endl;
	}
	else if (sum >= 1800 && sum < 2000)
	{
		cout << "������Ϸ���:�ǻ�ΪŮ������" << endl;
	}
	else
	{
		cout << "��Ϊ�˸����������Ͱ��ϵ�" << endl;
	}
}

/** ��Ů��̸��*/
void talk_to_girl(array<int, 5> &d_girl_arrays)
{
	/** ��ʱ��������*/
	int temp1, temp2, temp3, temp4;
	cout << "����������ϸ�ĸ�Ů������Ů������������" << endl;
	d_girl_arrays[1] += temp1= rand() % 10;
	d_girl_arrays[2] += temp2 = rand() % 10;
	d_girl_arrays[3] += temp3 = rand() % 10;
	d_girl_arrays[4] += temp4 = rand() % 10;
	/** ����Ƿ���Ǯ  ���������������������¡�����*/
	cout << "����:+" << temp1 << ", ����:+" << temp2 << "����:+" << temp3 << "����:+" << temp4<< endl;
}
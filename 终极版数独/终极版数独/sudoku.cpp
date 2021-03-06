#include <cstdio>
#include <stdlib.h>
#include <string>
#include<algorithm>
#include<iostream>
#include"Function.h"
#include<fstream>
using namespace std;
//--------------------------parameters for make sudoku--------------------------
int n;
char ans[200000000];
int cnt;
//--------------------------parameters for make sudoku--------------------------
//--------------------------function for solve sudoku---------------------------
string get_path() {
	string input;
	cin >> input;
	return input;
}
//--------------------------function for solve sudoku---------------------------
int main(int argc, char* argv[])
{
	Build new_Build;
	Solve new_Solve;
//------------------------------make sudoku-------------------------------------
	if (argc == 3 && strcmp(argv[1], "-c") == 0)
	{
		int len = strlen(argv[2]);
		for (int i = 0; i < len; i++)
		{
			if (argv[2][i] >= '0'&&argv[2][i] <= '9')
			{
				n = (n + (argv[2][i] - '0')) * 10;
			}
			else
			{
				cout << "Error!请输入数字！" << endl;
				return 0;
			}
		}
		n = n / 10;
		if (n == 0 || n > 1000000)
		{
			cout << "请确认输入的数在0到1000000之间！" << endl;
			return 0;
		}
//--------------------------exception handling ------------------------------
		new_Build.Permutation_Change(ans, cnt, n);
		ans[cnt++] = '\0';

		string sudoku = "sudoku.txt";
		ofstream out(sudoku);
		out << ans << endl;
	}
//----------------------------solve sudoku-----------------------------------
	else if (argc == 3 && strcmp(argv[1], "-s") == 0)
	{
		int firstone = 0;
		string input_path;
		input_path = argv[2];

		if (strcmp(argv[2], "shudu.txt") != 0)
		{
			cout << "请保证输入为shudu.txt" << endl;
			return 0;
		}
//--------------------------exception handling-------------------------------
		int cont = 0;
		string output = "sudoku.txt";
		string buf;
		ifstream in(input_path);
		ofstream ano_out(output);
		new_Solve.Init();

		while (getline(in, buf))
		{
			if (buf == "")
				continue;

			new_Solve.SaveProblem(cont, buf);
			cont++;
			if (cont == 9)
			{
				firstone++;
				new_Solve.GetAns(0, 0);
				for (int i = 0; i < 9; i++)
				{
					if (firstone != 1 && i == 0)
					{
						ano_out << endl;
					}
					ano_out << new_Solve.get_ans(i) << endl;
				}
				cont = 0;
				new_Solve.Init();
			}
		}
	}
	else
	{
		cout << "请检查输入！" << endl;
	}
//-------------------------exception handling---------------------------------	
	return 0;
}

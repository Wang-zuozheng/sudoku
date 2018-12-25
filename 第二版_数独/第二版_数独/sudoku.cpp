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

string get_path() {
	string input;
	cin >> input;
	return input;
}

int main(int argc, char* argv[])
{
	Build new_Build;
	Solve new_Solve;
	if (argc == 3 && strcmp(argv[1], "-c") == 0)
	{
		int len = strlen(argv[2]);
		for (int i = 0; i < len; i++)
		{
			if (argv[2][i] >= '0'&&argv[2][i] <= '9')
			{
				n = (n+(argv[2][i] - '0'))*10;
			}
			else
			{
				printf("Error!\n");
				return 0;
			}
		}
		n = n / 10;
		int flag = 0;
		do
		{
			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 6; j++)
				{
					for (int k = 0; k < 6; k++)
					{
						new_Build.BuildSudoku(i, j, k, ans, cnt);
						new_Build.add(1);
						if (new_Build.get_cnt() == n)
						{
							flag = 1; break;
						}
					}
					if (flag) break;
				}
				if (flag) break;
			}
			if (flag) break;
		} while (next_permutation(new_Build.get_permutation() + 1, new_Build.get_permutation() + 9));
		ans[cnt++] = '\0';
		string sudoku = "sudoku.txt";//printf
		ofstream out(sudoku);
		
			out << ans << endl;
		
	}

	if (argc == 3 && strcmp(argv[1], "-s") == 0)
	{
		int firstone = 0;
		string input_path;
		input_path = argv[2];
		//cout << input_path;
		int cont = 0;
		string output = "output.txt";
		string buf;
		//	char buf[100];  /*缓冲区*/
		ifstream in(input_path);
		//cout << input_path;
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
				/*初始化*/
				for (int i = 0; i < 9; i++) 
				{
					if (firstone != 1&&i == 0)
					{
						ano_out << endl;
					}
					ano_out << new_Solve.get_save(i) << endl;  //可能有问题
				}				
				cont = 0;
				new_Solve.Init();
			}
		}
	}

	system("pause");
	return 0;
}

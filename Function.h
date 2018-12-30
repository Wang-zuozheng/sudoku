#pragma once\

#ifndef __FUNCTION_H__

#define  __FUNCTION_H__
#include <string>
using namespace std;
class Build
{
private:
	int Change[3] = { 2,3,3 };
	int permutation[9] = { 3,1,2,4,5,6,7,8,9 };
	char rule1[7][4] = { "36","63" },
		rule2[7][4] = { "258","285","528","582","825","852" },
		rule3[7][4] = { "147","174","417","471","714","741" };
	int BuildCnt = 0;
public:
	void add(int a) {
		BuildCnt += a;
	}
	int get_cnt() {
		return BuildCnt;
	}
	int * get_permutation() {
		return permutation;
	}
	void BuildSudoku(int Row_change1, int Row_change2, int Row_change3, char *ans, int &cnt)
	{
		int i, k, j;
		for (i = 0; i < 9; i++)
		{
			ans[cnt++] = permutation[i] + '0';
			if (i != 8)
				ans[cnt++] = ' ';
		}
		ans[cnt++] = '\n';
		for (k = 0; k < 3; k++)
		{
			int p;
			p = Change[k];
			for (i = 0; i < p; i++)
			{
				for (j = 0; j < 9; j++)
				{
					if (k == 0)
					{
						ans[cnt++] = permutation[(j + (rule1[Row_change1][i] - '0')) % 9] + '0';

						if (j != 8)
							ans[cnt++] = ' ';
					}
					if (k == 1)
					{
						ans[cnt++] = permutation[(j + (rule2[Row_change2][i] - '0')) % 9] + '0';

						if (j != 8)
							ans[cnt++] = ' ';
					}
					if (k == 2)
					{
						ans[cnt++] = permutation[(j + (rule3[Row_change3][i] - '0')) % 9] + '0';

						if (j != 8)
							ans[cnt++] = ' ';
					}
				}
				ans[cnt++] = '\n';
			}
		}
		ans[cnt++] = '\n';
	}
	void Permutation_Change(char *ans, int &cnt, int &n)
	{
		int i, j, k;
		do
		{
			for (i = 0; i < 2; i++)
			{
				for (j = 0; j < 6; j++)
				{
					for (k = 0; k < 6; k++)
					{
						BuildSudoku(i, j, k, ans, cnt);
						add(1);
						if (get_cnt() == n)
						{
							return;
						}
					}
				}
			}
		} while (next_permutation(get_permutation() + 1, get_permutation() + 9));
	}
};
class node {
public:
	int row[10][10];
	int column[10][10];
	int area[10][10];
};
class Solve {
private:
	char save[9][10];
	char ans1[9][20];
	bool getit = 0;
	node Point[4];
public:

	char* get_ans(int i)
	{
		return ans1[i];
	}

	char* get_save(int i)
	{
		return save[i];
	}

	void Init()
	{
		memset(Point, 0, 4 * sizeof(struct node));
		getit = 0;
	}
	void Change()
	{
		int i, j;
		for (i = 0; i < 9; i++)
		{
			j = 0;
			for (int k = 0; k < 9; k++)
			{
				ans1[i][j] = save[i][k];
				j++;
				if (k != 8)
				{
					ans1[i][j] = ' ';
					j++;
				}
			}
			ans1[i][j] = '\0';
		}
	}
	void GetAns(int r, int col)
	{
		int i;
		while (save[r][col] != '0')
		{
			if (col < 8)
				col++;
			else
			{
				col = 0;
				r++;
			}
			if (r == 9)
			{
				getit = 1;
				Change();
				return;//get the answer!
			}

		}
		int flag = 0;
		for (i = 1; i < 10; i++)
		{
			if (Point[0].row[r][i] == 0 && Point[1].column[col][i] == 0 && Point[2].area[(r / 3) * 3 + col / 3][i] == 0)
			{
				flag = 1;
				Point[0].row[r][i] = 1;
				Point[1].column[col][i] = 1;
				Point[2].area[(r / 3) * 3 + col / 3][i] = 1;
				save[r][col] = i + '0';
				GetAns(r, col);
			}

			if (flag)
			{
				flag = 0;
				if (getit)
					return;
				else
				{
					save[r][col] = '0';
					Point[0].row[r][i] = 0;
					Point[1].column[col][i] = 0;
					Point[2].area[(r / 3) * 3 + col / 3][i] = 0;
				}
			}
		}


	}

	void SaveProblem(int cnt, string buf)//cnt是行 
	{
		int i;
		int num;
		int j = 0;
		for (i = 0; i < 17; i++)//i是列 
		{
			if (i % 2 == 0)
			{
				save[cnt][j] = buf[i];

				num = buf[i] - '0';

				Point[0].row[cnt][num] = 1;
				Point[1].column[j][num] = 1;
				Point[2].area[(cnt / 3) * 3 + j / 3][num] = 1;
				j++;
			}
		}
		save[cnt][j] = '\0';
	}
};


#endif

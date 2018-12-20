#include <cstdio>
#include <stdlib.h>
#include <string>
#include<iostream>
#include<fstream>
using namespace std;

char save[10][10];
int getit = 0;
//�������У��������У������ھŹ���������ֵı�ʶ 
struct node
{
	int row[10][10];//��0��ʼ 
	int column[10][10];
	int area[10][10];
}Point[4];//��0��ʼ 

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
void SaveProblem(int cnt, string buf)//cnt���� 
{
	int i;
	int num;
	int j = 0;
	for (i = 0; i < 17; i++)//i���� 
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
}
string get_path() {
	string input;
	cin >> input;
	return input;
}

int main(int argc,char* argv[])
{
	string input_path;
	input_path = argv[1];
	cout << input_path;
	//input_path= get_path();
	int cnt = 0;
	string output = "output.txt";
	string buf;
	//	char buf[100];  /*������*/
	ifstream in (input_path);
	cout << input_path;
	ofstream out (output);
	while (getline(in, buf)) {
		
		if (buf == "\n")
			continue;
		SaveProblem(cnt, buf);
		cnt++;

		if (cnt == 9)
		{
			GetAns(0, 0);
		/*	for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					printf("%c", save[i][j]);
				}
				printf("\n");
			}*/
			/*��ʼ��*/
			for (int i = 0; i < 9; i++) {
				out << save[i] << endl;
			}
			out << endl;
		}
	}
	system("pause");
	return 0;
	////  FILE *fp;            /*�ļ�ָ��*/
	//int cnt = 0;
	//memset(Point, 0, sizeof(struct node));
	////memset 
	//if ((fp = fopen("shudu.txt","r+")) == NULL)
	//{
	//	perror("fail to read");
	//	exit(1);
	//}
	//while (fgets(buf, 19, fp) != NULL)//�ڶ�������ָ���洢���ݵĴ�С//���ڶ���������ô�� 
	//{
	//	if (strcmp(buf, "\n") == 0)//������֮��Ŀ��� 
	//		continue;
	//	SaveProblem(cnt, buf);
	//	cnt++;

	//	if (cnt == 9)
	//	{
	//		GetAns(0, 0);
	//		for (int i = 0; i < 9; i++)
	//		{
	//			for (int j = 0; j < 9; j++)
	//			{
	//				printf("%c", save[i][j]);
	//			}
	//			printf("\n");
	//		}
	//		/*��ʼ��*/
	//		fprintf(fp, "%s", save);
	//	//}
	//}
	//system("pause");
	//return 0;
}

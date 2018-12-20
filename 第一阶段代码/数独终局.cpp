//125.4s 
#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;

int n, permutation[9] ={3,1,2,4,5,6,7,8,9};
char ans[200000000];
int cnt;
int BuildCnt=0;
char rule1[7][4] = { "36","63" },rule2[7][4] = { "258","285","528","582","825","852" }, rule3[7][4] = { "147","174","417","471","714","741" };

void BuildSudoku(int Row_change1,int Row_change2,int Row_change3) 
{
	int Change[3]={2,3,3};
	int i,k,j;

	for(i=0;i<9;i++)
	{
		ans[cnt++]=permutation[i]+'0';
	//	i++;
	if(i!=8)
		ans[cnt++]=' ';
	}
	
	
	ans[cnt++]='\n';
	for(k = 0 ;k < 3; k ++)
	{
		int p;
		p=Change[k];
		for(i = 0 ;i < p ; i ++ )
		{
			for(j = 0;j < 9 ; j ++)
			{
				if(k == 0)
				{
					ans[cnt++]=permutation[(j+(rule1[Row_change1][i]-'0'))%9]+'0';
					//j++;
					if(j!=8)
					ans[cnt++]=' ';
				}
				if(k == 1)
				{
					ans[cnt++]=permutation[(j+(rule2[Row_change2][i]-'0'))%9]+'0';
					//j++;
					if(j!=8)	
					ans[cnt++]=' ';
				}
				if(k == 2)
				{
					ans[cnt++]=permutation[(j+(rule3[Row_change3][i]-'0'))%9]+'0';
				//	j++;
					if(j!=8)
					ans[cnt++]=' ';
				}
			}
			ans[cnt++]='\n';
		}	
	}
	ans[cnt++]='\n';
}


int main()
{
	int flag=0;

	cnt=0;
	
	scanf("%d",&n); 

	do
	{	
		for (int i = 0; i < 2; i++)
		{ 
			for (int j = 0; j < 6; j++)
			{
				for (int k = 0; k < 6; k++)
				{
					BuildSudoku(i, j, k);
				
					if (++BuildCnt == n)
					{
						flag=1;break;
					}	
				}
				if(flag) break;
			}
			if(flag) break;
		}	
		if(flag) break;
	} while (next_permutation(permutation+1,permutation+9));
	
    printf("%s",ans);
	return 0;
}

 

	


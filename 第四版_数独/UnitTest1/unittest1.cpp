#include "stdafx.h"
#include "CppUnitTest.h"
#include<algorithm>
#include"..\第三版_数独\Function.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: 在此输入测试代码
			char ans_test[200];
			int cnt = 0;
			int n = 1;
			int expect = 163;
			Build new_Build_test;
			memset(ans_test, 0, sizeof(ans_test));
			new_Build_test.Permutation_Change(ans_test, cnt, n);
			Assert::AreEqual(cnt, expect);
		}

		TEST_METHOD(TestMethod2)
		{
			char ans_test[200];
			int cnt = 0;
			int n = 1;
			char expect_test[200] = { "3 1 2 4 5 6 7 8 9\n4 5 6 7 8 9 3 1 2\n7 8 9 3 1 2 4 5 6\n2 4 5 6 7 8 9 3 1\n6 7 8 9 3 1 2 4 5\n9 3 1 2 4 5 6 7 8\n1 2 4 5 6 7 8 9 3\n5 6 7 8 9 3 1 2 4\n8 9 3 1 2 4 5 6 7\n\n"};
			Build new_Build_test;
			memset(ans_test, 0, sizeof(ans_test));
			new_Build_test.Permutation_Change(ans_test, cnt, n);
			Assert::AreEqual(ans_test, expect_test);
		}

		TEST_METHOD(TestMethod3)
		{
			Build new_Build_test;
			int real;;
			int expect = 3;
			new_Build_test.add(3);
			real = new_Build_test.get_cnt();
			Assert::AreEqual(real, expect);
		}

		TEST_METHOD(TestMethod4)
		{
			Build new_Build_test;
			char ans9[200];
			memset(ans9, 0, sizeof(ans9));
			int cnt = 0;
			int permutation[9] = { 3,1,2,4,5,6,7,8,9 };
			char expect_test[200] = { "3 1 2 4 5 6 7 8 9\n7 8 9 3 1 2 4 5 6\n4 5 6 7 8 9 3 1 2\n9 3 1 2 4 5 6 7 8\n2 4 5 6 7 8 9 3 1\n6 7 8 9 3 1 2 4 5\n5 6 7 8 9 3 1 2 4\n8 9 3 1 2 4 5 6 7\n1 2 4 5 6 7 8 9 3\n\n" };
			int  Row_change1 = 1;
			int  Row_change2 = 4;
			int  Row_change3 = 3;
			new_Build_test.BuildSudoku(Row_change1, Row_change2, Row_change3, ans9, cnt);
			Assert::AreEqual(ans9, expect_test);
		}

		TEST_METHOD(TestMethod5)
		{
			Build new_Build_test;
			int n = 2;
			int *p;
			int a[9];
			int expect[9] = { 3,1,2,4,5,6,7,9,8 };
			do
			{
				n--;
				if (n == 0)break;
			}
			while(next_permutation(new_Build_test.get_permutation() + 1, new_Build_test.get_permutation() + 9));
			p=new_Build_test.get_permutation();
			for (int i = 0; i < 9; i++)
			{
				a[i] = *p;
				p++;
			}
			for (int i = 0; i < 9; i++)
			Assert::AreEqual(a[i], expect[i]);
			
		}
	};
}
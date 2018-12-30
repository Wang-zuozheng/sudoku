#include "stdafx.h"
#include "CppUnitTest.h"
#include<algorithm>
#include"..\sudoku\Function.h"
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
			char expect_test[200] = { "3 1 2 4 5 6 7 8 9\n4 5 6 7 8 9 3 1 2\n7 8 9 3 1 2 4 5 6\n2 4 5 6 7 8 9 3 1\n6 7 8 9 3 1 2 4 5\n9 3 1 2 4 5 6 7 8\n1 2 4 5 6 7 8 9 3\n5 6 7 8 9 3 1 2 4\n8 9 3 1 2 4 5 6 7\n\n" };
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
			} while (next_permutation(new_Build_test.get_permutation() + 1, new_Build_test.get_permutation() + 9));
			p = new_Build_test.get_permutation();
			for (int i = 0; i < 9; i++)
			{
				a[i] = *p;
				p++;
			}
			for (int i = 0; i < 9; i++)
				Assert::AreEqual(a[i], expect[i]);
		}

		TEST_METHOD(TestMethod6)
		{

			Solve new_Solve_test;
			string expect = "312456789", actual;
			int cnt = 0;
			int*p;
			string buf = "3 1 2 4 5 6 7 8 9";
			new_Solve_test.SaveProblem(cnt, buf);
			actual = new_Solve_test.get_save(cnt);
			Assert::AreEqual(actual, expect);
		}


		TEST_METHOD(TestMethod7)
		{
			Solve new_Solve_test;
			int cnt = 0;
			int*p;
			string actual;
			string buf = "3 1 2 4 5 6 7 8 9";
			new_Solve_test.SaveProblem(cnt, buf);
			new_Solve_test.Change();
			actual = new_Solve_test.get_ans(cnt);
			Assert::AreEqual(actual, buf);
		}


		TEST_METHOD(TestMethod8)
		{
			Solve new_Solve_test;
			int cnt = 0;
			int*p;
			string actual;
			string buf = "3 1 2 4 5 6 7 8 9";
			new_Solve_test.SaveProblem(cnt, buf);
			new_Solve_test.GetAns(9, 0);
			actual = new_Solve_test.get_ans(cnt);
			Assert::AreEqual(actual, buf);
		}


		TEST_METHOD(TestMethod9)
		{
			Solve new_Solve_test;
			int cnt = 0, cnt1 = 1, cnt2 = 2, cnt3 = 3, cnt4 = 4, cnt5 = 5, cnt6 = 6, cnt7 = 7, cnt8 = 8;
			int*p;
			string actual6, actual7, actual8;
			string buf = "3 1 2 4 5 6 7 8 9", buf1 = "7 8 9 3 1 2 4 5 6", buf2 = "4 5 6 7 8 9 3 1 2", buf3 = "9 3 1 2 4 5 6 7 8", buf4 = "2 4 5 6 7 8 9 3 1", buf5 = "6 7 8 9 3 1 2 4 5", buf6 = "5 6 7 8 9 3 0 0 4", buf7 = "8 9 0 1 2 0 0 0 0", buf8 = "1 2 4 5 6 7 0 0 3";
			string expect6 = "5 6 7 8 9 3 1 2 4", expect7 = "8 9 3 1 2 4 5 6 7", expect8 = "1 2 4 5 6 7 8 9 3";
			new_Solve_test.Init();
			new_Solve_test.SaveProblem(cnt, buf);
			new_Solve_test.SaveProblem(cnt1, buf1);
			new_Solve_test.SaveProblem(cnt2, buf2);
			new_Solve_test.SaveProblem(cnt3, buf3);
			new_Solve_test.SaveProblem(cnt4, buf4);
			new_Solve_test.SaveProblem(cnt5, buf5);
			new_Solve_test.SaveProblem(cnt6, buf6);
			new_Solve_test.SaveProblem(cnt7, buf7);
			new_Solve_test.SaveProblem(cnt8, buf8);
			new_Solve_test.GetAns(0, 0);
			actual6 = new_Solve_test.get_ans(cnt6);
			actual7 = new_Solve_test.get_ans(cnt7);
			actual8 = new_Solve_test.get_ans(cnt8);
			Assert::AreEqual(actual6, expect6);
			Assert::AreEqual(actual7, expect7);
			Assert::AreEqual(actual8, expect8);
		}


		TEST_METHOD(TestMethod10)
		{
			Solve new_Solve_test;
			int cnt = 0, cnt1 = 1, cnt2 = 2, cnt3 = 3, cnt4 = 4, cnt5 = 5, cnt6 = 6, cnt7 = 7, cnt8 = 8;
			int*p;
			string actual1, actual2;
			string buf = "3 1 2 4 5 6 7 8 9", buf1 = "7 8 0 0 1 2 4 5 0", buf2 = "4 5 0 7 8 0 0 1 2", buf3 = "9 3 1 2 4 5 6 7 8", buf4 = "2 4 5 6 7 8 9 3 1", buf5 = "6 7 8 9 3 1 2 4 5", buf6 = "5 6 7 8 9 3 1 2 4", buf7 = "8 9 3 1 2 4 5 6 7", buf8 = "1 2 4 5 6 7 8 9 3";
			string expect1 = "7 8 9 3 1 2 4 5 6", expect2 = "4 5 6 7 8 9 3 1 2";
			new_Solve_test.Init();
			new_Solve_test.SaveProblem(cnt, buf);
			new_Solve_test.SaveProblem(cnt1, buf1);
			new_Solve_test.SaveProblem(cnt2, buf2);
			new_Solve_test.SaveProblem(cnt3, buf3);
			new_Solve_test.SaveProblem(cnt4, buf4);
			new_Solve_test.SaveProblem(cnt5, buf5);
			new_Solve_test.SaveProblem(cnt6, buf6);
			new_Solve_test.SaveProblem(cnt7, buf7);
			new_Solve_test.SaveProblem(cnt8, buf8);
			new_Solve_test.GetAns(0, 0);
			actual1 = new_Solve_test.get_ans(cnt1);
			actual2 = new_Solve_test.get_ans(cnt2);
			Assert::AreEqual(actual1, expect1);
			Assert::AreEqual(actual2, expect2);
		}
	};
}
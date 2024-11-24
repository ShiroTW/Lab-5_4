#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_5.4/Lab_5.4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
	TEST_CLASS(UnitTest2)
	{
	public:

		TEST_METHOD(TestIterativeSum)
		{
			int N = 2;
			double expected = 0;
			for (int i = N; i <= 20; i++)
			{
				expected += (cos(i) + sin(i)) / (1 + cos(i) * sin(i));
			}

			double actual = IterativeSum(N);

			Assert::AreEqual(expected, actual, 0.001, L"TestIterativeSum failed");
		}

		TEST_METHOD(TestRec1)
		{
			int N = 2;
			double expected = IterativeSum(N);
			double actual = Rec1(N, N);
			Assert::AreEqual(expected, actual, 0.001, L"TestRec1 failed");
		}

		TEST_METHOD(TestRec2)
		{
			int N = 2;
			double expected = IterativeSum(N);
			double actual = Rec2(N, 20);

			Assert::AreEqual(expected, actual, 0.001, L"TestRec2 failed");
		}

		TEST_METHOD(TestRec3)
		{
			int N = 2;
			double expected = IterativeSum(N);
			double actual = Rec3(N, N, 0);

			Assert::AreEqual(expected, actual, 0.001, L"TestRec3 failed");
		}

		TEST_METHOD(TestRec4)
		{
			int N = 2;
			double expected = IterativeSum(N);
			double actual = Rec4(N, 20, 0);

			Assert::AreEqual(expected, actual, 0.001, L"TestRec4 failed");
		}
	};
}

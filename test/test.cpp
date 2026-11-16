#include "pch.h"
#include "CppUnitTest.h"
#include "../ЛР 9.1/var.cpp"
#include "../ЛР 9.1/dod.cpp"
#include "../ЛР 9.1/sum.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test91
{
	TEST_CLASS(test91)
	{
	public:

		TEST_METHOD(TestDod)
		{
			nsVar::n = 1;
			nsVar::x = 2;
			nsVar::a = 0.5;
			nsDod::dod();
			Assert::AreEqual(0.0416666667, nsVar::a, 1e-9);
		}

		TEST_METHOD(TestSum_X2)
		{
			nsVar::x = 2;
			nsVar::e = 1e-6;
			nsSum::sum();
			Assert::AreEqual(0.5493060145, nsVar::s, 1e-9);
			Assert::AreEqual(8, nsVar::n);
		}

		TEST_METHOD(TestSum_X3)
		{
			nsVar::x = 3;
			nsVar::e = 1e-6;
			nsSum::sum();
			Assert::AreEqual(0.3465735369, nsVar::s, 1e-9);
			Assert::AreEqual(5, nsVar::n);
		}

		TEST_METHOD(TestSum_CloseToExact)
		{
			nsVar::x = 2;
			nsVar::e = 1e-6;
			nsSum::sum();
			double exact = 0.5 * log((nsVar::x + 1) / (nsVar::x - 1));
			Assert::AreEqual(exact, nsVar::s, 1e-5);
		}
	};
}
#include "pch.h"
#include "CppUnitTest.h"
#include <math.h>

#include "../ConsLab_9_1/dod.h"
#include "../ConsLab_9_1/sum.h"
#include "../ConsLab_9_1/var.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace nsSum;
using namespace nsVar;

namespace Lab91Test
{
    TEST_CLASS(SumTest)
    {
    public:
        const double PI_2 = 1.57079632679489661923;

        // pi/2 - сума ряду має збігатися з acos(x)
        TEST_METHOD(ArccosMatchesStdAcos)
        {
            double xs[] = { -0.8, -0.5, 0.0, 0.2, 0.5, 0.8 };
            e = 1e-10;
            for (double v : xs)
            {
                x = v;
                sum();
                Assert::AreEqual(acos(v), PI_2 - s, 1e-8);
            }
        }

        // при x = 0 сума ряду дорівнює 0, обчислено один доданок
        TEST_METHOD(ZeroArgument)
        {
            x = 0;
            e = 1e-10;
            sum();
            Assert::AreEqual(0.0, s, 1e-12);
            Assert::AreEqual(1, n);
        }
    };
}
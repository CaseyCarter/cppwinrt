#include "stdafx.h"
#include <assert.h>
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace winrt;

namespace UnitTests
{		
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            try
            {
                using namespace Windows::Foundation;
                Uri uri(L"http://kennykerr.ca/articles");
                assert(5 == 6);
            }
            catch (Exception /*ex*/)
            {
                Assert::Fail(L"No exception should be caught");
            }
        }
    };
}
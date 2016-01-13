#include "stdafx.h"
#include <assert.h>
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace winrt;

namespace UnitTests
{		
    TEST_CLASS(BasicTests)
    {
    public:

        TEST_METHOD(InstantiateUriType)
        {
            try
            {
                using namespace Windows::Foundation;
                Uri uri(L"http://kennykerr.ca/articles");
            }
            catch (Exception /*ex*/)
            {
                Assert::Fail(L"No exception should be caught");
            }
        }
    };
}
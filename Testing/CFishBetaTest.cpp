/**
 * \file CFishBetaTest.cpp
 *
 * \author Matheus Araujo
 */

#include "stdafx.h"
#include "CppUnitTest.h"
#include "Aquarium.h"
#include "FishBeta.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{
	/**
	 * \brief Test bed for fish beta class
	 */
	TEST_CLASS(CFishBetaTest)
	{
	public:
		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}

		
		TEST_METHOD(TestMethod1)
		{
			// TODO: Your test code here
		}

	};
}
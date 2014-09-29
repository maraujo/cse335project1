/**
 * \file CAquariumTest.cpp
 *
 * \author Matheus Araujo
 */

#include "stdafx.h"
#include "CppUnitTest.h"

#include "Aquarium.h"
#include "FishBeta.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Testing
{
	TEST_CLASS(CAquariumTest)
	{
	public:
		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}		
		
		TEST_METHOD(TestCAquariumConstruct)
		{
			CAquarium aquarium;
		}

		TEST_METHOD(TestCAquariumHitTest)
		{
			CAquarium aquarium;

			Assert::IsTrue(aquarium.HitTest(100, 200) == nullptr, L"Testing empty aquarium");

			shared_ptr<CFishBeta> fish1 = make_shared<CFishBeta>(&aquarium);
			fish1->SetLocation(100, 200);
			aquarium.Add(fish1);

			Assert::IsTrue(aquarium.HitTest(100, 200) == fish1, L"Testing fish at 100, 200");

			//If two images are on top of each other, it finds the image on top, no matter what order they are added in.
			shared_ptr<CFishBeta> fish2 = make_shared<CFishBeta>(&aquarium);
			fish2->SetLocation(100, 200);
			aquarium.Add(fish2);
			Assert::IsTrue(aquarium.HitTest(100, 200) == fish2, L"Testing fish2 if got");

			//It returns nullptr if you test where there is no image.
			Assert::IsTrue(aquarium.HitTest(350, 450) == nullptr, L"Testing null pointer if no image");
		}
		TEST_METHOD(TestCAquariumClear)
		{
			CAquarium aquarium;

			//Creates 2 fishes
			shared_ptr<CFishBeta> fish1 = make_shared<CFishBeta>(&aquarium);
			fish1->SetLocation(100, 200);
			aquarium.Add(fish1);

			shared_ptr<CFishBeta> fish2 = make_shared<CFishBeta>(&aquarium);
			fish2->SetLocation(100, 200);
			aquarium.Add(fish2);

			//Clear Aquarium
			aquarium.Clear();

			Assert::IsTrue(aquarium.NumItems() == 0, L"Testing Clear Aquarium");

		}

	};
}
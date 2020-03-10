#include "pch.h"
#include "CppUnitTest.h"
#include "../Intersection/Intersection.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace IntersectionUnitTest
{
	TEST_CLASS(IntersectionUnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Intersection inter1;
			inter1.count_intersection("testfile/test1.txt", "testfile/out.txt");
			int ans = inter1.points.size();
			Assert::AreEqual(6, ans);
		}
	};
}

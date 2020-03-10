#include "pch.h"
#include "CppUnitTest.h"
#include "../Intersection/Intersection.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace IntersectionUnitTest
{
	TEST_CLASS(IntersectionUnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1， Total)
		{
			Intersection inter1;
			inter1.count_intersection("testfile/test1.txt", "testfile/out.txt");
			Assert::AreEqual(6, (int)inter1.points.size());
			
			Intersection inter2;
			inter2.count_intersection("testfile/test2.txt", "testfile/out.txt");
			Assert::AreEqual(5, (int)inter2.points.size());
		}
		TEST_METHOD(TestMethod2, Line_Line)
		{
			Line ln1(-2, 2, 3, 2);	// parallel to y
			Line ln2(-2, -2, 3, -2);	// parallel to y
			Line ln3(0, 1, 0, 2);		// parallel to x
			Line ln4(3, 5, 3, -1);		// parallel to x
			Line ln5(1, 1, 2, 2);		// normal line
			Line ln6(-1, 0, 0, 1);		// normal, parallel to ln5
			Line ln7(-1, 4, 4, -1);		// normal

			/* is intersect test */
			Assert::AreEqual(false, ln1.isInterset(&ln2));
			Assert::AreEqual(true, ln1.isInterset(&ln3));
			Assert::AreEqual(true, ln1.isInterset(&ln5));
			Assert::AreEqual(true, ln3.isInterset(&ln1));
			Assert::AreEqual(false, ln3.isInterset(&ln4));
			Assert::AreEqual(true, ln3.isInterset(&ln5));
			Assert::AreEqual(true, ln5.isInterset(&ln1));
			Assert::AreEqual(false, ln5.isInterset(&ln6));
			Assert::AreEqual(true, ln5.isInterset(&ln7));
		}
		TEST_METHOD(TestMethod3, Line_Circle) {
			Circle cc(3, -4, 5);
			Line ln1(-2, 0, 0, 2);
			Line ln2(-2, 0, -2, 2);
			Line ln3(0, -2, 2, 0);

			Assert::AreEqual(cc.isInterset(&ln1), false);
			Assert::AreEqual(ln1.isInterset(&cc), false);

			Assert::AreEqual(cc.isInterset(&ln2), true);
			Assert::AreEqual(1, (int)cc.getInterPoint(&ln2).size());
			Assert::AreEqual(ln2.isInterset(&cc), true);
			Assert::AreEqual(1, (int)ln2.getInterPoint(&cc).size());

			Assert::AreEqual(cc.isInterset(&ln3), true);
			Assert::AreEqual(2, (int)cc.getInterPoint(&ln3).size());
			Assert::AreEqual(ln3.isInterset(&cc), true);
			Assert::AreEqual(2, (int)ln3.getInterPoint(&cc).size());
		}

		TEST_METHOD(TestMethod4, Circle_Circle) {
			Circle cc1(0, 0, 8);
			Circle cc2(0, 0, 4);
			Circle cc3(0, 10, 1);
			Circle cc4(0, 6, 2);
			Circle cc5(0, 9, 1);
			Circle cc6(0, 11, 5);

			Assert::AreEqual(cc1.isInterset(&cc2), false);
			Assert::AreEqual(cc1.isInterset(&cc3), false);

			Assert::AreEqual(cc1.isInterset(&cc4), true);
			Assert::AreEqual(1, (int)cc1.getInterPoint(&cc4).size());
			Assert::AreEqual(cc1.isInterset(&cc5), true);
			Assert::AreEqual(1, (int)cc1.getInterPoint(&cc5).size());

			Assert::AreEqual(cc1.isInterset(&cc6), true);
			Assert::AreEqual(2, (int)cc1.getInterPoint(&cc6).size());
		}
	};
}

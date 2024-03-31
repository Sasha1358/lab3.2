#include "pch.h"
#include "CppUnitTest.h"
#include "../lab3.2/Truck.h"
#include "../lab3.2/Truck.cpp"
#include "../lab3.2/Car.h"
#include "../lab3.2/Car.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest32
{
	TEST_CLASS(UnitTest32)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Truck truck("Brand", "Color", 3.5, 200, 0.0);
			truck.reassignCargoCapacity(1000); 
			Assert::AreEqual(1000.0, truck.getCargoCapacity());
		}
	};
}

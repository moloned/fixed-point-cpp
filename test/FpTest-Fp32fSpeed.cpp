//!
//! @file 		FpTest-Fp32fSpeed.cpp
//! @author 	Geoffrey Hunter <gbmhunter@gmail.com> (www.cladlab.com)
//! @edited 	n/a
//! @date 		2013/05/30
//! @brief 		Performs speed unit tests on the 32-bit fixed point maths.
//! @details
//!				See README.rst in root dir for more info.

// 32-bit fixed-point library
#include "../src/include/FixedPoint-Fp32f.hpp"

#include "./UnitTest++/src/UnitTest++.h"

using namespace Fp;

SUITE(Fp32fSpeedTests)
{
	TEST(AddSpeedTest)
	{
		Fp32f<8> fp1 = Fp32f<8>(5.6);
		Fp32f<8> fp2 = Fp32f<8>(8.9);
		Fp32f<8> fp3;
		
		{
			UNITTEST_TIME_CONSTRAINT(1000);
			
			int x = 0;
			for(x = 0; x < 10000000; x++)
			{
				fp3 = fp1 + fp2;
			}
		
		}
	}
	
	TEST(SubSpeedTest)
	{
		Fp32f<8> fp1 = Fp32f<8>(5.6);
		Fp32f<8> fp2 = Fp32f<8>(8.9);
		Fp32f<8> fp3;
		
		{
			UNITTEST_TIME_CONSTRAINT(2000);
			
			int x = 0;
			for(x = 0; x < 100000000; x++)
			{
				fp3 = fp1 - fp2;
			}
		
		}
	}

	TEST(MultSpeedTest)
	{
		Fp32f<8> fp1 = Fp32f<8>(5.6);
		Fp32f<8> fp2 = Fp32f<8>(5.6);
		Fp32f<8> fp3;

		{
			UNITTEST_TIME_CONSTRAINT(2000);
			
			int x = 0;
			for(x = 0; x < 10000000; x++)
			{
				fp3 = fp1*fp2;
			}
		
			}
	}
	
	TEST(DivSpeedTest)
	{
		Fp32f<8> fp1 = Fp32f<8>(21.6);
		Fp32f<8> fp2 = Fp32f<8>(5.6);
		Fp32f<8> fp3;

		{
			UNITTEST_TIME_CONSTRAINT(2000);
			
			int x = 0;
			for(x = 0; x < 10000000; x++)
			{
				fp3 = fp1/fp2;
			}
		
			}
	}
}
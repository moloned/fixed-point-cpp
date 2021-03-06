//!
//! @file 		FpTest-Fp32sTypeConversion.cpp
//! @author 	Geoffrey Hunter <gbmhunter@gmail.com> (www.cladlab.com)
//! @edited 	n/a
//! @date 		2013/05/30
//! @brief 		Performs type conversion unit tests on the slow 32-bit fixed point library (Fp32s).
//! @details
//!				See README.rst in root dir for more info.

// Slow 32-bit fixed-point library
#include "../src/include/FixedPoint-Fp32s.hpp"

#include "./UnitTest++/src/UnitTest++.h"

using namespace Fp;

SUITE(Fp32sTypeConversionTests)
{
	// Check double->fixed conversion first as the
	// rest of the tests depend on it
	TEST(PositiveDoubleToFixedConversionTest)
	{
		Fp32s fp1 = Fp32s(3.2, 8);

		// The closest fixed point number this can be represented
		// as is Math.Round(3.2*2^8) = 819 = 0b001100110011
		CHECK_EQUAL((int32_t)0b001100110011, fp1.rawVal);
	}

	TEST(NegativeDoubleToFixedConversionTest)
	{
		Fp32s fp1 = Fp32s(-3.2, 8);

		// The closest fixed point number this can be represented
		// as is Math.Round(-3.2*2^8) = -819 = 0b11111111111111111111110011001101 (32-bit 2's compliment)
		CHECK_EQUAL((int32_t)0b11111111111111111111110011001101, fp1.rawVal);
	}
	
	TEST(PosInt32CastTest)
	{
		Fp32s fp1 = Fp32s(5.6, 12);
		int32_t myInt32 = (int32_t)fp1;
		
		CHECK_EQUAL(5, myInt32);
	}
	
	TEST(NegInt32CastTest)
	{
		Fp32s fp1 = Fp32s(-22.3, 12);
		int32_t myInt32 = (int32_t)fp1;
		
		// Rounds down to nearest int
		CHECK_EQUAL(-23, myInt32);
	}

	TEST(PosFloatCastTest)
	{
		Fp32s fp1 = Fp32s(5.6, 12);
		float flo1 = (float)fp1;
		
		CHECK_CLOSE(5.6, flo1, 0.05);
	}
	
	TEST(NegFloatCastTest)
	{
		Fp32s fp1 = Fp32s(-2.2, 12);
		float flo1 = (float)fp1;
		
		CHECK_CLOSE(-2.2, flo1, 0.05);
	}
	
	TEST(PosDoubleCastTest)
	{
		Fp32s fp1 = Fp32s(5.6, 12);
		double dbl1 = (double)fp1;
		
		CHECK_CLOSE(5.6, dbl1, 0.05);
	}
	
	TEST(NegDoubleCastTest)
	{
		Fp32s fp1 = Fp32s(-25.6, 12);
		double dbl1 = (double)fp1;
		
		CHECK_CLOSE(-25.6, dbl1, 0.05);
	}

}
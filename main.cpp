#include <gtest/gtest.h>
#include "ratio.h"


class RatioFixture : public :: testing::Test{

protected:

    Ratio rat1 = {1, 2};
    Ratio rat2 = {-1, 3};
    Ratio rat3 = {2, 4};
    Ratio rat4 = {5, 6};
};

TEST_F(RatioFixture, expressions)
{
    EXPECT_EQ(true, rat1 == rat3);
    EXPECT_EQ(true, rat1++==Ratio(3, 2));
    EXPECT_EQ(true, Ratio(5, 6) == rat3 - rat2);
    Ratio reverse_rat4 = 1/rat4;
    rat4.reverse();
    EXPECT_EQ(true, rat4 == reverse_rat4);
    EXPECT_EQ(true, rat4 > Ratio(5, 6));
    EXPECT_EQ(true, Ratio(27, 10) == rat4 + rat1);
    EXPECT_EQ(true, Ratio(1, 4).to_ten() == 0.25);
    EXPECT_EQ(true, Ratio(1, 4) + Ratio(-1, -4) == Ratio(1, 2));
    EXPECT_EQ(true, Ratio(5, 6)/Ratio(4, 7) == Ratio(35, 24));
    EXPECT_EQ(true, Ratio(4, 7)*4 == Ratio(16, 7));
}

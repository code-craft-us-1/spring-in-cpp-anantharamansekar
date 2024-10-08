#include "stats.h"

#include "gtest/gtest.h"
#include <cmath>

TEST(Statistics, ReportsAverageMinMax) {
    auto computedStats = Statistics::ComputeStatistics({1.5, 8.9, 3.2, 4.5});
    double epsilon = 0.001;
    EXPECT_LT(std::abs(computedStats.average - 4.525), epsilon);
    EXPECT_LT(std::abs(computedStats.max - 8.9), epsilon);
    EXPECT_LT(std::abs(computedStats.min - 1.5), epsilon);
}

TEST(Statistics, AverageNaNForEmpty) {
    auto computedStats = Statistics::ComputeStatistics({NAN,5.0,6.0});
    computedStats;
    //All fields of computedStats (average, max, min) must be
    //NAN (not-a-number), as defined in math.h
     
    //Design the gtest EXPECT statement here.
    EXPECT_TRUE(isnan(computedStats.average));
    EXPECT_TRUE(isnan(computedStats.min));
    EXPECT_TRUE(isnan(computedStats.max));

    //Use http://www.cplusplus.com/reference/cmath/isnan/
}

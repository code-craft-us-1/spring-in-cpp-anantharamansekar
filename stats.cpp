#include "stats.h"
#include <numeric>
#include <algorithm>
//using namespace std;


using namespace Statistics;

Stats Statistics::ComputeStatistics(const std::vector<double>& elements) {
    //Implement statistics here
    Stats result;

    result.average = accumulate(elements.begin(), elements.end(), 0.0 )/ elements.size();
        result.min = *(std::min(elements.begin(), elements.end()));
        result.max = *(std::max_element(elements.begin(), elements.end()));

    return result; 
}

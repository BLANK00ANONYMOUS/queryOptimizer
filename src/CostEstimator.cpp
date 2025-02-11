#include "CostEstimator.h"

CostEstimator::CostEstimator(const std::unordered_map<std::string, int> &stats)
    : tableStats(stats) {}

JoinAlgorithm CostEstimator::estimateJoinCost(const std::string &tableA,
                                              const std::string &tableB) const
{
    int sizeA = tableStats.at(tableA);
    int sizeB = tableStats.at(tableB);

    // Simple cost model:
    if (sizeA > 10000 || sizeB > 10000)
        return HASH_JOIN;
    if (sizeA + sizeB < 5000)
        return NESTED_LOOP;
    return MERGE_JOIN;
}
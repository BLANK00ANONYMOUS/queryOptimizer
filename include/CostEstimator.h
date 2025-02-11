#ifndef COST_ESTIMATOR_H
#define COST_ESTIMATOR_H

#include <string>
#include <unordered_map>

enum JoinAlgorithm
{
    HASH_JOIN,
    MERGE_JOIN,
    NESTED_LOOP
};

class CostEstimator
{
private:
    std::unordered_map<std::string, int> tableStats; // Table sizes

public:
    CostEstimator(const std::unordered_map<std::string, int> &stats);
    JoinAlgorithm estimateJoinCost(const std::string &tableA,
                                   const std::string &tableB) const;
};

#endif
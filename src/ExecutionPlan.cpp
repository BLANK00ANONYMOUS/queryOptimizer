#include "ExecutionPlan.h"

ExecutionPlan::ExecutionPlan(const Query &q, const CostEstimator &e)
    : query(q), estimator(e) {}

std::vector<std::string> ExecutionPlan::generatePlan() const
{
    std::vector<std::string> steps;

    for (const auto &join : query.joins)
    {
        std::string tableA = join.substr(0, join.find('='));
        std::string tableB = join.substr(join.find('=') + 1);

        JoinAlgorithm algo = estimator.estimateJoinCost(tableA, tableB);

        switch (algo)
        {
        case HASH_JOIN:
            steps.push_back("HashJoin(" + tableA + ", " + tableB + ")");
            break;
        case MERGE_JOIN:
            steps.push_back("MergeJoin(" + tableA + ", " + tableB + ")");
            break;
        default:
            steps.push_back("NestedLoop(" + tableA + ", " + tableB + ")");
        }
    }

    steps.push_back("Filter(" + query.whereClause + ")");
    return steps;
}

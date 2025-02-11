#ifndef EXECUTION_PLAN_H
#define EXECUTION_PLAN_H

#include "QueryParser.h"
#include "CostEstimator.h"
#include <vector>

class ExecutionPlan
{
private:
    Query query;
    CostEstimator estimator;

public:
    ExecutionPlan(const Query &q, const CostEstimator &e);
    std::vector<std::string> generatePlan() const;
};

#endif

#include <iostream>
#include "ExecutionPlan.h"

int main()
{
    // Mock table statistics
    std::unordered_map<std::string, int> stats = {
        {"users", 100000},
        {"orders", 500000},
        {"products", 20000}};

    CostEstimator estimator(stats);
    Query query = QueryParser::parse(
        "SELECT * FROM users JOIN orders JOIN products WHERE users.age > 25");

    ExecutionPlan plan(query, estimator);
    auto steps = plan.generatePlan();

    std::cout << "Optimized Execution Plan:\n";
    for (const auto &step : steps)
    {
        std::cout << "  → " << step << "\n";
    }

    return 0;
}

#include "QueryParser.h"
#include <sstream>

Query QueryParser::parse(const std::string &sql)
{
    Query query;
    std::istringstream iss(sql);
    std::string token;

    while (iss >> token)
    {
        if (token == "FROM")
        {
            while (iss >> token && token != "WHERE" && token != "JOIN")
            {
                query.tables.push_back(token);
            }
        }
        if (token == "JOIN")
        {
            std::string joinCondition;
            iss >> joinCondition;
            query.joins.push_back(joinCondition);
        }
    }
    return query;
}

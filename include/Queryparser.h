#ifndef QUERY_PARSER_H
#define QUERY_PARSER_H

#include <string>
#include <vector>
#include <unordered_map>

struct Query
{
    std::vector<std::string> tables;
    std::vector<std::string> joins;
    std::string whereClause;
};

class QueryParser
{
public:
    static Query parse(const std::string &sql);
};

#endif
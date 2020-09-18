#include <string>
#include "Query.hpp"

int main()
{
    std::string s1 = "1", s2 = "2", s3 = "3", s4 = "4";
    auto q1 = Query(s1) | Query(s2) & ~Query(s3);
    auto q2 = Query(s1) | (Query(s2) & ~Query(s3));
    auto q3 = (Query(s1) & (Query(s2)) | (Query(s3) & Query(s4)));
    return 0;
}
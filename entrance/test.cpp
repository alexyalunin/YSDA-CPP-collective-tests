#include <catch.hpp>
#include <entrance.h>

TEST_CASE("Simple test") {

    std::vector<std::tuple<StudentName, Date, int, std::vector<std::string>>> sts = {
        {StudentName("", "bba"), Date(1, 0, 0), 8, {"itmo", "spbu"}},
        {StudentName("", "bbb"), Date(0, 0, 0), 8, {"itmo", "spbu"}},
        {StudentName("", "aa"), Date(0, 0, 0), 10, {"itmo"}},
        {StudentName("", "ab"), Date(0, 0, 0), 9, {"spbu"}},
    };

    std::vector<std::pair<std::string, int>> unis = {{"itmo", 1}, {"spbu", 2}, {"poly", 100}};

    auto res = GetStudents(unis, sts);
    REQUIRE(res["itmo"][0].surname == "aa");
    REQUIRE(res["spbu"][0].surname == "ab");
    REQUIRE(res["spbu"][1].surname == "bbb");
    REQUIRE(res.find("poly") != res.end());
    REQUIRE(res["poly"].empty());
}

#include <catch.hpp>
#include <sort_students.h>

#include <iostream>

TEST_CASE("By date test") {
    Student aa000("a", "a", 0, 0, 0),
        ab000("a", "b", 0, 0, 0),
        bb000("b", "b", 0, 0, 0),
        bb100("b", "b", 1, 0, 0),
        bb101("b", "b", 1, 0, 1),
        bb110("b", "b", 1, 1, 0);

    std::vector<Student> st{bb110, bb101, bb000, bb100, ab000, aa000};
    SortStudents(&st, SortType::kByDate);

    REQUIRE(st[0] == aa000);
    REQUIRE(st[1] == ab000);
    REQUIRE(st[2] == bb000);
    REQUIRE(st[3] == bb100);
    REQUIRE(st[4] == bb101);
    REQUIRE(st[5] == bb110);
}

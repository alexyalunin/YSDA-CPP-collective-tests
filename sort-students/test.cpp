#include <catch.hpp>
#include <sort_students.h>

#include <iostream>

bool operator==(const Student& lhs, const Student& rhs) {
    return lhs.name == rhs.name && lhs.surname == rhs.surname && lhs.year == rhs.year &&
           lhs.month == rhs.month && lhs.day == rhs.day;
}

std::ostream& operator<<(std::ostream& s, const Student& lhs) {
    s << "(" << lhs.name << "," << lhs.surname << "," << lhs.day << "," << lhs.month << ","
      << lhs.year << ")";
    return s;
}

Student MakeStudent(std::string_view name, std::string_view surname, int year, int month, int day) {
    Student result;
    result.name = name;
    result.surname = surname;
    result.year = year;
    result.month = month;
    result.day = day;
    return result;
}

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

TEST_CASE("by_date") {
    std::vector<Student> test;
    std::vector<Student> expected;
    test.push_back(MakeStudent("c", "b", 1999, 9, 19));
    test.push_back(MakeStudent("a", "b", 2000, 8, 12));
    test.push_back(MakeStudent("b", "a", 2000, 11, 12));
    test.push_back(MakeStudent("a", "c", 1998, 10, 10));
    test.push_back(MakeStudent("a", "b", 2000, 11, 12));

    expected.push_back(MakeStudent("a", "c", 1998, 10, 10));
    expected.push_back(MakeStudent("c", "b", 1999, 9, 19));
    expected.push_back(MakeStudent("a", "b", 2000, 8, 12));
    expected.push_back(MakeStudent("b", "a", 2000, 11, 12));
    expected.push_back(MakeStudent("a", "b", 2000, 11, 12));

    SortStudents(&test, SortType::kByDate);
    REQUIRE(expected == test);
}

TEST_CASE("by_name") {
    std::vector<Student> test;
    std::vector<Student> expected;
    test.push_back(MakeStudent("c", "b", 1999, 9, 19));
    test.push_back(MakeStudent("a", "b", 2000, 8, 12));
    test.push_back(MakeStudent("b", "a", 2000, 11, 12));
    test.push_back(MakeStudent("a", "c", 1998, 10, 10));
    test.push_back(MakeStudent("a", "b", 2000, 11, 12));

    expected.push_back(MakeStudent("b", "a", 2000, 11, 12));
    expected.push_back(MakeStudent("a", "b", 2000, 8, 12));
    expected.push_back(MakeStudent("a", "b", 2000, 11, 12));
    expected.push_back(MakeStudent("c", "b", 1999, 9, 19));
    expected.push_back(MakeStudent("a", "c", 1998, 10, 10));

    SortStudents(&test, SortType::kByName);
    REQUIRE(expected == test);
}

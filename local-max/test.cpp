#include <catch.hpp>
#include <util.h>
#include <strict_iterator.h>
#include <local_max.h>

TEST_CASE("Your test") {
    // ВАЖНО: (в условии)
    // Используйте только оператор < для сравнения элементов.

    std::vector<int> vec = {5,4,3,2,1};
    auto pointer = LocalMax(vec.begin(), vec.end());
    REQUIRE(*pointer == 5);

    vec = {};
    pointer = LocalMax(vec.begin(), vec.end());
    REQUIRE(pointer == vec.end());
    
    vec = {3,4,3,2,1};
    pointer = LocalMax(vec.begin(), vec.end());
    REQUIRE(*pointer == 4);

    vec = {3,3,3,2,1};
    pointer = LocalMax(vec.begin(), vec.end());
    REQUIRE(pointer == vec.end());

    vec = {1,2,3,4,5};
    pointer = LocalMax(vec.begin(), vec.end());
    REQUIRE(*pointer == 5);

    vec = {1};
    pointer = LocalMax(vec.begin(), vec.end());
    REQUIRE(*pointer == 1);

    vec = {1,1};
    pointer = LocalMax(vec.begin(), vec.end());
    REQUIRE(pointer == vec.end());

    vec = {1,2};
    pointer = LocalMax(vec.begin(), vec.end());
    REQUIRE(*pointer == 2);

    vec = {3,1};
    pointer = LocalMax(vec.begin(), vec.end());
    REQUIRE(*pointer == 3);

    vec = {1,2,1,3,1};
    pointer = LocalMax(vec.begin(), vec.end());
    REQUIRE(*pointer == 2);

    vec = {1,2,3,2,1};
    pointer = LocalMax(vec.begin(), vec.end());
    REQUIRE(*pointer == 3);

}

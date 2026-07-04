#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include "task.h"

TEST_CASE("Task creation") {
    Task t(1, "Test title", "Test description", false);

    REQUIRE(t.id == 1);
    REQUIRE(t.title == "Test title");
    REQUIRE(t.description == "Test description");
    REQUIRE(t.completed == false);
}

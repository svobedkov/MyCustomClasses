#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "headers.h"

TEST_CASE("stack working")
{
    stack<int> stack1;
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);
    CHECK(stack1.pop() == 3);
    CHECK(stack1.pop() == 2);
    CHECK(stack1.pop() == 1);
}

/*TEST_CASE("queue working")
{
    //smth
}

TEST_CASE("deque working")
{
    //smth
}*/
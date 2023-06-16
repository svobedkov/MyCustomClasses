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

TEST_CASE("queue working")
{
    queue<int> queue1;
    queue1.push(1);
    queue1.push(2);
    queue1.push(3);
    CHECK(queue1.pop() == 1);
    CHECK(queue1.pop() == 2);
    CHECK(queue1.pop() == 3);
}

TEST_CASE("deque working 1")
{
    deque<int> deque1;
    deque1.push_back(2);
    deque1.push_back(1);
    deque1.push_front(3);
    deque1.push_front(4);
    CHECK(deque1.pop_back() == 1);
    CHECK(deque1.pop_back() == 2);
    CHECK(deque1.pop_back() == 3);
    CHECK(deque1.pop_back() == 4);
}

TEST_CASE("deque working 2")
{
    deque<int> deque1;
    deque1.push_back(2);
    deque1.push_back(1);
    deque1.push_front(3);
    deque1.push_front(4);
    CHECK(deque1.pop_front() == 4);
    CHECK(deque1.pop_front() == 3);
    CHECK(deque1.pop_front() == 2);
    CHECK(deque1.pop_front() == 1);
}

TEST_CASE("Work with different types") {
    stack<char> stack1;
    stack<double> stack2;
    stack<bool> stack3;
    stack1.push('f');
    CHECK(stack1.pop() == 'f');
    stack2.push(1.5);
    CHECK(stack2.pop() == 1.5);
    stack3.push(false);
    CHECK(stack3.pop() == false);
}

TEST_CASE("Clear correct") {
    deque<int> deq;
    deq.push_front(1);
    deq.push_front(2);
    deq.clear();
    CHECK(deq.isEmpty);
}

TEST_CASE("Can use variables, with no loss") {
    queue<int> que;
    CHECK(que.isEmpty);
    que.push(13);
    CHECK(!que.isEmpty);
    que.check();
    CHECK(!que.isEmpty);
    que.pop();
    CHECK(que.isEmpty);
}

TEST_CASE("Can work with negative numbers") {
    stack<int> var;
    var.push(-255);
    CHECK(var.pop() == -255);
}

TEST_CASE("Deque can only push_front and pop_back") {
    deque<char> var;
    var.push_front('a');
    var.push_front('b');
    var.push_front('c');
    CHECK(var.pop_back() == 'a');
    CHECK(var.pop_back() == 'b');
    CHECK(var.pop_back() == 'c');
}
#include <stdio.h>
#include <stack>
#include <queue>

#include "timer.h"
#include "Stack.h"

const char UPPER_CASE_BIT = ~('A' & 'a');

char get_valid_char(char c)
{
    c |= UPPER_CASE_BIT;
    if('A' <= c && c <= 'Z') return c;
    return 0;
}

bool is_palindrome_stack(const char* text)
{
    Stack<char> stack;

    const char* c = text;
    while(*c != '\0')
    {
        char t = get_valid_char(*c);
        if(t) stack.push(t);
        c++;
    }

    c = text;
    while(*c != '\0')
    {
        char t = get_valid_char(*c);
        if(t)
        {
            if(stack.peek() != t)
                return false;
            stack.pop();
        }
        c++;
    }

    return true;
}

bool is_palindrome_queue(const char* text)
{
    std::queue<char> queue;
    std::stack<char> stack;

    const char* c = text;
    while(*c != '\0')
    {
        char t = get_valid_char(*c);
        if(t)
        {
            stack.push(t);
            queue.push(*c);
        }
        c++;
    }

    while(!stack.empty())
    {
        if(stack.top() == queue.front())
        {
            stack.pop();
            queue.pop();
        }
        else
            return false;
    }

    return true;
}

int main(int argc, char *argv[])
{
    TIME_FUNC_N(printf("%d\n", is_palindrome_stack("du har bra hud")), "stack");
    TIME_FUNC_N(printf("%d\n", is_palindrome_queue("du har bra hud")), "queue");
    return 0;
}

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <time.h>

#include "timer.h"
#include "Stack.h"
#include "Queue.h"

const char LOWER_CASE_BIT = 'A' ^ 'a';

char get_valid_char(char c)
{
    c |= LOWER_CASE_BIT;
    if('a' <= c && c <= 'z') return c;
    return 0;
}

std::string create_valid_string(std::string str)
{
    std::string ret;
    for (char c : str)
    {
        char t = get_valid_char(c);
        if(t)
            ret.push_back(t);
    }
    return ret;
}

bool is_palindrome_stack(std::string text)
{
    Stack<char> begining_half;
    Stack<char> end_half;

    Timer t("Stack only"); // Timer starts here

    for(int i = 0; i < text.size()/2; i++)
        begining_half.push(text[i]);

    for(int i = 0; i < text.size()/2; i++)
        end_half.push(text[text.size()-i-1]);


    while(begining_half.size() > 0)
    {
        if( begining_half.peek() != end_half.peek() )
        {
            t.stop();
            return false;
        }

        begining_half.pop();
        end_half.pop();
    }

    t.stop();

    return true;
}

bool is_palindrome_queue(std::string text)
{
    Queue<char> queue;
    Stack<char> stack;

    Timer t("Stack and Queue"); // Timer starts here

    int half_size = text.size()/2;

    for(int i = 0; i < half_size; i++)
        stack.push(text[i]);


    for(int i = 0; i < half_size; i++)
        queue.enqueue(text[text.size() - half_size + i]);


    while(queue.size() > 0)
    {
        if( stack.peek() != queue.peek() )
        {
            t.stop();
            return false;
        }

        stack.pop();
        queue.dequeue();
    }

    t.stop();

    return true;
}

int main(int argc, char *argv[])
{
    srand(time(NULL));
    int string_len = 100;
    int n_tests = 100000;

    for(int j = 0; j < n_tests; j++)
    {
        std::string str;

        { // Generete Test Word
            // Randomly choose if the test word is a palindrome
            if(rand()%4)
            {
                //
                // Word is palindrome
                //
                Stack<char> string_stack;
                for(int i = 0; i < string_len/2; i++)
                {
                    char c = 'A' + rand()%28;
                    str.push_back(c);
                    string_stack.push(c);
                }
                for(int i = 0; i < string_len/2; i++)
                {
                    str.push_back(string_stack.peek());
                    string_stack.pop();
                }
            }
            else
            {
                //
                // Word is not palindrome
                //
                for(int i = 0; i < string_len; i++)
                {
                    char c = 'A' + rand()%28;
                    str.push_back(c);
                }
            }

        } // end Generate Test Word

        //
        // Run test
        //
        std::cout << "Checking: " << str << std::endl;
        is_palindrome_stack(create_valid_string(str));
        is_palindrome_queue(create_valid_string(str));
    }

    return 0;
}

#include <iostream>

#include <asio.hpp>


void print_cpp_ver()
{
    std::cout<<"Cpp version: ";
#if __cplusplus == 199711L
    std::cout << "C++98\n";
#elif __cplusplus == 201103L
    std::cout << "C++11\n";
#elif __cplusplus == 201402L
    std::cout << "C++14\n";
#elif __cplusplus == 201703L
    std::cout << "C++17\n";
#elif __cplusplus == 202002L
    std::cout << "C++20\n";
#elif __cplusplus == 202302L
    std::cout << "C++23\n";
#else
    std::cout << "Unknown C++ version\n";
#endif
}

int main()
{

    //??/
    std::cout<<"V.I.E"<<std::endl;

    asio::io_context io;

    asio::steady_timer timer(io, std::chrono::seconds(2));

    timer.async_wait([](const asio::error_code& error)
    {
        if (!error)
        {
            std::cout << "Timer finished!\n";
        }
        else
        {
            std::cout << "Error: " << error.message() << "\n";
        }
    });

    std::cout << "Waiting...\n";

    io.run();

    std::cout << "Done\n";

    return 0;
}
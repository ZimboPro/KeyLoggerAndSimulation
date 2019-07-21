#include <iostream>
#include "../include/spdlog/spdlog.h"
#include "../include/spdlog/sinks/base_sink.h"

int main(int, char**) {
    try
    {
        /* code */
        auto my_logger = spdlog::basic_logger_mt("basic_logger", "logs/basic.txt");
        my_logger->debug("test");
        my_logger->info("test");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}
 
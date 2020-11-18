/**
 * @file 11.1.cpp
 * @brief Lecture 11.1 code
 * Demonstrates the boost chrono library in use with the boost program options library
 * @author William Kloppenberg
 * @assignment Lecture 11.1
 * @date 11/16/20
 * @credit Boost chrono usage: https://theboostcpplibraries.com/boost.chrono
 */

#define BOOST_CHRONO_VERSION 2
#include <boost/program_options.hpp>
#include <boost/chrono.hpp>
#include <boost/chrono/chrono_io.hpp>
#include <iostream>

using namespace boost::program_options;
using namespace boost::chrono;

int main(int argc, const char *argv[])
{
  try
  {
    options_description desc{"Options"};
    desc.add_options()
      ("help,h", "Help screen")
      ("systime", "Display the time in H:M:S format")
      ("stdytime", "Display the time since last boot in nanoseconds (steady clock)")
      ("teststring", value<std::string>()->default_value("Test string"), "Test of a string value");

    variables_map vm;
    store(parse_command_line(argc, argv, desc), vm);
    notify(vm);

    if (vm.count("help"))
    {
        std::cout << desc << '\n';
    }
    else if (vm.count("systime"))
    {
        std::cout << "Current time: " << time_fmt(boost::chrono::timezone::local, "%H:%M:%S") << system_clock::now() << '\n';
    }
    else if (vm.count("stdytime"))
    {
        std::cout << steady_clock::now() << '\n';
    }
    else if (vm.count("teststring"))
    {
        std::cout << vm["teststring"].as<std::string>() << '\n';
    }

  }
  catch (const error &ex)
  {
    std::cerr << ex.what() << '\n';
  }
}
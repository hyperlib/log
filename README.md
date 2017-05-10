Hyper Log
=========

C++11 logger

Example
-------

```cpp
#include <hyper/log>
#include <memory>

hyper::log::addLogger(std::unique_ptr<hyper::log::LoggerInterface>(new hyper::log::Syslog()));
hyper::log::addLogger(std::unique_ptr<hyper::log::LoggerInterface>(new hyper::log::Stream()));

hyper::log::info("hello %s", "HyperLog");

```

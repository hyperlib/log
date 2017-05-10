/**
 * Hyper
 *
 * (c) 2017 Axel Etcheverry
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#include <hyper/log>

namespace hyper {

std::vector<std::unique_ptr<log::LoggerInterface>> Log::loggers;

void Log::addWriter(std::unique_ptr<log::LoggerInterface> logger_) {
    loggers.push_back(std::move(logger_));
}

void Log::log(LevelType level_, const std::string message_, va_list list_) {
    for (auto const& logger : loggers) {
        if (level_ >= logger->getLevel()) {
            logger->log(level_, message_, list_);
        }
    }
}

void Log::emergency(const std::string message_, ...) {
    va_list list;
    va_start(list, message_);
    log(LEVEL_EMERGENCY, message_, list);
    va_end(list);
}

void Log::alert(const std::string message_, ...) {
    va_list list;
    va_start(list, message_);
    log(LEVEL_ALERT, message_, list);
    va_end(list);
}

void Log::critical(const std::string message_, ...) {
    va_list list;
    va_start(list, message_);
    log(LEVEL_CRITICAL, message_, list);
    va_end(list);
}

void Log::error(const std::string message_, ...) {
    va_list list;
    va_start(list, message_);
    log(LEVEL_ERROR, message_, list);
    va_end(list);
}

void Log::warning(const std::string message_, ...) {
    va_list list;
    va_start(list, message_);
    log(LEVEL_WARNING, message_, list);
    va_end(list);
}

void Log::notice(const std::string message_, ...) {
    va_list list;
    va_start(list, message_);
    log(LEVEL_NOTICE, message_, list);
    va_end(list);
}

void Log::info(const std::string message_, ...) {
    va_list list;
    va_start(list, message_);
    log(LEVEL_INFO, message_, list);
    va_end(list);
}

void Log::debug(const std::string message_, ...) {
    va_list list;
    va_start(list, message_);
    log(LEVEL_DEBUG, message_, list);
    va_end(list);
}

void Log::log(LevelType level_, const std::string message_, ...) {
    va_list list;
    va_start(list, message_);
    log(level_, message_, list);
    va_end(list);
}
}

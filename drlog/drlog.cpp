#include <ctime>
#include <iostream>

#include "drlog.h"

using namespace std;

// logger::logger() { this->format = "[{TYPE}]: {MESSAGE}"; }

drlog::logger::logger(std::string format) {
    this->format = format;

    this->info_style = "\033[37mInfo\033[0m";

    this->note_style = "\033[32mNote\033[0m";
    this->warn_style = "\033[33mWarn\033[0m";
    this->error_style = "\033[31mError\033[0m";

    this->log_style = "\033[34mLog\033[0m";
    this->debug_style = "\033[35mDebug\033[0m";
}

static void replace_word(std::string& str, std::string from, std::string to) {
    size_t start_pos = str.find(from);
    if (start_pos == std::string::npos)
        return;
    str.replace(start_pos, from.length(), to);
}

std::string drlog::logger::replace(std::string type, std::string msg) {
    string format_bak = this->format;

    // If the type is found, replace it.
    replace_word(format_bak, string("{TYPE}"), type);

    // If the message is found, replace it.
    replace_word(format_bak, string("{MESSAGE}"), msg);

    // Get the current time.
    std::time_t currentTime = std::time(nullptr);
    std::tm* localTime = std::localtime(&currentTime);
    replace_word(format_bak, string("{YEAR}"),
                 to_string(localTime->tm_year + 1900));
    replace_word(format_bak, string("{MONTH}"),
                 to_string(localTime->tm_mon + 1));
    replace_word(format_bak, string("{DAY}"), to_string(localTime->tm_mday));
    replace_word(format_bak, string("{HOUR}"), to_string(localTime->tm_hour));
    replace_word(format_bak, string("{MINUTE}"), to_string(localTime->tm_min));
    replace_word(format_bak, string("{SECOND}"), to_string(localTime->tm_sec));

    replace_word(format_bak, string("{TIME}"),
                 to_string(localTime->tm_year + 1900) + "/" +
                     to_string(localTime->tm_mon + 1) + "/" +
                     to_string(localTime->tm_mday) + " " +
                     to_string(localTime->tm_hour) + ":" +
                     to_string(localTime->tm_min) + ":" +
                     to_string(localTime->tm_sec));

    return format_bak;
}

void drlog::logger::set_info_style(std::string style) {
    this->info_style = style;
}

void drlog::logger::info(std::string msg) {
    cout << this->replace(this->info_style, msg) << endl;
}

void drlog::logger::set_note_style(std::string style) {
    this->note_style = style;
}

void drlog::logger::note(std::string msg) {
    cout << this->replace(this->note_style, msg) << endl;
}

void drlog::logger::set_warn_style(std::string style) {
    this->warn_style = style;
}

void drlog::logger::warn(std::string msg) {
    cout << this->replace(this->warn_style, msg) << endl;
}

void drlog::logger::set_error_style(std::string style) {
    this->error_style = style;
}

void drlog::logger::error(std::string msg) {
    cout << this->replace(this->error_style, msg) << endl;
}

void drlog::logger::set_log_style(std::string style) {
    this->log_style = style;
}

void drlog::logger::log(std::string msg) {
    cout << this->replace(this->log_style, msg) << endl;
}

void drlog::logger::set_debug_style(std::string style) {
    this->debug_style = style;
}

void drlog::logger::debug(std::string msg) {
    cout << this->replace(this->debug_style, msg) << endl;
}

void drlog::logger::set_format(std::string format) { this->format = format; }

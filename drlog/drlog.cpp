#include <ctime>
#include <iostream>

#include "drlog.h"

using namespace std;

drlog::msg_info::msg_info(std::string type, std::string msg) {
    this->type = type;
    this->msg = msg;
    this->file = "";
    this->line = "";
    this->function = "";
    this->pretty_function = "";
};

drlog::msg_info::msg_info(std::string file, std::string line,
                          std::string function, std::string pretty_function) {
    this->file = file;
    this->line = line;
    this->function = function;
    this->pretty_function = pretty_function;
};

drlog::logger::logger() {
    this->format = "{TIME} [{TYPE}]: {MESSAGE}";

    this->info_style = "\033[37mInfo\033[0m";

    this->note_style = "\033[32mNote\033[0m";
    this->warn_style = "\033[33mWarn\033[0m";
    this->error_style = "\033[31mError\033[0m";

    this->log_style = "\033[34mLog\033[0m";
    this->debug_style = "\033[35mDebug\033[0m";
}

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

std::string drlog::logger::replace(drlog::msg_info info) {
    string format_bak = this->format;

    // If the type is found, replace it.
    replace_word(format_bak, string("{TYPE}"), info.type);

    // If the message is found, replace it.
    replace_word(format_bak, string("{MESSAGE}"), info.msg);

    replace_word(format_bak, string("{FILE}"), info.file);
    replace_word(format_bak, string("{LINE}"), info.line);
    replace_word(format_bak, string("{FUNCTION}"), info.function);
    replace_word(format_bak, string("{PRETTY_FUNCTION}"), info.pretty_function);

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
    drlog::msg_info info = drlog::msg_info(this->info_style, msg);
    cout << this->replace(info) << endl;
}

void drlog::logger::info(std::string msg, drlog::msg_info info) {
    info.type = this->info_style;
    info.msg = msg;
    cout << this->replace(info) << endl;
}

void drlog::logger::set_note_style(std::string style) {
    this->note_style = style;
}

void drlog::logger::note(std::string msg) {
    drlog::msg_info info = drlog::msg_info(this->note_style, msg);
    cout << this->replace(info) << endl;
}

void drlog::logger::note(std::string msg, drlog::msg_info info) {
    info.type = this->note_style;
    info.msg = msg;
    cout << this->replace(info) << endl;
}

void drlog::logger::set_warn_style(std::string style) {
    this->warn_style = style;
}

void drlog::logger::warn(std::string msg) {
    drlog::msg_info info = drlog::msg_info(this->warn_style, msg);
    cout << this->replace(info) << endl;
}

void drlog::logger::warn(std::string msg, drlog::msg_info info) {
    info.type = this->warn_style;
    info.msg = msg;
    cout << this->replace(info) << endl;
}

void drlog::logger::set_error_style(std::string style) {
    this->error_style = style;
}

void drlog::logger::error(std::string msg) {
    drlog::msg_info info = drlog::msg_info(this->error_style, msg);
    cout << this->replace(info) << endl;
}

void drlog::logger::error(std::string msg, drlog::msg_info info) {
    info.type = this->error_style;
    info.msg = msg;
    cout << this->replace(info) << endl;
}

void drlog::logger::set_log_style(std::string style) {
    this->log_style = style;
}

void drlog::logger::log(std::string msg) {
    drlog::msg_info info = drlog::msg_info(this->log_style, msg);
    cout << this->replace(info) << endl;
}

void drlog::logger::log(std::string msg, drlog::msg_info info) {
    info.type = this->log_style;
    info.msg = msg;
    cout << this->replace(info) << endl;
}

void drlog::logger::set_debug_style(std::string style) {
    this->debug_style = style;
}

void drlog::logger::debug(std::string msg) {
    drlog::msg_info info = drlog::msg_info(this->debug_style, msg);
    cout << this->replace(info) << endl;
}

void drlog::logger::debug(std::string msg, drlog::msg_info info) {
    info.type = this->debug_style;
    info.msg = msg;
    cout << this->replace(info) << endl;
}

void drlog::logger::set_format(std::string format) { this->format = format; }

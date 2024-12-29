#include <iostream>

#include "drlog.h"

using namespace std;
using namespace drlog;

// logger::logger() { this->format = "[{TYPE}]: {MESSAGE}"; }

logger::logger(std::string format) {
    this->format = format;

    this->info_style = "INFO";

    this->note_style = "Note";
    this->warn_style = "\033[33mWarn\033[0m";
    this->error_style = "Error";

    this->log_style = "Log";
    this->debug_style = "Debug";
}

std::string drlog::logger::replace(std::string type, std::string msg) {
    int pos = 0;
    string format_bak = this->format;

    // If the type is found, replace it.
    if ((pos = format_bak.find("{TYPE}")) != std::string::npos)
        format_bak.replace(pos, string("{TYPE}").length(), type);

    // If the message is found, replace it.
    if ((pos = format_bak.find("{MESSAGE}")) != std::string::npos)
        format_bak.replace(pos, string("{MESSAGE}").length(), msg);

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

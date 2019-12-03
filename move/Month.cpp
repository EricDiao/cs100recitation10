//
// Created by llk89 on 2019/12/4.
// Copyright (c) 2019 llk89 All rights reserved.
//
#include "Month.hpp"
#include <utility>
#include <iostream>
#include <atomic>

static const char *month_names[]{
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
};

std::vector<Month> listOfMonths() {
    std::vector<Month> months;
    const size_t months_count = sizeof(month_names) / sizeof(*month_names);
    months.reserve(months_count);
    for (int i = 0; i < months_count; ++i) {
        months.emplace_back(i, std::string(month_names[i]));
    }
    return months;
}

std::atomic<size_t> month_id;

size_t getObjectID() {
    return month_id.fetch_add(1, std::memory_order_acq_rel);
}

Month::Month(int index, std::string name)
        : index(index), name(std::move(name)), object_id(getObjectID()) {
    log_event("construct");
}

Month::Month(const Month &month)
        : index(month.index), name(month.name), object_id(getObjectID()) {
    log_event("copy");
}

Month::Month(Month &&month) noexcept
        : index(month.index), name(std::move(month.name)), object_id(month.object_id) {
    log_event("move");
}

Month::~Month() {
    log_event("destruct");
}

void Month::log_event(const char *event_name) {
    std::cout << event_name << ' ' << object_id << ' ' << index << ' ' << name << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Month &month) {
    os << "Month(index=" << month.index << ", name=" << month.name << ", id=" << month.object_id << ')';
    return os;
}

Month &Month::operator=(Month &&other) noexcept {
    index = other.index;
    name = std::move(other.name);
    object_id = other.object_id;
    return *this;
}


bool Month::operator==(const Month &rhs) const {
    return index == rhs.index;
}

bool Month::operator!=(const Month &rhs) const {
    return !(rhs == *this);
}

bool Month::operator<(const Month &rhs) const {
    return index < rhs.index;
}

bool Month::operator>(const Month &rhs) const {
    return rhs < *this;
}

bool Month::operator<=(const Month &rhs) const {
    return !(rhs < *this);
}

bool Month::operator>=(const Month &rhs) const {
    return !(*this < rhs);
}

int Month::getIndex() const {
    return index;
}

const std::string &Month::getName() const {
    return name;
}
//
// Created by llk89 on 2019/12/4.
// Copyright (c) 2019 llk89 All rights reserved.
//

#ifndef RECITATION10_MONTH_HPP
#define RECITATION10_MONTH_HPP

#include <string>
#include <ostream>
#include <vector>

class Month {
public:
    Month(int index, std::string name);

    Month(const Month &month);

    Month(Month &&month) noexcept;

    virtual ~Month();

    int getIndex() const;

    const std::string &getName() const;

    friend std::ostream &operator<<(std::ostream &os, const Month &month);

    Month &operator=(Month &&other) noexcept ;

    bool operator==(const Month &rhs) const;

    bool operator!=(const Month &rhs) const;

    bool operator<(const Month &rhs) const;

    bool operator>(const Month &rhs) const;

    bool operator<=(const Month &rhs) const;

    bool operator>=(const Month &rhs) const;

private:
    void log_event(const char *event_name);

    int index;
    std::string name;
    size_t object_id;
};

std::vector<Month> listOfMonths();

#endif //RECITATION10_MONTH_HPP

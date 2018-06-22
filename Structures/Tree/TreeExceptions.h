#pragma once

#include <exception>

class FindNodeNotInTree : public std::exception{
public:
    const char *what() const noexcept override {
        return "You tried to find a node that's not in the Tree!";
    }
};

class RemoveNodeEmptyTree : public std::exception{
public:
    const char *what() const noexcept override {
        return "You tried to remove a node from an empty tree!";
    }
};

class RemoveNodeNotInTree : public std::exception{
public:
    const char *what() const noexcept override {
        return "You tried to remove a node not in the Tree!";
    }
};
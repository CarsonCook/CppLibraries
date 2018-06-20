#pragma once

#include <exception>

class NoValueFoundListException : public std::exception {
public:
    const char *what() const noexcept override {
        return "Tried to find a value that isn't in the list!";
    }
};

class InsertNodeAfterNodeNotInList : public std::exception {
public:
    const char *what() const noexcept override {
        return "Tried to insert a Node before a Node not in the list!";
    }
};

class RemoveNodeNotInList : public std::exception {
public:
    const char *what() const noexcept override {
        return "Tried to remove a Node that's not in the list!";
    }
};

class RemoveNodeEmptyList : public RemoveNodeNotInList {
public:
    const char *what() const noexcept override {
        return "Tried to remove a Node that's not in the list!";
    }
};

class RemoveNodeAfterLast : public RemoveNodeNotInList {
public:
    const char *what() const noexcept override {
        return "Tried to remove a Node after the last node in the list!";
    }
};
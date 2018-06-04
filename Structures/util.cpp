namespace util {
    inline bool isSamePointer(const void *v1, const void *v2) {
        return v1 == v2;
    }

    inline bool isNullPointer(const void *v1) {
        return v1 == nullptr;
    }
}
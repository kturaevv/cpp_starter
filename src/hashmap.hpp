#pragma once

#include <algorithm>
#include <iostream>
#include <list>
#include <ranges>
#include <stdexcept>
#include <vector>

template <typename KeyType, typename ValueType, typename Hash = std::hash<KeyType>>
class HashMap {
private:
    struct Entry {
        KeyType key;
        ValueType value;
    };
    using Bucket = std::list<Entry>;

    std::vector<Bucket> _buckets;
    Hash _hashFunction;
    size_t _size;

private:
    // Private constructor
    HashMap(size_t bucketCount) : _buckets(bucketCount), _size(0) {
        if (bucketCount == 0) {
            throw std::invalid_argument("Bucket count must be greater than 0");
        }
    }

    size_t _hash(const KeyType& key) const {
        return _hashFunction(key) % _buckets.size();
    }

public:
    // Static init function for object creation
    static HashMap init(size_t bucketCount = 1) {
        return HashMap(bucketCount);
    }

    void insert(const KeyType& key, const ValueType& value) {
        size_t index = _hash(key);
        auto& bucket = _buckets[index];

        auto found = std::ranges::find_if(bucket, [&](const Entry& entry) { return entry.key == key; });

        if (found != bucket.end()) {
            found->value = value; // Update the value if key already exists
        } else {
            bucket.push_back({key, value});
            ++_size;
        }
    }

    bool contains(const KeyType& key) const {
        size_t index = _hash(key);
        const auto& bucket = _buckets[index];

        return std::ranges::any_of(bucket, [&](const Entry& entry) { return entry.key == key; });
    }

    const ValueType& get(const KeyType& key) const {
        size_t index = _hash(key);
        const auto& bucket = _buckets[index];

        auto found = std::ranges::find_if(bucket, [&](const Entry& entry) { return entry.key == key; });

        if (found != bucket.end()) {
            return found->value;
        }
        throw std::out_of_range("Key not found in HashMap");
    }

    void remove(const KeyType& key) {
        size_t index = _hash(key);
        auto& bucket = _buckets[index];

        auto found = std::ranges::find_if(bucket, [&](const Entry& entry) { return entry.key == key; });

        if (found != bucket.end()) {
            bucket.erase(found);
            --_size;
        }
    }

    size_t getSize() const { return _size; }

    size_t getBucketCount() const { return _buckets.size(); }

    void read() const {
        std::cout << "All key-value pairs in the HashMap:" << std::endl;
        for (const auto& bucket : _buckets) {
            for (const auto& entry : bucket) {
                std::cout << "Key: " << entry.key << ", Value: " << entry.value << std::endl;
            }
        }
    }
};

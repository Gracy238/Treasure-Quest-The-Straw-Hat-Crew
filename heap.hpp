#ifndef HEAP_HPP
#define HEAP_HPP

#include <vector>
#include <functional>
#include <algorithm>

template <typename T>
class Heap {
private:
    std::vector<T> arr;
    std::function<bool(const T&, const T&)> comparison_function;

    void heapify(int i, int size) {
        if (size <= 1) return;
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && comparison_function(arr[left], arr[largest])) {
            largest = left;
        }
        if (right < size && comparison_function(arr[right], arr[largest])) {
            largest = right;
        }
        if (largest != i) {
            std::swap(arr[i], arr[largest]);
            heapify(largest, size);
        }
    }

public:
    Heap(std::function<bool(const T&, const T&)> comp, const std::vector<T>& init_array)
        : comparison_function(comp), arr(init_array) {
        int n = arr.size();
        for (int i = (n - 1) / 2; i >= 0; --i) {
            heapify(i, n);
        }
    }

    void insert(const T& value) {
        arr.push_back(value);
        int index = arr.size() - 1;
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (comparison_function(arr[index], arr[parent])) {
                std::swap(arr[index], arr[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }

    T extract() {
        if (arr.empty()) {
            throw std::runtime_error("Heap is empty");
        }
        T result = arr[0];
        arr[0] = arr.back();
        arr.pop_back();
        if (!arr.empty()) {
            heapify(0, arr.size());
        }
        return result;
    }

    T top() const {
        if (arr.empty()) {
            throw std::runtime_error("Heap is empty");
        }
        return arr[0];
    }

    bool empty() const {
        return arr.empty();
    }

    const std::vector<T>& get_arr() const {
        return arr;
    }
};

#endif
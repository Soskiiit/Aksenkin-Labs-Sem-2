#pragma once

#include <algorithm>
#include <ostream>
#include <stdexcept>


namespace vector {
    template <typename T>
    class Vector {
    protected:
        T* data;
        size_t size;
        size_t capacity;
    public:
        Vector() {
            size = 0;
            capacity = 1;
            data = new T[capacity];
        }

        virtual ~Vector() {
            delete[] data;
        }

        Vector(const Vector& other) {
            size = other.size;
            capacity = other.capacity;
            data = new T[capacity];
            std::copy_n(other.data, size, data);
        }

        void resize(size_t new_capacity) {
            T* new_data = new T[new_capacity];
            std::copy_n(data, size, new_data);
            delete[] data;
            data = new_data;
            capacity = new_capacity;
        }

        void push_back(const T& value) {
            if (size == capacity) {
                capacity *= 2;
                resize(capacity);
            }
            data[size++] = value;
        }

        virtual void delete_element(size_t index) {
            if (index >= size) {
                throw std::out_of_range("Index is out of range");
            }
            for (size_t i = index; i < size; i++)
                data[i] = data[i + 1];
            size--;
            if (size < capacity / 4) {
                capacity /= 2;
                resize(capacity);
            }
        }

        virtual long find_element(const T& value) const {
            for (size_t i = 0; i < size; i++)
                if (data[i] == value)
                    return i;
            return -1;
        }

        T operator[](size_t index) const {
            if (index >= size) {
                throw std::out_of_range("Index is out of range");
            }
            return data[index];
        }

        Vector& operator=(const Vector& other) {
            if (this != &other) {
                delete[] data;
                size = other.size;
                capacity = other.capacity;
                data = new T[capacity];
                std::copy_n(other.data, size, data);
            }
            return *this;
        }

        friend std::ostream& operator<<(std::ostream& os, const Vector& vector) {
            for (size_t i = 0; i < vector.size; i++)
                os << vector.data[i] << " ";
            return os;
        }
    };
}

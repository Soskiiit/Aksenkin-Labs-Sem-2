#pragma once

#include <iostream>

#include "vector.h"


namespace set {
    template <typename T>
    class Set: vector::Vector<T> {
    public:
        void insert_at_pos(size_t pos, const T& value) {
            if (this->size >= this->capacity)
                vector::Vector<T>::resize(this->capacity * 2);
            for (size_t i = this->size; i > pos; i--) {
                this->data[i] = this->data[i - 1];
            }
            this->data[pos] = value;
        }

        void add_element(T element) {
            int l = 0;
            int r = this->size;
            while (l < r) {
                int m = l + (r - l) / 2;
                if (element <= this->data[m]) {
                    r = m;
                } else {
                    l = m + 1;
                }
            }
            if (element != this->data[r]) {
                insert_at_pos(l, element);
                this->size++;
            }
        }

        void print() {
            for (size_t i = 0; i < this->size; i++) {
                std::cout << this->data[i] << " ";
            }
            std::cout << std::endl;
        }

        void delete_at_pos(size_t pos) {
            if (pos >= this->size) {
                throw std::out_of_range("out of range");
            }
            for (size_t i = pos; i < this->size; i++) {
                this->data[i] = this->data[i + 1];
            }
            this->size--;
        }

        int index_of(T element) {
            int l = 0;
            int r = this->size;
            while (l < r) {
                int m = l + (r - l) / 2;
                if (element <= this->data[m]) {
                    r = m;
                }
                else {
                    l = m + 1;
                }
            }
            if (element == this->data[r]) {
                return r;
            }
            return -1;
        }

        void remove_element(T element) {
            int index = index_of(element);
            if (index != -1)
                delete_at_pos(index);
        }

        bool contains(T element) {
            if (index_of(element) == -1)
                return false;
            return true;
        }

        Set operator+=(T element) {
            add_element(element);
            return *this;
        }

        Set operator-=(T element) {
            remove_element(element);
            return *this;
        }

        Set operator+=(Set& other) {
            for (size_t i = 0; i < other.size; i++) {
                this->add_element(other.data[i]);
            }
            return *this;
        }

        Set operator-=(Set& other) {
            for (size_t i = 0; i < other.size; i++) {
                this->remove_element(other.data[i]);
            }
            return *this;
        }

        Set operator*=(Set& other) {
            for (size_t i = 0; i < this->size; i++) {
                if (!other.contains(this->data[i])) {
                    this->delete_at_pos(i);
                    i--;
                }
            }
            return *this;
        }

        friend Set operator+(Set& a, Set& b) {
            Set result = a;
            for (size_t i = 0; i < b.size; i++) {
                result.add_element(b.data[i]);
            }
            return result;
        }

        friend Set operator-(Set& a, Set& b) {
            Set result = a;
            for (size_t i = 0; i < b.size; i++) {
                result.remove(b.data[i]);
            }
            return result;
        }

        friend Set operator*(Set& a, Set& b) {
            Set result = a;
            for (size_t i = 0; i < a.size; i++)
                if (!b.contains(a.data[i]))
                    result.remove(a.data[i]);
            return result;
        }

        friend bool operator==(Set& a, Set& b) {
            if (a.size != b.size)
                return false;
            for (size_t i = 0; i < a.size; i++)
                if (a.data[i] != b.data[i])
                    return false;
            return true;
        }

        friend std::ostream& operator<<(std::ostream& os, const Set& vector) {
            for (size_t i = 0; i < vector.size; i++)
                os << vector.data[i] << " ";
            return os;
        }
    };
}

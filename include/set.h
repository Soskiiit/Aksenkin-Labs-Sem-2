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
            insert_at_pos(l, element);
            this->size++;
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

        bool contains(T element) {
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
                return true;
            }
            return false;
        }
    };
}

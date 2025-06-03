#ifndef LAB8_TASKS_H
#define LAB8_TASKS_H

#include <string>
#include <vector>
#include <map>
#include <list>
#include <fstream>

void task1_count_sentences();
int count_sentences_in_text(const std::string& text);

void task2_filter_characters();
std::string filter_punctuation(const std::string& input);

void task3_file_processing();
std::string to_uppercase_latin(const std::string& line);

void task4_vector_operations();
void print_vector(const std::vector<float>& vec, const std::string& title = "");

void task5_point_vector();

void task6_list_operations();
void print_list(const std::list<int>& lst, const std::string& title = "");

void task7_planet_list();

void task8_char_int_map();
void print_char_int_map(const std::map<char, int>& char_map);

void task9_states_map();
void print_states_map(const std::map<std::string, int>& states_map);
class Point {
public:
    double x, y;
    Point() : x(0), y(0) {}
    Point(double a, double b) : x(a), y(b) {}
    double distance_from_origin() const;
    void shift_left(double offset);
    bool operator<(const Point& other) const;
    bool operator==(const Point& other) const;
};

class Planet {
public:
    std::string name;
    int satellites;
    Planet() : name(""), satellites(0) {}
    Planet(const std::string& n, int s) : name(n), satellites(s) {}
    bool operator<(const Planet& other) const;
    bool operator==(const Planet& other) const;
};

std::ostream& operator<<(std::ostream& os, const Point& p);
std::ostream& operator<<(std::ostream& os, const Planet& p);

#endif

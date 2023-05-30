//
// Created by hassa on 21.11.2022.
//

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

using namespace std;

/**
 * Task 1
 */

int times_two(int value) {
    return value * 2;
}

double times_two(double value) {
    return value * 2.0;
}

string times_two(const string &str) {
    return str + str;
}

vector<int> times_two(const vector<int> &vec) {
    vector<int> result;
    result.reserve(vec.size());
    for (auto e : vec)
        result.emplace_back(e * 2);
    return result;
}

ostream &operator<<(ostream &stream, const vector<int> &vec) {
    stream << "{ ";
    for (size_t i = 0; i < vec.size(); ++i) {
        if (i != 0)
            stream << ", ";
        stream << vec[i];
    }
    return stream << " }";
}

/**
 * Task 2
 */

class Build {
public:
    virtual ~Build() {}
    virtual string build() = 0;
};

class CMake : public Build {
public:
    string build() override {
        return "cmake --build .";
    }
};

class Meson : public Build {
public:
    string build() override {
        return "meson compile -C .";
    }
};

class Cargo : public Build {
public:
    string build() override {
        return "cargo build";
    }
};

class ProgrammingLanguage {
    unique_ptr<Build> _build;

public:
    ProgrammingLanguage() {}
    ProgrammingLanguage(unique_ptr<Build> build) : _build(std::move(build)) {}

    virtual ~ProgrammingLanguage() {}
    virtual string print_line(const string &str) = 0;
    virtual string for_each(const string &e, const string &vec) = 0;

    string build() {
        return _build->build();
    }
};

class Cpp : public ProgrammingLanguage {
public:
    Cpp() {}
    Cpp(unique_ptr<Build> build) : ProgrammingLanguage(std::move(build)) {}

    string print_line(const string &str) override {
        return "cout << \"" + str + "\" << endl;";
    }

    string for_each(const string &e, const string &vec) override {
        return "for(auto &" + e + ": " + vec + ") {}";
    }
};

class Rust : public ProgrammingLanguage {
public:
    Rust() {}
    Rust(unique_ptr<Build> build) : ProgrammingLanguage(std::move(build)) {}

    string print_line(const string &str) override {
        return "println!(\"" + str + "\");";
    }

    string for_each(const string &e, const string &vec) override {
        return "for " + e + " in &" + vec + " {}";
    }
};

/**
 * Task 3
 */

template <typename T>
class Angle {
public:
    T value;

    Angle(int value_) : value(value_ % 360) {
    }

    Angle(double value_) : value(fmod(value_, 3.14159265359)) {}

    template <typename T2>
    friend Angle<T> operator+(const Angle<T> &angle, T2 value_) {
        return Angle<T>(angle.value + static_cast<T>(value_));
    }

    friend std::ostream &operator<<(std::ostream &os, const Angle<T> &angle) {
        return os << angle.value;
    }
};

/**
 * Task 4
 */

vector<int> parallell_transform(const vector<int> &a, const vector<int> &b, const std::function<int(int, int)> &callback) {
    vector<int> result(a.size());
    std::vector<thread> threads;
    auto thread_size = thread::hardware_concurrency();
    threads.reserve(thread_size);
    for (size_t thread_num = 0; thread_num < thread_size; ++thread_num) {
        threads.emplace_back([thread_num, thread_size, &result, &a, &b, &callback] {
            for (size_t i = thread_num; i < a.size(); i += thread_size)
                result[i] = callback(a[i], b[i]);
        });
    }
    for (auto &thread : threads)
        thread.join();
    return result;
}

int main() {
    cout << "Task 1"
         << endl
         << endl;

    cout << times_two(2) << endl;
    cout << times_two(2.25) << endl;
    cout << times_two("test") << endl;
    cout << times_two(vector<int>{1, 2, 3}) << endl;

    cout << endl
         << "Task 2a"
         << endl
         << endl;

    {
        vector<unique_ptr<ProgrammingLanguage>> programming_languages;
        // Uncommenting the following line should cause compilation error:
        // programming_languages.emplace_back(make_unique<ProgrammingLanguage>());
        programming_languages.emplace_back(make_unique<Cpp>());
        programming_languages.emplace_back(make_unique<Rust>());

        for (auto &programming_language : programming_languages) {
            cout << programming_language->print_line("Hello World") << endl;
            cout << programming_language->for_each("e", "vec") << endl
                 << endl;
        }
    }

    cout << endl
         << "Task 2b"
         << endl
         << endl;

    {
        vector<unique_ptr<ProgrammingLanguage>> programming_languages;
        programming_languages.emplace_back(make_unique<Cpp>(make_unique<CMake>()));
        programming_languages.emplace_back(make_unique<Cpp>(make_unique<Meson>()));
        programming_languages.emplace_back(make_unique<Rust>(make_unique<Cargo>()));

        for (auto &programming_language : programming_languages) {
            cout << programming_language->build() << endl;
        }
    }

    cout << endl
         << "Task 3"
         << endl
         << endl;

    cout << Angle<int>(30) << endl;
    cout << (Angle<int>(30) + 360) << endl;
    cout << (Angle<int>(30) + 3.14159265359) << endl;
    cout << Angle<double>(3.14159265359 / 2) << endl;
    cout << (Angle<double>(3.14159265359 / 2) + 3.14159265359) << endl;
    cout << (Angle<double>(3.14159265359 / 2) + 3) << endl;

    cout << endl
         << "Task 4"
         << endl
         << endl;

    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> b = {2, 3, 4, 5, 6};

    cout << parallell_transform(a, b, [](int a_element, int b_element) {
        return a_element + b_element;
    }) << endl;

    cout << parallell_transform(a, b, [](int a_element, int b_element) {
        return a_element * b_element;
    }) << endl;
}
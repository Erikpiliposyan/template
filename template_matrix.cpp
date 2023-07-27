#include <iostream>

template <typename T>
class Array {
private:
    int rows;
    int cols;
    T** ptr;

public:
    Array(int n, int m) : rows(n), cols(m) {
        ptr = new T*[rows];
        for (int i = 0; i < rows; i++) {
            ptr[i] = new T[cols];
        }
    }

    Array(Array&& other)
        : rows(other.rows)
        , cols(other.cols)
        , ptr(other.ptr) {
        other.rows = 0;
        other.cols = 0;
        other.ptr = nullptr;
    }

    Array& operator=(Array&& other) {
        if (this != &other) {
            for (int i = 0; i < rows; i++) {
                delete[] ptr[i];
            }
            delete[] ptr;

            rows = other.rows;
            cols = other.cols;
            ptr = other.ptr;

            other.rows = 0;
            other.cols = 0;
            other.ptr = nullptr;
        }
        return *this;
    }

    ~Array() {
        for (int i = 0; i < rows; i++) {
            delete[] ptr[i];
        }
        delete[] ptr;
    }

    void input_arr() {
        std::cout << "Enter matrix values:" << std::endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                std::cin >> ptr[i][j];
            }
        }
    }

    void output_arr() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                std::cout << ptr[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    int n, m;
    std::cin >> n;
    std::cin >> m;

    if (n >= 0 && m >= 0) {
        Array<int> matrix(n, m);
        matrix.input_arr();
        matrix.output_arr();

        Array<int> c(n, m);
        Array<int> b = std::move(c);
    } else {
        std::cout << "Negative number please change" << std::endl;
    }

    return 0;
}

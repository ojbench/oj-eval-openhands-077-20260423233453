
#ifndef CROSSARRAY_HPP
#define CROSSARRAY_HPP

namespace sjtu {
    class CrossArray {
    private:
        int **data;
        int *sizes;
        int max_lines;
        int current_lines;

    public:
        explicit CrossArray(int lines) : max_lines(lines), current_lines(0) {
            data = new int*[max_lines];
            sizes = new int[max_lines];
            for (int i = 0; i < max_lines; ++i) {
                data[i] = nullptr;
                sizes[i] = 0;
            }
        }

        CrossArray(const CrossArray & o) : max_lines(o.max_lines), current_lines(o.current_lines) {
            data = new int*[max_lines];
            sizes = new int[max_lines];
            for (int i = 0; i < max_lines; ++i) {
                if (o.data[i] != nullptr) {
                    sizes[i] = o.sizes[i];
                    data[i] = new int[sizes[i]];
                    for (int j = 0; j < sizes[i]; ++j) {
                        data[i][j] = o.data[i][j];
                    }
                } else {
                    data[i] = nullptr;
                    sizes[i] = 0;
                }
            }
        }

        CrossArray & WhichGreater(CrossArray & o) {
            long long count1 = 0;
            for (int i = 0; i < current_lines; ++i) {
                count1 += sizes[i];
            }
            long long count2 = 0;
            for (int i = 0; i < o.current_lines; ++i) {
                count2 += o.sizes[i];
            }
            if (count2 > count1) {
                return o;
            } else {
                return *this;
            }
        }

        bool IsSame(const CrossArray & o) {
            return this == &o;
        }

        bool InsertArrays(const int * Input, int size) {
            if (current_lines >= max_lines) {
                return false;
            }
            sizes[current_lines] = size;
            data[current_lines] = new int[size];
            for (int i = 0; i < size; ++i) {
                data[current_lines][i] = Input[i];
            }
            current_lines++;
            return true;
        }

        void AppendArrays(const int * Input, int Line, int size) {
            int new_size = sizes[Line] + size;
            int *new_array = new int[new_size];
            for (int i = 0; i < sizes[Line]; ++i) {
                new_array[i] = data[Line][i];
            }
            for (int i = 0; i < size; ++i) {
                new_array[sizes[Line] + i] = Input[i];
            }
            delete[] data[Line];
            data[Line] = new_array;
            sizes[Line] = new_size;
        }

        void DoubleCrossLength() {
            int new_max_lines = max_lines * 2;
            int **new_data = new int*[new_max_lines];
            int *new_sizes = new int[new_max_lines];
            for (int i = 0; i < max_lines; ++i) {
                new_data[i] = data[i];
                new_sizes[i] = sizes[i];
            }
            for (int i = max_lines; i < new_max_lines; ++i) {
                new_data[i] = nullptr;
                new_sizes[i] = 0;
            }
            delete[] data;
            delete[] sizes;
            data = new_data;
            sizes = new_sizes;
            max_lines = new_max_lines;
        }

        const int * AtArray(int i) {
            return data[i];
        }

        int & At(int i, int j) {
            return data[i][j];
        }

        ~CrossArray() {
            for (int i = 0; i < max_lines; ++i) {
                if (data[i] != nullptr) {
                    delete[] data[i];
                }
            }
            delete[] data;
            delete[] sizes;
        }
    };
}

#endif


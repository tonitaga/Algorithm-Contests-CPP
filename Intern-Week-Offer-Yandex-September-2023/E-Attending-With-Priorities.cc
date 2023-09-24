#include <bits/stdc++.h>

struct Student {
    int index;
    int position;
    int programs_count;
    std::vector<int> programs;
    int result = -1;
    int programs_length;

    Student(int index, int position, int programs_count, std::vector<int> &&programs_input)
        : index(index), position(position), programs_count(programs_count), programs(std::forward<std::vector<int>>(programs_input)), programs_length(programs.size())
    {}
};

void Solution() {
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");

    int n, k;
    fin >> n >> k;

    std::unordered_map<int, int> programs;
    for (int i = 1; i != k + 1; ++i)
        fin >> programs[i];


    std::unordered_map<int, std::vector<Student>> table;

    {
        int position, programs_count;
        for (int i = 0; i != n; ++i) {
            fin >> position >> programs_count;

            std::vector<int> student_programs(programs_count);
            for (auto &program: student_programs)
                fin >> program;

            if (table.find(position) == table.end())
                table[position];

            table[position].emplace_back(i, position, programs_count, std::move(student_programs));
        }
    }

    std::vector<Student> students;
    students.reserve(n);

    std::vector<std::pair<int, std::vector<Student>>> vector_table(table.begin(), table.end());
    std::sort(vector_table.begin(), vector_table.end(), [](const std::pair<int, std::vector<Student>> &lhs, const std::pair<int, std::vector<Student>> &rhs) {
        return lhs.first < rhs.first;
    });

    for (auto &[position, stud_vector] : vector_table) {
        std::sort(stud_vector.begin(), stud_vector.end(), [](const Student &lhs, const Student &rhs) {
            return lhs.programs_length < rhs.programs_length;
        });

        for (auto &student : stud_vector) {
            students.emplace_back(student);
            if (student.result != -1)
                continue;

            for (auto program : student.programs) {
                if (programs[program] > 0) {
                    student.result = program;
                    students.back().result = program;
                    programs[program]--;
                    break;
                }
            }
        }
    }

    std::sort(students.begin(), students.end(), [](const Student &lhs, const Student &rhs) {
        return lhs.index < rhs.index;
    });

    for (const auto &student : students)
        fout << student.result << ' ';
    fout << std::endl;
}

int main() {
    Solution();
    return EXIT_SUCCESS;
}
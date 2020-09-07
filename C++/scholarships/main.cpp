#include <iostream>
#include <string>
#include <iomanip>

std::string firstName, lastName;
int students, courses, scholarships, cnt = 0;
bool failed = false;
double avg, sum = 0.0, grade;

struct Smartest {
    std::string name;
    float results = 0.0;
} Smart;

int main() {

    std::cin >> students >> courses >> scholarships;

    for (int i = 0; i != students; ++i) {
        std::cin >> firstName >> lastName;

        for (int j = 0; j != courses; ++j) {
            std::cin >> grade;
            if (grade < 5) {
                failed = true;
            }
            sum += grade;
        }
        avg = sum / float(courses);
        std::cout << "Sum is: " << sum << " and avg is: " << avg << '\n';
        sum = 0.0;

        if (avg < 8 or failed) {
            failed = false;
            continue;
        } else {
            ++cnt;
        }

        if (Smart.results < avg) {
            Smart.results = avg;
            Smart.name = firstName + " " + lastName;
        }
    }

    if (cnt < scholarships) {
        std::cout << cnt - 1 << std::endl;
    } else {
        std::cout << scholarships << std::endl;
    }

    std::cout << Smart.name << " " << std::setprecision(2) << std::fixed << Smart.results;

    return 0;
}

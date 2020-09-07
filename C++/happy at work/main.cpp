#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

std::map<std::string, int> emotions, employees, jobCnt;
std::string placeHolder, emotion, job;
int number, score;
std::vector<std::pair<std::string, float>> averageEmotion;

bool SortVector(const std::pair<std::string, float>& pair1, const std::pair<std::string, float>& pair2){
    return pair1.second > pair2.second; // functor to sort vector in decreasing order of scores
}

int main() {
    std::cin >> number;

    for(int i = 0; i != number; ++i){
        std::cin >> placeHolder;
        std::cin >> score;

        emotions.insert(std::make_pair(placeHolder, score)); // make a map that holds emotion and its score
    }

    while (std::cin >> placeHolder){
        std::cin >> emotion >> job;

        auto ret = employees.insert(std::make_pair(job, emotions[emotion])); // make a map that adds the emotions for each job
        if (!ret.second){ // if job was already inserted into the map, add the current emotion to the value
            ret.first->second += emotions[emotion];
        }

        auto ret2 = jobCnt.insert(std::make_pair(job, 1)); // map that counts how many instances of each job appeared
        if (!ret2.second){
            ret2.first->second += 1; // if job already exist, increment counter
        }
    }

    for (const auto & feeling : employees){ // for every job registered
        auto localScore = float(feeling.second) / float (jobCnt[feeling.first]); // take the average using 'employees' for score and 'jobCnr' for instanced
        averageEmotion.emplace_back(std::make_pair(feeling.first, localScore));
    }

    std::sort(averageEmotion.begin(), averageEmotion.end(), SortVector); // sort vector

    for (const auto& employee : averageEmotion){ // print with fixed 2 digit precision
        std::cout << std::fixed << std::setprecision(2) << employee.first << " " << employee.second << '\n';
    }

    return 0;
}

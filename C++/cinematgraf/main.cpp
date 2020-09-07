#include <iostream>
#include <vector>
#include <map>
#include <string>

std::map<int, std::string> movies;
std::string placeHolder, arrivalTime;
std::vector<std::string> movie;
int movieNb, price;

int toHour(std::string &hour) { // function to transform time string to int minutes
    return std::stoi(hour.substr(0, 2)) * 60 + std::stoi(hour.substr(3, 2));
}

int main() {
    std::cin >> arrivalTime;
    std::cin >> movieNb;
    int time = toHour(arrivalTime);

    while (std::cin >> placeHolder) {
        movie.push_back(placeHolder);

        if (movie.size() == 3) { // size == 3 means all data about a movie
            if (toHour(movie[0]) < time) { // if movie is before arrival time
                movie.clear(); // clear entry and skip to next input
                continue;
            } else {
                auto ret = movies.insert(std::make_pair(toHour(movie[0]), movie[2])); // insert into map a std::pair<arrival time, movie title>

                if (ret.first == movies.begin() and ret.second) { // maps are inherently ordered thus, if inserted movie is first in map, remember price
                    price = std::stoi(movie[1]); // in case we need to compare later
                }

                if (!ret.second) { // if theres a movie at the same hour
                    if (std::stoi(movie[1]) < price) { // compare the prices
                        ret.first->second = movie[2]; // store the smallest price
                    }
                }
            }
            movie.clear();
        }
    }

    std::cout << movies.begin()->second; // print name of first movie

    return 0;
}
#include <iostream>
#include <vector>
#include <cmath>

int samples, parcels, milliseconds, state;
float speed = 0.0f;
std::vector<std::pair<int, int>> sensor1, sensor2;
std::vector<int> packages1, packages2;

void FindPackage(const std::vector<std::pair<int, int>> &sensor, std::vector<int> &parcel) { // function to detect packages from sensor data
    bool found = false; // we only care abut the first instance of a package being detected by each sensor
    // eg: a parcel travelling at 4 cm/s that is 20cm long will trigger the sensor for ~ 5 seconds
    // to find the speed we need the delta time between the first detections by each sensor
    for (const auto &data : sensor) {
        if (data.second == 1 and !found) {
            parcel.emplace_back(data.first);
            found = true; // if a parcel was found, skip next detections
        }
        if (data.second == 0) { // reset bool when we first encounter a 0
            found = false;
        }
    }
}

float FindSpeed(const int &time1, const int &time2) {
    return 0.2f * 1000 / float(time2 - time1); // speed is distance between sensors(in meters) divided by time(in seconds)
}

int main() {
    std::cin >> samples;

    while (std::cin >> milliseconds) {
        std::cin >> state;
        if (sensor1.size() <= samples) { // each sensor has equal entries, so fill the first and move to the next
            sensor1.emplace_back(std::make_pair(milliseconds, state));
        } else {
            sensor2.emplace_back(std::make_pair(milliseconds, state));
        }
    }

    FindPackage(sensor1, packages1); // scan vectors for parcels and append them
    FindPackage(sensor2, packages2);
    parcels = packages1.size();

    for (int i = 0; i != parcels; ++i) { // both vectors have equal number of parcels
        speed += FindSpeed(packages1[i], packages2[i]);
    }

    speed = speed / float(parcels);

    std::cout << std::round(speed) << " " << parcels << '\n'; // round speed to int

    return 0;
}

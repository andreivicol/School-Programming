#include <iostream>
#include <vector>
#include <cmath>

int particles, hitsNucleus = 0, dangerous = 0;
float distance, mass, angle, speed;
float energy = 200000000.0f;

bool CheckKineticEnergy(float &mass, float &speed) { // calculate kitetic energy
    auto localSpeed = speed * 1000; // make local variables to not alter higher scoped variables
    auto localMass = mass / 1000000;
    return energy <= localMass * localSpeed * localSpeed / 2;
}

bool CheckIfHits(const float &distance, const float &angle) { // check if particle hits based on computed angle
    float radians = std::atan(153.0f / (153.0f + distance));

    return (angle < radians);
}

int findParticle(const float &mass, const float &speed) { // identify particle based on mass and speed
    if (mass >= 2 and speed <= 10000.0f) {
        return 0;
    }

    if (mass < 2 and speed >= 15000.0f) {
        return 1;
    }
    return 2;
} // make function return int to directly access list index for corresponding particle

int main() {

    std::cin >> particles;
    std::vector<int> list(3, 0); // lists of particles for each category
    std::vector<int> listThatHits(3, 0);
    std::vector<int> listDanger(3, 0);

    for (int i = 0; i != particles; ++i) {
        std::cin >> distance >> mass >> angle >> speed;
        ++list[findParticle(mass, speed)];

        if (CheckIfHits(distance, angle)) {
            ++hitsNucleus;
            ++listThatHits[findParticle(mass, speed)];

            if (CheckKineticEnergy(mass, speed)) {
                ++dangerous;
                ++listDanger[findParticle(mass, speed)];
            }
        }
    }

    std::cout << hitsNucleus << " " << dangerous << '\n';

    for (const auto &particle : list) {
        std::cout << particle << " ";
    }
    std::cout << '\n';
    for (const auto &particle : listThatHits) {
        std::cout << particle << " ";
    }
    std::cout << '\n';
    for (const auto &particle : listDanger) {
        std::cout << particle << " ";
    }

    return 0;
}

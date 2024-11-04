#include "Walk.h"
#include "UtilRand.h"
#include <cmath>

Walk::Walk() : x(0), y(0), distance(0) {}

void Walk::setX(double x) {
    this->x = x;
}

double Walk::getX() const {
    return x;
}

void Walk::setY(double y) {
    this->y = y;
}

double Walk::getY() const {
    return y;
}

void Walk::setDistance(double distance) {
    this->distance = distance;
}

double Walk::getDistance() const {
    return distance;
}

int Walk::generateAngle() {
    return generateRandomInRange(1, 359);
}

int Walk::generateLength() {
    return generateRandomInRange(1, 100);
}

double Walk::convertToRadians(double degree) {
    const double pi = 3.14159265358979323846;
    return degree * pi / 180;
}

void Walk::walkAgain() {
    int length = generateLength();
    int angle = generateAngle();

    double angleRadians = convertToRadians(angle);

    x += length * cos(angleRadians);
    y += length * sin(angleRadians);

    distance += length;
}

std::ostream& operator<<(std::ostream& os, const Walk& w) {
    os << "Point: " << w.getX() << ", " << w.getY() << " Distance: " << w.getDistance();
    return os;
}

double calculateAverageDistance(const vector<Walk>& walks) {
    double totalDistance = 0;
    for (const auto& walk : walks) {
        totalDistance += walk.getDistance();
    }
    return totalDistance / walks.size();
}

double findShortestDistance(const vector<Walk>& walks) {
    double shortest = numeric_limits<double>::max();
    for (const auto& walk : walks) {
        if (walk.getDistance() < shortest) {
            shortest = walk.getDistance();
        }
    }
    return shortest;
}

double findMedianDistance(vector<double>& distances) {
    size_t size = distances.size();
    return (size % 2 == 0) ? (distances[size / 2 - 1] + distances[size / 2]) / 2.0 : distances[size / 2];
}

double findLongestDistance(const vector<Walk>& walks) {
    double longest = 0;
    for (const auto& walk : walks) {
        if (walk.getDistance() > longest) {
            longest = walk.getDistance();
        }
    }
    return longest;
}

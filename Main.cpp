#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <iomanip>
#include "UtilRand.h"
#include "Walk.h"

using namespace std;

int main() {
	initRandom();

	cout << "***Walks***" << endl << endl;

	cout << "This program generates a number of random walks." << endl << endl;

	int numPoints, numWalks;
	cout << "Enter number of points for each walk: ";
	cin >> numPoints;
	cout << endl;

	cout << "Enter number of random walks to generate: ";
	cin >> numWalks;
	cout << endl;

	vector<Walk> walks(numWalks);
	
	// Displays Walks and Steps
	cout << fixed << setprecision(2);
	for (int i = 0; i < numWalks; i++) {
		for (int j = 0; j < numPoints; j++) {
			walks[i].walkAgain();
			cout << "Walk/Step: " << i + 1 << "/" << j + 1 << ": Point: " << walks[i].getX() << ", " << walks[i].getY() << " Distance: " << walks[i].getDistance() << endl;
		}
		cout << endl;
	}

	sort(walks.begin(), walks.end(), [](const Walk& a, const Walk& b) {
        	return a.getDistance() < b.getDistance();
   	});

	cout << "Walks Sorted by Distance: " << endl;
	for(const auto& walk : walks) {
		cout << "Point: " << walk.getX() << ", " << walk.getY()
		     << " Distance: " << walk.getDistance() << endl;
	}
	
	// Display averages and different distances
	cout << "Average Distance: " << calculateAverageDistance(walks) << endl;
	cout << "Shortest Distance/Walk: " << findShortestDistance(walks) << endl;
	cout << "Median Distance/Walk: " << findMedianDistance(walks) << endl;
	cout << "Longest Distance/Walk: " << findLongestDistance(walks) << endl;

	return 0;
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

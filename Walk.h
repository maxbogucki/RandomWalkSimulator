// Walk.h
#ifndef WALK_H
#define WALK_H
#include <iostream>

class Walk {
private:
	double x, y, distance;

public:
	Walk();
	void setX(double x);
	double getX() const;
	void setY(double y);
	double getY() const;
	void setDistance(double distance);
	double getDistance() const;
	int generateAngle();
	int generateLength();
	double convertToRadians(double degree);
	void walkAgain();
};

ostream& operator<<(ostream& os, const Walk& w);

double calculateAverageDistance(const vector<Walk>& walks);
double findShortestDistance(const vector<Walk>& walks);
double findMedianDistance(vector<double>& distances);
double findLongestDistance(const vector<Walk>& walks);

#endif // Walk.h

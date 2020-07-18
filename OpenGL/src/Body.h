#pragma once

#include <vector>
using namespace std;

class Body {
	private:
		vector<float> colour;
		vector<float> position; //position of centre
		float radius;
		double mass;
		vector<double> acceleration, velocity; //Could potentially be replaced with a vector object

	public:
		Body(float colour[3], float position[2], float radius, double mass, double velocity[2]);
		void update();
		void gravity(Body otherBody);

		float getColour(int index);
		float getPosition(int index);
		float getRadius();
		double getMass();
		//vector<double> getAcceleration();
		//vector<double> getVelocity();
		~Body() {};
};
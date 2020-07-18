#include "Body.h"
#include "maths.h"

Body::Body(float colour[3], float position[2], float radius, double mass, double velocity[2]) { //mass needs to be given in kg x 10^17
	this->colour.push_back(colour[0]);
	this->colour.push_back(colour[1]);
	this->colour.push_back(colour[2]);

	this->position.push_back(position[0]);
	this->position.push_back(position[1]);

	this->acceleration.push_back(0);
	this->acceleration.push_back(0);
	//fill(this->acceleration->begin(), this->acceleration->begin() + 1, 0);

	this->velocity.push_back(velocity[0]);
	this->velocity.push_back(velocity[1]);

	this->radius = radius;
	this->mass = mass;
}

void Body::update() { //updated every frame
	this->velocity[0] += this->acceleration[0] * 0.0001; //0.01 is time for now
	this->velocity[1] += this->acceleration[1] * 0.0001;

	this->position[0] += this->velocity[0] * 0.0001;
	this->position[1] += this->velocity[1] * 0.0001;

	this->acceleration[0] = 0;
	this->acceleration[1] = 0;
}

void Body::gravity(Body otherBody) {
	float difference[2];
	difference[0] = this->getPosition(0) - otherBody.getPosition(0);
	difference[1] = this->getPosition(1) - otherBody.getPosition(1);
	float modDifSquare = difference[0] * difference[0] + difference[1] * difference[1];

	double result = otherBody.getMass() * 0.6674000 / modDifSquare;//6674 is equivalent to G x 10^17      uses Newton's formula for gravitation

	float modDif = root(modDifSquare, 2, 1000); //TODO - ALTER NUMBER OF ITERATIONS IF NEEDED
	difference[0] /= modDif; //unit vector
	difference[1] /= modDif;

	this->acceleration[0] -= difference[0] * result; //apply result
	this->acceleration[1] -= difference[1] * result;
}










float Body::getColour(int index) {
	return colour[index];
}

float Body::getPosition(int index) {
	return position[index];
}

float Body::getRadius() {
	return radius;
}

double Body::getMass() {
	return mass;
}
//vector<double> getAcceleration();
//vector<double> getVelocity();
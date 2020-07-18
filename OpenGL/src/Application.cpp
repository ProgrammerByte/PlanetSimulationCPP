//#include <GL/glew.h>
//#include <GLFW/glfw3.h>
#include "Graphics2D.h"
#include "Body.h"

#include <iostream>

using namespace std;

//for now the coordinates system goes from (-aspectRatio, -1) to (aspectRatio, 1)
int main() {

	/*const int count = 2;
	float colours[count][3] = { {1, 1, 1}, {1, 0, 0} }; //details about all planets
	float positions[count][2] = { {0, 0}, {-0.8, 0} };
	float radii[count] = { 0.3, 0.15 };
	double masses[count] = { 1000, 1 };
	double velocities[count][2] = { {0, 0}, {0, 30} };*/

	const int count = 2;
	float colours[count][3] = { {0, 0, 1}, {1, 0, 0} }; //details about all planets
	float positions[count][2] = { {0.8, 0}, {-0.8, 0} };
	float radii[count] = { 0.15, 0.15 };
	double masses[count] = { 10000, 10000 };
	double velocities[count][2] = { {0, -30}, {0, 30} };

	vector<Body> planets;
	//Body gay = Body(colours[0], positions[0], radii[0], masses[0], velocities[0]);
	//Body planets[count];
	for (int i = 0; i < count; i++) {
		planets.push_back(Body(colours[i], positions[i], radii[i], masses[i], velocities[i]));
	}
	//Body planet = Body();
	//planets[0] = Body();
	//planets[1] = Body;

	Graphics2D engine = Graphics2D(1080, 1080, "Space", false);
	while (engine.shouldClose() == false) {
		//cout << "hello" << endl;
		for (int i = 0; i < count; i++) { //applies gravity
			for (int x = 0; x < count; x++) {
				if (i != x) {
					planets[i].gravity(planets[x]);
				}
			}
		}

		for (int i = 0; i < count; i++) {
			planets[i].update();
			engine.setFillColour(planets[i].getColour(0), planets[i].getColour(1), planets[i].getColour(2), 1);
			engine.circle(planets[i].getPosition(0), planets[i].getPosition(1), planets[i].getRadius());
		}

		engine.clear();
	}
}
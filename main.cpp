#include "planetsdb/include/planets.h"

int main() {
    planets::PlanetsDB db;

    db.addPlanet(planets::Planet("Марс", 44444, true, 2));
    db.addPlanet(planets::Planet("Земля", 40000, true, 1));
    db.addPlanet(planets::Planet());

    db.printPlanets();
    std::cout << std::endl;
    db.sortPlanets();
    db.printPlanets();

    db.writePlanets("planets.txt");
    db.readPlanets("planets.txt");
    return 0;
}

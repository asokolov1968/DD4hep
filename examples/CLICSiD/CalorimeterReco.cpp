/*
 * CLICSiDCalorimeterReco.cpp
 *
 *  Created on: Apr 5, 2013
 *      Author: Christian Grefe, CERN
 */

#include "DD4hep/LCDD.h"
#include "BarrelDetector.h"
#include "PolyhedralBarrelCalorimeter.h"
#include "Calorimeter.h"

using namespace std;
using namespace DD4hep;
using namespace Geometry;

void printCalorimeterInformation(const DetElement& det) {
	std::string delimiter = "-------------------------------------\n";

	cout << "Detector name: " << det.name() << ", type: " << det.type() << endl;
	PolyhedralCalorimeter calorimeter(det);
	cout << delimiter << "Layer interface:" << endl;
	cout << "\tNumber of layers: " << calorimeter.getNumberOfLayers() << endl;
	cout << "\tTotal thickness: " << calorimeter.getTotalThickness() << " cm" << endl;
	cout << "\tTotal interaction lengths: " << calorimeter.getTotalInteractionLengths() << " Lambda_int" << endl;
	cout << "\tTotal radiation lengths: " << calorimeter.getTotalRadiationLengths() << " X_0" << endl;
	for (int layerIndex = 1; layerIndex <= calorimeter.getNumberOfLayers(); layerIndex++) {
		cout << "\t\tLayer " << layerIndex << ": d = " << calorimeter.getLayerThickness(layerIndex)
				<< " cm , Lambda/Lambda_int = " << calorimeter.getInteractionLengths(layerIndex) << ", X/X_0 = "
				<< calorimeter.getRadiationLengths(layerIndex) << ", Sensors: "
				<< calorimeter.getNumberOfSensors(layerIndex) << endl;
	}

	cout << delimiter << "Polyhedra interface:" << endl;
	cout << "\tInner radius: " << calorimeter.getRMin() << " cm" << endl;
	cout << "\tOuter radius: " << calorimeter.getRMax() << " cm" << endl;
	cout << "\tMinimum z: " << calorimeter.getZMin() << " cm" << endl;
	cout << "\tMaximum z: " << calorimeter.getZMax() << " cm" << endl;
	cout << "\tNumber of sides: " << calorimeter.getNSides() << endl;

	cout << delimiter << endl;
}

int main(int argc, char** argv) {

	LCDD& lcdd = LCDD::getInstance();
	lcdd.fromCompact(argv[1]);
	printCalorimeterInformation(lcdd.detector("MuonBarrel"));
	//printCalorimeterInformation(lcdd.detector("HcalBarrel"));

	return 0;
}
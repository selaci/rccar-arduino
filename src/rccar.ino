#include "arduino_interface.h"
#include "lights.h"
#include "motor.h"
#include "car.h"
#include "driver.h"

const int EN1 = 5;
const int IN1 = 6;
const int IN2 = 7;
const int IN3 = 8;
const int IN4 = 9;
const int EN2 = 10;

const int DS    = 4;
const int LATCH = 3;
const int CLOCK = 2;

Arduino* arduino = new RealArduino();

Lights* lights = new RealLights(arduino);

Motor* left = new RealMotor(arduino);
Motor* right = new RealMotor(arduino);

Car* car = new RealCar(left, right, lights);

Driver* driver = new RealDriver(car);

void setup() {
	lights->setPins(DS, LATCH, CLOCK);
	lights->addSequence(new Circular());
	lights->addSequence(new DoubleCircular());
	lights->addSequence(new StarTrek());
	lights->addSequence(new KnightRider());
	lights->addSequence(new NicRider());
	lights->addSequence(new FillUp());

	left->setPins(EN1, IN1, IN2);
	right->setPins(EN2, IN3, IN4);

	arduino->pinMode(EN1, OUTPUT);
	arduino->pinMode(IN1, OUTPUT);
	arduino->pinMode(IN2, OUTPUT);

	arduino->pinMode(EN2, OUTPUT);
	arduino->pinMode(IN3, OUTPUT);
	arduino->pinMode(IN4, OUTPUT);

	arduino->pinMode(DS, OUTPUT);
	arduino->pinMode(LATCH, OUTPUT);
	arduino->pinMode(CLOCK, OUTPUT);

	Serial.begin(9600);
}

int next;
int number;

void loop() {
	if (Serial.available()) {
		int command = Serial.read();
		driver->conduct(command);
	}

	driver->nextLight();

	arduino->delay(75);
}

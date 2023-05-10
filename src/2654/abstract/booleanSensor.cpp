#include "booleanSensor.hpp"

namespace lib2654 {
	
	BooleanSensor::BooleanSensor(bool uSensorValue) {
		this->sensorValue = uSensorValue;
	}

	bool BooleanSensor::get() {
		return this->sensorValue;
	}

	bool BooleanSensor::getRisingEdge() {
		return this->risingEdge;
	}

	bool BooleanSensor::getFallingEdge() {
		return this->fallingEdge;
	}

	uint32_t BooleanSensor::getLastSensorReadingTimestamp() {
		return this->lastSensorTimestamp;
	}

	uint32_t BooleanSensor::getLastReadingAge() {
		// TODO: implement
		return 0;
	}

	void BooleanSensor::updateLogic(bool uSensorValue) {
		this->risingEdge = !this->sensorValue && uSensorValue;
		this->fallingEdge = this->sensorValue && !uSensorValue;

		// TODO: add timestamp

		this->sensorValue = uSensorValue;
	}

	BooleanSensor::~BooleanSensor() {
	}
} // namespace lib2654

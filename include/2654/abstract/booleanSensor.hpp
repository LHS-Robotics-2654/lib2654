#pragma once

#include "stdint.h"

// TODO: add time type

namespace lib2654 {
	class BooleanSensor {
	private:
		/**
		 * @brief Most up to date sensor reading
		 * 
		 */
		bool sensorValue = false;

		/**
		 * @brief Most up to date rising edge value
		 * 
		 */
		bool risingEdge;

		/**
		 * @brief Most up to date falling edge value
		 * 
		 */
		bool fallingEdge;

		/**
		 * @brief Current reading sensor value
		 * 
		 */
		uint32_t lastSensorTimestamp = 0;
	public:
		BooleanSensor(bool uSensorValue);

		/**
		 * @brief Get the most up to date value from the sensor
		 *
		 * @return true Current frame's sensor reading is true
		 * @return false Current frame's sensor reading is false
		 */
		bool get();

		/**
		 * @brief Get the current sensor's rising edge value this frame, indicating the sensor has moved from false to true
		 *
		 * @return true The sensor's current value is true and the last value is false
		 * @return false The sensor's current value has remained the same as the last frame or is falling
		 */
		bool getRisingEdge();

		/**
		 * @brief Get the current sensor's rising edge value this frame, indicating the sensor has moved from true to false
		 *
		 * @return true The sensor's current value is false and the last value is true
		 * @return false The sensor's current value has remained the same as the last frame or is rising
		 */
		bool getFallingEdge();

		/**
		 * @brief Last sensor reading timestamp since program start (Either from pros::millis() or simulator timestamp)
		 *
		 * @return uint32_t Milliseconds since program start
		 */
		uint32_t getLastSensorReadingTimestamp();

		/**
		 * @brief Get the age of the current sensor reading, or lag since last vexos sensor update
		 *
		 * @return uint32_t Age of sensor reading in milliseconds
		 */
		uint32_t getLastReadingAge();

		/**
		 * @brief Called every frame to check for new sensor readings
		 *
		 */
		void update() { this->updateLogic(this->updateSensor()); }

		/**
		 * @brief Implemented to get readings from robot or simulated sensors
		 *
		 * @return true The simulated or robot sensor's reading is true
		 * @return false The simulated or robot sensor's reading is false
		 */
		virtual bool updateSensor() { return false; }

		/**
		 * @brief Called every sensor update
		 *
		 * @param uSensorValue The new sensor value
		 */
		void updateLogic(bool uSensorValue);

		~BooleanSensor();
	};
} // namespace lib2654

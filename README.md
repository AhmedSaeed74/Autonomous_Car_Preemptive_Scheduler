# Real-Time Operating System Preemptive Scheduler for Autonomous Car

## Project Overview

This project focuses on implementing a preemptive scheduler for an autonomous car that relies on a real-time operating system (RTOS). The preemptive scheduler abstracts the application from the Hardware Abstraction Layer (HAL) and is responsible for managing the execution of various tasks. The application layer consists of four software components that work together to operate the autonomous car, each performing specific tasks.

## System Components

The system components for the autonomous car include:

1. Two Photo-Resistors.
2. One Ultrasonic Sensor Module HC-SR04.
3. On-board Temperature sensor.
4. One LCD.
5. Four motors + Two motor drivers.

Key functionalities and operation of the system components:

- The car motors are initiated using one of the two on-board switches.
- The car will stop if the other switch is pressed or if one minute elapses.
- When motors are started, the car moves and adjusts its direction based on the light sensor readings.
- The Temperature, the LDR's difference, and the elapsed time are displayed on the LCD.
- If the car gets closer to an obstacle (up to 10 centimeters), the ultrasonic sensor triggers a response. The car reverses and rotates by 90 degrees.
- In case of abnormal temperature (above a certain threshold), a warning message is displayed on the LCD.

## Scheduler and Task Sequencing

The scheduler is a preemptive one and uses the SysTick timer. It operates according to the priority of tasks. The system sequence is as follows:

1. The scheduler executes the highest-priority task to initialize all system modules and then suspends itself. This task will not be resumed.
2. The switch-check task periodically checks if the switch is pressed. When pressed, the system operates for 60 seconds.
3. The ultrasonic sensor task reads data and passes it to the ultrasonic update task through queue1.
4. The ultrasonic update task takes action based on the readings to move the car forward if there's no obstacle, or to reverse and spin the car 90 degrees if there's an obstacle.
5. The LDR task reads data and passes it to the LDR update task through queue2.
6. The LDR update task takes action based on the readings to move the car toward the light if there's a light difference between the two LDR sensors.
7. Binary semaphores are used to protect shared resources (the motors) from simultaneous access by the ultrasonic update and LDR update tasks.
8. The temperature sensor task reads the temperature. If the temperature exceeds specific thresholds, it triggers warnings or system shutdown.
9. In normal cases, the sensor readings are passed to the LCD task for display.
10. The system will turn off when the 60 seconds elapse till the switch is pressed again.

## Project Levels and CPU Load

- The system was calculated to have a hyper-period of 200 milliseconds.
- The calculated CPU load for the system is 64.5%.

## Project Structure

The project is organized into different layers:

- Tasks and the main function
- Preemptive Scheduler (`RTOS`)
- Temperature, LCD, Motors, LDR, Ultrasonic, and Push button.
- GPIO, GPTM, SysTick, ADC, and PWM drivers


Please click the link to make sure everything works perfectly and passes all tests without any problems.

https://drive.google.com/drive/folders/151C40D_TIJ8sXVjjVSB8OwF8aiGkILuE?usp=sharing

## Contribution

Contributions and improvements to the project are welcome. Feel free to fork the repository and create pull requests to enhance the scheduler and the functionality of the autonomous car.



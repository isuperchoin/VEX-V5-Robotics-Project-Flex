# VEX V5 Robotics - 30597E (2026-2027)

Official repository for the 30597E VEX Robotics Competition robot code. Built for the Override season.

## System Overview & Tech Stack

This project is built using high-performance embedded C++ for the VEX V5 platform, leveraging industry-standard robotics tools:
* **Core Framework:** [PROS (Platform for Robotics Operating System)](https://pros.cs.purdue.edu/)
* **Chassis & Motion Engine:** [EZ-Template](https://ez-robotics.github.io/EZ-Template/) (Providing foundational PID control, drive movement abstractions, and telemetry infrastructure)
* **Language:** Modern C++ (C++17/20 idioms)

---

## Lead Programmer Contributions & Architecture

As the **Lead Programmer**, I designed, structured, and implemented the robot's custom operational logic on top of the base template framework. While EZ-Template provides robust chassis control primitives, the following custom systems were engineered entirely in-house:

* **Autonomous Pathfinding & Routines:** Designed multi-stage autonomous routines utilizing Encoder-based target positioning, PID tuning, and dynamic heading corrections.
* **Subsystem State Machine:** Implemented object-oriented control classes for intake, lift, and scoring mechanisms to prevent race conditions and ensure high-speed driver feedback.
* **Sensor Integration & Odometry:** Integrated inertial sensors, optical sensors, and rotation sensors for real-time error correction during high-speed maneuvers.
* **Match-Ready Error Handling:** Developed fail-safes and non-blocking sensor checks to maximize reliability under tournament pressure.

---

## Acknowledgments & Credits
This project stands on the shoulders of incredible open-source tools within the VEX community:

* **The PROS Team:** For providing a powerful, multi-threaded C/C++ development environment for VEX V5.

* **Robotics is ez:** For creating an exceptionally reliable drivetrain and PID abstraction layer that accelerated our baseline development and allowed our team to focus on advanced strategy.

Maintained and developed by Choin Park, Lead Programmer of Team 30597E.

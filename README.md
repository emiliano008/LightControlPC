# LightControlPC

Is a program designed to control the power on and off of a computer in response to the detection of electrical light. By using the analog pin of an Arduino Nano to monitor the 5V provided by a transformer connected to the electrical grid, the program continuously observes the voltage level.

When the voltage falls below a predefined threshold, it is interpreted as a lack of electrical light, and the program shuts down the PC. Conversely, when voltage is detected, the program powers on the PC.

In addition to this control function, the program provides real-time voltage level information through a serial connection. This allows users to monitor the status of both the light and the PC's power state as it changes.

This program is particularly valuable when using older equipment with uninterruptible power supplies (UPS) that lack PC connectivity for proper shutdown procedures.

The circuit is powered by a transformer connected to the UPS and a second transformer connected directly to the electrical grid. When the Arduino Nano detects the absence of voltage, it sends a signal to a transistor to act as a switch. This switch, connected directly to the motherboard, initiates the computer's shutdown process.

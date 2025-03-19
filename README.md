# Arduino Uno WiFi Rev2 Web Server with JSON Response

This project is a simple web server implemented on an Arduino Uno WiFi Rev2. It connects to a Wi-Fi network and listens for incoming HTTP requests. When it receives a GET request, it responds with a JSON object containing a predefined name.

## Features
- Connects to a Wi-Fi network using `WiFiNINA` library.
- Hosts a simple web server on port 80.
- Responds to HTTP GET requests with a JSON object.

## Hardware Required
- Arduino Uno WiFi Rev2
- USB cable for programming and power
- Wi-Fi network to connect to

## Libraries Used
- `WiFiNINA`: Library to manage Wi-Fi connections on the Arduino Uno WiFi Rev2. [link](https://docs.arduino.cc/libraries/wifinina/#WiFi%20Class)

## Setup Instructions

### 1. Install Required Libraries
Before uploading the code, make sure you have the following libraries installed in the Arduino IDE:
- **WiFiNINA** library (can be installed via Arduino Library Manager)

### 2. Connect Your Arduino Uno WiFi Rev2
Connect the Arduino Uno WiFi Rev2 to your computer via the USB cable.

### 3. Modify Wi-Fi Credentials
In the code, change the `ssid` and `pass` variables to match your Wi-Fi network credentials.

```cpp
char ssid[] = "your_network_name";    // Replace with your Wi-Fi network name
char pass[] = "your_password";        // Replace with your Wi-Fi password
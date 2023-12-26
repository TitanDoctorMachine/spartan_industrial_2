# Spartan Slave 2

Arduino ESP8266 Firmware with Web Management Interface for Relay Control and LCD Display

This firmware is developed for the Arduino platform, specifically targeting the ESP8266 module. It provides a web management interface for controlling relays, supports a shift register for GPIO expansion, integrates an LCD display for showing operation logs, and allows control of outputs and power supply initialization.

Key Features

    Web Management Interface:
        Access the web interface to configure and control the system intuitively.
        Configure parameters such as Wi-Fi network, passwords, and other important settings.

    Configuration Hotspot:
        In case of startup or configuration failure, the firmware initiates a hotspot for direct configuration, ensuring accessibility even in adverse situations.

    Shift Register Control for Relays:
        Support for relay control through a shift register, enabling the activation of multiple devices from a few GPIO pins.

    LCD Support:
        Integration of an LCD screen to display operation logs, status messages, and other relevant information.

    High Power Supply Initialization:
        Ability to control the initialization of an auxiliary power supply to optimize energy consumption and ensure a safe system behavior.

How to Use

    Initial Configuration:
        Connect to the hotspot provided by the device in case of startup failure.
        Access the web interface via the provided IP address (default: 192.168.4.1) to configure system options.

    Relay Control:
        Use the web interface to directly trigger relays.
        Configure the shift register to expand the number of controlled relays.

    Output Control and Initialization:
        Use the available options in the web interface to control outputs and initialize the power supply as needed.

Development Environment Setup

    Platform:
        Use the Arduino IDE and select the ESP8266 board.

    Required Libraries:
        Install the necessary libraries for ESP8266, shift register, and LCD as specified in the source code.

    Pin Configuration:
        Modify the pins according to your hardware configuration.

    Compilation and Upload:
        Compile the code and upload it to the ESP8266 module.

Contributions

You can clone and modify as you want, and if you want, try to submit some pull requests, and try to work above the develop branch;
Being honest I am normally not monitoring this platform, but you can try to send some messages if you you realy need or have some doubts. 
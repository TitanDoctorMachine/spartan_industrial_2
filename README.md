# Spartan Industrial 2

Arduino ESP8266 Firmware with Web Management Interface for Relay Control and LCD Display

This firmware is developed for the Arduino platform, specifically targeting the ESP8266 module. It provides a web management interface for controlling relays, supports a shift register for GPIO expansion, integrates an LCD display for showing operation logs, and allows control of outputs and power supply initialization.

# Key Features

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

# How to Use

    Initial Configuration:
        Connect to the hotspot provided by the device in case of startup failure.
        Access the web interface via the provided IP address (default: 192.168.4.1) to configure system options.

    Relay Control:
        Use the web interface to directly trigger relays.
        Configure the shift register to expand the number of controlled relays.

    Output Control and Initialization:
        Use the available options in the web interface to control outputs and initialize the power supply as needed.

# Development Environment Setup

    Platform:
        Use the Arduino IDE and select the ESP8266 board.

    Required Libraries:
        Install the necessary libraries for ESP8266, shift register, and LCD as specified in the source code.

    Pin Configuration:
        Modify the pins according to your hardware configuration.

    Compilation and Upload:
        Compile the code and upload it to the ESP8266 module.

# ------- Alpha release! -------

# System Requirements

    Ruby installed (version 3.0.1 or higher)
    LibUi gem
    Pry gem (optional)
    Yaml gem
    Write access to project directories

# Installation

    Clone or download the repository to your local environment.
    Ensure you have all Ruby dependencies installed.

# Usage

    Running the Program:
        Open a terminal.
        Navigate to the root directory of the software.
        Run the command ruby main.rb.

    Graphical Interface:
        After execution, a graphical interface will be displayed.
        Use the buttons and selection boxes to interact with the software.

    Generating Controllers:
        Enter the controller's name, select the desired HTTP method, and choose the rendering type (if applicable).
        Select the "Do not generate view" option if you do not want to create a view file.
        Click the "Generate" button to create the controller files.

    Viewing Results:
        The controller, routes, and, if applicable, view files will be generated in the specified directory.

# File Structures

    Main Directory:
        special_compilers/main.rb: Main executable file of the generator.

        jobs/: Directory containing project-specific files.
            routes.yml: YAML file containing route definitions.
            
            controllers/: Directory for controller files.
            controllers/application.cpp: main application file that runs before each controller.
            
            views/: Directory for view templates.
            public_assets/: folder whose files will bi available in the web server
            views/layouts/: html files for pre rendering pages
            views/layouts/assets/: partials of assets to be rendered by application.cpp

        async_jobs/: parallel jobs running in background (not quite precise though...)

        tasks/: API functions available to use in system, for each one it will store in the tasks lists and run in a asynchronous job later;
            EXAMPLE URL: http://192.168.1.100/api/v1/ignum4?token=xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx&cypher=POWER_PORT_UP.DELAY_5000.AUTO-Port_2-TRUE

        spartan_main/: main project and system structures;
        spartan_main/spartan_configs_static_class.h: Project Configs and some data structuration;

        spartan_industrial_2.ino: project Arduino compiler file.

# Contributions

    You can clone and modify as you want, and if you want, try to submit some pull requests, and try to work above the develop branch;
    Being honest I am normally not monitoring this platform, but you can try to send some messages if you you realy need or have some doubts. 
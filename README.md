# 4GP 2023-2024 "Projet capteur"
# Students : Maël LE BLANC, Daniel PERALES RIOS

4GP graphene-based sensor project
The aim of this project is to study a graphene-based low-tech sensor, based on the publication "Pencil Drawn Strain Gauges and Chemiresistors on Paper" by Cheng-Wei Lin*, Zhibo Zhao*, Jaemyung Kim & Jiaxing Huang.
According to this research, graphene particles, deposited by coloring a sensor trace, can act as strain gauges. 
As such, this project will cover the entire sensor field, right up to the development of a datasheet and test bench for this sensor.

[Necessary components](#necessary-components)

[Amplifier circuit](#amplifier-circuit)

[Graphite sensor](#graphite-sensor)

[OLED screen](#oled-screen)

## Necessary components

To carry out this project, we needed : 
  - 1 graphite-based sensor
  - 1 flex sensor
  - 1 digital potentiometer
  - 1 Arduino UNO
  - 1 bluetooth module
  - Resistances
  - Capacitors
  - 

## Amplifier circuit 

## Graphite sensor

/// Drawing of the sensor
 Diagram of the sensor used in the project. It will be filled in using different types of pencil. 

## OLED screen
The main page of the OLED screen has 3 different menus: Setting digital potentiometer values, bending sensor values and graphene-based sensor values. The user can select the menu using the rotary encoder. By turning the knob, the user can select the different drop-down menus and by pressing the knob, the user enters a specific menu. 

#### Potentiometer menu :
In this menu, the user selects the resistance value to be given to the potentiometer by placing the cursor over the available values. The user exits the calibration menu by pressing the encoder button. 
#### Flex Sensor menu:
In this menu, the value of the resistance and the value of the angle of the Flex Sensor are displayed.  
#### Flex Sensor menu:
In this menu, the resistance value of the graphite-based sensor is displayed. 

## PCB design in KiCAD
To realise our PCB we have used KiCAD under its 7.0 version. 
First of all, we had to reproduce the electrical amplifier circuit (resistances, capacitors...) with a few changes and component additions. In order to adjust the gain of our circuit, we've replaced the resistance R2 by a digital potentiometer which can be controlled using the encoder. Then for the realisation of the test bench we had to add some components that need to be connected to the power source, such as the flex sensor, the bluetooth module or the OLED screen. For that, we've created some symbols associated to the new elements. 
On the picture below, it is possible to see our whole and complete electrical circuit realised in KiCAD with the different symbols of the components. 

///mettre image du circuit KiCAD \\\ 
Then, the second part is to realise the footprint of the PCB on KiCAD. However, all the components and the whole circuit have to fit on Arduino Uno Shield. So, the spatial arrangement must be thoughtful, while considering the 3D shape of the components and the specifications we have to follow for the PCB printing. 
For the most commons components, we've used some predefined footprints but for the others we've created some specifical footprints thanks to the software. 
On the pictures below, it is possible to see the global footprint of our PCB and the 3D view. 

## Test bench 

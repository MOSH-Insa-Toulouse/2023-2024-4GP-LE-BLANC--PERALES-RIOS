# 4GP 2023-2024 "Projet capteur"
# Students : Maël LE BLANC, Daniel PERALES RIOS

4GP graphene-based sensor project

# Introduction
The aim of this project is to study a graphite-based low-tech sensor, based on the publication "Pencil Drawn Strain Gauges and Chemiresistors on Paper" by Cheng-Wei Lin, Zhibo Zhao, Jaemyung Kim & Jiaxing Huang, published on Nature in 2014.

According to this research, graphite particles, deposited by coloring a sensor trace, can act as strain gauges. These strain gauges can then be used to measure resistances of the order of the Giga-ohm (10E9 Ohms), for a much cheaper price than buying a multimeter able to measure this order of resistance.

To study this graphene-based low-tech sensor, we have made an amplifier circuit that allows to measure the current flowing through the graphite sensor. This current is very small, and to measure it we would need a very expensive multimeter. Moreover, as the resistance of the graphene sensor depends on each graphite sensor, we have added a digital potentiometer in one of the resistances of the amplifier circuit. This allows for tuning the circuit to each sensor.
We have also added a flex sensor to the project. The resistance of this sensor depends on the bending angle applied to it.

All the sensors and measurements are managed through an Arduino UNO board. In this Arduino UNO board, we have also connected an OLED screen that displays the data being measured. We have also implemented a simple menu in the screen that can be controlled through a rotary encoder. All the gathered data is then sent via a Bluetooth® module to an Android device though an app we have built using MIT’s App Inventor.

Finally, we have mounted all the sensors in a PCB we have built from scratch using KiCAD v7.0.

This project covers the entire sensor field, right up to the development of a datasheet and test bench for this sensor.

- [Principle of the measurement](#principle-of-the-measurement-for-the-graphite-and-flex-sensors)

- [Necessary components for the project](#necessary-components)

- [Overview of the project](#overview-of-the-project)

- [KiCAD PCB design](#kicad-pcb-design)

    - [Amplifier circuit](#amplifier-circuit)
    - [Graphite sensor](#graphite-sensor)
    - [OLED screen](#oled-screen)
    - [Rotary encoder](#rotary-encoder)
      

- [Android App](#android-app)

- [Test Bench](#test-bench)

# Principle of the measurement for the graphite and flex sensors

For the graphite and the flex sensors, let’s imagine they were a 2D layer of atoms to which we could apply tension and compression. This 2D layer of atoms would have a mean distance per atom depending on the atomic arrangement. The greater these mean distance between atoms is, the more difficult it is for an electron to “jump” from one atom to another, and vice versa. When these electron “jumps” are coordinated following the same direction (for example when we apply a potential difference between the two extremes of the 2D plane), we can say that an electric current is present.

On the one hand, when a compression force is applied to that 2D layer of atoms, the atoms would get closer to each other, thus reducing the mean distance per atom, facilitating the flow of an electric current, and reducing then the resistance. 

On the other hand, when a tensile force is applied to the 2D layer of atoms, the atoms would get further apart from each other, thus increasing the mean distance per atom, making the electron “jumps” less favorable, and increasing the resistance. 

We can see in Figure 1 how the compressive and tensile forces affect the geometry of the 2D plane. When generalizing the 2D plane to a 3D thin surface, the principle of the measurement stays the same.

![Imagen1](https://github.com/MOSH-Insa-Toulouse/2023-2024-4GP-LE-BLANC--PERALES-RIOS/assets/72049530/5d65b1fc-ff74-4581-843a-14737c406238)

Figure 1: Principle of the resistance measurement for the graphite and flex sensors. Extracted from “Pencil Drawn Strain Gauges and Chemiresistors on Paper”, by Cheng-Wei et al.

# Necessary components and schematic of the project

To carry out this project, we needed: 
  - 1 graphite-based paper sensor
  - 1 flex sensor
  - 1 LTC1050 operational amplifier
  - 1 MCP41050 digital potentiometer
  - 1 KY-040 rotary encoder
  - 1 Arduino UNO
  - 1 OLED screen
  - 1 HC-05 Bluetooth® module
  - Resistances
  - Capacitors

# Overview of the project





### Potentiometer menu
In this menu, the user selects the resistance value to be given to the potentiometer by placing the cursor over the available values. The user exits the calibration menu by pressing the encoder button. 
### Flex Sensor menu:
In this menu, the value of the resistance and the value of the angle of the Flex Sensor are displayed.  
### Flex Sensor menu:
In this menu, the resistance value of the graphite-based sensor is displayed. 

# KiCAD PCB design
To realise our PCB we have used KiCAD under its 7.0 version. 
First of all, we had to reproduce the electrical amplifier circuit (resistances, capacitors...) with a few changes and component additions. In order to adjust the gain of our circuit, we've replaced the resistance R2 by a digital potentiometer which can be controlled using the encoder. Then for the realisation of the test bench we had to add some components that need to be connected to the power source, such as the flex sensor, the bluetooth module or the OLED screen. For that, we've created some symbols associated to the new elements. 

On the picture below, it is possible to see our complete electrical circuit realised in KiCAD with the different symbols of the components. 

![Sin título](https://github.com/MOSH-Insa-Toulouse/2023-2024-4GP-LE-BLANC--PERALES-RIOS/assets/72049530/1b37a927-f7b1-49af-b2a8-71a55339fa15)

Figure 2 : Complete schematic of the electrical circuit in KiCAD for the project.

![Imagen2](https://github.com/MOSH-Insa-Toulouse/2023-2024-4GP-LE-BLANC--PERALES-RIOS/assets/72049530/8e232d55-1ca7-4d92-b692-054096b19475)

Figure 3: Schematic of the operationnal amplifier circuit in KiCAD

///mettre image du circuit KiCAD \\\ 
Then, the second part is to realise the footprint of the PCB on KiCAD. However, all the components and the whole circuit have to fit on Arduino Uno Shield. So, the spatial arrangement must be thoughtful, while considering the 3D shape of the components and the specifications we have to follow for the PCB printing. 
For the most commons components, we've used some predefined footprints but for the others we've created some specifical footprints thanks to the software. 
On the pictures below, it is possible to see the global footprint of our PCB and the 3D view. 

## Amplifier circuit 

## Graphite sensor

/// Drawing of the sensor
 

## OLED screen
The main page of the OLED screen has 3 different menus: Setting digital potentiometer values, bending sensor values and graphene-based sensor values. The user can select the menu using the rotary encoder. By turning the knob, the user can select the different drop-down menus and by pressing the knob, the user enters a specific menu. 

## Rotary encoder

# Android app

# Test bench

(Diagram of the sensor used in the project). It will be filled in using different types of pencil.

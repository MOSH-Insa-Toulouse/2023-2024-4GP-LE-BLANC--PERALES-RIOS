# 4GP 2023-2024 "Projet capteur"
# Students : Maël LE BLANC, Daniel PERALES RIOS

4GP graphene-based sensor project

# Introduction
The aim of this project is to study a graphite-based low-tech sensor, based on the publication "Pencil Drawn Strain Gauges and Chemiresistors on Paper" by Cheng-Wei Lin, Zhibo Zhao, Jaemyung Kim & Jiaxing Huang, published on Nature in 2014.

According to this research, graphite particles, deposited by coloring a sensor trace, can act as strain gauges. These strain gauges can then be used to measure resistances of the order of the Giga-ohm (10E9 Ohms), for a much cheaper price than buying a multimeter able to measure this order of resistance.

To study this graphene-based low-tech sensor, we have made an amplifier circuit that allows to measure the current flowing through the graphite sensor. This current is very small, and to measure it we would need a very expensive multimeter. Moreover, as the resistance of the graphene sensor depends on each graphite sensor, we have added a digital potentiometer in one of the resistances of the amplifier circuit. This allows for tuning the circuit to each sensor. We have also added a flex sensor to the project. The resistance of this sensor depends on the bending angle applied to it.

All the sensors and measurements are managed through an Arduino UNO board. In this Arduino UNO board, we have also connected an OLED screen that displays the data being measured. We have also implemented a simple menu in the screen that can be controlled through a rotary encoder. All the gathered data is then sent via a Bluetooth® module to an Android device though an app we have built using MIT’s App Inventor.

Finally, we have mounted all the sensors in a PCB we have built from scratch using KiCAD v7.0.

This project covers the entire sensor field, right up to the development of a datasheet and test bench for this sensor.

- [Deliverables](#deliverables)

- [Physics behind the resistance change in the graphite and the flex sensors](#physics-behind-the-resistance-change-in-the-graphite-and-the-flex-sensors)

- [Necessary components and image of the finished project](#necessary-components-and-image-of-the-finished-project)

- [Arduino code](#arduino-code)

- [KiCAD PCB design](#kicad-pcb-design)

    - [Amplifier circuit](#amplifier-circuit)
    - [Graphite sensor](#graphite-sensor)
    - [OLED screen](#oled-screen)
    - [Rotary encoder](#rotary-encoder)
      
- [Android App](#android-app)

- [Test Bench](#test-bench)


# Deliverables
The deliverables for this project are an Arduino shield with its associated Arduino code, an Android app that is able to gather the data sent by the Arduino shield, and a datasheet describing the results of some measurements for the sensors. 

To write the datasheet, a bench test must be used or built. In our project, we have used a bench test that was already at the department and that was perfect for our case.

# Physics behind the resistance change in the graphite and the flex sensors

For the graphite and the flex sensors, let’s imagine they were a 2D layer of atoms to which we could apply tension and compression. This 2D layer of atoms would have a mean distance per atom depending on the atomic arrangement. The greater these mean distance between atoms is, the more difficult it is for an electron to “jump” from one atom to another, and vice versa. When these electron “jumps” are coordinated following the same direction (for example when we apply a potential difference between the two extremes of the 2D plane), we can say that an electric current is present.

On the one hand, when a compression force is applied to that 2D layer of atoms, the atoms would get closer to each other, thus reducing the mean distance per atom, facilitating the flow of an electric current, and reducing then the resistance. 

On the other hand, when a tensile force is applied to the 2D layer of atoms, the atoms would get further apart from each other, thus increasing the mean distance per atom, making the electron “jumps” less favorable, and increasing the resistance. 

We can see in Figure 1 how the compressive and tensile forces affect the geometry of the 2D plane. When generalizing the 2D plane to a 3D thin surface, the principle of the measurement stays the same.

![Imagen1](https://github.com/MOSH-Insa-Toulouse/2023-2024-4GP-LE-BLANC--PERALES-RIOS/assets/72049530/5d65b1fc-ff74-4581-843a-14737c406238)
Figure 1: Principle of the resistance measurement for the graphite and flex sensors. Extracted from “Pencil Drawn Strain Gauges and Chemiresistors on Paper”, by Cheng-Wei et al.


# Necessary components and image of the finished project

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

![PCB_complet](https://github.com/MOSH-Insa-Toulouse/2023-2024-4GP-LE-BLANC--PERALES-RIOS/assets/72049530/649935e4-a762-47ec-a7d6-bdfd1e432b26)


# Arduino code


## OLED screen


### Potentiometer menu

In this menu, the user selects the resistance value to be given to the potentiometer by placing the cursor over the available values. The user exits the calibration menu by pressing the encoder button. 

(Insert photo of the menu)

### Flex sensor menu

In this menu, the value of the resistance and the value of the angle of the flex sensor are displayed.  

(Insert photo of the menu)

### Grpahite sensor menu

In this menu, the user can see the current value of the graphite sensor. The user exits to the main menu by pressing the encoder button.

(Insert photo of the menu)



# KiCAD PCB design

To realise our PCB we have used KiCAD under its 7.0 version.

First of all, we had to reproduce the electrical amplifier circuit (resistances, capacitors...) with a few changes and component additions. In order to adjust the gain of our circuit, we have replaced the resistance R2 by an MCP41050 digital potentiometer which can be controlled using the KY-040 rotary encoder. Then, for the realisation of the test bench we had to add some components that need to be connected to the power source, such as the flex sensor, the Bluetooth® module or the OLED screen. For that, we have created some symbols associated to the new elements. 

On the picture below, it is possible to see our complete electrical circuit realised in KiCAD with the different symbols of the components. 

![Sin título (1)](https://github.com/MOSH-Insa-Toulouse/2023-2024-4GP-LE-BLANC--PERALES-RIOS/assets/72049530/d7db149d-7aac-44d3-a966-45203cd0fb59)

Figure 2 : Complete schematic of the electrical circuit in KiCAD for the project.


Then, the second part is to realise the footprint of the PCB on KiCAD. However, all the components and the whole circuit have to fit on Arduino Uno Shield. So, the spatial arrangement must be thoughtful, while considering the 3D shape of the components and the specifications we have to follow for the PCB printing. 

For the most commons components, we've used some predefined footprints but for the others we've created some specifical footprints thanks to the software. On the pictures below, it is possible to see the global footprint of our PCB and the 3D view. 

## Amplifier circuit

The main role of the amplifier is to amplify sensor output voltages to make them measurable.

On the figure below, you can see its electrical circuit.

![image](https://github.com/MOSH-Insa-Toulouse/2023-2024-4GP-LE-BLANC--PERALES-RIOS/assets/72049530/22b4074c-a6f3-46b2-91a8-3a7a4a72a47d)

Figure 3: Schematic of the operationnal amplifier circuit in KiCAD

### LTC1050 Operationnal amplifier

The LTC1050 is the operationnal amplifier used in our amplifier circuit. 

### MCP41050 Digital potentiometer

The MCP41050 is the digital potentiometer used in our project. It varies up to 50,000 ohms depending on the command sent.
It has 8 connections pins as you can see on the next figure. 

## Graphite sensor

The graphite sensor used in our project is made from paper with a trace to be colored in with different pencils. 
In our electrical circuit, the sensor is connected between the 5V source and the positive input of the amplifier. 

(Diagram of the sensor used in the project).

## Flex sensor

The flex sensor, used for comparing the graphite-sensor measures, is mounted in a voltage divider bridge. 

![Flex_sensor](https://github.com/MOSH-Insa-Toulouse/2023-2024-4GP-LE-BLANC--PERALES-RIOS/assets/72049530/57c77a8c-33ca-4d10-ae2a-ecce92d62feb)


## KY-040 Rotary encoder

The rotary encoder is a main part of our project. It allows the user to change the selected menu, enter and exit menus by turning or pressing the encoder.
The rotary encoder has 5 pins connected to differents parts of the shield, as you can see on the figure below.  

![Encodeur_rotatoire](https://github.com/MOSH-Insa-Toulouse/2023-2024-4GP-LE-BLANC--PERALES-RIOS/assets/72049530/90a1ef97-2f27-425b-9fdc-b9fd0d33ee21)


## OLED screen

On the Arduino shield, the OLED screen is connected to 4 pins, as you can see on the figure below. 

# Android app

# Test bench

The last part of our project was to realize the test bench to acquire the datas from our sensors. 

To realize the measures, we have decided to use a test bench consisting of half-cylinders of different diameters, as you can see on the next figure.

// image bench test\\

We have tested 5 graphite-sensors, each made with a different type of pencil : 3B, 2B, B, H, 2H. 
To carry out the measurements, we placed the sensors on the various cylinders, in tension and compression. This enabled us to measure differences in resistance as a function of pencil type and deformation. 

The main results are described and presented in the graphite sensors' datasheet. 


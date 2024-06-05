# Graphite-based sensor project

## Students : Maël LE BLANC, Daniel PERALES RIOS

Département de Génie Physique

Institut National des Sciences Appliquées de Toulouse

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

- Arduino shield containing the BT module, the OLED screen...
- Arduino code for controlling the Arduino shield.
- Android app that is able to gather the data sent by the Arduino shield.
- Datasheet describing the results of some measurements for the sensors. 


To write the datasheet, a bench test must be used or built. In our project, we have used a bench test that was already at the department and that was perfect for our case.

# Physics behind the resistance change in the graphite and the flex sensors

For the graphite and the flex sensors, let’s imagine they were a 2D layer of atoms to which we could apply tension and compression. This 2D layer of atoms would have a mean distance per atom depending on the atomic arrangement. The greater these mean distance between atoms is, the more difficult it is for an electron to “jump” from one atom to another, and vice versa. When these electron “jumps” are coordinated following the same direction (for example when we apply a potential difference between the two extremes of the 2D plane), we can say that an electric current is present. When this happens, it is called "percolation".

On the one hand, when a compression force is applied to that 2D layer of atoms, the atoms would get closer to each other, thus reducing the mean distance per atom, facilitating the flow of an electric current, and reducing then the resistance. 

On the other hand, when a tensile force is applied to the 2D layer of atoms, the atoms would get further apart from each other, thus increasing the mean distance per atom, making the electron “jumps” less favorable, and increasing the resistance. 

We can see in figure 1 how the compressive and tensile forces affect the geometry of the 2D plane. When generalizing the 2D plane to a 3D thin surface, the principle of the measurement stays the same.

![Imagen1](https://github.com/MOSH-Insa-Toulouse/2023-2024-4GP-LE-BLANC--PERALES-RIOS/assets/72049530/5d65b1fc-ff74-4581-843a-14737c406238)

Figure 1: Principle of the resistance measurement for the graphite and flex sensors. Extracted from “Pencil Drawn Strain Gauges and Chemiresistors on Paper”, by Cheng-Wei et al.


# Necessary components and image of the finished project

In figure 2, the finished project, with all the components mounted on the shield, is showed. The only component that not mounted in the shield is the Bluetooth module, since what we thought to be a connection error was blocking the Arduino code from running.

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

Figure 2: Image of the complete project. The Bluetooth module is mounted on a separate Arduino breadboard, but this does not have any impact on the functioning of the program.

# Arduino code

The logic behind the Arduino program can be found in the logic chart in figure 3.

![bP9DRXin34RtEWMHLN85UvFunudH6WtgvW2CXl2ebIX1efAwHUzUIPunCi1iiZ3WaSZtFWgyJu9HihDAZ5Y2v-X_ae3689IZKkrQgSMH98UbMkpPY45h_X1exu9dOac0t44md4h1WmZg7eYrxoY2OQ4OSv1fxxUlsqthIXJBKMMvp4QZ6CzBfTvxOmbk7He-4ESxC0bkpvJk5C1YOr (1)](https://github.com/MOSH-Insa-Toulouse/2023-2024-4GP-LE-BLANC--PERALES-RIOS/assets/72049530/8321e4d1-a773-4e3a-b967-f35e9f0d8d79)

Figure 3: Logic chart for the Arduino code, that shows what are the main procedures and methods and what the code mainly does.

The is a main menu with three options, and the user can choose between each of these three options: the potentiometer, the flex sensor and the graphite sensor. These menus are showed below.

### Potentiometer menu

In this menu, the user selects the resistance value to be given to the potentiometer by placing the cursor over the available values. The user exits the calibration menu by pressing the encoder button. 

![IMG_1833](https://github.com/MOSH-Insa-Toulouse/2023-2024-4GP-LE-BLANC--PERALES-RIOS/assets/72049530/c86bfd6d-c473-4c29-aedd-c9c60b768446)

Figure 4: Potentiometer menu.

### Flex sensor menu

In this menu, the value of the resistance and the value of the angle of the flex sensor are displayed.  

![IMG_1834](https://github.com/MOSH-Insa-Toulouse/2023-2024-4GP-LE-BLANC--PERALES-RIOS/assets/72049530/1083f118-864a-41ad-b2f6-cd2d5c15ebec)

Figure 5: Flex sensor menu.

### Grpahite sensor menu

In this menu, the user can see the current value of the graphite sensor. The user exits to the main menu by pressing the encoder button.

![IMG_1835](https://github.com/MOSH-Insa-Toulouse/2023-2024-4GP-LE-BLANC--PERALES-RIOS/assets/72049530/0f888522-1073-4606-b248-1ee0906b1bc2)

Figure 6: Graphite sensor menu.

# KiCAD PCB design

To realise our PCB we have used KiCAD under its 7.0 version.

First of all, we had to reproduce the electrical amplifier circuit (resistances, capacitors...) with a few changes and component additions. In order to adjust the gain of our circuit, we have replaced the resistance R2 by an MCP41050 digital potentiometer which can be controlled using the KY-040 rotary encoder. Then, for the realisation of the test bench we had to add some components that need to be connected to the power source, such as the flex sensor, the Bluetooth® module or the OLED screen. For that, we have created some symbols associated to the new elements. 

On figure 7, it is possible to see our complete electrical circuit realised in KiCAD with the different symbols of the components. 

![Sin título (1)](https://github.com/MOSH-Insa-Toulouse/2023-2024-4GP-LE-BLANC--PERALES-RIOS/assets/72049530/d7db149d-7aac-44d3-a966-45203cd0fb59)

Figure 7 : Complete schematic of the electrical circuit in KiCAD for the project.


Then, the second part is to realise the footprint of the PCB on KiCAD. However, all the components and the whole circuit have to fit on Arduino Uno Shield. So, the spatial arrangement must be thoughtful, while considering the 3D shape of the components and the specifications we have to follow for the PCB printing. 

For the most commons components, we've used some predefined footprints but for the others we've created some specifical footprints thanks to the software. All the footprints can be found in the KiCAD folder.

## Amplifier circuit

The main role of the amplifier is to amplify sensor output voltages to make them measurable.

On figure 8 can be seen the electrical circuit of the amplifier.

![image](https://github.com/MOSH-Insa-Toulouse/2023-2024-4GP-LE-BLANC--PERALES-RIOS/assets/72049530/22b4074c-a6f3-46b2-91a8-3a7a4a72a47d)

Figure 8: Schematic of the operationnal amplifier circuit in KiCAD.

### LTC1050 Operationnal amplifier

The LTC1050 is the operationnal amplifier used in our amplifier circuit, than can be observed in figure 9.

![DIP-8](https://github.com/MOSH-Insa-Toulouse/2023-2024-4GP-LE-BLANC--PERALES-RIOS/assets/72049530/9779b100-5de5-48d5-8db4-3b4e4fddeefa)

Figure 9: LTC1050 operational amplifier.

### MCP41050 Digital potentiometer

The MCP41050 is the digital potentiometer used in our project. It varies up to 50,000 ohms depending on the command sent.
It has 8 connections pins as can be seen in figure 10. 

![Microchip-MCP41050-I_SN-image](https://github.com/MOSH-Insa-Toulouse/2023-2024-4GP-LE-BLANC--PERALES-RIOS/assets/72049530/a2f528a6-c030-491e-9876-67a0d771acc9)

Figure 10: MCP41050 digital potentiometer.

## Graphite sensor

The graphite sensor used in our project is made from paper with a trace to be colored in with different pencils. 
In our electrical circuit, the sensor is connected between the 5V (Vcc) source and the positive input of the amplifier (Vout), as can be seen in figure 11.

![Graphite_sensor](https://github.com/MOSH-Insa-Toulouse/2023-2024-4GP-LE-BLANC--PERALES-RIOS/assets/72049530/16bf690d-2f42-4ac8-a104-3a38da477129)

Figure 11: Schematic for the graphite sensor. Extracted from Niels Brun and Paul Besnard's GitHub site.


## Flex sensor

The flex sensor, used for comparing the graphite-sensor measures, is mounted in a voltage divider bridge. 

![Flex_sensor](https://github.com/MOSH-Insa-Toulouse/2023-2024-4GP-LE-BLANC--PERALES-RIOS/assets/72049530/57c77a8c-33ca-4d10-ae2a-ecce92d62feb)

Figure 12: Flex sensor. 

## KY-040 Rotary encoder

The rotary encoder is a main part of our project. It allows the user to change the selected menu, enter and exit menus by turning or pressing the encoder.
The rotary encoder has 5 pins connected to differents parts of the shield, as you can see on figure 13.  

![Encodeur_rotatoire](https://github.com/MOSH-Insa-Toulouse/2023-2024-4GP-LE-BLANC--PERALES-RIOS/assets/72049530/90a1ef97-2f27-425b-9fdc-b9fd0d33ee21)

Figure 13: Rotary encoder KY-040.

## OLED screen

On the Arduino shield, the OLED screen is connected to 4 pins, as you can see on figure 14.

![OLED_screen](https://github.com/MOSH-Insa-Toulouse/2023-2024-4GP-LE-BLANC--PERALES-RIOS/assets/72049530/1159e612-ad18-43d1-9c8d-d024195a0167)

Figure 14: The OLED screen, with 4 pins.

# Android app

The Android app has been coded using MIT's app inventor. In figures 15, 16 can be seen the code blocks for the Android app. 

![Code_blocks_app (1)](https://github.com/MOSH-Insa-Toulouse/2023-2024-4GP-LE-BLANC--PERALES-RIOS/assets/72049530/1a01e3fb-8526-4573-971d-22bba30600ec)

![Code_blocks_app (2)](https://github.com/MOSH-Insa-Toulouse/2023-2024-4GP-LE-BLANC--PERALES-RIOS/assets/72049530/e7ef99da-4fc3-4af5-a332-3d98066dadcd)

Figure 15: Code blocks for the Android app. 

Moreover, we have coded an improved version of the program with a login function, whose code appears in figure 16.

![Code_blocks_app_with_login (1)](https://github.com/MOSH-Insa-Toulouse/2023-2024-4GP-LE-BLANC--PERALES-RIOS/assets/72049530/9a0fd5f0-699d-4b53-a44a-c031073ffaeb)

![Code_blocks_app_with_login (2)](https://github.com/MOSH-Insa-Toulouse/2023-2024-4GP-LE-BLANC--PERALES-RIOS/assets/72049530/bd2f84ec-7919-46e4-9384-131d989c585e)

Figure 16: Code blocks for the Android app with the login function.

Next, in figures 17 and 18 are presented the data capture screen and the login screen, respectively.

![App_screen](https://github.com/MOSH-Insa-Toulouse/2023-2024-4GP-LE-BLANC--PERALES-RIOS/assets/72049530/e0e7354a-53f9-485d-a92e-41cd40fe97f5)

Figure 17: Data capture screen.

![App_screen_with_login](https://github.com/MOSH-Insa-Toulouse/2023-2024-4GP-LE-BLANC--PERALES-RIOS/assets/72049530/0c334be4-91e5-4867-9e5b-5f8786bf9b32)

Figure 18: Login screen.

# Test bench

The last part of our project was to realize the test bench to acquire the data from our sensors. 

To realize the measures, we have decided to use a test bench consisting of semi-cylinders going from 2 to 5 cm in diameter, with steps of 0.5 cm in between each semi-cylinder, as you can see on figure 19.

![Bench_test](https://github.com/MOSH-Insa-Toulouse/2023-2024-4GP-LE-BLANC--PERALES-RIOS/assets/72049530/e06a162e-13c2-42fb-a930-fb24063e44d7)

Figure 19: Test bench used.

We have tested 5 graphite-sensors, each made with a different type of pencil : 3B, 2B, B, H, 2H. 
To carry out the measurements, we placed the sensors on the various cylinders, in tension and compression, as can be seen respectively in figures 20 and 21. This enabled us to measure differences in resistance as a function of pencil type and deformation. 

![Deformation_tension](https://github.com/MOSH-Insa-Toulouse/2023-2024-4GP-LE-BLANC--PERALES-RIOS/assets/72049530/5b5fe1e5-2fde-4161-aca8-79e347c75b0c)

Figure 20: Deformation in tension.

![Deformation_compression](https://github.com/MOSH-Insa-Toulouse/2023-2024-4GP-LE-BLANC--PERALES-RIOS/assets/72049530/ebaba703-e45a-429a-bacf-cb0fce856f94)

Figure 21: Deformation in compression.

In figure 22 the results for the flex sensor in tension are showed. 

![Deformation_tension_flex](https://github.com/MOSH-Insa-Toulouse/2023-2024-4GP-LE-BLANC--PERALES-RIOS/assets/72049530/c671544d-74f5-486a-b064-83e683de38e2)

Figure 22: Results for the flex sensor, in tension.

The complete results are described and presented in the graphite sensors' datasheet, available in the Datasheet folder.

With our results it is found that the softer the pencil is (in our case, 3B is the softer pencil), the less sensitive it is. This is the same conclusion, saving the distance, of Wei et al. in “Pencil Drawn Strain Gauges and Chemiresistors on Paper”.

For any question concerning our sensor project, please contact: perales@insa-toulouse.fr / m_leblan@insa-toulouse.fr


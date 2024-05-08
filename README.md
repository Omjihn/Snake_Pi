<h1 align="center">
	SNAKE_PI
</h1>
A simple Snake game made for Raspberry Pi GPIO.

![Snake_pi](https://github.com/Omjihn/Snake_Pi/assets/110061001/0068a5ed-5672-4b53-8684-9e7eae9487fc)


### Components list:

 - Raspberry Pi (with 40 GPIO) x1
 - GPIO Extention board + Ribbon cable x1
 - Breadboard (see the schema below for the dimentions) x1
 - Jumper wire x36
 - 74HC595 chip x2
 - 8x8 LED matrix x1
 - Resistor 220Ω x8

### Electrical schema:

Place all the components and wires on your breadboard. Please double-check all the wiring.

![electrical_schema](https://github.com/Omjihn/Snake_Pi/assets/110061001/8c364ce9-8228-436f-8baf-d248833c8bf9)

### Software dependencies:

 - WiringPi: C library made for controlling the Raspberry GPIO pins. Follow the instructions in the [official_repo](https://github.com/WiringPi/WiringPi) to install it.

 - Make: Used for automate the compilation process. To install it on RaspberryOS:

      ```
      sudo apt install make
      ```

 - c++: Compiler used by the Makefile. To install it on RaspberryOS:

      ```
      sudo apt install clang
      ```

### Build the program:

 - At the root of the repository, execute the following command:

      ```
      make
      ```
 - Then start the program:

      ```
      ./Snake
      ```

### Controls:

 - To control the Snake press the arrow keys on your keyboard.

 - To quit press 'q'.

The Snake should appear on the top left of the LED matrix. Make sure you are looking at the correct angle.
The program will display your current score, and at the end, your final score.

### Have fun !

# HobbyLoader

A simple bootloader me and friends wrote during 2018 in C and asm for educational purposes. Now a little updated and finally uploaded on my GitHub. It loads a basic kernel from disk and transfers control to it.

## Features

- Loads a kernel from the boot sector
- Switches from real mode to protected mode
- Sets up a Global Descriptor Table (GDT)
- Initializes an Interrupt Descriptor Table (IDT)
- Provides a simple kernel with basic video output

## License

This project is licensed under the MIT License. See the LICENSE file for details.

Copy code

Feel free to customize this README further to fit the specifics and goals of your project.

## Building the Project

To build the project, run:

```sh
make


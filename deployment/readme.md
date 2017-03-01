
# Deployment

## STEP 1: Run the VDM generator

Lets download the latest:

```
wget http://overture.au.dk/into-cps/vdm-tool-wrapper/development/latest/fmu-import-export.jar
```

Then let generate the VDM model to a source code FMU:

```
java -jar fmu-import-export.jar -export tool -name wtct -output . -root Models/SingleWT/
```

This produces a `wtct.fmu` zip file. We need to extract it and place the content of the `sources` folder in `deployment/ATMega128-target-code/generated/`

```
mkdir temp
cd temp
unzip ../wtct.fmu
cp sources/* ../deployment/ATMega128-target-code/generated/
```

## STEP 2: Add a new custom `main`

in this case we added `main.c`


## STEP 3: Compile the code for the target

Make sure you have the required dependencies for linux these are: 

* `gcc-avr` - AVR GNU GCC compiler
* `binutils-avr` - AVR binary tools
* `avr-libc` - AVR C library
* `avrdude` - Firmware uploader

Also make sure you actually checked out the submodules:

```
git submodule update --init
```

Run this to generate the make file:

```
cd ATMega128-target-code
cmake -DCMAKE_TOOLCHAIN_FILE=../cmake-avr/generic-gcc-avr.cmake .
```

```
-- The C compiler identification is GNU 4.8.2
-- The CXX compiler identification is GNU 4.8.2
-- Check for working C compiler: /usr/bin/avr-gcc
-- Check for working C compiler: /usr/bin/avr-gcc -- works
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/avr-g++
-- Check for working CXX compiler: /usr/bin/avr-g++ -- works
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Current uploadtool is: avrdude
-- Current programmer is: avrispmkII
-- Current upload port is: usb
-- Current uploadtool options are: 
-- Current MCU is set to: atmega1284p
-- Current H_FUSE is set to: 0xd9
-- Current L_FUSE is set to: 0xc3
-- Set CMAKE_FIND_ROOT_PATH to /usr/lib/avr
-- Set CMAKE_SYSTEM_INCLUDE_PATH to /usr/lib/avr/include
-- Set CMAKE_SYSTEM_LIBRARY_PATH to /usr/lib/avr/lib
-- Configuring done
-- Generating done
-- Build files have been written to: /.../deployment/ATMega128-target-code
```

Now you can compile the sources with: 

```
make
```

```
-- The C compiler identification is GNU 4.8.2
-- The CXX compiler identification is GNU 4.8.2
-- Check for working C compiler: /usr/bin/avr-gcc
-- Check for working C compiler: /usr/bin/avr-gcc -- works
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/avr-g++
-- Check for working CXX compiler: /usr/bin/avr-g++ -- works
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Current uploadtool is: avrdude
-- Current programmer is: avrispmkII
-- Current upload port is: usb
-- Current uploadtool options are: 
-- Current MCU is set to: atmega1284p
-- Current H_FUSE is set to: 0xd9
-- Current L_FUSE is set to: 0xc3
-- Set CMAKE_FIND_ROOT_PATH to /usr/lib/avr
-- Set CMAKE_SYSTEM_INCLUDE_PATH to /usr/lib/avr/include
-- Set CMAKE_SYSTEM_LIBRARY_PATH to /usr/lib/avr/lib
-- Configuring done
-- Generating done
-- Build files have been written to: /.../deployment/ATMega128-target-code
parallels@ubuntu:/.../deployment/ATMega128-target-code$ make
-- Current uploadtool is: avrdude
-- Current programmer is: avrispmkII
-- Current upload port is: usb
-- Current uploadtool options are: 
-- Current MCU is set to: atmega1284p
-- Current H_FUSE is set to: 0xd9
-- Current L_FUSE is set to: 0xc3
-- Set CMAKE_FIND_ROOT_PATH to /usr/lib/avr
-- Set CMAKE_SYSTEM_INCLUDE_PATH to /usr/lib/avr/include
-- Set CMAKE_SYSTEM_LIBRARY_PATH to /usr/lib/avr/lib
-- Configuring done
-- Generating done
...
[ 90%] Building C object CMakeFiles/watertank-atmega1284p.elf.dir/main.c.obj
[ 93%] Building C object CMakeFiles/watertank-atmega1284p.elf.dir/adcutil.c.obj
Linking C executable watertank-atmega1284p.elf
[ 93%] Built target watertank-atmega1284p.elf
Scanning dependencies of target watertank
[ 96%] Generating watertank-atmega1284p.hex
AVR Memory Usage
----------------
Device: atmega1284p

Program:   24868 bytes (19.0% Full)
(.text + .data + .bootloader)

Data:        444 bytes (2.7% Full)
(.data + .bss + .noinit)


[100%] Generating watertank-atmega1284p-eeprom.hex
[100%] Built target watertank
```


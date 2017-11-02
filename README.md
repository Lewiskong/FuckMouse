# FuckMouse
A program use keyboard to substitute mouse . Support MACOS/Windows/Linux 

# Library Build
The program need a dynamic lib
to build the lib. Use :

```
    cd mouselib/
    mkdir build
    cd build/
    cmake ..
    make
    mv libmouse.dylib /usr/local/lib
```

# Build

```
    cd src/
    mkdir build
    cd build/
    cmake ..
    make
```

# Run
    `./FuckMouse`

# Usage
    Press Alt + W/S/A/D to manipulate the mouse to move towards up/down/left/right direction.
    Press Alt + Q/E to scroll upwards/downwards
    Press Alt + J/K/L/; to simulate left/right/double/triple click






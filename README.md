# SpeedMeet
Tactile programmable HMI for work meetings time control

This is not a plug&play project. To be able to flash the target board
(STM32F769i-DISCO), the user needs to: 

a) Install TouchGFX 4.1.13
b) Open TouchGFX Designer and create an empty app with the template for 
   STM32F769i-DISCO
c) Click the "Generate Code" tab in TouchGFX Designer
d) Copy the files tracked with this repository into the exact same files
   of the directory created by the TouchGFX application
   (the only different one will be the one with .touchgfx extension, which 
    you'll have to replace by the .touchgfx file tracked with this repo)

-- By now you should be able to use the TouchGFX Designer Simulator if you don't have
a physical board. If you do and want to flash it, the following still needs to be done: 

e) Open the STM32CubeIDE project within the STM32CubeIDE dir in the project dir
f) Eliminate all missing/corrupted files from within the IDE (when you try to build
   the errors will give you the name of such files anyway)

--You're finally ready to go

# SpeedMeet
Tactile programmable HMI for work meetings time control

Developped with TouchGFX Designer 4.13.0 for an STM32F769i-DISCO target.
The HMI can be simulated without the HW board via TouchGFX designer.
To do so, the following needs to be done: 

a) Install TouchGFX 4.13.0

b) Open TouchGFX Designer and create an empty app with the template for 
   STM32F769i-DISCO

c) Click the "Generate Code" tab in TouchGFX Designer

d) Copy the files tracked with this repository into the exact same files
   of the directory created by the TouchGFX application
   (the only file with a different name will be the one with .touchgfx extension, 
    which you'll have to replace anyway)

-- The application can then be exported to another HW project, (c.f.touchGFX support docs)
   or ported on an STM32F769i-DISCO board by doing the following

e) Open the STM32CubeIDE project within the STM32CubeIDE dir in the project dir

f) Eliminate all missing/corrupted files from within the IDE (when you try to build
   the errors will give you the name of such files anyway)

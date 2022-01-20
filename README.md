# zen_flute
FACTORY PROGRAMS
moogmodelzen: moog type synthesizer firmware for the zen flute hardware (www.museelectronicinstruments.com)
using the teensy audio library.  This is what arrives when the Zen flute is shipped. 

ZenGUI: programming interface for the moogmodelzen firmware using the Processing Language (https://processing.org/) and ControlP5 (https://sojamo.de/libraries/controlP5/) that lets you change the programming of the Zen flute without altering the firmware.  Run this on a separate computer connected to the Zen Flute.  You will need to download Processing to compile this.

EXPERIMENTAL PROGRAMS
physicalmodelzen: physically modeled flute firmware based on Faust programming language
--flute.cpp and flute.h needed as libraries.  Sounds a bit like a shakuhachi.  See Faust https://faustide.grame.fr/

(1) Zenproxax6.ino is a teesyduino sax model using libraries sax.h and sax.cpp  
(2) Zenprobass1.ino is teesyduino bass guitar model using libraries guitarMIDI.h and guitarMIDI.cpp.  
(3) Zenproflute3 is another flute model using flute.cpp and flute.h.  All of these models came from https://faustide.grame.fr/ and the programs use the teensy audio library framework https://www.pjrc.com/teensy/td_libs_Audio.html. Zenprosax6.pde is a programming interface in processing for procedural models (1)-(3).


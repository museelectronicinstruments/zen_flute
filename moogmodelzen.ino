

//C-Major Tomemon Mouth Theramin Low RF version (FCC approved)
// teensy 4.0/usb serial, midi, audio 600MHz
// Helmholtz resonator tracker with ppl and synth,

// //***************************MIT Software License*******************************
//Copyright (c) 2021 Keith Baxter (info@museelectronicinstruments.com)
//
//Permission is hereby granted, free of charge, to any person obtaining a copy
//of this software and associated documentation files (the "Software"), to deal
//in the Software without restriction, including without limitation the rights
//to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//copies of the Software, and to permit persons to whom the Software is
//furnished to do so, subject to the following conditions:
//
//The above copyright notice and this permission notice shall be included in all
//copies or substantial portions of the Software.
//
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//SOFTWARE.

//************************** End of MIT License*******************************

//This license is not a hardware license nor an implied license to hardware.
//Please support Muse Electronic Instruments (MEI) in its mission to offer
//innovative electronic instruments by purchasing the Zen Flute and other MEI products.  Thanks.


//***************************************
// libraries and global variables
//***************************************

// The following are synthesizer blocks setup with a graphical
// tool described at pjrc.com/teensy/td_libs_Audio.html
// copying the following into the tool will generate a graphical
// layout of this synth.

#if !defined(ARDUINO_TEENSY40)
#error "Please Select Teensy 4.0 Board Type"
#endif

#if !defined(SERIAL)
#error "USB MIDI not enabled. Please set USB type to 'Serial'."
#endif

#include <EEPROM.h>

#include <Audio.h>
#include <Wire.h>


// GUItool: begin automatically generated code
AudioSynthWaveformSine   sine1;          //xy=86.66666412353516,822.9999974668026
AudioSynthWaveformDc     dc1;            //xy=86.66666412353516,860.9999974668026
AudioSynthWaveformDc     dc7;            //xy=87.66666412353516,611.9999974668026
AudioSynthWaveformSine   sine5;          //xy=86.66666412353516,899.9999974668026
AudioSynthWaveformSine   sine4;          //xy=89.66666412353516,412.9999974668026
AudioSynthWaveformSine   sine2;          //xy=90.66666412353516,253.9999974668026
AudioSynthWaveformDc     dc3;            //xy=90.66666412353516,373.9999974668026
AudioSynthWaveformDc     dc5;            //xy=88.66666412353516,938.9999974668026
AudioSynthWaveformSine   sine8;          //xy=90.66666412353516,649.9999974668026
AudioSynthWaveformDc     dc8;            //xy=90.66666412353516,686.9999974668026
AudioSynthWaveformDc     dc4;            //xy=91.66666412353516,452.9999974668026
AudioSynthWaveformSine   sine6;          //xy=91.66666412353516,491.9999974668026
AudioSynthWaveformDc     dc6;            //xy=91.66666412353516,531.9999974668026
AudioSynthWaveformSine   sine7;          //xy=91.66666412353516,572.9999974668026
AudioSynthWaveformSine   sine3;          //xy=92.66666412353516,335.9999974668026
AudioSynthWaveformDc     dc2;            //xy=93.66666412353516,296.9999974668026
AudioSynthSimpleDrum     drum1;          //xy=90.66666412353516,1047.9999974668026
AudioSynthWaveformDc     glide5;         //xy=90.66666412353516,1464.9999974668026
AudioSynthWaveformDc     glide2;         //xy=91.66666412353516,1336.9999974668026
AudioSynthSimpleDrum     drum3;          //xy=92.66666412353516,1123.9999974668026
AudioSynthWaveformDc     glide1;         //xy=92.66666412353516,1295.9999974668026
AudioSynthSimpleDrum     drum2;          //xy=93.66666412353516,1085.9999974668026
AudioSynthWaveformDc     glide3;         //xy=92.66666412353516,1378.9999974668026
AudioSynthWaveformDc     chordglide4;    //xy=91.66666412353516,1667.9999974668026
AudioSynthWaveformDc     chordglide5;    //xy=91.66666412353516,1704.9999974668026
AudioSynthSimpleDrum     drum4;          //xy=94.66666412353516,1162.9999974668026
AudioSynthSimpleDrum     drum5;          //xy=94.66666412353516,1200.9999974668026
AudioSynthWaveformDc     chordglide3;    //xy=93.66666412353516,1628.9999974668026
AudioSynthWaveformDc     glide4;         //xy=94.66666412353516,1423.9999974668026
AudioSynthWaveform       waveform1;      //xy=101.66666412353516,103.9999974668026
AudioSynthWaveform       waveform3;      //xy=101.66666412353516,190.9999974668026
AudioSynthWaveform       waveform2;      //xy=102.66666412353516,147.9999974668026
AudioSynthWaveformDc     chordglide2;    //xy=97.66666412353516,1589.9999974668026
AudioSynthWaveformDc     chordglide1;    //xy=98.66666412353516,1548.9999974668026
AudioSynthWaveformDc     chordglide0;    //xy=100.66666412353516,1507.9999974668026
AudioSynthWaveformDc     dc9;            //xy=122.66665649414062,1775.9999771118164
AudioEffectMultiply      multiply6;      //xy=235.66666412353516,512.9999974668026
AudioEffectMultiply      multiply4;      //xy=238.66666412353516,432.9999974668026
AudioEffectMultiply      multiply2;      //xy=239.66666412353516,275.9999974668026
AudioEffectMultiply      multiply3;      //xy=239.66666412353516,354.9999974668026
AudioSynthKarplusStrong  string3;        //xy=238.66666412353516,758.9999974668026
AudioSynthKarplusStrong  string2;        //xy=238.66666412353516,797.9999974668026
AudioEffectMultiply      multiply7;      //xy=239.66666412353516,593.9999974668026
AudioSynthKarplusStrong  string4;        //xy=239.66666412353516,717.9999974668026
AudioSynthKarplusStrong  string1;        //xy=238.66666412353516,978.9999974668026
AudioEffectMultiply      multiply5;      //xy=248.66666412353516,921.9999974668026
AudioEffectMultiply      multiply8;      //xy=250.66666412353516,664.9999974668026
AudioEffectMultiply      multiply1;      //xy=251.66666412353516,864.9999974668026
AudioAnalyzePeak         peak1;          //xy=291.6666564941406,1778.9999771118164
AudioEffectEnvelope      envelope1;      //xy=310.66666412353516,104.9999974668026
AudioEffectEnvelope      envelope2;      //xy=310.66666412353516,148.9999974668026
AudioEffectEnvelope      envelope3;      //xy=312.66666412353516,191.9999974668026
AudioMixer4              dummy2;         //xy=307.66666412353516,1507.9999974668026
AudioMixer4              dummy;          //xy=314.66666412353516,1370.9999974668026
AudioMixer4              dummy3;         //xy=313.66666412353516,1640.9999974668026
AudioMixer4              drum_mixer1;    //xy=338.66666412353516,1093.9999974668026
AudioMixer4              drum_mixer2;    //xy=341.66666412353516,1203.9999974668026
AudioMixer4              dulcimermixer2; //xy=449.66666412353516,636.9999974668026
AudioMixer4              dulcimermixer3; //xy=454.66666412353516,750.9999974668026
AudioMixer4              dulcimermixer1; //xy=470.66666412353516,389.9999974668026
AudioMixer4              dulcimermixer4; //xy=475.66666412353516,906.9999974668026
AudioFilterStateVariable melody_filter;  //xy=516.6666641235352,99.9999974668026
AudioFilterStateVariable harmony_filter2; //xy=520.6666641235352,211.9999974668026
AudioFilterStateVariable harmony_filter1; //xy=522.6666641235352,155.9999974668026
AudioFilterStateVariable drum_filter;    //xy=526.6666641235352,1098.9999974668026
AudioMixer4              harmony_mixer;  //xy=757.6666641235352,151.9999974668026
AudioMixer4              dulcimermixer5; //xy=766.6666641235352,385.9999974668026
AudioSynthSimpleDrum     rain_drum2;     //xy=1018.6666641235352,1018.9999974668026
AudioSynthSimpleDrum     rain_drum1;     //xy=1025.6666641235352,959.9999974668026
AudioSynthNoisePink      pink1;          //xy=1024.6666641235352,1335.9999974668026
AudioSynthSimpleDrum     rain_drum3;     //xy=1029.6666641235352,1076.9999974668026
AudioSynthSimpleDrum     rain_drum4;     //xy=1036.6666641235352,1130.9999974668026
AudioSynthSimpleDrum     rain_drum5;     //xy=1037.6666641235352,1190.9999974668026
AudioSynthSimpleDrum     rain_drum6;     //xy=1038.6666641235352,1237.9999974668026
AudioSynthSimpleDrum     rain_drum7;     //xy=1038.6666641235352,1288.9999974668026
AudioMixer4              synth_selector; //xy=1085.6666641235352,280.9999974668026
AudioSynthWaveform       shimmerwaveform5; //xy=1099.6666641235352,629.9999974668026
AudioSynthWaveform       shimmerwaveform6; //xy=1100.6666641235352,679.9999974668026
AudioSynthWaveform       shimmerwaveform7; //xy=1100.6666641235352,725.9999974668026
AudioSynthWaveform       shimmerwaveform8; //xy=1100.6666641235352,771.9999974668026
AudioSynthWaveform       shimmerwaveform4; //xy=1101.6666641235352,583.9999974668026
AudioSynthWaveform       shimmerwaveform1; //xy=1103.6666641235352,447.9999974668026
AudioSynthWaveform       shimmerwaveform2; //xy=1103.6666641235352,489.9999974668026
AudioSynthWaveform       shimmerwaveform3; //xy=1103.6666641235352,536.9999974668026
AudioMixer4              rain_mixer1;    //xy=1273.6666641235352,1009.9999974668026
AudioMixer4              rain_mixer2;    //xy=1275.6666641235352,1225.9999974668026
AudioMixer4              shimmermixer2;  //xy=1327.6666641235352,687.9999974668026
AudioMixer4              shimmermixer1;  //xy=1331.6666641235352,516.9999974668026
AudioMixer4              rain_mixer3;    //xy=1463.6666641235352,991.9999974668026
AudioMixer4              shimmermixer3;  //xy=1536.6666641235352,534.9999974668026
AudioFilterStateVariable rain_filter1;   //xy=1647.6666641235352,988.9999974668026
AudioEffectFlange        shimmerchorusL; //xy=1746.6666641235352,515.9999974668026
AudioEffectFlange        shimmerchorusR; //xy=1759.6666641235352,280.9999974668026
AudioEffectFreeverbStereo reverb;         //xy=2042.6666641235352,375.9999974668026
AudioMixer4              reverb_mixer_L; //xy=2105.666664123535,239.9999974668026
AudioMixer4              reverb_mixer_R; //xy=2120.666664123535,482.9999974668026
AudioOutputUSB           usb1;           //xy=2291.666664123535,313.9999974668026
AudioOutputI2S           audio_output;   //xy=2297.666664123535,377.9999974668026
AudioConnection          patchCord1(sine1, 0, multiply1, 0);
AudioConnection          patchCord2(dc1, 0, multiply1, 1);
AudioConnection          patchCord3(dc7, 0, multiply7, 1);
AudioConnection          patchCord4(sine5, 0, multiply5, 0);
AudioConnection          patchCord5(sine4, 0, multiply4, 0);
AudioConnection          patchCord6(sine2, 0, multiply2, 0);
AudioConnection          patchCord7(dc3, 0, multiply3, 1);
AudioConnection          patchCord8(dc5, 0, multiply5, 1);
AudioConnection          patchCord9(sine8, 0, multiply8, 0);
AudioConnection          patchCord10(dc8, 0, multiply8, 1);
AudioConnection          patchCord11(dc4, 0, multiply4, 1);
AudioConnection          patchCord12(sine6, 0, multiply6, 0);
AudioConnection          patchCord13(dc6, 0, multiply6, 1);
AudioConnection          patchCord14(sine7, 0, multiply7, 0);
AudioConnection          patchCord15(sine3, 0, multiply3, 0);
AudioConnection          patchCord16(dc2, 0, multiply2, 1);
AudioConnection          patchCord17(drum1, 0, drum_mixer1, 0);
AudioConnection          patchCord18(glide5, 0, dummy2, 0);
AudioConnection          patchCord19(glide2, 0, dummy, 1);
AudioConnection          patchCord20(drum3, 0, drum_mixer1, 2);
AudioConnection          patchCord21(glide1, 0, dummy, 0);
AudioConnection          patchCord22(drum2, 0, drum_mixer1, 1);
AudioConnection          patchCord23(glide3, 0, dummy, 2);
AudioConnection          patchCord24(chordglide4, 0, dummy3, 2);
AudioConnection          patchCord25(chordglide5, 0, dummy3, 3);
AudioConnection          patchCord26(drum4, 0, drum_mixer2, 0);
AudioConnection          patchCord27(drum5, 0, drum_mixer2, 1);
AudioConnection          patchCord28(chordglide3, 0, dummy3, 1);
AudioConnection          patchCord29(glide4, 0, dummy, 3);
AudioConnection          patchCord30(waveform1, envelope1);
AudioConnection          patchCord31(waveform3, envelope3);
AudioConnection          patchCord32(waveform2, envelope2);
AudioConnection          patchCord33(chordglide2, 0, dummy3, 0);
AudioConnection          patchCord34(chordglide1, 0, dummy2, 2);
AudioConnection          patchCord35(chordglide0, 0, dummy2, 1);
AudioConnection          patchCord36(dc9, peak1);
AudioConnection          patchCord37(multiply6, 0, dulcimermixer1, 3);
AudioConnection          patchCord38(multiply4, 0, dulcimermixer1, 2);
AudioConnection          patchCord39(multiply2, 0, dulcimermixer1, 0);
AudioConnection          patchCord40(multiply3, 0, dulcimermixer1, 1);
AudioConnection          patchCord41(string3, 0, dulcimermixer3, 2);
AudioConnection          patchCord42(string2, 0, dulcimermixer3, 3);
AudioConnection          patchCord43(multiply7, 0, dulcimermixer2, 0);
AudioConnection          patchCord44(string4, 0, dulcimermixer3, 1);
AudioConnection          patchCord45(string1, 0, dulcimermixer4, 3);
AudioConnection          patchCord46(multiply5, 0, dulcimermixer4, 2);
AudioConnection          patchCord47(multiply8, 0, dulcimermixer2, 1);
AudioConnection          patchCord48(multiply1, 0, dulcimermixer4, 1);
AudioConnection          patchCord49(envelope1, 0, melody_filter, 0);
AudioConnection          patchCord50(envelope2, 0, harmony_filter1, 0);
AudioConnection          patchCord51(envelope3, 0, harmony_filter2, 0);
AudioConnection          patchCord52(drum_mixer1, 0, drum_filter, 0);
AudioConnection          patchCord53(drum_mixer2, 0, drum_mixer1, 3);
AudioConnection          patchCord54(dulcimermixer2, 0, dulcimermixer5, 1);
AudioConnection          patchCord55(dulcimermixer3, 0, dulcimermixer5, 2);
AudioConnection          patchCord56(dulcimermixer1, 0, dulcimermixer5, 0);
AudioConnection          patchCord57(dulcimermixer4, 0, dulcimermixer5, 3);
AudioConnection          patchCord58(melody_filter, 0, harmony_mixer, 0);
AudioConnection          patchCord59(harmony_filter2, 0, harmony_mixer, 2);
AudioConnection          patchCord60(harmony_filter1, 0, harmony_mixer, 1);
AudioConnection          patchCord61(drum_filter, 0, synth_selector, 3);
AudioConnection          patchCord62(harmony_mixer, 0, synth_selector, 0);
AudioConnection          patchCord63(dulcimermixer5, 0, synth_selector, 2);
AudioConnection          patchCord64(rain_drum2, 0, rain_mixer1, 1);
AudioConnection          patchCord65(rain_drum1, 0, rain_mixer1, 0);
AudioConnection          patchCord66(pink1, 0, rain_mixer2, 3);
AudioConnection          patchCord67(rain_drum3, 0, rain_mixer1, 2);
AudioConnection          patchCord68(rain_drum4, 0, rain_mixer1, 3);
AudioConnection          patchCord69(rain_drum5, 0, rain_mixer2, 0);
AudioConnection          patchCord70(rain_drum6, 0, rain_mixer2, 1);
AudioConnection          patchCord71(rain_drum7, 0, rain_mixer2, 2);
AudioConnection          patchCord72(synth_selector, 0, reverb_mixer_L, 0);
AudioConnection          patchCord73(synth_selector, reverb);
AudioConnection          patchCord74(synth_selector, 0, reverb_mixer_R, 0);
AudioConnection          patchCord75(shimmerwaveform5, 0, shimmermixer2, 0);
AudioConnection          patchCord76(shimmerwaveform6, 0, shimmermixer2, 1);
AudioConnection          patchCord77(shimmerwaveform7, 0, shimmermixer2, 2);
AudioConnection          patchCord78(shimmerwaveform8, 0, shimmermixer2, 3);
AudioConnection          patchCord79(shimmerwaveform4, 0, shimmermixer1, 3);
AudioConnection          patchCord80(shimmerwaveform1, 0, shimmermixer1, 0);
AudioConnection          patchCord81(shimmerwaveform2, 0, shimmermixer1, 1);
AudioConnection          patchCord82(shimmerwaveform3, 0, shimmermixer1, 2);
AudioConnection          patchCord83(rain_mixer1, 0, rain_mixer3, 0);
AudioConnection          patchCord84(rain_mixer2, 0, rain_mixer3, 1);
AudioConnection          patchCord85(shimmermixer2, 0, shimmermixer3, 1);
AudioConnection          patchCord86(shimmermixer1, 0, shimmermixer3, 0);
AudioConnection          patchCord87(rain_mixer3, 0, rain_filter1, 0);
AudioConnection          patchCord88(shimmermixer3, shimmerchorusR);
AudioConnection          patchCord89(shimmermixer3, shimmerchorusL);
AudioConnection          patchCord90(rain_filter1, 0, reverb_mixer_R, 2);
AudioConnection          patchCord91(rain_filter1, 0, reverb_mixer_L, 2);
AudioConnection          patchCord92(shimmerchorusL, 0, reverb_mixer_R, 3);
AudioConnection          patchCord93(shimmerchorusR, 0, reverb_mixer_L, 3);
AudioConnection          patchCord94(reverb, 0, reverb_mixer_L, 1);
AudioConnection          patchCord95(reverb, 1, reverb_mixer_R, 1);
AudioConnection          patchCord96(reverb_mixer_L, 0, audio_output, 0);
AudioConnection          patchCord97(reverb_mixer_L, 0, usb1, 0);
AudioConnection          patchCord98(reverb_mixer_R, 0, audio_output, 1);
AudioConnection          patchCord99(reverb_mixer_R, 0, usb1, 1);
// GUItool: end automatically generated code


//pin assignments Teensy 4.0
const int LEDpin = 13;
const int micInputPin = A0; //mouth microphone
const int mouthSpkrOutput = 12; //mouth speaker output pwm 12 for new RF verson, 15 otherwise
const int closeButton = 2;  //hardware is A2
const int middleButton = 1;
const int farButton = 0;
const int redPin = 5;
const int bluePin = 6;
const int greenPin = 8;
const int modePin = A9;
const int monitorPin = 4;
int WhammyPin = 17;

//********************************************************************
// Acoustic Volume Processor Settings
//********************************************************************

bool USB_Midi_on = true;

const float chromatic[59] = {98.00, 103.83, 110.00, 116.54, 123.47, 130.81, 138.59, 146.83, 155.56, 164.81, 174.61,
                             185.00, 196.00, 207.65, 220.00, 233.08, 246.94, 261.63, 277.18, 293.66,
                             311.13, 329.63, 349.23, 369.99, 392.00, 415.30, 440.00, 466.16, 493.88,
                             523.25, 554.37, 587.33, 622.25, 659.25, 698.46, 739.99, 783.99, 830.61,
                             880.00, 932.33, 987.77, 1046.50, 1108.73, 1174.66, 1244.51, 1318.51,
                             1396.91, 1479.98, 1567.98, 1661.22, 1760.00, 1864.66, 1975.53, 2093.00,
                             2217.46, 2349.32, 2489.02, 2637.02, 2793.83,
                            };

const int midiconvert[59] = {43, 44, 45, 46, 47, 48, 49, 50, 51, 52,
                             53, 54, 55, 56, 57, 58, 59, 60, 61, 62,
                             63, 64, 65, 66, 67, 68, 69, 70, 71, 72,
                             73, 74, 75, 76, 77, 78, 79, 80, 81, 82,
                             83, 84, 85, 86, 87, 88, 89, 90, 91, 92,
                             93, 94, 95, 96, 97, 98, 99, 100, 101,
                            };

int scalefilter[31] = {2, 4, 5, 7, 9, 10, 12, 14, 16, 17, 19, 21, 22, 24, 26,
                       28, 29, 31, 33, 34, 36, 38, 40, 41, 43, 45, 46, 48, 41, 41, 41
                      }; //cmaj

int scale_type = 0;

//maps chromatic to midi numbers
const int midifilter1[31] = {45, 47, 48, 50, 52, 53, 55, 57, 59, 60, 62, 64, 65, 67, 69,
                             71, 72, 74, 76, 77, 79, 81, 83, 84, 86, 88, 46, 48, 41, 41, 41
                            }; //cmaj
                          
//maps between chromatic and different scales
const int scalefilter1[31] = {2, 4, 5, 7, 9, 10, 12, 14, 16, 17, 19, 21, 22, 24, 26,
                              28, 29, 31, 33, 34, 36, 38, 40, 41, 43, 45, 46, 48, 41, 41, 41
                             }; //cmaj

const int scalefilter2[31] = {2, 5, 7, 9, 12, 14, 17, 19, 21, 24, 24, 26, 29, 31, 33, 36,
                              38, 41, 43, 45, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41
                             }; //c petatonic


const int scalefilter3[31] = { 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24,
                               25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42
                             }; //chromatic

const int scalefilter4[31] = {1, 3, 6, 11, 13, 15, 18, 20, 23, 25, 27, 30, 32, 35, 37, 39,
                              40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40,
                             }; //BLACK KEYS

float rootfreq = 0;
float thirdfreq = 0;
float fifthfreq = 0;
float secondfreq = 0;
float sixthfreq = 0;
float target1 = 0;
float target2 = 0;
float target3 = 0;
//float target4 = 0;
//float target5 = 0;

float justifiedtarget1 = 0;
float justifiedtarget2 = 0;
float justifiedtarget3 = 0;

//LUT for mouthspeaker volume

int closestLUTnumber = 0;


//*******Sampling ISR variables and objects*******
// Create an IntervalTimer object to call buffer ISR
IntervalTimer samplingTimer;
const int BUFSIZE = 300;//610;
static volatile int h;  //buffferindex
static volatile int drivebuffer[BUFSIZE];
static volatile int micbuffer[BUFSIZE];
static volatile byte micval, driveval, monitorval;
static volatile int duration = 0;
static float sineincrement = 1;
static float monitorsineincrement = 1;
static unsigned long ISRlasttime = 0;
//https://www.wolframalpha.com/input/?i=table+round%28127*%28sin%282*pi*t%2F100%29%2B1%29%29+from+0+to+99
const int16_t sinetable[100] = {127, 135, 143, 151, 159, 166, 174, 181, 188,
                                195, 202, 208, 214, 220, 225, 230, 234, 238, 242, 245, 248, 250, 252, 253,
                                254, 254, 254, 253, 252, 250, 248, 245, 242, 238, 234, 230, 225, 220, 214,
                                208, 202, 195, 188, 181, 174, 166, 159, 151, 143, 135, 127, 119, 111, 103,
                                95, 88, 80, 73, 66, 59, 52, 46, 40, 34, 29, 24, 20, 16, 12, 9, 6, 4, 2, 1,
                                0, 0, 0, 1, 2, 4, 6, 9, 12, 16, 20, 24, 29, 34, 40, 46, 52, 59, 66, 73, 80,
                                88, 95, 103, 111, 119
                               };
static bool earliest = true;
static int risingedge = 0;


//phase lock variables
//25 array elements

//yellow #1

// bool phasegainboost = 0;
// bool volumeboost = 0;
//float phasegainset[25] = {4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
//                          5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 3, 3, 3
//                         };
//float derivativegainset[25] = { 0, 0, 0, 0, 0, 0, 0, 0,
//                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
//                              };
//float phasetargetset[25] = {.1, .1, .1, .1, .1, .11, .12, .13, .14, .15,
//                            .16, .17, .17, .18, .18, .19, .19, .20, .20, .21, .27, .1, .1, .1, .1
//                           };
//
//float speakergainset[25] = {0.01, 0.06, 0.06, 0.06, 0.05, 0.04, 0.03, 0.03, 0.02, 0.03, 0.02, 0.02,
//
//0.01, 0.03, 0.04, 0.05, 0.09, 0.14, 0.14, 0.14, 0.14, 0.01, 0.01, 0.01, 0.01 };


////margaret aqua
//
//bool phasegainboost = 0;
// bool volumeboost = 0;
//float phasegainset[25] = {5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
//                          5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 3, 3, 3
//                         };
//float derivativegainset[25] = { 0, 0, 0, 0, 0, 0, 0, 0,
//                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
//                              };
//float phasetargetset[25] = {.1, .1, .1, .1, .1, .11, .12, .13, .14, .15,
//                            .16, .17, .17, .18, .18, .19, .19, .20, .20, .21, .27, .1, .1, .1, .1
//                           };
//
//
//float speakergainset[25] = {0.01, 0.32, 0.30, 0.21, 0.20, 0.20, 0.17, 0.12, 0.10, 0.06, 0.08, 0.05,
//                            0.04, 0.03, 0.03, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01,
//                           };

////margaret yellow
//bool phasegainboost=0;
//// bool volumeboost = 0;
//float phasegainset[25] = {5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
//                          5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 3, 3, 3
//                         };
//float derivativegainset[25] = { 0, 0, 0, 0, 0, 0, 0, 0,
//                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
//                              };
//float phasetargetset[25] = {.1, .1, .1, .1, .1, .11, .12, .13, .14, .15,
//                            .16, .17, .17, .18, .18, .19, .19, .20, .20, .21, .27, .1, .1, .1, .1
//                           };
//
//float speakergainset[25] = {.01, .01, .01, .01, .01, .01, .01, .01, .01, .01,
//                            .01, .01, .01, .01, .01, .01, .01, .01, .01, .01, .01, .01, .01, .01, .01
//                            };

//float phasegainset[25] = {10.00, 10.00, 10.00, 10.00, 7.73, 4.84, 6.05, 10.00, 10.00, 10.00, 10.00, 4.49,
//10.00, 10.00, 10.00, 10.00, 10.00, 10.00, 10.00, 10.00, 10.00, 10.00, 3.00, 3.00, 0.00,


////orange big mouth
//bool phasegainboost = 0;
//bool volumeboost = 0;
//
//float phasegainset[25] = {5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
//                         5, 5, 6, 6, 6, 6, 7, 8, 9, 10, 10, 103, 3, 3
//                         }; // orange
//
//float derivativegainset[25] = { 0, 0, 0, 0, 0, 0, 0, 0,
//                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
//                              };
//float phasetargetset[25] = {.10, .11, .12, .13, .14, .15, .16, .17, .18, .19,
//                            .21, .22, .23, .26, .28, .32, .32, .32, .32, .32, .32, .32, .32, .5, .4
//                           };
//
//float speakergainset[25] = {0.16, 0.25, 0.08, 0.08, 0.06, 0.04, 0.04, 0.02, 0.01, 0.01, 0.01, 0.01,
//
//0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.16, 0.16,
//                           };

//yellow #2 up to date

bool phasegainboost = 0;
bool volumeboost = 0;
float phasegainset[25] = {4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
                          5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 3, 3, 3
                         };
float derivativegainset[25] = { 0, 0, 0, 0, 0, 0, 0, 0,
                                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
                              };
float phasetargetset[25] = {0.10, 0.11, 0.12, 0.07, 0.10, 0.10, 0.10, 0.10, 0.10, 0.10, 0.10, 0.10,

                            0.10, 0.10, 0.10, 0.10, 0.10, 0.10, 0.10, 0.10, 0.10, 0.32, 0.32, 0.50, 0.40,
                           };

float speakergainset[25] = {0.16, 0.30, 0.20, 0.20, 0.20, 0.20, 0.14, 0.12, 0.11, 0.09, 0.09, 0.06,

                            0.06, 0.05, 0.05, 0.03, 0.03, 0.03, 0.03, 0.03, 0.07, 0.04, 0.04, 0.16, 0.16,

                           };
float phasegain = 3;

float derivativegain = 0;
float phasetarget = .25;
float speakergain = .01;
float phaseshift = 0;
float phaseshift2 = 0;
float phaseshiftdegrees = 0;
float phaseerror = 0;
float previousphaseerror = 0;
float phaseerrordegrees = 0;
float lastphaseerror = 0;
float drivefrequency = 880;
int lastdrivefrequency = 0;
float proportional = 0; //PPL gain block proportional term
float derivative = 0; //PPL gain block derivative term
float fderivative = 0;
int tuningband = 0; //coarse bins for tuning as function of pitch
float boost = 0;



//gain boost variables
unsigned long lastcheck;
float lastfrequency;
float slopemagnitude = 0;
int gaincorrect = 0;
unsigned long boosttimeout = 0;


int tempdrivebuffer[BUFSIZE];
int tempmicbuffer[BUFSIZE];
int startdrive = 0;
float averagemic = 0;
float microphonelevel = 0;
int startmic = 0;
int endmic = 0;
bool found = false;
int lastsample = 0;
float sinelength = 0;
bool capture = false;

// curvefitting variables for finding zero crossings accurately in noise
float ymean = 0;
float xmean = 0;
float lineslopenumerator = 0;
float lineslopedenominator = 0;
float lineslope = 0;
float yintercept = 0;
float precisemicstart = 0;
float precisemicend = 0;



// autoadjust AGC variables
const float SCALESIZE = 28; //number of notes that can be identified (!todo bigger?
const float TOPFREQ = chromatic[45]; //highest frequncy in scale was 1318 hz
const float BOTTOMFREQ = chromatic[27]; //lowest note is 523 hz  /was 25

//closest-note  variables
float closestfrequency = 0;
int closestscalenumber = 0;

//float delta = 0;
//float floatdelta = 0;
float driveerror = 9999;
//float floatdriveerror = 0;

//hysteresis
int hyster_closest_scale_number = 0;
float hysterclosestnote = 0;
int hyster_last_closest_scale_number = 0;
//int closest_chromatic_note_number = 0;
bool newnote = 0;
int hysterpreviousplayednotenumber1 = 0;
int hysterpreviousplayednotenumber2 = 0;
int hysterpreviousplayednotenumber3 = 0;
int hysteresisamount = 5; //smaller is more hysteresis  1/5 here
//int phasestyle = 0;






//////////////////////////////////////
//shimmer and shimmer drum cartridges
/////////////////////////////////////

float shimmer[3];
float shimmer1[3];
float shimmer2[3];
float shimmer3[3];
float shimmer4[3];
float shimmer1_1[3] = {523.25, 659.25, 783.99}; //c
float shimmer2_1[3] = {698.46, 880.00, 1046.50};//f
float shimmer3_1[3] = {392.00, 493.88, 587.33};//g
float shimmer4_1[3] = {440.00, 523.25, 659.25};//am

float shimmer1_2[3] = {523.25, 659.25, 783.99};//c
float shimmer2_2[3] = {587.33, 698.46, 880};//dm
float shimmer3_2[3] = {329.63, 392.00, 493.88};//em
float shimmer4_2[3] = {440.00, 523.25, 659.25};//am

float shimmer1_3[3] = {329.63, 392.00, 493.88};//em
float shimmer2_3[3] = {698.46, 880.00, 1046.50};//f
float shimmer3_3[3] = {392.00, 493.88, 587.33};//g
float shimmer4_3[3] = {440.00, 523.25, 659.25};//am

float shimmer1_4[3] = {523.25, 659.25, 783.99};//c
float shimmer2_4[3] = {698.46, 880.00, 1046.50};//f
float shimmer3_4[3] = {392.00, 493.88, 587.33};//g
float shimmer4_4[3] = {587.33, 698.46, 880};//dm

//////////////////////////////////////
//chord progression list chord
/////////////////////////////////////

int chordprogression1[24];
int chordprogression2[24];
int chordprogression3[24];
int chordprogression4[24];

int progressionlength = 0;

int progressionlength1 = 0; //last 0 based index
int progressionlength2 = 0;
int progressionlength3 = 0;
int progressionlength4 = 0;

int chordprogression1A[24] =  {0, 0, 1, 1, 0, 0, 3, 3, 3, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99}; //first chord button
int chordprogression2A[24] =  {0, 1, 3, 1, 1, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99}; //first chord button
int chordprogression3A[24] =  {2, 3, 1, 2, 3, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99}; //first chord button
int chordprogression4A[24] =  {1, 1, 1, 1, 1, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99}; //first chord button
int progressionlength1A = 7; //last 0 based index
int progressionlength2A = 15;
int progressionlength3A = 5;
int progressionlength4A = 5;

int chordprogression1B[24] =  {0, 2, 3, 1, 0, 1, 2, 3, 0, 2, 3, 1, 0, 1, 2, 3, 99, 99, 99, 99, 99, 99, 99, 99}; //first chord button
int chordprogression2B[24] =  {2, 1, 2, 3, 1, 0, 2, 3, 1, 0, 2, 3, 0, 2, 3, 1, 99, 99, 99, 99, 99, 99, 99, 99}; //first chord button
int chordprogression3B[24] =  {0, 2, 3, 1, 0, 2, 3, 1, 0, 2, 3, 1, 0, 2, 3, 1, 99, 99, 99, 99, 99, 99, 99, 99}; //first chord button
int chordprogression4B[24] =  {1, 1, 1, 1, 1, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99}; //first chord button
int progressionlength1B = 15; //last 0 based index
int progressionlength2B = 15;
int progressionlength3B = 5;
int progressionlength4B = 5;



//////////////////////////////////////
//universal chord cartridges  string/chord/song
/////////////////////////////////////

int chordcart1[24];  //immediate chord list
int chordcart2[24];
int chordcart3[24];
int chordcart1A[24]; //runtime chord family
int chordcart2A[24];
int chordcart3A[24];
int chordcart1B[24];
int chordcart2B[24];
int chordcart3B[24];
int chordcart1C[24];
int chordcart2C[24];
int chordcart3C[24];
int chordcart1D[24];
int chordcart2D[24];
int chordcart3D[24];


//song 1
//C
int chordcart1A_1[24] =  {17,  21, 24, 21, 17, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99}; //cmaj first chord button
int chordcart2A_1[24] =  {99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99};
int chordcart3A_1[24] =  {99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99};
int chordcartsize1 = 5;
//F
int chordcart1B_1[24] =  {10, 14, 17, 14, 22, 17, 26, 22, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99}; //fmaj second chord button
int chordcart2B_1[24] =  {99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99};
int chordcart3B_1[24] =  {99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99};
//G
int chordcart1C_1[24] =  {12,  16, 19, 19, 24, 19, 16, 12, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99}; //gmajthird chord button
int chordcart2C_1[24] =  {99, 99, 99, 99, 99, 12, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99};
int chordcart3C_1[24] =  {99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99};
//Am
int chordcart1D_1[24] =  {14, 17, 21, 26, 21, 17, 14, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99}; //amin fourth chord button
int chordcart2D_1[24] =  {99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99};
int chordcart3D_1[24] =  {99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99};


//song 2
//C
int chordcart1A_2[24] =  {17, 5, 12, 17, 5, 17, 5, 12, 12, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99}; //cmaj first chord button
int chordcart2A_2[24] =  {21, 99, 21, 21, 17, 21, 17, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99};
int chordcart3A_2[24] =  {12, 9, 17, 12, 33, 9, 99, 33, 34, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99};
int chordcartsize2 = 8;
//F
int chordcart1B_2[24] =  {10, 17, 17, 10, 2, 17, 22, 26, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99};//fmaj second chord button
int chordcart2B_2[24] =  {14, 22, 14, 14, 22, 5, 10, 14, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99};
int chordcart3B_2[24] =  {17, 26, 10, 17, 99, 19, 5, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99};
//G
int chordcart1C_2[24] =  {12, 4, 19, 12, 19, 99, 24, 12, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99}; //gmajthird chord button
int chordcart2C_2[24] =  {16, 16, 16, 16, 16, 12, 12, 16, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99};
int chordcart3C_2[24] =  {19, 7, 12, 19, 12, 99, 7, 19, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99};
//Am
int chordcart1D_2[24] =  {14, 2, 21, 14, 2, 14, 2, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99}; //amin fourth chord button
int chordcart2D_2[24] =  {17, 14, 17, 17, 14, 17, 14, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99};
int chordcart3D_2[24] =  {21, 99, 14, 21, 99, 21, 26, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99};


//song 3
//C
int chordcart1A_3[24] =  {12, 28, 24, 16, 24, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99}; //cmaj first chord button
int chordcart2A_3[24] =  {99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99};
int chordcart3A_3[24] =  {99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99};
int chordcartsize3 = 5;
//F
int chordcart1B_3[24] =  {21, 24, 28, 12, 16, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99}; //fmaj second chord button
int chordcart2B_3[24] =  {99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99};
int chordcart3B_3[24] =  {99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99};
//G
int chordcart1C_3[24] =  {24, 21, 9, 28, 21, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99}; //gmajthird chord button
int chordcart2C_3[24] =  {99, 99, 99, 99, 99, 12, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99};
int chordcart3C_3[24] =  {99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99};
//Em
int chordcart1D_3[24] =  {12, 16, 12, 21, 9, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99}; //amin fourth chord button
int chordcart2D_3[24] =  {99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99};
int chordcart3D_3[24] =  {99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99};



//////////////////////////////////////
//drum cartridges  drum /song number eg 1_1
/////////////////////////////////////

//these are the input variables for the drum and rhythm player--load as needed
bool drumcartridge1[24];
bool drumcartridge2[24];
bool drumcartridge3[24];
bool drumcartridge4[24];
bool drumcartridge5[24];
bool drumcartridge6[24];


//********************************************************************
// UI variables
//********************************************************************


bool cherry1 = false;
bool cherry2 = false;
bool cherry3 = false;
bool do1once = false;
bool do2once = false;
bool do3once = false;
unsigned long bouncetimerA1 = 0;
unsigned long bouncetimerB1 = 0;
unsigned long bouncetimerA2 = 0;
unsigned long bouncetimerB2 = 0;
unsigned long bouncetimerA3 = 0;
unsigned long bouncetimerB3 = 0;

unsigned long offtimer = 0;
bool modebutton = false;
unsigned long bouncetimer3 = 0;
int modecount = 1; //start at 1 to signal eeprom empty when 0
int lastmodecount = 1;
unsigned long uncolor = 0;

//fadein varialbles
int keycounter = 0;
//int startdrums = 2;
//int enddrums = 7;
//int endchords = 5;
//int timeout = 10;
int playstate = 0;
unsigned long deadmantimer = 0;
int fivenotes = 0;
int fadeintime = 10000;
int fadeouttime = 5000;

bool drumplay = true;
bool stringchordplay = true;
bool shimmerplay = true;
bool tonechordplay = true;



bool initializeme = false;
bool firsttimesetup = true;
//bool specialprint1 = false;
//bool specialprint2 = false;

bool button1toggle = true;
bool button2toggle = true;
bool button3toggle = true;
bool justonce = true; //part of sleep timer
unsigned long sticktimer = 0;
bool stickoverride = 0;
float locktarget1 = 0;
float locktarget2 = 0;
float locktarget3 = 0;

bool instantbeat = false;
bool cherry1truetoggle = true;
bool cherry2truetoggle = true;
bool cherry3truetoggle = true;
bool cherry1falsetoggle = true;
bool cherry2falsetoggle = true;
bool cherry3falsetoggle = true;
int  binarystate = 0;
int  lastbinarystate = 6;
bool binarystatetoggle0 = false;
bool binarystatetoggle1 = false;
bool binarystatetoggle2 = false;
bool binarystatetoggle3 = false;




long int measures = 0;
bool firstplay = false;
int progressionmeasures = 0;
bool progressiontoggle = false;
int chordselection = 0;
int lastchordselection = 0;
bool switchup = 0;

//********************************************************************
// Debugging variables
//********************************************************************

unsigned long last_time = millis();
//tuner program
int forceMode = 4; //uses whammypot to set PPL variables
float phasetargetforced = .25;
float phasegainforced = .25;
float drivefrequencyforced = 880;
float derivativegainforced = 0;
float AGCsmoothforced = 1;
float whammyfrequency = 0;

bool LEDtoggle = false;
int displayMode = 0; //0 is synth control, 1 is drum; 2 is save, 3 is debug
bool drumpreview = 0;
unsigned long profiledelta = 0;
unsigned long profiletimer = 0;
bool onetime = true;
//print variables and profiling values
unsigned long printusec = 0;//
unsigned long printusec2 = 0;//
unsigned long printusec3 = 0;//
unsigned long lastprintusec = 0;
unsigned long lastprintusec2 = 0;
bool printscreen = true;


//sweeping variables (for testing only)
int sweepy = 440;
unsigned long usec = 0;//special variable that increments on microseconds
unsigned long lastusec = 0;
unsigned long usec2 = 0;//special variable that increments on microseconds
unsigned long lastusec2 = 0;

//********************************************************************
// Misc variables
//********************************************************************

//sleep timer when not played in a while
unsigned long sleeptimer = 0;
bool woken = false;
bool wokenstall = false;
unsigned long wokentime = 0;
bool lastwoken = true;
bool nochord = true;

//monitor variables
float monitorgain = 1;
float performancegain = 1;

//LUT for monitor volume//not used right now
const float volumecurve[49] =
{ .05, .05, .05, .05, .05, .05, .05, .05, .05, .05,
  .05, .05, .05, .05, .05, .05, .05, .05, .05, .05,
  .05, .05, .05, .05, .05, .05, .05, .05, .05, .05,
  .05, .05, .05, .05, .05, .05, .05, .05, .05, .05,
  .05, .05, .05, .05, .05, .05, .05, .05, .05,
};


//float monitorvolume = 0;

//********************************************************************
// Common synthesizer variables
//********************************************************************

float glide_rate = 50; //glide maps all notes to range of 0-1
float reverb_wet = 0.2;

int buttonlogic = 0;
bool notetoggle1 = false;
bool notetoggle2 = false;
bool notetoggle3 = false;

//float synth_selection0 = 1;
//float synth_selection1 = 0;
//float synth_selection2 = 0;
//float synth_selection3 = 0;


float reverb_size = 0.9;
float reverb_damping = 0.999;

float rain_gain = 0;
float shimmer_gain = 0;
int shimmerchord = 0;

float harmony1_gain = 0;
float harmony2_gain = 0;

float mel_string_gain = 0;
float mel_string_octave = 0;
float harm_string_gain = 0;
float harm_string_octave = 0;

//********************************************************************
// Harmony Synthesizer Variables
//********************************************************************

float melody_octave = 2;

float harmony_mixer0 = .5;
float harmony_mixer1 = .5;
float harmony_mixer2 = .5;
//float harmony_mixer3 = .5;
//float harmony_mixer4 = .5;
//float harmony_mixer5 = .5;

float string_mixer0 = .2;
float string_mixer1 = .2;
float string_mixer2 = .2;

float drum_volume1 = .3;
float drum_volume2 = .3;
float drum_volume3 = .3;
float drum_volume4 = .3;
float drum_volume5 = .3;
float drum_volume6 = .3;

int drumMIDI1=71;
int drumMIDI2=72;
int drumMIDI3=73;
int drumMIDI4=74;
int drumMIDI5=75;

//float StringOctave = 1;

int melody_shape = 0;
float M_filterFrequency = 1000;
float M_filterResonance = 1;
float M_filterGain = 1;

float H1_filterFrequency = 1000;
float H1_filterResonance = 1;
float H1_filterGain = 1;

float H2_filterFrequency = 1000;
float H2_filterResonance = 1;
float H3_filterGain = 1;

float harmony1_octave = 2;
int harmony1_shape = 0;
float harmony2_octave = 2;
int harmony2_shape = 0;

//Melody ADSR
float M_attackTime = 20; //millis
float M_decayTime = 1000;
float M_sustainLevel = 1; //-1 to 1
float M_releaseTime = 10;

//Harmony ADSR
float HA_attackTime = 20;
float HA_decayTime = 100;
float HA_sustainLevel = 1;
float HA_releaseTime = 100;

float HB_attackTime = 20;
float HB_decayTime = 100;
float HB_sustainLevel = 1;
float HB_releaseTime = 100;

float HC_attackTime = 20;
float HC_decayTime = 100;
float HC_sustainLevel = 1;
float HC_releaseTime = 100;


float droneVolume = 0;
int lastdroneVolume = 0;
float droneFreq = 261;
float transpose = 1;
bool drumnotes = true;
bool arp_on = true;

//Note Timing
//bool noteTrigFlag[8];
//unsigned long attackWait[8];
short waveShapes[6] = {
  WAVEFORM_SINE,
  WAVEFORM_TRIANGLE,
  WAVEFORM_TRIANGLE_VARIABLE,
  WAVEFORM_SAWTOOTH,
  WAVEFORM_SQUARE,
  WAVEFORM_PULSE,
};

//********************************************************************
// Euclid Rhythm Variables
//********************************************************************

bool euclid[50]; //output of euclid function then tranwsfered to below arrays

int notetarget = 0;
//float noteclimb = 0;

bool euclid_on = 0;
int unisonclock = 0;
int unisonclock2 = 0;
int euclidclock1 = 0;
int euclidclock2 = 0;
int euclidclock3 = 0;
int euclidclock4 = 0;
int euclidclock5 = 0;
int euclidclock6 = 0;

int peuclidclock1 = 0;
int peuclidclock2 = 0;
int peuclidclock3 = 0;
int peuclidclock4 = 0;
int peuclidclock5 = 0;
int peuclidclock6 = 0;

int offsetnumber = 0;
int drum_mode = 1;
unsigned long next = 0;
unsigned long fnext = 0;
bool beattoggle = true; //flashes light
int drumtoggle1 = 0; //sequences different euclids
//drum preview
unsigned long pnext = 0;

int espeed = 300;

int bins = 0;
int beats = 0;


bool euclid_timing = 0;

int bins1 = 16;
int beats1 = 5;
int offsetnumber1 = 0;
int clump1 = 0;
int bins2 = 12;
int beats2 = 2;
int offsetnumber2 = 0;
int clump2 = 0;
int bins3 = 16;
int beats3 = 10;
int offsetnumber3 = 0;
int clump3 = 0;
int bins4 = 16;
int beats4 = 5;
int offsetnumber4 = 0;
int clump4 = 0;
int bins5 = 12;
int beats5 = 2;
int offsetnumber5 = 0;
int clump5 = 0;
int bins6 = 16;
int beats6 = 10;
int offsetnumber6 = 0;
int clump6 = 0;

int chrom_ref = 0;

bool chromatic_lock = 0; //cartridge numbers indicate chromatic notes

int chord_cartridge_number = 0;
int shimmer_cartridge_number = 0;
int  prog_cartridge_number = 0;

int savelocation = 0;
int lastsavelocation = 0;

//********************************************************************
// Factory preset Variables
//********************************************************************

bool EEPROMsource = false;
byte byteparameter[106] =
{
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0
};
int integerinput[106];


//factorypresets


bool updatetoggle = false;

byte factorypreset1[105] = //blank
{
  0, 60, 102, 0, 0, 255, 25, 0, 0, 0, 255, 4, 0, 51, 25, 10, 255, 25, 102, 0, 0,

  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 1, 0, 1,

  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,

  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,

  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 100,

  50, 5, 10, 0,


};

byte factorypreset2[105] = //ruby
{
  0, 1, 76, 0, 0, 0, 0, 100, 2, 0, 0, 2, 0, 25, 85, 10, 255, 85, 255, 0, 0,

  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,

  1, 0, 0, 0, 0, 0, 0, 0, 0, 76, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,

  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,

  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 100,

  50, 5, 10, 0,
};

byte factorypreset3[105] = //rose
{
  0, 20, 51, 1, 0, 0, 20, 100, 0, 0, 0, 4, 1, 51, 85, 10, 255, 25, 255, 0, 0,

  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,

  0, 0, 0, 0, 0, 0, 0, 0, 0, 76, 15, 63, 0, 140, 255, 12, 4, 0, 6, 76,

  1, 0, 0, 255, 12, 4, 0, 0, 8, 102, 0, 127, 51, 12, 2, 0, 0, 127, 1, 0,

  140, 102, 12, 5, 1, 0, 12, 191, 0, 112, 255, 12, 3, 0, 0, 12, 6, 1, 1, 100,

  50, 5, 10, 0,


};



byte factorypreset4[105] = //shamrock
{
  0, 30, 51, 0, 1, 0, 0, 0, 2, 0, 0, 3, 1, 51, 127, 10, 255, 85, 127, 3, 1,

  51, 170, 10, 255, 85, 51, 3, 1, 51, 170, 10, 255, 85, 51, 0, 12, 3, 0, 2, 0,

  2, 0, 0, 0, 5, 0, 0, 0, 0, 76, 15, 63, 0, 140, 0, 12, 4, 0, 0, 76,

  1, 0, 0, 0, 12, 4, 0, 0, 8, 102, 0, 127, 0, 12, 3, 0, 0, 127, 1, 0,

  140, 0, 4, 1, 0, 0, 12, 191, 0, 112, 0, 4, 1, 0, 0, 4, 6, 0, 0, 10,

  50, 5, 10, 0,
};

byte factorypreset5[105] = //sun
{
  0, 10, 51, 0, 1, 0, 0, 0, 0, 0, 0, 5, 1, 51, 25, 10, 255, 25, 0, 3, 0,

  51, 85, 10, 255, 25, 0, 3, 0, 51, 85, 10, 255, 25, 0, 0, 127, 3, 127, 3, 0,

  4, 0, 0, 0, 2, 0, 0, 0, 0, 102, 15, 63, 0, 140, 2, 8, 2, 0, 0, 76,

  1, 0, 0, 15, 3, 1, 0, 0, 8, 102, 0, 127, 0, 3, 1, 0, 0, 127, 1, 0,

  140, 10, 3, 3, 0, 0, 12, 191, 5, 112, 0, 4, 2, 1, 0, 3, 0, 1, 0, 0,

  50, 5, 10, 0,



};



byte factorypreset6[105] = //artic
{
  0, 10, 76, 0, 1, 0, 0, 0, 0, 0, 0, 2, 1, 51, 51, 10, 255, 2, 102, 3, 0,

  76, 1, 10, 255, 25, 76, 3, 0, 76, 1, 10, 255, 25, 76, 0, 20, 3, 12, 4, 1,

  5, 0, 0, 0, 0, 0, 0, 0, 0, 102, 15, 63, 0, 140, 0, 12, 4, 0, 0, 76,

  1, 0, 0, 0, 12, 4, 0, 0, 8, 102, 0, 127, 0, 12, 3, 0, 0, 127, 1, 0,

  140, 5, 4, 1, 0, 0, 12, 191, 0, 112, 25, 12, 3, 0, 0, 4, 6, 0, 0, 100,

  50, 5, 10, 0,


};

byte factorypreset7[105] = //pumpkin
{
  0, 20, 51, 0, 1, 0, 0, 0, 0, 0, 0, 4, 1, 51, 25, 10, 255, 25, 127, 3, 0,

  51, 85, 10, 255, 25, 12, 3, 0, 51, 85, 10, 255, 25, 12, 0, 12, 3, 51, 3, 0,

  1, 0, 0, 0, 5, 0, 0, 0, 0, 76, 15, 63, 0, 140, 12, 12, 4, 0, 0, 76,

  1, 0, 0, 5, 12, 4, 0, 0, 8, 102, 0, 127, 5, 12, 3, 0, 0, 127, 1, 0,

  140, 12, 4, 1, 0, 0, 12, 191, 0, 112, 12, 4, 1, 0, 0, 4, 6, 0, 0, 100,

  50, 7, 10, 0,
};
byte factorypreset8[105] = //lapis
{

  0, 20, 25, 0, 1, 0, 0, 0, 0, 0, 0, 2, 3, 25, 51, 10, 255, 25, 255, 3, 0,

  51, 85, 10, 255, 25, 0, 3, 0, 51, 85, 10, 255, 25, 0, 0, 51, 4, 51, 4, 0,

  1, 0, 0, 0, 1, 0, 0, 0, 0, 51, 15, 63, 0, 140, 12, 12, 5, 1, 2, 76,

  1, 0, 0, 12, 6, 2, 4, 3, 8, 102, 0, 127, 5, 3, 1, 0, 0, 127, 1, 0,

  140, 12, 6, 3, 0, 0, 12, 191, 0, 112, 12, 12, 5, 0, 0, 3, 3, 0, 3, 100,

  50, 7, 20, 0,
};

//byte factorypreset8[105] = //orchid
//{ 0, 20, 51, 0, 1, 0, 0, 0, 0, 0, 0, 4, 1, 51, 25, 10, 255, 25, 127, 2, 0,
//
//  51, 85, 10, 255, 25, 12, 2, 0, 51, 85, 10, 255, 25, 12, 0, 12, 3, 51, 3, 0,
//
//  1, 0, 0, 0, 2, 0, 0, 0, 0, 25, 15, 63, 0, 140, 0, 12, 1, 0, 0, 76,
//
//  1, 0, 0, 0, 12, 4, 0, 0, 8, 102, 0, 127, 0, 12, 3, 0, 0, 127, 1, 0,
//
//  140, 102, 12, 2, 0, 0, 12, 191, 0, 112, 0, 12, 1, 0, 0, 12, 4, 0, 0, 100,
//
//  50, 7, 10, 0,
//};

byte factorypreset9[105] = //porcelain
{
  0, 10, 76, 0, 1, 0, 0, 0, 0, 0, 0, 3, 1, 76, 2, 10, 255, 2, 102, 3, 0,

  51, 85, 10, 255, 25, 0, 3, 0, 51, 85, 10, 255, 25, 0, 0, 51, 4, 51, 4, 1,

  7, 0, 0, 0, 1, 0, 0, 0, 0, 76, 15, 63, 0, 140, 0, 12, 5, 1, 2, 76,

  1, 0, 0, 0, 6, 2, 4, 3, 8, 102, 0, 127, 0, 3, 1, 0, 0, 127, 1, 0,

  140, 12, 6, 3, 0, 0, 12, 191, 0, 112, 12, 12, 3, 0, 0, 3, 3, 0, 3, 100,

  50, 10, 12, 0,





};

byte factorypreset10[105] = //training
{
  0, 10, 76, 0, 1, 0, 4, 0, 0, 0, 0, 3, 1, 25, 0, 10, 0, 2, 178, 3, 0,

  51, 85, 10, 255, 25, 25, 3, 0, 51, 85, 10, 255, 25, 25, 0, 20, 4, 12, 4, 1,

  8, 0, 0, 0, 2, 0, 0, 0, 0, 38, 19, 6, 0, 0, 25, 4, 1, 1, 2, 38,

  1, 0, 127, 25, 32, 11, 4, 3, 15, 12, 0, 140, 25, 8, 3, 0, 0, 38, 1, 0,

  140, 25, 4, 3, 0, 0, 76, 12, 0, 112, 25, 12, 7, 0, 0, 5, 3, 2, 0, 100,
  50, 5, 10, 0,



};



//********************************************************************
// Rain Variables
//********************************************************************
unsigned long nextdrip = 0;
unsigned long holdoff1 = 0;
unsigned long holdoff2 = 0;
unsigned long holdoff3 = 0;
unsigned long holdoff4 = 0;
unsigned long holdoff5 = 0;
unsigned long holdoff6 = 0;
unsigned long holdoff7 = 0;

float rain_drumfreq1 = 600;
float rain_drumfreq2 = 750;
float rain_drumfreq3 = 4600;
float rain_drumfreq4 = 3400;
float rain_drumfreq5 = 400;
float rain_drumfreq6 = 2250;
float rain_drumfreq7 = 1300;

float rain_drumlength1 = 3;
float rain_drumlength2 = 3;
float rain_drumlength3 = 3;
float rain_drumlength4 = 20;
float rain_drumlength5 = 20;
float rain_drumlength6 = 20;
float rain_drumlength7 = 20;

float rain_drummod1 = .3;
float rain_drummod2 = .3;
float rain_drummod3 = .8;
float rain_drummod4 = .3;
float rain_drummod5 = .3;
float rain_drummod6 = .3;
float rain_drummod7 = .3;

float secondmix1 = 0;
float secondmix2 = 0;
float secondmix3 = 0;
float secondmix4 = 0;
float secondmix5 = 0;
float secondmix6 = 0;
float secondmix7 = 0;

//********************************************************************
// Shimmer Variables
//********************************************************************
// Number of samples in each delay line
#define FLANGE_DELAY_LENGTH (6*AUDIO_BLOCK_SAMPLES)

// Allocate the delay lines for left and right channels
short l_delayline[FLANGE_DELAY_LENGTH];
short r_delayline[FLANGE_DELAY_LENGTH];
int s_idx = FLANGE_DELAY_LENGTH / 4;
int s_depth = FLANGE_DELAY_LENGTH / 4;
double s_freq = .2;//.5;

int shimmerbank = 0;
unsigned long gliderate = 2000;
bool shimmerbankswitch = 0;
unsigned long plucktime = 0;
float nowplay0 = 0;
float nowplay1 = 0;
float nowplay2 = 0;
float nowplay3 = 0;
unsigned long fingerdelay = 10; //10 is harplike, 5 is guitar like


//********************************************************************
// Dulcimer Variables
//********************************************************************

int sinebank = 0;
float nowplay = 0;

//chord variables
bool stopplay_a = true;
bool stopplay_b = true;

bool switchup1 = 0;
bool switchup2 = 0;

int drum1frequency = 120; //low bong
int drum1length = 500;
float drum1mix = 0.0;
float drum1mod = 0.55;

int drum2frequency = 600; //plock
int drum2length = 10;
float drum2mix = 0.0;
float drum2mod = 0.0;

int drum3frequency = 100; //boing
int drum3length = 1500;
float drum3mix = 0.0;
float drum3mod = 0.55;

int drum4frequency = 1000; //knack
int drum4length = 1;
float drum4mix = 0.0;
float drum4mod = 0.55;

int drum5frequency = 100; //dome
int drum5length = 1500;
float drum5mix = 0;
float drum5mod = 0.44;

// ***************************************
//***************************************
// Setup
//***************************************
//***************************************
void setup()
{
  Serial.begin(9600);
  // audio bus between synth objects.  Set by looking at CPU usage
  AudioMemory(500);


  analogWriteResolution(8); //do I need this?
  analogWriteFrequency(mouthSpkrOutput, 30000);
  analogWriteFrequency(monitorPin, 30000);
  analogReadResolution(8);//was 12

  samplingTimer.begin(grabdata, 20);  // ISR to grab data (mic and drive wave)every 20 us
  samplingTimer.priority(200);  //0 is bad make this get interrupted by something, why?
  delay(1000);

  if (EEPROM.read(0) != 0)
  {
    for (int x = 0; x < 105; x++) byteparameter[x] = float(factorypreset1[x]);
    Serial.println("reading factory");
  }
  else
  {
    for (int x = 0; x < 105; x++) byteparameter[x] = EEPROM.read(x);
    Serial.println("reading eeprom");
  }
  delay(1000);

  //***************I/O*****************
  // pins 7, 20 and 213 used by i2s interface--so leave alone

  pinMode(LEDpin, OUTPUT); //led
  pinMode(micInputPin, INPUT); //microphone A0
  pinMode(mouthSpkrOutput, OUTPUT); //mouth sine output
  pinMode(closeButton, INPUT_PULLUP);
  pinMode(farButton, INPUT_PULLUP);
  pinMode(middleButton, INPUT_PULLUP);

  pinMode(monitorPin, OUTPUT);
  pinMode(WhammyPin, INPUT);
  analogWrite(redPin, 256); //need to set pinmode??
  analogWrite(bluePin, 256);
  analogWrite(greenPin, 256);
  pinMode(modePin, INPUT_PULLUP);

  pinMode(A3, INPUT);  //potentiometer
  pinMode(A4, INPUT);  //not needed

  //***********************************************************
  // synthesizer setup
  //***********************************************************

  synth_selector.gain(0, .25); //solo synth
  synth_selector.gain(1, .25); //harmony synth
  synth_selector.gain(2, .25);//string synth
  synth_selector.gain(3, .25);//drum synth


  AudioNoInterrupts();
  //solo synthesizer

  harmony_mixer.gain(0, 1);
  harmony_mixer.gain(1, 1);
  harmony_mixer.gain(2, .4); //string mixer

  reverb.roomsize(reverb_size);
  reverb.damping(reverb_damping);

  waveform1.begin(1, 220, WAVEFORM_SINE);
  waveform2.begin(1, 220, WAVEFORM_SINE);
  waveform3.begin(1, 220, WAVEFORM_SINE);

  //drum synthesizer

  drum_filter.frequency(2500);
  drum_filter.resonance(0.707);

  drum_mixer1.gain(0, drum_volume1);
  drum_mixer1.gain(1, drum_volume2);
  drum_mixer1.gain(2, drum_volume3);
  drum_mixer1.gain(3, 1);

  drum_mixer2.gain(0, drum_volume4);
  drum_mixer2.gain(1, drum_volume5);
  drum_mixer2.gain(2, 0);//to do delete drum 6
  drum_mixer2.gain(3, 0);



  //  drum6.frequency(2000);//rock
  //  drum6.length(20);
  //  drum6.secondMix(0.0);
  //  drum6.pitchMod(0.66);

  //harmony synthesizer

  melody_filter.frequency(2500);
  melody_filter.resonance(0.707);
  harmony_filter1.frequency(2500);
  harmony_filter1.resonance(0.707);
  harmony_filter2.frequency(2500);
  harmony_filter2.resonance(0.707);

  envelope1.releaseNoteOn(3);
  envelope2.releaseNoteOn(3);
  envelope3.releaseNoteOn(30);

  //***********************************************************
  // dulcimer setup
  //***********************************************************


  dulcimermixer1.gain(0, .25);
  dulcimermixer1.gain(1, .25);
  dulcimermixer1.gain(2, .25);
  dulcimermixer1.gain(3, .25);

  dulcimermixer2.gain(0, .25);
  dulcimermixer2.gain(1, .25);
  dulcimermixer2.gain(2, .25);
  dulcimermixer2.gain(3, .25);

  dulcimermixer3.gain(0, .25);
  dulcimermixer3.gain(1, .25);
  dulcimermixer3.gain(2, .25);
  dulcimermixer3.gain(3, .25);

  dulcimermixer4.gain(0, .25);
  dulcimermixer4.gain(1, .25);
  dulcimermixer4.gain(2, .25);
  dulcimermixer4.gain(3, .25);

  dulcimermixer5.gain(0, .25);
  dulcimermixer5.gain(1, .25);
  dulcimermixer5.gain(2, .25);
  dulcimermixer5.gain(3, .25);

  sine1.frequency(392.00);//g
  sine1.amplitude(1);
  sine2.frequency(440.00);//a
  sine2.amplitude(1);
  sine3.frequency(174.61);//b
  sine3.amplitude(1);
  sine4.frequency(349.23);//c
  sine4.amplitude(1);
  sine5.frequency(587.33);//d
  sine5.amplitude(1);
  sine6.frequency(659.25);//e
  sine6.amplitude(1);
  sine7.frequency(698.46);//f
  sine7.amplitude(1);
  sine8.frequency(783.99);//g
  sine8.amplitude(1);




  //***********************************************************
  // rain setup
  //***********************************************************

  reverb_mixer_L.gain(0, .05);
  reverb_mixer_L.gain(1, .05);
  reverb_mixer_L.gain(2, .3);
  reverb_mixer_L.gain(3, .3);

  reverb_mixer_R.gain(0, .05);
  reverb_mixer_R.gain(1, .05);
  reverb_mixer_R.gain(2, .3);
  reverb_mixer_R.gain(3, .3);

  rain_mixer1.gain(0, .8);
  rain_mixer1.gain(1, 1.6);
  rain_mixer1.gain(2, .8);
  rain_mixer1.gain(3, .4);

  rain_mixer2.gain(0, .25);
  rain_mixer2.gain(1, .25);
  rain_mixer2.gain(2, .25);
  rain_mixer2.gain(3, .25);

  rain_mixer3.gain(0, .25);
  rain_mixer3.gain(1, .25);
  rain_mixer3.gain(2, .25);
  rain_mixer3.gain(3, .25);

  pink1.amplitude(1);
  rain_filter1.frequency(6000);
  rain_filter1.resonance(.7);

  rain_drum1.frequency(rain_drumfreq1);
  rain_drum1.length(rain_drumlength1);
  rain_drum1.secondMix(secondmix1);
  rain_drum1.pitchMod(rain_drummod1);

  rain_drum2.frequency(rain_drumfreq2);
  rain_drum2.length(rain_drumlength2);
  rain_drum2.secondMix(secondmix2);
  rain_drum2.pitchMod(rain_drummod2);

  rain_drum3.frequency(rain_drumfreq3);
  rain_drum3.length(rain_drumlength3);
  rain_drum3.secondMix(secondmix3);
  rain_drum3.pitchMod(rain_drummod3);

  rain_drum4.frequency(rain_drumfreq4);
  rain_drum4.length(rain_drumlength4);
  rain_drum4.secondMix(secondmix4);
  rain_drum4.pitchMod(rain_drummod4);

  rain_drum5.frequency(rain_drumfreq5);
  rain_drum5.length(rain_drumlength5);
  rain_drum5.secondMix(secondmix5);
  rain_drum5.pitchMod(rain_drummod5);

  rain_drum6.frequency(rain_drumfreq6);
  rain_drum6.length(rain_drumlength6);
  rain_drum6.secondMix(secondmix6);
  rain_drum6.pitchMod(rain_drummod6);

  rain_drum7.frequency(rain_drumfreq7);
  rain_drum7.length(rain_drumlength7);
  rain_drum7.secondMix(secondmix7);
  rain_drum7.pitchMod(rain_drummod7);

  //***********************************************************
  // shimmer setup
  //***********************************************************


  shimmerwaveform1.begin(1, 440, WAVEFORM_SINE);
  shimmerwaveform2.begin(1, 440, WAVEFORM_SINE);
  shimmerwaveform3.begin(1, 440, WAVEFORM_SINE);
  shimmerwaveform4.begin(1, 440, WAVEFORM_SINE);
  shimmerwaveform5.begin(1, 440, WAVEFORM_SINE);
  shimmerwaveform6.begin(1, 440, WAVEFORM_SINE);
  shimmerwaveform7.begin(1, 440, WAVEFORM_SINE);
  shimmerwaveform8.begin(1, 440, WAVEFORM_SINE);

  shimmerwaveform1.frequency(130.81);
  shimmerwaveform2.frequency(196.00);
  shimmerwaveform3.frequency(261.63);
  shimmerwaveform4.frequency(392.00);

  shimmerwaveform5.frequency(523.25);
  shimmerwaveform6.frequency(783.99);
  shimmerwaveform7.frequency(1046.50);
  shimmerwaveform8.frequency(1567.00);

  shimmermixer1.gain(0, .8);
  shimmermixer1.gain(1, .4);
  shimmermixer1.gain(2, .2);
  shimmermixer1.gain(3, .2);

  shimmermixer2.gain(0, .2);
  shimmermixer2.gain(1, .1);
  shimmermixer2.gain(2, .1);
  shimmermixer2.gain(3, .05);

  shimmermixer3.gain(0, 1);
  shimmermixer3.gain(1, 1);
  shimmermixer3.gain(2, 0);
  shimmermixer3.gain(3, 0);

  shimmerchorusR.begin(l_delayline, FLANGE_DELAY_LENGTH, s_idx, s_depth, s_freq);
  shimmerchorusL.begin(r_delayline, FLANGE_DELAY_LENGTH, s_idx, s_depth, s_freq);


  shimmerchorusR.voices(s_idx, s_depth, s_freq);
  shimmerchorusL.voices(s_idx, s_depth, s_freq);

}

//***************************************
//***************************************
// Main Loop
//***************************************
//***************************************

void loop()
{

  //  profiledelta = micros() - profiletimer;
  //  profiletimer = micros();

  if (capture == true) //have a set of audio data?, if not avoid entire loop until data is captured
  {
    //*************************************************
    //This is the phase tracker
    //monitor the microphone wave and driving speaker to determine
    //the phase shift indicative of resonance--use this phase
    //difference in a phase locked loop to control the drive
    //frequency to measure the oral cavity volume
    //by its resonant frequency
    //*************************************************


    /////////////////////////////////////////
    //detect driving signal, start and length
    /////////////////////////////////////////
    //do this to zero array at current sample for simplicity

    for (int x = 0; x < BUFSIZE; x++)
    {
      tempdrivebuffer[x] = drivebuffer[x];
      tempmicbuffer[x] = micbuffer[x];
      float floaty = micbuffer[x]; //peak microphone value for ppl tuning routine
      dc9.amplitude(floaty / 256);
    }

    //***********************************************************
    //********zero crossing phase detection ********************
    //***********************************************************

    //determine sine length at this frequency
    if (drivefrequency < 0) drivefrequency = 1;  //nan bug figure out later
    sinelength = ((1 / drivefrequency) / .000020); //one sample every 20 usec, **sinelength is samples

    /////////////////////////////////////////
    //detect drive signal signal start
    /////////////////////////////////////////

    startdrive = risingedge; //micbuffer location of drive signal (+zero cross) now provided by ISR

    /////////////////////////////////////////
    //detect microphone signal start
    /////////////////////////////////////////

    //MICROPHONE UP ZERO CROSSING
    //find average of buffer for rough zero crossing calculation
    averagemic = 0;
    //int peakmic = -999;
    for (int x = 0; x < BUFSIZE; x++)
    {
      averagemic = averagemic + tempmicbuffer[x];
      //if (tempmicbuffer[x] > peakmic) peakmic = tempmicbuffer[x];
    }
    averagemic = int(averagemic / BUFSIZE);
    //microphonelevel = (peakmic - averagemic); //now use audio widget
    //averagecount++;

    //find positive going zero crossing
    found = false;
    lastsample = 2000;
    for (int x = startdrive; x < BUFSIZE; x++) //start at drive signal zero crossing
    {
      if (found == false)
      {
        if ((lastsample <= averagemic) && (tempmicbuffer[x] > averagemic))
        {
          found = true;
          startmic = x;  //up zero cross of mic
        }
        lastsample = tempmicbuffer[x];
      }
    }

    //find negative going zero crossing
    found = false;
    lastsample = 2000;
    for (int x = startmic; x < BUFSIZE; x++) //start at drive signal zero crossing
    {
      if (found == false)
      {
        if ((lastsample >= averagemic) && (tempmicbuffer[x] < averagemic))
        {
          found = true;
          endmic = x;  //next down zero cross of mic
        }
        lastsample = tempmicbuffer[x];
      }
    }

    //curvefit around up zero crossing for subsample interpolation
    ymean = 0;
    for (int x = startmic - 5; x < startmic + 6; x++) ymean = ymean + micbuffer[x];
    ymean = ymean / 11;
    xmean = startmic;
    lineslopenumerator = 0;
    lineslopedenominator = 0;
    for (int x = startmic - 5; x < startmic + 6; x++)
    {
      lineslopenumerator = ((x - xmean) * (micbuffer[x] - ymean));
      lineslopedenominator = (x - xmean) * (x - xmean);
    }
    lineslope = lineslopenumerator / lineslopedenominator;
    yintercept = ymean - lineslope * xmean;
    precisemicstart = ((averagemic - yintercept) / lineslope);


    //curvefit around down zero crossing for subsample interpolation
    ymean = 0;
    for (int x = endmic - 5; x < endmic + 6; x++) ymean = ymean + micbuffer[x];
    ymean = ymean / 11;
    xmean = endmic;
    lineslopenumerator = 0;
    lineslopedenominator = 0;
    for (int x = endmic - 5; x < endmic + 6; x++)
    {
      lineslopenumerator = ((x - xmean) * (micbuffer[x] - ymean));
      lineslopedenominator = (x - xmean) * (x - xmean);
    }
    lineslope = lineslopenumerator / lineslopedenominator;
    yintercept = ymean - lineslope * xmean;
    precisemicend = ((averagemic - yintercept) / lineslope);


    phaseshift = precisemicstart - startdrive; //the sample # measure of the phase delay

    int halfwave = int(sinelength / 2);
    phaseshift2 = precisemicend - (startdrive + halfwave); //the sample # measure of the phase delay

    phaseshift = (phaseshift2 + phaseshift) / 2; //corrects waveform zero shift?

    //handles an odd phase shift rollover at low frequecies
    if (phaseshift > (sinelength / 2)) phaseshift = sinelength - phaseshift;

    phaseshiftdegrees = phaseshift / sinelength * 360; // for display
    if (isnan(sinelength)) sinelength = 100; //weird startup bug--figure out later

    //compute phase error in time then degrees
    if (forceMode == 1)phaseerror = phaseshift - (sinelength * phasetargetforced); //tuning mode
    else phaseerror = phaseshift - (sinelength * phasetarget);
    phaseerror = phaseshift - (sinelength * phasetarget);
    phaseerrordegrees = phaseerror / sinelength * 360;


    /////////////////////////////////
    //determine loop gain factors (P and D) according to current pitch bin !!!!!!!!!!
    /////////////////////////////////

    //apply different loop gains depending on note frequency in 25 notes

    if ((drivefrequency <= chromatic[25]) && (drivefrequency > chromatic[24])) //note 2 !!!!!!!
    {
      tuningband = 0;//415
      //interpolate phase gain from discrete array values of bins
      phasegain = phasegainset[0] + (phasegainset[1] - phasegainset[0]) *
                  ((drivefrequency - chromatic[24]) / (chromatic[25] - chromatic[24])); //these are the frequency values bounding the top bin
      //interpolate derivative gain
      derivativegain = derivativegainset[0] + (derivativegainset[1] - derivativegainset[0]) *
                       ((drivefrequency - chromatic[24]) / (chromatic[25] - chromatic[24]));
      //interpolate  phase target
      phasetarget = phasetargetset[0] + (phasetargetset[1] - phasetargetset[0]) *
                    ((drivefrequency - chromatic[24]) / (chromatic[25] - chromatic[24]));
      //interpolate  speaker gain
      speakergain = speakergainset[0] + (speakergainset[1] - speakergainset[0]) *
                    ((drivefrequency - chromatic[24]) / (chromatic[25] - chromatic[24]));

    }
    else if (drivefrequency <= chromatic[26]) //493-659
    {
      tuningband = 1;
      //interpolate phase gain from discrete array values of bins
      phasegain = phasegainset[1] + (phasegainset[2] - phasegainset[1]) *
                  ((drivefrequency - chromatic[25]) / (chromatic[26] - chromatic[25]));
      //interpolate derivative gain
      derivativegain = derivativegainset[1] + (derivativegainset[2] - derivativegainset[1]) *
                       ((drivefrequency - chromatic[25]) / (chromatic[26] - chromatic[25]));
      //interpolate  phase target
      phasetarget = phasetargetset[1] + (phasetargetset[2] - phasetargetset[1]) *
                    ((drivefrequency - chromatic[25]) / (chromatic[26] - chromatic[25]));
      //interpolate  speaker gain
      speakergain = speakergainset[1] + (speakergainset[2] - speakergainset[1]) *
                    ((drivefrequency - chromatic[25]) / (chromatic[26] - chromatic[25]));
    }
    else if (drivefrequency <= chromatic[27]) //660-830
    {
      tuningband = 2;
      //interpolate phase gain from discrete array values of bins
      phasegain = phasegainset[2] + (phasegainset[3] - phasegainset[2]) *
                  ((drivefrequency - chromatic[26]) / (chromatic[27] - chromatic[26]));
      //interpolate derivative gain
      derivativegain = derivativegainset[2] + (derivativegainset[3] - derivativegainset[2]) *
                       ((drivefrequency - chromatic[26]) / (chromatic[27] - chromatic[26]));
      //interpolate  phase target
      phasetarget = phasetargetset[2] + (phasetargetset[3] - phasetargetset[2]) *
                    ((drivefrequency - chromatic[26]) / (chromatic[27] - chromatic[26]));
      //interpolate  speaker gain
      speakergain = speakergainset[2] + (speakergainset[3] - speakergainset[2]) *
                    ((drivefrequency - chromatic[26]) / (chromatic[27] - chromatic[26]));
    }
    else if (drivefrequency <= chromatic[28]) //831-1046
    {
      tuningband = 3;
      //interpolate phase gain from discrete array values of bins
      phasegain = phasegainset[3] + (phasegainset[4] - phasegainset[3]) *
                  ((drivefrequency - chromatic[27]) / (chromatic[28] - chromatic[27]));
      //interpolate derivative gain
      derivativegain = derivativegainset[3] + (derivativegainset[4] - derivativegainset[3]) *
                       ((drivefrequency - chromatic[27]) / (chromatic[28] - chromatic[27]));
      //interpolate  phase target
      phasetarget = phasetargetset[3] + (phasetargetset[4] - phasetargetset[3]) *
                    ((drivefrequency - chromatic[27]) / (chromatic[28] - chromatic[27]));
      //interpolate  speaker gain
      speakergain = speakergainset[3] + (speakergainset[4] - speakergainset[3]) *
                    ((drivefrequency - chromatic[27]) / (chromatic[28] - chromatic[27]));
    }
    else if (drivefrequency <= chromatic[29]) //1044-1244
    {
      tuningband = 4;
      //interpolate phase gain from discrete array values of bins
      phasegain = phasegainset[4] + (phasegainset[5] - phasegainset[4]) *
                  ((drivefrequency - chromatic[28]) / (chromatic[29] - chromatic[28]));
      //interpolate derivative gain
      derivativegain = derivativegainset[4] + (derivativegainset[5] - derivativegainset[4]) *
                       ((drivefrequency - chromatic[28]) / (chromatic[29] - chromatic[28]));
      //interpolate  phase target
      phasetarget = phasetargetset[4] + (phasetargetset[5] - phasetargetset[4]) *
                    ((drivefrequency - chromatic[28]) / (chromatic[29] - chromatic[28]));
      //interpolate  speaker gain
      speakergain = speakergainset[4] + (speakergainset[5] - speakergainset[4]) *
                    ((drivefrequency - chromatic[28]) / (chromatic[29] - chromatic[28]));
    }

    else if (drivefrequency <= chromatic[30]) //1245-1661
    {
      tuningband = 5;
      //interpolate phase gain from discrete array values of bins
      phasegain = phasegainset[5] + (phasegainset[6] - phasegainset[5]) *
                  ((drivefrequency - chromatic[29]) / (chromatic[30] - chromatic[29]));
      //interpolate derivative gain
      derivativegain = derivativegainset[5] + (derivativegainset[6] - derivativegainset[5]) *
                       ((drivefrequency - chromatic[29]) / (chromatic[30] - chromatic[29]));
      //interpolate  phase target
      phasetarget = phasetargetset[5] + (phasetargetset[6] - phasetargetset[5]) *
                    ((drivefrequency - chromatic[29]) / (chromatic[30] - chromatic[29]));
      //interpolate  speaker gain
      speakergain = speakergainset[5] + (speakergainset[6] - speakergainset[5]) *
                    ((drivefrequency - chromatic[29]) / (chromatic[30] - chromatic[29]));
    }

    else if (drivefrequency <= chromatic[31]) //1245-1661
    {
      tuningband = 6;
      //interpolate phase gain from discrete array values of bins
      phasegain = phasegainset[6] + (phasegainset[7] - phasegainset[6]) *
                  ((drivefrequency - chromatic[30]) / (chromatic[31] - chromatic[30]));
      //interpolate derivative gain
      derivativegain = derivativegainset[6] + (derivativegainset[7] - derivativegainset[6]) *
                       ((drivefrequency - chromatic[30]) / (chromatic[31] - chromatic[30]));
      //interpolate  phase target
      phasetarget = phasetargetset[6] + (phasetargetset[7] - phasetargetset[6]) *
                    ((drivefrequency - chromatic[30]) / (chromatic[31] - chromatic[30]));
      //interpolate  speaker gain
      speakergain = speakergainset[6] + (speakergainset[7] - speakergainset[6]) *
                    ((drivefrequency - chromatic[30]) / (chromatic[31] - chromatic[30]));
    }

    else if (drivefrequency <= chromatic[32]) //1245-1661
    {
      tuningband = 7;
      //interpolate phase gain from discrete array values of bins
      phasegain = phasegainset[7] + (phasegainset[8] - phasegainset[7]) *
                  ((drivefrequency - chromatic[31]) / (chromatic[32] - chromatic[31]));
      //interpolate derivative gain
      derivativegain = derivativegainset[7] + (derivativegainset[8] - derivativegainset[7]) *
                       ((drivefrequency - chromatic[31]) / (chromatic[32] - chromatic[31]));
      //interpolate  phase target
      phasetarget = phasetargetset[7] + (phasetargetset[8] - phasetargetset[7]) *
                    ((drivefrequency - chromatic[31]) / (chromatic[32] - chromatic[31]));
      //interpolate  speaker gain
      speakergain = speakergainset[7] + (speakergainset[8] - speakergainset[7]) *
                    ((drivefrequency - chromatic[31]) / (chromatic[32] - chromatic[31]));
    }

    else if (drivefrequency <= chromatic[33]) //1245-1661
    {
      tuningband = 8;
      //interpolate phase gain from discrete array values of bins
      phasegain = phasegainset[8] + (phasegainset[9] - phasegainset[8]) *
                  ((drivefrequency - chromatic[32]) / (chromatic[33] - chromatic[32]));
      //interpolate derivative gain
      derivativegain = derivativegainset[8] + (derivativegainset[9] - derivativegainset[8]) *
                       ((drivefrequency - chromatic[32]) / (chromatic[33] - chromatic[32]));
      //interpolate  phase target
      phasetarget = phasetargetset[8] + (phasetargetset[9] - phasetargetset[8]) *
                    ((drivefrequency - chromatic[32]) / (chromatic[33] - chromatic[32]));
      //interpolate  speaker gain
      speakergain = speakergainset[8] + (speakergainset[9] - speakergainset[8]) *
                    ((drivefrequency - chromatic[32]) / (chromatic[33] - chromatic[32]));
    }

    else if (drivefrequency <= chromatic[34]) //1245-1661
    {
      tuningband = 9;
      //interpolate phase gain from discrete array values of bins
      phasegain = phasegainset[9] + (phasegainset[10] - phasegainset[9]) *
                  ((drivefrequency - chromatic[33]) / (chromatic[34] - chromatic[33]));
      //interpolate derivative gain
      derivativegain = derivativegainset[9] + (derivativegainset[10] - derivativegainset[9]) *
                       ((drivefrequency - chromatic[33]) / (chromatic[34] - chromatic[33]));
      //interpolate  phase target
      phasetarget = phasetargetset[9] + (phasetargetset[10] - phasetargetset[9]) *
                    ((drivefrequency - chromatic[33]) / (chromatic[34] - chromatic[33]));
      //interpolate  speaker gain
      speakergain = speakergainset[9] + (speakergainset[10] - speakergainset[9]) *
                    ((drivefrequency - chromatic[33]) / (chromatic[34] - chromatic[33]));
    }

    else if (drivefrequency <= chromatic[35]) //1245-1661
    {
      tuningband = 10;
      //interpolate phase gain from discrete array values of bins
      phasegain = phasegainset[10] + (phasegainset[11] - phasegainset[10]) *
                  ((drivefrequency - chromatic[34]) / (chromatic[35] - chromatic[34]));
      //interpolate derivative gain
      derivativegain = derivativegainset[10] + (derivativegainset[11] - derivativegainset[10]) *
                       ((drivefrequency - chromatic[34]) / (chromatic[35] - chromatic[34]));
      //interpolate  phase target
      phasetarget = phasetargetset[10] + (phasetargetset[11] - phasetargetset[10]) *
                    ((drivefrequency - chromatic[34]) / (chromatic[35] - chromatic[34]));
      //interpolate  speaker gain
      speakergain = speakergainset[10] + (speakergainset[11] - speakergainset[10]) *
                    ((drivefrequency - chromatic[34]) / (chromatic[35] - chromatic[34]));
    }

    else if (drivefrequency <= chromatic[36]) //1245-1661
    {
      tuningband = 11;
      //interpolate phase gain from discrete array values of bins
      phasegain = phasegainset[11] + (phasegainset[12] - phasegainset[11]) *
                  ((drivefrequency - chromatic[35]) / (chromatic[36] - chromatic[35]));
      //interpolate derivative gain
      derivativegain = derivativegainset[11] + (derivativegainset[12] - derivativegainset[11]) *
                       ((drivefrequency - chromatic[35]) / (chromatic[36] - chromatic[35]));
      //interpolate  phase target
      phasetarget = phasetargetset[11] + (phasetargetset[12] - phasetargetset[11]) *
                    ((drivefrequency - chromatic[35]) / (chromatic[36] - chromatic[35]));
      //interpolate  speaker gain
      speakergain = speakergainset[11] + (speakergainset[12] - speakergainset[11]) *
                    ((drivefrequency - chromatic[35]) / (chromatic[36] - chromatic[35]));
    }

    else if (drivefrequency <= chromatic[37]) //1245-1661
    {
      tuningband = 12;
      //interpolate phase gain from discrete array values of bins
      phasegain = phasegainset[12] + (phasegainset[13] - phasegainset[12]) *
                  ((drivefrequency - chromatic[36]) / (chromatic[37] - chromatic[36]));
      //interpolate derivative gain
      derivativegain = derivativegainset[12] + (derivativegainset[13] - derivativegainset[12]) *
                       ((drivefrequency - chromatic[36]) / (chromatic[37] - chromatic[36]));
      //interpolate  phase target
      phasetarget = phasetargetset[12] + (phasetargetset[13] - phasetargetset[12]) *
                    ((drivefrequency - chromatic[36]) / (chromatic[37] - chromatic[36]));
      //interpolate  speaker gain
      speakergain = speakergainset[12] + (speakergainset[13] - speakergainset[12]) *
                    ((drivefrequency - chromatic[36]) / (chromatic[37] - chromatic[36]));
    }

    else if (drivefrequency <= chromatic[38]) //1245-1661
    {
      tuningband = 13;
      //interpolate phase gain from discrete array values of bins
      phasegain = phasegainset[13] + (phasegainset[14] - phasegainset[13]) *
                  ((drivefrequency - chromatic[37]) / (chromatic[38] - chromatic[37]));
      //interpolate derivative gain
      derivativegain = derivativegainset[13] + (derivativegainset[14] - derivativegainset[13]) *
                       ((drivefrequency - chromatic[37]) / (chromatic[38] - chromatic[37]));
      //interpolate  phase target
      phasetarget = phasetargetset[13] + (phasetargetset[14] - phasetargetset[13]) *
                    ((drivefrequency - chromatic[37]) / (chromatic[38] - chromatic[37]));
      //interpolate  speaker gain
      speakergain = speakergainset[13] + (speakergainset[14] - speakergainset[13]) *
                    ((drivefrequency - chromatic[37]) / (chromatic[38] - chromatic[37]));
    }

    else if (drivefrequency <= chromatic[39]) //1245-1661
    {
      tuningband = 14;
      //interpolate phase gain from discrete array values of bins
      phasegain = phasegainset[14] + (phasegainset[15] - phasegainset[14]) *
                  ((drivefrequency - chromatic[38]) / (chromatic[39] - chromatic[38]));
      //interpolate derivative gain
      derivativegain = derivativegainset[14] + (derivativegainset[15] - derivativegainset[14]) *
                       ((drivefrequency - chromatic[38]) / (chromatic[39] - chromatic[38]));
      //interpolate  phase target
      phasetarget = phasetargetset[14] + (phasetargetset[15] - phasetargetset[14]) *
                    ((drivefrequency - chromatic[38]) / (chromatic[39] - chromatic[38]));
      //interpolate  speaker gain
      speakergain = speakergainset[14] + (speakergainset[15] - speakergainset[14]) *
                    ((drivefrequency - chromatic[38]) / (chromatic[39] - chromatic[38]));
    }

    else if (drivefrequency <= chromatic[40]) //1245-1661
    {
      tuningband = 15;
      //interpolate phase gain from discrete array values of bins
      phasegain = phasegainset[15] + (phasegainset[16] - phasegainset[15]) *
                  ((drivefrequency - chromatic[39]) / (chromatic[40] - chromatic[39]));
      //interpolate derivative gain
      derivativegain = derivativegainset[15] + (derivativegainset[16] - derivativegainset[15]) *
                       ((drivefrequency - chromatic[39]) / (chromatic[40] - chromatic[39]));
      //interpolate  phase target
      phasetarget = phasetargetset[15] + (phasetargetset[16] - phasetargetset[15]) *
                    ((drivefrequency - chromatic[39]) / (chromatic[40] - chromatic[39]));
      //interpolate  speaker gain
      speakergain = speakergainset[15] + (speakergainset[16] - speakergainset[15]) *
                    ((drivefrequency - chromatic[39]) / (chromatic[40] - chromatic[39]));
    }

    else if (drivefrequency <= chromatic[41]) //1245-1661
    {
      tuningband = 16;
      //interpolate phase gain from discrete array values of bins
      phasegain = phasegainset[16] + (phasegainset[17] - phasegainset[16]) *
                  ((drivefrequency - chromatic[40]) / (chromatic[41] - chromatic[40]));
      //interpolate derivative gain
      derivativegain = derivativegainset[16] + (derivativegainset[17] - derivativegainset[16]) *
                       ((drivefrequency - chromatic[40]) / (chromatic[41] - chromatic[40]));
      //interpolate  phase target
      phasetarget = phasetargetset[16] + (phasetargetset[17] - phasetargetset[16]) *
                    ((drivefrequency - chromatic[40]) / (chromatic[41] - chromatic[40]));
      //interpolate  speaker gain
      speakergain = speakergainset[16] + (speakergainset[17] - speakergainset[16]) *
                    ((drivefrequency - chromatic[40]) / (chromatic[41] - chromatic[40]));
    }

    else if (drivefrequency <= chromatic[42]) //1245-1661
    {
      tuningband = 17;
      //interpolate phase gain from discrete array values of bins
      phasegain = phasegainset[17] + (phasegainset[18] - phasegainset[17]) *
                  ((drivefrequency - chromatic[41]) / (chromatic[42] - chromatic[41]));
      //interpolate derivative gain
      derivativegain = derivativegainset[17] + (derivativegainset[18] - derivativegainset[17]) *
                       ((drivefrequency - chromatic[41]) / (chromatic[42] - chromatic[41]));
      //interpolate  phase target
      phasetarget = phasetargetset[17] + (phasetargetset[18] - phasetargetset[17]) *
                    ((drivefrequency - chromatic[41]) / (chromatic[42] - chromatic[41]));
      //interpolate  speaker gain
      speakergain = speakergainset[17] + (speakergainset[18] - speakergainset[17]) *
                    ((drivefrequency - chromatic[41]) / (chromatic[42] - chromatic[41]));
    }

    else if (drivefrequency <= chromatic[43]) //1245-1661
    {
      tuningband = 18;
      //interpolate phase gain from discrete array values of bins
      phasegain = phasegainset[18] + (phasegainset[19] - phasegainset[18]) *
                  ((drivefrequency - chromatic[42]) / (chromatic[43] - chromatic[42]));
      //interpolate derivative gain
      derivativegain = derivativegainset[18] + (derivativegainset[19] - derivativegainset[18]) *
                       ((drivefrequency - chromatic[42]) / (chromatic[43] - chromatic[42]));
      //interpolate  phase target
      phasetarget = phasetargetset[18] + (phasetargetset[19] - phasetargetset[18]) *
                    ((drivefrequency - chromatic[42]) / (chromatic[43] - chromatic[42]));
      //interpolate  speaker gain
      speakergain = speakergainset[18] + (speakergainset[19] - speakergainset[18]) *
                    ((drivefrequency - chromatic[42]) / (chromatic[43] - chromatic[42]));
    }

    else if (drivefrequency <= chromatic[44]) //1245-1661
    {
      tuningband = 19;
      //interpolate phase gain from discrete array values of bins
      phasegain = phasegainset[19] + (phasegainset[20] - phasegainset[19]) *
                  ((drivefrequency - chromatic[43]) / (chromatic[44] - chromatic[43]));
      //interpolate derivative gain
      derivativegain = derivativegainset[19] + (derivativegainset[20] - derivativegainset[19]) *
                       ((drivefrequency - chromatic[43]) / (chromatic[44] - chromatic[43]));
      //interpolate  phase target
      phasetarget = phasetargetset[19] + (phasetargetset[20] - phasetargetset[19]) *
                    ((drivefrequency - chromatic[43]) / (chromatic[44] - chromatic[43]));
      //interpolate  speaker gain
      speakergain = speakergainset[19] + (speakergainset[20] - speakergainset[19]) *
                    ((drivefrequency - chromatic[43]) / (chromatic[44] - chromatic[43]));
    }

    else if (drivefrequency <= chromatic[45]) //1245-1661
    {
      tuningband = 20;
      //interpolate phase gain from discrete array values of bins
      phasegain = phasegainset[20] + (phasegainset[21] - phasegainset[20]) *
                  ((drivefrequency - chromatic[44]) / (chromatic[45] - chromatic[44]));
      //interpolate derivative gain
      derivativegain = derivativegainset[20] + (derivativegainset[21] - derivativegainset[20]) *
                       ((drivefrequency - chromatic[44]) / (chromatic[45] - chromatic[44]));
      //interpolate  phase target
      phasetarget = phasetargetset[20] + (phasetargetset[21] - phasetargetset[20]) *
                    ((drivefrequency - chromatic[44]) / (chromatic[45] - chromatic[44]));
      //interpolate  speaker gain
      speakergain = speakergainset[20] + (speakergainset[21] - speakergainset[20]) *
                    ((drivefrequency - chromatic[44]) / (chromatic[45] - chromatic[44]));
    }



    if (speakergain < 0)speakergain = 0;

    if (forceMode == 5)
    {
      derivativegainforced = map(whammyfrequency, 0, 255, 1, 100) / 10000;
      derivativegain = derivativegainforced;
    }

    //***********volume boost on rapid frequency change--could be more sophisticated, e.g continuous
    if (volumeboost == 1)
    {
      fderivative = (lastdrivefrequency - drivefrequency) * .1;//derivativegain; //looks at output derivative
      if ((fderivative) > 4) boost = .02;
      if (boost > 0) boost = boost - .001; //slow fall  to do reactivate with derivative gain
      speakergain = speakergain + boost;
    }
    //***************end of volume boost

    //**********************phasegain boost
    float flyingaverage = (drivefrequency + lastfrequency) / 2;
    slopemagnitude = ((drivefrequency - lastfrequency) / ((millis() - lastcheck) * flyingaverage));
    //slopemagnitude = abs(slopemagnitude);
    lastcheck = millis();
    lastfrequency = drivefrequency;
    //*************end of phasechange boost


    if (phasetarget < 0)phasetarget = 0;
    if (phasegain < 0)phasegain = 0;

    if (phasegainboost == 1)
    {
      if ((drivefrequency > 800) && ((slopemagnitude * 100000) < -400)) //
      {
        phasegain = phasegain + 3;
        gaincorrect = 100;
        boosttimeout = millis() + 25;
      }

      if ((drivefrequency <= 900) && ((slopemagnitude * 100000) > 400))
      {
        phasegain = phasegain + 3;
        gaincorrect = 100;
        boosttimeout = millis() + 25;
      }
    }


    if (boosttimeout > millis())
    {
      phasegain = phasegain + 3;
    }
    else gaincorrect = 0;

    /////////////////////////////////
    //calculate P and D error values
    /////////////////////////////////

    if (forceMode == 2) proportional = (phaseerror * phasegainforced);
    else proportional = (phaseerror * phasegain);


    //derivative = (lastdrivefrequency - drivefrequency) * derivativegain; //looks at output derivative
    //derivative = (previousphaseerror - phaseerror) * derivativegain;
    //should this be based on phaseerror(above)??
    //lastdrivefrequency = drivefrequency;
    previousphaseerror = phaseerror;

    /////////////////////////////////
    //adjust the drive frequency based on proportional and derivative
    /////////////////////////////////

    drivefrequency = drivefrequency - proportional - derivative; // derivative is negative to damp oscillation
    if (isnan(drivefrequency)) drivefrequency = 1200; //bug figure out later

    if (drivefrequency < BOTTOMFREQ) drivefrequency = BOTTOMFREQ;//prevents windup?
    if (drivefrequency > TOPFREQ) drivefrequency = TOPFREQ;

    //set global variable for ISR frequency control
    //if (DISPLAY_MODE == 2) drivefrequency = chromatic[scalefilter[AGCindex]]; //override for AGC adjust


    /////////////////////////////////
    //find closest note for LUT
    /////////////////////////////////

    driveerror = 9999;
    closestfrequency = 0;
    for (int x = 0;  x < 50; x++)
    {
      if (abs(chromatic[x] - drivefrequency) < driveerror)
      {
        driveerror = abs(chromatic[x] - drivefrequency);
        closestLUTnumber = x;
      }
    }

    whammyfrequency = analogRead(WhammyPin);
    if (forceMode == 0)
    {
      drivefrequencyforced = map(whammyfrequency, 0, 255, 393, 1400);
      drivefrequency = drivefrequencyforced;
    }
    if (forceMode == 1) phasetargetforced = map(whammyfrequency, 0, 255, 10, 40) / 100;
    if (forceMode == 2) phasegainforced = map(whammyfrequency, 0, 255, 1, 12);
    if (forceMode == 3) AGCsmoothforced = map(whammyfrequency, 0, 255, 1, 200) / 1000;


    sineincrement = (10000 / drivefrequency); //test for drivefreq change?
    /////////////////////////////////
    //find closest scale note for quantization
    /////////////////////////////////

    driveerror = 9999;
    closestfrequency = 0;
    for (int x = 0;  x < SCALESIZE; x++)
    {
      if (abs(chromatic[scalefilter[x]] - drivefrequency) < driveerror)
      {
        driveerror = abs(chromatic[scalefilter[x]] - drivefrequency);
        closestfrequency = chromatic[scalefilter[x]];
        closestscalenumber = x;

      }
    }

    /////////////////////////////////
    //recalculate closest scale note for hysteresis
    /////////////////////////////////

    hyster_closest_scale_number = closestscalenumber;
    float A = chromatic[scalefilter[hyster_closest_scale_number]];
    float B = chromatic[scalefilter[hyster_last_closest_scale_number]];
    newnote = false;
    if (A > B)
    {
      if (drivefrequency < ((A + B) / 2) + ((A - B) / hysteresisamount)) // 1/5 is the hysteramount
        hyster_closest_scale_number = hyster_last_closest_scale_number;
    }
    else if (B > A)
    {
      if (drivefrequency > ((A + B) / 2) - ((B - A) / hysteresisamount))
        hyster_closest_scale_number = hyster_last_closest_scale_number;
    }
    else newnote = true;

    hyster_last_closest_scale_number = hyster_closest_scale_number;
    //closest_chromatic_note_number = scalefilter[hyster_closest_scale_number];

    //    if (lasthysterclosestnote != hysterclosestnote) glide1.amplitude(hysterclosestnote / 20000, glide_rate);
    //    lasthysterclosestnote = hysterclosestnote;
    //    hysterclosestnote = chromatic[scalefilter[hyster_closest_scale_number]];


    /////////////////////////////////
    // monitor signal amplitude calculation
    /////////////////////////////////

    usec2 = millis();
    if (usec2 > lastusec2 + 100)//
    {
      monitorsineincrement = (10000 / chromatic[scalefilter[hyster_closest_scale_number]]); //test for drivefreq change?
      float tempo = analogRead(WhammyPin);
      if (modecount == 1) monitorgain = tempo / 255;
      performancegain = tempo / 255;
      //monitorgain = volumecurve[hyster_closest_scale_number] * monitorgain;
      if (woken == false) monitorgain = 0;
    }


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// BEGIN SYNTHEZIER MECHANICS/ UI
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /////////////////////////////////////////
    //sleep timer
    /////////////////////////////////////////

    //test sleep timer--turns off mouth speaker after a few seconds
    if ((sleeptimer < millis()) && (woken == true))
    {
      woken = false;  //go to sleep
      wokenstall = false;
      nochord = true;
      justonce = true;


    }

    //maintains sleep timer even if not transition of button
    if (cherry1 == true) // || (cherry2 == true) || (cherry3 == true) )
    {
      sleeptimer = millis() + 5000;
      if (woken == false) wokentime = millis();
      woken = true;
      nochord = false;
      deadmantimer = millis(); //fadeout
    }

    if ((woken == true) && (wokentime + 500 < millis()) ) wokenstall = true; //don't make sound for 2 seconds after mouth spek

    /////////////////////////////////////////
    //synthesizer mode button detect/ binary encoding etc
    /////////////////////////////////////////

    if ((digitalRead(modePin) == 0) && (modebutton == false))
    {
      modebutton = true;
      modecount++;
      Serial.print("***************************************************");
      Serial.println(modecount);
      initializeme = true;
      Colorme(modecount);
      bouncetimer3 = millis() + 100;
      offtimer = millis() + 3000;
      woken = false;
      wokenstall = false;
      displayMode = 0;
      fivenotes = 0; //used for fadein fadeout
      glide4.amplitude(0, 1);
      playstate = 0;
      bool stringchordplay = true;
      shimmerplay = false;
      tonechordplay = false;
      stringchordplay = false;

    }
    else if (millis() > bouncetimer3)
    {
      if (digitalRead(modePin) == 1) modebutton = false;
    }

    if (modecount > 9) modecount = 1; //10 crashes it, why? eeprom?




    //////////////////////////////////
    //CHANGE SYNTH MODE
    /////////////////////////////////

    if (modecount != lastmodecount)
    {
      lastmodecount = modecount;
      EEPROMsource = true;
      switch (modecount)
      {
        case 1:
          if (EEPROM.read(0) != 0)
          {
            for (int x = 0; x < 105; x++) byteparameter[x] = float(factorypreset1[x]);
            EEPROMsource = false;
          }
          else for (int x = 0; x < 105; x++) byteparameter[x] = EEPROM.read(x);
          break;
        case 2:
          if (EEPROM.read(105) != 0)
          {
            for (int x = 0; x < 105; x++) byteparameter[x] = float(factorypreset2[x]);
            EEPROMsource = false;
          }
          else for (int x = 0; x < 105; x++) byteparameter[x] = EEPROM.read(x + 105);
          break;
        case 3:
          if (EEPROM.read(210) != 0)
          {
            for (int x = 0; x < 105; x++) byteparameter[x] = float(factorypreset3[x]);
            EEPROMsource = false;
          }
          else for (int x = 0; x < 105; x++) byteparameter[x] = EEPROM.read(x + 210);
          EEPROMsource = false;
          break;
        case 4:
          if (EEPROM.read(315) != 0)
          {
            for (int x = 0; x < 105; x++) byteparameter[x] = float(factorypreset4[x]);
            EEPROMsource = false;
          }
          else for (int x = 0; x < 105; x++) byteparameter[x] = EEPROM.read(x + 315);
          break;
        case 5:
          if (EEPROM.read(420) != 0)
          {
            for (int x = 0; x < 105; x++) byteparameter[x] = float(factorypreset5[x]);
            EEPROMsource = false;
          }
          else for (int x = 0; x < 105; x++) byteparameter[x] = EEPROM.read(x + 420);
          break;
        case 6:
          if (EEPROM.read(525) != 0)
          {
            for (int x = 0; x < 105; x++) byteparameter[x] = float(factorypreset6[x]);
            EEPROMsource = false;
          }
          else for (int x = 0; x < 105; x++) byteparameter[x] = EEPROM.read(x + 525);
          break;
        case 7:
          if (EEPROM.read(630) != 0)
          {
            for (int x = 0; x < 105; x++) byteparameter[x] = float(factorypreset7[x]);
            EEPROMsource = false;
          }
          else for (int x = 0; x < 105; x++) byteparameter[x] = EEPROM.read(x + 630);
          break;
        case 8:
          if (EEPROM.read(735) != 0)
          {
            for (int x = 0; x < 105; x++) byteparameter[x] = float(factorypreset8[x]);
            EEPROMsource = false;
          }
          else for (int x = 0; x < 105; x++) byteparameter[x] = EEPROM.read(x + 735);
          break;
        case 9:
          if (EEPROM.read(840) != 0)
          {
            for (int x = 0; x < 105; x++) byteparameter[x] = float(factorypreset9[x]);
            EEPROMsource = false;
          }
          else for (int x = 0; x < 105; x++) byteparameter[x] = EEPROM.read(x + 840);
          break;
        case 10:
          if (EEPROM.read(945) != 0)
          {
            for (int x = 0; x < 105; x++) byteparameter[x] = float(factorypreset10[x]);
            EEPROMsource = false;
          }
          else for (int x = 0; x < 105; x++) byteparameter[x] = EEPROM.read(x + 945);
          break;
        default:
          Serial.println("no such mode");
          break;
      }
      //updatetoggle = true;
      printscreen = true;
    }


    /////////////////////////////////
    // SENSING CHERRY SWITCHES 1, 2, 3
    /////////////////////////////////

    //********first switch*********************************************
    if ((digitalRead(closeButton) == false) && (cherry1 == false) && (millis() > bouncetimerB1))
    {
      cherry1 = true;
      bouncetimerA1 = millis() + 50;
      fivenotes++;
    }

    if ((digitalRead(closeButton) == true) && (cherry1 == true) && (millis() > bouncetimerA1))
    {
      cherry1 = false;
      bouncetimerB1 = millis() + 50;
    }

    //********second switch*********************************************
    if ((digitalRead(middleButton) == false) && (cherry2 == false) && (millis() > bouncetimerB2))
    {
      cherry2 = true;
      bouncetimerA2 = millis() + 50;
      if (displayMode == 4) //if in PPL tuning mode, this button captures setting
      {
        if (forceMode == 1)phasetargetset[tuningband] = phasetargetforced;
        if (forceMode == 2)phasegainset[tuningband] = phasegainforced;
        if (forceMode == 3)speakergainset[tuningband] = AGCsmoothforced;
      }
    }

    if ((digitalRead(middleButton) == true) && (cherry2 == true) && (millis() > bouncetimerA2))
    {
      cherry2 = false;
      bouncetimerB2 = millis() + 50;
    }

    //********third switch*********************************************
    if ((digitalRead(farButton) == false) && (cherry3 == false) && (millis() > bouncetimerB3))
    {
      cherry3 = true;
      bouncetimerA3 = millis() + 50;
    }

    if ((digitalRead(farButton) == true) && (cherry3 == true) && (millis() > bouncetimerA3))
    {
      cherry3 = false;
      bouncetimerB3 = millis() + 50;
    }

    //binary encoding  ***************************************************************************
    //****binary state 0********************************************************************************
    if ((cherry2 == false) && (cherry3 == false) && (binarystate != 0))
    {
      binarystatetoggle0 = true;
      binarystate = 0;
    }
    //****binary state 1********************************************************************************
    if ((cherry2 == false) && (cherry3 == true) && (binarystate != 1))
    {
      binarystatetoggle1 = true;
      binarystate = 1;
    }
    //****binary state 2********************************************************************************
    if ((cherry2 == true) && (cherry3 == false) && (binarystate != 2))
    {
      binarystatetoggle2 = true;
      binarystate = 2;
    }
    //****binary state 3********************************************************************************
    if ((cherry2 == true) && (cherry3 == true) && (binarystate != 3))
    {
      binarystatetoggle3 = true;
      binarystate = 3;
    }
    //binary decoding  end***************************************************************************


    //FADE IN FADE OUT****************************************
    //***state 0 fade in ambient
    if ((playstate == 0) && ((cherry2 == true) || (cherry3 == true)))
    {
      playstate = 1; //
      //Serial.println("state 1 fadein");
      //fadeup master volume
      glide4.amplitude(1, fadeintime); //10000 is good
    }
    //***state 1 fade out ambient
    if ((playstate == 1) && (fivenotes > 5) && (millis() - deadmantimer > 10000))
    {
      //Serial.println("state 2 fadeout");
      playstate = 2;
      glide4.amplitude(0, fadeouttime); //5000 is good
    }

    //***state 1 reset to state 1 if start playing again
    if ((playstate == 2) && (cherry1 == true))
    {
      //Serial.println("state 1 recovery");
      playstate = 0;
      deadmantimer = millis();
    }

    //***state 2 reset to state 0
    if ((playstate == 2) && (glide4.read() == 0))
    {
      //Serial.println("state 0 ready");
      playstate = 0;
      fivenotes = 0;
    }





    //realtime glide fix update
    harmony_mixer.gain(0, harmony_mixer0 * performancegain);
    harmony_mixer.gain(1, harmony_mixer1 * glide4.read()*performancegain);
    harmony_mixer.gain(2, harmony_mixer2 * glide4.read()*performancegain);
    synth_selector.gain(2, .25 * glide4.read());
    synth_selector.gain(3, .25 * glide4.read());
    reverb_mixer_L.gain(1, (reverb_wet)*glide4.read());
    reverb_mixer_L.gain(2, (rain_gain)*glide4.read());
    reverb_mixer_L.gain(3, (shimmer_gain)*glide4.read());
    reverb_mixer_R.gain(1, (reverb_wet)*glide4.read());
    reverb_mixer_R.gain(2, (rain_gain)*glide4.read());
    reverb_mixer_R.gain(3, (shimmer_gain)*glide4.read());







    /////////////////////////////////
    //RAIN SYNTH
    /////////////////////////////////
    if (rain_gain > 0)
    {

      if (millis() >= nextdrip)
      {
        nextdrip = millis() + 19;
        int RA = random(1, 40);
        int RB = random(1, 40);
        int RC = random(1, 40);
        int RD = random(1, 40);
        int RE = random(1, 40);
        int RF = random(1, 40);
        int RG = random(1, 40);


        if ((RA < 2) && (millis() > holdoff1))
        {
          rain_drum1.noteOn();

          holdoff1 = millis() + rain_drumlength1;
        }
        if ((RB < 2) && (millis() > holdoff2))
        {
          rain_drum2.noteOn();
          holdoff2 = millis() + rain_drumlength2;
        }
        if ((RC < 2) && (millis() > holdoff3))
        {
          rain_drum3.noteOn();
          holdoff3 = millis() + rain_drumlength3;
        }
        if ((RD < 2) && (millis() > holdoff4))
        {
          rain_drum4.noteOn();
          holdoff4 = millis() + rain_drumlength4;
        }
        if ((RE < 2) && (millis() > holdoff5))
        {
          rain_drum5.noteOn();
          holdoff5 = millis() + rain_drumlength5;
        }
        if ((RF < 2) && (millis() > holdoff6))
        {
          rain_drum6.noteOn();
          holdoff6 = millis() + rain_drumlength6;
        }
        if ((RG < 2) && (millis() > holdoff7))
        {
          rain_drum7.noteOn();
          holdoff7 = millis() + rain_drumlength7;
        }
      }
    }





    //////////////////////////////////////////////////////////
    // 0-SHIMMER  plays wave and shimmer chords
    /////////////////////////////////////////////////////////

    if (buttonlogic == 0) //shimmer
    {
      shimmerplay = true;
      //  melody section start****************************************************************
      if ((cherry1 == true) &&  (button1toggle == false))
      {
        button1toggle = true;
        keycounter++;
        cherry1truetoggle = true;
        sticktimer = millis() + 500; //short time to allow player to slide into correct value
        if (USB_Midi_on == true )usbMIDI.sendNoteOff(midiconvert[scalefilter[hysterpreviousplayednotenumber1]], 0, 1);  //
        analogchordcalculate(hyster_closest_scale_number, 1); //start the glides
        hysterpreviousplayednotenumber1 = hyster_closest_scale_number;
        if (wokenstall == true)
        {
          envelope1.noteOn(); //play melody note
          if (USB_Midi_on == true ) usbMIDI.sendNoteOn(midiconvert[scalefilter[hyster_closest_scale_number]], harmony_mixer0 * 254, 1); // 61 = C#4
        }
      }
      if ((cherry1 == true) && ((sticktimer > millis()) || stickoverride)
          && (hyster_closest_scale_number != hysterpreviousplayednotenumber1))
      {
        envelope1.noteOff(); //?? want this new note strike
        if (USB_Midi_on == true )usbMIDI.sendNoteOff(midiconvert[scalefilter[hysterpreviousplayednotenumber1]], 0, 1); // 61 = C#4
        analogchordcalculate(hyster_closest_scale_number, 1);
        hysterpreviousplayednotenumber1 = hyster_closest_scale_number;
        if (wokenstall == true)
        {
          envelope1.noteOn(); //?? want this new note strike
          if (USB_Midi_on == true )usbMIDI.sendNoteOn(midiconvert[scalefilter[hyster_closest_scale_number]], harmony_mixer0 * 254, 1); // 61 = C#4
        }
      }
      if ((cherry1 == false) && (button1toggle == true))
      {
        envelope1.noteOff();
        if (USB_Midi_on == true )usbMIDI.sendNoteOff(midiconvert[scalefilter[hysterpreviousplayednotenumber1]], 0, 1); // 61 = C#4
        button1toggle = false;
      }

      if ((sticktimer > millis() || stickoverride))
      {
        waveform1.frequency(glide1.read() * 20000 * melody_octave);
      }
      /// melody section end****************************************************************

      /// set shimmer chords *****************************************************************
      if ((binarystate != lastbinarystate) && (millis() - plucktime > gliderate)) //shimmer glitch supression
      {
        for (int x = 0; x < 3; x++) //could be chordcart not special shimmer chords
        {
          if (binarystate == 0)shimmer[x] = shimmer1[x];
          if (binarystate == 1)shimmer[x] = shimmer2[x];
          if (binarystate == 2)shimmer[x] = shimmer3[x];
          if (binarystate == 3)shimmer[x] = shimmer4[x];
        }
        Playshimmer(shimmer[0], shimmer[1], shimmer[2]);
        lastbinarystate = binarystate;
      }
    }


    //////////////////////////////////////////////////////////
    // 1-CHORD  synth on melody, string chord loops
    /////////////////////////////////////////////////////////
    if (buttonlogic == 1) //chord
    {
      stringchordplay == true;
      // flute melody section start****************************************************************
      if ((cherry1 == true) &&  (button1toggle == false))
      {
        keycounter++;
        button1toggle = true;
        cherry1truetoggle = true;
        //buttonlaston1 = millis();
        sticktimer = millis() + 500; //short time to allow player to slide into correct value
        analogchordcalculate(hyster_closest_scale_number, 1); //start the glides
        hysterpreviousplayednotenumber1 = hyster_closest_scale_number;
        if (wokenstall == true)  envelope1.noteOn(); //play melody note
      }
      if ((cherry1 == true) && ((sticktimer > millis()) || stickoverride)
          && (hyster_closest_scale_number != hysterpreviousplayednotenumber1))
      {
        //envelope1.noteOff(); //?? want this new note strike
        hysterpreviousplayednotenumber1 = hyster_closest_scale_number;
        analogchordcalculate(hyster_closest_scale_number, 1);
        if (wokenstall == true) envelope1.noteOn();
      }
      if ((cherry1 == false) && (button1toggle == true))
      {
        envelope1.noteOff();
        button1toggle = false;
      }

      //update chords ************************************************
      if (binarystate != lastbinarystate)
      {
        firstplay = true;
        unisonclock = 0;
        for (int x = 0; x < 24; x++) //could be chordcartsize
        {
          if (binarystate == 0)
          {
            chordcart1[x] = chordcart1A[x];
            chordcart2[x] = chordcart2A[x];
            chordcart3[x] = chordcart3A[x];
          }
          if (binarystate == 1)
          {
            chordcart1[x] = chordcart1B[x];
            chordcart2[x] = chordcart2B[x];
            chordcart3[x] = chordcart3B[x];
          }
          if (binarystate == 2)
          {
            chordcart1[x] = chordcart1C[x];
            chordcart2[x] = chordcart2C[x];
            chordcart3[x] = chordcart3C[x];
          }
          if (binarystate == 3)
          {
            chordcart1[x] = chordcart1D[x];
            chordcart2[x] = chordcart2D[x];
            chordcart3[x] = chordcart3D[x];
          }
        }
        lastbinarystate = binarystate;
      }

      if ((sticktimer > millis() || stickoverride))
      {
        waveform1.frequency(glide1.read() * 20000 * melody_octave);
      }
    }



    //////////////////////////////////////////////////////////
    // 2-HARMONY   synth melody synth third and fifth
    /////////////////////////////////////////////////////////
    if (buttonlogic == 2) //chord
    {

      // flute melody section start****************************************************************
      if ((cherry1 == true) &&  (button1toggle == false))
      {
        keycounter++;
        button1toggle = true;
        cherry1truetoggle = true;
        sticktimer = millis() + 500; //short time to allow player to slide into correct value
        if (USB_Midi_on == true)usbMIDI.sendNoteOff(midiconvert[scalefilter[hysterpreviousplayednotenumber1]], 0, 1);
        analogchordcalculate(hyster_closest_scale_number, 1); //start the glides
        hysterpreviousplayednotenumber1 = hyster_closest_scale_number;
        //        locktarget2 = target2 * harmony1_octave;
        //        locktarget3 = target3 * harmony2_octave;
        locktarget2 = justifiedtarget2 * harmony1_octave;
        locktarget3 = justifiedtarget3 * harmony2_octave;
        if (wokenstall == true)
        {
          envelope1.noteOn(); //play melody note
          if (USB_Midi_on == true ) usbMIDI.sendNoteOn(midiconvert[scalefilter[hyster_closest_scale_number]], harmony_mixer0 * 254, 1);
        }
      }


      if ((cherry1 == true) && ((sticktimer > millis()) || stickoverride)
          && (hyster_closest_scale_number != hysterpreviousplayednotenumber1))
      {
        if (USB_Midi_on == true )usbMIDI.sendNoteOff(midiconvert[scalefilter[hysterpreviousplayednotenumber1]], 0, 1);
        analogchordcalculate(hyster_closest_scale_number, 1);
        hysterpreviousplayednotenumber1 = hyster_closest_scale_number;
        //        locktarget2 = target2 * harmony1_octave;
        //        locktarget3 = target3 * harmony2_octave;
        locktarget2 = justifiedtarget2 * harmony1_octave;
        locktarget3 = justifiedtarget3 * harmony2_octave;
        if (USB_Midi_on == true ) usbMIDI.sendNoteOn(midiconvert[scalefilter[hyster_closest_scale_number]], harmony_mixer0 * 254, 1);
        //envelope1.noteOn();
      }
      if ((cherry1 == false) && (button1toggle == true))
      {
        //buttonlastoff1 = millis();
        envelope1.noteOff();
        if (USB_Midi_on == true )usbMIDI.sendNoteOff(midiconvert[scalefilter[hysterpreviousplayednotenumber1]], 0, 1);
        button1toggle = false;
      }

      //****button 2********************************************************************************
      if ((cherry2 == true) &  (button2toggle == false))
      {
        button2toggle = true;
        waveform2.frequency(locktarget2); //
        envelope2.noteOn();
        if (USB_Midi_on == true ) usbMIDI.sendNoteOn(midiconvert[scalefilter[hyster_closest_scale_number + 4]], harmony_mixer0 * 254, 2);
        hysterpreviousplayednotenumber2 = hyster_closest_scale_number;
      }
      if ((cherry2 == false) &  (button2toggle == true))
      {
        button2toggle = false;
        envelope2.noteOff();
        if (USB_Midi_on == true )usbMIDI.sendNoteOff(midiconvert[scalefilter[hysterpreviousplayednotenumber2 + 4]], 0, 2);
      }
      //****button 3********************************************************************************
      if ((cherry3 == true) &&  (button3toggle == false))
      {
        button3toggle = true;
        waveform3.frequency(locktarget3);//
        envelope3.noteOn();
        if (USB_Midi_on == true ) usbMIDI.sendNoteOn(midiconvert[scalefilter[hyster_closest_scale_number + 7]], harmony_mixer0 * 254, 3);
        hysterpreviousplayednotenumber3 = hyster_closest_scale_number;
        //Serial.print("enveflope3:");
        //Serial.println(locktarget3);

      }
      if ((cherry3 == false) &&  (button3toggle == true))
      {
        button3toggle = false;
        envelope3.noteOff();
        if (USB_Midi_on == true )usbMIDI.sendNoteOff(midiconvert[scalefilter[hysterpreviousplayednotenumber3 + 7]], 0, 3);
      }

      //update frequencies
      if ((sticktimer > millis() || stickoverride))
      {
        waveform1.frequency(glide1.read() * 20000 * melody_octave);
      }

    }


    //////////////////////////////////////////////////////////
    // 4-STRINGCHORD (unfavored) strings on melody, string analogchord -generated
    /////////////////////////////////////////////////////////
    if (buttonlogic == 4) //chord
    {
      playstate = 1;
      glide4.amplitude(1, fadeintime); //10000 is good
      // first button****************************************************************
      if ((cherry1 == true) &&  (button1toggle == false))
      {
        keycounter++;
        button1toggle = true;
        cherry1truetoggle = true;
        sticktimer = millis() + 500; //short time to allow player to slide into correct value
        analogchordcalculate(hyster_closest_scale_number, 1); //start the glides
        hysterpreviousplayednotenumber1 = hyster_closest_scale_number;
        locktarget1 = justifiedtarget1 * mel_string_octave;
        locktarget2 = justifiedtarget2 * harm_string_octave;
        locktarget3 = justifiedtarget3 * harm_string_octave;
        if (wokenstall == true)
        {
          string2.noteOn(locktarget1, 1);
          sine2.frequency(locktarget1);
          dc2.amplitude(1, 20);
          sine6.frequency(locktarget1 / 2);
          dc6.amplitude(1, 20);

        }
      }

      if ((cherry1 == true) && ((sticktimer > millis()) || stickoverride)
          && (hyster_closest_scale_number != hysterpreviousplayednotenumber1))
      {
        hysterpreviousplayednotenumber1 = hyster_closest_scale_number;
        analogchordcalculate(hyster_closest_scale_number, 1); //start the glides
        locktarget1 = justifiedtarget1 * mel_string_octave;
        locktarget2 = justifiedtarget2 * harm_string_octave;
        locktarget3 = justifiedtarget3 * harm_string_octave;
        string2.frequency(locktarget1);
        sine2.frequency(locktarget1);
        dc2.amplitude(1, 20);
        sine6.frequency(locktarget1 / 2);
        dc6.amplitude(1, 20);

        string3.frequency(locktarget2);
        sine3.frequency(locktarget2);
        dc3.amplitude(1, 20);
        sine7.frequency(locktarget2 / 2);
        dc7.amplitude(1, 20);

        string4.frequency(locktarget3);
        sine4.frequency(locktarget3);
        dc4.amplitude(1, 20);
        sine8.frequency(locktarget3 / 2);
        dc8.amplitude(1, 20);

      }
      if ((cherry1 == false) && (button1toggle == true))
      {
        button1toggle = false;
      }


      // string melody section start****************************************************************
      if ((cherry2 == true) &&  (button2toggle == false))
      {
        button2toggle = true;
        cherry2truetoggle = true;
        sleeptimer = millis() + 5000;
        if (woken == false) wokentime = millis();
        woken = true;
        keycounter++;
        sticktimer = millis() + 500; //short time to allow player to slide into correct value
        if (wokenstall == true)
        {
          string3.noteOn(locktarget2, 1);
          sine3.frequency(locktarget2);
          dc3.amplitude(1, 20);
          sine7.frequency(locktarget2 / 2);
          dc7.amplitude(1, 20);

        }
      }

      if ((cherry2 == false) && (button2toggle == true))
      {
        button2toggle = false;
      }


      // string melody section start****************************************************************
      if ((cherry3 == true) &&  (button3toggle == false))
      {
        button3toggle = true;
        cherry3truetoggle = true;
        sleeptimer = millis() + 5000;
        if (woken == false) wokentime = millis();
        woken = true;
        keycounter++;
        if (wokenstall == true)
        {
          string4.noteOn(locktarget3, 1);
          sine4.frequency(locktarget3);
          dc4.amplitude(1, 20);
          sine8.frequency(locktarget3 / 2);
          dc8.amplitude(1, 20);

        }
      }


      if ((cherry3 == false) && (button3toggle == true))
      {
        button3toggle = false;
      }


    }


    //////////////////////////////////////////////////////////
    // 5-SYNTHCHORD  plays wave on melody and wave on chords
    /////////////////////////////////////////////////////////
    if (buttonlogic == 5) //chord
    {
      tonechordplay = true;
      ///one time intializer****************************************************************

      // melody section start****************************************************************
      if ((cherry1 == true) && (do1once == false))
      {
        do1once = true;
        keycounter++;
        cherry1truetoggle = true;
        switchup = !switchup;
        analogchordcalculate(hyster_closest_scale_number, 1);
        sticktimer = millis() + 500;
        analogchordcalculate(hyster_closest_scale_number, 1);
        sticktimer = millis() + 500;
        if (wokenstall == true)  envelope1.noteOn();
      }
      if ((cherry1 == true) && (sticktimer > millis() || stickoverride)
          && (hyster_closest_scale_number != hysterpreviousplayednotenumber1))
      {
        hysterpreviousplayednotenumber1 = hyster_closest_scale_number;
        analogchordcalculate(hyster_closest_scale_number, 1);
      }

      if (cherry1 == false)
      {
        do1once = false;
        envelope1.noteOff();
      }


      //update chords ************************************************
      if (binarystate != lastbinarystate)
      {
        for (int x = 0; x < 24; x++) //could be chordcartsize
        {
          if (binarystate == 0)
          {
            chordcart1[x] = chordcart1A[x];
            chordcart2[x] = chordcart2A[x];
            chordcart3[x] = chordcart3A[x];
          }
          if (binarystate == 1)
          {
            chordcart1[x] = chordcart1B[x];
            chordcart2[x] = chordcart2B[x];
            chordcart3[x] = chordcart3B[x];
          }
          if (binarystate == 2)
          {
            chordcart1[x] = chordcart1C[x];
            chordcart2[x] = chordcart2C[x];
            chordcart3[x] = chordcart3C[x];
          }
          if (binarystate == 3)
          {
            chordcart1[x] = chordcart1D[x];
            chordcart2[x] = chordcart2D[x];
            chordcart3[x] = chordcart3D[x];
          }
        }
        lastbinarystate = binarystate;
      }



      if ((sticktimer > millis() || stickoverride))
      {
        waveform1.frequency(glide1.read() * 20000 * melody_octave);
      }
    }


    //////////////////////////////////////////////////////////
    // 6=UNASSINGED plays chord progressions using chord keying drums and rhythm notes
    /////////////////////////////////////////////////////////
    if (buttonlogic == 6) //
    {
    

      // flute melody section start****************************************************************
      if ((cherry1 == true) &&  (button1toggle == false))
      {
        keycounter++;
        button1toggle = true;
        cherry1truetoggle = true;
        sticktimer = millis() + 500; //short time to allow player to slide into correct value
        if (USB_Midi_on == true)usbMIDI.sendNoteOff(midiconvert[scalefilter[hysterpreviousplayednotenumber1]], 0, 1);
        analogchordcalculate(hyster_closest_scale_number, 1); //start the glides
        hysterpreviousplayednotenumber1 = hyster_closest_scale_number;
        if (wokenstall == true)
        {
          envelope1.noteOn(); //play melody note
          if (USB_Midi_on == true ) usbMIDI.sendNoteOn(midiconvert[scalefilter[hyster_closest_scale_number]], harmony_mixer0 * 254, 1);
        }
      }


      if ((cherry1 == true) && ((sticktimer > millis()) || stickoverride)
          && (hyster_closest_scale_number != hysterpreviousplayednotenumber1))
      {
        if (USB_Midi_on == true )usbMIDI.sendNoteOff(midiconvert[scalefilter[hysterpreviousplayednotenumber1]], 0, 1);
        analogchordcalculate(hyster_closest_scale_number, 1);
        hysterpreviousplayednotenumber1 = hyster_closest_scale_number;
        if (USB_Midi_on == true ) usbMIDI.sendNoteOn(midiconvert[scalefilter[hyster_closest_scale_number]], harmony_mixer0 * 254, 1);
        //envelope1.noteOn();
      }
      if ((cherry1 == false) && (button1toggle == true))
      {
        //buttonlastoff1 = millis();
        envelope1.noteOff();
        if (USB_Midi_on == true )usbMIDI.sendNoteOff(midiconvert[scalefilter[hysterpreviousplayednotenumber1]], 0, 1);
        button1toggle = false;
      }

      //****button 2********************************************************************************
      if ((cherry2 == true) &  (button2toggle == false))
      {
        button2toggle = true;
        waveform2.frequency(locktarget2); //
        envelope2.noteOn();
        if (USB_Midi_on == true ) usbMIDI.sendNoteOn(midiconvert[scalefilter[hyster_closest_scale_number]], harmony_mixer0 * 254, 2);
        hysterpreviousplayednotenumber2 = hyster_closest_scale_number;
      }
      if ((cherry2 == false) &  (button2toggle == true))
      {
        button2toggle = false;
        envelope2.noteOff();
        if (USB_Midi_on == true )usbMIDI.sendNoteOff(midiconvert[scalefilter[hysterpreviousplayednotenumber2]], 0, 2);
      }
      //****button 3********************************************************************************
      if ((cherry3 == true) &&  (button3toggle == false))
      {
        button3toggle = true;
        waveform3.frequency(locktarget3);//
        envelope3.noteOn();
        if (USB_Midi_on == true ) usbMIDI.sendNoteOn(midiconvert[scalefilter[hyster_closest_scale_number]], harmony_mixer0 * 254, 3);
        hysterpreviousplayednotenumber3 = hyster_closest_scale_number;
        //Serial.print("enveflope3:");
        //Serial.println(locktarget3);

      }
      if ((cherry3 == false) &&  (button3toggle == true))
      {
        button3toggle = false;
        envelope3.noteOff();
        if (USB_Midi_on == true )usbMIDI.sendNoteOff(midiconvert[scalefilter[hysterpreviousplayednotenumber3]], 0, 3);
      }

      //update frequencies
      if ((sticktimer > millis() || stickoverride))
      {
        waveform1.frequency(glide1.read() * 20000 * melody_octave);
      }
 
    }


    //////////////////////////////////////////////////////////
    // 7=CHORDPROGRESSION plays chord progressions using chord keying drums and rhythm notes
    /////////////////////////////////////////////////////////
    if (buttonlogic == 7) //chord
    {
      stringchordplay = true;
      // flute melody section start****************************************************************
      if ((cherry1 == true) &&  (button1toggle == false))
      {
        button1toggle = true;
        cherry1truetoggle = true;
        keycounter++;
        //buttonlaston1 = millis();
        sticktimer = millis() + 500; //short time to allow player to slide into correct value
        analogchordcalculate(hyster_closest_scale_number, 1); //start the glides
        hysterpreviousplayednotenumber1 = hyster_closest_scale_number;
        if (wokenstall == true)  envelope1.noteOn(); //play melody note
      }
      if ((cherry1 == true) && ((sticktimer > millis()) || stickoverride)
          && (hyster_closest_scale_number != hysterpreviousplayednotenumber1))
      {
        envelope1.noteOff(); //?? want this new note strike
        hysterpreviousplayednotenumber1 = hyster_closest_scale_number;
        analogchordcalculate(hyster_closest_scale_number, 1);
        if (wokenstall == true) envelope1.noteOn();
      }
      if ((cherry1 == false) && (button1toggle == true))
      {
        //buttonlastoff1 = millis();
        envelope1.noteOff();
        button1toggle = false;
      }

      ///flute melody section end****************************************************************


      //update chords ************************************************
      if (binarystate != lastbinarystate) progressiontoggle = true;
      lastbinarystate = binarystate;

      if (binarystate == 0)
      {
        chordselection = chordprogression1[progressionmeasures];
        progressionlength = progressionlength1;
      }
      else if (binarystate == 1)
      {
        chordselection = chordprogression2[progressionmeasures];
        progressionlength = progressionlength2;
      }
      else if (binarystate == 2)
      {
        chordselection = chordprogression3[progressionmeasures];
        progressionlength = progressionlength3;
      }
      else if (binarystate == 3)
      {
        chordselection = chordprogression4[progressionmeasures];
        progressionlength = progressionlength4;
      }

      if (progressiontoggle == true) //reset on new button press
      {
        progressionmeasures = 0;
        progressiontoggle = false;

      }

      if (chordselection != lastchordselection) //!!like more than 4
      {
        for (int x = 0; x < 24; x++) //could be chordcartsize
        {
          if (chordselection == 0)
          {
            chordcart1[x] = chordcart1A[x];//
            chordcart2[x] = chordcart2A[x];
            chordcart3[x] = chordcart3A[x];
          }
          if (chordselection == 1)
          {
            chordcart1[x] = chordcart1B[x];
            chordcart2[x] = chordcart2B[x];
            chordcart3[x] = chordcart3B[x];
          }
          if (chordselection == 2)
          {
            chordcart1[x] = chordcart1C[x];
            chordcart2[x] = chordcart2C[x];
            chordcart3[x] = chordcart3C[x];
          }
          if (chordselection == 3)
          {
            chordcart1[x] = chordcart1D[x];
            chordcart2[x] = chordcart2D[x];
            chordcart3[x] = chordcart3D[x];
          }
        }
        lastchordselection = chordselection;
      }


      if ((sticktimer > millis() || stickoverride))
      {
        waveform1.frequency(glide1.read() * 20000 * melody_octave);
      }


    }



    //////////////////////////////////////////////////////////
    // QUANTPLAYER plays bass guitar
    /////////////////////////////////////////////////////////
    if (buttonlogic == 8) //base
    {
      stringchordplay = true;
      // flute melody section start****************************************************************


      if (cherry1 == true)  notetoggle1 = true;

      if ((cherry1 == true) &&  (button1toggle == false))
      {
        keycounter++;
        button1toggle = true;
        cherry1truetoggle = true;
        instantbeat = true;
        //buttonlaston1 = millis();
        sticktimer = millis() + 500; //short time to allow player to slide into correct value
        analogchordcalculate(hyster_closest_scale_number, 1); //start the glides
        hysterpreviousplayednotenumber1 = hyster_closest_scale_number;
      }

      if ((cherry1 == true) && ((sticktimer > millis()) || stickoverride)
          && (hyster_closest_scale_number != hysterpreviousplayednotenumber1))
      {
        hysterpreviousplayednotenumber1 = hyster_closest_scale_number;
        analogchordcalculate(hyster_closest_scale_number, 1);
      }

      if ((cherry1 == false) && (button1toggle == true))
      {
        envelope1.noteOff();
        notetoggle1 = false;
        button1toggle = false;
      }

      if ((sticktimer > millis() || stickoverride))
      {
        waveform1.frequency(glide1.read() * 20000 * melody_octave);
        waveform2.frequency(glide2.read() * 20000 * harmony1_octave);
        waveform3.frequency(glide3.read() * 20000 * harmony2_octave);
      }
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////
    // UPDATE TIME SENSITIVE PARAMETERS
    //////////////////////////////////////////////////////////////////////////////////////////////////

    /////////////////// UPDATE GLIDES ON PEAK DETECTION ////////////////////////

    //string resets can turn off if no strings
    if (dc1.read() == 1) dc1.amplitude(0, 2000);
    if (dc2.read() == 1) dc2.amplitude(0, 2000);
    if (dc3.read() == 1) dc3.amplitude(0, 2000);
    if (dc4.read() == 1) dc4.amplitude(0, 2000);
    if (dc5.read() == 1) dc5.amplitude(0, 3000);
    if (dc6.read() == 1) dc6.amplitude(0, 3000);
    if (dc7.read() == 1) dc7.amplitude(0, 3000);
    if (dc8.read() == 1) dc8.amplitude(0, 3000);

    shimmermixer1.gain(0, chordglide0.read()*.05);
    shimmermixer1.gain(1, chordglide1.read()*.03);
    shimmermixer1.gain(2, chordglide2.read()*.01);
    shimmermixer1.gain(3, chordglide3.read()*.05);
    shimmermixer2.gain(0, chordglide4.read()*.03);
    shimmermixer2.gain(1, chordglide5.read()*.01);
    //    rain_mixer3.gain(0, glide5.read());
    //    rain_mixer3.gain(1, glide5.read());
    //    shimmermixer3.gain(0, glide4.read());
    //    shimmermixer3.gain(1, glide4.read());


    if (millis() > uncolor + 300)
    {
      analogWrite(redPin, 256);
      analogWrite(bluePin, 256);
      analogWrite(greenPin, 256);
    }


    //////////////////////////////////////////
    //DRUM CLOCKWORK/SHIMMER CLOCKWORK
    //////////////////////////////////////////

    //clocked section ******************************************************
    if (millis() >= fnext)
    {
      fnext = millis() + espeed;
      //play drums****************************************************
      if (drumplay == true)
      {
        //clocked section ********************************************************
     
        //play drums****************************************************

        if (drumcartridge1[euclidclock1] == true)
        {
          drum1.noteOn();
          if (USB_Midi_on == true)
          {
            usbMIDI.sendNoteOff(drumMIDI1, 0, 4);
            usbMIDI.sendNoteOn(drumMIDI1, drum_volume1*255, 4);
          }
        }

        if (drumcartridge2[euclidclock2] == true)
        {
          drum2.noteOn();
          if (USB_Midi_on == true)
          {
            usbMIDI.sendNoteOff(drumMIDI2, 0, 4);
            usbMIDI.sendNoteOn(drumMIDI2, drum_volume2*255, 4);
          }
        }

        if (drumcartridge3[euclidclock3] == true)
        {
          drum3.noteOn();
          if (USB_Midi_on == true)
          {
            usbMIDI.sendNoteOff(drumMIDI3, 0, 4);
            usbMIDI.sendNoteOn(drumMIDI3, drum_volume3*255, 4);
          }
        }

        if (drumcartridge4[euclidclock4] == true)
        {
          drum4.noteOn();
          if (USB_Midi_on == true)
          {
            usbMIDI.sendNoteOff(drumMIDI4, 0, 4);
            usbMIDI.sendNoteOn(drumMIDI4, drum_volume4*255, 4);
          }
        }

        if (drumcartridge5[euclidclock5] == true)
        {
          drum5.noteOn();
          if (USB_Midi_on == true)
          {
            usbMIDI.sendNoteOff(drumMIDI5, 0, 4);
            usbMIDI.sendNoteOn(drumMIDI5, drum_volume5*255, 4);
          }
        }


      //play notes*****************************************
      if (drumcartridge6[euclidclock6] == true) //timing by euclid drum 6
      {
        if (stringchordplay == true)
        {
          if (chordcart1[unisonclock] != 99)
          {
            if (chromatic_lock == false) nowplay = harm_string_octave * chromatic[scalefilter[chordcart1[unisonclock]]]; //am i chromatic, am i offset by melody
            else nowplay = harm_string_octave * chromatic[chordcart1[unisonclock]];
            if (firstplay == true) Playstring(nowplay, 0);
          }
          if (chordcart2[unisonclock] != 99)
          {
            if (chromatic_lock == false) nowplay = harm_string_octave * chromatic[scalefilter[chordcart2[unisonclock]]]; //am i chromatic, am i offset by melody
            else nowplay = harm_string_octave * chromatic[chordcart2[unisonclock]];
            if (firstplay == true) Playstring(nowplay, 0);
          }
          if (chordcart3[unisonclock] != 99)
          {
            if (chromatic_lock == false) nowplay = harm_string_octave * chromatic[scalefilter[chordcart3[unisonclock]]]; //am i chromatic, am i offset by melody
            else nowplay = harm_string_octave * chromatic[chordcart3[unisonclock]];
            if (firstplay == true) Playstring(nowplay, 0);
          }
        }
        if (tonechordplay == true)
        {
          if ((chordcart1[unisonclock2] != 99))
          {
            if (chromatic_lock == false) nowplay = harmony2_octave * chromatic[scalefilter[chordcart1[unisonclock2]]]; //am i chromatic, am i offset by melody
            else nowplay = harmony2_octave * chromatic[chordcart1[unisonclock2]];
            switchup = !switchup;
            sticktimer = millis() + 500;
            switchup2 = !switchup2;
            if (switchup2 == true)
            {
              waveform2.frequency(nowplay);
              envelope3.noteOff();
              envelope2.noteOn();
            }
            else
            {
              waveform3.frequency(nowplay);
              envelope2.noteOff();
              envelope3.noteOn();
              //Serial.println("two");
            }
            if (unisonclock2 < 24) unisonclock2++;
          }
        }
        if (unisonclock < 24) unisonclock++;
      }




      //if (shimmerplay == true)Playshimmer(shimmer[0], shimmer[1], shimmer[2]);

      //update all the clocks*****************************************
      euclidclock1++;
      if (euclidclock1 >= bins1) euclidclock1 = 0;
      euclidclock2++;
      if (euclidclock2 >= bins2) euclidclock2 = 0;
      euclidclock3++;
      if (euclidclock3 >= bins3) euclidclock3 = 0;
      euclidclock4++;
      if (euclidclock4 >= bins4) euclidclock4 = 0;
      euclidclock5++;
      if (euclidclock5 >= bins5) euclidclock5 = 0;
      euclidclock6++;
      if (euclidclock6 >= bins6)
      {
        measures++;
        euclidclock6 = 0;
        if (progressionmeasures < progressionlength) progressionmeasures++;
        unisonclock = 0;
        unisonclock2 = 0;
        if (stopplay_a == false) Colorme(modecount);
      }
    }
    
    }


    //////////////////////////////////////////
    //DRUM PREVIEW
    //////////////////////////////////////////
    if ((displayMode == 1) && (drumpreview == 1))
    {
      //clocked section ********************************************************
      if (millis() >= pnext)
      {
        pnext = millis() + espeed;

        //play drums****************************************************

        if (drumcartridge1[peuclidclock1] == true)
        {
          drum1.noteOn();
          if (USB_Midi_on == true)
          {
            usbMIDI.sendNoteOff(60, 0, 4);
            usbMIDI.sendNoteOn(60, 125, 4);
          }
        }

        if (drumcartridge2[peuclidclock2] == true)
        {
          drum2.noteOn();
          if (USB_Midi_on == true)
          {
            usbMIDI.sendNoteOff(61, 0, 4);
            usbMIDI.sendNoteOn(61, 125, 4);
          }
        }

        if (drumcartridge3[peuclidclock3] == true)
        {
          drum3.noteOn();
          if (USB_Midi_on == true)
          {
            usbMIDI.sendNoteOff(62, 0, 4);
            usbMIDI.sendNoteOn(62, 125, 4);
          }
        }

        if (drumcartridge4[peuclidclock4] == true)
        {
          drum4.noteOn();
          if (USB_Midi_on == true)
          {
            usbMIDI.sendNoteOff(63, 0, 4);
            usbMIDI.sendNoteOn(63, 125, 4);
          }
        }

        if (drumcartridge5[peuclidclock5] == true)
        {
          drum5.noteOn();
          if (USB_Midi_on == true)
          {
            usbMIDI.sendNoteOff(64, 0, 4);
            usbMIDI.sendNoteOn(64, 125, 4);
          }
        }


        //update all the clocks*****************************************
        peuclidclock1++;
        if (peuclidclock1 >= bins1) peuclidclock1 = 0;
        peuclidclock2++;
        if (peuclidclock2 >= bins2) peuclidclock2 = 0;
        peuclidclock3++;
        if (peuclidclock3 >= bins3) peuclidclock3 = 0;
        peuclidclock4++;
        if (peuclidclock4 >= bins4) peuclidclock4 = 0;
        peuclidclock5++;
        if (peuclidclock5 >= bins5) peuclidclock5 = 0;
        peuclidclock6++;
        if (peuclidclock6 >= bins6)
        {
          measures++;
          peuclidclock6 = 0;
          unisonclock = 0;
          Colorme(modecount);
        }
      }
    }

    //////////////////////////////////////////
    //PARAMETER INTERFACE
    //////////////////////////////////////////

    int category = 0;
    float fvalue = 999;
    //receive input from console
    // if there's any serial available, read it:
    while (Serial.available() > 0)
    {
      //crazy approach to work with Serial monitor and Putty
      //changed usb to serial only (no audio or midi)
      // look for the next valid integer in the incoming serial stream:
      category = Serial.parseInt();
      // do it again:
      fvalue = Serial.parseInt();
      if (Serial.available() > 0) Serial.read(); //flush becuase parse is buggy on CR+NL
      // look for the newline. That's the end of the input:
      if ((fvalue != 999) || (onetime == true))
      {
        printscreen = true;
        if (category == 0) integerinput[0] = fvalue ;
        if (category == 1) integerinput[1] = fvalue ;
        if (category == 2) integerinput[2] = fvalue ;
        if (category == 3) integerinput[3] = fvalue ;
        if (category == 4) integerinput[4] = fvalue ;
        if (category == 5) integerinput[5] = fvalue ;
        if (category == 6) integerinput[6] = fvalue ;
        if (category == 7) integerinput[7] = fvalue ;
        if (category == 8) integerinput[8] = fvalue ;
        if (category == 9) integerinput[9] = fvalue ;
        if (category == 10) integerinput[10] = fvalue ;
        if (category == 11) integerinput[11] = fvalue ;
        if (category == 12) integerinput[12] = fvalue ;
        if (category == 13) integerinput[13] = fvalue ;
        if (category == 14) integerinput[14] = fvalue ;
        if (category == 15) integerinput[15] = fvalue ;
        if (category == 16) integerinput[16] = fvalue ;
        if (category == 17) integerinput[17] = fvalue ;
        if (category == 18) integerinput[18] = fvalue ;
        if (category == 19) integerinput[19] = fvalue ;
        if (category == 20) integerinput[20] = fvalue ;
        if (category == 21) integerinput[21] = fvalue ;
        if (category == 22) integerinput[22] = fvalue ;
        if (category == 23) integerinput[23] = fvalue ;
        if (category == 24) integerinput[24] = fvalue ;
        if (category == 25) integerinput[25] = fvalue ;
        if (category == 26) integerinput[26] = fvalue ;
        if (category == 27) integerinput[27] = fvalue ;
        if (category == 28) integerinput[28] = fvalue ;
        if (category == 29) integerinput[29] = fvalue ;
        if (category == 30) integerinput[30] = fvalue ;
        if (category == 31) integerinput[31] = fvalue ;
        if (category == 32) integerinput[32] = fvalue ;
        if (category == 33) integerinput[33] = fvalue ;
        if (category == 34) integerinput[34] = fvalue ;
        if (category == 35) integerinput[35] = fvalue ;
        if (category == 36) integerinput[36] = fvalue ;
        if (category == 37) integerinput[37] = fvalue ;
        if (category == 38) integerinput[38] = fvalue ;
        if (category == 39) integerinput[39] = fvalue ;
        if (category == 40) integerinput[40] = fvalue ;
        if (category == 41) integerinput[41] = fvalue ;
        if (category == 42) integerinput[42] = fvalue ;
        if (category == 43) integerinput[43] = fvalue ;
        if (category == 44) integerinput[44] = fvalue ;
        if (category == 45) integerinput[45] = fvalue ;
        if (category == 46) integerinput[46] = fvalue ;
        if (category == 47) integerinput[47] = fvalue ;
        if (category == 48) integerinput[48] = fvalue ;
        if (category == 49) integerinput[49] = fvalue ;
        if (category == 50) integerinput[50] = fvalue ;
        if (category == 51) integerinput[51] = fvalue ;
        if (category == 52) integerinput[52] = fvalue ;
        if (category == 53) integerinput[53] = fvalue ;
        if (category == 54) integerinput[54] = fvalue ;
        if (category == 55) integerinput[55] = fvalue ;
        if (category == 56) integerinput[56] = fvalue ;
        if (category == 57) integerinput[57] = fvalue ;
        if (category == 58) integerinput[58] = fvalue ;
        if (category == 59) integerinput[59] = fvalue ;
        if (category == 60) integerinput[60] = fvalue ;
        if (category == 61) integerinput[61] = fvalue ;
        if (category == 62) integerinput[62] = fvalue ;
        if (category == 63) integerinput[63] = fvalue ;
        if (category == 64) integerinput[64] = fvalue ;
        if (category == 65) integerinput[65] = fvalue ;
        if (category == 66) integerinput[66] = fvalue ;
        if (category == 67) integerinput[67] = fvalue ;
        if (category == 68) integerinput[68] = fvalue ;
        if (category == 69) integerinput[69] = fvalue ;
        if (category == 70) integerinput[70] = fvalue ;
        if (category == 71) integerinput[71] = fvalue ;
        if (category == 72) integerinput[72] = fvalue ;
        if (category == 73) integerinput[73] = fvalue ;
        if (category == 74) integerinput[74] = fvalue ;
        if (category == 75) integerinput[75] = fvalue ;
        if (category == 76) integerinput[76] = fvalue ;
        if (category == 77) integerinput[77] = fvalue ;
        if (category == 78) integerinput[78] = fvalue ;
        if (category == 79) integerinput[79] = fvalue ;
        if (category == 80) integerinput[80] = fvalue ;
        if (category == 81) integerinput[81] = fvalue ;
        if (category == 82) integerinput[82] = fvalue ;
        if (category == 83) integerinput[83] = fvalue ;
        if (category == 84) integerinput[84] = fvalue ;
        if (category == 85) integerinput[85] = fvalue ;
        if (category == 86) integerinput[86] = fvalue ;
        if (category == 87) integerinput[87] = fvalue ;
        if (category == 88) integerinput[88] = fvalue ;
        if (category == 89) integerinput[89] = fvalue ;
        if (category == 90) integerinput[90] = fvalue ;
        if (category == 91) integerinput[91] = fvalue ;
        if (category == 92) integerinput[92] = fvalue ;
        if (category == 93) integerinput[93] = fvalue ;
        if (category == 94) integerinput[94] = fvalue ;
        if (category == 95) integerinput[95] = fvalue ;
        if (category == 96) integerinput[96] = fvalue ;
        if (category == 97) integerinput[97] = fvalue ;
        if (category == 98) integerinput[98] = fvalue ;
        if (category == 99) integerinput[99] = fvalue ;
        if (category == 100) integerinput[100] = fvalue ;
        if (category == 101) integerinput[101] = fvalue ;
        if (category == 102) integerinput[102] = fvalue ;
        if (category == 103) integerinput[103] = fvalue ;
        if (category == 104) integerinput[104] = fvalue ;
        if (category == 105) integerinput[105] = fvalue ;

        fvalue = 200;
      }

      // SELECT DISPLAY
      if (category == 0) byteparameter[0] = map(integerinput[0], 0, 255, 0, 255);
      if (byteparameter[0] > 255)byteparameter[0] = 255;
      displayMode = map(byteparameter[0], 0, 255, 0, 255);

      for (int x = 0; x < 40; x++) Serial.println();
    }


    //////////////////////////////////////////
    // SYNTH PARAMETER DISPLAY
    //////////////////////////////////////////
    if (printscreen == true)
    {
      //one-time initialize for keyboard logic
      playstate = 0;//update fade variables
      envelope1.noteOff();
      envelope2.noteOff();
      envelope3.noteOff();
      //printscreen = true;
      measures = 0;
      keycounter = 0;
      glide5.amplitude(0);
      glide4.amplitude(0, 1);
      glide5.amplitude(0, 1);
      stopplay_a = true;
      stopplay_b = true;
      fnext = millis() + 1000;

      // SELECT DISPLAY

      if (displayMode == 0) printscreen = false;
      Serial.print("0) display screen (0=synthC,1=drums,2=save,3=test, 4-PPL tune): ");
      displayMode = byteparameter[0];
      switch (displayMode)
      {
        case 0:
          Serial.println("0-synthesizer controls");
          break;
        case 1:
          Serial.println("1-drum controls");
          break;
        case 2:
          Serial.println("2-save settings");
          break;
        case 3:
          Serial.println("3-hardware monitor");
          break;
        case 4:
          Serial.println("4-PPL tuning");
          break;
        default:
          Serial.println("default");
          displayMode = 0;
          break;
      }
      Serial.print("PRESET: ");
      Serial.println(modecount);

      if (displayMode == 0) Serial.println("*********************common synth controls*********************");


      if (displayMode == 0) Serial.print("1) glide rate (ms): ");
      if (category == 1)byteparameter[1] = map(integerinput[1], 0, 255, 0, 255);
      if (byteparameter[1] > 255)byteparameter[1] = 255;
      glide_rate = map(byteparameter[1], 0, 255, 0, 255);
      if (displayMode == 0) Serial.print(glide_rate);

      if (displayMode == 0) Serial.print("\t2) reverb wet (0-100): ");
      if (category == 2)byteparameter[2] = map(integerinput[2], 0, 100, 0, 255);
      if (byteparameter[2] > 255)byteparameter[2] = 255;
      reverb_wet = float(map(byteparameter[2], 0, 255, 0, 100)) / 100;
      reverb_mixer_L.gain(0, 1.0 - reverb_wet);
      reverb_mixer_L.gain(1, reverb_wet);
      reverb_mixer_R.gain(0, 1.0 - reverb_wet);
      reverb_mixer_R.gain(1, reverb_wet);
      if (displayMode == 0) Serial.print(reverb_wet);

      if (displayMode == 0) Serial.print("\t3) scale type: (0-1)");
      if (category == 3)byteparameter[3] = map(integerinput[3], 0, 255, 0, 255);
      if (byteparameter[3] > 4)byteparameter[3] = 4;
      scale_type = map(byteparameter[3], 0, 255, 0, 255);
      for (int x = 0; x < 25; x++)
      {
        if (scale_type == 0) scalefilter[x] = scalefilter1[x];
        if (scale_type == 1) scalefilter[x] = scalefilter2[x];
        if (scale_type == 2) scalefilter[x] = scalefilter3[x];
        if (scale_type == 4) scalefilter[x] = scalefilter4[x];
      }
      switch (scale_type)
      {
        case 0:
          if (displayMode == 0) Serial.println("0-C MAJOR");
          break;
        case 1:
          if (displayMode == 0) Serial.println("1-C DORIAN");
          break;
        case 2:
          if (displayMode == 0) Serial.println("2-CHROMATIC");
          break;
        default:
          if (displayMode == 0) Serial.println("DEFAULT");
          break;
      }

      if (displayMode == 0) Serial.print("4) chromatic interpret (0 - 1): ");
      if (category == 4) byteparameter[4] = map(integerinput[4], 0, 255, 0, 255);
      if (byteparameter[4] > 1)byteparameter[4] = 1;
      chromatic_lock = map(byteparameter[4], 0, 255, 0, 255);
      if (displayMode == 0) Serial.println (chromatic_lock);

      if (displayMode == 0) Serial.println("*********************ambient sounds controls*********************");

      if (displayMode == 0) Serial.print("6) rain gain (0-100): ");
      if (category == 6)byteparameter[6] = map(integerinput[6], 0, 255, 0, 255);
      if (byteparameter[6] > 255)byteparameter[6] = 255;
      rain_gain = float(map(byteparameter[6], 0, 255, 0, 255)) / 100;
      rain_mixer3.gain(0, rain_gain);
      rain_mixer3.gain(1, rain_gain);
      if (displayMode == 0) Serial.println(rain_gain);

      if (displayMode == 0) Serial.print("7) shimmer gain (0-100): ");
      if (category == 7)byteparameter[7] = map(integerinput[7], 0, 255, 0, 255);
      if (byteparameter[7] > 255)byteparameter[7] = 255;
      shimmer_gain = float(map(byteparameter[7], 0, 255, 0, 255)) / 100;
      //shimmermixer3.gain(0, shimmer_gain);
      //shimmermixer3.gain(1, shimmer_gain);
      if (displayMode == 0) Serial.print(shimmer_gain);

      if (displayMode == 0) Serial.print("\t8) shimmer off/play/drone (0-2): ");
      if (category == 8)byteparameter[8] = map(integerinput[8], 0, 255, 0, 255);
      if (byteparameter[8] > 2)byteparameter[8] = 2;
      shimmerchord = map(byteparameter[8], 0, 255, 0, 255);
      if (displayMode == 0) Serial.print(shimmerchord);
      if (shimmerchord == 0) //set to drone
      {
        Playshimmer(0, 0, 0);
        shimmermixer1.gain(0, .05);
        shimmermixer1.gain(1, .03);
        shimmermixer1.gain(2, .01);
        shimmermixer1.gain(3, .01);

        shimmermixer2.gain(0, .01);
        shimmermixer2.gain(1, .005);
        shimmermixer2.gain(2, .005);
        shimmermixer2.gain(3, .001);
      }
      if (shimmerchord == 1) //set to drone
      {
        Playshimmer(0, 0, 0);
        shimmermixer1.gain(0, .05);
        shimmermixer1.gain(1, .03);
        shimmermixer1.gain(2, .01);
        shimmermixer1.gain(3, .01);

        shimmermixer2.gain(0, .01);
        shimmermixer2.gain(1, .005);
        shimmermixer2.gain(2, .005);
        shimmermixer2.gain(3, .001);
      }

      if (shimmerchord == 2) //set to drone
      {
        shimmerwaveform1.frequency(130.81);
        shimmerwaveform2.frequency(196.00);
        shimmerwaveform3.frequency(261.63);
        shimmerwaveform4.frequency(392.00);
        shimmerwaveform5.frequency(523.25);
        shimmerwaveform6.frequency(783.99);
        shimmerwaveform7.frequency(1046.50);
        shimmerwaveform8.frequency(1567.00);

        shimmermixer1.gain(0, .05);
        shimmermixer1.gain(1, .03);
        shimmermixer1.gain(2, .01);
        shimmermixer1.gain(3, .01);

        shimmermixer2.gain(0, .01);
        shimmermixer2.gain(1, .005);
        shimmermixer2.gain(2, .005);
        shimmermixer2.gain(3, .001);
      }

      if (displayMode == 0) Serial.print("\t9) shimmer chords (0 - 1): ");
      if (category == 9)byteparameter[9] = map(integerinput[9], 0, 255, 0, 255);
      if (byteparameter[9] > 255)byteparameter[9] = 255;
      shimmer_cartridge_number = map(byteparameter[9], 0, 255, 0, 255);
      switch (shimmer_cartridge_number)
      {
        case 0:
          if (displayMode == 0) Serial.print ("0-standard chords");
          for (int x = 0; x < 3; x++)
          {
            shimmer1[x] = shimmer1_1[x];
            shimmer2[x] = shimmer2_1[x];
            shimmer3[x] = shimmer3_1[x];
            shimmer4[x] = shimmer4_1[x];
          }
          break;
        case 1:
          if (displayMode == 0) Serial.print ("1-choice 2");
          for (int x = 0; x < 3; x++)
          {
            shimmer1[x] = shimmer1_2[x];
            shimmer2[x] = shimmer2_2[x];
            shimmer3[x] = shimmer3_2[x];
            shimmer4[x] = shimmer4_2[x];
          }
          break;
        case 2:
          if (displayMode == 0) Serial.print ("2-choice 3");
          for (int x = 0; x < 3; x++)
          {
            shimmer1[x] = shimmer1_3[x];
            shimmer2[x] = shimmer2_3[x];
            shimmer3[x] = shimmer3_3[x];
            shimmer4[x] = shimmer4_3[x];
          }
          break;
        case 3:
          if (displayMode == 0) Serial.print ("3-choice 4");
          for (int x = 0; x < 3; x++)
          {
            shimmer1[x] = shimmer1_4[x];
            shimmer2[x] = shimmer2_4[x];
            shimmer3[x] = shimmer3_4[x];
            shimmer4[x] = shimmer4_4[x];
          }
          break;
        default:
          if (displayMode == 0) Serial.print ("1-notecart 5");
          for (int x = 0; x < 3; x++)
          {
            shimmer1[x] = shimmer1_1[x];
            shimmer2[x] = shimmer2_1[x];
            shimmer3[x] = shimmer3_1[x];
            shimmer4[x] = shimmer4_1[x];
          }
          break;
      }
      if (displayMode == 0) Serial.println("");

      if (displayMode == 0) Serial.println("********************* continuous wave controls*********************");

      if (displayMode == 0) Serial.print("11) melody oct (0-5): ");
      if (category == 11)byteparameter[11] = map(integerinput[11], 0, 255, 0, 255);
      if (byteparameter[11] > 255)byteparameter[11] = 255;
      int dummy = map(byteparameter[11], 0, 255, 0, 255);
      switch (dummy)
      {
        case 0:
          melody_octave = .125;
          if (displayMode == 0) Serial.print("0-");
          break;
        case 1:
          melody_octave = .25;
          if (displayMode == 0) Serial.print("1-");
          break;
        case 2:
          melody_octave = .5;
          if (displayMode == 0) Serial.print("2-");
          break;
        case 3:
          melody_octave = 1;
          if (displayMode == 0) Serial.print("3-");
          break;
        case 4:
          melody_octave = 2;
          if (displayMode == 0) Serial.print("4-");
          break;
        case 5:
          melody_octave = 4;
          if (displayMode == 0) Serial.print("5-");
          break;
        default:
          melody_octave = 1;
          break;
      }
      if (displayMode == 0) Serial.print(melody_octave);

      if (displayMode == 0) Serial.print("\t12) melody shape (0-6): ");
      if (category == 12)byteparameter[12] = map(integerinput[12], 0, 255, 0, 255);
      if (byteparameter[12] > 255)byteparameter[12] = 255;
      melody_shape = map(byteparameter[12], 0, 255, 0, 255);
      waveform1.begin(waveShapes[melody_shape]);
      switch (melody_shape)
      {
        case 0:
          if (displayMode == 0) Serial.print("0-SINE");
          break;
        case 1:
          if (displayMode == 0) Serial.print("1-TRIANGLE");
          break;
        case 2:
          if (displayMode == 0) Serial.print("2-TRIANGLE-VARIABLE");
          break;
        case 3:
          if (displayMode == 0) Serial.print("3-SAWTOOTH");
          break;
        case 4:
          if (displayMode == 0) Serial.print("4-SQUARE");
          break;
        case 5:
          if (displayMode == 0) Serial.print("5-PULSE");
          break;
        default:
          if (displayMode == 0) Serial.print("DEFAULT");
          break;
      }

      if (displayMode == 0) Serial.print("\t13) melody FTR cutoff (0-10000): ");
      if (category == 13)byteparameter[13] = map(integerinput[13], 0, 10000, 0, 255);
      if (byteparameter[13] > 255)byteparameter[13] = 255;
      M_filterFrequency = map(byteparameter[13], 0, 255, 0, 10000);
      melody_filter.frequency(M_filterFrequency);
      if (displayMode == 0) Serial.println(M_filterFrequency);

      if (displayMode == 0) Serial.print("14-17) M_ADSR (0-3000): ");
      if (category == 14)byteparameter[14] = map(integerinput[14], 0, 3000, 0, 255);
      if (byteparameter[14] > 255)byteparameter[14] = 255;
      M_attackTime = map(byteparameter[14], 0, 255, 0, 3000);
      envelope1.attack(M_attackTime);
      if (displayMode == 0) Serial.print(M_attackTime);

      if (displayMode == 0) Serial.print("/");
      if (category == 15)byteparameter[15] = map(integerinput[15], 0, 255, 0, 255);
      if (byteparameter[15] > 255)byteparameter[15] = 255;
      M_decayTime = map(byteparameter[15], 0, 255, 0, 255);
      envelope1.decay(M_decayTime);
      if (displayMode == 0) Serial.print(M_decayTime);

      if (displayMode == 0) Serial.print("/");
      if (category == 16)byteparameter[16] = map(integerinput[16], 0, 100, 0, 255);
      if (byteparameter[16] > 255)byteparameter[16] = 255;
      M_sustainLevel = float(map(byteparameter[16], 0, 255, 0, 100)) / 100;
      envelope1.sustain(M_sustainLevel);
      if (displayMode == 0) Serial.print(M_sustainLevel);

      if (displayMode == 0) Serial.print("/");
      if (category == 17)byteparameter[17] = map(integerinput[17], 0, 3000, 0, 255);
      if (byteparameter[17] > 255)byteparameter[17] = 255;
      M_releaseTime = map(byteparameter[17], 0, 255, 0, 3000);
      envelope1.release(M_releaseTime);
      if (displayMode == 0) Serial.print(M_releaseTime);

      if (displayMode == 0) Serial.print("\t18) melody volume (0-100): ");
      if (category == 18)byteparameter[18] = map(integerinput[18], 0, 100, 0, 255);
      if (byteparameter[18] > 255)byteparameter[18] = 255;
      harmony_mixer0 = float(map(byteparameter[18], 0, 255, 0, 100)) / 100;
      harmony_mixer.gain(0, harmony_mixer0);
      if (displayMode == 0) Serial.println(harmony_mixer0);

      if (displayMode == 0) Serial.println("");

      if (displayMode == 0) Serial.print("19) harmony1 octave (0-5): ");
      if (category == 19)byteparameter[19] = map(integerinput[19], 0, 255, 0, 255);
      if (byteparameter[19] > 255)byteparameter[19] = 255;
      dummy = map(byteparameter[19], 0, 255, 0, 255);
      switch (dummy)
      {
        case 0:
          harmony1_octave = .125;
          if (displayMode == 0) Serial.print("0-");
          break;
        case 1:
          harmony1_octave = .25;
          if (displayMode == 0) Serial.print("1-");
          break;
        case 2:
          harmony1_octave = .5;
          if (displayMode == 0) Serial.print("2-");
          break;
        case 3:
          harmony1_octave = 1;
          if (displayMode == 0) Serial.print("3-");
          break;
        case 4:
          harmony1_octave = 2;
          if (displayMode == 0) Serial.print("4-");
          break;
        case 5:
          harmony1_octave = 5;
          if (displayMode == 0) Serial.print("5-");
          break;
        default:
          harmony1_octave = 1;
          break;
      }
      if (displayMode == 0) Serial.print(harmony1_octave);

      if (displayMode == 0) Serial.print("\t20) harmony1 shape (0-4): ");
      if (category == 20)byteparameter[20] = map(integerinput[20], 0, 255, 0, 255);
      if (byteparameter[20] > 255)byteparameter[20] = 255;
      harmony1_shape = map(byteparameter[20], 0, 255, 0, 255);
      waveform2.begin(waveShapes[harmony1_shape]);
      switch (harmony1_shape)
      {
        case 0:
          if (displayMode == 0) Serial.print("0-SINE");
          break;
        case 1:
          if (displayMode == 0) Serial.print("1-TRIANGLE");
          break;
        case 2:
          if (displayMode == 0) Serial.print("2-TRIANGLE-VARIABLE");
          break;
        case 3:
          if (displayMode == 0) Serial.print("3-SAWTOOTH");
          break;
        case 4:
          if (displayMode == 0) Serial.print("4-SQUARE");
          break;
        case 5:
          if (displayMode == 0) Serial.print("5-PULSE");
          break;
        default:
          if (displayMode == 0) Serial.print("DEFAULT");
          break;
      }

      if (displayMode == 0) Serial.print("\t21) H1 FTR cutoff (0-10000): ");
      if (category == 21)byteparameter[21] = map(integerinput[21], 0, 10000, 0, 255);
      if (byteparameter[21] > 255)byteparameter[21] = 255;
      H1_filterFrequency  = map(byteparameter[21], 0, 255, 0, 10000);
      harmony_filter1.frequency(H1_filterFrequency);
      if (displayMode == 0) Serial.println(H1_filterFrequency);

      if (displayMode == 0) Serial.print("22-25) HA1_ADSR (0-1000): ");
      if (category == 22)byteparameter[22] = map(integerinput[22], 0, 3000, 0, 255);
      if (byteparameter[22] > 255)byteparameter[22] = 255;
      HA_attackTime  = map(byteparameter[22], 0, 255, 0, 3000);
      envelope2.attack(HA_attackTime);
      if (displayMode == 0) Serial.print(HA_attackTime);

      if (displayMode == 0) Serial.print("/");
      if (category == 23)byteparameter[23] = map(integerinput[23], 0, 255, 0, 255);
      if (byteparameter[23] > 255)byteparameter[23] = 255;
      HA_decayTime  = map(byteparameter[23], 0, 255, 0, 255);
      envelope2.decay(HA_decayTime);
      if (displayMode == 0) Serial.print(HA_decayTime);

      if (displayMode == 0) Serial.print("/");
      if (category == 24)byteparameter[24] = map(integerinput[24], 0, 100, 0, 255);
      if (byteparameter[24] > 255)byteparameter[24] = 255;
      HA_sustainLevel   = float(map(byteparameter[24], 0, 255, 0, 100)) / 100;
      envelope2.sustain(HA_sustainLevel);
      if (displayMode == 0) Serial.print(HA_sustainLevel);

      if (displayMode == 0) Serial.print("/");
      if (category == 25)byteparameter[25] = map(integerinput[25], 0, 3000, 0, 255);
      if (byteparameter[25] > 255)byteparameter[25] = 255;
      HA_releaseTime   = map(byteparameter[25], 0, 255, 0, 3000);
      envelope2.release(HA_releaseTime);
      if (displayMode == 0) Serial.print(HA_releaseTime);

      if (displayMode == 0) Serial.print("\t26) harmony 1 volume (0-100): ");
      if (category == 26)byteparameter[26] = map(integerinput[26], 0, 100, 0, 255);
      if (byteparameter[26] > 255)byteparameter[26] = 255;
      harmony_mixer1  = float(map(byteparameter[26], 0, 255, 0, 100)) / 100;
      harmony_mixer.gain(1, harmony_mixer1);
      if (displayMode == 0) Serial.print(harmony_mixer1);
      if (displayMode == 0) Serial.println("");
      if (displayMode == 0) Serial.println("");

      if (displayMode == 0) Serial.print("27) harmony 2 octave (0-5): ");
      if (category == 27)byteparameter[27] = map(integerinput[27], 0, 255, 0, 255);
      if (byteparameter[27] > 255)byteparameter[27] = 255;
      dummy  = map(byteparameter[27], 0, 255, 0, 255);
      switch (dummy)
      {
        case 0:
          harmony2_octave = .125;
          if (displayMode == 0) Serial.print("0-");
          break;
        case 1:
          harmony2_octave = .25;
          if (displayMode == 0) Serial.print("1-");
          break;
        case 2:
          harmony2_octave = .5;
          if (displayMode == 0) Serial.print("2-");
          break;
        case 3:
          harmony2_octave = 1;
          if (displayMode == 0) Serial.print("3-");
          break;
        case 4:
          harmony2_octave = 2;
          if (displayMode == 0) Serial.print("4-");
          break;
        case 5:
          harmony2_octave = 5;
          if (displayMode == 0) Serial.print("5-");
          break;
        default:
          harmony2_octave = 1;
          break;
      }
      if (displayMode == 0) Serial.print(harmony1_octave);

      if (displayMode == 0) Serial.print("\t28) harmony 2 shape (0-4): ");
      if (category == 28)byteparameter[28] = map(integerinput[28], 0, 255, 0, 255);
      if (byteparameter[28] > 255)byteparameter[28] = 255;
      harmony2_shape  = map(byteparameter[28], 0, 255, 0, 255);
      waveform3.begin(waveShapes[harmony2_shape]);
      switch (harmony2_shape)
      {
        case 0:
          if (displayMode == 0) Serial.print("0-SINE");
          break;
        case 1:
          if (displayMode == 0) Serial.print("1-TRIANGLE");
          break;
        case 2:
          if (displayMode == 0) Serial.print("2-TRIANGLE-VARIABLE");
          break;
        case 3:
          if (displayMode == 0) Serial.print("3-SAWTOOTH");
          break;
        case 4:
          if (displayMode == 0) Serial.print("4-SQUARE");
          break;
        case 5:
          if (displayMode == 0) Serial.print("5-PULSE");
          break;
        default:
          if (displayMode == 0) Serial.print("DEFAULT");
          break;
      }

      if (displayMode == 0) Serial.print("\t29) melody FTR cutoff (0-10000): ");
      if (category == 29)byteparameter[29] = map(integerinput[29], 0, 10000, 0, 255);
      if (byteparameter[29] > 255)byteparameter[29] = 255;
      H2_filterFrequency = map(byteparameter[29], 0, 255, 0, 10000);
      harmony_filter2.frequency(H2_filterFrequency);
      if (displayMode == 0) Serial.println(H2_filterFrequency);

      if (displayMode == 0) Serial.print("30-33) H2_ADSR (0-1000): ");
      if (category == 30)byteparameter[30] = map(integerinput[30], 0, 3000, 0, 255);
      if (byteparameter[30] > 255)byteparameter[30] = 255;
      HB_attackTime = map(byteparameter[30], 0, 255, 0, 3000);
      envelope3.attack(HB_attackTime);
      if (displayMode == 0) Serial.print(HB_attackTime);

      if (displayMode == 0) Serial.print("/");
      if (category == 31)byteparameter[31] = map(integerinput[31], 0, 255, 0, 255);
      if (byteparameter[31] > 255)byteparameter[31] = 255;
      HB_decayTime = map(byteparameter[31], 0, 255, 0, 255);
      envelope3.decay(HB_decayTime);
      if (displayMode == 0) Serial.print(HB_decayTime);

      if (displayMode == 0) Serial.print("/");
      if (category == 32)byteparameter[32] = map(integerinput[32], 0, 100, 0, 255);
      if (byteparameter[32] > 255)byteparameter[32] = 255;
      HB_sustainLevel  = float(map(byteparameter[32], 0, 255, 0, 100)) / 100;
      envelope3.sustain(HB_sustainLevel);
      if (displayMode == 0) Serial.print(HB_sustainLevel);

      if (displayMode == 0) Serial.print("/");
      if (category == 33)byteparameter[33] = map(integerinput[33], 0, 3000, 0, 255);
      if (byteparameter[33] > 255)byteparameter[33] = 255;
      HB_releaseTime = map(byteparameter[33], 0, 255, 0, 3000);
      envelope3.release(HB_releaseTime);
      if (displayMode == 0) Serial.print(HB_releaseTime);


      if (displayMode == 0) Serial.print("\t34) harmony 2 volume (0-100): ");
      if (category == 34)byteparameter[34] = map(integerinput[34], 0, 100, 0, 255);
      if (byteparameter[34] > 255)byteparameter[34] = 255;
      harmony_mixer2 = float(map(byteparameter[34], 0, 255, 0, 100)) / 100;
      harmony_mixer.gain(2, harmony_mixer2);
      if (displayMode == 0) Serial.println(harmony_mixer2);

      if (displayMode == 0) Serial.println("*********************plucked string controls*********************");

      if (displayMode == 0) Serial.print("36) melody string gain (0-100): ");
      if (category == 36) byteparameter[36] = map(integerinput[36], 0, 100, 0, 255);
      if (byteparameter[36] > 255)byteparameter[36] = 255;
      mel_string_gain  = float(map(byteparameter[36], 0, 255, 0, 100)) / 100;
      dulcimermixer5.gain(3, mel_string_gain);
      if (displayMode == 0) Serial.print(mel_string_gain);

      if (displayMode == 0) Serial.print("\t37) melody string octave (0-4): ");
      if (category == 37)byteparameter[37] = map(integerinput[37], 0, 255, 0, 255);
      if (byteparameter[37] > 255)byteparameter[37] = 255;
      dummy = map(byteparameter[37], 0, 255, 0, 255);
      switch (dummy)
      {
        case 0:
          mel_string_octave = .125;
          if (displayMode == 0) Serial.print("0-eighth");
          break;
        case 1:
          mel_string_octave = .25;
          if (displayMode == 0) Serial.print("1-quarter");
          break;
        case 2:
          mel_string_octave = .5;
          if (displayMode == 0) Serial.print("2-half");
          break;
        case 3:
          mel_string_octave = 1;
          if (displayMode == 0) Serial.print("3-one");
          break;
        case 4:
          mel_string_octave = 2;
          if (displayMode == 0) Serial.print("4-double");
          break;
        case 5:
          mel_string_octave = 4;
          if (displayMode == 0) Serial.print("5-quadruple");
          break;
        default:
          mel_string_octave = 1;
          break;
      }
      if (displayMode == 0) Serial.println("");

      if (displayMode == 0) Serial.print("38) harmony string gain (0-100): ");
      if (category == 38) byteparameter[38] = map(integerinput[38], 0, 100, 0, 255);
      if (byteparameter[38] > 255)byteparameter[38] = 255;
      harm_string_gain  = float(map(byteparameter[38], 0, 255, 0, 100)) / 100;
      dulcimermixer5.gain(0, harm_string_gain);
      dulcimermixer5.gain(1, harm_string_gain);
      dulcimermixer5.gain(2, harm_string_gain);
      if (displayMode == 0) Serial.print(harm_string_gain);

      if (displayMode == 0) Serial.print("\t39) harmony string octave (0-4): ");
      if (category == 39)byteparameter[39] = map(integerinput[39], 0, 255, 0, 255);
      if (byteparameter[39] > 255)byteparameter[39] = 255;
      dummy = map(byteparameter[39], 0, 255, 0, 255);
      switch (dummy)
      {
        case 0:
          harm_string_octave = .125;
          if (displayMode == 0) Serial.print("0-eighth");
          break;
        case 1:
          harm_string_octave = .25;
          if (displayMode == 0) Serial.print("1-quarter");
          break;
        case 2:
          harm_string_octave = .5;
          if (displayMode == 0) Serial.print("2-half");
          break;
        case 3:
          harm_string_octave = 1;
          if (displayMode == 0) Serial.print("3-one");
          break;
        case 4:
          harm_string_octave = 2;
          if (displayMode == 0) Serial.print("4-double");
          break;
        case 5:
          harm_string_octave = 4;
          if (displayMode == 0) Serial.print("5-quadruple");
          break;
        default:
          harm_string_octave = 1;
          break;
      }
      if (displayMode == 0) Serial.println("");
      if (displayMode == 0) Serial.println("*********************keyboard logic*********************");

      if (displayMode == 0) Serial.print("40) sticktimer override (0-1): ");
      if (category == 40)byteparameter[40] = map(integerinput[40], 0, 255, 0, 255);
      if (byteparameter[40] > 1)byteparameter[40] = 1;
      stickoverride = map(byteparameter[40], 0, 255, 0, 255);
      if (displayMode == 0) Serial.print(stickoverride);

      if (displayMode == 0) Serial.print("\t41) Keyboard Logic(0-1): ");
      if (category == 41)byteparameter[41] = map(integerinput[41], 0, 255, 0, 255);
      if (byteparameter[41] > 255)byteparameter[41] = 255;
      buttonlogic = map(byteparameter[41], 0, 255, 0, 255);
      switch (buttonlogic)
      {
        case 0:
          if (displayMode == 0) Serial.println("0-SHIMMER");
          break;
        case 1:
          if (displayMode == 0) Serial.println("1-CHORD");
          break;
        case 2:
          if (displayMode == 0) Serial.println("2-HARMONY");
          break;
        case 3:
          if (displayMode == 0) Serial.println("3-STRINGS");
          break;
        case 4:
          if (displayMode == 0) Serial.println("4-STRINGCHORD");
          break;
        case 5:
          if (displayMode == 0) Serial.println("5-SYNTHCHORD");
          break;
        case 6:
          if (displayMode == 0) Serial.println("6-UNISON");
          break;
        case 7:
          if (displayMode == 0) Serial.println("7-PROGRESSION");
          break;
        case 8:
          if (displayMode == 0) Serial.println("8-BASS");
          break;
        case 9:
          if (displayMode == 0) Serial.println("9-LUT control");
          break;
        default:
          if (displayMode == 0) Serial.println("DEFAULT");
          break;
      }

      if (displayMode == 0) Serial.println("*********************note sequence controls*********************");

      if (displayMode == 0) Serial.print("45) chord pallet (1 - 100): ");
      if (category == 45)byteparameter[45] = map(integerinput[45], 0, 255, 0, 255);
      if (byteparameter[45] > 255)byteparameter[45] = 255;
      chord_cartridge_number = map(byteparameter[45], 0, 255, 0, 255);
      switch (chord_cartridge_number)
      {
        case 0:
          if (displayMode == 0) Serial.print ("1-standard chords");
          for (int x = 0; x < 24; x++)
          {
            chordcart1A[x] = chordcart1A_1[x];
            chordcart2A[x] = chordcart2A_1[x];
            chordcart3A[x] = chordcart3A_1[x];
            chordcart1B[x] = chordcart1B_1[x];
            chordcart2B[x] = chordcart2B_1[x];
            chordcart3B[x] = chordcart3B_1[x];
            chordcart1C[x] = chordcart1C_1[x];
            chordcart2C[x] = chordcart2C_1[x];
            chordcart3C[x] = chordcart3C_1[x];
            chordcart1D[x] = chordcart1D_1[x];
            chordcart2D[x] = chordcart2D_1[x];
            chordcart3D[x] = chordcart3D_1[x];
          }
          break;
        case 1:
          if (displayMode == 0) Serial.print ("-2 string chords");
          for (int x = 0; x < 24; x++)
          {
            chordcart1A[x] = chordcart1A_2[x];
            chordcart2A[x] = chordcart2A_2[x];
            chordcart3A[x] = chordcart3A_2[x];
            chordcart1B[x] = chordcart1B_2[x];
            chordcart2B[x] = chordcart2B_2[x];
            chordcart3B[x] = chordcart3B_2[x];
            chordcart1C[x] = chordcart1C_2[x];
            chordcart2C[x] = chordcart2C_2[x];
            chordcart3C[x] = chordcart3C_2[x];
            chordcart1D[x] = chordcart1D_2[x];
            chordcart2D[x] = chordcart2D_2[x];
            chordcart3D[x] = chordcart3D_2[x];
          }
          break;
        case 2:
          if (displayMode == 0) Serial.print ("-2 celtic");
          for (int x = 0; x < 24; x++)
          {
            chordcart1A[x] = chordcart1A_3[x];
            chordcart2A[x] = chordcart2A_3[x];
            chordcart3A[x] = chordcart3A_3[x];
            chordcart1B[x] = chordcart1B_3[x];
            chordcart2B[x] = chordcart2B_3[x];
            chordcart3B[x] = chordcart3B_3[x];
            chordcart1C[x] = chordcart1C_3[x];
            chordcart2C[x] = chordcart2C_3[x];
            chordcart3C[x] = chordcart3C_3[x];
            chordcart1D[x] = chordcart1D_3[x];
            chordcart2D[x] = chordcart2D_3[x];
            chordcart3D[x] = chordcart3D_3[x];
          }
          break;
        default:
          if (displayMode == 0) Serial.print ("-notecart 5");
          for (int x = 0; x < 24; x++)
          {
            chordcart1A[x] = chordcart1A_1[x];
            chordcart2A[x] = chordcart2A_1[x];
            chordcart3A[x] = chordcart3A_1[x];
            chordcart1B[x] = chordcart1B_1[x];
            chordcart2B[x] = chordcart2B_1[x];
            chordcart3B[x] = chordcart3B_1[x];
            chordcart1C[x] = chordcart1C_1[x];
            chordcart2C[x] = chordcart2C_1[x];
            chordcart3C[x] = chordcart3C_1[x];
            chordcart1D[x] = chordcart1D_1[x];
            chordcart2D[x] = chordcart2D_1[x];
            chordcart3D[x] = chordcart3D_1[x];
          }
          break;
      }

      if (displayMode == 0) Serial.print("\t46) progression pallet (1 - 100): ");
      if (category == 46)byteparameter[46] = map(integerinput[46], 0, 255, 0, 255);
      if (byteparameter[46] > 255)byteparameter[46] = 255;
      prog_cartridge_number  = map(byteparameter[46], 0, 255, 0, 255);
      switch (prog_cartridge_number)
      {
        case 0:
          if (displayMode == 0) Serial.print ("0-first prog");
          for (int x = 0; x < 24; x++)
          {
            chordprogression1[x] = chordprogression1A[x];
            chordprogression2[x] = chordprogression2A[x];
            chordprogression3[x] = chordprogression3A[x];
            chordprogression4[x] = chordprogression4A[x];
          }
          progressionlength1 = progressionlength1A;
          progressionlength2 = progressionlength2A;
          progressionlength3 = progressionlength3A;
          progressionlength4 = progressionlength4A;
          break;
        case 1:
          if (displayMode == 0) Serial.print ("1-second progression");
          for (int x = 0; x < 24; x++)
          {
            chordprogression1[x] = chordprogression1B[x];
            chordprogression2[x] = chordprogression2B[x];
            chordprogression3[x] = chordprogression3B[x];
            chordprogression4[x] = chordprogression4B[x];
          }
          progressionlength1 = progressionlength1B;
          progressionlength2 = progressionlength2B;
          progressionlength3 = progressionlength3B;
          progressionlength4 = progressionlength4B;
          break;

        default:
          if (displayMode == 0) Serial.print ("2-third progression");
          for (int x = 0; x < 24; x++)
          {
            chordprogression1[x] = chordprogression1A[x];
            chordprogression2[x] = chordprogression2A[x];
            chordprogression3[x] = chordprogression3A[x];
            chordprogression4[x] = chordprogression4A[x];
          }
          progressionlength1 = progressionlength1A;
          progressionlength2 = progressionlength2A;
          progressionlength3 = progressionlength3A;
          progressionlength4 = progressionlength4A;
          break;
      }
      if (displayMode == 0) Serial.println("");
      if (displayMode == 0) Serial.println("");




      //////////////////////////////////////////
      // DRUM DISPLAY
      //////////////////////////////////////////



      // SELECT DISPLAY
      if (displayMode == 1)printscreen = false;
      Serial.print("0) display screen (0=synthD,1=drums,2=save,3=test, 4-PPL tune): ");
      displayMode = byteparameter[0];
      switch (displayMode)
      {
        case 0:
          Serial.println("0-synthesizer controls");
          break;
        case 1:
          Serial.println("1-drum controls");
          break;
        case 2:
          Serial.println("2-save settings");
          break;
        case 3:
          Serial.println("3-hardware monitor");
          break;
        case 4:
          Serial.println("4-PPL tuning");
          break;
        default:
          Serial.println("default");
          displayMode = 0;
          break;
      }
      Serial.print("PRESET: ");
      Serial.println(modecount);
      if (displayMode == 1) Serial.println("*********************drum synth controls*********************");

      if (displayMode == 1) Serial.print("49) drum preview (0,1)");
      if (category == 49)drumpreview = integerinput[49];
      if (byteparameter[50] > 255)byteparameter[50] = 255;
      if (displayMode == 1) Serial.println(drumpreview);


      if (displayMode == 1) Serial.print("50) drum speed:(ms)");
      if (category == 50)byteparameter[50] = map(integerinput[50], 0, 1000, 0, 255);
      if (byteparameter[50] > 255)byteparameter[50] = 255;
      espeed = map(byteparameter[50], 0, 255, 0, 1000);
      if (displayMode == 1) Serial.println(espeed);
      if (displayMode == 1) Serial.println("");

      if (displayMode == 1) Serial.print("51-55) drum1: freq/length/mix/pitchmod/vol: "); //to do one entry for each drum
      if (category == 51)byteparameter[51] = map(integerinput[51], 0, 2000, 0, 255);
      if (byteparameter[51] > 255)byteparameter[51] = 255;
      drum1frequency = map(byteparameter[51], 0, 255, 0, 2000);
      drum1.frequency(drum1frequency);
      if (displayMode == 1) Serial.print(drum1frequency);

      if (displayMode == 1) Serial.print("/");
      if (category == 52)byteparameter[52] = map(integerinput[52], 0, 2000, 0, 255);
      if (byteparameter[52] > 255)byteparameter[52] = 255;
      drum1length = map(byteparameter[52], 0, 255, 0, 2000);
      drum1.length(drum1length);
      if (displayMode == 1) Serial.print(drum1length);

      if (displayMode == 1) Serial.print("/");
      if (category == 53)byteparameter[53] = map(integerinput[53], 0, 100, 0, 255);
      if (byteparameter[53] > 255)byteparameter[53] = 255;
      drum1mix = float(map(byteparameter[53], 0, 255, 0, 100)) / 100;
      drum1.secondMix(drum1mix);
      if (displayMode == 1) Serial.print(drum1mix);

      if (displayMode == 1) Serial.print("/");
      if (category == 54)byteparameter[54] = map(integerinput[54], 0, 100, 0, 255);
      if (byteparameter[54] > 255)byteparameter[54] = 255;
      drum1mod = float(map(byteparameter[54], 0, 255, 0, 100)) / 100;
      drum1.pitchMod(drum1mod);
      if (displayMode == 1) Serial.print(drum1mod);

      if (displayMode == 1) Serial.print("/");
      if (category == 55)byteparameter[55] = map(integerinput[55], 0, 100, 0, 255);
      if (byteparameter[55] > 255)byteparameter[55] = 255;
      drum_volume1 = float(map(byteparameter[55], 0, 255, 0, 100)) / 100;
      drum_mixer1.gain(0, drum_volume1);
      if (displayMode == 1) Serial.println(drum_volume1);

      if (displayMode == 1) Serial.print("56-59) drum1 bucket/beat/offset/clump:(1-20)");
      if (category == 56)byteparameter[56] = map(integerinput[56], 0, 255, 0, 255);
      if (byteparameter[56] > 32)byteparameter[56] = 32;
      bins1 = map(byteparameter[56], 0, 255, 0, 255);
      EuclidGenerator(bins1, beats1, offsetnumber1, clump1);  //outputs to array "euclid"
      for (int x = 0; x < bins1; x++) drumcartridge1[x] = euclid[x];
      if (displayMode == 1) Serial.print(bins1);
      Resettime();

      if (displayMode == 1) Serial.print("/");
      if (category == 57)byteparameter[57] = map(integerinput[57], 0, 255, 0, 255);
      if (byteparameter[57] > 32)byteparameter[57] = 32;
      beats1 = map(byteparameter[57], 0, 255, 0, 255);
      EuclidGenerator(bins1, beats1, offsetnumber1, clump1);  //outputs to array "euclid"
      for (int x = 0; x < bins1; x++) drumcartridge1[x] = euclid[x];
      if (displayMode == 1) Serial.print(beats1);
      Resettime();

      if (displayMode == 1) Serial.print("/");
      if (category == 58)byteparameter[58] = map(integerinput[58], 0, 255, 0, 255);
      if (byteparameter[58] > 32)byteparameter[58] = 32;
      offsetnumber1 = map(byteparameter[58], 0, 255, 0, 255);
      EuclidGenerator(bins1, beats1, offsetnumber1, clump1);  //outputs to array "euclid"
      for (int x = 0; x < bins1; x++) drumcartridge1[x] = euclid[x];
      if (displayMode == 1) Serial.print(offsetnumber1);
      Resettime();

      if (displayMode == 1) Serial.print("/");
      if (category == 59)byteparameter[59] = map(integerinput[59], 0, 255, 0, 255);
      if (byteparameter[59] > 32)byteparameter[59] = 32;
      clump1 = map(byteparameter[59], 0, 255, 0, 255);
      EuclidGenerator(bins1, beats1, offsetnumber1, clump1);  //outputs to array "euclid"
      for (int x = 0; x < bins1; x++) drumcartridge1[x] = euclid[x];
      if (displayMode == 1) Serial.print(clump1);
      Resettime();

      if (displayMode == 1) Serial.print("\t");
      for (int x = 0; x < bins1; x++)
      {
        if (displayMode == 1) Serial.print (" / ");
        if (displayMode == 1) Serial.print (drumcartridge1[x]);
      }
      if (displayMode == 1) Serial.println  ("   ");
      if (displayMode == 1) Serial.println("");

      if (displayMode == 1) Serial.print("60-64) drum2: freq/length/mix/pitchmod/vol: "); //to do one entry for each drum
      if (category == 60)byteparameter[60] = map(integerinput[60], 0, 2000, 0, 255);
      if (byteparameter[60] > 255)byteparameter[60] = 255;
      drum2frequency = map(byteparameter[60], 0, 255, 0, 2000);
      drum2.frequency(drum2frequency);
      if (displayMode == 1) Serial.print(drum2frequency);

      if (displayMode == 1) Serial.print("/");
      if (category == 61)byteparameter[61] = map(integerinput[61], 0, 2000, 0, 255);
      if (byteparameter[61] > 255)byteparameter[61] = 255;
      drum2length = map(byteparameter[61], 0, 255, 0, 2000);
      drum2.length(drum2length);
      if (displayMode == 1) Serial.print(drum2length);

      if (displayMode == 1) Serial.print("/");
      if (category == 62)byteparameter[62] = map(integerinput[62], 0, 100, 0, 255);
      if (byteparameter[62] > 255)byteparameter[62] = 255;
      drum2mix = float(map(byteparameter[62], 0, 255, 0, 100)) / 100;
      drum2.secondMix(drum2mix);
      if (displayMode == 1) Serial.print(drum2mix);

      if (displayMode == 1) Serial.print("/");
      if (category == 63)byteparameter[63] = map(integerinput[63], 0, 100, 0, 255);
      if (byteparameter[63] > 255)byteparameter[63] = 255;
      drum2mod = float(map(byteparameter[63], 0, 255, 0, 100)) / 100;
      drum2.pitchMod(drum2mod);
      if (displayMode == 1) Serial.print(drum2mod);

      if (displayMode == 1) Serial.print("/");
      if (category == 64)byteparameter[64] = map(integerinput[64], 0, 100, 0, 255);
      if (byteparameter[64] > 255)byteparameter[64] = 255;
      drum_volume2 = float(map(byteparameter[64], 0, 255, 0, 100)) / 100;
      drum_mixer1.gain(1, drum_volume2);
      if (displayMode == 1) Serial.println(drum_volume2);

      if (displayMode == 1) Serial.print("65-68) euclid2 bucket/beat/offset/clump:(1 - 20)");
      if (category == 65)byteparameter[65] = map(integerinput[65], 0, 255, 0, 255);
      if (byteparameter[65] > 32)byteparameter[65] = 32;
      bins2 = map(byteparameter[65], 0, 255, 0, 255);
      EuclidGenerator(bins2, beats2, offsetnumber2, clump2);  //outputs to array "euclid"
      for (int x = 0; x < bins2; x++) drumcartridge2[x] = euclid[x];
      if (displayMode == 1) Serial.print(bins2);
      Resettime();

      if (displayMode == 1) Serial.print("/");
      if (category == 66)byteparameter[66] = map(integerinput[66], 0, 255, 0, 255);
      if (byteparameter[66] > 32)byteparameter[66] = 32;
      beats2 = map(byteparameter[66], 0, 255, 0, 255);
      EuclidGenerator(bins2, beats2, offsetnumber2, clump2);  //outputs to array "euclid"
      for (int x = 0; x < bins2; x++) drumcartridge2[x] = euclid[x];
      if (displayMode == 1) Serial.print(beats2);
      Resettime();

      if (displayMode == 1) Serial.print("/");
      if (category == 67)byteparameter[67] = map(integerinput[67], 0, 255, 0, 255);
      if (byteparameter[67] > 32)byteparameter[67] = 32;
      offsetnumber2 = map(byteparameter[67], 0, 255, 0, 255);
      EuclidGenerator(bins2, beats2, offsetnumber2, clump2);  //outputs to array "euclid"
      for (int x = 0; x < bins2; x++) drumcartridge2[x] = euclid[x];
      if (displayMode == 1) Serial.print(offsetnumber2);
      Resettime();

      if (displayMode == 1) Serial.print("/");
      if (category == 68)byteparameter[68] = map(integerinput[68], 0, 255, 0, 255);
      if (byteparameter[68] > 32)byteparameter[68] = 32;
      clump2 = map(byteparameter[68], 0, 255, 0, 255);
      EuclidGenerator(bins2, beats2, offsetnumber2, clump2);  //outputs to array "euclid"
      for (int x = 0; x < bins1; x++) drumcartridge2[x] = euclid[x];
      if (displayMode == 1) Serial.print(clump2);

      if (displayMode == 1) Serial.print("\t");
      for (int x = 0; x < bins2; x++)
      {
        if (displayMode == 1) Serial.print (" / ");
        if (displayMode == 1) Serial.print (drumcartridge2[x]);
      }
      if (displayMode == 1) Serial.println ("");
      if (displayMode == 1) Serial.println("");

      if (displayMode == 1) Serial.print("69-73) drum3: freq/length/mix/pitchmod/vol: "); //to do one entry for each drum
      if (category == 69)byteparameter[69] = map(integerinput[69], 0, 2000, 0, 255);
      if (byteparameter[69] > 255)byteparameter[69] = 255;
      drum3frequency  = map(byteparameter[69], 0, 255, 0, 2000);
      drum3.frequency(drum3frequency);
      if (displayMode == 1) Serial.print(drum3frequency);

      if (displayMode == 1) Serial.print("/");
      if (category == 70)byteparameter[70] = map(integerinput[70], 0, 2000, 0, 255);
      if (byteparameter[70] > 255)byteparameter[70] = 255;
      drum3length  = map(byteparameter[70], 0, 255, 0, 2000);
      drum3.length(drum3length);
      if (displayMode == 1) Serial.print(drum3length);

      if (displayMode == 1) Serial.print("/");
      if (category == 71)byteparameter[71] = map(integerinput[71], 0, 100, 0, 255);
      if (byteparameter[71] > 255)byteparameter[71] = 255;
      drum3mix  = float(map(byteparameter[71], 0, 255, 0, 100)) / 100;
      drum3.secondMix(drum3mix);
      if (displayMode == 1) Serial.print(drum3mix);

      if (displayMode == 1) Serial.print("/");
      if (category == 72)byteparameter[72] = map(integerinput[72], 0, 100, 0, 255);
      if (byteparameter[72] > 255)byteparameter[72] = 255;
      drum3mod  = float(map(byteparameter[72], 0, 255, 0, 100)) / 100;
      if (displayMode == 1) Serial.print(drum3mod);

      if (displayMode == 1) Serial.print("/");
      if (category == 73)byteparameter[73] = map(integerinput[73], 0, 100, 0, 255);
      if (byteparameter[73] > 255)byteparameter[73] = 255;
      drum_volume3  = float(map(byteparameter[73], 0, 255, 0, 100)) / 100;
      drum_mixer1.gain(2, drum_volume3);
      if (displayMode == 1) Serial.println(drum_volume3);


      if (displayMode == 1) Serial.print("74-77) euclid3 bucket/beat/offset/clump: ");
      if (category == 74)byteparameter[74] = map(integerinput[74], 0, 255, 0, 255);
      if (byteparameter[74] > 32)byteparameter[74] = 32;
      bins3   = map(byteparameter[74], 0, 255, 0, 255);
      EuclidGenerator(bins3, beats3, offsetnumber3, clump3);  //outputs to array "euclid"
      for (int x = 0; x < bins3; x++) drumcartridge3[x] = euclid[x];
      if (displayMode == 1) Serial.print(bins3);
      Resettime();

      if (displayMode == 1) Serial.print("/");
      if (category == 75)byteparameter[75] = map(integerinput[75], 0, 255, 0, 255);
      if (byteparameter[75] > 32)byteparameter[75] = 32;
      beats3  = map(byteparameter[75], 0, 255, 0, 255);
      EuclidGenerator(bins3, beats3, offsetnumber3, clump3);  //outputs to array "euclid"
      for (int x = 0; x < bins3; x++) drumcartridge3[x] = euclid[x];
      if (displayMode == 1) Serial.print(beats3);
      Resettime();

      if (displayMode == 1) Serial.print("/");
      if (category == 76)byteparameter[76] = map(integerinput[76], 0, 255, 0, 255);
      if (byteparameter[76] > 32)byteparameter[76] = 32;
      offsetnumber3   = map(byteparameter[76], 0, 255, 0, 255);
      EuclidGenerator(bins3, beats3, offsetnumber3, clump3);  //outputs to array "euclid"
      for (int x = 0; x < bins3; x++) drumcartridge3[x] = euclid[x];
      if (displayMode == 1) Serial.print(offsetnumber3);
      Resettime();

      if (displayMode == 1) Serial.print("/");
      if (category == 77)byteparameter[77] = map(integerinput[77], 0, 255, 0, 255);
      if (byteparameter[77] > 32)byteparameter[77] = 32;
      clump3   = map(byteparameter[77], 0, 255, 0, 255);
      EuclidGenerator(bins3, beats3, offsetnumber3, clump3);  //outputs to array "euclid"
      for (int x = 0; x < bins1; x++) drumcartridge3[x] = euclid[x];
      if (displayMode == 1) Serial.print(clump3);
      Resettime();

      if (displayMode == 1) Serial.print ("\t");
      for (int x = 0; x < bins3; x++)
      {
        if (displayMode == 1) Serial.print (" / ");
        if (displayMode == 1) Serial.print (drumcartridge3[x]);
      }
      if (displayMode == 1) Serial.println ("");
      if (displayMode == 1) Serial.println("");

      if (displayMode == 1) Serial.print("78-82) drum4: freq/length/mix/pitchmod/vol: "); //to do one entry for each drum
      if (category == 78)byteparameter[78] = map(integerinput[78], 0, 2000, 0, 255);
      if (byteparameter[78] > 255)byteparameter[78] = 255;
      drum4frequency   = map(byteparameter[78], 0, 255, 0, 2000);
      drum4.frequency(drum4frequency);
      if (displayMode == 1) Serial.print(drum4frequency);

      if (displayMode == 1) Serial.print("/");
      if (category == 79)byteparameter[79] = map(integerinput[79], 0, 2000, 0, 255);
      if (byteparameter[79] > 255)byteparameter[79] = 255;
      drum4length   = map(byteparameter[79], 0, 255, 0, 2000);
      drum4.length(drum4length);
      if (displayMode == 1) Serial.print(drum4length);

      if (displayMode == 1) Serial.print("/");
      if (category == 80)byteparameter[80] = map(integerinput[80], 0, 100, 0, 255);
      if (byteparameter[80] > 255)byteparameter[80] = 255;
      drum4mix   = float(map(byteparameter[80], 0, 255, 0, 100)) / 100;
      drum4.secondMix(drum4mix);
      if (displayMode == 1) Serial.print(drum4mix);

      if (displayMode == 1) Serial.print("/");
      if (category == 81)byteparameter[81] = map(integerinput[81], 0, 100, 0, 255);
      if (byteparameter[81] > 255)byteparameter[81] = 255;
      drum4mod   = float(map(byteparameter[81], 0, 255, 0, 100)) / 100;
      drum4.pitchMod(drum4mod);
      if (displayMode == 1) Serial.print(drum4mod);

      if (displayMode == 1) Serial.print("/");
      if (category == 82)byteparameter[82] = map(integerinput[82], 0, 100, 0, 255);
      if (byteparameter[82] > 255)byteparameter[82] = 255;
      drum_volume4   = float(map(byteparameter[82], 0, 255, 0, 100)) / 100;
      drum_mixer2.gain(0, drum_volume4);
      if (displayMode == 1) Serial.println(drum_volume4);


      if (displayMode == 1) Serial.print("83-86) euclid4 bucket/beat/offset/clump: ");
      if (category == 83)byteparameter[83] = map(integerinput[83], 0, 255, 0, 255);
      if (byteparameter[83] > 32)byteparameter[83] = 32;
      bins4   = map(byteparameter[83], 0, 255, 0, 255);
      EuclidGenerator(bins4, beats4, offsetnumber4, clump4);  //outputs to array "euclid"
      for (int x = 0; x < bins4; x++) drumcartridge4[x] = euclid[x];
      if (displayMode == 1) Serial.print(bins4);
      Resettime();

      if (displayMode == 1) Serial.print("/");
      if (category == 84)byteparameter[84] = map(integerinput[84], 0, 255, 0, 255);
      if (byteparameter[84] > 32)byteparameter[84] = 32;
      beats4  = map(byteparameter[84], 0, 255, 0, 255);
      EuclidGenerator(bins4, beats4, offsetnumber4, clump4);  //outputs to array "euclid"
      for (int x = 0; x < bins4; x++) drumcartridge4[x] = euclid[x];
      if (displayMode == 1) Serial.print(beats4);
      Resettime();

      if (displayMode == 1) Serial.print("/");
      if (category == 85)byteparameter[85] = map(integerinput[85], 0, 255, 0, 255);
      if (byteparameter[85] > 32)byteparameter[85] = 32;
      offsetnumber4   = map(byteparameter[85], 0, 255, 0, 255);
      EuclidGenerator(bins4, beats4, offsetnumber4, clump4);  //outputs to array "euclid"
      for (int x = 0; x < bins4; x++) drumcartridge4[x] = euclid[x];
      if (displayMode == 1) Serial.print(offsetnumber4);
      Resettime();

      if (displayMode == 1) Serial.print("/");
      if (category == 86)byteparameter[86] = map(integerinput[86], 0, 255, 0, 255);
      if (byteparameter[86] > 32)byteparameter[86] = 32;
      clump4   = map(byteparameter[86], 0, 255, 0, 255);
      EuclidGenerator(bins4, beats4, offsetnumber4, clump4);  //outputs to array "euclid"
      for (int x = 0; x < bins1; x++) drumcartridge4[x] = euclid[x];
      if (displayMode == 1) Serial.print(clump4);

      if (displayMode == 1) Serial.print ("\t");
      for (int x = 0; x < bins4; x++)
      {
        if (displayMode == 1) Serial.print (" / ");
        if (displayMode == 1) Serial.print (drumcartridge4[x]);
      }
      if (displayMode == 1) Serial.println ("");
      if (displayMode == 1) Serial.println("");

      if (displayMode == 1) Serial.print("87-91) drum5: freq/length/mix/pitchmod/vol: "); //to do one entry for each drum
      if (category == 87)byteparameter[87] = map(integerinput[87], 0, 2000, 0, 255);
      if (byteparameter[87] > 255)byteparameter[87] = 255;
      drum5frequency = map(byteparameter[87], 0, 255, 0, 2000);
      drum5.frequency(drum5frequency);
      if (displayMode == 1) Serial.print(drum5frequency);

      if (displayMode == 1) Serial.print("/");
      if (category == 88)byteparameter[88] = map(integerinput[88], 0, 2000, 0, 255);
      if (byteparameter[88] > 255)byteparameter[88] = 255;
      drum5length = map(byteparameter[88], 0, 255, 0, 2000);
      drum5.length(drum5length);
      if (displayMode == 1) Serial.print(drum5length);

      if (displayMode == 1) Serial.print("/");
      if (category == 89)byteparameter[89] = map(integerinput[89], 0, 100, 0, 255);
      if (byteparameter[89] > 255)byteparameter[89] = 255;
      drum5mix  = float(map(byteparameter[89], 0, 255, 0, 100)) / 100;
      drum5.secondMix(drum5mix);
      if (displayMode == 1) Serial.print(drum5mix);

      if (displayMode == 1) Serial.print("/");
      if (category == 90)byteparameter[90] = map(integerinput[90], 0, 100, 0, 255);
      if (byteparameter[90] > 255)byteparameter[90] = 255;
      drum5mod  = float(map(byteparameter[90], 0, 255, 0, 100)) / 100;
      drum5.pitchMod(drum5mod);
      if (displayMode == 1) Serial.print(drum5mod);

      if (displayMode == 1) Serial.print("/");
      if (category == 91)byteparameter[91] = map(integerinput[91], 0, 100, 0, 255);
      if (byteparameter[91] > 255)byteparameter[91] = 255;
      drum_volume5  = float(map(byteparameter[91], 0, 255, 0, 100)) / 100;
      drum_mixer2.gain(1, drum_volume5);
      if (displayMode == 1) Serial.println(drum_volume5);


      if (displayMode == 1) Serial.print("92-95) euclid5 bucket/beat/offset/clump: ");
      if (category == 92)byteparameter[92] = map(integerinput[92], 0, 255, 0, 255);
      if (byteparameter[92] > 32)byteparameter[92] = 32;
      bins5   = map(byteparameter[92], 0, 255, 0, 255);
      EuclidGenerator(bins5, beats5, offsetnumber5, clump5);  //outputs to array "euclid"
      for (int x = 0; x < bins5; x++) drumcartridge5[x] = euclid[x];
      if (displayMode == 1) Serial.print(bins5);
      Resettime();

      if (displayMode == 1) Serial.print("/");
      if (category == 93)byteparameter[93] = map(integerinput[93], 0, 255, 0, 255);
      if (byteparameter[93] > 32)byteparameter[93] = 32;
      beats5   = map(byteparameter[93], 0, 255, 0, 255);
      EuclidGenerator(bins5, beats5, offsetnumber5, clump5);  //outputs to array "euclid"
      for (int x = 0; x < bins5; x++) drumcartridge5[x] = euclid[x];
      if (displayMode == 1) Serial.print(beats5);
      Resettime();

      if (displayMode == 1) Serial.print("/");
      if (category == 94)byteparameter[94] = map(integerinput[94], 0, 255, 0, 255);
      if (byteparameter[94] > 32)byteparameter[94] = 32;
      offsetnumber5   = map(byteparameter[94], 0, 255, 0, 255);
      EuclidGenerator(bins5, beats5, offsetnumber5, clump5);  //outputs to array "euclid"
      for (int x = 0; x < bins3; x++) drumcartridge5[x] = euclid[x];
      if (displayMode == 1) Serial.print(offsetnumber5);
      Resettime();

      if (displayMode == 1) Serial.print("/");
      if (category == 95)byteparameter[95] = map(integerinput[95], 0, 255, 0, 255);
      if (byteparameter[95] > 32)byteparameter[95] = 32;
      clump5   = map(byteparameter[95], 0, 255, 0, 255);
      EuclidGenerator(bins5, beats5, offsetnumber5, clump5);  //outputs to array "euclid"
      for (int x = 0; x < bins1; x++) drumcartridge5[x] = euclid[x];
      if (displayMode == 1) Serial.print(clump5);
      Resettime();

      if (displayMode == 1) Serial.print ("\t");
      for (int x = 0; x < bins5; x++)
      {
        if (displayMode == 1) Serial.print (" / ");
        if (displayMode == 1) Serial.print (drumcartridge5[x]);
      }
      if (displayMode == 1) Serial.println ("");
      if (displayMode == 1) Serial.println("");

      if (displayMode == 1) Serial.print("96-99) euclid6 (note trigger) bucket/beat/offset/clump: ");
      if (category == 96)byteparameter[96] = map(integerinput[96], 0, 255, 0, 255);
      if (byteparameter[96] > 32)byteparameter[96] = 32;
      bins6   = map(byteparameter[96], 0, 255, 0, 255);
      EuclidGenerator(bins6, beats6, offsetnumber6, clump6);  //outputs to array "euclid"
      for (int x = 0; x < bins6; x++) drumcartridge6[x] = euclid[x];
      if (displayMode == 1) Serial.print(bins6);
      Resettime();

      if (displayMode == 1) Serial.print("/");
      if (category == 97)byteparameter[97] = map(integerinput[97], 0, 255, 0, 255);
      if (byteparameter[97] > 32)byteparameter[97] = 32;
      beats6    = map(byteparameter[97], 0, 255, 0, 255);
      EuclidGenerator(bins6, beats6, offsetnumber6, clump6);  //outputs to array "euclid"
      for (int x = 0; x < bins6; x++) drumcartridge6[x] = euclid[x];
      if (displayMode == 1) Serial.print(beats6);
      Resettime();

      if (displayMode == 1) Serial.print("/");
      if (category == 98)byteparameter[98] = map(integerinput[98], 0, 255, 0, 255);
      if (byteparameter[98] > 32)byteparameter[98] = 32;
      offsetnumber6   = map(byteparameter[98], 0, 255, 0, 255);
      EuclidGenerator(bins6, beats6, offsetnumber6, clump6);  //outputs to array "euclid"
      for (int x = 0; x < bins6; x++) drumcartridge6[x] = euclid[x];
      if (displayMode == 1) Serial.print(offsetnumber6);
      Resettime();

      if (displayMode == 1) Serial.print("/");
      if (category == 99)byteparameter[99] = map(integerinput[99], 0, 255, 0, 255);
      if (byteparameter[99] > 32)byteparameter[99] = 32;
      clump6    = map(byteparameter[99], 0, 255, 0, 255);
      EuclidGenerator(bins6, beats6, offsetnumber6, clump6);  //outputs to array "euclid"
      for (int x = 0; x < bins1; x++) drumcartridge6[x] = euclid[x];
      if (displayMode == 1) Serial.print(clump6);
      Resettime();

      if (displayMode == 1) Serial.print ("\t");
      for (int x = 0; x < bins6; x++)
      {
        if (displayMode == 1) Serial.print (" / ");
        if (displayMode == 1) Serial.print (drumcartridge6[x]);
      }
      if (displayMode == 1) Serial.println ("");


      if (displayMode == 1) Serial.print("100-101) fadeintime/fadeouttime(x10ms): ");
      if (category == 100)byteparameter[100] = map(integerinput[100], 0, 255, 0, 255);
      if (byteparameter[100] > 255)byteparameter[100] = 255;
      fadeintime   = map(byteparameter[100], 0, 255, 0, 25500);
      if (displayMode == 1) Serial.print(fadeintime);


      if (displayMode == 1) Serial.print("/");
      if (category == 101)byteparameter[101] = map(integerinput[101], 0, 255, 0, 255);
      if (byteparameter[101] > 255)byteparameter[101] = 255;
      fadeouttime   = map(byteparameter[101], 0, 255, 0, 25500);
      if (displayMode == 1) Serial.print(fadeouttime);

      //      if (displayMode == 1) Serial.print("/");
      //      if (category == 102)byteparameter[102] = map(integerinput[102], 0, 255, 0, 255);
      //      if (byteparameter[102] > 255)byteparameter[102] = 255;
      //      endchords   = map(byteparameter[102], 0, 255, 0, 255);
      //      if (displayMode == 1) Serial.print(endchords);
      //
      //      if (displayMode == 1) Serial.print("/");
      //      if (category == 103)byteparameter[103] = map(integerinput[103], 0, 255, 0, 255);
      //      if (byteparameter[103] > 255)byteparameter[103] = 255;
      //      timeout   = map(byteparameter[103], 0, 255, 0, 255);
      //      if (displayMode == 1) Serial.print(timeout);










      onetime = false;
      if (displayMode == 1) Serial.println("");
      if (displayMode == 1) Serial.println("");
      if (displayMode == 1) Serial.println("");
      if (displayMode == 1) Serial.println("");

    }//end of printscreen triggered printing  (only if new

    //////////////////////////////////////////
    // SAVE FILE DISPLAY
    //////////////////////////////////////////
    if (displayMode == 2)
    {
      if (printscreen == true)
      {
        printscreen = false;

        // SELECT DISPLAY
        Serial.print("0) display screen (0=synthE,1=drums,2=save,3=test, 4-PPL tune): ");
        displayMode = byteparameter[0];
        switch (displayMode)
        {
          case 0:
            Serial.println("0-synthesizer controls");
            break;
          case 1:
            Serial.println("1-drum controls");
            break;
          case 2:
            Serial.println("2-save settings");
            break;
          case 3:
            Serial.println("3-hardware monitor");
            break;
          case 4:
            Serial.println("4-PPL tuning");
            break;
          default:
            Serial.println("default");
            displayMode = 0;
            break;
        }
        Serial.print("PRESET: ");
        Serial.println(modecount);
        Serial.println("current synth parameter string: ");
        if (EEPROMsource == false) Serial.println("FACTORY SETTING"); else Serial.println("USER SETTING");
        for (int x = 0; x < 105; x++)
        {
          if (x != 0)Serial.print(int(byteparameter[x])); else Serial.print("0");
          Serial.print(",");
          if ((x % 20 == 0) && (x > 1)) Serial.println("");
        }
        Serial.println("");
        Serial.println("");
        Serial.println("*************save commands**********************");
        Serial.print("100) save location: ");
        if (category == 100) byteparameter[100] = map(integerinput[100], 0, 255, 0, 255);
        if (byteparameter[100] > 9)byteparameter[100] = 9;
        savelocation = map(byteparameter[100], 0, 255, 0, 255);
        switch (savelocation)
        {
          case 1:
            Serial.println("1-Aether");
            break;
          case 2:
            Serial.println("2-Ruby");
            break;
          case 3:
            Serial.println("3-Rose");
            break;
          case 4:
            Serial.println("4-Pumpkin");
            break;
          case 5:
            Serial.println("5-Shamrock");
            break;
          case 6:
            Serial.println("6-Sun");
            break;
          case 7:
            Serial.println("7-Artic");
            break;
          case 8:
            Serial.println("8-Lapis");
            break;
          case 9:
            Serial.println("9-Orchid");
            break;
          case 10:
            Serial.println("10-Porcelain");
            break;
          default:
            Serial.println("needs to be entered");
            break;
        }

        Serial.print("101) activate save location?: (no=0, yes=1)");
        if ((category == 101) && (integerinput[101] == 1))
        {
          integerinput[101] = 0;
          Serial.println("ready to save");
          Serial.println("");
          Serial.println("");
          Serial.println("");
          Serial.println("");
          Serial.println("save current parameters to this location? (no=0, yes=1)");
          Serial.println("");
          Serial.println("");
          Serial.println("");
          Serial.println("");
          while (Serial.available() == 0);
          if (Serial.read() == '1')
          {
            Serial.println("saving settings");
            EEPROMsource = true;
            delay(2000);
            printscreen = true;
            switch (savelocation)
            {
              case 1:
                for (int x = 1; x < 105; x++) EEPROM.write(x, byteparameter[x]);
                EEPROM.write(0, 0);  //marks as storage
                break;
              case 2:
                for (int x = 1; x < 105; x++) EEPROM.write(x + 105, byteparameter[x]);
                EEPROM.write(105, 0);
                break;
              case 3:
                for (int x = 1; x < 105; x++) EEPROM.write(x + 210, byteparameter[x]);
                EEPROM.write(210, 0);
                break;
              case 4:
                for (int x = 1; x < 105; x++) EEPROM.write(x + 315, byteparameter[x]);
                EEPROM.write(315, 0);
                break;
              case 5:
                for (int x = 1; x < 105; x++) EEPROM.write(x + 420, byteparameter[x]);
                EEPROM.write(420, 0);
                break;
              case 6:
                for (int x = 1; x < 105; x++) EEPROM.write(x + 525, byteparameter[x]);
                EEPROM.write(525, 0);
                break;
              case 7:
                for (int x = 1; x < 105; x++) EEPROM.write(x + 630, byteparameter[x]);
                EEPROM.write(630, 0);
                break;
              case 8:
                for (int x = 1; x < 105; x++) EEPROM.write(x + 735, byteparameter[x]);
                EEPROM.write(735, 0);
                break;
              case 9:
                for (int x = 1; x < 105; x++) EEPROM.write(x + 840, byteparameter[x]);
                EEPROM.write(840, 0);
                break;
              case 10:
                for (int x = 1; x < 105; x++) EEPROM.write(x + 945, byteparameter[x]);
                EEPROM.write(945, 0);
                break;
              default:
                // statements
                break;
            }
            Serial.println("settings saved");

          }
          else
          {
            Serial.println("factory reset this location? (no=0, yes=1)");
            Serial.println("");
            Serial.println("");
            Serial.println("");
            Serial.println("");
            while (Serial.available() > 0) Serial.read();
            while (Serial.available() == 0);
            if (Serial.read() == '1')
            {
              Serial.println("resetting to factory");
              EEPROMsource = false;
              delay(2000);
              printscreen = true;
              switch (savelocation)
              {
                case 1:
                  for (int x = 1; x < 105; x++) EEPROM.write(x, factorypreset1[x]);
                  EEPROM.write(0, 255);
                  break;
                case 2:
                  for (int x = 1; x < 105; x++) EEPROM.write(x + 105, factorypreset2[x]);
                  EEPROM.write(105, 255);
                  break;
                case 3:
                  for (int x = 1; x < 105; x++) EEPROM.write(x + 210, factorypreset3[x]);
                  EEPROM.write(210, 255);
                  break;
                case 4:
                  for (int x = 1; x < 105; x++) EEPROM.write(x + 315, factorypreset4[x]);
                  EEPROM.write(315, 255);
                  break;
                case 5:
                  for (int x = 1; x < 105; x++) EEPROM.write(x + 420, factorypreset5[x]);
                  EEPROM.write(420, 255);
                  break;
                case 6:
                  for (int x = 1; x < 105; x++) EEPROM.write(x + 525, factorypreset6[x]);
                  EEPROM.write(525, 255);
                  break;
                case 7:
                  for (int x = 1; x < 105; x++) EEPROM.write(x + 630, factorypreset7[x]);
                  EEPROM.write(630, 255);
                  break;
                case 8:
                  for (int x = 1; x < 105; x++) EEPROM.write(x + 735, factorypreset8[x]);
                  EEPROM.write(735, 255);
                  break;
                case 9:
                  for (int x = 1; x < 105; x++) EEPROM.write(x + 840, factorypreset9[x]);
                  EEPROM.write(840, 255);
                  break;
                case 10:
                  for (int x = 1; x < 105; x++) EEPROM.write(x + 945, factorypreset10[x]);
                  EEPROM.write(945, 255);
                  break;
                default:
                  // statements
                  break;
              }
            }
            else
            {
              Serial.println("save cancelled");
              delay(2000);
              printscreen = true;
            }
          }
        }
        if (Serial.available() > 0) Serial.read(); //flush becuase parse is buggy on CR+NL

        Serial.println("");
        Serial.println("");
        Serial.println("");
        Serial.println("");
        Serial.println("");
        Serial.println("");
        Serial.println("");
      }
    }




    //////////////////////////////////////////
    // TROUBLESHOOTING DISPLAY
    //////////////////////////////////////////
    if ((displayMode == 3) && ((millis() - last_time) > 700))
    {
      last_time = millis();
      printscreen = false;
      Serial.print(last_time);
      Serial.print("0) display screen (0=synthA,1=drums,2=save,3=test, 4-PPL tune): ");
      displayMode = byteparameter[0];
      switch (displayMode)
      {
        case 0:
          Serial.println("0-synthesizer controls");
          break;
        case 1:
          Serial.println("1-drum controls");
          break;
        case 2:
          Serial.println("2-save settings");
          break;
        case 3:
          Serial.println("3-hardware monitor");
          break;
        case 4:
          Serial.println("4-PPL tuning");
          break;
        default:
          Serial.println("default");
          displayMode = 0;
          break;
      }
      Serial.print("PRESET: ");
      Serial.println(modecount);
      Serial.println("***********************************************************");
      Serial.print("   CPU: ");
      Serial.print("all = ");
      Serial.print(AudioProcessorUsage());
      Serial.print(", ");
      Serial.print(AudioProcessorUsageMax());
      Serial.print("    ");
      Serial.print("Memory: ");
      Serial.print(AudioMemoryUsage());
      Serial.print(", ");
      Serial.println(AudioMemoryUsageMax());
      AudioProcessorUsageMaxReset();
      AudioMemoryUsageMaxReset();
      Serial.println("***************************************");
      Serial.print("cherry1 =");
      Serial.println(cherry1);
      Serial.print("cherry2 =");
      Serial.println(cherry2);
      Serial.print("cherry3 =");
      Serial.println(cherry3);
      Serial.println("***************************************");
      Serial.print("phasetargetset: ");
      for (int y = 0;  y < 6; y++)
      {
        Serial.print( phasetargetset[y], 3);
        Serial.print (", ");
      }
      Serial.println("");
      Serial.print("phasegainset: ");
      for (int y = 0;  y < 6; y++)
      {
        Serial.print (phasegainset[y], 3);
        Serial.print (", ");
      }
      Serial.println("");

      Serial.print("speakergainset: ");
      for (int y = 0;  y < 6; y++)
      {
        Serial.print (speakergainset[y], 3);
        Serial.print (", ");
      }

      Serial.println("");
      Serial.print("phasetarget: ");
      Serial.print(phasetarget);
      Serial.print("   phasegain: ");
      Serial.print(phasegain);
      Serial.print("   speakergain: ");
      Serial.println(speakergain, 3);
      Serial.println("");

      Serial.print("drivefrequency: ");
      Serial.print(drivefrequency);
      Serial.print("  closestscalenumber: ");
      Serial.print(closestscalenumber);
      Serial.print(" hyster chrom number: ");
      Serial.print(scalefilter[hyster_closest_scale_number]);
      Serial.print("  closest scale freq: ");
      Serial.println(chromatic[scalefilter[hyster_closest_scale_number]]);

      Serial.print("proportional: ");
      Serial.print(proportional);
      Serial.print(" phaseshift: ");
      Serial.print(phaseshift);
      Serial.print(" phaseshiftdegrees: ");
      Serial.print(phaseshiftdegrees);
      Serial.print("  phaseerror: ");
      Serial.print(phaseerror);
      Serial.print("  phaseerrordegrees: ");
      Serial.println(phaseerrordegrees);


      Serial.println("");
      Serial.println("");
      Serial.println("");
    }


    //////////////////////////////////////////
    // PPL TUNING DISPLAY
    //////////////////////////////////////////

    //whammy pot allows parameters to be changes real-time
    //press middle button to updates parameter array
    //copy (ctrl-v/ctrl-c?) and load into program

    if ((displayMode == 4) && ((millis() - last_time) > 1400))
    {
      last_time = millis();
      printscreen = false;
      Serial.print("0) display screen (0=synthB,1=drums,2=save,3=test, 4=PPL tune): ");
      displayMode = byteparameter[0];
      switch (displayMode)
      {
        case 0:
          Serial.println("0-synthesizer controls");
          break;
        case 1:
          Serial.println("1-drum controls");
          break;
        case 2:
          Serial.println("2-save settings");
          break;
        case 3:
          Serial.println("3-hardware monitor");
          break;
        case 4:
          Serial.println("4-PPL tuning");
          break;
        default:
          Serial.println("default");
          displayMode = 0;
          break;
      }
      Serial.print("PRESET: ");
      Serial.println(modecount);
      Serial.println("***********************************************************");

      Serial.println("expects whammy pot to be connected, pot controls the following:");
      Serial.println("");
      Serial.print("1) forcemode (0=freq,1=p-target,2=p-gain,3=speakervol,4=off, 5=d-gain): ");
      forceMode = byteparameter[1];
      switch (forceMode)
      {
        case 0:
          Serial.println("0-frequency");
          break;
        case 1:
          Serial.println("1-phasetarget");
          break;
        case 2:
          Serial.println("2-phasegain");
          break;
        case 3:
          Serial.println("3-speaker volume");
          break;
        case 4:
          Serial.println("4-off");
          break;
        case 5:
          Serial.println("5-derivative");
          break;
        default:
          Serial.println("default");
          forceMode = 4;
          break;
      }
      Serial.println("*************************************");
      Serial.print("phasetargetset: "); //
      for (int y = 0;  y < 25; y++)
      {
        if (y == tuningband) Serial.print("*");
        if (y == 12) Serial.println("");
        Serial.print( phasetargetset[y], 2);
        Serial.print (", ");
      }
      Serial.println("");
      Serial.println("");

      Serial.print("phasegainset: "); //
      for (int y = 0;  y < 25; y++)
      {

        if (y == tuningband) Serial.print("*");
        if (y == 12) Serial.println("");
        Serial.print (phasegainset[y], 2);
        Serial.print (", ");
      }
      Serial.println("");
      Serial.println("");

      Serial.print("speakergainset: "); //
      for (int y = 0;  y < 25; y++)
      {
        if (y == tuningband) Serial.print("*");
        if (y == 12) Serial.println("");
        Serial.print (speakergainset[y], 2);
        Serial.print (", ");
      }


      Serial.println("");

      Serial.print("derivativegainset: "); //
      for (int y = 0;  y < 19; y++)
      {
        if (y == tuningband) Serial.print("*");
        if (y == 10) Serial.println("");
        Serial.print (derivativegainset[y], 2);
        Serial.print (", ");
      }

      Serial.println("");
      Serial.println("");
      //frequency info**************************************************
      Serial.println("*************************************");
      Serial.print("tuningband: ");
      Serial.print(tuningband);

      if (forceMode == 0)
      {
        Serial.print("   drivefrequencyforced: ");
        Serial.print(drivefrequencyforced);
      }
      else
      {
        Serial.print("   drivefrequency: ");
        Serial.print(drivefrequency);
      }

      Serial.print("  closest hyster scale freq: ");
      Serial.print(chromatic[scalefilter[hyster_closest_scale_number]]);


      Serial.println("");
      //gain info**************************************************

      if (forceMode == 3)
      {
        Serial.print("   AGCsmoothforced: ");
        Serial.print(AGCsmoothforced, 3);
      }
      else
      {
        Serial.print("   speakergain: ");
        Serial.print(speakergain, 3);
      }
      Serial.print("  microphone peak: ");
      Serial.print(peak1.read());

      Serial.print("  boost: ");
      Serial.print(boost);


      Serial.println("");
      //phasegain info**************************************************

      if (forceMode == 2)
      {
        Serial.print("phasegainforced: ");
        Serial.print(phasegainforced);
      }
      else
      {
        Serial.print("phasegain: ");
        Serial.print(phasegain);
      }

      //Serial.println("");


      if (forceMode == 1)
      {
        Serial.print("   phasetargetforced: ");
        Serial.print(phasetargetforced );
      }
      else
      {
        Serial.print("   phasetarget: ");
        Serial.print(phasetarget );
      }


      if (forceMode == 1)
      {
        Serial.print("   phasetargetforced (samples): ");
        Serial.print(phasetargetforced * sinelength );
      }
      else
      {
        Serial.print("   phasetarget (samples): ");
        Serial.print(phasetarget * sinelength);
      }

      if (forceMode == 1)
      {
        Serial.print("   phasetargetddegreesforced: ");
        Serial.print(phasetargetforced  * 360);
      }
      else
      {
        Serial.print("   phasetargetdegrees: ");
        Serial.println(phasetarget * 360);
      }
      if (forceMode == 5)
      {
        Serial.print("   derivativegainforced: ");
        Serial.print(derivativegainforced);
      }
      else
      {
        Serial.print("   derivativegain: ");
        Serial.print(derivativegain);
      }

      Serial.print("   fderivative: ");
      Serial.println(fderivative);
      Serial.println("phase error*************************");
      Serial.print("   phaseerror: ");
      Serial.print(phaseerror);
      Serial.print("   phaseerrordegrees: ");
      Serial.println(phaseerrordegrees);

      Serial.println("misc********************************");

      Serial.print("   phaseshift: ");
      Serial.print(phaseshift);
      Serial.print("   phaseshift2: ");
      Serial.print(phaseshift2);
      Serial.print("   composite: ");
      Serial.println((phaseshift2 + phaseshift) / 2);


      Serial.print("   startdrive: ");
      Serial.print(startdrive);
      Serial.print("   sinelength: ");
      Serial.print(sinelength);
      Serial.print("   precisemicstart: ");
      Serial.print(precisemicstart);
      Serial.print("   precisemicend: ");
      Serial.print(precisemicend);


      Serial.print("   phaseshiftdegrees: ");
      Serial.print(phaseshiftdegrees);
      Serial.print("   phaseshiftdegrees: ");
      Serial.println(phaseshiftdegrees);

      Serial.print("   proportional: ");
      Serial.print(proportional);

      Serial.print("   closestscalenumber: ");
      Serial.print(closestscalenumber);

      Serial.print("   closest hyster chrom number: ");
      Serial.println(scalefilter[hyster_closest_scale_number]);

      Serial.println("profile*****************************");
      Serial.print("   profiledelta usecs: ");
      Serial.print(profiledelta);
    }



    capture = false; //controls filling buffer
  }//end of capture==true
}//end of main *********************************************************************************************************


////////////////////////////////////////////////////
//     FUNCTIONS
///////////////////////////////////////////////////

void Resettime(void)
{
  unisonclock = 0;
  euclidclock1 = 0;
  euclidclock2 = 0;
  euclidclock3 = 0;
  euclidclock4 = 0;
  euclidclock5 = 0;
  euclidclock6 = 0;
  measures = 0;
  progressionmeasures = 0;
}

//////////////////////////////////////////////////////////
// PLAYSTRING FUNCTION  plays dulcimer string (rotates through strings
/////////////////////////////////////////////////////////

void Playstring(float pluck, bool bend)
{
  if (bend == 0)
  {
    sinebank++;
    if (sinebank > 3) sinebank = 1;
    switch (sinebank)
    {
      case 1:
        string2.noteOn(pluck, 1);
        sine2.frequency(pluck);
        dc2.amplitude(1, 20);
        sine6.frequency(pluck / 2);
        dc6.amplitude(1, 20);
        break;
      case 2:
        string3.noteOn(pluck, 1);
        sine3.frequency(pluck);
        dc3.amplitude(1, 20);
        sine7.frequency(pluck / 2);
        dc7.amplitude(1, 20);
        break;
      case 3:
        string4.noteOn(pluck, 1);
        sine4.frequency(pluck);
        dc4.amplitude(1, 20);
        sine8.frequency(pluck / 2);
        dc8.amplitude(1, 20);
        break;
      default:
        // statements
        break;
    }
  }
  else
  {
    //Serial.println("bend");
    switch (sinebank)
    {
      case 1:
        string2.frequency(pluck);
        sine2.frequency(pluck);
        dc2.amplitude(1, 20);
        sine6.frequency(pluck / 2);
        dc6.amplitude(1, 20);
        break;
      case 2:
        string3.frequency(pluck);
        sine3.frequency(pluck);
        dc3.amplitude(1, 20);
        sine7.frequency(pluck / 2);
        dc7.amplitude(1, 20);
        break;
      case 3:
        string4.frequency(pluck);
        sine4.frequency(pluck);
        dc4.amplitude(1, 20);
        sine8.frequency(pluck / 2);
        dc8.amplitude(1, 20);
        break;
      default:
        // statements
        break;
    }

  }


}

//////////////////////////////////////////////////////////
// SHIMMER CHORD plays chords that cross fade
/////////////////////////////////////////////////////////

void Playshimmer(float pluck1, float pluck2, float pluck3)
{
  gliderate = 2000;

  bool offpluck = 0;  //turn shimmer off
  if ((pluck1 == 0) && (pluck2 == 0) && (pluck3 == 0))offpluck = true; else offpluck = false;

  if (shimmerbank == 1) shimmerbank = 0; else shimmerbank = 1;
  switch (shimmerbank)
  {
    case 0:
      shimmerwaveform1.frequency(pluck1);
      if (offpluck == true) chordglide0.amplitude(0, gliderate); else chordglide0.amplitude(1, gliderate);
      chordglide3.amplitude(0, gliderate);
      shimmerwaveform2.frequency(pluck2);
      if (offpluck == true) chordglide1.amplitude(0, gliderate); else chordglide1.amplitude(1, gliderate);
      chordglide4.amplitude(0, gliderate);
      shimmerwaveform3.frequency(pluck3);
      if (offpluck == true) chordglide2.amplitude(0, gliderate); else chordglide2.amplitude(1, gliderate);
      chordglide5.amplitude(0, gliderate);
      break;
    case 1:
      shimmerwaveform4.frequency(pluck1);
      if (offpluck == true) chordglide3.amplitude(0, gliderate); else chordglide3.amplitude(1, gliderate);
      chordglide0.amplitude(0, gliderate);
      shimmerwaveform5.frequency(pluck2);
      if (offpluck == true) chordglide4.amplitude(0, gliderate); else chordglide4.amplitude(shimmer_gain, gliderate);
      chordglide1.amplitude(0, gliderate);
      shimmerwaveform6.frequency(pluck3);
      if (offpluck == true) chordglide5.amplitude(0, gliderate); else chordglide5.amplitude(1, gliderate);
      chordglide2.amplitude(0, gliderate);
      break;
    default:
      // statements
      break;
  }

  plucktime = millis();
  // Serial.println(millis());
  //shimmerbankswitch = true; //don't switch banks on switch glitches
}

//////////////////////////////////////////////////////////
// COLORME FUNCTION  sets led color
/////////////////////////////////////////////////////////
void Colorme(int color)
{
  uncolor = millis();
  switch (color)
  {
    case 1:
      analogWrite(redPin, 256);//off
      analogWrite(bluePin, 256);
      analogWrite(greenPin, 256);
      break;
    case 2:
      analogWrite(redPin, 128);//red
      analogWrite(bluePin, 256);
      analogWrite(greenPin, 256);
      break;
    case 3:
      analogWrite(redPin, 64);//pink
      analogWrite(bluePin, 198);
      analogWrite(greenPin, 198);
      break;
    case 4:
      analogWrite(redPin, 64);//orange
      analogWrite(bluePin, 256);
      analogWrite(greenPin, 172);
      break;
    case 5:
      analogWrite(redPin, 256);//green
      analogWrite(bluePin, 256);
      analogWrite(greenPin, 128);
      break;
    case 6:
      analogWrite(redPin, 128);//yellow
      analogWrite(bluePin, 256);
      analogWrite(greenPin, 128);
      break;
    case 7:
      analogWrite(redPin, 256);//aqua
      analogWrite(bluePin, 128);
      analogWrite(greenPin, 128);
      break;
    case 8:
      analogWrite(redPin, 256);//blue
      analogWrite(bluePin, 128);
      analogWrite(greenPin, 256);
      break;
    case 9:
      analogWrite(redPin, 128);//violet
      analogWrite(bluePin, 128);
      analogWrite(greenPin, 256);
      break;
    case 10:
      analogWrite(redPin, 128); //white
      analogWrite(bluePin, 128);
      analogWrite(greenPin, 128);
      break;
    default:
      // if nothing else matches, do the default
      // default is optional
      break;
  }
}


//////////////////////////////////////////////////////////
// GRABDATA FUNCTION  ISR to buffer microphone samples for analysis
/////////////////////////////////////////////////////////
void grabdata()
{
  //unsigned long starttime = micros(); //for profiling

  //Sine wave output to mouth speaker
  unsigned long temptime = micros();  //figure out sine table lookup
  int tableindex = int((temptime - ISRlasttime) / sineincrement);
  int monitortableindex = int((temptime - ISRlasttime) / monitorsineincrement);
  if (tableindex >= 100) //rising edge is always
  {
    tableindex = 0;
    ISRlasttime = temptime;
  }

  monitorval = int(sinetable[tableindex] * monitorgain);
  AudioNoInterrupts();
  if (woken == true)analogWrite(monitorPin, monitorval);
  if (forceMode == 3) driveval = int(sinetable[tableindex] * AGCsmoothforced);
  else driveval = int(sinetable[tableindex] * speakergain); // grab new reading from drivewave
  if (woken == false) driveval = 0;
  analogWrite(mouthSpkrOutput, driveval);//output to speaker
  AudioInterrupts();

  //read mouth microphone
  if (capture == false) //do this only if new data needed
  {
    micval = analogRead(micInputPin);   // grab new reading from microphone
    micbuffer[h] = micval;
    if ((tableindex == 0) && (earliest == true) && (h > 4))
    {
      risingedge = h;
      earliest = false;
    }
    drivebuffer[h] = driveval; // put new data into buffer
    h++;
    if (h >= BUFSIZE)
    {
      h = 0;
      capture = true; //full data set complete
      earliest = true;
    }
  }
  //duration = int(micros() - starttime);
}

//////////////////////////////////////////////////////////
// EUCLIDGENERATOR creates a euclid rhythm
/////////////////////////////////////////////////////////

void EuclidGenerator(int buckets, int beats, int offsetnumber, int clumpy)//generates euclid rhythms
{
  //fill an array euclid[50] with bits
  //providing euclid rhythyms for input "buckets" and "beats".
  //The useful array size is the provided bucket size and must be handled by user

  //The program works by making an array representing spaces between beats, loading the
  //number of beats into the first bits of this array (e.g., three beats equals three array
  //places set), then equalizing the values of
  //the array (interatively subtracting from large array values and adding
  //to smaller array values.  The space array then creates a beat array having
  //those spaces. returns values in euclid[] global. oofset shifts pattern by bins
  //clump weakens the rules to allow uneven spacing

  //int euclidspace[50]; //array used to track spaces between beats
  int euclidspace[50];
  int tempbeats = 0;
  int minspace = 0;
  int minspaceindex = 0;
  int maxspace = 0;
  int maxspaceindex = 0;
  int euclidindex = 0;
  bool notdoneyet = true;

  //build an array of spaces with beats installed
  tempbeats = beats;
  for (int x = 0; x < buckets; x++)
  {
    tempbeats--;
    if (tempbeats > 0)euclidspace[x] = 0;  //first beats are packed
    else if (tempbeats == 0)euclidspace[x] = buckets - beats; //last space is what is left
    else if (tempbeats < 0)euclidspace[x] = -1; //after beats are placed

  }
  //now even out the buckets
  //(1) find the minimum and maximum

  notdoneyet = true;

  while (notdoneyet == true)
  {
    minspace = 99;
    minspaceindex = 0;
    maxspace = -99;
    maxspaceindex = 0;
    for (int x = 0; x < buckets; x++)
    {
      if ((euclidspace[x] < minspace) && (euclidspace[x] >= 0))
      {
        minspace = euclidspace[x];
        minspaceindex = x;
      }
      if (euclidspace[x] > maxspace)
      {
        maxspace = euclidspace[x];
        maxspaceindex = x;
      }
    }
    //(2) shuffle spaces from max to min
    if (maxspace - clumpy - 1 > minspace) //without clumpy -1 is correct
    {
      euclidspace[minspaceindex]++; //even out buckets by shifts between max and min
      euclidspace[maxspaceindex]--;
    }
    else notdoneyet = false;
  }

  //create the final beat array "euclid" matching the spaces
  for (int x = 0; x < buckets; x++)euclid[x] = false; //create blank array

  //create the beat array from the space array
  euclidindex = 0;
  for (int x = 0; x < buckets; x++)
  {
    if (euclidspace[x] != -1)
    {
      euclid[euclidindex] = true;
      euclidindex = euclidindex + euclidspace[x] + 1;
    }
    else euclid[buckets - 1] = false; //set last bit to zero
  }

  //create offset
  bool euclidrotate[50];
  int y = offsetnumber;
  for (int x = 0; x < buckets; x++)
  {
    euclidrotate[y] = euclid[x];
    y++;
    if (y >= buckets) y = 0;
  }

  for (int x = 0; x < buckets; x++)euclid[x] = euclidrotate[x];

  if (beats == 0) for (int x = 0; x < buckets + 1; x++) euclid[x] = false; //if beats is zero null out

}

//////////////////////////////////////////////////////////
// ANALOGCHORDCALCULATE generates auto chords from melody c scale
/////////////////////////////////////////////////////////

void analogchordcalculate(int locknote, float octave)//just intonation
{
  chrom_ref = scalefilter[locknote];  //lock note is closest chromatic number
  // locknote is a scale degree
  notetarget = locknote;

  if ((chrom_ref == 2) || (chrom_ref == 14) || (chrom_ref == 26) || (chrom_ref == 38)) //A
  {

    glide1.amplitude(chromatic[chrom_ref] / 20000 * octave, glide_rate); //3rd
    thirdfreq = chromatic[chrom_ref] / 20000 * octave;
    target1 = chromatic[chrom_ref];
    justifiedtarget1 = target1;


    glide2.amplitude(chromatic[chrom_ref + 3] / 20000 * octave, glide_rate); //5th
    fifthfreq = chromatic[chrom_ref + 3] / 20000 * octave;
    target2 = chromatic[chrom_ref + 3];
    justifiedtarget2 = target1 * 6 / 5;


    glide3.amplitude(chromatic[chrom_ref - 4] / 20000 * octave, glide_rate); //Root
    rootfreq = chromatic[chrom_ref - 4] / 20000 * octave;
    target3 = chromatic[chrom_ref - 4];
    justifiedtarget3 = target1 * 4 / 5;

    //    glide4.amplitude(chromatic[chrom_ref - 2] / 20000 * octave, glide_rate); //2nd
    //    secondfreq = chromatic[chrom_ref - 2] / 20000 * octave;


    //    glide5.amplitude(chromatic[chrom_ref + 5] / 20000 * octave, glide_rate); //6th
    //    sixthfreq = chromatic[chrom_ref + 5] / 20000 * octave;

  }
  if ((chrom_ref == 3) || (chrom_ref == 15) || (chrom_ref == 27) || (chrom_ref == 39)) //A#
  {

    glide1.amplitude(chromatic[chrom_ref] / 20000 * octave, glide_rate); //3rd
    thirdfreq = chromatic[chrom_ref] / 20000 * octave;
    target1 = chromatic[chrom_ref];
    justifiedtarget1 = target1;

    glide2.amplitude(chromatic[chrom_ref + 3] / 20000 * octave, glide_rate); //5th
    fifthfreq = chromatic[chrom_ref + 3] / 20000 * octave;
    target2 = chromatic[chrom_ref + 3];
    justifiedtarget2 = target1 * 6 / 5;

    glide3.amplitude(chromatic[chrom_ref - 4] / 20000 * octave, glide_rate); //Root
    rootfreq = chromatic[chrom_ref - 4] / 20000 * octave;
    target3 = chromatic[chrom_ref - 4];
    justifiedtarget3 = target1 * 4 / 5;
  }

  if ((chrom_ref == 4) || (chrom_ref == 16) || (chrom_ref == 28) || (chrom_ref == 40)) //B
  {
    glide1.amplitude(chromatic[chrom_ref] / 20000 * octave, glide_rate); //3rd
    thirdfreq = chromatic[chrom_ref] / 20000 * octave;
    target1 = chromatic[chrom_ref];
    justifiedtarget1 = target1;


    glide2.amplitude(chromatic[chrom_ref + 3] / 20000 * octave, glide_rate); //5th
    fifthfreq = chromatic[chrom_ref + 3] / 20000 * octave;
    target2 = chromatic[chrom_ref + 3];
    justifiedtarget2 = target1 * 6 / 5;

    glide3.amplitude(chromatic[chrom_ref - 4] / 20000 * octave, glide_rate); //Root
    rootfreq = chromatic[chrom_ref - 4] / 20000 * octave;
    target3 = chromatic[chrom_ref - 4];
    justifiedtarget3 = target1 * 4 / 5;


    //    glide4.amplitude(chromatic[chrom_ref - 2] / 20000 * octave, glide_rate); //2nd
    //    secondfreq = chromatic[chrom_ref - 2] / 20000 * octave;


    //    glide5.amplitude(chromatic[chrom_ref + 5] / 20000 * octave, glide_rate); //6th
    //    sixthfreq = chromatic[chrom_ref + 5] / 20000 * octave;

  }
  if ((chrom_ref == 5) || (chrom_ref == 17) || (chrom_ref == 29) || (chrom_ref == 41)) //C
  {

    glide1.amplitude(chromatic[chrom_ref] / 20000 * octave, glide_rate); //root
    rootfreq = chromatic[chrom_ref] / 20000 * octave;
    target1 = chromatic[chrom_ref];
    justifiedtarget1 = target1;


    glide2.amplitude(chromatic[chrom_ref + 4] / 20000 * octave, glide_rate); //3rd
    thirdfreq = chromatic[chrom_ref + 4] / 20000 * octave;
    target2 = chromatic[chrom_ref + 4];
    justifiedtarget2 = target1 * 5 / 4;


    glide3.amplitude(chromatic[chrom_ref + 7] / 20000 * octave, glide_rate); //5th
    fifthfreq = chromatic[chrom_ref + 7] / 20000 * octave;
    target3 = chromatic[chrom_ref + 7];
    justifiedtarget3 = target1 * 3 / 2;



    //    glide4.amplitude(chromatic[chrom_ref + 2] / 20000 * octave, glide_rate); //2nd
    //    secondfreq = chromatic[chrom_ref + 2] / 20000 * octave;


    //    glide5.amplitude(chromatic[chrom_ref + 9] / 20000 * octave, glide_rate); //6th
    //    sixthfreq = chromatic[chrom_ref + 9] / 20000 * octave;

  }

  if ((chrom_ref == 6) || (chrom_ref == 18) || (chrom_ref == 30) || (chrom_ref == 42)) //c#
  {

    glide1.amplitude(chromatic[chrom_ref] / 20000 * octave, glide_rate); //3rd
    thirdfreq = chromatic[chrom_ref] / 20000 * octave;
    target1 = chromatic[chrom_ref];
    justifiedtarget1 = target1;

    glide2.amplitude(chromatic[chrom_ref + 2] / 20000 * octave, glide_rate); //5th
    fifthfreq = chromatic[chrom_ref + 3] / 20000 * octave;
    target2 = chromatic[chrom_ref + 3];
    justifiedtarget2 = target1 * 6 / 5;

    glide3.amplitude(chromatic[chrom_ref - 4] / 20000 * octave, glide_rate); //Root
    rootfreq = chromatic[chrom_ref - 4] / 20000 * octave;
    target3 = chromatic[chrom_ref - 4];
    justifiedtarget3 = target1 * 4 / 5;

  }
  if ((chrom_ref == 7) || (chrom_ref == 19) || (chrom_ref == 31) || (chrom_ref == 43)) //D
  {
    glide1.amplitude(chromatic[chrom_ref ] / 20000 * octave, glide_rate); //5th
    fifthfreq = chromatic[chrom_ref ] / 20000 * octave;
    target1 = chromatic[chrom_ref ];
    justifiedtarget1 = target1;


    glide2.amplitude(chromatic[chrom_ref - 7] / 20000 * octave, glide_rate); //Root
    rootfreq = chromatic[chrom_ref - 7] / 20000 * octave;
    target2 = chromatic[chrom_ref - 7];
    justifiedtarget2 = target1 * 2 / 3;


    glide3.amplitude(chromatic[chrom_ref - 3] / 20000 * octave, glide_rate); //3rd
    thirdfreq = chromatic[chrom_ref - 3] / 20000 * octave;
    target3 = chromatic[chrom_ref - 3];
    justifiedtarget3 = target1 * 5 / 6;


    //    glide4.amplitude(chromatic[chrom_ref - 5] / 20000 * octave, glide_rate); //2nd
    //    secondfreq = chromatic[chrom_ref - 5] / 20000 * octave;


    //    glide5.amplitude(chromatic[chrom_ref + 2] / 20000 * octave, glide_rate); //6th
    //    sixthfreq = chromatic[chrom_ref + 2] / 20000 * octave;

  }


  if ((chrom_ref == 8) || (chrom_ref == 20) || (chrom_ref == 32) || (chrom_ref == 44)) //D#
  {

    glide1.amplitude(chromatic[chrom_ref] / 20000 * octave, glide_rate); //3rd
    thirdfreq = chromatic[chrom_ref] / 20000 * octave;
    target1 = chromatic[chrom_ref];
    justifiedtarget1 = target1;

    glide2.amplitude(chromatic[chrom_ref + 3] / 20000 * octave, glide_rate); //5th
    fifthfreq = chromatic[chrom_ref + 3] / 20000 * octave;
    target2 = chromatic[chrom_ref + 3];
    justifiedtarget2 = target1 * 6 / 5;


    glide3.amplitude(chromatic[chrom_ref - 4] / 20000 * octave, glide_rate); //Root
    rootfreq = chromatic[chrom_ref - 4] / 20000 * octave;
    target3 = chromatic[chrom_ref - 4];
    justifiedtarget3 = target1 * 2 / 3;

  }

  if ((chrom_ref == 9) || (chrom_ref == 21) || (chrom_ref == 33) || (chrom_ref == 45)) //E
  {
    glide1.amplitude(chromatic[chrom_ref] / 20000 * octave, glide_rate); //3rd
    thirdfreq = chromatic[chrom_ref] / 20000 * octave;
    target1 = chromatic[chrom_ref];
    justifiedtarget1 = target1;


    glide2.amplitude(chromatic[chrom_ref + 3] / 20000 * octave, glide_rate); //5th
    fifthfreq = chromatic[chrom_ref + 3] / 20000 * octave;
    target2 = chromatic[chrom_ref + 3];
    justifiedtarget2 = target1 * 6 / 5;


    glide3.amplitude(chromatic[chrom_ref - 4] / 20000 * octave, glide_rate); //Root
    rootfreq = chromatic[chrom_ref - 4] / 20000 * octave;
    target3 = chromatic[chrom_ref - 4];
    justifiedtarget3 = target1 * 4 / 5;


    //    glide4.amplitude(chromatic[chrom_ref - 2] / 20000 * octave, glide_rate); //2nd
    //    secondfreq = chromatic[chrom_ref - 2] / 20000 * octave;


    //    glide5.amplitude(chromatic[chrom_ref + 5] / 20000 * octave, glide_rate); //6th
    //    sixthfreq = chromatic[chrom_ref + 5] / 20000 * octave;

  }

  if ((chrom_ref == 10) || (chrom_ref == 22) || (chrom_ref == 34) || (chrom_ref == 46)) //F
  {
    glide1.amplitude(chromatic[chrom_ref] / 20000 * octave, glide_rate); //root
    rootfreq = chromatic[chrom_ref] / 20000 * octave;
    target1 = chromatic[chrom_ref ];
    justifiedtarget1 = target1;


    glide2.amplitude(chromatic[chrom_ref + 4] / 20000 * octave, glide_rate); //3rd
    thirdfreq = chromatic[chrom_ref + 4] / 20000 * octave;
    target2 = chromatic[chrom_ref + 4];
    justifiedtarget2 = target1 * 5 / 4;


    glide3.amplitude(chromatic[chrom_ref + 7] / 20000 * octave, glide_rate); //5th
    fifthfreq = chromatic[chrom_ref + 7] / 20000 * octave;
    target3 = chromatic[chrom_ref + 7];
    justifiedtarget3 = target1 * 3 / 2;


    //    glide4.amplitude(chromatic[chrom_ref + 2] / 20000 * octave, glide_rate); //2nd
    //    secondfreq = chromatic[chrom_ref + 2] / 20000 * octave;


    //    glide5.amplitude(chromatic[chrom_ref + 9] / 20000 * octave, glide_rate); //6th
    //    sixthfreq = chromatic[chrom_ref + 9] / 20000 * octave;

  }

  if ((chrom_ref == 11) || (chrom_ref == 23) || (chrom_ref == 35) || (chrom_ref == 47)) //f#
  {
    glide1.amplitude(chromatic[chrom_ref] / 20000 * octave, glide_rate); //3rd
    thirdfreq = chromatic[chrom_ref] / 20000 * octave;
    target1 = chromatic[chrom_ref];
    justifiedtarget1 = target1;

    glide2.amplitude(chromatic[chrom_ref + 2] / 20000 * octave, glide_rate); //5th
    fifthfreq = chromatic[chrom_ref + 3] / 20000 * octave;
    target2 = chromatic[chrom_ref + 3];
    justifiedtarget2 = target1 * 6 / 5;

    glide3.amplitude(chromatic[chrom_ref - 4] / 20000 * octave, glide_rate); //Root
    rootfreq = chromatic[chrom_ref - 5] / 20000 * octave;
    target3 = chromatic[chrom_ref - 5];
    justifiedtarget3 = target1 * 2 / 3;
  }

  if ((chrom_ref == 12) || (chrom_ref == 24) || (chrom_ref == 36) || (chrom_ref == 48)) //G
  {
    glide1.amplitude(chromatic[chrom_ref] / 20000 * octave, glide_rate); //root
    rootfreq = chromatic[chrom_ref] / 20000 * octave;
    target1 = chromatic[chrom_ref];
    justifiedtarget1 = target1;

    glide2.amplitude(chromatic[chrom_ref + 4] / 20000 * octave, glide_rate); //3rd
    thirdfreq = chromatic[chrom_ref + 4] / 20000 * octave;
    target2 = chromatic[chrom_ref + 4];
    justifiedtarget2 = target1 * 5 / 4;

    glide3.amplitude(chromatic[chrom_ref + 7] / 20000 * octave, glide_rate); //5th
    fifthfreq = chromatic[chrom_ref + 7] / 20000 * octave;
    target3 = chromatic[chrom_ref + 7];
    justifiedtarget3 = target1 * 3 / 2;

    //    glide4.amplitude(chromatic[chrom_ref + 2] / 20000 * octave, glide_rate); //2nd
    //    secondfreq = chromatic[chrom_ref + 2] / 20000 * octave;

    //    glide5.amplitude(chromatic[chrom_ref + 9] / 20000 * octave, glide_rate); //6th
    //    sixthfreq = chromatic[chrom_ref + 9] / 20000 * octave;
  }

  if ((chrom_ref == 13) || (chrom_ref == 25) || (chrom_ref == 37)) //g#
  {

    glide1.amplitude(chromatic[chrom_ref] / 20000 * octave, glide_rate); //3rd
    thirdfreq = chromatic[chrom_ref] / 20000 * octave;
    target1 = chromatic[chrom_ref];
    justifiedtarget1 = target1;

    glide2.amplitude(chromatic[chrom_ref + 2] / 20000 * octave, glide_rate); //5th
    fifthfreq = chromatic[chrom_ref + 3] / 20000 * octave;
    target2 = chromatic[chrom_ref + 3];
    justifiedtarget2 = target1 * 6 / 5;

    glide3.amplitude(chromatic[chrom_ref - 4] / 20000 * octave, glide_rate); //Root
    rootfreq = chromatic[chrom_ref - 4] / 20000 * octave;
    target3 = chromatic[chrom_ref - 4];
    justifiedtarget3 = target1 * 2 / 3;

  }
}


////////////////////////////////////////////////////////////
//// ANALOGCHORDCALCULATE generates auto chords from melody 5 note dorian
///////////////////////////////////////////////////////////
//
//void analogchordcalculate(int locknote, float octave)//just intonation
//{
//  chrom_ref = scalefilter[locknote];  //lock note is closest chromatic number
//  // locknote is a scale degree
//
//  if ((chrom_ref == 2) || (chrom_ref == 14) || (chrom_ref == 26)) //A
//  {
//
//    glide1.amplitude(chromatic[chrom_ref] / 20000 * octave, glide_rate); //3rd
//    thirdfreq = chromatic[chrom_ref] / 20000 * octave;
//
//
//    glide2.amplitude(chromatic[chrom_ref + 3] / 20000 * octave, glide_rate); //5th
//    fifthfreq = chromatic[chrom_ref + 3] / 20000 * octave;
//
//
//    glide3.amplitude(chromatic[chrom_ref - 4] / 20000 * octave, glide_rate); //Root
//    rootfreq = chromatic[chrom_ref - 4] / 20000 * octave;
//  }
//  if ((chrom_ref == 5) || (chrom_ref == 17)|| (chrom_ref == 29)) //C
//  {
//
//    glide1.amplitude(chromatic[chrom_ref] / 20000 * octave, glide_rate); //root
//    rootfreq = chromatic[chrom_ref] / 20000 * octave;
//
//
//    glide2.amplitude(chromatic[chrom_ref + 3] / 20000 * octave, glide_rate); //3rd
//    thirdfreq = chromatic[chrom_ref + 3] / 20000 * octave;
//
//
//    glide3.amplitude(chromatic[chrom_ref + 7] / 20000 * octave, glide_rate); //5th
//    fifthfreq = chromatic[chrom_ref + 7] / 20000 * octave;
//
//
//  }
//  if ((chrom_ref == 7) || (chrom_ref == 19) || (chrom_ref == 31)) //D
//  {
//    glide1.amplitude(chromatic[chrom_ref ] / 20000 * octave, glide_rate); //root
//    fifthfreq = chromatic[chrom_ref ] / 20000 * octave;
//
//
//    glide2.amplitude(chromatic[chrom_ref +3] / 20000 * octave, glide_rate); //3rd
//    rootfreq = chromatic[chrom_ref +3] / 20000 * octave;
//
//
//    glide3.amplitude(chromatic[chrom_ref +7] / 20000 * octave, glide_rate); //5th
//    thirdfreq = chromatic[chrom_ref +7] / 20000 * octave;
//
//  }
//
//  if ((chrom_ref == 8) || (chrom_ref == 20) || (chrom_ref == 32)) //D
//  {
//    glide1.amplitude(chromatic[chrom_ref ] / 20000 * octave, glide_rate); //3rd
//    fifthfreq = chromatic[chrom_ref ] / 20000 * octave;
//
//
//    glide2.amplitude(chromatic[chrom_ref -3] / 20000 * octave, glide_rate); //Root
//    rootfreq = chromatic[chrom_ref -3] / 20000 * octave;
//
//
//    glide3.amplitude(chromatic[chrom_ref +4] / 20000 * octave, glide_rate); //3rd
//    thirdfreq = chromatic[chrom_ref +4] / 20000 * octave;
//
//  }
//
//
//  if ((chrom_ref == 10) || (chrom_ref == 22)) //F
//  {
//    glide1.amplitude(chromatic[chrom_ref] / 20000 * octave, glide_rate); //root
//    rootfreq = chromatic[chrom_ref] / 20000 * octave;
//
//
//    glide2.amplitude(chromatic[chrom_ref + 4] / 20000 * octave, glide_rate); //3rd
//    thirdfreq = chromatic[chrom_ref + 4] / 20000 * octave;
//
//
//    glide3.amplitude(chromatic[chrom_ref + 7] / 20000 * octave, glide_rate); //5th
//    fifthfreq = chromatic[chrom_ref + 7] / 20000 * octave;
//
//
//  }
//  if ((chrom_ref == 0) || (chrom_ref == 12) || (chrom_ref == 24)) //G
//  {
//    glide1.amplitude(chromatic[chrom_ref] / 20000 * octave, glide_rate); //5th
//    rootfreq = chromatic[chrom_ref] / 20000 * octave;
//
//
//    glide2.amplitude(chromatic[chrom_ref - 4] / 20000 * octave, glide_rate); //3rd
//    thirdfreq = chromatic[chrom_ref - 4] / 20000 * octave;
//
//
//    glide3.amplitude(chromatic[chrom_ref - 7] / 20000 * octave, glide_rate); //root
//    fifthfreq = chromatic[chrom_ref - 7] / 20000 * octave;
//
//  }
//}



//////////////////////////////////////////////////////////
// MAPFLOAT FUNCTION  map float values to ranges //todo not used
/////////////////////////////////////////////////////////


float mapfloat(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

float bound1(float val)
{
  if (val > 1) return 1;
  if (val < 0) return 0;
  return val;
}

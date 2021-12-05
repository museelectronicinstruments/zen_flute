//Interface for the Muse volume flute


import processing.serial.*;
import controlP5.*;
import java.util.*; //needed for dropdown list

ControlP5 cp5;

Serial myPort;  // Create object from Serial class

String command;     // Data received from the serial port
int num_ports;
String[] port_list;

String[] lines;

int datalength=0;

String presetdata = "";
int currentpreset=1;
boolean saveafile=false;
boolean saveaEPROM=false;
int saveSlot=0;

boolean doonce=false;

int espeedLSB=0;
int espeedMSB=0;

Textlabel myTextlabelA ; //text controls are quirky
//Textfield  myTextFieldA, myTextFieldb;
Textarea myTextarea;


//*******************************************************************************
//
void setup()//
  //
  //*******************************************************************************

{
  size(1200, 850);


  // change the default font to Verdana
  PFont p = createFont("Arial", 20);
  ControlFont font = new ControlFont(p);
  PFont q = createFont("Arial", 15);
  ControlFont fonts = new ControlFont(q);
  cp5 = new ControlP5(this);
  cp5.setFont(font);

  //*************************************
  //create tabs *************************
  //*************************************

  cp5.addTab("tab_port")
    .setHeight(50)
    .setWidth(150)
    .setColorBackground(color(0, 160, 100))
    .setColorLabel(color(255))
    .setColorActive(color(255, 128, 0))
    .setLabel("port")
    ;

  cp5.addTab("tab_ambiance")
    .setHeight(50)
    .setWidth(150)
    .setColorBackground(color(0, 160, 100))
    .setColorLabel(color(255))
    .setColorActive(color(255, 128, 0))
    .setLabel("ambiance")
    ;

  cp5.addTab("tab_synth")
    .setHeight(50)
    .setWidth(150)
    .setColorBackground(color(0, 160, 100))
    .setColorLabel(color(255))
    .setColorActive(color(255, 128, 0))
    .setLabel("synth")
    ;

  cp5.addTab("tab_drums")
    .setHeight(50)
    .setWidth(150)
    .setColorBackground(color(0, 160, 100))
    .setColorLabel(color(255))
    .setColorActive(color(255, 128, 0))
    .setLabel("drums")
    ;

  cp5.addTab("tab_backing")
    .setHeight(50)
    .setWidth(150)
    .setColorBackground(color(0, 160, 100))
    .setColorLabel(color(255))
    .setColorActive(color(255, 128, 0))
    .setLabel("backing")
    ;


  cp5.addTab("tab_save")
    .setHeight(50)
    .setWidth(150)
    .setColorBackground(color(0, 160, 100))
    .setColorLabel(color(255))
    .setColorActive(color(255, 128, 0))
    .setLabel("save/load")
    ;

  cp5.addTab("tab_advanced")
    .setHeight(50)
    .setWidth(150)
    .setColorBackground(color(0, 160, 100))
    .setColorLabel(color(255))
    .setColorActive(color(255, 128, 0))
    .setLabel("advanced")
    ;

  cp5.getTab("default").hide();
  cp5.getTab("tab_port").bringToFront();



  //*************************************
  //global controls *********************
  //*************************************


  cp5.addTextlabel("label")
    .setText("MUSE INSTRUMENTS")
    .setPosition(10, 820)
    .setColorValue(0xffFFFFFF)//leading ff on hex color
    .setFont(font)
    ;

  cp5.addTextfield("preset")
    .setPosition(1100, 20)
    .setSize(40, 40)
    .setFocus(true)
    .setColor(color(255, 0, 0))
    .clear()
    .setText("1");
  ;

  cp5.getController("label").moveTo("global");
  cp5.getController("preset").moveTo("global");


  //*************************************
  //port selection controls *************
  //*************************************

  // get the number of detected serial ports
  num_ports = Serial.list().length;
  // save the current list of serial ports
  port_list = new String[num_ports];
  for (int i = 0; i < num_ports; i++)
  {
    port_list[i] = Serial.list()[i];
  }


  cp5.addScrollableList("listA")
    .setPosition(50, 100)
    .setSize(200, 100)
    .setBarHeight(30)
    .setItemHeight(30)
    .setOpen(false)
    .setCaptionLabel("port number")
    .addItems(port_list)
    ;

  cp5.getController("listA").moveTo("tab_port");


  //*************************************
  //ambiance setup controls *************
  //*************************************

  cp5.addKnob("knobA")
    .setPosition(100, 150)
    .setRadius(70)
    .setRange(0, 1000)
    .setValue(50)
    .setCaptionLabel("glide rate ms");
  ;

  cp5.addKnob("knobB")
    .setPosition(300, 150)
    .setRadius(70)
    .setRange(0, 100)
    .setValue(50)
    .setCaptionLabel("reverb wet");
  ;

  cp5.addKnob("knobC")
    .setPosition(500, 150)
    .setRadius(70)
    .setRange(0, 100)
    .setValue(50)
    .setCaptionLabel("rain gain");
  ;

  cp5.addKnob("knobD")
    .setPosition(700, 150)
    .setRadius(70)
    .setRange(0, 100)
    .setValue(50)
    .setCaptionLabel("shimmer gain");
  ;

  List l = Arrays.asList("Cmaj/Amin", "Bmaj/G#min", "A#maj/Gmin", "Amaj/F#min", "G#maj/Fmin", "Gmaj/Emin",
    "F#maj/D#min", "Fmaj/Dmin", "Emaj/C#min", "D#maj/Cmin", "Dmaj/Bmin", "C#maj/Bbmin");

  cp5.addScrollableList("listB")
    .setPosition(900, 175)
    .setSize(150, 820)
    .setBarHeight(30)
    .setItemHeight(30)
    .addItems(l)
    .setOpen(false)
    .setCaptionLabel("scale type");
  ;

  cp5.addToggle("toggleA")
    .setPosition(140, 450)
    .setSize(50, 20)
    .setValue(true)
    .setCaptionLabel("chromatic");
  ;

  cp5.addToggle("toggleB")
    .setPosition(340, 450)
    .setSize(50, 20)
    .setValue(true)
    .setCaptionLabel("shimmer play/drone");
  ;

  
  cp5.addKnob("knobAO")
    .setPosition(100, 550)
    .setRadius(70)
    .setRange(0, 20000)
    .setValue(50)
    .setCaptionLabel("fade in ms");
  ;

  cp5.addKnob("knobAP")
    .setPosition(300, 550)
    .setRadius(70)
    .setRange(0, 20000)
    .setValue(50)
    .setCaptionLabel("fade out ms");
  ;

  cp5.addKnob("monvolume")
    .setPosition(500, 550)
    .setRadius(70)
    .setRange(0, 100)
    .setValue(50)
    .setCaptionLabel("monitor volume");
  ;

  //move controls to correct tab
  cp5.getController("knobA").moveTo("tab_ambiance");
  cp5.getController("knobB").moveTo("tab_ambiance");
  cp5.getController("knobC").moveTo("tab_ambiance");
  cp5.getController("knobD").moveTo("tab_ambiance");
  cp5.getController("listB").moveTo("tab_ambiance");
  cp5.getController("monvolume").moveTo("tab_ambiance");
  cp5.getController("toggleA").moveTo("tab_ambiance");
  cp5.getController("toggleB").moveTo("tab_ambiance");
  cp5.getController("knobAP").moveTo("tab_ambiance");
  cp5.getController("knobAO").moveTo("tab_ambiance");
  //myTextarea.moveTo("tab_ambiance");

  //*************************************
  //synth setup controls ****************
  //*************************************


  //melody controls **********************************************

  List n = Arrays.asList("-3", "-2", "-1", "0", "+1", "+2" );
  cp5.addScrollableList("listD")
    .setPosition(10, 100)
    .setSize(250, 320)
    .setBarHeight(30)
    .setItemHeight(20)
    .addItems(n)
    .setOpen(false)
    .setCaptionLabel("mel octave")
    .setFont(fonts);
  ;

  List o = Arrays.asList("sine", "triangle", "t-variable", "sawtooth", "square", "pulse");
  cp5.addScrollableList("listE")
    .setPosition(290, 100)
    .setSize(250, 320)
    .setBarHeight(30)
    .setItemHeight(20)
    .addItems(o)
    .setOpen(false)
    .setFont(fonts)
    .setCaptionLabel("mel shape");
  ;

  cp5.addKnob("knobE")
    .setPosition(1050, 85)
    .setRadius(50)
    .setRange(0, 10000)
    .setValue(50)
    .setCaptionLabel("cutoff Hz");
  ;

  cp5.addSlider("sliderA")
    .setPosition(575, 100)
    .setSize(200, 20)
    .setRange(0, 3000)
    .setValue(128)
    .setCaptionLabel("mel attack");
  ;
  cp5.addSlider("sliderB")
    .setPosition(575, 120)
    .setSize(200, 20)
    .setRange(0, 3000)
    .setValue(128)
    .setCaptionLabel("mel decay");
  ;
  cp5.addSlider("sliderC")
    .setPosition(575, 140)
    .setSize(200, 20)
    .setRange(0, 100)
    .setValue(128)
    .setCaptionLabel("mel sustain");
  ;
  cp5.addSlider("sliderD")
    .setPosition(575, 160)
    .setSize(200, 20)
    .setRange(0, 3000)
    .setValue(128)
    .setCaptionLabel("mel release");
  ;

  cp5.addKnob("knobF")
    .setPosition(920, 85)
    .setRadius(50)
    .setRange(0, 100)
    .setValue(50)
    .setCaptionLabel("mel vol.");

  cp5.getController("listD").moveTo("tab_synth");
  cp5.getController("listE").moveTo("tab_synth");
  cp5.getController("knobE").moveTo("tab_synth");
  cp5.getController("sliderA").moveTo("tab_synth");
  cp5.getController("sliderB").moveTo("tab_synth");
  cp5.getController("sliderC").moveTo("tab_synth");
  cp5.getController("sliderD").moveTo("tab_synth");
  cp5.getController("knobF").moveTo("tab_synth");
  ;

  //harmony 1************************************************
  cp5.addScrollableList("listF")
    .setPosition(10, 250)
    .setSize(250, 320)
    .setBarHeight(30)
    .setItemHeight(20)
    .addItems(n)
    .setOpen(false)
    .setFont(fonts)
    .setCaptionLabel("harm1 octave");
  ;


  cp5.addScrollableList("listG")
    .setPosition(290, 250)
    .setSize(250, 320)
    .setBarHeight(30)
    .setItemHeight(20)
    .addItems(o)
    .setOpen(false)
    .setFont(fonts)
    .setCaptionLabel("harm1 shape");
  ;


  cp5.addKnob("knobG")
    .setPosition(1050, 235)
    .setRadius(50)
    .setRange(0, 10000)
    .setValue(50)
    .setCaptionLabel("cutoff Hz");
  ;

  cp5.addSlider("sliderE")
    .setPosition(575, 250)
    .setSize(200, 20)
    .setRange(0, 3000)
    .setValue(128)
    .setCaptionLabel("h1 attack");
  ;
  cp5.addSlider("sliderF")
    .setPosition(575, 270)
    .setSize(200, 20)
    .setRange(0, 3000)
    .setValue(128)
    .setCaptionLabel("h1 decay");
  ;
  cp5.addSlider("sliderG")
    .setPosition(575, 290)
    .setSize(200, 20)
    .setRange(0, 100)
    .setValue(128)
    .setCaptionLabel("h1 sustain");
  ;
  cp5.addSlider("sliderH")
    .setPosition(575, 310)
    .setSize(200, 20)
    .setRange(0, 3000)
    .setValue(128)
    .setCaptionLabel("h1 release");
  ;

  cp5.addKnob("knobH")
    .setPosition(920, 235)
    .setRadius(50)
    .setRange(0, 100)
    .setValue(50)
    .setCaptionLabel("h1 vol.");

  cp5.getController("listF").moveTo("tab_synth");
  cp5.getController("listG").moveTo("tab_synth");
  cp5.getController("knobG").moveTo("tab_synth");
  cp5.getController("sliderE").moveTo("tab_synth");
  cp5.getController("sliderF").moveTo("tab_synth");
  cp5.getController("sliderG").moveTo("tab_synth");
  cp5.getController("sliderH").moveTo("tab_synth");
  cp5.getController("knobH").moveTo("tab_synth");
  ;

  //harmony 2 *********************************************************************


  cp5.addScrollableList("listH")
    .setPosition(10, 400)
    .setSize(250, 320)
    .setBarHeight(30)
    .setItemHeight(20)
    .setFont(fonts)
    .addItems(n)
    .setOpen(false)
    .setCaptionLabel("harm2 octave");
  ;


  cp5.addScrollableList("listI")
    .setPosition(290, 400)
    .setSize(250, 320)
    .setBarHeight(30)
    .setItemHeight(20)
    .addItems(o)
    .setOpen(false)
    .setFont(fonts)
    .setCaptionLabel("harm2 shape");
  ;


  cp5.addKnob("knobI")
    .setPosition(1050, 385)
    .setRadius(50)
    .setRange(0, 10000)
    .setValue(50)
    .setCaptionLabel("cutoff Hz");
  ;

  cp5.addSlider("sliderI")
    .setPosition(575, 400)
    .setSize(200, 20)
    .setRange(0, 3000)
    .setValue(128)
    .setCaptionLabel("h2 attack");
  ;
  cp5.addSlider("sliderJ")
    .setPosition(575, 420)
    .setSize(200, 20)
    .setRange(0, 3000)
    .setValue(128)
    .setCaptionLabel("h2 decay");
  ;
  cp5.addSlider("sliderK")
    .setPosition(575, 440)
    .setSize(200, 20)
    .setRange(0, 100)
    .setValue(128)
    .setCaptionLabel("h2 sustain");
  ;
  cp5.addSlider("sliderL")
    .setPosition(575, 460)
    .setSize(200, 20)
    .setRange(0, 3000)
    .setValue(128)
    .setCaptionLabel("h2 release");
  ;

  cp5.addKnob("knobJ")
    .setPosition(920, 385)
    .setRadius(50)
    .setRange(0, 100)
    .setValue(50)
    .setCaptionLabel("h2 vol.");


  cp5.getController("listH").moveTo("tab_synth");
  cp5.getController("listI").moveTo("tab_synth");
  cp5.getController("knobI").moveTo("tab_synth");
  cp5.getController("sliderI").moveTo("tab_synth");
  cp5.getController("sliderJ").moveTo("tab_synth");
  cp5.getController("sliderK").moveTo("tab_synth");
  cp5.getController("sliderL").moveTo("tab_synth");
  cp5.getController("knobJ").moveTo("tab_synth");

  //string controls****************************************

  cp5.addKnob("knobK")
    .setPosition(50, 550)
    .setRadius(50)
    .setRange(0, 100)
    .setValue(50)
    .setCaptionLabel("mel stringvol.");

  cp5.addScrollableList("listJ")
    .setPosition(200, 550)
    .setSize(250, 320)
    .setBarHeight(30)
    .setItemHeight(30)
    .addItems(n)
    .setOpen(false)
    .setCaptionLabel("mel string octave");
  ;


  cp5.addKnob("knobL")
    .setPosition(500, 550)
    .setRadius(50)
    .setRange(0, 100)
    .setValue(50)
    .setCaptionLabel("harm.string vol.");

  cp5.addScrollableList("listK")
    .setPosition(650, 550)
    .setSize(250, 320)
    .setBarHeight(30)
    .setItemHeight(30)
    .addItems(n)
    .setOpen(false)
    .setCaptionLabel("harm string octave");
  ;
  cp5.addToggle("toggleF")
    .setPosition(50, 750)
    .setSize(50, 20)
    .setValue(true)
    .setCaptionLabel("note stick override");

  cp5.getController("toggleF").moveTo("tab_synth");
  cp5.getController("listJ").moveTo("tab_synth");
  cp5.getController("listK").moveTo("tab_synth");
  cp5.getController("knobK").moveTo("tab_synth");
  cp5.getController("knobL").moveTo("tab_synth");

  //*************************************
  //drums setup controls ****************
  //*************************************

  cp5.addTextfield("beat")
    .setPosition(100, 500)
    .setSize(40, 40)
    .setFocus(true)
    .setColor(color(255, 0, 0))
    .clear()
    .setCaptionLabel("count")
    .setText("1");
  ;

  cp5.getController("beat").moveTo("tab_drums");


  cp5.addKnob("knobM")
    .setPosition(150, 70)
    .setRadius(50)
    .setRange(0, 1000)
    .setValue(50)
    .setCaptionLabel("drum speed");
  ;
  //drum sounds

  cp5.addKnob("knobN")
    .setPosition(300, 70)
    .setRadius(25)
    .setRange(0, 2000)
    .setValue(25)
    .setCaptionLabel("d1 freq");
  ;

  cp5.addKnob("knobO")
    .setPosition(450, 70)
    .setRadius(25)
    .setRange(20, 1000)
    .setValue(50)
    .setCaptionLabel("d1 length");
  ;

  cp5.addKnob("knobP")
    .setPosition(600, 70)
    .setRadius(25)
    .setRange(0, 100)
    .setValue(50)
    .setCaptionLabel("d1 mix");
  ;

  cp5.addKnob("knobQ")
    .setPosition(750, 70)
    .setRadius(25)
    .setRange(0, 100)
    .setValue(50)
    .setCaptionLabel("d1 mod");
  ;

  cp5.addKnob("knobR")
    .setPosition(900, 70)
    .setRadius(25)
    .setRange(0, 100)
    .setValue(50)
    .setCaptionLabel("d1 vol");

  cp5.addKnob("knobAK")
    .setPosition(1050, 70)
    .setRadius(25)
    .setRange(0, 105)
    .setValue(50)
    .setCaptionLabel("d1 MIDI");
  ;


  cp5.addKnob("knobS")
    .setPosition(300, 170)
    .setRadius(25)
    .setRange(0, 2000)
    .setValue(25)
    .setCaptionLabel("d2 freq");
  ;

  cp5.addKnob("knobT")
    .setPosition(450, 170)
    .setRadius(25)
    .setRange(20, 1000)
    .setValue(50)
    .setCaptionLabel("d2 length");
  ;

  cp5.addKnob("knobU")
    .setPosition(600, 170)
    .setRadius(25)
    .setRange(0, 100)
    .setValue(50)
    .setCaptionLabel("d2 mix");
  ;

  cp5.addKnob("knobV")
    .setPosition(750, 170)
    .setRadius(25)
    .setRange(0, 100)
    .setValue(50)
    .setCaptionLabel("d2 mod");
  ;

  cp5.addKnob("knobW")
    .setPosition(900, 170)
    .setRadius(25)
    .setRange(0, 100)
    .setValue(50)
    .setCaptionLabel("d2 vol");
  ;

  cp5.addKnob("knobAL")
    .setPosition(1050, 170)
    .setRadius(25)
    .setRange(0, 105)
    .setValue(50)
    .setCaptionLabel("d2 MIDI");
  ;

  cp5.addKnob("knobX")
    .setPosition(300, 270)
    .setRadius(25)
    .setRange(0, 2000)
    .setValue(25)
    .setCaptionLabel("d3 freq");
  ;

  cp5.addKnob("knobY")
    .setPosition(450, 270)
    .setRadius(25)
    .setRange(20, 1000)
    .setValue(50)
    .setCaptionLabel("d3 length");
  ;

  cp5.addKnob("knobZ")
    .setPosition(600, 270)
    .setRadius(25)
    .setRange(0, 100)
    .setValue(50)
    .setCaptionLabel("d3 mix");
  ;

  cp5.addKnob("knobAA")
    .setPosition(750, 270)
    .setRadius(25)
    .setRange(0, 100)
    .setValue(50)
    .setCaptionLabel("d3 mod");
  ;

  cp5.addKnob("knobAB")
    .setPosition(900, 270)
    .setRadius(25)
    .setRange(0, 100)
    .setValue(50)
    .setCaptionLabel("d3 vol");
  ;

  cp5.addKnob("knobAM")
    .setPosition(1050, 270)
    .setRadius(25)
    .setRange(0, 105)
    .setValue(50)
    .setCaptionLabel("d3 MIDI");
  ;


  cp5.addKnob("knobAC")
    .setPosition(300, 370)
    .setRadius(25)
    .setRange(0, 2000)
    .setValue(25)
    .setCaptionLabel("d4 freq");
  ;

  cp5.addKnob("knobAD")
    .setPosition(450, 370)
    .setRadius(25)
    .setRange(20, 1000)
    .setValue(50)
    .setCaptionLabel("d4 length");
  ;

  cp5.addKnob("knobAE")
    .setPosition(600, 370)
    .setRadius(25)
    .setRange(0, 100)
    .setValue(50)
    .setCaptionLabel("d4 mix");
  ;

  cp5.addKnob("knobAF")
    .setPosition(750, 370)
    .setRadius(25)
    .setRange(0, 100)
    .setValue(50)
    .setCaptionLabel("d4 mod");
  ;

  cp5.addKnob("knobAG")
    .setPosition(900, 370)
    .setRadius(25)
    .setRange(0, 100)
    .setValue(50)
    .setCaptionLabel("d4 vol");
  ;

  cp5.addKnob("knobAN")
    .setPosition(1050, 370)
    .setRadius(25)
    .setRange(0, 105)
    .setValue(50)
    .setCaptionLabel("d4 MIDI");
  ;



  //cp5.getController("toggleC").moveTo("tab_drums");
  cp5.getController("knobM").moveTo("tab_drums");
  cp5.getController("knobN").moveTo("tab_drums");
  cp5.getController("knobO").moveTo("tab_drums");
  cp5.getController("knobP").moveTo("tab_drums");
  cp5.getController("knobQ").moveTo("tab_drums");
  cp5.getController("knobR").moveTo("tab_drums");
  cp5.getController("knobS").moveTo("tab_drums");
  cp5.getController("knobT").moveTo("tab_drums");
  cp5.getController("knobU").moveTo("tab_drums");
  cp5.getController("knobV").moveTo("tab_drums");
  cp5.getController("knobW").moveTo("tab_drums");
  cp5.getController("knobX").moveTo("tab_drums");
  cp5.getController("knobY").moveTo("tab_drums");
  cp5.getController("knobZ").moveTo("tab_drums");
  cp5.getController("knobAA").moveTo("tab_drums");
  cp5.getController("knobAB").moveTo("tab_drums");
  cp5.getController("knobAC").moveTo("tab_drums");
  cp5.getController("knobAD").moveTo("tab_drums");
  cp5.getController("knobAE").moveTo("tab_drums");
  cp5.getController("knobAF").moveTo("tab_drums");
  cp5.getController("knobAG").moveTo("tab_drums");
  cp5.getController("knobAK").moveTo("tab_drums");
  cp5.getController("knobAL").moveTo("tab_drums");
  cp5.getController("knobAM").moveTo("tab_drums");
  cp5.getController("knobAN").moveTo("tab_drums");


  //beat map
  //beat1 *********************************************************************
  cp5.addToggle("toggleD")
    .setPosition(230, 625)
    .setSize(50, 20)
    .setValue(true)
    .setCaptionLabel("euclid generate");
  ;

  cp5.addKnob("knobAH")
    .setPosition(50, 610)
    .setRadius(25)
    .setRange(0, 16)
    .setValue(50)
    .setCaptionLabel("beats");
  ;

  cp5.addKnob("knobAI")
    .setPosition(150, 610)
    .setRadius(25)
    .setRange(0, 16)
    .setValue(50)
    .setCaptionLabel("offset");
  ;

  cp5.addKnob("knobAJ")
    .setPosition(200, 495)
    .setRadius(25)
    .setRange(0, 16)
    .setValue(50)
    .setCaptionLabel("bins");
  ;

  myTextlabelA = cp5.addTextlabel("label2")
    .setText("D1")
    .setPosition(440, 500)
    .setColorValue(0xffFFFFFF)//leading ff on hex color
    .setFont(font)
    ;

  cp5.addToggle("togL")
    .setPosition(480, 500)
    .setSize(20, 20)
    .setCaptionLabel("1")
    ;

  cp5.addToggle("togM")
    .setPosition(520, 500)
    .setSize(20, 20)
    .setCaptionLabel("2");
  ;

  cp5.addToggle("togN")
    .setPosition(560, 500)
    .setSize(20, 20)
    .setCaptionLabel("3");
  ;

  cp5.addToggle("togO")
    .setPosition(600, 500)
    .setSize(20, 20)
    .setCaptionLabel("4");
  ;

  cp5.addToggle("togP")
    .setPosition(640, 500)
    .setSize(20, 20)
    .setCaptionLabel("5");
  ;

  cp5.addToggle("togQ")
    .setPosition(680, 500)
    .setSize(20, 20)
    .setCaptionLabel("6");
  ;

  cp5.addToggle("togR")
    .setPosition(720, 500)
    .setSize(20, 20)
    .setCaptionLabel("7");
  ;

  cp5.addToggle("togS")
    .setPosition(760, 500)
    .setSize(20, 20)
    .setCaptionLabel("8");
  ;

  cp5.addToggle("togT")
    .setPosition(800, 500)
    .setSize(20, 20)
    .setCaptionLabel("9");
  ;

  cp5.addToggle("togU")
    .setPosition(840, 500)
    .setSize(20, 20)
    .setCaptionLabel("10");
  ;

  cp5.addToggle("togV")
    .setPosition(880, 500)
    .setSize(20, 20)
    .setCaptionLabel("11");
  ;

  cp5.addToggle("togW")
    .setPosition(920, 500)
    .setSize(20, 20)
    .setCaptionLabel("12");
  ;

  cp5.addToggle("togX")
    .setPosition(960, 500)
    .setSize(20, 20)
    .setCaptionLabel("13");
  ;

  cp5.addToggle("togY")
    .setPosition(1000, 500)
    .setSize(20, 20)
    .setCaptionLabel("14");
  ;

  cp5.addToggle("togZ")
    .setPosition(1040, 500)
    .setSize(20, 20)
    .setCaptionLabel("15");

  cp5.addToggle("togAA")
    .setPosition(1080, 500)
    .setSize(20, 20)
    .setCaptionLabel("16");
  ;

  cp5.getController("label2").moveTo("tab_drums");
  cp5.getController("toggleD").moveTo("tab_drums");
  cp5.getController("knobAH").moveTo("tab_drums");
  cp5.getController("knobAI").moveTo("tab_drums");
  cp5.getController("knobAJ").moveTo("tab_drums");
  cp5.getController("togL").moveTo("tab_drums");
  cp5.getController("togM").moveTo("tab_drums");
  cp5.getController("togN").moveTo("tab_drums");
  cp5.getController("togO").moveTo("tab_drums");
  cp5.getController("togP").moveTo("tab_drums");
  cp5.getController("togQ").moveTo("tab_drums");
  cp5.getController("togR").moveTo("tab_drums");
  cp5.getController("togS").moveTo("tab_drums");
  cp5.getController("togT").moveTo("tab_drums");
  cp5.getController("togU").moveTo("tab_drums");
  cp5.getController("togV").moveTo("tab_drums");
  cp5.getController("togW").moveTo("tab_drums");
  cp5.getController("togX").moveTo("tab_drums");
  cp5.getController("togY").moveTo("tab_drums");
  cp5.getController("togZ").moveTo("tab_drums");
  cp5.getController("togAA").moveTo("tab_drums");

  myTextlabelA = cp5.addTextlabel("label3")
    .setText("D2")
    .setPosition(440, 550)
    .setColorValue(0xffFFFFFF)//leading ff on hex color
    .setFont(font)
    ;

  cp5.addToggle("togAB")
    .setPosition(480, 550)
    .setSize(20, 20)
    .setCaptionLabel("1");
  ;

  cp5.addToggle("togAC")
    .setPosition(520, 550)
    .setSize(20, 20)
    .setCaptionLabel("2");
  ;

  cp5.addToggle("togAD")
    .setPosition(560, 550)
    .setSize(20, 20)
    .setCaptionLabel("3");
  ;

  cp5.addToggle("togAE")
    .setPosition(600, 550)
    .setSize(20, 20)
    .setCaptionLabel("4");
  ;

  cp5.addToggle("togAF")
    .setPosition(640, 550)
    .setSize(20, 20)
    .setCaptionLabel("5");
  ;

  cp5.addToggle("togAG")
    .setPosition(680, 550)
    .setSize(20, 20)
    .setCaptionLabel("6");
  ;

  cp5.addToggle("togAH")
    .setPosition(720, 550)
    .setSize(20, 20)
    .setCaptionLabel("7");
  ;

  cp5.addToggle("togAI")
    .setPosition(760, 550)
    .setSize(20, 20)
    .setCaptionLabel("8");
  ;

  cp5.addToggle("togAJ")
    .setPosition(800, 550)
    .setSize(20, 20)
    .setCaptionLabel("9");
  ;

  cp5.addToggle("togAK")
    .setPosition(840, 550)
    .setSize(20, 20)
    .setCaptionLabel("10");
  ;

  cp5.addToggle("togAL")
    .setPosition(880, 550)
    .setSize(20, 20)
    .setCaptionLabel("11");
  ;

  cp5.addToggle("togAM")
    .setPosition(920, 550)
    .setSize(20, 20)
    .setCaptionLabel("12");
  ;

  cp5.addToggle("togAN")
    .setPosition(960, 550)
    .setSize(20, 20)
    .setCaptionLabel("13");
  ;

  cp5.addToggle("togAO")
    .setPosition(1000, 550)
    .setSize(20, 20)
    .setCaptionLabel("14");
  ;

  cp5.addToggle("togAP")
    .setPosition(1040, 550)
    .setSize(20, 20)
    .setCaptionLabel("15");

  cp5.addToggle("togAQ")
    .setPosition(1080, 550)
    .setSize(20, 20)
    .setCaptionLabel("16");
  ;

  cp5.getController("label3").moveTo("tab_drums");
  cp5.getController("togAB").moveTo("tab_drums");
  cp5.getController("togAC").moveTo("tab_drums");
  cp5.getController("togAD").moveTo("tab_drums");
  cp5.getController("togAE").moveTo("tab_drums");
  cp5.getController("togAF").moveTo("tab_drums");
  cp5.getController("togAG").moveTo("tab_drums");
  cp5.getController("togAH").moveTo("tab_drums");
  cp5.getController("togAI").moveTo("tab_drums");
  cp5.getController("togAJ").moveTo("tab_drums");
  cp5.getController("togAK").moveTo("tab_drums");
  cp5.getController("togAL").moveTo("tab_drums");
  cp5.getController("togAM").moveTo("tab_drums");
  cp5.getController("togAN").moveTo("tab_drums");
  cp5.getController("togAO").moveTo("tab_drums");
  cp5.getController("togAP").moveTo("tab_drums");
  cp5.getController("togAQ").moveTo("tab_drums");

  //beat3 *********************************************************************

  myTextlabelA = cp5.addTextlabel("label4")
    .setText("D3")
    .setPosition(440, 600)
    .setColorValue(0xffFFFFFF)//leading ff on hex color
    .setFont(font)
    ;

  cp5.addToggle("togAR")
    .setPosition(480, 600)
    .setSize(20, 20)
    .setCaptionLabel("1");
  ;

  cp5.addToggle("togAS")
    .setPosition(520, 600)
    .setSize(20, 20)
    .setCaptionLabel("2");
  ;

  cp5.addToggle("togAT")
    .setPosition(560, 600)
    .setSize(20, 20)
    .setCaptionLabel("3");
  ;

  cp5.addToggle("togAU")
    .setPosition(600, 600)
    .setSize(20, 20)
    .setCaptionLabel("4");
  ;

  cp5.addToggle("togAV")
    .setPosition(640, 600)
    .setSize(20, 20)
    .setCaptionLabel("5");
  ;

  cp5.addToggle("togAW")
    .setPosition(680, 600)
    .setSize(20, 20)
    .setCaptionLabel("6");
  ;

  cp5.addToggle("togAX")
    .setPosition(720, 600)
    .setSize(20, 20)
    .setCaptionLabel("7");
  ;

  cp5.addToggle("togAY")
    .setPosition(760, 600)
    .setSize(20, 20)
    .setCaptionLabel("8");
  ;

  cp5.addToggle("togAZ")
    .setPosition(800, 600)
    .setSize(20, 20)
    .setCaptionLabel("9");
  ;

  cp5.addToggle("togBA")
    .setPosition(840, 600)
    .setSize(20, 20)
    .setCaptionLabel("10");
  ;

  cp5.addToggle("togBB")
    .setPosition(880, 600)
    .setSize(20, 20)
    .setCaptionLabel("11");
  ;

  cp5.addToggle("togBC")
    .setPosition(920, 600)
    .setSize(20, 20)
    .setCaptionLabel("12");
  ;

  cp5.addToggle("togBD")
    .setPosition(960, 600)
    .setSize(20, 20)
    .setCaptionLabel("13");
  ;

  cp5.addToggle("togBE")
    .setPosition(1000, 600)
    .setSize(20, 20)
    .setCaptionLabel("14");
  ;

  cp5.addToggle("togBF")
    .setPosition(1040, 600)
    .setSize(20, 20)
    .setCaptionLabel("15");

  cp5.addToggle("togBG")
    .setPosition(1080, 600)
    .setSize(20, 20)
    .setCaptionLabel("16");
  ;


  cp5.getController("label4").moveTo("tab_drums");
  cp5.getController("togAR").moveTo("tab_drums");
  cp5.getController("togAS").moveTo("tab_drums");
  cp5.getController("togAT").moveTo("tab_drums");
  cp5.getController("togAU").moveTo("tab_drums");
  cp5.getController("togAV").moveTo("tab_drums");
  cp5.getController("togAW").moveTo("tab_drums");
  cp5.getController("togAX").moveTo("tab_drums");
  cp5.getController("togAY").moveTo("tab_drums");
  cp5.getController("togAZ").moveTo("tab_drums");
  cp5.getController("togBA").moveTo("tab_drums");
  cp5.getController("togBB").moveTo("tab_drums");
  cp5.getController("togBC").moveTo("tab_drums");
  cp5.getController("togBD").moveTo("tab_drums");
  cp5.getController("togBE").moveTo("tab_drums");
  cp5.getController("togBF").moveTo("tab_drums");
  cp5.getController("togBG").moveTo("tab_drums");

  //drum4 *********************************************************************

  myTextlabelA = cp5.addTextlabel("label5")
    .setText("D4")
    .setPosition(440, 650)
    .setColorValue(0xffFFFFFF)//leading ff on hex color
    .setFont(font)
    ;

  cp5.addToggle("togBH")
    .setPosition(480, 650)
    .setSize(20, 20)
    .setCaptionLabel("1");
  ;

  cp5.addToggle("togBI")
    .setPosition(520, 650)
    .setSize(20, 20)
    .setCaptionLabel("2");
  ;

  cp5.addToggle("togBJ")
    .setPosition(560, 650)
    .setSize(20, 20)
    .setCaptionLabel("3");
  ;

  cp5.addToggle("togBK")
    .setPosition(600, 650)
    .setSize(20, 20)
    .setCaptionLabel("4");
  ;

  cp5.addToggle("togBL")
    .setPosition(640, 650)
    .setSize(20, 20)
    .setCaptionLabel("5");
  ;

  cp5.addToggle("togBM")
    .setPosition(680, 650)
    .setSize(20, 20)
    .setCaptionLabel("6");
  ;

  cp5.addToggle("togBN")
    .setPosition(720, 650)
    .setSize(20, 20)
    .setCaptionLabel("7");
  ;

  cp5.addToggle("togBO")
    .setPosition(760, 650)
    .setSize(20, 20)
    .setCaptionLabel("8");
  ;

  cp5.addToggle("togBP")
    .setPosition(800, 650)
    .setSize(20, 20)
    .setCaptionLabel("9");
  ;

  cp5.addToggle("togBQ")
    .setPosition(840, 650)
    .setSize(20, 20)
    .setCaptionLabel("10");
  ;

  cp5.addToggle("togBR")
    .setPosition(880, 650)
    .setSize(20, 20)
    .setCaptionLabel("11");
  ;

  cp5.addToggle("togBS")
    .setPosition(920, 650)
    .setSize(20, 20)
    .setCaptionLabel("12");
  ;

  cp5.addToggle("togBT")
    .setPosition(960, 650)
    .setSize(20, 20)
    .setCaptionLabel("13");
  ;

  cp5.addToggle("togBU")
    .setPosition(1000, 650)
    .setSize(20, 20)
    .setCaptionLabel("14");
  ;

  cp5.addToggle("togBV")
    .setPosition(1040, 650)
    .setSize(20, 20)
    .setCaptionLabel("15");

  cp5.addToggle("togBW")
    .setPosition(1080, 650)
    .setSize(20, 20)
    .setCaptionLabel("16");
  ;

  cp5.addToggle("toggleG")
    .setPosition(50, 750)
    .setSize(50, 20)
    .setValue(true)
    .setCaptionLabel("drums on");



  cp5.getController("label5").moveTo("tab_drums");
  cp5.getController("togBH").moveTo("tab_drums");
  cp5.getController("togBI").moveTo("tab_drums");
  cp5.getController("togBJ").moveTo("tab_drums");
  cp5.getController("togBK").moveTo("tab_drums");
  cp5.getController("togBL").moveTo("tab_drums");
  cp5.getController("togBM").moveTo("tab_drums");
  cp5.getController("togBN").moveTo("tab_drums");
  cp5.getController("togBO").moveTo("tab_drums");
  cp5.getController("togBP").moveTo("tab_drums");
  cp5.getController("togBQ").moveTo("tab_drums");
  cp5.getController("togBR").moveTo("tab_drums");
  cp5.getController("togBS").moveTo("tab_drums");
  cp5.getController("togBT").moveTo("tab_drums");
  cp5.getController("togBU").moveTo("tab_drums");
  cp5.getController("togBV").moveTo("tab_drums");
  cp5.getController("togBW").moveTo("tab_drums");
  cp5.getController("toggleG").moveTo("tab_drums");

  //*************************************
  // CHORD controls **********************
  //*************************************


  List x = Arrays.asList("shimmer chords", "string chords", "3rd/5th", "ostinato-str", "ostinator-syn", "ost. str/syn",
    "synth chords", "glissando", "auto" );

  cp5.addScrollableList("listL")
    .setPosition(700, 700)//@@
    .setSize(200, 500)
    .setBarHeight(30)
    .setItemHeight(30)
    .addItems(x)
    .setOpen(false)
    .setCaptionLabel("button logic");
  ;


  //CHORD 1
  List f = Arrays.asList("-", "A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#",
    "A'", "A'#", "B'", "C'", "C'#", "D'", "D'#", "E'", "F'", "F'#", "G'", "G#'");
  cp5.addScrollableList("listNA1")
    .setPosition(50, 100)
    .setSize(30, 300)
    .setBarHeight(30)
    .setItemHeight(20)
    .addItems(f)
    .setOpen(false)
    .setCaptionLabel("1")
    .setFont(fonts);
  ;

  cp5.addScrollableList("listNA2")
    .setPosition(80, 100)
    .setSize(30, 300)
    .setBarHeight(30)
    .setItemHeight(20)
    .addItems(f)
    .setOpen(false)
    .setCaptionLabel("2")
    .setFont(fonts);
  ;

  cp5.addScrollableList("listNA3")
    .setPosition(110, 100)
    .setSize(30, 300)
    .setBarHeight(30)
    .setItemHeight(20)
    .addItems(f)
    .setOpen(false)
    .setCaptionLabel("3")
    .setFont(fonts);
  ;

  cp5.addScrollableList("listNA4")
    .setPosition(140, 100)
    .setSize(30, 300)
    .setBarHeight(30)
    .setItemHeight(20)
    .addItems(f)
    .setOpen(false)
    .setCaptionLabel("4")
    .setFont(fonts);
  ;

  cp5.addScrollableList("listNA5")
    .setPosition(170, 100)
    .setSize(30, 300)
    .setBarHeight(30)
    .setItemHeight(20)
    .addItems(f)
    .setOpen(false)
    .setCaptionLabel("5")
    .setFont(fonts);
  ;

  cp5.addScrollableList("listNA6")
    .setPosition(200, 100)
    .setSize(30, 300)
    .setBarHeight(30)
    .setItemHeight(20)
    .addItems(f)
    .setOpen(false)
    .setCaptionLabel("6")
    .setFont(fonts);
  ;

  cp5.addScrollableList("listNA7")
    .setPosition(230, 100)
    .setSize(30, 300)
    .setBarHeight(30)
    .setItemHeight(20)
    .addItems(f)
    .setOpen(false)
    .setCaptionLabel("7")
    .setFont(fonts);
  ;

  cp5.addScrollableList("listNA8")
    .setPosition(260, 100)
    .setSize(30, 300)
    .setBarHeight(30)
    .setItemHeight(20)
    .addItems(f)
    .setOpen(false)
    .setCaptionLabel("8")
    .setFont(fonts);
  ;

  cp5.addScrollableList("listNA9")
    .setPosition(290, 100)
    .setSize(30, 300)
    .setBarHeight(30)
    .setItemHeight(20)
    .addItems(f)
    .setOpen(false)
    .setCaptionLabel("9")
    .setFont(fonts);
  ;

  cp5.addScrollableList("listNA10")
    .setPosition(320, 100)
    .setSize(30, 300)
    .setBarHeight(30)
    .setItemHeight(20)
    .addItems(f)
    .setOpen(false)
    .setCaptionLabel("10")
    .setFont(fonts);
  ;

  cp5.addScrollableList("listNA11")
    .setPosition(350, 100)
    .setSize(30, 300)
    .setBarHeight(30)
    .setItemHeight(20)
    .addItems(f)
    .setOpen(false)
    .setCaptionLabel("11")
    .setFont(fonts);
  ;

  cp5.addScrollableList("listNA12")
    .setPosition(380, 100)
    .setSize(30, 300)
    .setBarHeight(30)
    .setItemHeight(20)
    .addItems(f)
    .setOpen(false)
    .setCaptionLabel("12")
    .setFont(fonts);
  ;

  cp5.addScrollableList("listNA13")
    .setPosition(410, 100)
    .setSize(30, 300)
    .setBarHeight(30)
    .setItemHeight(20)
    .addItems(f)
    .setOpen(false)
    .setCaptionLabel("13")
    .setFont(fonts);
  ;

  cp5.addScrollableList("listNA14")
    .setPosition(440, 100)
    .setSize(30, 300)
    .setBarHeight(30)
    .setItemHeight(20)
    .addItems(f)
    .setOpen(false)
    .setCaptionLabel("14")
    .setFont(fonts);
  ;

  cp5.addScrollableList("listNA15")
    .setPosition(470, 100)
    .setSize(30, 300)
    .setBarHeight(30)
    .setItemHeight(20)
    .addItems(f)
    .setOpen(false)
    .setCaptionLabel("15")
    .setFont(fonts);
  ;

  cp5.addScrollableList("listNA16")
    .setPosition(500, 100)
    .setSize(30, 300)
    .setBarHeight(30)
    .setItemHeight(20)
    .addItems(f)
    .setOpen(false)
    .setCaptionLabel("16")
    .setFont(fonts);
  ;

  //CHORD 2
  cp5.addScrollableList("listNB1")
    .setPosition(600, 100)
    .setSize(30, 300)
    .setBarHeight(30)
    .setItemHeight(20)
    .addItems(f)
    .setOpen(false)
    .setCaptionLabel("1")
    .setFont(fonts);
  ;

  cp5.addScrollableList("listNB2")
    .setPosition(630, 100)
    .setSize(30, 300)
    .setBarHeight(30)
    .setItemHeight(20)
    .addItems(f)
    .setOpen(false)
    .setCaptionLabel("2")
    .setFont(fonts);
  ;

  cp5.addScrollableList("listNB3")
    .setPosition(660, 100)
    .setSize(30, 300)
    .setBarHeight(30)
    .setItemHeight(20)
    .addItems(f)
    .setOpen(false)
    .setCaptionLabel("3")
    .setFont(fonts);
  ;

  cp5.addScrollableList("listNB4")
    .setPosition(690, 100)
    .setSize(30, 300)
    .setBarHeight(30)
    .setItemHeight(20)
    .addItems(f)
    .setOpen(false)
    .setCaptionLabel("4")
    .setFont(fonts);
  ;

  cp5.addScrollableList("listNB5")
    .setPosition(720, 100)
    .setSize(30, 300)
    .setBarHeight(30)
    .setItemHeight(20)
    .addItems(f)
    .setOpen(false)
    .setCaptionLabel("5")
    .setFont(fonts);
  ;

  cp5.addScrollableList("listNB6")
    .setPosition(750, 100)
    .setSize(30, 300)
    .setBarHeight(30)
    .setItemHeight(20)
    .addItems(f)
    .setOpen(false)
    .setCaptionLabel("6")
    .setFont(fonts);
  ;

  cp5.addScrollableList("listNB7")
    .setPosition(780, 100)
    .setSize(30, 300)
    .setBarHeight(30)
    .setItemHeight(20)
    .addItems(f)
    .setOpen(false)
    .setCaptionLabel("7")
    .setFont(fonts);
  ;

  cp5.addScrollableList("listNB8")
    .setPosition(810, 100)
    .setSize(30, 300)
    .setBarHeight(30)
    .setItemHeight(20)
    .addItems(f)
    .setOpen(false)
    .setCaptionLabel("8")
    .setFont(fonts);
  ;

  cp5.addScrollableList("listNB9")
    .setPosition(840, 100)
    .setSize(30, 300)
    .setBarHeight(30)
    .setItemHeight(20)
    .addItems(f)
    .setOpen(false)
    .setCaptionLabel("9")
    .setFont(fonts);
  ;

  cp5.addScrollableList("listNB10")
    .setPosition(870, 100)
    .setSize(30, 300)
    .setBarHeight(30)
    .setItemHeight(20)
    .addItems(f)
    .setOpen(false)
    .setCaptionLabel("10")
    .setFont(fonts);
  ;

  cp5.addScrollableList("listNB11")
    .setPosition(900, 100)
    .setSize(30, 300)
    .setBarHeight(30)
    .setItemHeight(20)
    .addItems(f)
    .setOpen(false)
    .setCaptionLabel("11")
    .setFont(fonts);
  ;

  cp5.addScrollableList("listNB12")
    .setPosition(930, 100)
    .setSize(30, 300)
    .setBarHeight(30)
    .setItemHeight(20)
    .addItems(f)
    .setOpen(false)
    .setCaptionLabel("12")
    .setFont(fonts);
  ;

  cp5.addScrollableList("listNB13")
    .setPosition(950, 100)
    .setSize(30, 300)
    .setBarHeight(30)
    .setItemHeight(20)
    .addItems(f)
    .setOpen(false)
    .setCaptionLabel("13")
    .setFont(fonts);
  ;

  cp5.addScrollableList("listNB14")
    .setPosition(980, 100)
    .setSize(30, 300)
    .setBarHeight(30)
    .setItemHeight(20)
    .addItems(f)
    .setOpen(false)
    .setCaptionLabel("14")
    .setFont(fonts);
  ;

  cp5.addScrollableList("listNB15")
    .setPosition(1010, 100)
    .setSize(30, 300)
    .setBarHeight(30)
    .setItemHeight(20)
    .addItems(f)
    .setOpen(false)
    .setCaptionLabel("15")
    .setFont(fonts);
  ;

  cp5.addScrollableList("listNB16")
    .setPosition(1040, 100)
    .setSize(30, 300)
    .setBarHeight(30)
    .setItemHeight(20)
    .addItems(f)
    .setOpen(false)
    .setCaptionLabel("16")
    .setFont(fonts);
  ;

  //CHORD 3
  cp5.addScrollableList("listNC1")
    .setPosition(50, 400)
    .setSize(30, 300)
    .setBarHeight(30)
    .setItemHeight(20)
    .addItems(f)
    .setOpen(false)
    .setCaptionLabel("1")
    .setFont(fonts);
  ;

  cp5.addScrollableList("listNC2")
    .setPosition(80, 400)
    .setSize(30, 300)
    .setBarHeight(30)
    .setItemHeight(20)
    .addItems(f)
    .setOpen(false)
    .setCaptionLabel("2")
    .setFont(fonts);
  ;

  cp5.addScrollableList("listNC3")
    .setPosition(110, 400)
    .setSize(30, 300)
    .setBarHeight(30)
    .setItemHeight(20)
    .addItems(f)
    .setOpen(false)
    .setCaptionLabel("3")
    .setFont(fonts);
  ;

  cp5.addScrollableList("listNC4")
    .setPosition(140, 400)
    .setSize(30, 300)
    .setBarHeight(30)
    .setItemHeight(20)
    .addItems(f)
    .setOpen(false)
    .setCaptionLabel("4")
    .setFont(fonts);
  ;

  cp5.addScrollableList("listNC5")
    .setPosition(170, 400)
    .setSize(30, 300)
    .setBarHeight(30)
    .setItemHeight(20)
    .addItems(f)
    .setOpen(false)
    .setCaptionLabel("5")
    .setFont(fonts);
  ;

  cp5.addScrollableList("listNC6")
    .setPosition(200, 400)
    .setSize(30, 300)
    .setBarHeight(30)
    .setItemHeight(20)
    .addItems(f)
    .setOpen(false)
    .setCaptionLabel("6")
    .setFont(fonts);
  ;

  cp5.addScrollableList("listNC7")
    .setPosition(230, 400)
    .setSize(30, 300)
    .setBarHeight(30)
    .setItemHeight(20)
    .addItems(f)
    .setOpen(false)
    .setCaptionLabel("7")
    .setFont(fonts);
  ;

  cp5.addScrollableList("listNC8")
    .setPosition(260, 400)
    .setSize(30, 300)
    .setBarHeight(30)
    .setItemHeight(20)
    .addItems(f)
    .setOpen(false)
    .setCaptionLabel("8")
    .setFont(fonts);
  ;

  cp5.addScrollableList("listNC9")
    .setPosition(290, 400)
    .setSize(30, 300)
    .setBarHeight(30)
    .setItemHeight(20)
    .addItems(f)
    .setOpen(false)
    .setCaptionLabel("9")
    .setFont(fonts);
  ;

  cp5.addScrollableList("listNC10")
    .setPosition(320, 400)
    .setSize(30, 300)
    .setBarHeight(30)
    .setItemHeight(20)
    .addItems(f)
    .setOpen(false)
    .setCaptionLabel("10")
    .setFont(fonts);
  ;

  cp5.addScrollableList("listNC11")
    .setPosition(350, 400)
    .setSize(30, 300)
    .setBarHeight(30)
    .setItemHeight(20)
    .addItems(f)
    .setOpen(false)
    .setCaptionLabel("11")
    .setFont(fonts);
  ;

  cp5.addScrollableList("listNC12")
    .setPosition(380, 400)
    .setSize(30, 300)
    .setBarHeight(30)
    .setItemHeight(20)
    .addItems(f)
    .setOpen(false)
    .setCaptionLabel("12")
    .setFont(fonts);
  ;

  cp5.addScrollableList("listNC13")
    .setPosition(410, 400)
    .setSize(30, 300)
    .setBarHeight(30)
    .setItemHeight(20)
    .addItems(f)
    .setOpen(false)
    .setCaptionLabel("13")
    .setFont(fonts);
  ;

  cp5.addScrollableList("listNC14")
    .setPosition(440, 400)
    .setSize(30, 300)
    .setBarHeight(30)
    .setItemHeight(20)
    .addItems(f)
    .setOpen(false)
    .setCaptionLabel("14")
    .setFont(fonts);
  ;

  cp5.addScrollableList("listNC15")
    .setPosition(470, 400)
    .setSize(30, 300)
    .setBarHeight(30)
    .setItemHeight(20)
    .addItems(f)
    .setOpen(false)
    .setCaptionLabel("15")
    .setFont(fonts);
  ;

  cp5.addScrollableList("listNC16")
    .setPosition(500, 400)
    .setSize(30, 300)
    .setBarHeight(30)
    .setItemHeight(20)
    .addItems(f)
    .setOpen(false)
    .setCaptionLabel("16")
    .setFont(fonts);
  ;

  //CHORD 4
  cp5.addScrollableList("listND1")
    .setPosition(600, 400)
    .setSize(30, 300)
    .setBarHeight(30)
    .setItemHeight(20)
    .addItems(f)
    .setOpen(false)
    .setCaptionLabel("1")
    .setFont(fonts);
  ;

  cp5.addScrollableList("listND2")
    .setPosition(630, 400)
    .setSize(30, 300)
    .setBarHeight(30)
    .setItemHeight(20)
    .addItems(f)
    .setOpen(false)
    .setCaptionLabel("2")
    .setFont(fonts);
  ;

  cp5.addScrollableList("listND3")
    .setPosition(660, 400)
    .setSize(30, 300)
    .setBarHeight(30)
    .setItemHeight(20)
    .addItems(f)
    .setOpen(false)
    .setCaptionLabel("3")
    .setFont(fonts);
  ;

  cp5.addScrollableList("listND4")
    .setPosition(690, 400)
    .setSize(30, 300)
    .setBarHeight(30)
    .setItemHeight(20)
    .addItems(f)
    .setOpen(false)
    .setCaptionLabel("4")
    .setFont(fonts);
  ;

  cp5.addScrollableList("listND5")
    .setPosition(720, 400)
    .setSize(30, 300)
    .setBarHeight(30)
    .setItemHeight(20)
    .addItems(f)
    .setOpen(false)
    .setCaptionLabel("5")
    .setFont(fonts);
  ;

  cp5.addScrollableList("listND6")
    .setPosition(750, 400)
    .setSize(30, 300)
    .setBarHeight(30)
    .setItemHeight(20)
    .addItems(f)
    .setOpen(false)
    .setCaptionLabel("6")
    .setFont(fonts);
  ;

  cp5.addScrollableList("listND7")
    .setPosition(780, 400)
    .setSize(30, 300)
    .setBarHeight(30)
    .setItemHeight(20)
    .addItems(f)
    .setOpen(false)
    .setCaptionLabel("7")
    .setFont(fonts);
  ;

  cp5.addScrollableList("listND8")
    .setPosition(810, 400)
    .setSize(30, 300)
    .setBarHeight(30)
    .setItemHeight(20)
    .addItems(f)
    .setOpen(false)
    .setCaptionLabel("8")
    .setFont(fonts);
  ;

  cp5.addScrollableList("listND9")
    .setPosition(840, 400)
    .setSize(30, 300)
    .setBarHeight(30)
    .setItemHeight(20)
    .addItems(f)
    .setOpen(false)
    .setCaptionLabel("9")
    .setFont(fonts);
  ;

  cp5.addScrollableList("listND10")
    .setPosition(870, 400)
    .setSize(30, 300)
    .setBarHeight(30)
    .setItemHeight(20)
    .addItems(f)
    .setOpen(false)
    .setCaptionLabel("10")
    .setFont(fonts);
  ;

  cp5.addScrollableList("listND11")
    .setPosition(900, 400)
    .setSize(30, 300)
    .setBarHeight(30)
    .setItemHeight(20)
    .addItems(f)
    .setOpen(false)
    .setCaptionLabel("11")
    .setFont(fonts);
  ;

  cp5.addScrollableList("listND12")
    .setPosition(930, 400)
    .setSize(30, 300)
    .setBarHeight(30)
    .setItemHeight(20)
    .addItems(f)
    .setOpen(false)
    .setCaptionLabel("12")
    .setFont(fonts);
  ;

  cp5.addScrollableList("listND13")
    .setPosition(950, 400)
    .setSize(30, 300)
    .setBarHeight(30)
    .setItemHeight(20)
    .addItems(f)
    .setOpen(false)
    .setCaptionLabel("13")
    .setFont(fonts);
  ;

  cp5.addScrollableList("listND14")
    .setPosition(980, 400)
    .setSize(30, 300)
    .setBarHeight(30)
    .setItemHeight(20)
    .addItems(f)
    .setOpen(false)
    .setCaptionLabel("14")
    .setFont(fonts);
  ;

  cp5.addScrollableList("listND15")
    .setPosition(1010, 400)
    .setSize(30, 300)
    .setBarHeight(30)
    .setItemHeight(20)
    .addItems(f)
    .setOpen(false)
    .setCaptionLabel("15")
    .setFont(fonts);
  ;

  cp5.addScrollableList("listND16")
    .setPosition(1040, 400)
    .setSize(30, 300)
    .setBarHeight(30)
    .setItemHeight(20)
    .addItems(f)
    .setOpen(false)
    .setCaptionLabel("16")
    .setFont(fonts);
  ;

  cp5.addKnob("knobLock")
    .setPosition(50, 700)
    .setRadius(25)
    .setRange(0, 4)
    .setValue(25)
    .setCaptionLabel("lock");
  ;


  cp5.getController("knobLock").moveTo("tab_backing");
  cp5.getController("listL").moveTo("tab_backing");
  cp5.getController("listNA1").moveTo("tab_backing");
  cp5.getController("listNA2").moveTo("tab_backing");
  cp5.getController("listNA3").moveTo("tab_backing");
  cp5.getController("listNA4").moveTo("tab_backing");
  cp5.getController("listNA5").moveTo("tab_backing");
  cp5.getController("listNA6").moveTo("tab_backing");
  cp5.getController("listNA7").moveTo("tab_backing");
  cp5.getController("listNA8").moveTo("tab_backing");
  cp5.getController("listNA9").moveTo("tab_backing");
  cp5.getController("listNA10").moveTo("tab_backing");
  cp5.getController("listNA11").moveTo("tab_backing");
  cp5.getController("listNA12").moveTo("tab_backing");
  cp5.getController("listNA13").moveTo("tab_backing");
  cp5.getController("listNA14").moveTo("tab_backing");
  cp5.getController("listNA15").moveTo("tab_backing");
  cp5.getController("listNA16").moveTo("tab_backing");
  cp5.getController("listNB1").moveTo("tab_backing");
  cp5.getController("listNB2").moveTo("tab_backing");
  cp5.getController("listNB3").moveTo("tab_backing");
  cp5.getController("listNB4").moveTo("tab_backing");
  cp5.getController("listNB5").moveTo("tab_backing");
  cp5.getController("listNB6").moveTo("tab_backing");
  cp5.getController("listNB7").moveTo("tab_backing");
  cp5.getController("listNB8").moveTo("tab_backing");
  cp5.getController("listNB9").moveTo("tab_backing");
  cp5.getController("listNB10").moveTo("tab_backing");
  cp5.getController("listNB11").moveTo("tab_backing");
  cp5.getController("listNB12").moveTo("tab_backing");
  cp5.getController("listNB13").moveTo("tab_backing");
  cp5.getController("listNB14").moveTo("tab_backing");
  cp5.getController("listNB15").moveTo("tab_backing");
  cp5.getController("listNB16").moveTo("tab_backing");
  cp5.getController("listNC1").moveTo("tab_backing");
  cp5.getController("listNC2").moveTo("tab_backing");
  cp5.getController("listNC3").moveTo("tab_backing");
  cp5.getController("listNC4").moveTo("tab_backing");
  cp5.getController("listNC5").moveTo("tab_backing");
  cp5.getController("listNC6").moveTo("tab_backing");
  cp5.getController("listNC7").moveTo("tab_backing");
  cp5.getController("listNC8").moveTo("tab_backing");
  cp5.getController("listNC9").moveTo("tab_backing");
  cp5.getController("listNC10").moveTo("tab_backing");
  cp5.getController("listNC11").moveTo("tab_backing");
  cp5.getController("listNC12").moveTo("tab_backing");
  cp5.getController("listNC13").moveTo("tab_backing");
  cp5.getController("listNC14").moveTo("tab_backing");
  cp5.getController("listNC15").moveTo("tab_backing");
  cp5.getController("listNC16").moveTo("tab_backing");
  cp5.getController("listND1").moveTo("tab_backing");
  cp5.getController("listND2").moveTo("tab_backing");
  cp5.getController("listND3").moveTo("tab_backing");
  cp5.getController("listND4").moveTo("tab_backing");
  cp5.getController("listND5").moveTo("tab_backing");
  cp5.getController("listND6").moveTo("tab_backing");
  cp5.getController("listND7").moveTo("tab_backing");
  cp5.getController("listND8").moveTo("tab_backing");
  cp5.getController("listND9").moveTo("tab_backing");
  cp5.getController("listND10").moveTo("tab_backing");
  cp5.getController("listND11").moveTo("tab_backing");
  cp5.getController("listND12").moveTo("tab_backing");
  cp5.getController("listND13").moveTo("tab_backing");
  cp5.getController("listND14").moveTo("tab_backing");
  cp5.getController("listND15").moveTo("tab_backing");
  cp5.getController("listND16").moveTo("tab_backing");


  //*************************************
  //save  controls *****************
  //*************************************


  cp5.addToggle("toggleE")
    .setPosition(50, 150)
    .setSize(50, 20)
    .setValue(false)
    .setCaptionLabel("save settings to disk");
  ;

  cp5.addToggle("toggleH")
    .setPosition(50, 300)
    .setSize(50, 20)
    .setValue(false)
    .setCaptionLabel("save color to flute");
  ;

  cp5.addToggle("toggleI")
    .setPosition(700, 300)
    .setSize(50, 20)
    .setValue(false)
    .setCaptionLabel("reset this color");

  cp5.addToggle("toggleJ")
    .setPosition(50, 450)
    .setSize(50, 20)
    .setValue(false)
    .setCaptionLabel("load color from disk");
  ;


  cp5.addTextfield("load file name")
    .setPosition(350, 450)
    .setSize(200, 25)
    .setFont(font)
    .setFocus(true)
    .setColor(color(255, 0, 0))
    ;

  cp5.addTextfield("save file name")
    .setPosition(350, 150)
    .setSize(200, 25)
    .setFont(font)
    .setFocus(true)
    .setColor(color(255, 0, 0))
    ;

  List a = Arrays.asList("enter a color", "6-artic", "7-pumpkin", "8-lapis", "9-porcelain");
  cp5.addScrollableList("listO")
    .setPosition(350, 300)
    .setSize(200, 320)
    .setFont(font)
    .setBarHeight(30)
    .setItemHeight(30)
    .addItems(a)
    .setOpen(false)
    .setCaptionLabel("preset number");
  ;


  cp5.getController("toggleE").moveTo("tab_save");
  cp5.getController("toggleH").moveTo("tab_save");
  cp5.getController("toggleI").moveTo("tab_save");
  cp5.getController("listO").moveTo("tab_save");
  cp5.getController("toggleJ").moveTo("tab_save");
  cp5.getController("load file name").moveTo("tab_save");
  cp5.getController("save file name").moveTo("tab_save");
  //myTextarea2.moveTo("tab_save");


  //*************************************
  //advanced  controls *****************
  //*************************************

  cp5.addTextlabel("label6")
    .setText("PHASE GAIN")
    .setPosition(50, 100)
    .setColorValue(0xffFFFFFF)//leading ff on hex color
    .setFont(font)
    ;


  cp5.addNumberbox("NA1")
    .setPosition(50, 160)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 6)
    .setMultiplier(0.1) // set the sensitifity of the numberbox
    .setCaptionLabel("1")
  ;
    ;

  cp5.addNumberbox("NA2")
    .setPosition(100, 160)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 6)
    .setMultiplier(0.1) // set the sensitifity of the numberbox
    .setCaptionLabel("2");
  ;

  cp5.addNumberbox("NA3")
    .setPosition(150, 160)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 6)
    .setMultiplier(0.1) // set the sensitifity of the numberbox
    .setCaptionLabel("3");
  ;

  cp5.addNumberbox("NA4")
    .setPosition(200, 160)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 6)
    .setMultiplier(0.1) // set the sensitifity of the numberbox
    .setCaptionLabel("4");
  ;

  cp5.addNumberbox("NA5")
    .setPosition(250, 160)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 6)
    .setMultiplier(0.1) // set the sensitifity of the numberbox
    .setCaptionLabel("5");
  ;

  cp5.addNumberbox("NA6")
    .setPosition(300, 160)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 6)
    .setMultiplier(0.1) // set the sensitifity of the numberbox
    .setCaptionLabel("6");
  ;

  cp5.addNumberbox("NA7")
    .setPosition(350, 160)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 6)
    .setMultiplier(0.1) // set the sensitifity of the numberbox
    .setCaptionLabel("7");
  ;

  cp5.addNumberbox("NA8")
    .setPosition(400, 160)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 6)
    .setMultiplier(0.1) // set the sensitifity of the numberbox
    .setCaptionLabel("8");
  ;

  cp5.addNumberbox("NA9")
    .setPosition(450, 160)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 6)
    .setMultiplier(0.1) // set the sensitifity of the numberbox
    .setCaptionLabel("9");
  ;

  cp5.addNumberbox("NA10")
    .setPosition(500, 160)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 6)
    .setMultiplier(0.1) // set the sensitifity of the numberbox
    .setCaptionLabel("10");
  ;

  cp5.addNumberbox("NA11")
    .setPosition(550, 160)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 6)
    .setMultiplier(0.1) // set the sensitifity of the numberbox
    .setCaptionLabel("11");
  ;

  cp5.addNumberbox("NA12")
    .setPosition(600, 160)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 6)
    .setMultiplier(0.1) // set the sensitifity of the numberbox
    .setCaptionLabel("12");
  ;

  cp5.addNumberbox("NA13")
    .setPosition(650, 160)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 6)
    .setMultiplier(0.1) // set the sensitifity of the numberbox
    .setCaptionLabel("13");
  ;

  cp5.addNumberbox("NA14")
    .setPosition(700, 160)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 6)
    .setMultiplier(0.1) // set the sensitifity of the numberbox
    .setCaptionLabel("14");
  ;

  cp5.addNumberbox("NA15")
    .setPosition(750, 160)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 6)
    .setMultiplier(0.1) // set the sensitifity of the numberbox
    .setCaptionLabel("15");
  ;

  cp5.addNumberbox("NA16")
    .setPosition(800, 160)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 6)
    .setMultiplier(0.1) // set the sensitifity of the numberbox
    .setCaptionLabel("16");
  ;

  cp5.addNumberbox("NA17")
    .setPosition(850, 160)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 6)
    .setMultiplier(0.1) // set the sensitifity of the numberbox
    .setCaptionLabel("17");
  ;

  cp5.addNumberbox("NA18")
    .setPosition(900, 160)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 6)
    .setMultiplier(0.1) // set the sensitifity of the numberbox
    .setCaptionLabel("18");
  ;

  cp5.addNumberbox("NA19")
    .setPosition(950, 160)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 6)
    .setMultiplier(0.1) // set the sensitifity of the numberbox
    .setCaptionLabel("19");
  ;

  cp5.addNumberbox("NA20")
    .setPosition(1000, 160)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 6)
    .setMultiplier(0.1) // set the sensitifity of the numberbox
    .setCaptionLabel("20");
  ;

  cp5.addNumberbox("NA21")
    .setPosition(1050, 160)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 6)
    .setMultiplier(0.1) // set the sensitifity of the numberbox  
    .setCaptionLabel("21");
  ;

  cp5.addNumberbox("NA22")
    .setPosition(1100, 160)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 6)
    .setMultiplier(0.1) // set the sensitifity of the numberbox    
    .setCaptionLabel("22");
  ;

  cp5.getController("NA1").moveTo("tab_advanced");
  cp5.getController("NA2").moveTo("tab_advanced");
  cp5.getController("NA3").moveTo("tab_advanced");
  cp5.getController("NA4").moveTo("tab_advanced");
  cp5.getController("NA5").moveTo("tab_advanced");
  cp5.getController("NA6").moveTo("tab_advanced");
  cp5.getController("NA7").moveTo("tab_advanced");
  cp5.getController("NA8").moveTo("tab_advanced");
  cp5.getController("NA9").moveTo("tab_advanced");
  cp5.getController("NA10").moveTo("tab_advanced");
  cp5.getController("NA11").moveTo("tab_advanced");
  cp5.getController("NA12").moveTo("tab_advanced");
  cp5.getController("NA13").moveTo("tab_advanced");
  cp5.getController("NA14").moveTo("tab_advanced");
  cp5.getController("NA15").moveTo("tab_advanced");
  cp5.getController("NA16").moveTo("tab_advanced");
  cp5.getController("NA17").moveTo("tab_advanced");
  cp5.getController("NA18").moveTo("tab_advanced");
  cp5.getController("NA19").moveTo("tab_advanced");
  cp5.getController("NA20").moveTo("tab_advanced");
  cp5.getController("NA20").moveTo("tab_advanced");
  cp5.getController("NA21").moveTo("tab_advanced");
  cp5.getController("NA22").moveTo("tab_advanced");

  cp5.addTextlabel("label7")
    .setText("PHASE TARGET")
    .setPosition(50, 300)
    .setColorValue(0xffFFFFFF)//leading ff on hex color
    .setFont(font)
    ;

  cp5.addNumberbox("NB1")
    .setPosition(50, 360)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2) // set the sensitifity of the numberbox
    .setCaptionLabel("1");
  ;

  cp5.addNumberbox("NB2")
    .setPosition(100, 360)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2) // set the sensitifity of the numberbox
    .setCaptionLabel("2");
  ;

  cp5.addNumberbox("NB3")
    .setPosition(150, 360)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2) // set the sensitifity of the numberbox
    .setCaptionLabel("3");
  ;

  cp5.addNumberbox("NB4")
    .setPosition(200, 360)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2) // set the sensitifity of the numberbox
    .setCaptionLabel("4");
  ;

  cp5.addNumberbox("NB5")
    .setPosition(250, 360)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2) // set the sensitifity of the numberbox
    .setCaptionLabel("5");
  ;

  cp5.addNumberbox("NB6")
    .setPosition(300, 360)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2) // set the sensitifity of the numberbox
    .setCaptionLabel("6");
  ;

  cp5.addNumberbox("NB7")
    .setPosition(350, 360)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2) // set the sensitifity of the numberbox
    .setCaptionLabel("7");
  ;

  cp5.addNumberbox("NB8")
    .setPosition(400, 360)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2) // set the sensitifity of the numberbox
    .setCaptionLabel("8");
  ;

  cp5.addNumberbox("NB9")
    .setPosition(450, 360)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2) // set the sensitifity of the numberbox
    .setCaptionLabel("9");
  ;

  cp5.addNumberbox("NB10")
    .setPosition(500, 360)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2) // set the sensitifity of the numberbox
    .setCaptionLabel("10");
  ;

  cp5.addNumberbox("NB11")
    .setPosition(550, 360)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2) // set the sensitifity of the numberbox
    .setCaptionLabel("11");
  ;

  cp5.addNumberbox("NB12")
    .setPosition(600, 360)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2) // set the sensitifity of the numberbox
    .setCaptionLabel("12");
  ;

  cp5.addNumberbox("NB13")
    .setPosition(650, 360)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2) // set the sensitifity of the numberbox  
    .setCaptionLabel("13");
  ;

  cp5.addNumberbox("NB14")
    .setPosition(700, 360)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2) // set the sensitifity of the numberbox
    .setCaptionLabel("14");
  ;

  cp5.addNumberbox("NB15")
    .setPosition(750, 360)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2) // set the sensitifity of the numberbox
    .setCaptionLabel("15");
  ;

  cp5.addNumberbox("NB16")
    .setPosition(800, 360)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2) // set the sensitifity of the numberbox    
    .setCaptionLabel("16");
  ;

  cp5.addNumberbox("NB17")
    .setPosition(850, 360)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2) // set the sensitifity of the numberbox    
    .setCaptionLabel("17");
  ;

  cp5.addNumberbox("NB18")
    .setPosition(900, 360)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2) // set the sensitifity of the numberbox    
    .setCaptionLabel("18");
  ;

  cp5.addNumberbox("NB19")
    .setPosition(950, 360)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2) // set the sensitifity of the numberbox    
    .setCaptionLabel("19");
  ;

  cp5.addNumberbox("NB20")
    .setPosition(1000, 360)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2) // set the sensitifity of the numberbox   
    .setCaptionLabel("20");
  ;

  cp5.addNumberbox("NB21")
    .setPosition(1050, 360)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2) // set the sensitifity of the numberbox
   
    .setCaptionLabel("21");
  ;

  cp5.addNumberbox("NB22")
    .setPosition(1100, 360)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2) // set the sensitifity of the numberbox    
    .setCaptionLabel("21");
  ;

  cp5.getController("NB1").moveTo("tab_advanced");
  cp5.getController("NB2").moveTo("tab_advanced");
  cp5.getController("NB3").moveTo("tab_advanced");
  cp5.getController("NB4").moveTo("tab_advanced");
  cp5.getController("NB5").moveTo("tab_advanced");
  cp5.getController("NB6").moveTo("tab_advanced");
  cp5.getController("NB7").moveTo("tab_advanced");
  cp5.getController("NB8").moveTo("tab_advanced");
  cp5.getController("NB9").moveTo("tab_advanced");
  cp5.getController("NB10").moveTo("tab_advanced");
  cp5.getController("NB11").moveTo("tab_advanced");
  cp5.getController("NB12").moveTo("tab_advanced");
  cp5.getController("NB13").moveTo("tab_advanced");
  cp5.getController("NB14").moveTo("tab_advanced");
  cp5.getController("NB15").moveTo("tab_advanced");
  cp5.getController("NB16").moveTo("tab_advanced");
  cp5.getController("NB17").moveTo("tab_advanced");
  cp5.getController("NB18").moveTo("tab_advanced");
  cp5.getController("NB19").moveTo("tab_advanced");
  cp5.getController("NB20").moveTo("tab_advanced");
  cp5.getController("NB21").moveTo("tab_advanced");
  cp5.getController("NB22").moveTo("tab_advanced");

  cp5.addTextlabel("label8")
    .setText("SPEAKER GAIN")
    .setPosition(50, 500)
    .setColorValue(0xffFFFFFF)//leading ff on hex color
    .setFont(font)
    ;

  cp5.addNumberbox("NC1")
    .setPosition(50, 560)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2) // set the sensitifity of the numberbox    
    .setCaptionLabel("1");
  ;

  cp5.addNumberbox("NC2")
    .setPosition(100, 560)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2) // set the sensitifity of the numberbox    
    .setCaptionLabel("2");
  ;

  cp5.addNumberbox("NC3")
    .setPosition(150, 560)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2) // set the sensitifity of the numberbox    
    .setCaptionLabel("3");
  ;

  cp5.addNumberbox("NC4")
    .setPosition(200, 560)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2) // set the sensitifity of the numberbox   
    .setCaptionLabel("4");
  ;

  cp5.addNumberbox("NC5")
    .setPosition(250, 560)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2) // set the sensitifity of the numberbox    
    .setCaptionLabel("5");
  ;

  cp5.addNumberbox("NC6")
    .setPosition(300, 560)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2) // set the sensitifity of the numberbox  
    .setCaptionLabel("6");
  ;

  cp5.addNumberbox("NC7")
    .setPosition(350, 560)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2) // set the sensitifity of the numberbox    
    .setCaptionLabel("7");
  ;

  cp5.addNumberbox("NC8")
    .setPosition(400, 560)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2) // set the sensitifity of the numberbox    
    .setCaptionLabel("8");
  ;

  cp5.addNumberbox("NC9")
    .setPosition(450, 560)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2) // set the sensitifity of the numberbox    
    .setCaptionLabel("9");
  ;

  cp5.addNumberbox("NC10")
    .setPosition(500, 560)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2) // set the sensitifity of the numberbox    
    .setCaptionLabel("10");
  ;

  cp5.addNumberbox("NC11")
    .setPosition(550, 560)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2) // set the sensitifity of the numberbox    
    .setCaptionLabel("11");
  ;

  cp5.addNumberbox("NC12")
    .setPosition(600, 560)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2) // set the sensitifity of the numberbox    
    .setCaptionLabel("12");
  ;

  cp5.addNumberbox("NC13")
    .setPosition(650, 560)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2) // set the sensitifity of the numberbox    
    .setCaptionLabel("13");
  ;

  cp5.addNumberbox("NC14")
    .setPosition(700, 560)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2) // set the sensitifity of the numberbox    
    .setCaptionLabel("14");
  ;

  cp5.addNumberbox("NC15")
    .setPosition(750, 560)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2) // set the sensitifity of the numberbox    
    .setCaptionLabel("15");
  ;

  cp5.addNumberbox("NC16")
    .setPosition(800, 560)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2) // set the sensitifity of the numberbox
   
    .setCaptionLabel("16");
  ;

  cp5.addNumberbox("NC17")
    .setPosition(850, 560)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2) // set the sensitifity of the numberbox    
    .setCaptionLabel("17");
  ;

  cp5.addNumberbox("NC18")
    .setPosition(900, 560)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2) // set the sensitifity of the numberbox    
    .setCaptionLabel("18");
  ;

  cp5.addNumberbox("NC19")
    .setPosition(950, 560)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2) // set the sensitifity of the numberbox    
    .setCaptionLabel("19");
  ;

  cp5.addNumberbox("NC20")
    .setPosition(1000, 560)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2) // set the sensitifity of the numberbox    
    .setCaptionLabel("20");
  ;

  cp5.addNumberbox("NC21")
    .setPosition(1050, 560)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2) // set the sensitifity of the numberbox   
    .setCaptionLabel("21");
  ;

  cp5.addNumberbox("NC22")
    .setPosition(1100, 560)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2) // set the sensitivity of the numberbox   
    .setCaptionLabel("22");
  ;

  cp5.getController("NC1").moveTo("tab_advanced");
  cp5.getController("NC2").moveTo("tab_advanced");
  cp5.getController("NC3").moveTo("tab_advanced");
  cp5.getController("NC4").moveTo("tab_advanced");
  cp5.getController("NC5").moveTo("tab_advanced");
  cp5.getController("NC6").moveTo("tab_advanced");
  cp5.getController("NC7").moveTo("tab_advanced");
  cp5.getController("NC8").moveTo("tab_advanced");
  cp5.getController("NC9").moveTo("tab_advanced");
  cp5.getController("NC10").moveTo("tab_advanced");
  cp5.getController("NC11").moveTo("tab_advanced");
  cp5.getController("NC12").moveTo("tab_advanced");
  cp5.getController("NC13").moveTo("tab_advanced");
  cp5.getController("NC14").moveTo("tab_advanced");
  cp5.getController("NC15").moveTo("tab_advanced");
  cp5.getController("NC16").moveTo("tab_advanced");
  cp5.getController("NC17").moveTo("tab_advanced");
  cp5.getController("NC18").moveTo("tab_advanced");
  cp5.getController("NC19").moveTo("tab_advanced");
  cp5.getController("NC20").moveTo("tab_advanced");
  cp5.getController("NC21").moveTo("tab_advanced");
  cp5.getController("NC22").moveTo("tab_advanced");
  cp5.getController("label6").moveTo("tab_advanced");
  cp5.getController("label7").moveTo("tab_advanced");
  cp5.getController("label8").moveTo("tab_advanced");

  cp5.addToggle("toggleK")
    .setPosition(50, 700)
    .setSize(50, 20)
    .setValue(false)
    .setCaptionLabel("save settings to flute");
  ;

  cp5.addToggle("toggleL")
    .setPosition(350, 700)
    .setSize(50, 20)
    .setValue(false)
    .setCaptionLabel("factory reset settings");
  ;

  cp5.getController("toggleL").moveTo("tab_advanced");
  cp5.getController("toggleK").moveTo("tab_advanced");
}
//*******************************************************************************
//
void draw()
  //
  //*******************************************************************************

{
  background(200, 200, 200);

  if ((cp5.getTab("tab_drums").isActive()) &&(doonce==true)) //turn off count display if not in drum preview
  {
    doonce=false;
    if (myPort != null) myPort.write("49,"+"1"+" "); //turn off beat counter when saving

  }

  if ((cp5.getTab("tab_drums").isActive()==false) && (doonce==false))
  {
    doonce=true;
    if (myPort != null) myPort.write("49,"+"0"+" "); //turn off count display  when not in drums
  }

  //*******************************************
  //update control values with data from Teensy
  //*******************************************

  //check for incoming communications and parse
  if (myPort != null)
  {
    if (myPort.available() > 0)
    {
      command = myPort.readStringUntil('\n');         // read it and store it in command
      if (command == null || command.isEmpty()) command="0";  //catch null pointer excpeton
      String[] list = splitTokens(command);
      datalength = list.length;
      int controlindex=0;
      if (datalength!=0)controlindex=int(list[0]);  //parse into controlindex and control value
      int controlvalue=0;

      if (datalength>1) controlvalue=int(list[1]);//


      //print("from teensy ");
      //print(controlindex);
      //print(", ");
      //println(controlvalue);


      // Writes the strings to a file, each on a separate line

      switch(controlindex)//per incoming serial data from teensy, update controllers
      {

        //preset display
        case(0):
        cp5.get(Textfield.class, "preset").clear();
        cp5.get(Textfield.class, "preset").setText(str(int(controlvalue)));
        currentpreset=int(controlvalue);
        break;
        //ambiance controls
        case(1):
        cp5.getController("knobA").setValue(controlvalue);
        break;
        case(2):
        cp5.getController("knobB").setValue(controlvalue);
        break;
        case(3):
        cp5.getController("listB").setValue(controlvalue);
        break;
        case(4):
        cp5.getController("toggleA").setValue(controlvalue);
        break;
        case(5):
        cp5.getController("monvolume").setValue(controlvalue);
        break;
        case(6):
        cp5.getController("knobC").setValue(controlvalue);
        break;
        case(7):
        cp5.getController("knobD").setValue(controlvalue);
        break;
        case(8):
        cp5.getController("toggleB").setValue(controlvalue);
        break;
        case(11):
        cp5.getController("listD").setValue(controlvalue);
        break;
        case(12):
        cp5.getController("listE").setValue(controlvalue);
        break;
        case(13):
        cp5.getController("knobE").setValue(controlvalue);
        break;
        case(14):
        cp5.getController("sliderA").setValue(controlvalue);
        break;
        case(15):
        cp5.getController("sliderB").setValue(controlvalue);
        break;
        case(16):
        cp5.getController("sliderC").setValue(controlvalue);
        break;
        case(17):
        cp5.getController("sliderD").setValue(controlvalue);
        break;
        case(18):
        cp5.getController("knobF").setValue(controlvalue);
        break;
        case(19):
        cp5.getController("listF").setValue(controlvalue);
        break;
        case(20):
        cp5.getController("listG").setValue(controlvalue);
        break;
        case(21):
        cp5.getController("knobG").setValue(controlvalue);
        break;
        case(22):
        cp5.getController("sliderE").setValue(controlvalue);
        break;
        case(23):
        cp5.getController("sliderF").setValue(controlvalue);
        break;
        case(24):
        cp5.getController("sliderG").setValue(controlvalue);
        break;
        case(25):
        cp5.getController("sliderH").setValue(controlvalue);
        break;
        case(26):
        cp5.getController("knobH").setValue(controlvalue);
        break;
        case(27):
        cp5.getController("listH").setValue(controlvalue);
        break;
        case(28):
        cp5.getController("listI").setValue(controlvalue);
        break;
        case(29):
        cp5.getController("knobI").setValue(controlvalue);
        break;
        case(30):
        cp5.getController("sliderI").setValue(controlvalue);
        break;
        case(31):
        cp5.getController("sliderJ").setValue(controlvalue);
        break;
        case(32):
        cp5.getController("sliderK").setValue(controlvalue);
        break;
        case(33):
        cp5.getController("sliderL").setValue(controlvalue);
        break;
        case(34):
        cp5.getController("knobJ").setValue(controlvalue);
        break;
        case(36):
        cp5.getController("knobK").setValue(controlvalue);
        break;
        case(37):
        cp5.getController("listJ").setValue(controlvalue);
        break;
        case(38):
        cp5.getController("knobL").setValue(controlvalue);
        break;
        case(39):
        cp5.getController("listK").setValue(controlvalue);
        break;
        case(40):
        cp5.getController("toggleF").setValue(controlvalue);
        break;
        case(41):
        cp5.getController("listL").setValue(controlvalue);
        break;
        case(42):
        cp5.getController("toggleG").setValue(controlvalue);
        break;
        case(46):
        cp5.getController("knobAO").setValue(controlvalue);
        break;
        case(47):
        cp5.getController("knobAP").setValue(controlvalue);
        break;
        case(48):
        espeedLSB=controlvalue;
        break;
        case(50):
        cp5.getController("knobM").setValue((controlvalue*256)+espeedLSB);
        break;
        case(51):
        cp5.getController("knobN").setValue(controlvalue);
        break;
        case(52):
        cp5.getController("knobO").setValue(controlvalue);
        break;
        case(53):
        cp5.getController("knobP").setValue(controlvalue);
        break;
        case(54):
        cp5.getController("knobQ").setValue(controlvalue);
        break;
        case(55):
        cp5.getController("knobR").setValue(controlvalue);
        break;
        case(56):
        cp5.getController("knobS").setValue(controlvalue);
        break;
        case(57):
        cp5.getController("knobT").setValue(controlvalue);
        break;
        case(58):
        cp5.getController("knobU").setValue(controlvalue);
        break;
        case(59):
        cp5.getController("knobV").setValue(controlvalue);
        break;
        case(60):
        cp5.getController("knobW").setValue(controlvalue);
        break;
        case(61):
        cp5.getController("knobX").setValue(controlvalue);
        break;
        case(62):
        cp5.getController("knobY").setValue(controlvalue);
        break;
        case(63):
        cp5.getController("knobZ").setValue(controlvalue);
        break;
        case(64):
        cp5.getController("knobAA").setValue(controlvalue);
        break;
        case(65):
        cp5.getController("knobAB").setValue(controlvalue);
        break;
        case(66):
        cp5.getController("knobAC").setValue(controlvalue);
        break;
        case(67):
        cp5.getController("knobAD").setValue(controlvalue);
        break;
        case(68):
        cp5.getController("knobAE").setValue(controlvalue);
        break;
        case(69):
        cp5.getController("knobAF").setValue(controlvalue);
        break;
        case(70):
        cp5.getController("knobAG").setValue(controlvalue);
        break;
        case(71):
        cp5.get(Textfield.class, "beat").clear();
        cp5.get(Textfield.class, "beat").setText(str(int(controlvalue)));
        break;
        case(72):
        cp5.getController("toggleD").setValue(controlvalue);
        break;
        case(73):
        cp5.getController("knobAH").setValue(controlvalue);
        break;
        case(74):
        cp5.getController("knobAI").setValue(controlvalue);
        break;
        case(75):
        cp5.getController("knobAJ").setValue(controlvalue);
        break;
        case(76):
        cp5.getController("togL").setValue(controlvalue);
        break;
        case(77):
        cp5.getController("togM").setValue(controlvalue);
        break;
        case(78):
        cp5.getController("togN").setValue(controlvalue);
        break;
        case(79):
        cp5.getController("togO").setValue(controlvalue);
        break;
        case(80):
        cp5.getController("togP").setValue(controlvalue);
        break;
        case(81):
        cp5.getController("togQ").setValue(controlvalue);
        break;
        case(82):
        cp5.getController("togR").setValue(controlvalue);
        break;
        case(83):
        cp5.getController("togS").setValue(controlvalue);
        break;
        case(84):
        cp5.getController("togT").setValue(controlvalue);
        break;
        case(85):
        cp5.getController("togU").setValue(controlvalue);
        break;
        case(86):
        cp5.getController("togV").setValue(controlvalue);
        break;
        case(87):
        cp5.getController("togW").setValue(controlvalue);
        break;
        case(88):
        cp5.getController("togX").setValue(controlvalue);
        break;
        case(89):
        cp5.getController("togY").setValue(controlvalue);
        break;
        case(90):
        cp5.getController("togZ").setValue(controlvalue);
        break;
        case(91):
        cp5.getController("togAA").setValue(controlvalue);
        break;
        case(92):
        cp5.getController("knobAK").setValue(controlvalue);
        break;
        case(93):
        cp5.getController("knobAL").setValue(controlvalue);
        break;
        case(94):
        cp5.getController("knobAM").setValue(controlvalue);
        break;
        case(95):
        cp5.getController("knobAN").setValue(controlvalue);
        break;
        case(96):
        cp5.getController("togAB").setValue(controlvalue);
        break;
        case(97):
        cp5.getController("togAC").setValue(controlvalue);
        break;
        case(98):
        cp5.getController("togAD").setValue(controlvalue);
        break;
        case(99):
        cp5.getController("togAE").setValue(controlvalue);
        break;
        case(100):
        cp5.getController("togAF").setValue(controlvalue);
        break;
        case(101):
        cp5.getController("togAG").setValue(controlvalue);
        break;
        case(102):
        cp5.getController("togAH").setValue(controlvalue);
        break;
        case(103):
        cp5.getController("togAI").setValue(controlvalue);
        break;
        case(104):
        cp5.getController("togAJ").setValue(controlvalue);
        break;
        case(105):
        cp5.getController("togAK").setValue(controlvalue);
        break;
        case(106):
        cp5.getController("togAL").setValue(controlvalue);
        break;
        case(107):
        cp5.getController("togAM").setValue(controlvalue);
        break;
        case(108):
        cp5.getController("togAN").setValue(controlvalue);
        break;
        case(109):
        cp5.getController("togAO").setValue(controlvalue);
        break;
        case(110):
        cp5.getController("togAP").setValue(controlvalue);
        break;
        case(111):
        cp5.getController("togAQ").setValue(controlvalue);
        break;
        case(112):
        cp5.getController("toggleJ").setValue(controlvalue);
        break;
        case(116):
        cp5.getController("togAR").setValue(controlvalue);
        break;
        case(117):
        cp5.getController("togAS").setValue(controlvalue);
        break;
        case(118):
        cp5.getController("togAT").setValue(controlvalue);
        break;
        case(119):
        cp5.getController("togAU").setValue(controlvalue);
        break;
        case(120):
        cp5.getController("togAV").setValue(controlvalue);
        break;
        case(121):
        cp5.getController("togAW").setValue(controlvalue);
        break;
        case(122):
        cp5.getController("togAX").setValue(controlvalue);
        break;
        case(123):
        cp5.getController("togAY").setValue(controlvalue);
        break;
        case(124):
        cp5.getController("togAZ").setValue(controlvalue);
        break;
        case(125):
        cp5.getController("togBA").setValue(controlvalue);
        break;
        case(126):
        cp5.getController("togBB").setValue(controlvalue);
        break;
        case(127):
        cp5.getController("togBC").setValue(controlvalue);
        break;
        case(128):
        cp5.getController("togBD").setValue(controlvalue);
        break;
        case(129):
        cp5.getController("togBE").setValue(controlvalue);
        break;
        case(130):
        cp5.getController("togBF").setValue(controlvalue);
        break;
        case(131):
        cp5.getController("togBG").setValue(controlvalue);
        break;
        case(132):
        cp5.getController("togBH").setValue(controlvalue);
        break;
        case(133):
        cp5.getController("togBI").setValue(controlvalue);
        break;
        case(134):
        cp5.getController("togBJ").setValue(controlvalue);
        break;
        case(135):
        cp5.getController("togBK").setValue(controlvalue);
        break;
        case(136):
        cp5.getController("togBL").setValue(controlvalue);
        break;
        case(137):
        cp5.getController("togBM").setValue(controlvalue);
        break;
        case(138):
        cp5.getController("togBN").setValue(controlvalue);
        break;
        case(139):
        cp5.getController("togBO").setValue(controlvalue);
        break;
        case(140):
        cp5.getController("togBP").setValue(controlvalue);
        break;
        case(141):
        cp5.getController("togBQ").setValue(controlvalue);
        break;
        case(142):
        cp5.getController("togBR").setValue(controlvalue);
        break;
        case(143):
        cp5.getController("togBS").setValue(controlvalue);
        break;
        case(144):
        cp5.getController("togBT").setValue(controlvalue);
        break;
        case(145):
        cp5.getController("togBU").setValue(controlvalue);
        break;
        case(146):
        cp5.getController("togBV").setValue(controlvalue);
        break;
        case(147):
        cp5.getController("togBW").setValue(controlvalue);
        break;
        case(149):
        cp5.getController("toggleE").setValue(controlvalue);
        break;
        case(150):
        cp5.getController("toggleH").setValue(controlvalue);
        break;
        case(151):
        cp5.getController("listO").setValue(controlvalue);
        break;
        case(152):
        cp5.getController("toggleI").setValue(controlvalue);
        break;
        case(153):
        cp5.getController("listNA1").setValue(controlvalue);
        break;
        case(154):
        cp5.getController("listNA2").setValue(controlvalue);
        break;
        case(155):
        cp5.getController("listNA3").setValue(controlvalue);
        break;
        case(156):
        cp5.getController("listNA4").setValue(controlvalue);
        break;
        case(157):
        cp5.getController("listNA5").setValue(controlvalue);
        break;
        case(158):
        cp5.getController("listNA6").setValue(controlvalue);
        break;
        case(159):
        cp5.getController("listNA7").setValue(controlvalue);
        break;
        case(160):
        cp5.getController("listNA8").setValue(controlvalue);
        break;
        case(161):
        cp5.getController("listNA9").setValue(controlvalue);
        break;
        case(162):
        cp5.getController("listNA10").setValue(controlvalue);
        break;
        case(163):
        cp5.getController("listNA11").setValue(controlvalue);
        break;
        case(164):
        cp5.getController("listNA12").setValue(controlvalue);
        break;
        case(165):
        cp5.getController("listNA13").setValue(controlvalue);
        break;
        case(166):
        cp5.getController("listNA14").setValue(controlvalue);
        break;
        case(167):
        cp5.getController("listNA15").setValue(controlvalue);
        break;
        case(168):
        cp5.getController("listNA16").setValue(controlvalue);
        break;
        case(169):
        cp5.getController("listNB1").setValue(controlvalue);
        break;
        case(170):
        cp5.getController("listNB2").setValue(controlvalue);
        break;
        case(171):
        cp5.getController("listNB3").setValue(controlvalue);
        break;
        case(172):
        cp5.getController("listNB4").setValue(controlvalue);
        break;
        case(173):
        cp5.getController("listNB5").setValue(controlvalue);
        break;
        case(174):
        cp5.getController("listNB6").setValue(controlvalue);
        break;
        case(175):
        cp5.getController("listNB7").setValue(controlvalue);
        break;
        case(176):
        cp5.getController("listNB8").setValue(controlvalue);
        break;
        case(177):
        cp5.getController("listNB9").setValue(controlvalue);
        break;
        case(178):
        cp5.getController("listNB10").setValue(controlvalue);
        break;
        case(179):
        cp5.getController("listNB11").setValue(controlvalue);
        break;
        case(180):
        cp5.getController("listNB12").setValue(controlvalue);
        break;
        case(181):
        cp5.getController("listNB13").setValue(controlvalue);
        break;
        case(182):
        cp5.getController("listNB14").setValue(controlvalue);
        break;
        case(183):
        cp5.getController("listNB15").setValue(controlvalue);
        break;
        case(184):
        cp5.getController("listNB16").setValue(controlvalue);
        break;
        case(185):
        cp5.getController("listNC1").setValue(controlvalue);
        break;
        case(186):
        cp5.getController("listNC2").setValue(controlvalue);
        break;
        case(187):
        cp5.getController("listNC3").setValue(controlvalue);
        break;
        case(188):
        cp5.getController("listNC4").setValue(controlvalue);
        break;
        case(189):
        cp5.getController("listNC5").setValue(controlvalue);
        break;
        case(190):
        cp5.getController("listNC6").setValue(controlvalue);
        break;
        case(191):
        cp5.getController("listNC7").setValue(controlvalue);
        break;
        case(192):
        cp5.getController("listNC8").setValue(controlvalue);
        break;
        case(193):
        cp5.getController("listNC9").setValue(controlvalue);
        break;
        case(194):
        cp5.getController("listNC10").setValue(controlvalue);
        break;
        case(195):
        cp5.getController("listNC11").setValue(controlvalue);
        break;
        case(196):
        cp5.getController("listNC12").setValue(controlvalue);
        break;
        case(197):
        cp5.getController("listNC13").setValue(controlvalue);
        break;
        case(198):
        cp5.getController("listNC14").setValue(controlvalue);
        break;
        case(199):
        cp5.getController("listNC15").setValue(controlvalue);
        break;
        case(200):
        cp5.getController("listNC16").setValue(controlvalue);
        break;
        case(201):
        cp5.getController("listND1").setValue(controlvalue);
        break;
        case(202):
        cp5.getController("listND2").setValue(controlvalue);
        break;
        case(203):
        cp5.getController("listND3").setValue(controlvalue);
        break;
        case(204):
        cp5.getController("listND4").setValue(controlvalue);
        break;
        case(205):
        cp5.getController("listND5").setValue(controlvalue);
        break;
        case(206):
        cp5.getController("listND6").setValue(controlvalue);
        break;
        case(207):
        cp5.getController("listND7").setValue(controlvalue);
        break;
        case(208):
        cp5.getController("listND8").setValue(controlvalue);
        break;
        case(209):
        cp5.getController("listND9").setValue(controlvalue);
        break;
        case(210):
        cp5.getController("listND10").setValue(controlvalue);
        break;
        case(211):
        cp5.getController("listND11").setValue(controlvalue);
        break;
        case(212):
        cp5.getController("listND12").setValue(controlvalue);
        break;
        case(213):
        cp5.getController("listND13").setValue(controlvalue);
        break;
        case(214):
        cp5.getController("listND14").setValue(controlvalue);
        break;
        case(215):
        cp5.getController("listND15").setValue(controlvalue);
        break;
        case(216):
        cp5.getController("listND16").setValue(controlvalue);
        break;
        case(217):
        cp5.getController("knobLock").setValue(controlvalue);
        break;
        case(218):
        cp5.getController("toggleK").setValue(controlvalue);
        break;
        case(219):
        cp5.getController("toggleL").setValue(controlvalue);
        break;
        //phasegain start
        case(1001):
        cp5.getController("NA1").setValue(controlvalue);
        break;
        case(1002):
        cp5.getController("NA2").setValue(controlvalue);
        break;
        case(1003):
        cp5.getController("NA3").setValue(controlvalue);
        break;
        case(1004):
        cp5.getController("NA4").setValue(controlvalue);
        break;
        case(1005):
        cp5.getController("NA5").setValue(controlvalue);
        break;
        case(1006):
        cp5.getController("NA6").setValue(controlvalue);
        break;
        case(1007):
        cp5.getController("NA7").setValue(controlvalue);
        break;
        case(1008):
        cp5.getController("NA8").setValue(controlvalue);
        break;
        case(1009):
        cp5.getController("NA9").setValue(controlvalue);
        break;
        case(1010):
        cp5.getController("NA10").setValue(controlvalue);
        break;
        case(1011):
        cp5.getController("NA11").setValue(controlvalue);
        break;
        case(1012):
        cp5.getController("NA12").setValue(controlvalue);
        break;
        case(1013):
        cp5.getController("NA13").setValue(controlvalue);
        break;
        case(1014):
        cp5.getController("NA14").setValue(controlvalue);
        break;
        case(1015):
        cp5.getController("NA15").setValue(controlvalue);
        break;
        case(1016):
        cp5.getController("NA16").setValue(controlvalue);
        break;
        case(1017):
        cp5.getController("NA17").setValue(controlvalue);
        break;
        case(1018):
        cp5.getController("NA18").setValue(controlvalue);
        break;
        case(1019):
        cp5.getController("NA19").setValue(controlvalue);
        break;
        case(1020):
        cp5.getController("NA20").setValue(controlvalue);
        break;
        case(1021):
        cp5.getController("NA21").setValue(controlvalue);
        break;
        case(1022):
        cp5.getController("NA22").setValue(controlvalue);
        break;
        case(1023):
        cp5.getController("NB1").setValue(controlvalue);
        break;
        case(1024):
        cp5.getController("NB2").setValue(controlvalue);
        break;
        case(1025):
        cp5.getController("NB3").setValue(controlvalue);
        break;
        case(1026):
        cp5.getController("NB4").setValue(controlvalue);
        break;
        case(1027):
        cp5.getController("NB5").setValue(controlvalue);
        break;
        case(1028):
        cp5.getController("NB6").setValue(controlvalue);
        break;
        case(1029):
        cp5.getController("NB7").setValue(controlvalue);
        break;
        case(1030):
        cp5.getController("NB8").setValue(controlvalue);
        break;
        case(1031):
        cp5.getController("NB9").setValue(controlvalue);
        break;
        case(1032):
        cp5.getController("NB10").setValue(controlvalue);
        break;
        case(1033):
        cp5.getController("NB11").setValue(controlvalue);
        break;
        case(1034):
        cp5.getController("NB12").setValue(controlvalue);
        break;
        case(1035):
        cp5.getController("NB13").setValue(controlvalue);
        break;
        case(1036):
        cp5.getController("NB14").setValue(controlvalue);
        break;
        case(1037):
        cp5.getController("NB15").setValue(controlvalue);
        break;
        case(1038):
        cp5.getController("NB16").setValue(controlvalue);
        break;
        case(1039):
        cp5.getController("NB17").setValue(controlvalue);
        break;
        case(1040):
        cp5.getController("NB18").setValue(controlvalue);
        break;
        case(1041):
        cp5.getController("NB19").setValue(controlvalue);
        break;
        case(1042):
        cp5.getController("NB20").setValue(controlvalue);
        break;
        case(1043):
        cp5.getController("NB21").setValue(controlvalue);
        break;
        case(1044):
        cp5.getController("NB22").setValue(controlvalue);
        break;
        case(1045):
        cp5.getController("NC1").setValue(controlvalue);
        break;
        case(1046):
        cp5.getController("NC2").setValue(controlvalue);
        break;
        case(1047):
        cp5.getController("NC3").setValue(controlvalue);
        break;
        case(1048):
        cp5.getController("NC4").setValue(controlvalue);
        break;
        case(1049):
        cp5.getController("NC5").setValue(controlvalue);
        break;
        case(1050):
        cp5.getController("NC6").setValue(controlvalue);
        break;
        case(1051):
        cp5.getController("NC7").setValue(controlvalue);
        break;
        case(1052):
        cp5.getController("NC8").setValue(controlvalue);
        break;
        case(1053):
        cp5.getController("NC9").setValue(controlvalue);
        break;
        case(1054):
        cp5.getController("NC10").setValue(controlvalue);
        break;
        case(1055):
        cp5.getController("NC11").setValue(controlvalue);
        break;
        case(1056):
        cp5.getController("NC12").setValue(controlvalue);
        break;
        case(1057):
        cp5.getController("NC13").setValue(controlvalue);
        break;
        case(1058):
        cp5.getController("NC14").setValue(controlvalue);
        break;
        case(1059):
        cp5.getController("NC15").setValue(controlvalue);
        break;
        case(1060):
        cp5.getController("NC16").setValue(controlvalue);
        break;
        case(1061):
        cp5.getController("NC17").setValue(controlvalue);
        break;
        case(1062):
        cp5.getController("NC18").setValue(controlvalue);
        break;
        case(1063):
        cp5.getController("NC19").setValue(controlvalue);
        break;
        case(1064):
        cp5.getController("NC20").setValue(controlvalue);
        break;
        case(1065):
        cp5.getController("NC21").setValue(controlvalue);
        break;
        case(1066):
        cp5.getController("NC22").setValue(controlvalue);
        break;
      }


      //****** pure byte data transmission
      if (saveafile==true)
      {
        //print("saving a file");
        if ((controlindex>299)&&(controlindex<520))
        {
          //println(controlindex);
          presetdata=presetdata+" "+str(controlvalue);
        }
        if (controlindex==517)
        {
          saveafile=false;
          //println(presetdata);
          String[] listy = split(presetdata, ' ');

          String savefilename=cp5.get(Textfield.class, "save file name").getText();
          if (savefilename.isEmpty()==false)
          {
            saveStrings(savefilename, listy);
          }
        }
      }//save a file
    }
  }//data on my port
}//end of draw

//******************************************************************
//
//functions
//
//******************************************************************

//****************************************************************
//control events transmisions
//****************************************************************

//port select tab events *******************************************

void listA(int theValue)
{
  /* request the selected item based on index n */
  //first clear the old port
  if (myPort != null)
  {
    myPort.clear(); //delete the port
    myPort.stop(); //stop the port
  }
  String portName = Serial.list()[theValue]; //change the 0 to a 1 or 2 etc. to match your port
  myPort = new Serial(this, portName, 38400);
  if (myPort != null) myPort.write("148,"+"1" +" "); //update controls on GUI
}

//ambience control events***************************


void knobA(int theValue)// glide rate
{
  if (myPort != null) myPort.write("1,"+str(theValue)+" ");
}

void knobB(int theValue)// reverb wet
{
  if (myPort != null) myPort.write("2,"+str(theValue)+" ");
}

void listB(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("3,"+a +" ");
}

void toggleA (boolean theFlag)//
{
  String a;
  if (theFlag==false) a="0";
  else a="1";
  if (myPort != null) myPort.write("4,"+a+" ");
}

void monvolume (int theValue)//
{
  if (myPort != null) myPort.write("5,"+str(theValue) +" ");
}

void knobC(int theValue)// rain gain
{
  if (myPort != null) myPort.write("6,"+str(theValue)+" ");
}

void knobD(int theValue)// shimmergain
{
  if (myPort != null) myPort.write("7,"+str(theValue)+" ");
}

void toggleB (boolean theFlag)
{
  String a;
  if (theFlag==false) a="0";
  else a="1";
  if (myPort != null) myPort.write("8,"+a+" ");
}

//void listC(int theValue) //
//{
//  String a = str(theValue);
//  if (myPort != null) myPort.write("9,"+a +" ");
//}

//waveform control events************************************

//melody****************************************************

void knobE(int theValue)// mel filter
{
  if (myPort != null) myPort.write("13,"+str(theValue)+" ");
}

void knobF(int theValue)// mel volume
{
  if (myPort != null) myPort.write("18,"+str(theValue)+" ");
}

void listD(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("11,"+a +" ");
}

void listE(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("12,"+a +" ");
}

void sliderA(int theValue)
{
  String a = str(theValue);
  if (myPort != null) myPort.write("14,"+a +" ");
}

void sliderB(int theValue)
{
  String a = str(theValue);
  if (myPort != null) myPort.write("15,"+a +" ");
}

void sliderC(int theValue)
{
  String a = str(theValue);
  if (myPort != null) myPort.write("16,"+a +" ");
}

void sliderD(int theValue)
{
  String a = str(theValue);
  if (myPort != null) myPort.write("17,"+a +" ");
}

//harmony1***********************************************

void knobG(int theValue)// glide rate
{
  if (myPort != null) myPort.write("21,"+str(theValue)+" ");
}

void knobH(int theValue)// reverb wet
{
  if (myPort != null) myPort.write("26,"+str(theValue)+" ");
}

void listF(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("19,"+a +" ");
}

void listG(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("20,"+a +" ");
}

void sliderE(int theValue)
{
  String a = str(theValue);
  if (myPort != null) myPort.write("22,"+a +" ");
}

void sliderF(int theValue)
{
  String a = str(theValue);
  if (myPort != null) myPort.write("23,"+a +" ");
}

void sliderG(int theValue)
{
  String a = str(theValue);
  if (myPort != null) myPort.write("24,"+a +" ");
}

void sliderH(int theValue)
{
  String a = str(theValue);
  if (myPort != null) myPort.write("25,"+a +" ");
}

//harmony2***********************************************

void knobI(int theValue)// glide rate
{
  if (myPort != null) myPort.write("29,"+str(theValue)+" ");
}

void knobJ(int theValue)// reverb wet
{
  if (myPort != null) myPort.write("34,"+str(theValue)+" ");
}

void listH(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("27,"+a +" ");
}

void listI(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("28,"+a +" ");
}

void sliderI(int theValue)
{
  String a = str(theValue);
  if (myPort != null) myPort.write("30,"+a +" ");
}

void sliderJ(int theValue)
{
  String a = str(theValue);
  if (myPort != null) myPort.write("31,"+a +" ");
}

void sliderK(int theValue)
{
  String a = str(theValue);
  if (myPort != null) myPort.write("32,"+a +" ");
}

void sliderL(int theValue)
{
  String a = str(theValue);
  if (myPort != null) myPort.write("33,"+a +" ");
}

//strings**********************************************


void knobK(int theValue)// glide rate
{
  if (myPort != null) myPort.write("36,"+str(theValue)+" ");
}

void knobL(int theValue)// reverb wet
{
  if (myPort != null) myPort.write("38,"+str(theValue)+" ");
}

void listJ(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("37,"+a +" ");
}

void listK(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("39,"+a +" ");
}

//background controls

void toggleF(int theValue) //stick override
{
  String a = str(theValue);
  if (myPort != null) myPort.write("40,"+a +" ");
}

void listL(int theValue) //button logic
{
  String a = str(theValue);
  if (myPort != null) myPort.write("41,"+a +" ");
}

void toggleG(int theValue) //drums on
{
  String a = str(theValue);
  if (myPort != null) myPort.write("42,"+a +" ");
}

void listM(int theValue) //chord type
{
  String a = str(theValue);
  if (myPort != null) myPort.write("44,"+a +" ");
}

void listN(int theValue) //progression type
{
  String a = str(theValue);
  if (myPort != null) myPort.write("45,"+a +" ");
}

void knobAO(int theValue) //fade in
{
  String a = str(theValue);
  if (myPort != null) myPort.write("46,"+a +" ");
}

void listAP(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("47,"+a +" ");
}



//drum controls***************************************************
//drum sounds

//void toggleC(boolean theFlag)//
//{
//  String a;
//  if (theFlag==false) a="0";
//  else a="1";
//  if (myPort != null) myPort.write("49,"+a+" ");
//}

void knobM(int theValue)//
{
  if (myPort != null)
  {
    espeedMSB=int(theValue/256);
    espeedLSB=theValue-(256*espeedMSB);
    myPort.write("48,"+espeedLSB +" ");
    myPort.write("50,"+espeedMSB +" ");
  }
}
void knobN(int theValue)//
{
  if (myPort != null) myPort.write("51,"+theValue +" ");
}
void knobO(int theValue)//
{
  if (myPort != null) myPort.write("52,"+theValue +" ");
}
void knobP(int theValue)//
{
  if (myPort != null) myPort.write("53,"+theValue +" ");
}
void knobQ(int theValue)//
{
  if (myPort != null) myPort.write("54,"+theValue +" ");
}
void knobR(int theValue)//
{
  if (myPort != null) myPort.write("55,"+theValue +" ");
}
void knobS(int theValue)//
{
  if (myPort != null) myPort.write("56,"+theValue +" ");
}
void knobT(int theValue)//
{
  if (myPort != null) myPort.write("57,"+theValue +" ");
}
void knobU(int theValue)//
{
  if (myPort != null) myPort.write("58,"+theValue +" ");
}
void knobV(int theValue)//
{
  if (myPort != null) myPort.write("59,"+theValue +" ");
}
void knobW(int theValue)//
{
  if (myPort != null) myPort.write("60,"+theValue +" ");
}
void knobX(int theValue)//
{
  if (myPort != null) myPort.write("61,"+theValue +" ");
}
void knobY(int theValue)//
{
  if (myPort != null) myPort.write("62,"+theValue +" ");
}
void knobZ(int theValue)//
{
  if (myPort != null) myPort.write("63,"+theValue +" ");
}
void knobAA(int theValue)//
{
  if (myPort != null) myPort.write("64,"+theValue +" ");
}
void knobAB(int theValue)//
{
  if (myPort != null) myPort.write("65,"+theValue +" ");
}
void knobAC(int theValue)//
{
  if (myPort != null) myPort.write("66,"+theValue +" ");
}
void knobAD(int theValue)//
{
  if (myPort != null) myPort.write("67,"+theValue +" ");
}
void knobAE(int theValue)//
{
  if (myPort != null) myPort.write("68,"+theValue +" ");
}
void knobAF(int theValue)//
{
  if (myPort != null) myPort.write("69,"+theValue +" ");
}
void knobAG(int theValue)//
{
  if (myPort != null) myPort.write("70,"+theValue +" ");
}

void toggleD(boolean theFlag)// spin euclid series
{
  String a;
  if (theFlag==false) a="0";
  else a="1";
  if (myPort != null) myPort.write("72,"+a+" ");
}
void knobAH(int theValue)//
{
  if (myPort != null) myPort.write("73,"+theValue +" ");
}
void knobAI(int theValue)//
{
  if (myPort != null) myPort.write("74,"+theValue +" ");
}
void knobAJ(int theValue)//
{

  if (myPort != null) myPort.write("75,"+theValue +" ");
}
void togL(int theValue)//
{
  String a = str(theValue);
  if (myPort != null) myPort.write("76,"+a +" ");
}
void togM(int theValue)//
{
  String a = str(theValue);
  if (myPort != null) myPort.write("77,"+a +" ");
}
void togN(int theValue)//
{
  String a = str(theValue);
  if (myPort != null) myPort.write("78,"+a +" ");
}
void togO(int theValue)//
{
  String a = str(theValue);
  if (myPort != null) myPort.write("79,"+a +" ");
}
void togP(int theValue)//
{
  String a = str(theValue);
  if (myPort != null) myPort.write("80,"+a +" ");
}
void togQ(int theValue)//
{
  String a = str(theValue);
  if (myPort != null) myPort.write("81,"+a +" ");
}
void togR(int theValue)//
{
  String a = str(theValue);
  if (myPort != null) myPort.write("82,"+a +" ");
}
void togS(int theValue)//
{
  String a = str(theValue);
  if (myPort != null) myPort.write("83,"+a +" ");
}
void togT(int theValue)//
{
  String a = str(theValue);
  if (myPort != null) myPort.write("84,"+a +" ");
}
void togU(int theValue)//
{
  String a = str(theValue);
  if (myPort != null) myPort.write("85,"+a +" ");
}
void togV(int theValue)//
{
  String a = str(theValue);
  if (myPort != null) myPort.write("86,"+a +" ");
}
void togW(int theValue)//
{
  String a = str(theValue);
  if (myPort != null) myPort.write("87,"+a +" ");
}
void togX(int theValue)//
{
  String a = str(theValue);
  if (myPort != null) myPort.write("88,"+a +" ");
}
void togY(int theValue)//
{
  String a = str(theValue);
  if (myPort != null) myPort.write("89,"+a +" ");
}
void togZ(int theValue)//
{
  String a = str(theValue);
  if (myPort != null) myPort.write("90,"+a +" ");
}
void togAA(int theValue)//
{
  String a = str(theValue);
  if (myPort != null) myPort.write("91,"+a +" ");
}

void knobAK(int theValue)//
{
  String a = str(theValue);
  if (myPort != null) myPort.write("92,"+a +" ");
}

void knobAL(int theValue)//
{
  String a = str(theValue);
  if (myPort != null) myPort.write("93,"+a +" ");
}

void knobAM(int theValue)//
{
  String a = str(theValue);
  if (myPort != null) myPort.write("94,"+a +" ");
}

void knobAN(int theValue)//
{
  String a = str(theValue);
  if (myPort != null) myPort.write("95,"+a +" ");
}

//second row of buttons
void togAB(int theValue)//
{
  String a = str(theValue);
  if (myPort != null) myPort.write("96,"+a +" ");
}
void togAC(int theValue)//
{
  String a = str(theValue);
  if (myPort != null) myPort.write("97,"+a +" ");
}
void togAD(int theValue)//
{
  String a = str(theValue);
  if (myPort != null) myPort.write("98,"+a +" ");
}
void togAE(int theValue)//
{
  String a = str(theValue);
  if (myPort != null) myPort.write("99,"+a +" ");
}
void togAF(int theValue)//
{
  String a = str(theValue);
  if (myPort != null) myPort.write("100,"+a +" ");
}
void togAG(int theValue)//
{
  String a = str(theValue);
  if (myPort != null) myPort.write("101,"+a +" ");
}
void togAH(int theValue)//
{
  String a = str(theValue);
  if (myPort != null) myPort.write("102,"+a +" ");
}
void togAI(int theValue)//
{
  String a = str(theValue);
  if (myPort != null) myPort.write("103,"+a +" ");
}
void togAJ(int theValue)//
{
  String a = str(theValue);
  if (myPort != null) myPort.write("104,"+a +" ");
}
void togAK(int theValue)//
{
  String a = str(theValue);
  if (myPort != null) myPort.write("105,"+a +" ");
}
void togAL(int theValue)//
{
  String a = str(theValue);
  if (myPort != null) myPort.write("106,"+a +" ");
}
void togAM(int theValue)//
{
  String a = str(theValue);
  if (myPort != null) myPort.write("107,"+a +" ");
}
void togAN(int theValue)//
{
  String a = str(theValue);
  if (myPort != null) myPort.write("108,"+a +" ");
}
void togAO(int theValue)//
{
  String a = str(theValue);
  if (myPort != null) myPort.write("109,"+a +" ");
}
void togAP(int theValue)//
{
  String a = str(theValue);
  if (myPort != null) myPort.write("110,"+a +" ");
}
void togAQ(int theValue)//
{
  String a = str(theValue);
  if (myPort != null) myPort.write("111,"+a +" ");
}

//third row of buttons

void togAR(int theValue)//
{
  String a = str(theValue);
  if (myPort != null) myPort.write("116,"+a +" ");
}
void togAS(int theValue)//
{
  String a = str(theValue);
  if (myPort != null) myPort.write("117,"+a +" ");
}
void togAT(int theValue)//
{
  String a = str(theValue);
  if (myPort != null) myPort.write("118,"+a +" ");
}
void togAU(int theValue)//
{
  String a = str(theValue);
  if (myPort != null) myPort.write("119,"+a +" ");
}
void togAV(int theValue)//
{
  String a = str(theValue);
  if (myPort != null) myPort.write("120,"+a +" ");
}
void togAW(int theValue)//
{
  String a = str(theValue);
  if (myPort != null) myPort.write("121,"+a +" ");
}
void togAX(int theValue)//
{
  String a = str(theValue);
  if (myPort != null) myPort.write("122,"+a +" ");
}
void togAY(int theValue)//
{
  String a = str(theValue);
  if (myPort != null) myPort.write("123,"+a +" ");
}
void togAZ(int theValue)//
{
  String a = str(theValue);
  if (myPort != null) myPort.write("124,"+a +" ");
}
void togBA(int theValue)//
{
  String a = str(theValue);
  if (myPort != null) myPort.write("125,"+a +" ");
}
void togBB(int theValue)//
{
  String a = str(theValue);
  if (myPort != null) myPort.write("126,"+a +" ");
}
void togBC(int theValue)//
{
  String a = str(theValue);
  if (myPort != null) myPort.write("127,"+a +" ");
}
void togBD(int theValue)//
{
  String a = str(theValue);
  if (myPort != null) myPort.write("128,"+a +" ");
}
void togBE(int theValue)//
{
  String a = str(theValue);
  if (myPort != null) myPort.write("129,"+a +" ");
}
void togBF(int theValue)//
{
  String a = str(theValue);
  if (myPort != null) myPort.write("130,"+a +" ");
}
void togBG(int theValue)//
{
  String a = str(theValue);
  if (myPort != null) myPort.write("131,"+a +" ");
}

//fourth row of buttons

void togBH(int theValue)//
{
  String a = str(theValue);
  if (myPort != null) myPort.write("132,"+a +" ");
}
void togBI(int theValue)//
{
  String a = str(theValue);
  if (myPort != null) myPort.write("133,"+a +" ");
}
void togBJ(int theValue)//
{
  String a = str(theValue);
  if (myPort != null) myPort.write("134,"+a +" ");
}
void togBK(int theValue)//
{
  String a = str(theValue);
  if (myPort != null) myPort.write("135,"+a +" ");
}
void togBL(int theValue)//
{
  String a = str(theValue);
  if (myPort != null) myPort.write("136,"+a +" ");
}
void togBM(int theValue)//
{
  String a = str(theValue);
  if (myPort != null) myPort.write("137,"+a +" ");
}
void togBN(int theValue)//
{
  String a = str(theValue);
  if (myPort != null) myPort.write("138,"+a +" ");
}
void togBO(int theValue)//
{
  String a = str(theValue);
  if (myPort != null) myPort.write("139,"+a +" ");
}
void togBP(int theValue)//
{
  String a = str(theValue);
  if (myPort != null) myPort.write("140,"+a +" ");
}
void togBQ(int theValue)//
{
  String a = str(theValue);
  if (myPort != null) myPort.write("141,"+a +" ");
}
void togBR(int theValue)//
{
  String a = str(theValue);
  if (myPort != null) myPort.write("142,"+a +" ");
}
void togBS(int theValue)//
{
  String a = str(theValue);
  if (myPort != null) myPort.write("143,"+a +" ");
}
void togBT(int theValue)//
{
  String a = str(theValue);
  if (myPort != null) myPort.write("144,"+a +" ");
}
void togBU(int theValue)//
{
  String a = str(theValue);
  if (myPort != null) myPort.write("145,"+a +" ");
}
void togBV(int theValue)//
{
  String a = str(theValue);
  if (myPort != null) myPort.write("146,"+a +" ");
}
void togBW(int theValue)//
{
  String a = str(theValue);
  if (myPort != null) myPort.write("147,"+a +" ");
}

void toggleE(boolean theFlag)//save settings to disk
{
  if (theFlag==true)
  {
    if (myPort != null)
    {
      myPort.write("149,"+"1" +" "); //tell teensy to dump byte values
      saveafile=true;//set to save file
      presetdata="";
    }
  }
}

void toggleH(boolean theFlag)//save a file
{
  if (theFlag==true)
  {
    if (myPort != null)
    {
      myPort.write("150,"+str(saveSlot) +" "); //tell teensy to save to eeprom
    }
  }
}

void listO(int theValue) //save to eeprom
{
  saveSlot=theValue;//save eeprom locaton
  String a = str(theValue);
  if (myPort != null) myPort.write("151,"+a +" "); // send slot for saving
}

void toggleI(boolean theFlag)// resest this color
{
  if (theFlag==true)
  {
    if (myPort != null)
    {
      myPort.write("152,"+str(saveSlot) +" "); //reset to factory preset
    }
  }
}


void toggleJ(boolean theValue)//load a preset and send to teensy
{
  if ((myPort != null) && (theValue==true))
  {
    String filename=cp5.get(Textfield.class, "load file name").getText();
    if (filename.isEmpty()==false)
    {
      //print("filename:");
      //println(filename);
      //print("data in lines:");
      lines =loadStrings(filename);
      if (lines!=null)
      {
        for (int x=0; x<218; x++)
        {
          lines[x]=lines[x+1];
          //print(" ");
          //print(lines[x]);
        }
        FileLoadUpdate();       
      }
    }
  }
}

void toggleK(boolean theFlag)//save phase settngs to eeprom
{
  if (theFlag==true)
  {
    if (myPort != null)
    {
      myPort.write("218,"+"1" +" "); //tell teensy to save phase settings to eeprom
    }
  }
}

void toggleL(boolean theFlag)// resest phase settings
{
  if (theFlag==true)
  {
    if (myPort != null)
    {
      myPort.write("219,"+"1" +" "); //reset phase settings to factory preset
    }
  }
}
//backup

//chord1

void listNA1(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("153,"+a +" ");
}

void listNA2(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("154,"+a +" ");
}

void listNA3(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("155,"+a +" ");
}

void listNA4(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("156,"+a +" ");
}

void listNA5(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("157,"+a +" ");
}

void listNA6(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("158,"+a +" ");
}

void listNA7(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("159,"+a +" ");
}

void listNA8(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("160,"+a +" ");
}

void listNA9(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("161,"+a +" ");
}

void listNA10(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("162,"+a +" ");
}

void listNA11(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("163,"+a +" ");
}

void listNA12(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("164,"+a +" ");
}

void listNA13(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("165,"+a +" ");
}

void listNA14(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("166,"+a +" ");
}

void listNA15(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("167,"+a +" ");
}

void listNA16(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("168,"+a +" ");
}



//backup

//chord2

void listNB1(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("169,"+a +" ");
}
void listNB2(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("170,"+a +" ");
}

void listNB3(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("171,"+a +" ");
}

void listNB4(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("172,"+a +" ");
}

void listNB5(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("173,"+a +" ");
}

void listNB6(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("174,"+a +" ");
}

void listNB7(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("175,"+a +" ");
}

void listNB8(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("176,"+a +" ");
}

void listNB9(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("177,"+a +" ");
}

void listNB10(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("178,"+a +" ");
}

void listNB11(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("179,"+a +" ");
}

void listNB12(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("180,"+a +" ");
}

void listNB13(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("181,"+a +" ");
}

void listNB14(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("182,"+a +" ");
}

void listNB15(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("183,"+a +" ");
}

void listNB16(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("184,"+a +" ");
}



//chord4

void listNC1(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("185,"+a +" ");
}
void listNC2(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("186,"+a +" ");
}

void listNC3(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("187,"+a +" ");
}

void listNC4(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("188,"+a +" ");
}

void listNC5(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("189,"+a +" ");
}

void listNC6(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("190,"+a +" ");
}

void listNC7(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("191,"+a +" ");
}

void listNC8(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("192,"+a +" ");
}

void listNC9(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("193,"+a +" ");
}

void listNC10(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("194,"+a +" ");
}

void listNC11(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("195,"+a +" ");
}

void listNC12(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("196,"+a +" ");
}

void listNC13(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("197,"+a +" ");
}

void listNC14(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("198,"+a +" ");
}

void listNC15(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("199,"+a +" ");
}

void listNC16(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("200,"+a +" ");
}


//backup

//chord4

void listND1(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("201,"+a +" ");
}
void listND2(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("202,"+a +" ");
}

void listND3(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("203,"+a +" ");
}

void listND4(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("204,"+a +" ");
}

void listND5(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("205,"+a +" ");
}

void listND6(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("206,"+a +" ");
}

void listND7(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("207,"+a +" ");
}

void listND8(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("208,"+a +" ");
}

void listND9(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("209,"+a +" ");
}

void listND10(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("210,"+a +" ");
}

void listND11(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("211,"+a +" ");
}

void listND12(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("212,"+a +" ");
}

void listND13(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("213,"+a +" ");
}

void listND14(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("214,"+a +" ");
}

void listND15(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("215,"+a +" ");
}

void listND16(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("216,"+a +" ");
}

void knobLock(int theValue)// lock chord player
{
  if (myPort != null) myPort.write("217,"+str(theValue)+" ");
}

//phase data


void NA1(int theValue)
{
  if (myPort != null) myPort.write("1001,"+str(theValue)+" ");
}

void NA2(int theValue)
{
  if (myPort != null) myPort.write("1002,"+str(theValue)+" ");
}
void NA3(int theValue)
{
  if (myPort != null) myPort.write("1003,"+str(theValue)+" ");
}

void NA4(int theValue)
{
  if (myPort != null) myPort.write("1004,"+str(theValue)+" ");
}

void NA5(int theValue)
{
  if (myPort != null) myPort.write("1005,"+str(theValue)+" ");
}

void NA6(int theValue)
{
  if (myPort != null) myPort.write("1006,"+str(theValue)+" ");
}

void NA7(int theValue)
{
  if (myPort != null) myPort.write("1007,"+str(theValue)+" ");
}

void NA8(int theValue)
{
  if (myPort != null) myPort.write("1008,"+str(theValue)+" ");
}

void NA9(int theValue)
{
  if (myPort != null) myPort.write("1009,"+str(theValue)+" ");
}

void NA10(int theValue)
{
  if (myPort != null) myPort.write("1010,"+str(theValue)+" ");
}

void NA11(int theValue)
{
  if (myPort != null) myPort.write("1011,"+str(theValue)+" ");
}

void NA12(int theValue)
{
  if (myPort != null) myPort.write("1012,"+str(theValue)+" ");
}

void NA13(int theValue)
{
  if (myPort != null) myPort.write("1013,"+str(theValue)+" ");
}

void NA14(int theValue)
{
  if (myPort != null) myPort.write("1014,"+str(theValue)+" ");
}

void NA15(int theValue)
{
  if (myPort != null) myPort.write("1015,"+str(theValue)+" ");
}

void NA16(int theValue)
{
  if (myPort != null) myPort.write("1016,"+str(theValue)+" ");
}

void NA17(int theValue)
{
  if (myPort != null) myPort.write("1017,"+str(theValue)+" ");
}

void NA18(int theValue)
{
  if (myPort != null) myPort.write("1018,"+str(theValue)+" ");
}

void NA19(int theValue)
{
  if (myPort != null) myPort.write("1019,"+str(theValue)+" ");
}

void NA20(int theValue)
{
  if (myPort != null) myPort.write("1020,"+str(theValue)+" ");
}

void NA21(int theValue)
{
  if (myPort != null) myPort.write("1021,"+str(theValue)+" ");
}

void NA22(int theValue)
{
  if (myPort != null) myPort.write("1022,"+str(theValue)+" ");
}



void NB1(int theValue)
{
  if (myPort != null) myPort.write("1023,"+str(theValue)+" ");
}

void NB2(int theValue)
{
  if (myPort != null) myPort.write("1024,"+str(theValue)+" ");
}

void NB3(int theValue)
{
  if (myPort != null) myPort.write("1025,"+str(theValue)+" ");
}

void NB4(int theValue)
{
  if (myPort != null) myPort.write("1026,"+str(theValue)+" ");
}

void NB5(int theValue)
{
  if (myPort != null) myPort.write("1027,"+str(theValue)+" ");
}

void NB6(int theValue)
{
  if (myPort != null) myPort.write("1028,"+str(theValue)+" ");
}

void NB7(int theValue)
{
  if (myPort != null) myPort.write("1029,"+str(theValue)+" ");
}

void NB8(int theValue)
{
  if (myPort != null) myPort.write("1030,"+str(theValue)+" ");
}

void NB9(int theValue)
{
  if (myPort != null) myPort.write("1031,"+str(theValue)+" ");
}

void NB10(int theValue)
{
  if (myPort != null) myPort.write("1032,"+str(theValue)+" ");
}

void NB11(int theValue)
{
  if (myPort != null) myPort.write("1033,"+str(theValue)+" ");
}

void NB12(int theValue)
{
  if (myPort != null) myPort.write("1034,"+str(theValue)+" ");
}

void NB13(int theValue)
{
  if (myPort != null) myPort.write("1035,"+str(theValue)+" ");
}

void NB14(int theValue)
{
  if (myPort != null) myPort.write("1036,"+str(theValue)+" ");
}

void NB15(int theValue)
{
  if (myPort != null) myPort.write("1037,"+str(theValue)+" ");
}

void NB16(int theValue)
{
  if (myPort != null) myPort.write("1038,"+str(theValue)+" ");
}

void NB17(int theValue)
{
  if (myPort != null) myPort.write("1039,"+str(theValue)+" ");
}

void NB18(int theValue)
{
  if (myPort != null) myPort.write("1040,"+str(theValue)+" ");
}

void NB19(int theValue)
{
  if (myPort != null) myPort.write("1041,"+str(theValue)+" ");
}

void NB20(int theValue)
{
  if (myPort != null) myPort.write("1042,"+str(theValue)+" ");
}

void NB21(int theValue)
{
  if (myPort != null) myPort.write("1043,"+str(theValue)+" ");
}

void NB22(int theValue)
{
  if (myPort != null) myPort.write("1044,"+str(theValue)+" ");
}


void NC1(int theValue)
{
  if (myPort != null) myPort.write("1045,"+str(theValue)+" ");
}

void NC2(int theValue)
{
  if (myPort != null) myPort.write("1046,"+str(theValue)+" ");
}

void NC3(int theValue)
{
  if (myPort != null) myPort.write("1047,"+str(theValue)+" ");
}

void NC4(int theValue)
{
  if (myPort != null) myPort.write("1048,"+str(theValue)+" ");
}

void NC5(int theValue)
{
  if (myPort != null) myPort.write("1049,"+str(theValue)+" ");
}

void NC6(int theValue)
{
  if (myPort != null) myPort.write("1050,"+str(theValue)+" ");
}

void NC7(int theValue)
{
  if (myPort != null) myPort.write("1051,"+str(theValue)+" ");
}

void NC8(int theValue)
{
  if (myPort != null) myPort.write("1052,"+str(theValue)+" ");
}

void NC9(int theValue)
{
  if (myPort != null) myPort.write("1053,"+str(theValue)+" ");
}

void NC10(int theValue)
{
  if (myPort != null) myPort.write("1054,"+str(theValue)+" ");
}

void NC11(int theValue)
{
  if (myPort != null) myPort.write("1055,"+str(theValue)+" ");
}

void NC12(int theValue)
{
  if (myPort != null) myPort.write("1056,"+str(theValue)+" ");
}

void NC13(int theValue)
{
  if (myPort != null) myPort.write("1057,"+str(theValue)+" ");
}

void NC14(int theValue)
{
  if (myPort != null) myPort.write("1058,"+str(theValue)+" ");
}

void NC15(int theValue)
{
  if (myPort != null) myPort.write("1059,"+str(theValue)+" ");
}

void NC16(int theValue)
{
  if (myPort != null) myPort.write("1060,"+str(theValue)+" ");
}

void NC17(int theValue)
{
  if (myPort != null) myPort.write("1061,"+str(theValue)+" ");
}

void NC18(int theValue)
{
  if (myPort != null) myPort.write("1062,"+str(theValue)+" ");
}

void NC19(int theValue)
{
  if (myPort != null) myPort.write("1063,"+str(theValue)+" ");
}

void NC20(int theValue)
{
  if (myPort != null) myPort.write("1064,"+str(theValue)+" ");
}

void NC21(int theValue)
{
  if (myPort != null) myPort.write("1065,"+str(theValue)+" ");
}

void NC22(int theValue)
{
  if (myPort != null) myPort.write("1066,"+str(theValue)+" ");
}









//********************************************************************************************
void FileLoadUpdate()//update values of teensy from file
{

  int settingdata=0;
  //knobA glide rate
  settingdata= int(map(int(lines[1]), 0, 255, 0, 1000)); //
  myPort.write("1,"+str(settingdata)+" ");

  // knobB  reverb wet
  settingdata= int(map(int(lines[2]), 0, 255, 0, 100)); //
  myPort.write("2,"+str(settingdata)+" ");

  // listB scale type
  settingdata= int(map(int(lines[3]), 0, 255, 0, 255)); //
  myPort.write("3,"+str(settingdata)+" ");


  // toggleA chromatic interpret
  settingdata= int(map(int(lines[4]), 0, 255, 0, 255)); //
  myPort.write("4,"+str(settingdata)+" ");


  // knobC rain gain
  settingdata= int(map(int(lines[6]), 0, 255, 0, 100));// rain gain
  myPort.write("6,"+str(settingdata)+" ");

  // knobD shimmer gain
  settingdata= int(map(int(lines[7]), 0, 255, 0, 100));// shimmergain
  myPort.write("7,"+str(settingdata)+" ");


  // toggleB shimmer chord
  settingdata= int(map(int(lines[8]), 0, 255, 0, 255)); //
  myPort.write("8,"+str(settingdata)+" ");


  ////waveform control events************************************

  ////melody****************************************************

  // knobE m filter frequency
  settingdata= int(map(int(lines[13]), 0, 255, 0, 10000));// mel filter
  myPort.write("13,"+str(settingdata)+" ");

  // knobF harmony mixer
  settingdata= int(map(int(lines[18]), 0, 255, 0, 100));// mel volume
  myPort.write("18,"+str(settingdata)+" ");

  // listD melody octave
  settingdata= int(map(int(lines[11]), 0, 255, 0, 255)); //
  myPort.write("11,"+str(settingdata)+" ");

  // listE melody shape
  settingdata= int(map(int(lines[12]), 0, 255, 0, 255)); //
  myPort.write("12,"+str(settingdata)+" ");

  // sliderA M attack time
  settingdata= int(map(int(lines[14]), 0, 255, 0, 3000));
  myPort.write("14,"+str(settingdata)+" ");

  // sliderB M decay time
  settingdata= int(map(int(lines[15]), 0, 255, 0, 3000));
  myPort.write("15,"+str(settingdata)+" ");

  // sliderC M sustain level
  settingdata= int(map(int(lines[16]), 0, 255, 0, 100));
  ;
  myPort.write("16,"+str(settingdata)+" ");

  // sliderD m release time
  settingdata= int(map(int(lines[17]), 0, 255, 0, 3000));
  myPort.write("17,"+str(settingdata)+" ");

  //harmony1***********************************************

  // knobG harmony one filter frequency
  settingdata= int(map(int(lines[21]), 0, 255, 0, 10000));
  myPort.write("21,"+str(settingdata)+" ");

  // knobH harmony 1 mixer
  settingdata= int(map(int(lines[26]), 0, 255, 0, 100));
  myPort.write("26,"+str(settingdata)+" ");

  // listF harmony 1 octave
  settingdata= int(map(int(lines[19]), 0, 255, 0, 255)); //
  myPort.write("19,"+str(settingdata)+" ");

  // listG Harmony 1 shape
  settingdata= int(map(int(lines[20]), 0, 255, 0, 255)); //
  myPort.write("20,"+str(settingdata)+" ");

  // sliderE harmony 1 attack time
  settingdata= int(map(int(lines[22]), 0, 255, 0, 3000));
  myPort.write("22,"+str(settingdata)+" ");

  // sliderF  harmony 1 decay time
  settingdata= int(map(int(lines[23]), 0, 255, 0, 3000));
  myPort.write("23,"+str(settingdata)+" ");

  // sliderG harmony 1 sustain level
  settingdata= int(map(int(lines[24]), 0, 255, 0, 100));
  myPort.write("24,"+str(settingdata)+" ");

  // sliderH harmony 1 release time
  settingdata= int(map(int(lines[25]), 0, 255, 0, 3000));
  myPort.write("25,"+str(settingdata)+" ");

  //harmony2***********************************************

  // knobI harmony 2 filter frequency
  settingdata= int(map(int(lines[29]), 0, 255, 0, 10000));
  myPort.write("29,"+str(settingdata)+" ");

  // knobJ  harmony 2 mixer
  settingdata= int(map(int(lines[34]), 0, 255, 0, 100));
  myPort.write("34,"+str(settingdata)+" ");

  // listH harmony 2 octave
  settingdata= int(map(int(lines[27]), 0, 255, 0, 255)); //
  myPort.write("27,"+str(settingdata)+" ");

  // listI harmony 2 shape
  settingdata= int(map(int(lines[28]), 0, 255, 0, 255)); //
  myPort.write("28,"+str(settingdata)+" ");

  // sliderI harmony 2 attack time
  settingdata= int(map(int(lines[30]), 0, 255, 0, 3000));
  myPort.write("30,"+str(settingdata)+" ");

  // sliderJ harmony 2 decay time
  settingdata= int(map(int(lines[31]), 0, 255, 0, 3000));
  myPort.write("31,"+str(settingdata)+" ");

  // sliderK harmony 2 sustain level
  settingdata= int(map(int(lines[32]), 0, 255, 0, 100));
  myPort.write("32,"+str(settingdata)+" ");

  // sliderL harmony 2 release time
  settingdata= int(map(int(lines[33]), 0, 255, 0, 3000));
  myPort.write("33,"+str(settingdata)+" ");

  ////strings**********************************************


  // knobK melody string gain
  settingdata= int(map(int(lines[36]), 0, 255, 0, 100));
  ;
  myPort.write("36,"+str(settingdata)+" ");

  // knobL harmony string gain
  settingdata= int(map(int(lines[38]), 0, 255, 0, 100));
  myPort.write("38,"+str(settingdata)+" ");

  // listJ melody string octave
  settingdata= int(map(int(lines[37]), 0, 255, 0, 255)); //
  myPort.write("37,"+str(settingdata)+" ");

  // listK harmony string octave
  settingdata= int(map(int(lines[39]), 0, 255, 0, 255)); //
  myPort.write("39,"+str(settingdata)+" ");

  //background controls

  // toggleF stick override
  settingdata= int(map(int(lines[40]), 0, 255, 0, 255)); //stick override
  myPort.write("40,"+str(settingdata)+" ");

  // listL button logic
  settingdata= int(map(int(lines[41]), 0, 255, 0, 255)); //button logic
  myPort.write("41,"+str(settingdata)+" ");

  // toggleG drum play
  settingdata= int(map(int(lines[42]), 0, 255, 0, 255)); //drums on
  myPort.write("42,"+str(settingdata)+" ");


  // knobAO fade in time
  settingdata= int(map(int(lines[46]), 0, 255, 0, 20000)); //fade in
  myPort.write("46,"+str(settingdata)+" ");


  // listAP fadeout time
  settingdata= int(map(int(lines[47]), 0, 255, 0, 20000)); //
  myPort.write("47,"+str(settingdata)+" ");

  ////drum controls***************************************************
  ////drum sounds

  ////// toggleC count display active
  //settingdata= int(map(int(lines[49]), 0, 255, 0, 255)); //drum preview
  //myPort.write("49,"+str(settingdata)+" ");

  // knobM drum speed--special case no compression
  espeedLSB= int(map(int(lines[48]), 0, 255, 0, 255));//
  myPort.write("48,"+str(espeedLSB) +" ");
  espeedMSB= int(map(int(lines[50]), 0, 255, 0, 255));//
  myPort.write("50,"+str(espeedMSB) +" ");

  //knobN drum 1 frequency
  settingdata= int(map(int(lines[51]), 0, 255, 0, 2000));//
  myPort.write("51,"+str(settingdata) +" ");

  //knobO drum one length
  settingdata= int(map(int(lines[52]), 0, 255, 0, 1000));//
  myPort.write("52,"+str(settingdata) +" ");

  //knobP drum one mix
  settingdata= int(map(int(lines[53]), 0, 255, 0, 100));//
  myPort.write("53,"+str(settingdata) +" ");

  //knobQ drum one modulation
  settingdata= int(map(int(lines[54]), 0, 255, 0, 100));//
  myPort.write("54,"+str(settingdata) +" ");

  //knobR drum one volume
  settingdata= int(map(int(lines[55]), 0, 255, 0, 100));//
  myPort.write("55,"+str(settingdata) +" ");

  //knobS drum 2 frequency
  settingdata= int(map(int(lines[56]), 0, 255, 0, 2000));//
  myPort.write("56,"+str(settingdata) +" ");

  //knobT drum 2 length
  settingdata= int(map(int(lines[57]), 0, 255, 0, 255));//
  myPort.write("57,"+str(settingdata) +" ");

  //knobU drum 2 mix
  settingdata= int(map(int(lines[58]), 0, 255, 0, 100));//
  myPort.write("58,"+str(settingdata) +" ");

  //knobV drum 2 modulation
  settingdata= int(map(int(lines[59]), 0, 255, 0, 100));//
  myPort.write("59,"+str(settingdata) +" ");

  //knobW drum 2 volume
  settingdata= int(map(int(lines[60]), 0, 255, 0, 100));//
  myPort.write("60,"+str(settingdata) +" ");

  //knobX drum 3 frequency
  settingdata= int(map(int(lines[61]), 0, 255, 0, 2000));//
  myPort.write("61,"+str(settingdata) +" ");

  //knobY drum 3 length
  settingdata= int(map(int(lines[62]), 0, 255, 0, 1000));//
  myPort.write("62,"+str(settingdata) +" ");

  //knobZ drum 3 mix
  settingdata= int(map(int(lines[63]), 0, 255, 0, 100));//
  myPort.write("63,"+str(settingdata) +" ");

  //knobAA drum 3 modulation
  settingdata= int(map(int(lines[64]), 0, 255, 0, 100));//
  myPort.write("64,"+str(settingdata) +" ");

  //knobAB drum 3 volume
  settingdata= int(map(int(lines[65]), 0, 255, 0, 100));//
  myPort.write("65,"+str(settingdata) +" ");

  //knobAC drum 4 frequency
  settingdata= int(map(int(lines[66]), 0, 255, 0, 2000));//
  myPort.write("66,"+str(settingdata) +" ");

  //knobAD drum 4 length
  settingdata= int(map(int(lines[67]), 0, 255, 0, 1000));//
  myPort.write("67,"+str(settingdata) +" ");

  //knobAE drum 4 mix
  settingdata= int(map(int(lines[68]), 0, 255, 0, 100));
  myPort.write("68,"+str(settingdata) +" ");

  //knobAF drum 4 modulation
  settingdata= int(map(int(lines[69]), 0, 255, 0, 100));//
  myPort.write("69,"+str(settingdata) +" ");

  //knobAG drum 4 volume
  settingdata= int(map(int(lines[70]), 0, 255, 0, 100));//
  myPort.write("70,"+str(settingdata) +" ");


  //toggleD Euclid activated
  settingdata= int(map(int(lines[72]), 0, 255, 0, 255)); //
  myPort.write("72,"+str(settingdata)+" ");

  //knobAH beats
  settingdata= int(map(int(lines[73]), 0, 255, 0, 255));//
  myPort.write("73,"+str(settingdata) +" ");

  //knobAI offset
  settingdata= int(map(int(lines[74]), 0, 255, 0, 255));//
  myPort.write("74,"+str(settingdata) +" ");

  //knobAJ bins
  settingdata= int(map(int(lines[75]), 0, 255, 0, 255));//
  myPort.write("75,"+str(settingdata) +" ");

  //togL beat A 1
  settingdata= int(map(int(lines[76]), 0, 255, 0, 255));//
  myPort.write("76,"+str(settingdata)+" ");

  //togM beat A 2
  settingdata= int(map(int(lines[77]), 0, 255, 0, 255));//
  myPort.write("77,"+str(settingdata)+" ");

  //togN beat A 3
  settingdata= int(map(int(lines[78]), 0, 255, 0, 255));//
  myPort.write("78,"+str(settingdata)+" ");

  //togO beat A 4
  settingdata= int(map(int(lines[79]), 0, 255, 0, 255));//
  myPort.write("79,"+str(settingdata)+" ");

  //togP beat A 5
  settingdata= int(map(int(lines[80]), 0, 255, 0, 255));//
  myPort.write("80,"+str(settingdata)+" ");

  //togQ beat A 6
  settingdata= int(map(int(lines[81]), 0, 255, 0, 255));//
  myPort.write("81,"+str(settingdata)+" ");

  //togR beat A 7
  settingdata= int(map(int(lines[82]), 0, 255, 0, 255));//
  myPort.write("82,"+str(settingdata)+" ");

  //togS beat A 8
  settingdata= int(map(int(lines[83]), 0, 255, 0, 255));//
  myPort.write("83,"+str(settingdata)+" ");

  //togT beat A 9
  settingdata= int(map(int(lines[84]), 0, 255, 0, 255));//
  myPort.write("84,"+str(settingdata)+" ");

  //togU beat A 10
  settingdata= int(map(int(lines[85]), 0, 255, 0, 255));//
  myPort.write("85,"+str(settingdata)+" ");

  //togV beat A 11
  settingdata= int(map(int(lines[86]), 0, 255, 0, 255));//
  myPort.write("86,"+str(settingdata)+" ");

  //togW beat A 12
  settingdata= int(map(int(lines[87]), 0, 255, 0, 255));//
  myPort.write("87,"+str(settingdata)+" ");

  //togX beat A 13
  settingdata= int(map(int(lines[88]), 0, 255, 0, 255));//
  myPort.write("88,"+str(settingdata)+" ");

  //togY beat A 14
  settingdata= int(map(int(lines[89]), 0, 255, 0, 255));//
  myPort.write("89,"+str(settingdata)+" ");

  //togZ beat A 15
  settingdata= int(map(int(lines[90]), 0, 255, 0, 255));//
  myPort.write("90,"+str(settingdata)+" ");

  //togAA beat A 16
  settingdata= int(map(int(lines[91]), 0, 255, 0, 255));//
  myPort.write("91,"+str(settingdata)+" ");


  //knobAK drum 1 MIDI
  settingdata= int(map(int(lines[92]), 0, 255, 0, 255));//
  myPort.write("92,"+str(settingdata)+" ");


  //knobAL drum 2 MIDI
  settingdata= int(map(int(lines[93]), 0, 255, 0, 255));//
  myPort.write("93,"+str(settingdata)+" ");


  //knobAM drum 3 MIDI
  settingdata= int(map(int(lines[94]), 0, 255, 0, 255));//
  myPort.write("94,"+str(settingdata)+" ");


  //knobAN drum 4 MIDI
  settingdata= int(map(int(lines[95]), 0, 255, 0, 255));//
  myPort.write("95,"+str(settingdata)+" ");

  ////second row of buttons

  //togAB beat B 1
  settingdata= int(map(int(lines[96]), 0, 255, 0, 255));//
  myPort.write("96,"+str(settingdata)+" ");

  //togAC beat B 2
  settingdata= int(map(int(lines[97]), 0, 255, 0, 255));//
  myPort.write("97,"+str(settingdata)+" ");

  //togAD beat B 3
  settingdata= int(map(int(lines[98]), 0, 255, 0, 255));//
  myPort.write("98,"+str(settingdata)+" ");

  //togAE beat B 4
  settingdata= int(map(int(lines[99]), 0, 255, 0, 255));//
  myPort.write("99,"+str(settingdata)+" ");

  //togAF beat B 5
  settingdata= int(map(int(lines[100]), 0, 255, 0, 255));//
  myPort.write("100,"+str(settingdata)+" ");

  //togAG beat B 6
  settingdata= int(map(int(lines[101]), 0, 255, 0, 255));//
  myPort.write("101,"+str(settingdata)+" ");

  //togAH beat B 7
  settingdata= int(map(int(lines[102]), 0, 255, 0, 255));//
  myPort.write("102,"+str(settingdata)+" ");

  //togAI beat B 8
  settingdata= int(map(int(lines[103]), 0, 255, 0, 255));//
  myPort.write("103,"+str(settingdata)+" ");

  //togAJ beat B 9
  settingdata= int(map(int(lines[104]), 0, 255, 0, 255));//
  myPort.write("104,"+str(settingdata)+" ");

  //togAK beat B 10
  settingdata= int(map(int(lines[105]), 0, 255, 0, 255));//
  myPort.write("105,"+str(settingdata)+" ");

  //togAL beat B 11
  settingdata= int(map(int(lines[106]), 0, 255, 0, 255));//
  myPort.write("106,"+str(settingdata)+" ");

  //togAM beat B 12
  settingdata= int(map(int(lines[107]), 0, 255, 0, 255));//
  myPort.write("107,"+str(settingdata)+" ");

  //togAN beat B 13
  settingdata= int(map(int(lines[108]), 0, 255, 0, 255));//
  myPort.write("108,"+str(settingdata)+" ");

  //togAO beat B 14
  settingdata= int(map(int(lines[109]), 0, 255, 0, 255));//
  myPort.write("109,"+str(settingdata)+" ");

  //togAP beat B 15
  settingdata= int(map(int(lines[110]), 0, 255, 0, 255));//
  myPort.write("110,"+str(settingdata)+" ");

  //togAQ beat B 16
  settingdata= int(map(int(lines[111]), 0, 255, 0, 255));//
  myPort.write("111,"+str(settingdata)+" ");

  ////third row of buttons


  //togAR beat C 1
  settingdata= int(map(int(lines[116]), 0, 255, 0, 255));//
  myPort.write("116,"+str(settingdata)+" ");

  //togAS beat C 2
  settingdata= int(map(int(lines[117]), 0, 255, 0, 255));//
  myPort.write("117,"+str(settingdata)+" ");

  //togAT beat C 3
  settingdata= int(map(int(lines[118]), 0, 255, 0, 255));//
  myPort.write("118,"+str(settingdata)+" ");

  //togAU beat C 4
  settingdata= int(map(int(lines[119]), 0, 255, 0, 255));//
  myPort.write("119,"+str(settingdata)+" ");

  //togAV beat C 5
  settingdata= int(map(int(lines[120]), 0, 255, 0, 255));//
  myPort.write("120,"+str(settingdata)+" ");

  //togAW beat C 6
  settingdata= int(map(int(lines[121]), 0, 255, 0, 255));//
  myPort.write("121,"+str(settingdata)+" ");

  //togAX beat C 7
  settingdata= int(map(int(lines[122]), 0, 255, 0, 255));//
  myPort.write("122,"+str(settingdata)+" ");

  //togAY beat C 8
  settingdata= int(map(int(lines[123]), 0, 255, 0, 255));//
  myPort.write("123,"+str(settingdata)+" ");

  //togAZ beat C 9
  settingdata= int(map(int(lines[124]), 0, 255, 0, 255));//
  myPort.write("124,"+str(settingdata)+" ");

  //togBA beat C 10
  settingdata= int(map(int(lines[125]), 0, 255, 0, 255));//
  myPort.write("125,"+str(settingdata)+" ");

  //togBB beat C 11
  settingdata= int(map(int(lines[126]), 0, 255, 0, 255));//
  myPort.write("126,"+str(settingdata)+" ");

  //togBC beat C 12
  settingdata= int(map(int(lines[127]), 0, 255, 0, 255));//
  myPort.write("127,"+str(settingdata)+" ");

  //togBD beat C 13
  settingdata= int(map(int(lines[128]), 0, 255, 0, 255));//
  myPort.write("128,"+str(settingdata)+" ");

  //togBE beat C 14
  settingdata= int(map(int(lines[129]), 0, 255, 0, 255));//
  myPort.write("129,"+str(settingdata)+" ");

  //togBF beat C 15
  settingdata= int(map(int(lines[130]), 0, 255, 0, 255));//
  myPort.write("130,"+str(settingdata)+" ");

  //togBG beat C 16
  settingdata= int(map(int(lines[131]), 0, 255, 0, 255));//
  myPort.write("131,"+str(settingdata)+" ");

  ////fourth row of buttons


  //togBH beat D 1
  settingdata= int(map(int(lines[132]), 0, 255, 0, 255));//
  myPort.write("132,"+str(settingdata)+" ");

  //togBI beat D 2
  settingdata= int(map(int(lines[133]), 0, 255, 0, 255));//
  myPort.write("133,"+str(settingdata)+" ");

  //togBJ beat D 3
  settingdata= int(map(int(lines[134]), 0, 255, 0, 255));//
  myPort.write("134,"+str(settingdata)+" ");

  //togBK beat D 4
  settingdata= int(map(int(lines[135]), 0, 255, 0, 255));//
  myPort.write("135,"+str(settingdata)+" ");

  //togBL beat D 5
  settingdata= int(map(int(lines[136]), 0, 255, 0, 255));//
  myPort.write("136,"+str(settingdata)+" ");

  //togBM beat D 6
  settingdata= int(map(int(lines[137]), 0, 255, 0, 255));//
  myPort.write("137,"+str(settingdata)+" ");

  //togBN beat D 7
  settingdata= int(map(int(lines[138]), 0, 255, 0, 255));//
  myPort.write("138,"+str(settingdata)+" ");

  //togBO beat D 8
  settingdata= int(map(int(lines[139]), 0, 255, 0, 255));//
  myPort.write("139,"+str(settingdata)+" ");

  //togBP beat D 9
  settingdata= int(map(int(lines[140]), 0, 255, 0, 255));//
  myPort.write("140,"+str(settingdata)+" ");

  //togBQ beat De 10
  settingdata= int(map(int(lines[141]), 0, 255, 0, 255));//
  myPort.write("141,"+str(settingdata)+" ");

  //togBR beat D 11
  settingdata= int(map(int(lines[142]), 0, 255, 0, 255));//
  myPort.write("142,"+str(settingdata)+" ");

  //togBS beat D 12
  settingdata= int(map(int(lines[143]), 0, 255, 0, 255));//
  myPort.write("143,"+str(settingdata)+" ");

  //togBT beat D 13
  settingdata= int(map(int(lines[144]), 0, 255, 0, 255));//
  myPort.write("144,"+str(settingdata)+" ");

  //togBU beat D 14
  settingdata= int(map(int(lines[145]), 0, 255, 0, 255));//
  myPort.write("145,"+str(settingdata)+" ");

  //togBV beat D 15
  settingdata= int(map(int(lines[146]), 0, 255, 0, 255));//
  myPort.write("146,"+str(settingdata)+" ");

  //togBW beat D 16
  settingdata= int(map(int(lines[147]), 0, 255, 0, 255));//
  myPort.write("147,"+str(settingdata)+" ");


  ////toggleH  save a file
  //settingdata= int(map(int(lines[150]), 0, 255, 0, 255)); //
  //myPort.write("150,"+str(settingdata)+" ");


  ////listO selected preset
  //settingdata= int(map(int(lines[151]), 0, 255, 0, 255)); //save to eeprom
  //myPort.write("151,"+str(settingdata)+" ");


  ////toggleI factory reset
  //settingdata= int(map(int(lines[152]), 0, 255, 0, 255)); //
  //myPort.write("152,"+str(settingdata)+" ");


  ////chord1


  //listNA1
  settingdata= int(map(int(lines[153]), 0, 255, 0, 255)); //
  myPort.write("153,"+str(settingdata)+" ");

  //listNA2
  settingdata= int(map(int(lines[154]), 0, 255, 0, 255)); //
  myPort.write("154,"+str(settingdata)+" ");


  //listNA3
  settingdata= int(map(int(lines[155]), 0, 255, 0, 255)); //
  myPort.write("155,"+str(settingdata)+" ");


  //listNA4
  settingdata= int(map(int(lines[156]), 0, 255, 0, 255)); //
  myPort.write("156,"+str(settingdata)+" ");


  //listNA5
  settingdata= int(map(int(lines[157]), 0, 255, 0, 255)); //
  myPort.write("157,"+str(settingdata)+" ");


  //listNA6
  settingdata= int(map(int(lines[158]), 0, 255, 0, 255)); //
  myPort.write("158,"+str(settingdata)+" ");


  //listNA7
  settingdata= int(map(int(lines[159]), 0, 255, 0, 255)); //
  myPort.write("159,"+str(settingdata)+" ");


  //listNA8
  settingdata= int(map(int(lines[160]), 0, 255, 0, 255)); //
  myPort.write("160,"+str(settingdata)+" ");


  //listNA9
  settingdata= int(map(int(lines[161]), 0, 255, 0, 255)); //
  myPort.write("161,"+str(settingdata)+" ");


  //listNA10
  settingdata= int(map(int(lines[162]), 0, 255, 0, 255)); //
  myPort.write("162,"+str(settingdata)+" ");


  //listNA11
  settingdata= int(map(int(lines[163]), 0, 255, 0, 255)); //
  myPort.write("163,"+str(settingdata)+" ");


  //listNA12
  settingdata= int(map(int(lines[164]), 0, 255, 0, 255)); //
  myPort.write("164,"+str(settingdata)+" ");


  //listNA13
  settingdata= int(map(int(lines[165]), 0, 255, 0, 255)); //
  myPort.write("165,"+str(settingdata)+" ");


  //listNA14
  settingdata= int(map(int(lines[166]), 0, 255, 0, 255)); //
  myPort.write("166,"+str(settingdata)+" ");


  //listNA15
  settingdata= int(map(int(lines[167]), 0, 255, 0, 255)); //
  myPort.write("167,"+str(settingdata)+" ");


  //listNA16
  settingdata= int(map(int(lines[168]), 0, 255, 0, 255)); //
  myPort.write("168,"+str(settingdata)+" ");



  ////backup

  ////chord2


  //listNB1
  settingdata= int(map(int(lines[169]), 0, 255, 0, 255)); //
  myPort.write("169,"+str(settingdata)+" ");

  //listNB2
  settingdata= int(map(int(lines[170]), 0, 255, 0, 255)); //
  myPort.write("170,"+str(settingdata)+" ");


  //listNB3
  settingdata= int(map(int(lines[171]), 0, 255, 0, 255)); //
  myPort.write("171,"+str(settingdata)+" ");


  //listNB4
  settingdata= int(map(int(lines[172]), 0, 255, 0, 255)); //
  myPort.write("172,"+str(settingdata)+" ");


  //listNB5
  settingdata= int(map(int(lines[173]), 0, 255, 0, 255)); //
  myPort.write("173,"+str(settingdata)+" ");


  //listNB6
  settingdata= int(map(int(lines[174]), 0, 255, 0, 255)); //
  myPort.write("174,"+str(settingdata)+" ");


  //listNB7
  settingdata= int(map(int(lines[175]), 0, 255, 0, 255)); //
  myPort.write("175,"+str(settingdata)+" ");


  //listNB8
  settingdata= int(map(int(lines[176]), 0, 255, 0, 255)); //
  myPort.write("176,"+str(settingdata)+" ");


  //listNB9
  settingdata= int(map(int(lines[177]), 0, 255, 0, 255)); //
  myPort.write("177,"+str(settingdata)+" ");


  //listNB10
  settingdata= int(map(int(lines[178]), 0, 255, 0, 255)); //
  myPort.write("178,"+str(settingdata)+" ");


  //listNB11
  settingdata= int(map(int(lines[179]), 0, 255, 0, 255)); //
  myPort.write("179,"+str(settingdata)+" ");


  //listNB12
  settingdata= int(map(int(lines[180]), 0, 255, 0, 255)); //
  myPort.write("180,"+str(settingdata)+" ");


  //listNB13
  settingdata= int(map(int(lines[181]), 0, 255, 0, 255)); //
  myPort.write("181,"+str(settingdata)+" ");


  //listNB14
  settingdata= int(map(int(lines[182]), 0, 255, 0, 255)); //
  myPort.write("182,"+str(settingdata)+" ");


  //listNB15
  settingdata= int(map(int(lines[183]), 0, 255, 0, 255)); //
  myPort.write("183,"+str(settingdata)+" ");


  //listNB16
  settingdata= int(map(int(lines[184]), 0, 255, 0, 255)); //
  myPort.write("184,"+str(settingdata)+" ");



  //chord4


  //listNC1
  settingdata= int(map(int(lines[185]), 0, 255, 0, 255)); //
  myPort.write("185,"+str(settingdata)+" ");

  //listNC2
  settingdata= int(map(int(lines[186]), 0, 255, 0, 255)); //
  myPort.write("186,"+str(settingdata)+" ");


  //listNC3
  settingdata= int(map(int(lines[187]), 0, 255, 0, 255)); //
  myPort.write("187,"+str(settingdata)+" ");


  //listNC4
  settingdata= int(map(int(lines[188]), 0, 255, 0, 255)); //
  myPort.write("188,"+str(settingdata)+" ");


  //listNC5
  settingdata= int(map(int(lines[189]), 0, 255, 0, 255)); //
  myPort.write("189,"+str(settingdata)+" ");


  //listNC6
  settingdata= int(map(int(lines[190]), 0, 255, 0, 255)); //
  myPort.write("190,"+str(settingdata)+" ");


  //listNC7
  settingdata= int(map(int(lines[191]), 0, 255, 0, 255)); //
  myPort.write("191,"+str(settingdata)+" ");


  //listNC8
  settingdata= int(map(int(lines[192]), 0, 255, 0, 255)); //
  myPort.write("192,"+str(settingdata)+" ");


  //listNC9
  settingdata= int(map(int(lines[193]), 0, 255, 0, 255)); //
  myPort.write("193,"+str(settingdata)+" ");


  //listNC10
  settingdata= int(map(int(lines[194]), 0, 255, 0, 255)); //
  myPort.write("194,"+str(settingdata)+" ");


  //listNC11
  settingdata= int(map(int(lines[195]), 0, 255, 0, 255)); //
  myPort.write("195,"+str(settingdata)+" ");


  //listNC12
  settingdata= int(map(int(lines[196]), 0, 255, 0, 255)); //
  myPort.write("196,"+str(settingdata)+" ");


  //listNC13
  settingdata= int(map(int(lines[197]), 0, 255, 0, 255)); //
  myPort.write("197,"+str(settingdata)+" ");


  //listNC14
  settingdata= int(map(int(lines[198]), 0, 255, 0, 255)); //
  myPort.write("198,"+str(settingdata)+" ");


  //listNC15
  settingdata= int(map(int(lines[199]), 0, 255, 0, 255)); //
  myPort.write("199,"+str(settingdata)+" ");


  //listNC16
  settingdata= int(map(int(lines[200]), 0, 255, 0, 255)); //
  myPort.write("200,"+str(settingdata)+" ");


  //backup

  //chord4


  //listND1
  settingdata= int(map(int(lines[201]), 0, 255, 0, 255)); //
  myPort.write("201,"+str(settingdata)+" ");

  //listND2
  settingdata= int(map(int(lines[202]), 0, 255, 0, 255)); //
  myPort.write("202,"+str(settingdata)+" ");


  //listND3
  settingdata= int(map(int(lines[203]), 0, 255, 0, 255)); //
  myPort.write("203,"+str(settingdata)+" ");


  //listND4
  settingdata= int(map(int(lines[204]), 0, 255, 0, 255)); //
  myPort.write("204,"+str(settingdata)+" ");


  //listND5
  settingdata= int(map(int(lines[205]), 0, 255, 0, 255)); //
  myPort.write("205,"+str(settingdata)+" ");


  //listND6
  settingdata= int(map(int(lines[206]), 0, 255, 0, 255)); //
  myPort.write("206,"+str(settingdata)+" ");


  //listND7
  settingdata= int(map(int(lines[207]), 0, 255, 0, 255)); //
  myPort.write("207,"+str(settingdata)+" ");


  //listND8
  settingdata= int(map(int(lines[208]), 0, 255, 0, 255)); //
  myPort.write("208,"+str(settingdata)+" ");


  //listND9
  settingdata= int(map(int(lines[209]), 0, 255, 0, 255)); //
  myPort.write("209,"+str(settingdata)+" ");


  //listND10
  settingdata= int(map(int(lines[210]), 0, 255, 0, 255)); //
  myPort.write("210,"+str(settingdata)+" ");


  //listND11
  settingdata= int(map(int(lines[211]), 0, 255, 0, 255)); //
  myPort.write("211,"+str(settingdata)+" ");


  //listND12
  settingdata= int(map(int(lines[212]), 0, 255, 0, 255)); //
  myPort.write("212,"+str(settingdata)+" ");


  //listND13
  settingdata= int(map(int(lines[213]), 0, 255, 0, 255)); //
  myPort.write("213,"+str(settingdata)+" ");


  //listND14
  settingdata= int(map(int(lines[214]), 0, 255, 0, 255)); //
  myPort.write("214,"+str(settingdata)+" ");


  //listND15
  settingdata= int(map(int(lines[215]), 0, 255, 0, 255)); //
  myPort.write("215,"+str(settingdata)+" ");


  //listND16
  settingdata= int(map(int(lines[216]), 0, 255, 0, 255)); //
  myPort.write("216,"+str(settingdata)+" ");


  //knobLock
  settingdata= int(map(int(lines[217]), 0, 255, 0, 255));
  myPort.write("217,"+str(settingdata)+" ");

  delay(2000);
  myPort.write("148,"+"1"+" "); //update controls
}

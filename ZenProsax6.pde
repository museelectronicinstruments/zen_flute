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
int scaleNumber=0;

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

  cp5.addTab("tab_performance")
    .setHeight(50)
    .setWidth(150)
    .setColorBackground(color(0, 160, 100))
    .setColorLabel(color(255))
    .setColorActive(color(255, 128, 0))
    .setLabel("ambience")
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
  //performance setup controls *************
  //*************************************

  cp5.addKnob("knob1")
    .setPosition(100, 100)
    .setRadius(70)
    .setRange(0, 100)
    .setValue(50)
    .setCaptionLabel("reverb amount %");
  ;

  cp5.addKnob("knob2")
    .setPosition(300, 100)
    .setRadius(70)
    .setRange(0, 100)
    .setValue(50)
    .setCaptionLabel("reverb size %");
  ;

  cp5.addKnob("knob3")
    .setPosition(500, 100)
    .setRadius(70)
    .setRange(0, 100)
    .setValue(50)
    .setCaptionLabel("reverb damping %");
  ;


  cp5.addKnob("knob6")
    .setPosition(100, 300)
    .setRadius(70)
    .setRange(0, 300)
    .setValue(50)
    .setCaptionLabel("LP filter res x100");
  ;

  cp5.addKnob("knob7")
    .setPosition(300, 300)
    .setRadius(70)
    .setRange(0, 10000)
    .setValue(50)
    .setCaptionLabel("lp filter freq");
  ;

  cp5.addKnob("knob8")
    .setPosition(500, 300)
    .setRadius(70)
    .setRange(0, 300)
    .setValue(50)
    .setCaptionLabel("hp filter res x100");
  ;

  cp5.addKnob("knob9")
    .setPosition(700, 300)
    .setRadius(70)
    .setRange(0, 10000)
    .setValue(50)
    .setCaptionLabel("hp filter freq");
  ;


  List l = Arrays.asList("Cmaj/Amin", "Bmaj/G#min", "A#maj/Gmin", "Amaj/F#min", "G#maj/Fmin", "Gmaj/Emin",
    "F#maj/D#min", "Fmaj/Dmin", "Emaj/C#min", "D#maj/Cmin", "Dmaj/Bmin", "C#maj/Bbmin");

  cp5.addScrollableList("list1")
    .setPosition(950, 175)
    .setSize(150, 820)
    .setBarHeight(30)
    .setItemHeight(30)
    .addItems(l)
    .setOpen(false)
    .setCaptionLabel("scale type");
  ;


  cp5.addToggle("toggleF")
    .setPosition(950, 100)
    .setSize(50, 20)
    .setValue(false)
    .setCaptionLabel("scale generate");
  ;


  cp5.addToggle("tog1")
    .setPosition(50, 600)
    .setSize(20, 20)
    .setCaptionLabel("A4")
    ;

  cp5.addToggle("tog2")
    .setPosition(100, 600)
    .setSize(20, 20)
    .setCaptionLabel("A#4");
  ;

  cp5.addToggle("tog3")
    .setPosition(150, 600)
    .setSize(20, 20)
    .setCaptionLabel("B4");
  ;

  cp5.addToggle("tog4")
    .setPosition(200, 600)
    .setSize(20, 20)
    .setCaptionLabel("C5");
  ;

  cp5.addToggle("tog5")
    .setPosition(250, 600)
    .setSize(20, 20)
    .setCaptionLabel("C#5");
  ;

  cp5.addToggle("tog6")
    .setPosition(300, 600)
    .setSize(20, 20)
    .setCaptionLabel("D5");
  ;

  cp5.addToggle("tog7")
    .setPosition(350, 600)
    .setSize(20, 20)
    .setCaptionLabel("D#5");
  ;

  cp5.addToggle("tog8")
    .setPosition(400, 600)
    .setSize(20, 20)
    .setCaptionLabel("E5");
  ;

  cp5.addToggle("tog9")
    .setPosition(450, 600)
    .setSize(20, 20)
    .setCaptionLabel("F5");
  ;

  cp5.addToggle("tog10")
    .setPosition(500, 600)
    .setSize(20, 20)
    .setCaptionLabel("F#5");
  ;

  cp5.addToggle("tog11")
    .setPosition(550, 600)
    .setSize(20, 20)
    .setCaptionLabel("G5");
  ;

  cp5.addToggle("tog12")
    .setPosition(600, 600)
    .setSize(20, 20)
    .setCaptionLabel("G#5");
  ;

  cp5.addToggle("tog13")
    .setPosition(650, 600)
    .setSize(20, 20)
    .setCaptionLabel("A5");
  ;

  cp5.addToggle("tog14")
    .setPosition(700, 600)
    .setSize(20, 20)
    .setCaptionLabel("A#5");
  ;

  cp5.addToggle("tog15")
    .setPosition(750, 600)
    .setSize(20, 20)
    .setCaptionLabel("B5");

  cp5.addToggle("tog16")
    .setPosition(800, 600)
    .setSize(20, 20)
    .setCaptionLabel("C6");

  cp5.addToggle("tog17")
    .setPosition(850, 600)
    .setSize(20, 20)
    .setCaptionLabel("C#6");
  ;

  cp5.addToggle("tog18")
    .setPosition(900, 600)
    .setSize(20, 20)
    .setCaptionLabel("D6");
  ;

  cp5.addToggle("tog19")
    .setPosition(950, 600)
    .setSize(20, 20)
    .setCaptionLabel("D#6");
  ;

  cp5.addToggle("tog20")
    .setPosition(1000, 600)
    .setSize(20, 20)
    .setCaptionLabel("E6");
  ;

  cp5.addToggle("tog21")
    .setPosition(1050, 600)
    .setSize(20, 20)
    .setCaptionLabel("F6");
  ;

  cp5.addToggle("tog22")
    .setPosition(1100, 600)
    .setSize(20, 20)
    .setCaptionLabel("F#6");
  ;


  cp5.getController("toggleF").moveTo("tab_performance");
  cp5.getController("knob1").moveTo("tab_performance");
  cp5.getController("knob2").moveTo("tab_performance");
  cp5.getController("knob3").moveTo("tab_performance");
  cp5.getController("knob6").moveTo("tab_performance");
  cp5.getController("knob7").moveTo("tab_performance");
  //cp5.getController("knob8").moveTo("tab_performance");
  //cp5.getController("knob9").moveTo("tab_performance");
  cp5.getController("tog1").moveTo("tab_performance");
  cp5.getController("tog2").moveTo("tab_performance");
  cp5.getController("tog3").moveTo("tab_performance");
  cp5.getController("tog4").moveTo("tab_performance");
  cp5.getController("tog5").moveTo("tab_performance");
  cp5.getController("tog6").moveTo("tab_performance");
  cp5.getController("tog7").moveTo("tab_performance");
  cp5.getController("tog8").moveTo("tab_performance");
  cp5.getController("tog9").moveTo("tab_performance");
  cp5.getController("tog10").moveTo("tab_performance");
  cp5.getController("tog11").moveTo("tab_performance");
  cp5.getController("tog12").moveTo("tab_performance");
  cp5.getController("tog13").moveTo("tab_performance");
  cp5.getController("tog14").moveTo("tab_performance");
  cp5.getController("tog15").moveTo("tab_performance");
  cp5.getController("tog16").moveTo("tab_performance");
  cp5.getController("tog17").moveTo("tab_performance");
  cp5.getController("tog18").moveTo("tab_performance");
  cp5.getController("tog19").moveTo("tab_performance");
  cp5.getController("tog20").moveTo("tab_performance");
  cp5.getController("tog21").moveTo("tab_performance");
  cp5.getController("tog22").moveTo("tab_performance");
  cp5.getController("list1").moveTo("tab_performance");


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
    .setCaptionLabel("save settings to flute");
  ;

  cp5.addToggle("toggleI")
    .setPosition(700, 300)
    .setSize(50, 20)
    .setValue(false)
    .setCaptionLabel("reset this preset");

  cp5.addToggle("toggleJ")
    .setPosition(50, 450)
    .setSize(50, 20)
    .setValue(false)
    .setCaptionLabel("load settings from disk");
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
    .setPosition(20, 160)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 6)
    .setMultiplier(0.1)
    .setCaptionLabel("1")
    ;
  ;

  cp5.addNumberbox("NA2")
    .setPosition(60, 160)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 6)
    .setMultiplier(0.1)
    .setCaptionLabel("2");
  ;

  cp5.addNumberbox("NA3")
    .setPosition(100, 160)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 6)
    .setMultiplier(0.1)
    .setCaptionLabel("3");
  ;

  cp5.addNumberbox("NA4")
    .setPosition(140, 160)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 6)
    .setMultiplier(0.1)
    .setCaptionLabel("4");
  ;

  cp5.addNumberbox("NA5")
    .setPosition(180, 160)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 6)
    .setMultiplier(0.1)
    .setCaptionLabel("5");
  ;

  cp5.addNumberbox("NA6")
    .setPosition(220, 160)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 6)
    .setMultiplier(0.1)
    .setCaptionLabel("6");
  ;

  cp5.addNumberbox("NA7")
    .setPosition(260, 160)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 6)
    .setMultiplier(0.1)
    .setCaptionLabel("7");
  ;

  cp5.addNumberbox("NA8")
    .setPosition(300, 160)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 6)
    .setMultiplier(0.1)
    .setCaptionLabel("8");
  ;

  cp5.addNumberbox("NA9")
    .setPosition(340, 160)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 6)
    .setMultiplier(0.1)
    .setCaptionLabel("9");
  ;

  cp5.addNumberbox("NA10")
    .setPosition(380, 160)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 6)
    .setMultiplier(0.1)
    .setCaptionLabel("10");
  ;

  cp5.addNumberbox("NA11")
    .setPosition(420, 160)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 6)
    .setMultiplier(0.1)
    .setCaptionLabel("11");
  ;

  cp5.addNumberbox("NA12")
    .setPosition(460, 160)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 6)
    .setMultiplier(0.1)
    .setCaptionLabel("12");
  ;

  cp5.addNumberbox("NA13")
    .setPosition(500, 160)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 6)
    .setMultiplier(0.1)
    .setCaptionLabel("13");
  ;

  cp5.addNumberbox("NA14")
    .setPosition(540, 160)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 6)
    .setMultiplier(0.1)
    .setCaptionLabel("14");
  ;

  cp5.addNumberbox("NA15")
    .setPosition(580, 160)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 6)
    .setMultiplier(0.1)
    .setCaptionLabel("15");
  ;

  cp5.addNumberbox("NA16")
    .setPosition(620, 160)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 6)
    .setMultiplier(0.1)
    .setCaptionLabel("16");
  ;

  cp5.addNumberbox("NA17")
    .setPosition(660, 160)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 6)
    .setMultiplier(0.1)
    .setCaptionLabel("17");
  ;

  cp5.addNumberbox("NA18")
    .setPosition(700, 160)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 6)
    .setMultiplier(0.1)
    .setCaptionLabel("18");
  ;

  cp5.addNumberbox("NA19")
    .setPosition(740, 160)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 6)
    .setMultiplier(0.1)
    .setCaptionLabel("19");
  ;

  cp5.addNumberbox("NA20")
    .setPosition(780, 160)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 6)
    .setMultiplier(0.1)
    .setCaptionLabel("20");
  ;

  cp5.addNumberbox("NA21")
    .setPosition(820, 160)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 6)
    .setMultiplier(0.1)
    .setCaptionLabel("21");
  ;

  cp5.addNumberbox("NA22")
    .setPosition(860, 160)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 6)
    .setMultiplier(0.1)
    .setDecimalPrecision(1)
    .setCaptionLabel("22");
  ;

  cp5.addNumberbox("NA23")
    .setPosition(900, 160)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 6)
    .setMultiplier(0.1)
    .setDecimalPrecision(1)
    .setCaptionLabel("23");
  ;

  cp5.addNumberbox("NA24")
    .setPosition(940, 160)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 6)
    .setMultiplier(0.1)
    .setDecimalPrecision(1)
    .setCaptionLabel("24");
  ;

  cp5.addNumberbox("NA25")
    .setPosition(980, 160)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 6)
    .setMultiplier(0.1)
    .setDecimalPrecision(1)
    .setCaptionLabel("25");
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
  cp5.getController("NA23").moveTo("tab_advanced");
  cp5.getController("NA24").moveTo("tab_advanced");
  cp5.getController("NA25").moveTo("tab_advanced");

  cp5.addTextlabel("label7")
    .setText("PHASE TARGET")
    .setPosition(50, 300)
    .setColorValue(0xffFFFFFF)//leading ff on hex color
    .setFont(font)
    ;

  cp5.addNumberbox("NB1")
    .setPosition(20, 360)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2)
    .setCaptionLabel("1");
  ;

  cp5.addNumberbox("NB2")
    .setPosition(60, 360)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2)
    .setCaptionLabel("2");
  ;

  cp5.addNumberbox("NB3")
    .setPosition(100, 360)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2)
    .setCaptionLabel("3");
  ;

  cp5.addNumberbox("NB4")
    .setPosition(140, 360)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2)
    .setCaptionLabel("4");
  ;

  cp5.addNumberbox("NB5")
    .setPosition(180, 360)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2)
    .setCaptionLabel("5");
  ;

  cp5.addNumberbox("NB6")
    .setPosition(220, 360)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2)
    .setCaptionLabel("6");
  ;

  cp5.addNumberbox("NB7")
    .setPosition(260, 360)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2)
    .setCaptionLabel("7");
  ;

  cp5.addNumberbox("NB8")
    .setPosition(300, 360)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2)
    .setCaptionLabel("8");
  ;

  cp5.addNumberbox("NB9")
    .setPosition(340, 360)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2)
    .setCaptionLabel("9");
  ;

  cp5.addNumberbox("NB10")
    .setPosition(380, 360)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2)
    .setCaptionLabel("10");
  ;

  cp5.addNumberbox("NB11")
    .setPosition(420, 360)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2)
    .setCaptionLabel("11");
  ;

  cp5.addNumberbox("NB12")
    .setPosition(460, 360)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2)
    .setCaptionLabel("12");
  ;

  cp5.addNumberbox("NB13")
    .setPosition(500, 360)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2)
    .setCaptionLabel("13");
  ;

  cp5.addNumberbox("NB14")
    .setPosition(540, 360)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2)
    .setCaptionLabel("14");
  ;

  cp5.addNumberbox("NB15")
    .setPosition(580, 360)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2)
    .setCaptionLabel("15");
  ;

  cp5.addNumberbox("NB16")
    .setPosition(620, 360)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2)
    .setCaptionLabel("16");
  ;

  cp5.addNumberbox("NB17")
    .setPosition(660, 360)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2)
    .setCaptionLabel("17");
  ;

  cp5.addNumberbox("NB18")
    .setPosition(700, 360)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2)
    .setCaptionLabel("18");
  ;

  cp5.addNumberbox("NB19")
    .setPosition(740, 360)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2)
    .setCaptionLabel("19");
  ;

  cp5.addNumberbox("NB20")
    .setPosition(780, 360)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2)
    .setCaptionLabel("20");
  ;

  cp5.addNumberbox("NB21")
    .setPosition(820, 360)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2)
    .setCaptionLabel("21");
  ;

  cp5.addNumberbox("NB22")
    .setPosition(860, 360)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2)
    .setCaptionLabel("22");
  ;

  cp5.addNumberbox("NB23")
    .setPosition(900, 360)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2)
    .setCaptionLabel("23");
  ;

  cp5.addNumberbox("NB24")
    .setPosition(940, 360)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2)
    .setCaptionLabel("24");
  ;

  cp5.addNumberbox("NB25")
    .setPosition(980, 360)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2)
    .setCaptionLabel("25");
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
  cp5.getController("NB23").moveTo("tab_advanced");
  cp5.getController("NB24").moveTo("tab_advanced");
  cp5.getController("NB25").moveTo("tab_advanced");

  cp5.addTextlabel("label8")
    .setText("SPEAKER GAIN")
    .setPosition(50, 500)
    .setColorValue(0xffFFFFFF)//leading ff on hex color
    .setFont(font)
    ;

  cp5.addNumberbox("NC1")
    .setPosition(20, 560)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2)
    .setCaptionLabel("1");
  ;

  cp5.addNumberbox("NC2")
    .setPosition(60, 560)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2)
    .setCaptionLabel("2");
  ;

  cp5.addNumberbox("NC3")
    .setPosition(100, 560)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2)
    .setCaptionLabel("3");
  ;

  cp5.addNumberbox("NC4")
    .setPosition(140, 560)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2)
    .setCaptionLabel("4");
  ;

  cp5.addNumberbox("NC5")
    .setPosition(180, 560)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2)
    .setCaptionLabel("5");
  ;

  cp5.addNumberbox("NC6")
    .setPosition(220, 560)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2)
    .setCaptionLabel("6");
  ;

  cp5.addNumberbox("NC7")
    .setPosition(260, 560)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2)
    .setCaptionLabel("7");
  ;

  cp5.addNumberbox("NC8")
    .setPosition(300, 560)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2)
    .setCaptionLabel("8");
  ;

  cp5.addNumberbox("NC9")
    .setPosition(340, 560)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2)
    .setCaptionLabel("9");
  ;

  cp5.addNumberbox("NC10")
    .setPosition(380, 560)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2)
    .setCaptionLabel("10");
  ;

  cp5.addNumberbox("NC11")
    .setPosition(420, 560)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2)
    .setCaptionLabel("11");
  ;

  cp5.addNumberbox("NC12")
    .setPosition(460, 560)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2)
    .setCaptionLabel("12");
  ;

  cp5.addNumberbox("NC13")
    .setPosition(500, 560)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2)
    .setCaptionLabel("13");
  ;

  cp5.addNumberbox("NC14")
    .setPosition(540, 560)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2)
    .setCaptionLabel("14");
  ;

  cp5.addNumberbox("NC15")
    .setPosition(580, 560)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2)
    .setCaptionLabel("15");
  ;

  cp5.addNumberbox("NC16")
    .setPosition(620, 560)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2)
    .setCaptionLabel("16");
  ;

  cp5.addNumberbox("NC17")
    .setPosition(660, 560)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2)
    .setCaptionLabel("17");
  ;

  cp5.addNumberbox("NC18")
    .setPosition(700, 560)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2)
    .setCaptionLabel("18");
  ;

  cp5.addNumberbox("NC19")
    .setPosition(740, 560)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2)
    .setCaptionLabel("19");
  ;

  cp5.addNumberbox("NC20")
    .setPosition(780, 560)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2)
    .setCaptionLabel("20");
  ;

  cp5.addNumberbox("NC21")
    .setPosition(820, 560)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2)
    .setCaptionLabel("21");
  ;

  cp5.addNumberbox("NC22")
    .setPosition(860, 560)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2)
    .setCaptionLabel("22");
  ;

  cp5.addNumberbox("NC23")
    .setPosition(900, 560)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2)
    .setCaptionLabel("23");
  ;

  cp5.addNumberbox("NC24")
    .setPosition(940, 560)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2)
    .setCaptionLabel("24");
  ;

  cp5.addNumberbox("NC25")
    .setPosition(980, 560)
    .setSize(50, 20)
    .setScrollSensitivity(1)
    .setRange(0, 100)
    .setMultiplier(0.2)
    .setCaptionLabel("25");
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
  cp5.getController("NC23").moveTo("tab_advanced");
  cp5.getController("NC24").moveTo("tab_advanced");
  cp5.getController("NC25").moveTo("tab_advanced");
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
    .setCaptionLabel("factory reset tuning");
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


      print("from teensy ");
      print(controlindex);
      print(", ");
      println(controlvalue);


      // Writes the strings to a file, each on a separate line

      switch(controlindex)//per incoming serial data from teensy, update controllers
      {

        //preset display
        case(0):
        cp5.get(Textfield.class, "preset").clear();
        cp5.get(Textfield.class, "preset").setText(str(int(controlvalue)));
        currentpreset=int(controlvalue);
        break;
        //ambience controls
        case(1):
        cp5.getController("knob1").setValue(controlvalue);
        break;
        case(2):
        cp5.getController("knob2").setValue(controlvalue);
        break;
        case(3):
        cp5.getController("knob3").setValue(controlvalue);
        break;
        case(6):
        cp5.getController("knob6").setValue(controlvalue);
        break;
        case(7):
        cp5.getController("knob7").setValue(controlvalue);
        break;
        case(8):
        cp5.getController("knob8").setValue(controlvalue);
        break;
        case(9):
        cp5.getController("knob9").setValue(controlvalue);
        break;
        case(12):
        cp5.getController("tog1").setValue(controlvalue);
        break;
        case(13):
        cp5.getController("tog2").setValue(controlvalue);
        break;
        case(14):
        cp5.getController("tog3").setValue(controlvalue);
        break;
        case(15):
        cp5.getController("tog4").setValue(controlvalue);
        break;
        case(16):
        cp5.getController("tog5").setValue(controlvalue);
        break;
        case(17):
        cp5.getController("tog6").setValue(controlvalue);
        break;
        case(18):
        cp5.getController("tog7").setValue(controlvalue);
        break;
        case(19):
        cp5.getController("tog8").setValue(controlvalue);
        break;
        case(20):
        cp5.getController("tog9").setValue(controlvalue);
        break;
        case(21):
        cp5.getController("tog10").setValue(controlvalue);
        break;
        case(22):
        cp5.getController("tog11").setValue(controlvalue);
        break;
        case(23):
        cp5.getController("tog12").setValue(controlvalue);
        break;
        case(24):
        cp5.getController("tog13").setValue(controlvalue);
        break;
        case(25):
        cp5.getController("tog14").setValue(controlvalue);
        break;
        case(26):
        cp5.getController("tog15").setValue(controlvalue);
        break;
        case(27):
        cp5.getController("tog16").setValue(controlvalue);
        break;
        case(28):
        cp5.getController("tog17").setValue(controlvalue);
        break;
        case(29):
        cp5.getController("tog18").setValue(controlvalue);
        break;
        case(30):
        cp5.getController("tog19").setValue(controlvalue);
        break;
        case(31):
        cp5.getController("tog20").setValue(controlvalue);
        break;
        case(32):
        cp5.getController("tog21").setValue(controlvalue);
        break;
        case(33):
        cp5.getController("tog22").setValue(controlvalue);
        break;
        //case(36):
        //cp5.getController("tog30").setValue(controlvalue);
        //break;
        

        case(41):
        cp5.getController("NA1").setValue(controlvalue);
        break;
        case(42):
        cp5.getController("NA2").setValue(controlvalue);
        break;
        case(43):
        cp5.getController("NA3").setValue(controlvalue);
        break;
        case(44):
        cp5.getController("NA4").setValue(controlvalue);
        break;
        case(45):
        cp5.getController("NA5").setValue(controlvalue);
        break;
        case(46):
        cp5.getController("NA6").setValue(controlvalue);
        break;
        case(47):
        cp5.getController("NA7").setValue(controlvalue);
        break;
        case(48):
        cp5.getController("NA8").setValue(controlvalue);
        break;
        case(49):
        cp5.getController("NA9").setValue(controlvalue);
        break;
        case(50):
        cp5.getController("NA10").setValue(controlvalue);
        break;
        case(51):
        cp5.getController("NA11").setValue(controlvalue);
        break;
        case(52):
        cp5.getController("NA12").setValue(controlvalue);
        break;
        case(53):
        cp5.getController("NA13").setValue(controlvalue);
        break;
        case(54):
        cp5.getController("NA14").setValue(controlvalue);
        break;
        case(55):
        cp5.getController("NA15").setValue(controlvalue);
        break;
        case(56):
        cp5.getController("NA16").setValue(controlvalue);
        break;
        case(57):
        cp5.getController("NA17").setValue(controlvalue);
        break;
        case(58):
        cp5.getController("NA18").setValue(controlvalue);
        break;
        case(59):
        cp5.getController("NA19").setValue(controlvalue);
        break;
        case(60):
        cp5.getController("NA20").setValue(controlvalue);
        break;
        case(61):
        cp5.getController("NA21").setValue(controlvalue);
        break;
        case(62):
        cp5.getController("NA22").setValue(controlvalue);
        break;
        case(63):
        cp5.getController("NA23").setValue(controlvalue);
        break;
        case(64):
        cp5.getController("NA24").setValue(controlvalue);
        break;
        case(65):
        cp5.getController("NA25").setValue(controlvalue);
        break;

        case(71):
        cp5.getController("NB1").setValue(controlvalue);
        break;
        case(72):
        cp5.getController("NB2").setValue(controlvalue);
        break;
        case(73):
        cp5.getController("NB3").setValue(controlvalue);
        break;
        case(74):
        cp5.getController("NB4").setValue(controlvalue);
        break;
        case(75):
        cp5.getController("NB5").setValue(controlvalue);
        break;
        case(76):
        cp5.getController("NB6").setValue(controlvalue);
        break;
        case(77):
        cp5.getController("NB7").setValue(controlvalue);
        break;
        case(78):
        cp5.getController("NB8").setValue(controlvalue);
        break;
        case(79):
        cp5.getController("NB9").setValue(controlvalue);
        break;
        case(80):
        cp5.getController("NB10").setValue(controlvalue);
        break;
        case(81):
        cp5.getController("NB11").setValue(controlvalue);
        break;
        case(82):
        cp5.getController("NB12").setValue(controlvalue);
        break;
        case(83):
        cp5.getController("NB13").setValue(controlvalue);
        break;
        case(84):
        cp5.getController("NB14").setValue(controlvalue);
        break;
        case(85):
        cp5.getController("NB15").setValue(controlvalue);
        break;
        case(86):
        cp5.getController("NB16").setValue(controlvalue);
        break;
        case(87):
        cp5.getController("NB17").setValue(controlvalue);
        break;
        case(88):
        cp5.getController("NB18").setValue(controlvalue);
        break;
        case(89):
        cp5.getController("NB19").setValue(controlvalue);
        break;
        case(90):
        cp5.getController("NB20").setValue(controlvalue);
        break;
        case(91):
        cp5.getController("NB21").setValue(controlvalue);
        break;
        case(92):
        cp5.getController("NB22").setValue(controlvalue);
        break;
        case(93):
        cp5.getController("NB23").setValue(controlvalue);
        break;
        case(94):
        cp5.getController("NB24").setValue(controlvalue);
        break;
        case(95):
        cp5.getController("NB25").setValue(controlvalue);
        break;

        case(101):
        cp5.getController("NC1").setValue(controlvalue);
        break;
        case(102):
        cp5.getController("NC2").setValue(controlvalue);
        break;
        case(103):
        cp5.getController("NC3").setValue(controlvalue);
        break;
        case(104):
        cp5.getController("NC4").setValue(controlvalue);
        break;
        case(105):
        cp5.getController("NC5").setValue(controlvalue);
        break;
        case(106):
        cp5.getController("NC6").setValue(controlvalue);
        break;
        case(107):
        cp5.getController("NC7").setValue(controlvalue);
        break;
        case(108):
        cp5.getController("NC8").setValue(controlvalue);
        break;
        case(109):
        cp5.getController("NC9").setValue(controlvalue);
        break;
        case(110):
        cp5.getController("NC10").setValue(controlvalue);
        break;
        case(111):
        cp5.getController("NC11").setValue(controlvalue);
        break;
        case(112):
        cp5.getController("NC12").setValue(controlvalue);
        break;
        case(113):
        cp5.getController("NC13").setValue(controlvalue);
        break;
        case(114):
        cp5.getController("NC14").setValue(controlvalue);
        break;
        case(115):
        cp5.getController("NC15").setValue(controlvalue);
        break;
        case(116):
        cp5.getController("NC16").setValue(controlvalue);
        break;
        case(117):
        cp5.getController("NC17").setValue(controlvalue);
        break;
        case(118):
        cp5.getController("NC18").setValue(controlvalue);
        break;
        case(119):
        cp5.getController("NC19").setValue(controlvalue);
        break;
        case(120):
        cp5.getController("NC20").setValue(controlvalue);
        break;
        case(121):
        cp5.getController("NC21").setValue(controlvalue);
        break;
        case(122):
        cp5.getController("NC22").setValue(controlvalue);
        break;
        case(123):
        cp5.getController("NC23").setValue(controlvalue);
        break;
        case(124):
        cp5.getController("NC24").setValue(controlvalue);
        break;
        case(125):
        cp5.getController("NC25").setValue(controlvalue);
        break;
        
         case(128):
        cp5.getController("toggleK").setValue(controlvalue);
        break;
         case(129):
        cp5.getController("toggleL").setValue(controlvalue);
        break;
        
        

        case(131):
        cp5.getController("toggleE").setValue(controlvalue);
        break;
        case(132):
        cp5.getController("toggleH").setValue(controlvalue);
        break;
        case(133):
        cp5.getController("listO").setValue(controlvalue);
        break;
        case(134):
        cp5.getController("toggleI").setValue(controlvalue);
        break;
        
        case(135):
        cp5.getController("toggleF").setValue(controlvalue);
        break;
        case(136):
        cp5.getController("list1").setValue(controlvalue);
        break;
        
        
        case(137):
        cp5.getController("toggleJ").setValue(controlvalue);
        break;
      }


      //****** pure byte data transmission
      if (saveafile==true)
      {
        //print("saving a file");
        if ((controlindex>154)&&(controlindex<460))
        {
          // println(controlindex);
          presetdata=presetdata+" "+str(controlvalue);
        }
        if (controlindex==131)//this value is sent by teensy to trigger actual save
        {
          saveafile=false;
          println(presetdata);
          String[] listy = split(presetdata, ' ');

          String savefilename=cp5.get(Textfield.class, "save file name").getText();
          if (savefilename.isEmpty()==false)
          {
            saveStrings(savefilename, listy);
            println(savefilename);
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
  if (myPort != null) myPort.write("130,"+"1" +" "); //update controls on GUI
}

//ambience control events***************************


void knob1(int theValue)// reverb amount
{
  if (myPort != null) myPort.write("1,"+str(theValue)+" ");
}

void knob2(int theValue)// reverb size
{
  if (myPort != null) myPort.write("2,"+str(theValue)+" ");
}

void knob3(int theValue)// reverb damping
{
  if (myPort != null) myPort.write("3,"+str(theValue)+" ");
}

void knob6(int theValue)// lp res
{
  if (myPort != null) myPort.write("6,"+str(theValue)+" ");
}

void knob7(int theValue)// lp freq
{
  if (myPort != null) myPort.write("7,"+str(theValue)+" ");
}

void knob8(int theValue)// hp res
{
  if (myPort != null) myPort.write("8,"+str(theValue)+" ");
}

void knob9(int theValue)// hp freq
{
  if (myPort != null) myPort.write("9,"+str(theValue)+" ");
}


void tog1(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("12,"+a +" ");
}

void tog2(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("13,"+a +" ");
}

void tog3(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("14,"+a +" ");
}

void tog4(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("15,"+a +" ");
}

void tog5(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("16,"+a +" ");
}

void tog6(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("17,"+a +" ");
}

void tog7(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("18,"+a +" ");
}

void tog8(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("19,"+a +" ");
}

void tog9(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("20,"+a +" ");
}

void tog10(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("21,"+a +" ");
}

void tog11(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("22,"+a +" ");
}

void tog12(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("23,"+a +" ");
}

void tog13(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("24,"+a +" ");
}

void tog14(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("25,"+a +" ");
}

void tog15(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("26,"+a +" ");
}

void tog16(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("27,"+a +" ");
}

void tog17(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("28,"+a +" ");
}

void tog18(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("29,"+a +" ");
}

void tog19(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("30,"+a +" ");
}

void tog20(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("31,"+a +" ");
}

void tog21(int theValue) //
{
  String a = str(theValue);
  if (myPort != null) myPort.write("32,"+a +" ");
}

void tog22(int theValue) // last note
{
  String a = str(theValue);
  if (myPort != null) myPort.write("33,"+a +" ");
}

//void tog30(int theValue) //chord preset
//{
//  String a = str(theValue);
//  if (myPort != null) myPort.write("36,"+a +" ");
//}

//void tog31(int theValue) //preset load
//{
//  String a = str(theValue);
//  if (myPort != null) myPort.write("37,"+a +" ");
//}

//void tog32(int theValue) //savephase
//{
//  String a = str(theValue);
//  if (myPort != null) myPort.write("38,"+a +" ");
//}

//void tog33(int theValue) //factory reset
//{
//  String a = str(theValue);
//  if (myPort != null) myPort.write("39,"+a +" ");
//}


//phase data

void NA1(int theValue)
{
  if (myPort != null) myPort.write("41,"+str(theValue)+" ");
}

void NA2(int theValue)
{
  if (myPort != null) myPort.write("42,"+str(theValue)+" ");
}
void NA3(int theValue)
{
  if (myPort != null) myPort.write("43,"+str(theValue)+" ");
}

void NA4(int theValue)
{
  if (myPort != null) myPort.write("44,"+str(theValue)+" ");
}

void NA5(int theValue)
{
  if (myPort != null) myPort.write("45,"+str(theValue)+" ");
}

void NA6(int theValue)
{
  if (myPort != null) myPort.write("46,"+str(theValue)+" ");
}

void NA7(int theValue)
{
  if (myPort != null) myPort.write("47,"+str(theValue)+" ");
}

void NA8(int theValue)
{
  if (myPort != null) myPort.write("48,"+str(theValue)+" ");
}

void NA9(int theValue)
{
  if (myPort != null) myPort.write("49,"+str(theValue)+" ");
}

void NA10(int theValue)
{
  if (myPort != null) myPort.write("50,"+str(theValue)+" ");
}

void NA11(int theValue)
{
  if (myPort != null) myPort.write("51,"+str(theValue)+" ");
}

void NA12(int theValue)
{
  if (myPort != null) myPort.write("52,"+str(theValue)+" ");
}

void NA13(int theValue)
{
  if (myPort != null) myPort.write("53,"+str(theValue)+" ");
}

void NA14(int theValue)
{
  if (myPort != null) myPort.write("54,"+str(theValue)+" ");
}

void NA15(int theValue)
{
  if (myPort != null) myPort.write("55,"+str(theValue)+" ");
}

void NA16(int theValue)
{
  if (myPort != null) myPort.write("56,"+str(theValue)+" ");
}

void NA17(int theValue)
{
  if (myPort != null) myPort.write("57,"+str(theValue)+" ");
}

void NA18(int theValue)
{
  if (myPort != null) myPort.write("58,"+str(theValue)+" ");
}

void NA19(int theValue)
{
  if (myPort != null) myPort.write("59,"+str(theValue)+" ");
}

void NA20(int theValue)
{
  if (myPort != null) myPort.write("60,"+str(theValue)+" ");
}

void NA21(int theValue)
{
  if (myPort != null) myPort.write("61,"+str(theValue)+" ");
}

void NA22(int theValue)
{
  if (myPort != null) myPort.write("62,"+str(theValue)+" ");
}

void NA23(int theValue)
{
  if (myPort != null) myPort.write("63,"+str(theValue)+" ");
}

void NA24(int theValue)
{
  if (myPort != null) myPort.write("64,"+str(theValue)+" ");
}

void NA25(int theValue)
{
  if (myPort != null) myPort.write("65,"+str(theValue)+" ");
}



void NB1(int theValue)
{
  if (myPort != null) myPort.write("71,"+str(theValue)+" ");
}

void NB2(int theValue)
{
  if (myPort != null) myPort.write("72,"+str(theValue)+" ");
}

void NB3(int theValue)
{
  if (myPort != null) myPort.write("73,"+str(theValue)+" ");
}

void NB4(int theValue)
{
  if (myPort != null) myPort.write("74,"+str(theValue)+" ");
}

void NB5(int theValue)
{
  if (myPort != null) myPort.write("75,"+str(theValue)+" ");
}

void NB6(int theValue)
{
  if (myPort != null) myPort.write("76,"+str(theValue)+" ");
}

void NB7(int theValue)
{
  if (myPort != null) myPort.write("77,"+str(theValue)+" ");
}

void NB8(int theValue)
{
  if (myPort != null) myPort.write("78,"+str(theValue)+" ");
}

void NB9(int theValue)
{
  if (myPort != null) myPort.write("79,"+str(theValue)+" ");
}

void NB10(int theValue)
{
  if (myPort != null) myPort.write("80,"+str(theValue)+" ");
}

void NB11(int theValue)
{
  if (myPort != null) myPort.write("81,"+str(theValue)+" ");
}

void NB12(int theValue)
{
  if (myPort != null) myPort.write("82,"+str(theValue)+" ");
}

void NB13(int theValue)
{
  if (myPort != null) myPort.write("83,"+str(theValue)+" ");
}

void NB14(int theValue)
{
  if (myPort != null) myPort.write("84,"+str(theValue)+" ");
}

void NB15(int theValue)
{
  if (myPort != null) myPort.write("85,"+str(theValue)+" ");
}

void NB16(int theValue)
{
  if (myPort != null) myPort.write("86,"+str(theValue)+" ");
}

void NB17(int theValue)
{
  if (myPort != null) myPort.write("87,"+str(theValue)+" ");
}

void NB18(int theValue)
{
  if (myPort != null) myPort.write("88,"+str(theValue)+" ");
}

void NB19(int theValue)
{
  if (myPort != null) myPort.write("89,"+str(theValue)+" ");
}

void NB20(int theValue)
{
  if (myPort != null) myPort.write("90,"+str(theValue)+" ");
}

void NB21(int theValue)
{
  if (myPort != null) myPort.write("91,"+str(theValue)+" ");
}

void NB22(int theValue)
{
  if (myPort != null) myPort.write("92,"+str(theValue)+" ");
}

void NB23(int theValue)
{
  if (myPort != null) myPort.write("93,"+str(theValue)+" ");
}

void NB24(int theValue)
{
  if (myPort != null) myPort.write("94,"+str(theValue)+" ");
}

void NB25(int theValue)
{
  if (myPort != null) myPort.write("95,"+str(theValue)+" ");
}


void NC1(int theValue)
{
  if (myPort != null) myPort.write("101,"+str(theValue)+" ");
}

void NC2(int theValue)
{
  if (myPort != null) myPort.write("102,"+str(theValue)+" ");
}

void NC3(int theValue)
{
  if (myPort != null) myPort.write("103,"+str(theValue)+" ");
}

void NC4(int theValue)
{
  if (myPort != null) myPort.write("104,"+str(theValue)+" ");
}

void NC5(int theValue)
{
  if (myPort != null) myPort.write("105,"+str(theValue)+" ");
}

void NC6(int theValue)
{
  if (myPort != null) myPort.write("106,"+str(theValue)+" ");
}

void NC7(int theValue)
{
  if (myPort != null) myPort.write("107,"+str(theValue)+" ");
}

void NC8(int theValue)
{
  if (myPort != null) myPort.write("108,"+str(theValue)+" ");
}

void NC9(int theValue)
{
  if (myPort != null) myPort.write("109,"+str(theValue)+" ");
}

void NC10(int theValue)
{
  if (myPort != null) myPort.write("110,"+str(theValue)+" ");
}

void NC11(int theValue)
{
  if (myPort != null) myPort.write("111,"+str(theValue)+" ");
}

void NC12(int theValue)
{
  if (myPort != null) myPort.write("112,"+str(theValue)+" ");
}

void NC13(int theValue)
{
  if (myPort != null) myPort.write("113,"+str(theValue)+" ");
}

void NC14(int theValue)
{
  if (myPort != null) myPort.write("114,"+str(theValue)+" ");
}

void NC15(int theValue)
{
  if (myPort != null) myPort.write("115,"+str(theValue)+" ");
}

void NC16(int theValue)
{
  if (myPort != null) myPort.write("116,"+str(theValue)+" ");
}

void NC17(int theValue)
{
  if (myPort != null) myPort.write("117,"+str(theValue)+" ");
}

void NC18(int theValue)
{
  if (myPort != null) myPort.write("118,"+str(theValue)+" ");
}

void NC19(int theValue)
{
  if (myPort != null) myPort.write("119,"+str(theValue)+" ");
}

void NC20(int theValue)
{
  if (myPort != null) myPort.write("120,"+str(theValue)+" ");
}

void NC21(int theValue)
{
  if (myPort != null) myPort.write("121,"+str(theValue)+" ");
}

void NC22(int theValue)
{
  if (myPort != null) myPort.write("122,"+str(theValue)+" ");
}

void NC23(int theValue)
{
  if (myPort != null) myPort.write("123,"+str(theValue)+" ");
}

void NC24(int theValue)
{
  if (myPort != null) myPort.write("124,"+str(theValue)+" ");
}

void NC25(int theValue)
{
  if (myPort != null) myPort.write("125,"+str(theValue)+" ");
}





void toggleE(boolean theFlag)//save settings to disk
{
  if (theFlag==true)
  {
    if (myPort != null)
    {
      myPort.write("131,"+"1" +" "); //tell teensy to dump byte values
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
      myPort.write("132,"+str(saveSlot) +" "); //tell teensy to save tunings to eeprom
    }
  }
}

void listO(int theValue) //save to eeprom
{
  saveSlot=theValue;//save eeprom locaton
  String a = str(theValue);
  if (myPort != null) myPort.write("133,"+a +" "); // send slot for saving ???? needed
}

void list1(int theValue) //scale selection
{
  scaleNumber=theValue;//save eeprom locaton
  String a = str(theValue);
  if (myPort != null) myPort.write("136,"+scaleNumber +" "); // send slot for saving ????needed
}

void toggleI(boolean theFlag)// reset this color
{
  if (theFlag==true)
  {
    if (myPort != null)
    {
      myPort.write("134,"+str(saveSlot) +" "); //tell teensy to reset to factory preset
    }
  }
}

void toggleF(boolean theFlag)// autoset scale
{
  if (theFlag==true)
  {
    if (myPort != null)
    {
      myPort.write("135,"+str(scaleNumber) +" "); //tell teensy to set scale
    }
  }
}


void toggleJ(boolean theValue)//load a preset from disk and send to teensy
{
  if ((myPort != null) && (theValue==true))
  {
    String filename=cp5.get(Textfield.class, "load file name").getText();
    if (filename.isEmpty()==false)
    {
      print("filename:");
      println(filename);
      print("data in lines:");


      lines =loadStrings(filename);
            println(lines.length);
      if (lines!=null)
      {
        for (int x=0; x<lines.length-1; x++)
        {
          lines[x]=lines[x+1];
          print(" ");
          print(lines[x]);
        }
        FileLoadUpdate();
      }
    }
  }
}

void toggleK(boolean theFlag)//save phase settings to eeprom
{
  if (theFlag==true)
  {
    if (myPort != null)
    {
      myPort.write("128,"+"1" +" "); //tell teensy to save phase settings to eeprom
    }
  }
}

void toggleL(boolean theFlag)// factory reset  
{
  if (theFlag==true)
  {
    if (myPort != null)
    {
      myPort.write("129,"+"1" +" "); //reset phase settings to factory preset
    }
  }
}





//********************************************************************************************
void FileLoadUpdate()//update values of teensy from disk file (holding byte values)
{

  int settingdata=0;
  //knob1 reverb amount
  settingdata= int(map(int(lines[1]), 0, 255, 0, 100)); //
  myPort.write("1,"+str(settingdata)+" ");


  // knob2  reverb size
  settingdata= int(map(int(lines[2]), 0, 255, 0, 100)); //
  myPort.write("2,"+str(settingdata)+" ");


  // knob 3 reverb damping
  settingdata= int(map(int(lines[3]), 0, 255, 0, 100)); //
  myPort.write("3,"+str(settingdata)+" ");



  // knob 6 LP resonance
  settingdata= int(map(int(lines[6]), 0, 255, 0, 100)); //
  myPort.write("6,"+str(settingdata)+" ");


  // knob7 LP frequency
  settingdata= int(map(int(lines[7]), 0, 255, 0, 10000));
  myPort.write("7,"+str(settingdata)+" ");

  // knob8 HP resonance
  settingdata= int(map(int(lines[8]), 0, 255, 0, 100));
  myPort.write("8,"+str(settingdata)+" ");


  // knob9 HP freq
  settingdata= int(map(int(lines[9]), 0, 255, 0, 10000));
  myPort.write("9,"+str(settingdata)+" ");


  // tog1
  settingdata= int(map(int(lines[12]), 0, 255, 0, 255));
  myPort.write("12,"+str(settingdata)+" ");


  // tog2
  settingdata= int(map(int(lines[13]), 0, 255, 0, 255));
  myPort.write("13,"+str(settingdata)+" ");

  // tog3
  settingdata= int(map(int(lines[14]), 0, 255, 0, 255));
  myPort.write("14,"+str(settingdata)+" ");

  // tog4
  settingdata= int(map(int(lines[15]), 0, 255, 0, 255));
  myPort.write("15,"+str(settingdata)+" ");

  // tog5
  settingdata= int(map(int(lines[16]), 0, 255, 0, 255));
  myPort.write("16,"+str(settingdata)+" ");

  // tog6
  settingdata= int(map(int(lines[17]), 0, 255, 0, 255));
  myPort.write("17,"+str(settingdata)+" ");

  // tog7
  settingdata= int(map(int(lines[18]), 0, 255, 0, 255));
  myPort.write("18,"+str(settingdata)+" ");

  // tog8
  settingdata= int(map(int(lines[19]), 0, 255, 0, 255));
  myPort.write("19,"+str(settingdata)+" ");

  // tog9
  settingdata= int(map(int(lines[20]), 0, 255, 0, 255));
  myPort.write("20,"+str(settingdata)+" ");

  // tog10
  settingdata= int(map(int(lines[21]), 0, 255, 0, 255));
  myPort.write("21,"+str(settingdata)+" ");

  // tog11
  settingdata= int(map(int(lines[22]), 0, 255, 0, 255));
  myPort.write("22,"+str(settingdata)+" ");

  // tog12
  settingdata= int(map(int(lines[23]), 0, 255, 0, 255));
  myPort.write("23,"+str(settingdata)+" ");

  // tog13
  settingdata= int(map(int(lines[24]), 0, 255, 0, 255));
  myPort.write("24,"+str(settingdata)+" ");

  // tog14
  settingdata= int(map(int(lines[25]), 0, 255, 0, 255));
  myPort.write("25,"+str(settingdata)+" ");

  // tog15
  settingdata= int(map(int(lines[26]), 0, 255, 0, 255));
  myPort.write("26,"+str(settingdata)+" ");

  // tog16
  settingdata= int(map(int(lines[27]), 0, 255, 0, 255));
  myPort.write("27,"+str(settingdata)+" ");

  // tog17
  settingdata= int(map(int(lines[28]), 0, 255, 0, 255));
  myPort.write("28,"+str(settingdata)+" ");

  // tog18
  settingdata= int(map(int(lines[29]), 0, 255, 0, 255));
  myPort.write("29,"+str(settingdata)+" ");

  // tog19
  settingdata= int(map(int(lines[30]), 0, 255, 0, 255));
  myPort.write("30,"+str(settingdata)+" ");

  // tog20
  settingdata= int(map(int(lines[31]), 0, 255, 0, 255));
  myPort.write("31,"+str(settingdata)+" ");

  // tog21
  settingdata= int(map(int(lines[32]), 0, 255, 0, 255));
  myPort.write("32,"+str(settingdata)+" ");

  // tog22
  settingdata= int(map(int(lines[33]), 0, 255, 0, 255));
  myPort.write("33,"+str(settingdata)+" ");


  // chordpreset
  settingdata= int(map(int(lines[36]), 0, 255, 0, 255));
  myPort.write("36,"+str(settingdata)+" ");

  // presetload
  settingdata= int(map(int(lines[37]), 0, 255, 0, 255));
  myPort.write("37,"+str(settingdata)+" ");

  // savephase
  settingdata= int(map(int(lines[38]), 0, 255, 0, 255));
  myPort.write("38,"+str(settingdata)+" ");

  // factory reset
  settingdata= int(map(int(lines[39]), 0, 255, 0, 255));
  myPort.write("39,"+str(settingdata)+" ");
  
  
  settingdata= int(map(int(lines[41]), 0, 255, 0, 255));
  myPort.write("41,"+str(settingdata)+" ");
  

 settingdata= int(map(int(lines[42]), 0, 255, 0, 255));
  myPort.write("42,"+str(settingdata)+" ");
  

 settingdata= int(map(int(lines[43]), 0, 255, 0, 255));
  myPort.write("43,"+str(settingdata)+" ");
  

 settingdata= int(map(int(lines[44]), 0, 255, 0, 255));
  myPort.write("44,"+str(settingdata)+" ");
  

 settingdata= int(map(int(lines[45]), 0, 255, 0, 255));
  myPort.write("45,"+str(settingdata)+" ");
  

 settingdata= int(map(int(lines[46]), 0, 255, 0, 255));
  myPort.write("46,"+str(settingdata)+" ");
  

 settingdata= int(map(int(lines[47]), 0, 255, 0, 255));
  myPort.write("47,"+str(settingdata)+" ");
  


 settingdata= int(map(int(lines[48]), 0, 255, 0, 255));
  myPort.write("48,"+str(settingdata)+" ");
  

 settingdata= int(map(int(lines[49]), 0, 255, 0, 255));
  myPort.write("49,"+str(settingdata)+" ");
  

 settingdata= int(map(int(lines[50]), 0, 255, 0, 255));
  myPort.write("50,"+str(settingdata)+" ");
  

 settingdata= int(map(int(lines[51]), 0, 255, 0, 255));
  myPort.write("51,"+str(settingdata)+" ");
  

 settingdata= int(map(int(lines[52]), 0, 255, 0, 255));
  myPort.write("52,"+str(settingdata)+" ");
  

 settingdata= int(map(int(lines[53]), 0, 255, 0, 255));
  myPort.write("53,"+str(settingdata)+" ");
  

 settingdata= int(map(int(lines[54]), 0, 255, 0, 255));
  myPort.write("54,"+str(settingdata)+" ");
  

 settingdata= int(map(int(lines[55]), 0, 255, 0, 255));
  myPort.write("55,"+str(settingdata)+" ");
  

 settingdata= int(map(int(lines[56]), 0, 255, 0, 255));
  myPort.write("56,"+str(settingdata)+" ");
  

 settingdata= int(map(int(lines[57]), 0, 255, 0, 255));
  myPort.write("57,"+str(settingdata)+" ");
  

 settingdata= int(map(int(lines[58]), 0, 255, 0, 255));
  myPort.write("58,"+str(settingdata)+" ");
  

 settingdata= int(map(int(lines[59]), 0, 255, 0, 255));
  myPort.write("59,"+str(settingdata)+" ");
  

 settingdata= int(map(int(lines[60]), 0, 255, 0, 255));
  myPort.write("60,"+str(settingdata)+" ");
  

 settingdata= int(map(int(lines[61]), 0, 255, 0, 255));
  myPort.write("61,"+str(settingdata)+" ");
  

 settingdata= int(map(int(lines[62]), 0, 255, 0, 255));
  myPort.write("62,"+str(settingdata)+" ");
  

 settingdata= int(map(int(lines[63]), 0, 255, 0, 255));
  myPort.write("63,"+str(settingdata)+" ");
  

 settingdata= int(map(int(lines[64]), 0, 255, 0, 255));
  myPort.write("64,"+str(settingdata)+" ");
  
  
   settingdata= int(map(int(lines[65]), 0, 255, 0, 255));
  myPort.write("65,"+str(settingdata)+" ");
  

   settingdata= int(map(int(lines[71]), 0, 255, 0, 255));
  myPort.write("71,"+str(settingdata)+" ");
  

 settingdata= int(map(int(lines[72]), 0, 255, 0, 255));
  myPort.write("72,"+str(settingdata)+" ");
  

 settingdata= int(map(int(lines[73]), 0, 255, 0, 255));
  myPort.write("73,"+str(settingdata)+" ");
  

 settingdata= int(map(int(lines[74]), 0, 255, 0, 255));
  myPort.write("74,"+str(settingdata)+" ");
  

 settingdata= int(map(int(lines[75]), 0, 255, 0, 255));
  myPort.write("75,"+str(settingdata)+" ");
  

 settingdata= int(map(int(lines[76]), 0, 255, 0, 255));
  myPort.write("76,"+str(settingdata)+" ");
  

 settingdata= int(map(int(lines[77]), 0, 255, 0, 255));
  myPort.write("77,"+str(settingdata)+" ");
  

 settingdata= int(map(int(lines[78]), 0, 255, 0, 255));
  myPort.write("78,"+str(settingdata)+" ");
  

 settingdata= int(map(int(lines[79]), 0, 255, 0, 255));
  myPort.write("79,"+str(settingdata)+" ");
  

 settingdata= int(map(int(lines[80]), 0, 255, 0, 255));
  myPort.write("80,"+str(settingdata)+" ");
  

 settingdata= int(map(int(lines[81]), 0, 255, 0, 255));
  myPort.write("81,"+str(settingdata)+" ");
  

 settingdata= int(map(int(lines[82]), 0, 255, 0, 255));
  myPort.write("82,"+str(settingdata)+" ");
  

 settingdata= int(map(int(lines[83]), 0, 255, 0, 255));
  myPort.write("83,"+str(settingdata)+" ");
  

 settingdata= int(map(int(lines[84]), 0, 255, 0, 255));
  myPort.write("84,"+str(settingdata)+" ");
  

 settingdata= int(map(int(lines[85]), 0, 255, 0, 255));
  myPort.write("85,"+str(settingdata)+" ");
  

 settingdata= int(map(int(lines[86]), 0, 255, 0, 255));
  myPort.write("86,"+str(settingdata)+" ");
  

 settingdata= int(map(int(lines[87]), 0, 255, 0, 255));
  myPort.write("87,"+str(settingdata)+" ");
  

 settingdata= int(map(int(lines[88]), 0, 255, 0, 255));
  myPort.write("88,"+str(settingdata)+" ");
  

 settingdata= int(map(int(lines[89]), 0, 255, 0, 255));
  myPort.write("89,"+str(settingdata)+" ");
  

 settingdata= int(map(int(lines[90]), 0, 255, 0, 255));
  myPort.write("90,"+str(settingdata)+" ");
  

 settingdata= int(map(int(lines[91]), 0, 255, 0, 255));
  myPort.write("91,"+str(settingdata)+" ");
  

 settingdata= int(map(int(lines[92]), 0, 255, 0, 255));
  myPort.write("92,"+str(settingdata)+" ");
  

 settingdata= int(map(int(lines[93]), 0, 255, 0, 255));
  myPort.write("93,"+str(settingdata)+" ");
  

 settingdata= int(map(int(lines[94]), 0, 255, 0, 255));
  myPort.write("94,"+str(settingdata)+" ");
  
  
   settingdata= int(map(int(lines[95]), 0, 255, 0, 255));
  myPort.write("95,"+str(settingdata)+" ");
  
  
    settingdata= int(map(int(lines[101]), 0, 255, 0, 255));
  myPort.write("101,"+str(settingdata)+" ");
  

 settingdata= int(map(int(lines[102]), 0, 255, 0, 255));
  myPort.write("102,"+str(settingdata)+" ");
  

 settingdata= int(map(int(lines[103]), 0, 255, 0, 255));
  myPort.write("103,"+str(settingdata)+" ");
  

 settingdata= int(map(int(lines[104]), 0, 255, 0, 255));
  myPort.write("104,"+str(settingdata)+" ");
  

 settingdata= int(map(int(lines[105]), 0, 255, 0, 255));
  myPort.write("105,"+str(settingdata)+" ");
  

 settingdata= int(map(int(lines[106]), 0, 255, 0, 255));
  myPort.write("106,"+str(settingdata)+" ");
  

 settingdata= int(map(int(lines[107]), 0, 255, 0, 255));
  myPort.write("107,"+str(settingdata)+" ");
  

 settingdata= int(map(int(lines[108]), 0, 255, 0, 255));
  myPort.write("108,"+str(settingdata)+" ");
  

 settingdata= int(map(int(lines[109]), 0, 255, 0, 255));
  myPort.write("109,"+str(settingdata)+" ");
  

 settingdata= int(map(int(lines[110]), 0, 255, 0, 255));
  myPort.write("110,"+str(settingdata)+" ");
  

 settingdata= int(map(int(lines[111]), 0, 255, 0, 255));
  myPort.write("111,"+str(settingdata)+" ");
  

 settingdata= int(map(int(lines[112]), 0, 255, 0, 255));
  myPort.write("112,"+str(settingdata)+" ");
  

 settingdata= int(map(int(lines[113]), 0, 255, 0, 255));
  myPort.write("113,"+str(settingdata)+" ");
  

 settingdata= int(map(int(lines[114]), 0, 255, 0, 255));
  myPort.write("114,"+str(settingdata)+" ");
  

 settingdata= int(map(int(lines[115]), 0, 255, 0, 255));
  myPort.write("115,"+str(settingdata)+" ");
  

 settingdata= int(map(int(lines[116]), 0, 255, 0, 255));
  myPort.write("116,"+str(settingdata)+" ");
  

 settingdata= int(map(int(lines[117]), 0, 255, 0, 255));
  myPort.write("117,"+str(settingdata)+" ");
  

 settingdata= int(map(int(lines[118]), 0, 255, 0, 255));
  myPort.write("118,"+str(settingdata)+" ");
  

 settingdata= int(map(int(lines[119]), 0, 255, 0, 255));
  myPort.write("119,"+str(settingdata)+" ");
  

 settingdata= int(map(int(lines[120]), 0, 255, 0, 255));
  myPort.write("120,"+str(settingdata)+" ");
  

 settingdata= int(map(int(lines[121]), 0, 255, 0, 255));
  myPort.write("121,"+str(settingdata)+" ");
  

 settingdata= int(map(int(lines[122]), 0, 255, 0, 255));
  myPort.write("122,"+str(settingdata)+" ");
  

 settingdata= int(map(int(lines[123]), 0, 255, 0, 255));
  myPort.write("123,"+str(settingdata)+" ");
  

 settingdata= int(map(int(lines[124]), 0, 255, 0, 255));
  myPort.write("124,"+str(settingdata)+" ");
  
  
   settingdata= int(map(int(lines[125]), 0, 255, 0, 255));
  myPort.write("125,"+str(settingdata)+" ");
  
  
  
  
  


  delay(2000);
  myPort.write("130,"+"1"+" "); //cause teensy to update GUI
}

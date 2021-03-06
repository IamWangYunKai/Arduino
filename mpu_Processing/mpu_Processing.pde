import processing.serial.*;

Serial myPort;  
boolean firstSample = true;

float [] RwAcc = new float[3]; 
float [] Gyro = new float[3]; 
float [] RwGyro = new float[3]; 
float [] Awz = new float[2]; 
float [] RwEst = new float[3];


int lastTime = 0;
int interval = 0;
float wGyro = 10.0;

int lf = 10;
byte[] inBuffer = new byte[100];

PFont font;
final int VIEW_SIZE_X = 800, VIEW_SIZE_Y = 800;


void setup() 
{
  size(800, 800, P3D);

  myPort = new Serial(this, "COM4", 9600);  

//font=loadFont("Vivaldii-48.vlw");
}


void readSensors() {
  if (myPort.available() > 0) {
    if (myPort.readBytesUntil(lf, inBuffer) > 0) {
      String inputString = new String(inBuffer);
      String [] inputStringArr = split(inputString, ',');

      RwAcc[0] = float(inputStringArr[0]) / 16384.0;
      RwAcc[1] = float(inputStringArr[1])/ 16384.0;
      RwAcc[2] = float(inputStringArr[2])/ 16384.0;

      Gyro[0] = float(inputStringArr[3]) / 131.0;
      Gyro[1] = float(inputStringArr[4]) / 131.0;
      Gyro[2] = float(inputStringArr[5]) / 131.0;
    }
  }
}


void normalize3DVec(float [] vector) {
  float R;
  R = sqrt(vector[0]*vector[0] + vector[1]*vector[1] + vector[2]*vector[2]);
  vector[0] /= R;
  vector[1] /= R;  
  vector[2] /= R;
}


float squared(float x) {
  return x*x;
}


void buildBoxShape() {
  //box(60, 10, 40);
  noStroke();
  beginShape(QUADS);

  //Z+ (绘图区域)
  fill(#00ff00);
  vertex(-30, -5, 20);
  vertex(30, -5, 20);
  vertex(30, 5, 20);
  vertex(-30, 5, 20);

  //Z-
  fill(#0000ff);
  vertex(-30, -5, -20);
  vertex(30, -5, -20);
  vertex(30, 5, -20);
  vertex(-30, 5, -20);

  //X-
  fill(#ff0000);
  vertex(-30, -5, -20);
  vertex(-30, -5, 20);
  vertex(-30, 5, 20);
  vertex(-30, 5, -20);

  //X+
  fill(#ffff00);
  vertex(30, -5, -20);
  vertex(30, -5, 20);
  vertex(30, 5, 20);
  vertex(30, 5, -20);

  //Y-
  fill(#ff00ff);
  vertex(-30, -5, -20);
  vertex(30, -5, -20);
  vertex(30, -5, 20);
  vertex(-30, -5, 20);

  //Y+
  fill(#00ffff);
  vertex(-30, 5, -20);
  vertex(30, 5, -20);
  vertex(30, 5, 20);
  vertex(-30, 5, 20);

  endShape();
}


void drawCube() {  
  pushMatrix();
  translate(400, 550, 0);
  scale(6, 6, 6);

  rotateX(HALF_PI * -RwEst[0]);
  rotateZ(HALF_PI * RwEst[1]);

  buildBoxShape();

  popMatrix();
}


void getInclination() {
  int w = 0;
  float tmpf = 0.0;
  int currentTime, signRzGyro;


  readSensors();
  normalize3DVec(RwAcc);

  currentTime = millis();
  interval = currentTime - lastTime;
  lastTime = currentTime;

  if (firstSample || Float.isNaN(RwEst[0])) { // NaN用来等待检查从arduino过来的数据
    for (w=0;w<=2;w++) {
      RwEst[w] = RwAcc[w];    // 初始化加速度传感器读数
    }
  }
  else {

    if (abs(RwEst[2]) < 0.1) {

      for (w=0;w<=2;w++) {
        RwGyro[w] = RwEst[w];
      }
    }
    else {
    
      for (w=0;w<=1;w++) {
        tmpf = Gyro[w]; 
        tmpf *= interval / 1000.0f;   
        Awz[w] = atan2(RwEst[w], RwEst[2]) * 180 / PI; 
        Awz[w] += tmpf; 
      }


      signRzGyro = ( cos(Awz[0] * PI / 180) >=0 ) ? 1 : -1;

      // 从Awz的角度值反向计算RwGyro的公式请查看网页 http://starlino.com/imu_guide.html
      for (w=0;w<=1;w++) {
        RwGyro[0] = sin(Awz[0] * PI / 180);
        RwGyro[0] /= sqrt( 1 + squared(cos(Awz[0] * PI / 180)) * squared(tan(Awz[1] * PI / 180)) );
        RwGyro[1] = sin(Awz[1] * PI / 180);
        RwGyro[1] /= sqrt( 1 + squared(cos(Awz[1] * PI / 180)) * squared(tan(Awz[0] * PI / 180)) );
      }
      RwGyro[2] = signRzGyro * sqrt(1 - squared(RwGyro[0]) - squared(RwGyro[1]));
    }

    for (w=0;w<=2;w++) RwEst[w] = (RwAcc[w] + wGyro * RwGyro[w]) / (1 + wGyro);

    normalize3DVec(RwEst);
  }

  firstSample = false;
}


void draw() {  
  getInclination();

  background(#555555);
  fill(#ffffff);
  
  textSize(20);
  //textFont(font, 20);
  //float temp_decoded = 35.0 + ((float) (temp + 13200)) / 280;
  //text("temp:\n" + temp_decoded + " C", 350, 250);
  text("RwAcc (G):\n" + RwAcc[0] + "\n" + RwAcc[1] + "\n" + RwAcc[2] + "\ninterval: " + interval, 20, 50);
  text("Gyro (°/s):\n" + Gyro[0] + "\n" + Gyro[1] + "\n" + Gyro[2], 220, 50);
  text("Awz (°):\n" + Awz[0] + "\n" + Awz[1], 420, 50);
  text("RwGyro (°/s):\n" + RwGyro[0] + "\n" + RwGyro[1] + "\n" + RwGyro[2], 20, 200);
  text("RwEst :\n" + RwEst[0] + "\n" + RwEst[1] + "\n" + RwEst[2], 220, 200);

  // display axes显示轴
  /*pushMatrix();
  translate(450, 250, 0);
  stroke(#ffffff);
  scale(100, 100, 100);
  line(0, 0, 0, 1, 0, 0);
  line(0, 0, 0, 0, -1, 0);
  line(0, 0, 0, 0, 0, 1);
  line(0, 0, 0, -RwEst[0], RwEst[1], RwEst[2]);
  popMatrix();
*/
  drawCube();
}
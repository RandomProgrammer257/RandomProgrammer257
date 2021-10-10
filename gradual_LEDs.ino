#define nPins 3
#define Max 1023
#define maxLight 255
#define dieZone 50

#define hi (Max-dieZone);
#define deo ((Max-2*dieZone)/(nPins+1));
#define wLo (hi - deo);

int pinS[3]={3,5,6};

void setup() {
 for(int i=0;i<3;i++){pinMode(pinS[i],OUTPUT);}
}

void loop() {

  long pinX[nPins];
  int Signalvalue = analogRead(A0);
  int anyLight = 0;
  for(int i=0;i<=nPins;i++){
    long pinx = 0;

    int dMin = i * deo + dieZone;
    int dMax = dMin + deo;
    
    if(Signalvalue > dMin && Signalvalue < dMax){
      pinx=(long)(Signalvalue-dMin) * maxLight / deo;
      anyLight += ( i < nPins );
    }  
    if(i < nPins) {
      pinX[i] = pinx;
    }else if(!anyLight){
       for(int j = 0; j < nPins; j ++){
          pinX[j] = pinx;
       }
    }
 }

    for(int j = 0; j < nPins; j ++){
    analogWrite(pinS[j], pinX[j]);
  }

}

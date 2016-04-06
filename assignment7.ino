/* Διαβάστε τον κώδικα, προσπαθήστε να καταλάβετε τι κάνει από μόνοι σας (σκοπίμως δεν έχουν μπει σχόλια που να εξηγούν
  τι κάνουν οι διάφορες εντολές) και μετά γράψτε μόνοι σας το υπόλοιπο πρόγραμμα με τις οδηγίες που θα βρείτε στα σχόλια.
  Χρησιμοποιήστε της μεταβλητές αληθείας (boolean) ώστε οι εντολές της κάθε κατάστασης (state) να εκτελούνται μόνο μια φορά.
  Ο σκοπός σας είναι, να τελειώσετε το πρόγραμμα στο σπίτι και όταν το δοκιμάσετε στο αμαξάκι, το αμαξάκι να επιδείξει
  την εξής συμπεριφορά:
  Θα προχωρήσει περίπου 20 εκατοστά και θα στρίψει 180 μοίρες (αυτό είναι ήδη έτοιμο για εσάς).
  Θα προχωρήσει ΕΠΙΠΛΕΟΝ περίπου 60 εκατοστά (δηλαδή πόσα απ' την αρχή της λειτουργίας του;) και θα στρίψει 90 μοίρες προς
  τα αριστερά.
  Τέλος, θα συνεχίσει να κινείται ευθεία, μέχρι να διανύσει συνολικά (από την αρχή δηλαδή της λειτουργίας του) 150 εκατοστά. */

#include <Smartcar.h>

Odometer encoderLeft(91), encoderRight(91); //balte tous palmous  ana metro
Gyroscope gyro(16); //bale tin katalili timi gia to giroskopio
Car folkracer;
boolean state1Done = false;
boolean state2Done = false;

void setup() {
  gyro.attach();
  encoderLeft.attach(3); //xrisimopiise ta  pins
  encoderRight.attach(2);
  encoderLeft.begin();
  encoderRight.begin();
  gyro.begin();
  folkracer.begin(encoderLeft, encoderRight, gyro);
  folkracer.enableCruiseControl();//3ekinise na elenxis tin taxitita
  folkracer.setSpeed(0.5);
}

void loop() {
  folkracer.updateMotors();
  unsigned long distance = encoderLeft.getDistance();
  distance = distance + encoderRight.getDistance();
  distance = distance / 2;
  if (distance > 20) {
    if (distance < 30) {
      if (state1Done == false) {
        folkracer.stop();
        folkracer.rotate(180);
        folkracer.setSpeed(0.5);
        state1Done = true;
      }
    }
  }
  if (distance > 80) { 
    if (distance < 90) {
      if (state2Done == false){
        folkracer.stop();
        folkracer.rotate(90);
        folkracer.setSpeed(0.5);
        state2Done=true;
      }
    }
  }
  if (distance > 150) { 
    
  }
}

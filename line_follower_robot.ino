//defining sensor pins
#define s1  3
#define s2  4
#define s3  5
#define s4  6
#define s5  7
#define s6  8
#define s7  9
#define s8  10

//defining motor pins
#define motor_right_forw  A2
#define motor_right_rev  A3

#define motor_left_forw  A0
#define motor_left_rev  A1

void setup(){

    // Initialization of PIN MODE 
   pinMode(s1, INPUT);
    pinMode(s2, INPUT);
    pinMode(s3, INPUT);
    pinMode(s4, INPUT);
    pinMode(s5, INPUT);
    pinMode(s6, INPUT);
    pinMode(s7, INPUT);
    pinMode(s8, INPUT);

    pinMode(motor_right_forw, OUTPUT);
    pinMode(motor_right_rev, OUTPUT);

    pinMode(motor_left_forw, OUTPUT);
    pinMode(motor_left_rev, OUTPUT);

}

void forward(){
    analogWrite(motor_right_forw, HIGH);
    analogWrite(motor_right_rev, LOW);

    analogWrite(motor_left_forw, HIGH);
    analogWrite(motor_left_rev, LOW);
}

void right(){

    analogWrite(motor_right_forw, LOW);
    analogWrite(motor_right_rev, HIGH);

    analogWrite(motor_left_forw, HIGH);
    analogWrite(motor_left_rev, LOW);
    
}

void left(){

    analogWrite(motor_right_forw, HIGH);
    analogWrite(motor_right_rev, LOW);

    analogWrite(motor_left_forw, LOW);
    analogWrite(motor_left_rev, HIGH);
    
}

void stop(){

    analogWrite(motor_right_forw, LOW);
    analogWrite(motor_right_rev, LOW);

    analogWrite(motor_left_forw, LOW);
    analogWrite(motor_left_rev, LOW);
    
}

void loop(){

    forward();
    

    //s1, s2, s7, s8 are on white
    if((digitalRead(s1) == 0) && (digitalRead(s8) == 0) && (digitalRead(s2) == 0) && (digitalRead(s7) == 0)
    && (digitalRead(s3) == 1) && (digitalRead(s6) == 1) && (digitalRead(s4) == 1) && (digitalRead(s5) == 1)){
        forward();
    }

    //s6, s7, s8 are on black
    if((digitalRead(s1) == 0) && (digitalRead(s8) == 1) && (digitalRead(s2) == 0) && (digitalRead(s7) == 1)
    && (digitalRead(s3) == 0) && (digitalRead(s6) == 1) && (digitalRead(s4) == 0) && (digitalRead(s5) == 0)){
        right();
    }

    //s1, s2, s3 are on black
    if((digitalRead(s1) == 1) && (digitalRead(s8) == 0) && (digitalRead(s2) == 1) && (digitalRead(s7) == 0)
    && (digitalRead(s3) == 1) && (digitalRead(s6) == 0) && (digitalRead(s4) == 0) && (digitalRead(s5) == 0)){
        left();
    }


    //all are on black
    if((digitalRead(s1) == 1) && (digitalRead(s8) == 1) && (digitalRead(s2) == 1) && (digitalRead(s7) == 1)
    && (digitalRead(s3) == 1) && (digitalRead(s6) == 1) && (digitalRead(s4) == 1) && (digitalRead(s5) == 1)){
        stop();
    }

  
   


}

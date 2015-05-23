# arduinoQuadripod
Arduino based quadripod with 3 servos

This quadripod is an autonomous robot, it can avoid obstacles with a mobile ultrasound sensor and can be controled by a bluetooth connexion (force direction or speed) 

Robot and code are strongly inspired by the "4legswalker" http://playground.arduino.cc/Main/4LegWalker   

See the robot in action (walking and avoiding obstacles ) :  https://www.youtube.com/watch?v=VJJ-kUMxDps

Robot block diagram :

<pre>
2*3.7V LiPo batteries -> lm2596 dc-dc to 6.5V -> 3 motions Servos + radar mini servo
          |                                           ^
          |                                           |
      Arduino nano -----------------------------------+
        |  |   |
        |  |  Status leds, buzzer...
        |  |
        |  Bluetooth HC-05 module
        |
   Ultra sound sensor
</pre>

![image](https://cloud.githubusercontent.com/assets/377778/7783785/c6ee8854-014e-11e5-91ca-8d9c6660f84c.jpg)

Without bluetooth :
![image](https://cloud.githubusercontent.com/assets/377778/7671552/a24be7e4-fcd5-11e4-8a29-57907ae6fc59.jpg)

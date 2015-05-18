# arduinoQuadripod
Arduino based quadripod with 3 servos

Robot and code strongly inspired from  the "4legswalker" http://playground.arduino.cc/Main/4LegWalker   

Robot in action (walking and avoiding obstacles ) :  https://www.youtube.com/watch?v=VJJ-kUMxDps

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

![image](https://cloud.githubusercontent.com/assets/377778/7671552/a24be7e4-fcd5-11e4-8a29-57907ae6fc59.jpg)

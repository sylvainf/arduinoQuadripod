# arduinoQuadripod
Arduino based quadripod with 3 servos


Robot block diagram :

<pre>
2*3.7V LiPo batteries -> lm2596 dc-dc to 6.5V -> 3 motions Servos + radar mini servo
          |                                           ^
          |                                           |
      Arduino nano -----------------------------------+
        |  |   |
        |  |  Status leds, buzzer...
        |  |
        |  Bluetooth control
        |
   Ultra sound sensor
</pre>

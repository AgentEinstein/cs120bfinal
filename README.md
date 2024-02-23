# cs120b Lab 7
Youtube Link: https://youtu.be/SKQay7kit2A

An automated plant care system involving a servo motor, soil sensor, and ultrasonic sensor
Hello, this is my automated plant care system featuring a soil sensor, ultrasonic sensor, and a
servo motor. I also have an LCD screen displaying the system's current state to the user. Here I
have 2 cups of soil labeled WET and DRY, to quickly and easily simulate different conditions of
a potential plant this system would take care of. I have 3 potential states: Idle, Watering, and
Alert. I’ll explain each state’s conditions and meanings as we move along. Here I have the
sensor placed in the wet soil and my LCD shows that the system is idle, with a moisture level of
400. Let me dry off the sensor and place it in the dry soil. As soon as the sensor displays a low
enough water level, the system is now in the watering state, as you see here. In this state, the
servo motor rotates 90 degrees, pushing the spigot of the water dispenser, causing water to
leak out. Okay, this dispenser isn’t actually connected to anything, but for the purposes of this
demonstration, pretend that it is dispensing water into the soil when it becomes dry. When I
place the sensor back into the wet soil, the motor turns back to its original position, stopping the
flow of water. Now we are back in the idle state. Let me show you these two states once more.
This might seem cool and all, but what happens when we run out of water? Let me demonstrate
that real quick by dumping the water into this separate container. (At this point, I temporarily
moved the ultrasonic sensor and disconnected the servo motor so I could move the dispenser
freely and put them back when I was done pouring) Now the LCD displays, “Water LOW”. As
you see, the dispenser is empty right now. This is known as the Alert state. The system goes
into this state when the distance detected by the ultrasonic sensor is greater than the distance
threshold (which is roughly the water dispenser’s height in centimeters) set in the code. The
motor will not turn while in this state regardless of the moisture level. The system will stay in
this state until the distance detected by the sensor is back below the threshold (meaning the
dispenser is replenished). Now, let’s pour back in the water I dumped previously. As you see,
the system is now back in the idle state when the water levels are high enough again. At this
point, normal operation should resume. I’ll dry off the sensor once more and as you see, it starts
watering again. Put it back and now it’s idle. And that concludes my demonstration. I hope you
enjoyed it!

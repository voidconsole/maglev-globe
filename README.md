<img width="2783" height="670" alt="1210167345" src="https://github.com/user-attachments/assets/9142035f-fffe-474d-923c-6eadfb2ecb5a" />

## **The Interactive Levitation-Based Wireless 3D Infographic**

A levitating globe that actually listens to you.
Not metaphorically. Literally.

This project combines magnetic levitation, servo-driven rotation mapping, custom geolocation math, Bluetooth control, and a full Android app built end-to-end to create an *interactive 3D infographic* for the G20 nations (or, honestly, whatever you want to point at on the planet).

You pick a country on the app ->
The globe realigns itself ->
RGB lighting matches the flag ->
And the whole thing floats in mid-air like it’s acting for a sci-fi movie.



https://github.com/user-attachments/assets/267d2f81-c088-4885-9614-61dbd61e7121



## **The Core Idea**

Build a levitating, continuously-spinning globe that:

* Locks magnetically without physical contact
* Rotates to a specific longitude on command
* Shows the dominant color of the selected country's flag
* Communicates with an Android app via Bluetooth
* Functions as a physical 3D data-visualization device

The result: a clean fusion of physics, hardware hacking, embedded systems, and Flutter magic.



## **Hardware Stuff**

### **Magnetic Levitation System**

* A central dipole inside the globe links to an opposite dipole placed above it.
* No bearings. No friction. Just air, magnets, a nylon wire from the bottom and pain-staking alignment.

### **Servo Drive**

* A continuous-rotation 360° servo (intentionally chosen for full revolution capability).
* Downside? No positional feedback.
* Solution? A clever hack:

  * Attach a thin flap to the servo shaft
  * Let it tap a fixed beam once per rotation
  * Record the sound
  * Measure RPM
  * Use math + trigonometry + Earth’s geometry to map **rotation time -> longitude**
* One-time calibration sets the 0° reference via Bluetooth.

### **Electronics**

* Arduino Uno
* HC-05 Bluetooth Module
* 360° Continuous Servo
* RGB LED (for flag-based color theming)



## **Control App (Flutter)**

Designed in Figma, fully implemented in Flutter.

### **Features**

* Connects to HC-05
* Shows live connection status
* Controls spin direction and speed
* Shows flag assets (custom-designed)
* Sends minimal-byte commands for maximum responsiveness
* Select a country -> instantly rotates the globe to face you



## **The Math (oversimplified)**

You want the servo to move X degrees.
But the servo only speaks “PWM power” and “time.”

So:

1. Measure the RPM precisely
2. Convert RPM -> degrees/second
3. Build a lookup table mapping longitudes -> required timing
4. Adjust for drift with periodic recalibration
5. Because Earth isn’t flat (sadly), use proper geolocation math for country alignment

The result: accurate, repeatable positioning from a motor that wasn’t designed for accuracy at all.



## **Build Log**

* Crafted a wooden stand with internal compartments and a sliding lid
* Sculpted and painted a thermocol globe
* Embedded the magnetic dipole and structural supports
* Designed the globe arch and servo mount
* Built the electronics system and wiring
* Fought with servo inaccuracies
* Invented the RPM audio-capture solution out of sheer stubbornness
* Wrote the Arduino control code
* Built the entire Android app
* Debugged Bluetooth reliability issues
* Mapped countries -> longitudes -> servo timing
* Added RGB graduation tied to each country’s flag
* Assembled everything into a functional, clean, interactive device



# **Installation & Setup**

#### **1. Upload the Firmware (globe.ino)**
#### **2. Install the App (globe.apk)**
#### **3. Assemble components (hc-05 and servo to the arduino uno)**
#### **4. Connect via bluetooth and enjoy**

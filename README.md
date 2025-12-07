<img width="2783" height="670" alt="1210167345" src="https://github.com/user-attachments/assets/9142035f-fffe-474d-923c-6eadfb2ecb5a" />

## **The Interactive Levitation-Based Wireless 3D Infographic**

This project combines magnetic levitation, servo-driven rotation mapping, custom geolocation math, Bluetooth control, and an Android app built end-to-end to create an interactive 3D infographic for the G20 nations (or, honestly, whatever you want to point at on the planet).


### **What I actually built**

* A magnetically levitating globe using a dipole pairing (one inside the globe, one above it) plus a bottom nylon support
* A continuous-rotation servo hidden inside the stand
* A rotation-mapping system based entirely on timing, RPM measurement, and some geometry
* An RGB lighting setup tied to each selected country
* A full Android app (Flutter) to control everything over Bluetooth

https://github.com/user-attachments/assets/267d2f81-c088-4885-9614-61dbd61e7121




---

### **The servo problem and the hack**

Continuous-rotation servos don’t know their own position, which makes them terrible for accuracy. I got around that by attaching a tiny flap to the servo shaft so it taps a fixed beam once per full rotation. That click gives me RPM. From there:

* RPM -> degrees per second
* Degrees per second -> timing for each longitude
* One Bluetooth-based calibration to set “zero”
* Then some geolocation math to make sure each country is actually facing forward

It’s a dumb hack on paper but ridiculously effective in practice.

### **Electronics setup**

* Arduino Uno
* HC-05 Bluetooth module
* 360° servo
* RGB LED
  Simple parts, but pushed hard.

### **About the app**

I designed the UI in Figma and built the whole thing in Flutter. It:

* Connects to the HC-05
* Shows live status
* Lets me control direction/speed
* Displays custom flag assets
* Sends minimal command bytes for near-instant reactions
  Tap a country -> globe rotates -> lighting changes.

### **Build process**

* Made a wooden stand with hidden compartments
* Sculpted and painted the thermocol globe
* Installed the magnetic system
* Built the servo mount and arch
* Fought servo drift for way too long
* Invented the “RPM via sound tap” method
* Wrote the Arduino firmware
* Built the Flutter app
* Mapped every country’s longitude
* Synced RGB colors with flags
* Final assembly and fine-tuning

### **Setup now**

* Upload the firmware
* Install the APK
* Connect the HC-05 and servo to the Arduino
* Pair your phone
* Use the app

And that’s it, a levitating, app-controlled, data-driven globe that moves on command and glows with each country’s colors.

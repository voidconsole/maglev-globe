<img width="2783" height="670" alt="1210167345" src="https://github.com/user-attachments/assets/9142035f-fffe-474d-923c-6eadfb2ecb5a" />

## **The Interactive Levitation-Based Wireless 3D Infographic**

This project combines magnetic levitation, servo-driven rotation mapping, custom geolocation math, Bluetooth control, and an Android app built end-to-end to create an interactive 3D infographic for the G20 nations (or, honestly, whatever you want to point at on the planet).


**What I actually built**

* A magnetically levitating globe using a dipole pairing (one inside the globe, one above it) plus a bottom nylon support
* A continuous-rotation servo hidden inside the stand
* A rotation-mapping system based entirely on timing, RPM measurement, and some geometry
* An RGB lighting setup tied to each selected country
* A full Android app (Flutter) to control everything over Bluetooth

https://github.com/user-attachments/assets/267d2f81-c088-4885-9614-61dbd61e7121

The globe stays suspended using a dipole magnetic pairing with a nylon support at the bottom for stability. I tucked a 360 degree servo and an RGB setup inside a custom wooden stand with hidden compartments. Everything runs on an Arduino Uno and connects to a Flutter app via an HC-05 Bluetooth module.

One of the biggest engineering hurdles was the fact that continuous rotation servos do not provide position feedback. To fix this, I attached a small flap to the servo shaft that hits a fixed beam once per rotation. By measuring the time between those clicks, I can calculate the RPM and convert that into degrees per second. I used this timing along with a calibration step to make sure the globe spins exactly to the correct longitude for any country.

I designed the interface in Figma and built the app in Flutter to send minimal command bytes for low latency. When you tap a country in the app, the globe rotates to the right spot and the RGB LEDs change to match the colors of that country's flag.

The build process involved sculpting the thermocol globe, writing the Arduino firmware, and fighting servo drift for a long time until the rotation was precise. The final result is a fully synced, data-driven globe that reacts instantly to the app.

And that’s it, a levitating, app-controlled, data-driven globe that moves on command and glows with each country’s colors.

**Why**
- To explore the possibilities of the bluetooth enabled robotics
- To try mobile connectivity with an arduino uno
- To present as a exibition artifact
- To blend aesthetics with functionality


**How to**
- Take a thermocol ball and insert a bar magnet horizontally inside it. A string should be tied to the center of the magnet and it should be drown out of the the globe perpendicular to the magnets, downwards, and tie it to the base plate.
- Another bar magnet to be attached to a servo and the servo should be mounted on the stand in such a way that the bar magnet of the servo is parallel to the bar magnet hidden inside the globe. 
- The above system will make the globe suspended in the air as the bar magnets will attract each other but the string is just short enough that it doesn't let them fully snap.
- Since we're using bar magnets, the servo magnet and the globe magnet will be in sync in rotation, the polar end maintaining their attraction.
- That should complete the maglev part. A rgb led can be fixed under the globe or as preferred.
- The rest of the electronics can be wired according to the schematics and hidden inside a box beneath the base.
- The globe.ino code should be uploaded to the arduino.
- The globe.apk should be downloaded on an Android phone, and when the arduino and circuitry is powered on and active, one should connect that android phone to the circuit's bluetooth.
- A successful connection will be shown in the app and from then on all could be controlled via the phone.

<img width="969" height="797" alt="image" src="https://github.com/user-attachments/assets/341237a2-5516-4cd7-93a8-0ff4917fe2a4" />
<img width="867" height="823" alt="image" src="https://github.com/user-attachments/assets/c1fe46ef-7233-4184-9be2-a5b13fb8191f" />
<img width="818" height="871" alt="image" src="https://github.com/user-attachments/assets/28785b87-469c-46ae-b0d3-b9d17796b684" />

|Name|Description|Amount| Cost|Link|Running Total|
|----|-----------|------|-----|----|-------------|
|Arduino Uno|Execute code and handle components|1x|15$|https://a.co/d/bmDaQzY|15$|
|HC-05 Module|Connect to phone app via bluetooth|1x|12$|https://a.co/d/aNaK21Q|27$|
|Servo 360|Control globe spin|1x|11$|https://a.co/d/8QtKBlF|38$|
|Magnets|Crux of maglev|12x disks of neodymium|10$|https://a.co/d/8QtKBlF|48$|
|Plywood|To craft the stand and holder|50cm^2|8$|https://a.co/d/0e6iqHY|56$|
|Stryoball|To carve the globe|5cm radius ball of styrofoam|8$|https://a.co/d/0e6iqHY|64$|
|RGB LED|For cool effects|1x small diode|7$|https://a.co/d/2UdZyUL|71$|
|Nylon String|Tension against magnet|10cm|7$|https://a.co/d/aRDm3VX|78$|
|Decor (Optional)|Paper, cotton, paint, pins|As preferred|10$?|As preferred|88$|

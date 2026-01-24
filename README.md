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

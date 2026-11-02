\# Laboratory Activity 6: Basic Actuator Control



\## 1. Specifications \& Datasheets

\* \*\*DC Actuator (Hobby Round DC Toy Motor / RF-300 / 130-size):\*\*

&#x20; \* \*\*Operating Voltage:\*\* 3V – 6V DC

&#x20; \* \*\*No-Load Current:\*\* \~50 mA – 100 mA

&#x20; \* \*\*Stall Current:\*\* \~500 mA – 800 mA at 5V

&#x20; \* \*\*Datasheet:\*\* \[Standard Small DC Toy Motor Specifications](https://components101.com/motors/130-dc-motor)

\* \*\*Driver Breakout Board (L298N Dual H-Bridge Module):\*\*

&#x20; \* \*\*Motor Supply Voltage ($V\_M$ / $V\_{CC}$):\*\* 5V – 35V

&#x20; \* \*\*Logic Voltage ($V\_{SS}$):\*\* 5V (regulated on-board when 5V jumper is in place)

&#x20; \* \*\*Peak Output Current:\*\* 2A per bridge

&#x20; \* \*\*Datasheet:\*\* \[STMicroelectronics L298N Datasheet](https://www.st.com/resource/en/datasheet/l298.pdf)



\---



\## 2. Driver Pin Explanations (L298N vs DRV8833 Equivalent)

\* \*\*`VM / +12V Terminal`:\*\* Main motor supply rail. Connected here to an external 5V rail (tapped from the USB-powered Arduino Uno) to isolate inductive motor currents from the ESP32 power rail.

\* \*\*`Common Ground (GND)`:\*\* Establishes a common 0V electrical reference between the ESP32 microcontroller, the L298N driver board, and the external power source.

\* \*\*`ENA` (nSLEEP Equivalent):\*\* Channel A bridge enable input. When pulled HIGH (or driven via PWM), it activates the H-bridge output; when pulled LOW, it disables the outputs into high-impedance freewheel mode.

\* \*\*`IN1` \& `IN2` (AIN1 / AIN2 Equivalent):\*\* Directional logic control pins for Channel A:

&#x20; \* \*\*Run (Forward/Reverse):\*\* One pin HIGH, opposite pin LOW.

&#x20; \* \*\*Brake:\*\* Both pins HIGH (or both LOW with ENA active) creates dynamic braking by shorting windings through the bridge.

&#x20; \* \*\*Coast (Freewheeling):\*\* Removing drive (ENA held LOW or IN1/IN2 both LOW) allows mechanical inertia to spin the rotor down naturally.



\---



\## 3. Experimental Observations \& Measurements

\* \*\*Run/Coast Behavior:\*\* Pressing the breadboard pushbutton initiates drive output, spinning the DC motor. Releasing the button ceases signal propagation, causing the motor to freewheel (coast) to a halt rather than stopping abruptly via active short-circuit braking.

\* \*\*Deadband \& Rotation Onset:\*\*

&#x20; \* \*\*PWM Resolution:\*\* 8-bit (0 – 255)

&#x20; \* \*\*Measured Onset of Rotation:\*\* Duty cycle \~`70/255` (\~27.5%).

&#x20; \* \*\*Observation:\*\* Because the L298N uses bipolar junction transistors (BJTs) with a \~1.4V–2V internal voltage drop, plus mechanical brush and bearing friction on the round DC motor, the shaft will not spin below approximately 25–30% duty cycle.



\---



\## 4. Hardware Setup Evidence

!\[Physical Setup](docs/wiring\_diagram.png)


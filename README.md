Follow this wiring diagram for the HC-SR04 ultrasonic sensor: ![image](https://github.com/user-attachments/assets/eb05a3ee-d7cf-466b-8b87-67265901112a)


I used 1KΩ and 2KΩ resistors instead of 330Ω and 470Ω (because it's what I had on hand).

Test the wiring with the [Python script](test.py).

Then install [WiringPi](https://github.com/WiringPi/WiringPi) , the fastest RPi GPIO access library:

```bash
git clone https://github.com/WiringPi/WiringPi.git
cd WiringPi
./build debian
mv debian-template/wiringpi_3.10_arm64.deb .
sudo apt install ./wiringpi_3.10_arm64.deb
```

Compile the [C++ program](main.cpp) (linking wiringPi):
```bash
g++ -o ultrasonic main.cpp -l wiringPi
```

And run:

```bash
./ultrasonic
```

If everything worked correctly, you should see something like this:
```bash
66.7 cm
66.2 cm
65.8 cm
4.8 cm
24.4 cm
23.6 cm
4.9 cm
```

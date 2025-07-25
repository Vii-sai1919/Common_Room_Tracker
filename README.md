# Common Room Tracker
A simple Arduino-based device to help students track the occupancy of hostel common rooms in real-time.

## Project Description
When students move between hostels, they often waste time and energy carrying luggage while searching for vacant common rooms. This project solves that by providing a small device that counts students entering a common room and displays live occupancy status.

## Each device:
- Uses a pushbutton (or sensor) to count students.
- Displays the current count and room status (`Open`, `Rush`, `Closing Soon`, `Full`) on an LCD.
- Helps students and staff manage room capacity efficiently.

## How It Works
- Pushbutton: Each press adds one student to the count.
- LCD Display: Shows current student count and status.
  - `0–69` → Open
  - `70–89` → Hurry Up!
  - `90–99` → Closing Soon
  - `100` → Full (closed)

##  Materials Used
- Arduino Uno Rev 3 (or ESP32 for Wi-Fi version)
- 16x2 LCD Display
- Pushbutton switch
- Resistors (220Ω, 10kΩ)
- Breadboard & jumper wires

## Code Overview
- Written in Arduino C++ using the `LiquidCrystal` library.
- Debounce logic ensures accurate counting.
- Display auto-updates with each press.

## Made By:
- Vighnesh Shankar
- Bharat Gahlawat


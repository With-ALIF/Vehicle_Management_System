# Vehicle Management System  
*A Command-Line Based Software Project*

---

## Background & Motivation

Modern transport systems involve managing multiple types of vehicles— `cars, buses, bikes, trucks, and many` others. Even in a simplified environment, keeping track of vehicle records becomes difficult without a structured system.  

Key information such as `model name, registration number, brand, engine capacity, and manufacturing year` must be stored, retrieved, updated, and removed as the fleet grows or changes.

This project focuses on building a `menu-driven command-line Vehicle Management System` that simulates a lightweight vehicle database using basic data structures only. The primary objective is to design a proram capable of performing structured operations on `multiple vehicle` records and simulatimg a lightweight information management process.

---

# Problem Statement

Design and implement a **Vehicle Management System** that allows users to:

- Store information about different types of vehicles  
- Perform structured operations such as `add new vehicle, list all vehicles, search for specific vehicles, update existing vehicles, and delete records` 

The system should continue functioning correctly regardless of how many operations the user performs, until the user explicitly exits the program.
Your progra will simulate how vehicle operations mignt work in a very simplified database, using only `basic data structures and manula handling of records`.

---

##  Core Requirements

### 1 Vehicle Data Structure

Each vehicle must store at least the following attributes:

- **Vehicle ID** (unique numeric identifier)  
- **Vehicle Type** (Car, Bus, Bike, Truck, etc.)  
- **Model Name**  
- **Brand / Manufacturer**  
- **Year of Manufacture**  
- **Engine Capacity** (numeric in cc or descriptive text)

**Optional Attributes (Encouraged):**
- Color  
- Fuel Type  
- Seat Count

---

## 2. Required Operations (Main Menu)

The system must be **menu-driven** and include the following functions:

---

### A. Add New Vehicle

- Prompt the user to enter all required attributes  
- Validate that the **Vehicle ID is unique**  
- Store the vehicle in an internal data structure (array or similar)  
- Display a confirmation message upon successful insertion  

---

### B. Show All Vehicles

- Display all stored vehicles in a **clear, readable format**  
- Show **all attributes** for each vehicle  
- If no records exist, display an appropriate message  

---

### C. Search for a Vehicle

Provide **at least two search methods**:

1. Search by **Vehicle ID**  
2. Search by **Vehicle Type** or **Model Name**

Search process:
- Prompt the user for search input  
- Scan through all stored records  
- Display matching vehicle(s) with full details  
- Display **“Vehicle not found”** if no match exists  

---

### D. Update Vehicle Information

- Ask for a **Vehicle ID**  
- If found:
  - Display current details  
  - Allow modification of one or more fields  
- Save and confirm the updated record  

---

### E. Delete a Vehicle

- Prompt for a **Vehicle ID**  
- Locate and remove the record  
- Shift remaining records if necessary to maintain continuity  
- Confirm successful deletion  

---

### F. Exit Program

- Terminate the application cleanly  
- Ensure no data corruption occurs  

---

## 3. Functional Constraints

### 1 Manual Data Storage Only
- All vehicles must be stored in arrays, structures, or basic data constructs. 
-  No external database, files, or advanced libraries.

### 2 Maximum Record Limit
- Define a maximum number of vehicles (e.g., 100 or 200)  

### 3 Unique Vehicle IDs
- Duplicate IDs must not be allowed  
- If entered, prompt the user to retry or tyr again  

### 4 Input Validation
- System should handle invalid user inputs (e.g., letters instead of numbers). 

### 5 Consistent Menu Loop
- The program must not terminate until the user explicitly selects Exit.

### 6 Record Integrity
- Updating or deleting must not affect other records  
- All operations should maintain the integrity of stored data 

### 7 Separation of Logic *(Optional but Recommended)*

Suggested modular functions:
``` bash
- addVehicle() 
- showVehicles()
- searchVehicle()
- updateVehicle()
- deleteVehicle()
```  

---

## 4. Advanced Features & Operations

### 4.1 Filter Vehicles (Multiple Conditions)

- Vehicles manufactured **after 2015 AND engine capacity > 1500cc**  
- All bikes with engine capacity **below 150cc**  
- All buses of brand **Volvo** between **2010–2020**

--- 

### 4.2 Sort Vehicles (Multiple Criteria)

- Sort by **Year of Manufacture (Descending)**  
- Sort by **Brand Name (Alphabetical)**  
- Sort by **Engine Capacity**, and if equal, then by **Model Name**

---

### 4.3 Duplicate Detection Across Attributes

Detect:
- Same **model name**, different IDs  
- Same **brand and year**  
- Any duplicate model names in the system  

---

### 4.4 Bulk Delete Operations

Examples:
- Delete all vehicles older than **2010**  
- Delete all bikes with engine capacity **< 100cc**  
- Delete all vehicles of brand **Toyota**

---

### 4.5 Partial Update for Multiple Records

Examples:
- Increase engine capacity of all trucks by **+200cc**  
- Update the brand name **“Honda” to “Honda Motors”**  everywhere
- Convert vehicle type **“Bike” to “Motorcycle”** for all matching entries

---

### 4.6 Summary Statistics

Generate:
- Count of vehicles by type  `Car = 5,Bus = 2, Bike = 12`
- Vehicle with the highest engine capacity  
- Average manufacturing year for cars  
- Percentage of vehicles manufactured after `2020`

---

### 4.7 Group Vehicles by Category

Example Output:
```
Cars:
[list of cars]

Bikes:
[list of bikes]

Trucks:
[list of trucks]

Others:
[list]
```

---

### 4.8 Dynamic Data Expansion

- When maximum capacity is reached, allow adding more vehicles
  - Increase capacity dynamically (e.g., +20 records)  

---

### 4.9 Clone Vehicle Record (Template Creation)

- Copy a vehiclee with `ID X`to create a new one with a different `ID`
- Useful for creating `similar` vehicles quickly  

---

### 4.10 Report View

Example:
```
Total Vehicles: 20
Average Engine Capacity: 1250cc
Oldest Vehicle Year: 1998
Newest Vehicle Year: 2024

Brand Distribution:
Toyota: 5
Honda: 3
Bajaj: 4
Others: 8
```

---

### 4.11 Multiple Vehicle Types with Specialized Attributes

Examples:
- **Car** → Seat Count  
- **Bike** → Gear Count  
- **Bus** → Route Number  

---

### 4.12 Universal Text-Based Search

- Convert each record into a searchable string  
- Search any keyword across all fields  

Examples:
- Input: `2020` → Show all vehicles containing “2020”  
- Input: `Honda` → Show all Honda vehicles  

---

### 4.13 Undo Last Operation

Allow undo for:
- Add  
- Update  
- Delete  

*(Undo only the most recent operation)*

---

### Data Validation (Input Rules)

- **Vehicle Type:** Accept only predefined types (Car, Bike, Truck, Bus, Electric Vehicle). Reject invalid types.

- **Vehicle ID:** Auto-generated IDs use the format `V%03d`. If allowing manual IDs, require uniqueness and reject duplicates.

- **Year of manufacture:** Accept only integers; require `year >= 1999` (or configurable minimum). Reject otherwise.

- **Engine capacity (cc):** Validate per type:
  - Bike: `80` to `2000`
  - Car: `750` to `2000` 
  - Truck: `2000` to `7500` 
  - Bus: `1500` to `35000` 

- **Gear count (Bike):** Integer, typically `<= 4`.

- **Seat count (Car / Bus):** Validate ranges (Car: `02–12` in code; Bus: `20–50`). Use retry attempts when out-of-range.

- **Battery capacity (EV):** Integer range used in code examples: `1000`–`12000` kWh; billing uses this value to compute charges.

- **Charge time (EV):** Integer hours, e.g. `1`–`24`.

- **Strings (model, brand, fuel type, route):** Use scans that limit input length and trim trailing newlines 

- **Retry policy:** For some fields the program allows up to **2 attempts** before aborting the add operation — keep this consistent for engine, seat, gear, battery, and charge-time inputs.

---

### 6. Billing Module 

**Rules by Vehicle Type:**
- **Bike:** Tiered by engine capacity and scaled by gear count (gear count capped during input).
  - Engine Capacity <=100 cc: `300 + (gearCount * 50)`
  - Engine Capacity 101–150 cc: `400 + (gearCount * 75)`
  - Engine Capacity >150 cc: `500 + (gearCount * 100)`

- **Car:** Tiered by engine capacity.
  - Engine Capacity <=1000 cc: `1500` TK
  - Engine Capacity 1001–1500 cc: `2000` TK
  - Engine Capacity >1500 cc: `2500` TK

- **Bus:** Tiered by seat count (20–50) and by engine capacity.
  - Seat groups: 20–30, 31–40, 41–50 — each group uses engine-capacity sub-tiers to select the charge.
  - Engine-capacity sub-tiers are used to escalate the charge within each seat group.

- **Truck:** Tiered by engine capacity (covers 2000–7500 cc and above):
  - Engine Capacity <2000 cc: `2000` TK
  - Engine Capacity 2000–3000 cc: `2500` TK
  - Engine Capacity 3001–5000 cc: `3500` TK
  - Engine Capacity 5001–7500 cc: `4500` TK
  - Engine Capacity >7500 cc: `5500` TK

- **Electric Vehicle (EV):** Charge computed solely from battery capacity and clamped to the range 1000–12000 TK:
  - `charge = batteryCapacity * 100`
  - If `charge < 1000`, set `charge = 1000`.
  - If `charge > 12000`, set `charge = 12000`.

**Common Adjustments:**
- **Age surcharge:** If vehicle age > 5 years (currentYear - year > 5) then `charge += 200` TK.
- **Lower bound:** The final `charge` is never negative; if the computed value is negative it is set to 0.
---

## 6. Conclusion

This Vehicle Management System project provides a **strong foundation in structured programming and data handling**. While simplified, it reflects real-world challenges such as validation, consistency, scalability, and extensibility—essential skills for any software developer.

---
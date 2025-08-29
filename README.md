# HOSPITAL-MANAGEMENT
Program Description – Hospital Management System

This C program implements a Hospital Management System that helps manage doctors, patients, admissions, discharges, billing, and hospital resources such as beds and wards.


🗝 Key Features


🥼 Doctor Management
Input doctor details (name, fee per day, treatment specialization).
Update doctor information (name, fee, or treatment).
Track the number of patients under each doctor.


 🌡 Patient Management

Admit new patients by entering their personal details (name, age, ailment).
Assign patients to doctors based on specialization.
Allocate patients to wards (800/day) or beds (1200/day) depending on availability.
Search for patients by name and display their admission details.
Discharge patients and free up their allocated ward/bed.


⏳ Hospital Reporting

Generate reports showing doctor details (name, fee, patient count).
Display the number of admitted patients and available beds/wards.


💵 Billing System

Calculate bills based on:
Doctor’s daily fee .
Hospital charges .
Show a detailed breakdown of doctor fees, hospital charges, and total bill.


🛌 Patient Records

Display a list of all patients with their name, age, doctor, and ailment.


🔧 Core Data Structures 

Patient struct – stores patient details (name, age, ailment, doctor, assigned bed/ward).
Doctor struct – stores doctor details (name, fees, specialization, number of patients).


🖇 Main Menu Options

Add Patient
Search Patient Details
Update Doctor Information
Generate Hospital Report
Discharge Patient
Billing System
Show All Patients
Exit

👉 In short, this program is a menu-driven Hospital Management System that provides basic operations for handling patients, doctors, admissions, billing, and hospital resource management.

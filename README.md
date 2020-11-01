# MicroprocessorSim
a microprocessor simulator using C++ and aheavily object oriented implementation 

# Usage
complie & run :
- g++  *.cpp -o sim.exe 
- .\sim.exe
enter the file name that contains the program (instruction list)

# Supported instructions 
ADD in1 in2 out1 ==> out1 := in1 + in2
NEG in1 out1 ==> out1 := - in1
MUL in1 in2 out1 ==> out1 := in1 * in2
JPA a1 ==> goto address a1
JP0 in1 a1 ==> if (in1 == 0) goto a1
ASI in1 out1 ==> out1 := in1
LOE in1 in2 out1 ==> if (in1 <= in2) then out :=1 else out1 := 0
HLT ==> stop the SIM

# Contributers 
Samah Hussein  900172660
Mahmoud Ahmed  900172747

# AUC CSCE493005: Object Oriented Development 
## License
[MIT](https://choosealicense.com/licenses/mit/)
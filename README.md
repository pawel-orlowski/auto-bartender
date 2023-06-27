![Front of the device](/docs/frontOfTheDevice.jpg)

## **Objective**
The main goal was to create an easy-to-use device in which anyone can order any of the drinks from the offer created by the owner of the vending machine. The dedicated task of the device is not to serve standardized drinks, but a variety of drinks made of unusual proportions of mixtures of available liquids.
## **Realization**
The elementary components of the device are eight feeding lines that are completely separated from each other. Each feeding line includes:
* Stainless steel tank with a capacity of *1.37 l* containing the dispensed liquid (**1**);
* Peristaltic pump with 3 satellites driven by a brush DC motor, powered by a voltage of *6 V* (**3**);
* The output element is an aluminum connector (**5**), placed in the printed revolver for stable outflow of liquid (**4**);
* All the above-mentioned elements are connected with a silicone hose with an internal diameter of *4 mm* (**2**).

![Single feeding line](/docs/feedingLine.png)

The project includes several elements designed and made in 3D printing technology. One of the parts is the housing for the display and keyboard consisting of two elements - the top cover and the bottom cover. A revolver used in fluid supply lines and a tray with a drainer for collecting fluid residues were also made.

![Back of the device](/docs/backOfTheDevice.jpg)

The machine controlled by a microcontroller is equipped with a simple interface consisting of a *4x20* liquid crystal display and a manual 16-button keyboard.
### **Electrical diagram**



## **Tests**
Tests were carried out to determine the accuracy of liquid dispensing by the prototype of the automatic bartender. The test was carried out for 3 liquids with different physical properties that are used in this device: orange juice, vodka (40% vol.) and liqueur. In order to distinguish the most important features of these fluids, tests of density and kinematic viscosity were carried out for each of them. After identifying the properties of the tested substances, the accuracy of pouring eight pumps in the bartender was tested.
### **Dosage method**
The pumps are controlled by a time constant, which is determined by the value of one dose. According to the technical specification of the pump, its capacity is *0.25 L/min*. One dose is designed to target the time it takes to pump *1 ml*. Therefore, using the manufacturer's specification, it should be stated that the value of one dose should be equivalent to *240 ms*.
### **Testing the accuracy of pumping a given volume of 3 different liquids for each pump**

![Testing the accuracy of pumping a given volume of 3 different liquids for each pump](/docs/dosingTest.png)

### **Test result and solution proposal**
The device in current form does not ensure the required accuracy of dosing - deviations between the set and received values range from approx. 20 to over 50%. Therefore, for correct operation, the dispenser should be calibrated with settings depending on the viscosity of the dispensed liquid and the accuracy of the pump. This process could be improved, for example, by creating a database of liquid properties associated with appropriate correction factors, the loading of which before each use of the device would guarantee satisfactory dosing precision.

![Above the device](/docs/aboveTheDevice.jpg)
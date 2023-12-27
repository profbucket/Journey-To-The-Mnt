NOTE: These were the lab instructions given to us for our class, I am keeping them here for posterity.

# Lab08

Must follow standards cited here:
https://github.com/olekaspt/LabStandards/blob/main/README.md

## Objective
The objective of this Lab is to create an implementation of a D&D like fighting game.

Requirements:

To see example starter code - https://github.com/olekaspt/SampleFleetAttack

All classes that have data members should have at least an accessor to query the data, and potentially a setter if it makes sense.

1.	You will need to create classes for the following concepts.
  *	A Class that represents Race – Elves, Dwarves, Humans, Halflings (this will be contained in the concrete classes).
  *	These will have three methods on them   HitPointModification, ArmorClassModification, ,HitBonusModification. Initiative Bonus
  *	An Interface (Abstract Class) class that represents a Character
    1.	They have Hit points, armor class, to hit bonus, and initiative bonus
    1.	They will have accessors to retrieve Hit points, Armor Class, Hit Bonus, that will take into account Racial Modifications
    1.	Will have (most likely pure virtual methods) to Attack, take damage, 
  *	Character Factory that takes in type of class and race to generate a Wizard, etc.
  *	Concrete classes that inherit from characters to represent Wizards, Rogues, Fighters, Clerics (yes if you have D&D background, these are called classes 😊).  This should inherit from Character.  NOTE: If you want to you can choose other “classes”, but pick four, and have different behaviors.  You will have a reference to the race class (using containment).
    *	Make some behavior changes for these character classes.   Ex. Fighters have more HP and have higher AC.   Rogues deal more damage and can hit back row of opposing party, wizards hit all opposing party members but low damage, and clerics can heal.   Feel free to add more exceptions, this is just a starter list.  I want you to have some design reign here 😊
1.	Create a Class represent to an adventuring Party
And adventuring party consists of four characters with two in the front row, and two in the back row.   Should be able to make a Party of Characters.  As you develop the attack system below, feel free to add method to the Template make things easier (i.e. damage entire party, pick a party member in rear, or front)

1.	Make a executable that will allow one to have  two opposing parties, and have them fight.  You can just hard code the parties, don’ worry about adding complex UI\text system to setup the parties (unless you really want to, but that is not par to of the assignment).

Use or ignore below, but but some rules we will have from D&D, that could be used at inspirations:
  *	Default armor class (AC) is 10
  *	To attack someone, we pick a random number 1-20 and add to hit bonus.  And then compare against targets AC.
  *	Unless they have a special ability, character attacks opposing parties front line characters until they die/knock out, and then works backwards.   Make it easy, and say front row must be incapacitated before hitting anyone in back row
  *	Have some basic AI so attacking is automated (so we can answer the question can a party of wizards beat up a party of fighters)

The requirements is not compete, as I did this on purpose.  You will need to make assumptions or decision points you had to make to implement this.  These will need to be documented in the lab report.   

# Checklist on items I’m looking for when grading
* Interface class that is abstract class (technically not required to be pure abstract)
* Containment of a object in another one (Wizard will contain a pointer to a Race class, as opposed to making a ElvenWizard class that inherits from Wizard and Elf).
* Smart Pointers – all pointers should be smart pointers or use RAII
* Virtual and overridden methods (polymorphism)
* Factory to create the "characters"
* Make Unit Tests, at least 2 per concrete class.


# Lab Submission
1.	Package all files in a single tar folder and submit the file as a group via Canvas. 
1.	Lab report contains 
  1.	class diagrams (use doxygen to generate easily)
  1.	Assumptions or changes made to requirements above.  Try not to go overboard here, bulleted list of assumptions\phrases is OK.  No need for a 10 page requirement document 😊
1.	If you were going to add in a new race and character class, what would it be?   What abilities\exceptions\weaknesses would it have?  Would your existing framework support it or what modifications would you need to make.

1. Participation Rubric

Participation rubric of teammates.  List out for your all team members how much they participated.  This will go into your Lab report.
```
	             Member1	Member2	Member3
Member1 (opinion)	33	     33	     33
Member2 (opinion)	33	     33	     33
Member3 (opinion)	33	     33	     33
```			
			
Example 			
```
	             Member1	Member2	Member3
Member1 (opinion)	33	     33	     33
Member2 (opinion)	20	     40	     40
Member3 (opinion)	20	     40	     40
```

# Lab Grading
1.	70% - Task 1 has been correctly implemented and meets all requirements.
1.	30% - Lab report contains all required information and is well written.
If program fails to compile, 0% will be given for that Task.

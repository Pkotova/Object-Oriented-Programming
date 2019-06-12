// GameOfThrones.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include"Character.h"
#include"Ruler.h"
#include "Knight.h"
#include "Advisor.h"
#include"Servant.h"
#include"House.h"
#include"Comparators.h"
using namespace std;

char m = 'm', f = 'f'; // using for genders

int main()
{

		Ruler eddard("Eddard Stark", 40, m, 5, true),
			robbert("Robert Baratheon", 43, m, 3, true),
			rhaegar("Rhaegar Targaryen", 30, m, 1, true),
			tywin("Tywin Lannister", 60, m, 3, true),
			robyn("Robyn Arryn", 14, m, 0, false),
			edmure("Edmure Tully", 37, m, 0, false),
			mace("Mice Tyrell", 55, m, 2, false),
			cercei("Cercei Lannister", 40, f, 3, true),
			daenerys("Daenerys Targeryen", 20, f, 100, true),
			aegon("Aegon Targeryen", 18, m, 0, false),
			drogo("Khal Drogo", 30, m, 0, false);

		Advisor tyrion("Tyrion Lannister", 38, m, false, true),
			qyburn("Qyburn", 58, m, true, true),
			pycelle("Pycelle", 70, m, true, false),
			aemon("Aemon", 90, m, true, false),
			luwin("Luwin", 80, m, true, true);

		Knight jorah("Jorah Mormont", 60, m, "Ser", 20),
			jamie("Jamie Lanister", 40, m, "Lord-Commander ", 10),
			barristan("Barristan Selmy", 60, m, "Ser", 30),
			bronn("Bronn", 39, m, "Ser", 40),
			brienne("Brienne Tarth", 30, m, "Knight ", 15),
			greyworm("Torconudo", 28, m, "Unsullied", 30),
			tormund("Tormund Giantsbane", 35, m, "Wildling ", 40);

		Servant shae("Shae", 30, f, true),
			missandei("Missandei", 25, f, false),
			sandor("Sandor The Hound Clegane", 40, m, true),
			varys("Lord Varys", 43, m, true),
			daario("Daario Naharis", 30, m, false),
			osha("Osha", 29, f, false);

		House custom;
		custom.setName("Gryffinclaw");
		custom.setLocation("Narnia");
		custom.setHouseWords("The more you know, the more you chill! ");

		custom.add(daenerys);
		custom.add(qyburn);
		custom.add(brienne);
		custom.add(tormund);
		custom.add(osha);
		custom.add(missandei);
		custom.add(jamie);

		custom.showTeam();
		custom.remove(jamie);

		// custom.showTeam();

		custom.sort(byScore);
		custom.showTeam();

		// custom.sort(byAge);

		//custom.sort(byName);
		custom.srinkShow();

		cout << "Your eldest character: ";
		custom.getExtreme(isEldest).show();

		cout << "Your best character: ";
		custom.getExtreme(isBest).show();
	 
}

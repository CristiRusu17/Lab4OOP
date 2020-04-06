#include "pch.h"
#include "MedikamentUI.h"


MedikamentUI::MedikamentUI()
{
}

void MedikamentUI::Show_Menu() {

	MedikamentController controller = MedikamentController();
	MedikamentDomain m1 = MedikamentDomain("Aspacardin", 4, 10, 25);
	MedikamentDomain m2 = MedikamentDomain("Baraka", 12, 5, 16.5);
	MedikamentDomain m3 = MedikamentDomain("Nurofen", 6, 10, 14);
	MedikamentDomain m4 = MedikamentDomain("Paracetamol", 15,12, 19.5);

	controller.addMedikament(m1);
	controller.addMedikament(m2);
	controller.addMedikament(m3);
	controller.addMedikament(m4);

	int key;
	bool running = true;
	while (running) {
		std::cout << "\n1.Add Medikament \n2.Delete Medikament \n3.Such Medikamente nach string \n4.Such Medikamente nach Menge \n5.Gruppiere nach Preis \n6.Zeige Medikamente \n7.Undo \n8.Redo \n0.Back";
		std::cout << "\nWahle eine Option: ";
		std::cin >> key;
		if (key == 1) {

			std::cout << "Gib Namen: ";
			std::string name;
			std::cin >> name;

			std::cout << "Gib Konzentration: ";
			double konz;
			std::cin >> konz;

			std::cout << "Gib Menge: ";
			int menge;
			std::cin >> menge;

			std::cout << "Gib Preis: ";
			double preis;
			std::cin >> preis;
			MedikamentDomain m = MedikamentDomain(name, konz, menge, preis);

			controller.addMedikament(m);

			std::cout << '\n';
		}
		if (key == 2) {

			std::cout << "Gib Namen: ";
			std::string name;
			std::cin >> name;

			std::cout << "Gib Konzentration: ";
			double konz;
			std::cin >> konz;

			MedikamentDomain m = MedikamentDomain(name, konz, -1, -1);

			controller.deleteMedikament(m);
			std::cout << '\n';
		}
		if (key == 3) {

			controller.Kette();
			std::cout << '\n';
		}
		if (key == 4) {

			int menge;
			std::cout << "Gib Menge: ";
			std::cin >> menge;

			controller.Knapp_Menge(menge);

			std::cout << '\n';
		}
		if (key == 5) {

			controller.Preis();
			std::cout << '\n';
		}
		if (key == 6) {
			std::cout << '\n';
			controller.repo.show_medikamente();

		}
		if (key == 7) {

			controller.Undo();
			std::cout << '\n';

		}

		if (key == 8) {
			controller.Redo();
			std::cout << '\n';

		}

		if (key == 0) {
			running = false;
		}

	}
}

MedikamentUI::~MedikamentUI()
{
}

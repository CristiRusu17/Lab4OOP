#include "pch.h"
#include "MedikamentController.h"
#include <algorithm>


MedikamentController::MedikamentController()
{
	this->repo = MedikamentRepo();
	this->size = -1;
}

void MedikamentController::addMedikament(MedikamentDomain m) {
	//functie pentru introducerea medicamentului
	this->Change();
	for (std::vector<MedikamentDomain>::iterator ptr = repo.medikamente.begin();
		ptr < repo.medikamente.end(); ptr++) {

		if (ptr->GetName() == m.GetName() && ptr->GetKonzentration() == m.GetKonzentration()) {
			ptr->SetMenge(ptr->GetMenge() + m.GetMenge());
			repo.undo_redo.push_back(repo.medikamente);
			this->size++;
			repo.current_index++;

			return;
		}

	}

	repo.medikamente.push_back(m);

	repo.undo_redo.push_back(repo.medikamente);
	repo.current_index++;
	this->size++;

}

void MedikamentController::deleteMedikament(MedikamentDomain m) {
	//functie pentru stergerea unui medicament
	this->Change();
	for (std::vector<MedikamentDomain>::iterator ptr = repo.medikamente.begin();
		ptr < repo.medikamente.end(); ptr++) {

		if (ptr->GetName() == m.GetName() && ptr->GetKonzentration() == m.GetKonzentration()) {
			repo.medikamente.erase(ptr);
			repo.undo_redo.push_back(repo.medikamente);
			repo.current_index++;
			this->size++;

			return;
		}

	}

}

void MedikamentController::Kette() {

	std::cout << "Gib ein string: ";
	std::string sir;
	std::cin >> sir;
	std::vector<std::string> med;

	for (std::vector<MedikamentDomain>::iterator ptr = repo.medikamente.begin();
		ptr < repo.medikamente.end(); ptr++) {

		if (ptr->GetName().find(sir) != -1) {
			med.push_back(ptr->GetName());
		}

	}

	sort(med.begin(), med.end());
	std::vector < std::string > ::iterator ptr;
	for (ptr = med.begin(); ptr < med.end(); ptr++)
	{
		std::cout << *ptr << std::endl;
	}
}

void MedikamentController::Knapp_Menge(int x) {

	for (std::vector<MedikamentDomain>::iterator ptr = repo.medikamente.begin();
		ptr < repo.medikamente.end(); ptr++) {

		if (ptr->GetMenge() < x) {
			std::cout << ptr->GetName() << ' ';
		}

	}
	std::cout << '\n';
}

void MedikamentController::Preis() {

	std::vector<MedikamentDomain> med_preis;
	for (std::vector<MedikamentDomain>::iterator i = repo.medikamente.begin();
		i < repo.medikamente.end(); i++) {

		med_preis.push_back(*i);

	}

	for (std::vector<MedikamentDomain>::iterator i = med_preis.begin();
		i < med_preis.end(); i++) {

		for (std::vector<MedikamentDomain>::iterator j = med_preis.begin();
			j < med_preis.end(); j++) {

			if (j->GetPreis() < i->GetPreis()) {
				MedikamentDomain t = *i;
				*i = *j;
				*j = t;
			}

		}
	}
	std::vector<MedikamentDomain>::iterator i = med_preis.begin();
	while (i < med_preis.end()) {

		std::cout << i->GetPreis() << ": ";
		double aux = i->GetPreis();
		while (aux == i->GetPreis()) {
			std::cout << i->GetName() << ' ';
			i++;
			if (i == med_preis.end()) {
				return;
			}
		}
		std::cout << '\n';
	}

}

void MedikamentController::Undo() {

	if (repo.current_index > 0) {
		repo.current_index--;
		repo.medikamente = repo.undo_redo[repo.current_index];
	}

}

void MedikamentController::Redo() {

	if (this->size > repo.current_index) {
		repo.current_index++;
		repo.medikamente = repo.undo_redo[repo.current_index];
	}
}

void MedikamentController::Change() {

	if (repo.current_index < this->size) {
		int diff = this->size - repo.current_index;
		while (diff) {
			repo.undo_redo.erase(repo.undo_redo.end() - 1);
			diff--;
		}

		this->size = repo.current_index;
	}
}

MedikamentController::~MedikamentController()
{
}

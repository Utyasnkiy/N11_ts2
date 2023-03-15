#include <iostream>
#include <vector>

using namespace std;

class Atom {
public:
    int protons, neutrons, electrons;
    Atom(int p, int n, int e) {
        protons = p;
        neutrons = n;
        electrons = e;
    }
    int mass() {
        return protons + neutrons;
    }
    int totalElectrons() {
        return protons == 0 ? electrons : electrons + protons;
    }
};

class Molecule {
public:
    vector<Atom> atoms;
    vector<vector<double>> bonds;
    Molecule(vector<Atom> a, vector<vector<double>> b) {
        atoms = a;
        bonds = b;
    }
    double interactionEnergy() {
        double energy = 0;
        for (int i = 0; i < atoms.size(); i++) {
            for (int j = 0; j < atoms.size(); j++) {
                if (i != j) {
                    energy += bonds[i][j] * atoms[i].totalElectrons() * atoms[j].totalElectrons();
                }
            }
        }
        return energy;
    }
    int totalMass() {
        int mass = 0;
        for (Atom a : atoms) {
            mass += a.mass();
        }
        return mass;
    }
    int totalNucleons() {
        int nucleons = 0;
        for (Atom a : atoms) {
            nucleons += a.protons + a.neutrons;
        }
        return nucleons;
    }
    int totalElectrons() {
        int electrons = 0;
        for (Atom a : atoms) {
            electrons += a.electrons;
        }
        return electrons;
    }
    int countAtomsOfType(int p, int n, int e) {
        int count = 0;
        for (Atom a : atoms) {
            if (a.protons == p && a.neutrons == n && a.electrons == e) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    Atom oxygen(8, 8, 8);
    Atom hydrogen(1, 0, 1);
    vector<Atom> atoms = { oxygen, hydrogen, hydrogen };
    vector<vector<double>> bonds = {
        {0.0, 0.9, 0.9},
        {0.9, 0.0, 0.0},
        {0.9, 0.0, 0.0}
    };
    Molecule water(atoms, bonds);
    cout << "Взаимодействующая энергия: " << water.interactionEnergy() << endl;
    cout << "Общая масса: " << water.totalMass() << endl;
    cout << "Общее число нуклонов: " << water.totalNucleons() << endl;
    cout << "Общее число электронов: " << water.totalElectrons() << endl;
    cout << "Количество атомов кислорода: " << water.countAtomsOfType(8, 8, 8) << endl;
    cout << "Количество атомов водорода: " << water.countAtomsOfType(1, 0, 1) << endl;
    return 0;
}

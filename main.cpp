#include <iostream>
#include <G4MTRunManager.hh>
#include <QBBC.hh>
#include "G4RunManager.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4VUserActionInitialization.hh"
class Geometry : public G4VUserDetectorConstruction{
    G4VPhysicalVolume* Construct(){
        return nullptr;
    }
};
class Action : public G4VUserActionInitialization{
    void Build() const{

    }
};
int main() {
    auto runManager = new G4MTRunManager();

    runManager->SetUserInitialization(new Geometry); //геометрия
    runManager->SetUserInitialization(new QBBC);  //физические процессы
    runManager->SetUserInitialization(new Action); //действия
    runManager->Initialize();
    delete runManager;
    return 0;
}
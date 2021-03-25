#include "Seismotoad.hpp"  

#include "../Skill/Torrent.hpp"
#include "../Skill/Fissure.hpp"

void Seismotoad::InitComp() {
    this->namaSpecies = "Seismotoad";
    monElements[0].setElement(Water);
    monElements[1].setElement(Ground);
    this->monSkills[0] = Torrent();
    this->monSkills[1] = Fissure();
}

Seismotoad :: Seismotoad() : Engimon(){
    InitComp();
};

Seismotoad :: Seismotoad(string name) : Engimon(name){
    InitComp();
};

// Seismotoad::Seismotoad(string nama, Engimon& other1, Engimon& other2): Engimon(nama,other1,other2){
//     InitComp();
// }

Seismotoad :: ~Seismotoad(){

}
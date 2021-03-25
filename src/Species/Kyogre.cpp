#include "Kyogre.hpp"  
#include "../Skill/Torrent.hpp"
#include "../Skill/IceVortex.hpp"

void Kyogre::InitComp() {
    this->namaSpecies = "Kyogre";
    monElements[0].setElement(Water);
    monElements[1].setElement(Ice);
    this->monSkills[0] = Torrent();
    this->monSkills[1] = IceVortex();
}

Kyogre :: Kyogre() : Engimon(){
    InitComp();
};

Kyogre :: Kyogre(string name) : Engimon(name){
    InitComp();
};

// Kyogre::Kyogre(string nama, Engimon& other1, Engimon& other2): Engimon(nama,other1,other2){
//     InitComp();
// }

Kyogre :: ~Kyogre(){

}

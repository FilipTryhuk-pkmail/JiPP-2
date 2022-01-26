//
// Created by anon on 1/23/22.
//

#include <iostream>
#include <vector>
#include <fstream>
#include "MeleeCard.h"
#include "RangedCard.h"
#include "MagicCard.h"

using namespace std;

void help();
void overload();

template<typename T>
void attack(MagicCard &mage, T &target) {
    target.takeDamage(mage.getPower()*0.8, mage.true_damage_dealt);
}
template<typename T>
void attack(RangedCard &ranger, T &target) {
    target.takeDamage(ranger.getPower()*1.0);
}
template<typename T>
void attack(MeleeCard &fighter, T &target) {
    target.takeDamage(fighter.getPower()*1.2);
}

int main(int argc, char *argv[]) {

    string tempNameMagic, tempNameRanged, tempNameMelee;
    double tempPowerMagic, tempLifeMagic, tempPowerRanged, tempLifeRanged, tempPowerMelee, tempLifeMelee;
    double tempEthereal, tempMageSpecial;
    int tempArmor, tempDodge;
    ofstream logFile;

    srand(time(nullptr));

    vector <Card*> playerUnits;
    vector <Card*> enemyUnits;
    try {
        //Sprawdź, czy użytkownik zapytał o pomoc
        if (string(argv[1]) == "help") {
            help();
            return 1;
        }
    }
    catch (logic_error) {
        help();
        return 1;
    }

    //wywolaj demnostacje przeciazenia opeatorow
    if (string(argv[1]) == "o") {
        overload();
        return 1;
    }

    //Sprawdź, czy podano odpowiednią liczbę parametrów
    if (argc != 2) {
        help();
        return 1;
    } else if (string(argv[1]) == "e") {
        cout << "A group of undead emerges from a nearby cellar!" << endl;
        tempNameMagic = "Risen Necromancer";
        tempPowerMagic = 400;
        tempLifeMagic = 2000;
        tempEthereal = 0.2;
        tempMageSpecial = 0.1;
        tempNameRanged = "Skeleton Archer";
        tempPowerRanged = 1000;
        tempLifeRanged = 2000;
        tempDodge = 30;
        tempNameMelee = "Decaying Abomination";
        tempPowerMelee = 400;
        tempLifeMelee = 4000;
        tempArmor = 100;

    } else if (string(argv[1]) == "h") {
        cout << "You're ambushed by an elite demonic strike force!" << endl;
        tempNameMagic = "Annihilation Demon";
        tempPowerMagic = 450;
        tempLifeMagic = 3000;
        tempEthereal = 0.4;
        tempMageSpecial = 0.3;
        tempNameRanged = "Hellfire Ballista";
        tempPowerRanged = 1200;
        tempLifeRanged = 4000;
        tempDodge = 00;
        tempNameMelee = "Infernal Overseer";
        tempPowerMelee = 666;
        tempLifeMelee = 3666;
        tempArmor = 250;

    } else if (string(argv[1]) == "c") {
        cout << "A sparring match! Who will you face today?" << endl;
        cout << "Enter the name of the Magic enemy: ";
        cin >> tempNameMagic;
        cout << endl << "Enter its power: ";
        cin >> tempPowerMagic;
        cout << endl << "...its health: ";
        cin >> tempLifeMagic;
        cout << endl << "And its ethereal stat: ";
        cin >> tempEthereal;
        cout << endl << "And finally its true damage percentage: ";
        cin >> tempMageSpecial;

        cout << "Enter the name of the Ranged enemy: ";
        cin >> tempNameRanged;
        cout << endl << "Enter its power: ";
        cin >> tempPowerRanged;
        cout << endl << "...its health: ";
        cin >> tempLifeRanged;
        cout << endl << "And its dodge [percent]: ";
        cin >> tempDodge;

        cout << "Enter the name of the Melee enemy: ";
        cin >> tempNameMelee;
        cout << endl << "Enter its power: ";
        cin >> tempPowerMelee;
        cout << endl << "...its health: ";
        cin >> tempLifeMelee;
        cout << endl << "And its armor: ";
        cin >> tempArmor;

    } else {
        cout << "Selected an incorrect setting! Restart and try again." << endl;
        help();
        return 1;
    }
    //Create enemy party
    MagicCard EnemyCaster = MagicCard(tempNameMagic, tempPowerMagic, tempLifeMagic, tempEthereal, tempMageSpecial);
    RangedCard EnemyRanged = RangedCard(tempNameRanged, tempPowerRanged, tempLifeRanged, tempDodge);
    MeleeCard EnemyFighter = MeleeCard(tempNameMelee, tempPowerMelee, tempLifeMelee, tempArmor);
    enemyUnits.push_back(&EnemyRanged);
    enemyUnits.push_back(&EnemyCaster);
    enemyUnits.push_back(&EnemyFighter);

    //Create player party
    MagicCard PlayerCaster = MagicCard("Firemage Adept", 300, 3000, 0.4, 0.1);
    RangedCard PlayerRanged = RangedCard("Deepwood Rogue", 500, 4000, 50);
    MeleeCard PlayerFighter =  MeleeCard("Faithbound Paladin", 400, 5000, 300);
    playerUnits.push_back(&PlayerRanged);
    playerUnits.push_back(&PlayerCaster);
    playerUnits.push_back(&PlayerFighter);

    bool playerRangedDied = false;
    bool playerMagicDied = false;
    bool playerMeleeDied = false;
    bool enemyRangedDied = false;
    bool enemyMagicDied = false;
    bool enemyMeleeDied = false;
    int enemiesDefeated = 0;
    int turnsCount = 0;
    logFile.open("logs.txt", ios::app);
    if (logFile.fail()) {
        cout << "Couldn't open logs.txt, exiting..." << endl;
        return 1;
    }
    while(!enemyUnits.empty() && !playerUnits.empty()) {
        //Player's turn
        turnsCount++;
        int target;
        if(PlayerRanged.alive) {
            cout << endl << "Pick a target for your " << PlayerRanged.getName() << endl;
            cout << "0 -- " << EnemyRanged.getName() << ", 1 -- " << EnemyCaster.getName() << ", 2 -- " << EnemyFighter.getName() << endl;
            cin >> target;
            switch(target) {
                case 0:
                    attack(PlayerRanged, EnemyRanged);
                    cout << "Your " << PlayerRanged.getName() << " attacked " << EnemyRanged.getName() << " leaving it at " << EnemyRanged.getCurrentLife() << " out of " << EnemyRanged.getMaxLife() << " health." << endl;
                    break;
                case 1:
                    attack(PlayerRanged, EnemyCaster);
                    cout << "Your " << PlayerRanged.getName() << " attacked " << EnemyCaster.getName() << " leaving it at " << EnemyCaster.getCurrentLife() << " out of " << EnemyCaster.getMaxLife() << " health." << endl;
                    break;
                case 2:
                    attack(PlayerRanged, EnemyFighter);
                    cout << "Your " << PlayerRanged.getName() << " attacked " << EnemyFighter.getName() << " leaving it at " << EnemyFighter.getCurrentLife() << " out of " << EnemyFighter.getMaxLife() << " health." << endl;
                    break;
                default:
                    cout << "Incorrect identifier, turn skipped!" << endl;
            }
        } else if (!playerRangedDied) {
            playerUnits.erase(playerUnits.begin());
            playerRangedDied = true;
        }
        if(PlayerCaster.alive) {
            cout  << endl << "Pick a target for your " << PlayerCaster.getName() << endl;
            cout << "0 -- " << EnemyRanged.getName() << ", 1 -- " << EnemyCaster.getName() << ", 2 -- "
                 << EnemyFighter.getName() << endl;
            cin >> target;
            switch (target) {
                case 0:
                    attack(PlayerCaster, EnemyRanged);
                    cout << "Your " << PlayerCaster.getName() << " attacked " << EnemyRanged.getName()
                         << " leaving it at " << EnemyRanged.getCurrentLife() << " out of " << EnemyRanged.getMaxLife()
                         << " health." << endl;
                    break;
                case 1:
                    attack(PlayerCaster, EnemyCaster);
                    cout << "Your " << PlayerCaster.getName() << " attacked " << EnemyCaster.getName()
                         << " leaving it at " << EnemyCaster.getCurrentLife() << " out of " << EnemyCaster.getMaxLife()
                         << " health." << endl;
                    break;
                case 2:
                    attack(PlayerCaster, EnemyFighter);
                    cout << "Your " << PlayerCaster.getName() << " attacked " << EnemyFighter.getName()
                         << " leaving it at " << EnemyFighter.getCurrentLife() << " out of "
                         << EnemyFighter.getMaxLife() << " health." << endl;
                    break;
                default:
                    cout << "Incorrect identifier, turn skipped!" << endl;
            }
        } else if (!playerMagicDied){
            if (playerUnits.size() == 3) {
                playerUnits.erase(playerUnits.begin()+1);
                playerMagicDied = true;
            } else if ((playerUnits.size() == 2) and playerRangedDied) {
                playerUnits.erase(playerUnits.begin());
                playerMagicDied = true;
            } else if ((playerUnits.size() == 2) and !playerRangedDied) {
                playerUnits.pop_back();
                playerMagicDied = true;
            } else if (playerUnits.size() == 1) {
                playerUnits.pop_back();
                playerMagicDied = true;
            }
        }
        if (PlayerFighter.alive) {
            cout  << endl << "Pick a target for your " << PlayerFighter.getName() << endl;
            cout << "0 -- " << EnemyRanged.getName() << ", 1 -- " << EnemyCaster.getName() << ", 2 -- "
                 << EnemyFighter.getName() << endl;
            cin >> target;
            switch (target) {
                case 0:
                    attack(PlayerFighter, EnemyRanged);
                    cout << "Your " << PlayerFighter.getName() << " attacked " << EnemyRanged.getName()
                         << " leaving it at " << EnemyRanged.getCurrentLife() << " out of " << EnemyRanged.getMaxLife()
                         << " health." << endl;
                    break;
                case 1:
                    attack(PlayerFighter, EnemyCaster);
                    cout << "Your " << PlayerFighter.getName() << " attacked " << EnemyCaster.getName()
                         << " leaving it at " << EnemyCaster.getCurrentLife() << " out of " << EnemyCaster.getMaxLife()
                         << " health." << endl;
                    break;
                case 2:
                    attack(PlayerFighter, EnemyFighter);
                    cout << "Your " << PlayerFighter.getName() << " attacked " << EnemyFighter.getName()
                         << " leaving it at " << EnemyFighter.getCurrentLife() << " out of "
                         << EnemyFighter.getMaxLife() << " health." << endl;
                    break;
                default:
                    cout << "Incorrect identifier, turn skipped!" << endl;
            }
        } else if (!playerMeleeDied) {
            playerUnits.pop_back();
            playerMeleeDied = true;
        }
        cout << endl;

        //Enemy's turn, can target dead units
        if (EnemyRanged.alive) {
            switch(rand() % 3) {
                case 0:
                    attack(EnemyRanged, PlayerRanged);
                    break;
                case 1:
                    attack(EnemyRanged, PlayerCaster);
                    break;
                case 2:
                    attack(EnemyRanged, PlayerFighter);
                    break;
            }
        } else if (!enemyRangedDied) {
            enemiesDefeated += 1;
            enemyRangedDied = true;
        }
        if (EnemyCaster.alive) {
            switch(rand() % 3) {
                case 0:
                    attack(EnemyCaster, PlayerRanged);
                    break;
                case 1:
                    attack(EnemyCaster, PlayerCaster);
                    break;
                case 2:
                    attack(EnemyCaster, PlayerFighter);
                    break;
            }
        } else if (!enemyMagicDied) {
            enemiesDefeated += 1;
            enemyMagicDied = true;
        }
        if (EnemyFighter.alive) {
            switch(rand() % 3) {
                case 0:
                    attack(EnemyFighter, PlayerRanged);
                    break;
                case 1:
                    attack(EnemyFighter, PlayerCaster);
                    break;
                case 2:
                    attack(EnemyFighter, PlayerFighter);
                    break;
            }
        } else if (!enemyMeleeDied) {
            enemiesDefeated += 1;
            enemyMeleeDied = true;
        }
        if (enemiesDefeated == 3) {
            enemyUnits.clear();
        }

        //Player team status
        logFile << endl << "Turn " << turnsCount;
        cout << endl << "You still have " << (PlayerRanged.alive + PlayerCaster.alive + PlayerFighter.alive) << " units left." << endl;
        logFile << endl << "You still have " << (PlayerRanged.alive + PlayerCaster.alive + PlayerFighter.alive) << " units left." << endl;
        if (!playerUnits.empty()) {
            cout << "Your " << playerUnits[0]->getName() << " is at " << playerUnits[0]->getCurrentLife() << " out of "
                 << playerUnits[0]->getMaxLife() << " health." << endl;
            logFile << "Your " << playerUnits[0]->getName() << " is at " << playerUnits[0]->getCurrentLife() << " out of "
                 << playerUnits[0]->getMaxLife() << " health." << endl;
        }
        if (playerUnits.size() > 1) {
            cout << "Your " << playerUnits[1]->getName() << " is at " << playerUnits[1]->getCurrentLife() << " out of "
                 << playerUnits[1]->getMaxLife() << " health." << endl;
            logFile << "Your " << playerUnits[1]->getName() << " is at " << playerUnits[1]->getCurrentLife() << " out of "
                 << playerUnits[1]->getMaxLife() << " health." << endl;
        }
        if (playerUnits.size() > 2) {
            cout << "Your " << playerUnits[2]->getName() << " is at " << playerUnits[2]->getCurrentLife() << " out of "
                 << playerUnits[2]->getMaxLife() << " health." << endl;
            logFile << "Your " << playerUnits[2]->getName() << " is at " << playerUnits[2]->getCurrentLife() << " out of "
                 << playerUnits[2]->getMaxLife() << " health." << endl;
        }
        cout << endl;
        logFile << endl;

    }
    if (enemyUnits.empty()) {
        cout << "You won! Congratulations!" << endl;
        logFile << "You won! Congratulations!" << endl << endl << endl;
    } else {
        cout << "You lost! Better luck next time!" << endl;
        logFile << "You lost! Better luck next time!" << endl << endl << endl;
    }
    logFile.close();

    return 0;
}

void overload() {
    MeleeCard Fighter01 = MeleeCard("Fighter01", 100, 1000, 10);
    MeleeCard Fighter02 = MeleeCard("Fighter02", 200, 2000, 20);
    MeleeCard Fighter03 = Fighter01 + Fighter02;
    cout << "Adding the two fighters together we get a Fighter MeleeCard with combined stats" << endl;
    cout << "For example, combined life: " << Fighter03.getMaxLife() << endl;
}

void help() {
    cout << "To start the game chose a mode as a launch parameter:" << endl;
    cout << "\t\"e\"" << endl << "Easy - a group of weak undead." << endl << endl;
    cout << "\t\"h\"" << endl << "Hard - a demonic assault party." << endl << endl;
    cout << "\t\"c\"" << endl << "Custom - design the enemies yourself." << endl << endl;
    cout << "\t\"o\"" << endl << "Overload - show how two cards can be added via overloaded \"+=\"" << endl << endl;
}
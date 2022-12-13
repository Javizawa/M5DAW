// Ejercicio1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

using namespace std;

//Atributos del enemigo
int enemyHP = 100;
string enemyName = "Creeper";
bool enemyIsAlive = true;
int enemyDamage = 600;

//Atributos de héroe
string heroName;
int heroDamage;
int heroHP = 500;
bool heroIsAlive = true;




void startGame() {
    cout << "Un " << enemyName << " acaba de aparecer y tiene " << enemyHP << " puntos de vida\n";
    cout << "Como se llama el heroe?\n";
    cin >> heroName;
    cout << "El nombre del heroe es " << heroName << "\n";
}


int heroAttack() {
    return enemyHP - heroDamage;
}


bool statusEnemy() {
     if (enemyHP <= 0) {
         cout << "Te acabas de cargar al enemigo " << enemyName << "\n";
         //enemyIsAlive = false;
         return false;
     }
     else {
           cout << "Al enemigo " << enemyName << " le quedan " << enemyHP << " puntos de vida\n";
           return true;
      }
}



bool statusHero() {
    if (heroHP <= 0) {
        heroHP = 0;
        cout << "El enemigo " << enemyName << " te ha dado matarile\n";
        return false;
    }
    else {
        cout << "El enemigo " << enemyName << " te ha hecho un ataque de " << enemyDamage << " puntos de danyo. Te quedan " << heroHP << "  puntos de vida\n";
        return true;
    }
}


int enemyAttack(int damage) {
   return heroHP - damage;
}


int main()
{
    startGame();
    while(enemyIsAlive && heroIsAlive){
                cout << "Cuanto danyo quieres hacer al " << enemyName << "?\n";
                cin >> heroDamage;
                enemyHP = heroAttack();
             //   enemyIsAlive = statusEnemy();              
             //   if (enemyIsAlive) {
                 if (statusEnemy()) {
                    //ATACO AL HÉROE
                    heroHP = enemyAttack(100);
                    heroIsAlive = statusHero();
                }
    }
}

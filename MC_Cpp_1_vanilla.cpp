#include <iostream>
#include <string>

#include "EnnemiFuyant.h"


class Joueur {
public:
	Vec2i pos{0,0};
};



int main()
{
	using namespace std;

	Joueur joueur;
	EnnemiFuyant en1( Vec2i(5,8), 20 );
	vector<Obstacle> obstacles{	Obstacle(Vec2i(3,5),2), 
								Obstacle( Vec2i(-5,14),3 ) };

	vector<Ennemi*> ennemis;
	en1.obstacles = &obstacles;
	ennemis.push_back( static_cast<Ennemi*>(&en1) );

	std::cout << "Demarrage...\n";

	bool boucle = true;
	while( boucle ) {
		string commande;
		cin >> commande;

		// bouge le joueur ?
		// a remplir : tester si pas d'obstacles!
		if( commande == "z" ) joueur.pos.y++;
		else if( commande == "q" ) joueur.pos.x--;
		else if( commande == "d" ) joueur.pos.x++;
		else if( commande == "s" ) joueur.pos.y--;

		for( auto ennemi : ennemis ) {
			ennemi->perceptionJoueur( joueur.pos );
			ennemi->action();
		}
	}
}


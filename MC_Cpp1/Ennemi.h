#pragma once

#include <iostream>
#include <vector>
#include "Utils.h"


class Ennemi {
public:
	Ennemi() { pos = Vec2i( 0, 0 ); };
	Ennemi( const Vec2i& pos, int vie = 10 ) {
		this->pos = pos;
		this->vie = vie;
	};
	virtual ~Ennemi() {};

	// verifie si on voit le joueur en fonction de notre position actuelle, notre orientation et les obstacles
	void perceptionJoueur( const Vec2i& joueur ) 
	{
		// a remplir : ajouter un test pour que le joueur ne soit pas visible si trop loin


		// verifie si on est tourné vers le joueur
		switch( ori )
		{
		case HAUT:
			if( joueur.y < pos.y ) return;
			if( abs( joueur.x - pos.x ) > abs( joueur.y - pos.y ) ) return;
			break;

		case DROITE:
			// a remplir
			break;

		case BAS:
			// a remplir
			break;

		case GAUCHE:
			// a remplir
			break;

		default:
			break;
		}

		// vérifie si des obstacles sont entre nous et le joueur
		if( obstacles == nullptr ) {
			std::cout << "Obstacles non initialises!!\n";
			return;
		}
		for( const auto& obs : *obstacles ) {
			if( Utils::minDistance( pos, joueur, obs.pos ) < static_cast<double>(obs.taille) ) return;
		}

		// on a vu le joueur! on enregistre sa position
		posJoueur = joueur;
	}


	bool bougeVers( const Vec2i& destination ) {

		// a remplir : calcule la nouvelle orientation

		// a remplir : teste s'il n'y a pas d'obstacles au point d'arrivee

		// a remplir : met a jour la position
		
		return true;
	}


	virtual bool action() { return true; };

public:
	std::vector<Obstacle> *obstacles = nullptr;

protected:
	Vec2i pos, posJoueur;
	orientation ori = HAUT;
	int vie = 10;
};




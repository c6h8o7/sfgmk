#include "stdafx.h"

#include "IncludesProjet.hpp"

#include <omp.h>
#include <conio.h>
#include <iostream>

using namespace sfgmk;

StateDefault::StateDefault()
{
	DATA_MANAGER->loadLevel(m_sRessourcesPath);
	PARALLAXE.loadLevel(m_sRessourcesPath);
}

StateDefault::~StateDefault()
{
	DATA_MANAGER->unloadLevel(m_sRessourcesPath);
	PARALLAXE.unloadLevel(m_sRessourcesPath);
}

void StateDefault::init()
{
	GRAPHIC_MANAGER->getCurrentCamera()->setFreeMove();
	//PHYSIC_MANAGER->setDraw(true);

	for( int i(0); i < 100; i++ )
	{
		Entity* entity = new Entity(sf::Vector3f(RAND(100, 1180), RAND(100, 620), 0.0f));
		entity->getSprite()->setAnimation(DATA_MANAGER->getAnimation("goomba"));

		if( RAND(0, 1) == 0 )
			entity->addObbCollider();
		else
			entity->addSphereCollider();

		ADD_ENTITY(entity);
	}
}

void StateDefault::update()
{


}

void StateDefault::deinit()
{

}

void StateDefault::draw()
{

}
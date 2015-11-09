namespace sfgmk
{
	namespace engine
	{
		Core::Core()
		{
			sfgmk::FoncterTemplateInstance<StateMachineManager, void>* Ptr1 = new sfgmk::FoncterTemplateInstance<StateMachineManager, void>(STATE_MACHINE_MANAGER, &StateMachineManager::update);
			m_MainFunctions.m_FunctionsArray.pushBack(Ptr1);
			sfgmk::FoncterTemplateInstance<EntityManager, void>* Ptr2 = new sfgmk::FoncterTemplateInstance<EntityManager, void>(ENTITY_MANAGER, &EntityManager::update);
			m_MainFunctions.m_FunctionsArray.pushBack(Ptr2);
			sfgmk::FoncterTemplateInstance<PhysicManager, void>* Ptr3 = new sfgmk::FoncterTemplateInstance<PhysicManager, void>(PHYSIC_MANAGER, &PhysicManager::update);
			m_MainFunctions.m_FunctionsArray.pushBack(Ptr3);
			sfgmk::FoncterTemplateInstance<EntityManager, void>* Ptr4 = new sfgmk::FoncterTemplateInstance<EntityManager, void>(ENTITY_MANAGER, &EntityManager::sortEntityVector);
			m_MainFunctions.m_FunctionsArray.pushBack(Ptr4);
			sfgmk::FoncterTemplateInstance<GraphicManager, void>* Ptr5 = new sfgmk::FoncterTemplateInstance<GraphicManager, void>(GRAPHIC_MANAGER, &GraphicManager::compute);
			m_MainFunctions.m_FunctionsArray.pushBack(Ptr5);
			sfgmk::FoncterTemplateInstance<GraphicManager, void>* Ptr6 = new sfgmk::FoncterTemplateInstance<GraphicManager, void>(GRAPHIC_MANAGER, &GraphicManager::draw);
			m_MainFunctions.m_FunctionsArray.pushBack(Ptr6);
			sfgmk::FoncterTemplateInstance<StateMachineManager, void>* Ptr7 = new sfgmk::FoncterTemplateInstance<StateMachineManager, void>(STATE_MACHINE_MANAGER, &StateMachineManager::draw);
			m_MainFunctions.m_FunctionsArray.pushBack(Ptr7);
			sfgmk::FoncterTemplateInstance<GraphicManager, void>* Ptr8 = new sfgmk::FoncterTemplateInstance<GraphicManager, void>(GRAPHIC_MANAGER, &GraphicManager::display);
			m_MainFunctions.m_FunctionsArray.pushBack(Ptr8);
		}

		Core::~Core()
		{
			m_MainFunctions.m_FunctionsArray.clear();
		}


		void Core::update()
		{
			//Update du time delta
			m_fTimeDelta = (m_ClockTimeDelta.restart()).asSeconds();
		}

		void Core::preLoop()
		{
			this->update();

			//Update inputs
			INPUT_MANAGER->update();

			//Boucle events
			while( GRAPHIC_MANAGER->getRenderWindow()->pollEvent(m_Event) )
			{
				if( m_Event.type == sf::Event::Closed )
					GRAPHIC_MANAGER->getRenderWindow()->close();

				INPUT_MANAGER->handleEvent(m_Event);
			}
			GRAPHIC_MANAGER->set();

			//Debug
			DEBUG_MANAGER->update(m_fTimeDelta);

			//Son
			SOUND_MANAGER->update();
		}

		void Core::loop()
		{
			//Update �tat(s) courant(s)
			measureFoncterExecutionTime(m_ExecutionTimes.dStateUpdate, m_MainFunctions.m_FunctionsArray[eStateMachineUpdate]);
			
			//Update des entit�s
			measureFoncterExecutionTime(m_ExecutionTimes.dEntityUpdate, m_MainFunctions.m_FunctionsArray[eEntityManagerUpdate]);
		
			//Physique
			measureFoncterExecutionTime(m_ExecutionTimes.dPhysic, m_MainFunctions.m_FunctionsArray[ePhysicManagerUpdate]);

			AI_MANAGER->update(m_fTimeDelta);

			//Trie les entit�s du vector en fonction de leur Z
			measureFoncterExecutionTime(m_ExecutionTimes.dEntitySort, m_MainFunctions.m_FunctionsArray[eEntityManagerSort]);

			//Parallaxe
			measureFoncterExecutionTime(m_ExecutionTimes.dParallaxeComputation, m_MainFunctions.m_FunctionsArray[eGraphicManagerCompute]);

			//Draw parallaxe
			measureFoncterExecutionTime(m_ExecutionTimes.dParallaxeDisplay, m_MainFunctions.m_FunctionsArray[eGraphicManagerDraw]);

			//Draw �tat(s) courant(s)
			measureFoncterExecutionTime(m_ExecutionTimes.dStateDraw, m_MainFunctions.m_FunctionsArray[eStateMachineDraw]);
		}

		void Core::postLoop()
		{
			//Finalisation affichage
			m_MainFunctions[eGraphicManagerDisplay];
		}
	}
}
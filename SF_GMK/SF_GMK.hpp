/*--------------------------------------------------------------------------------------------------

	@author		GMK
	@date		03/01/2015
	@brief		Point d'entr�e

--------------------------------------------------------------------------------------------------*/

#ifndef SF_GMK_HPP
#define SF_GMK_HPP

 
namespace sfgmk
{ 
	enum eSFGMK_STATES
	{
		eLoadingState = 0,
		eStateDefault = 1,
		eSFGMK_STATES_NUMBER
	};

	#define EMPTY_COLOR sf::Color(0, 0, 0, 0)

	//States
	#define STATE_BANK sfgmk::StateBank::getSingleton()
	#define CHANGE_STATE(a) sfgmk::GameManager::getSingleton()->getStateMachine()->changeState(a);
	#define STATE_MACHINE sfgmk::GameManager::getSingleton()->getStateMachine()
	#define CURRENT_STATE sfgmk::GameManager::getSingleton()->getStateMachine()->Get_CurrentState()

	//Managers
	#define DATA_MANAGER sfgmk::DataManager::getSingleton()
	#define GAME_MANAGER sfgmk::GameManager::getSingleton()
	#define ADD_ENTITY(a) sfgmk::GameManager::getSingleton()->addEntity(a)
	#define FREE_ENTITY_VECTOR sfgmk::GameManager::getSingleton()->freeEntityVector()
	#define CAMERA sfgmk::GameManager::getSingleton()->getCurrentCamera()
	#define CONSOLE sfgmk::ConsoleDev::getSingleton();
	#define PARALLAXE sfgmk::GameManager::getSingleton()->getParallaxe()
	#define TIME_DELTA sfgmk::GameManager::getSingleton()->getTimeDelta()

	#define SOUND_MANAGER sfgmk::SoundManager::getSingleton()

	//Inputs
	#define INPUT_MANAGER sfgmk::InputManager::getSingleton()
		//Keyboard
		#define SFGMK_KEYBOARD sfgmk::InputManager::getSingleton()->getKeyboard()
		#define SFGMK_KEYBOARD_KEY(a) sfgmk::InputManager::getSingleton()->getKeyboard().getKeyState(a)

		//Mouse
		#define SFGMK_MOUSE sfgmk::InputManager::getSingleton()->getMouse()
		#define SFGMK_MOUSE_WINDOW_POS sfgmk::InputManager::getSingleton()->getMouse().getWindowPosition()
		#define SFGMK_MOUSE_WORLD_POS sfgmk::InputManager::getSingleton()->getMouse().getWorldPosition()

		//Joystick
		#define SFGMK_JOYSTICK_GET_BUTTON(a, b) sfgmk::InputManager::getSingleton()->getJoystick(a).getButtonState(b)
		#define SFGMK_JOYSTICK_GET_AXIS(a, b) sfgmk::InputManager::getSingleton()->getJoystick(a).getAxis(b)   

			//Manette XBOX-360
			#define BUTTON_A 0
			#define BUTTON_B 1
			#define BUTTON_X 2
			#define BUTTON_Y 3
			#define BUTTON_LB 4
			#define BUTTON_RB 5
			#define BUTTON_BACK 6
			#define BUTTON_START 7
			#define BUTTON_JOYSTICK_LEFT 8
			#define BUTTON_JOYSTICK_RIGHT 9
			//touche 'XBOX'								==> pas r�cup�rable apparemment
			//appuie sur le centre du pad directionnel	==> //

			#define JOYSTICK_LEFT_HORIZONTAL sf::Joystick::X //-100 � gauche, 100 � droite
			#define JOYSTICK_LEFT_VERTICAL sf::Joystick::Y //-100 en haut, 100 en bas
			#define TRIGGER_RIGHT sf::Joystick::Z //0 -> -99
			#define TRIGGER_LEFT sf::Joystick::Z //0 -> 99
			#define JOYSTICK_RIGHT_VERTICAL sf::Joystick::R //-100 en haut, 100 en bas
			#define JOYSTICK_RIGHT_HORIZONTAL sf::Joystick::U //-100 � gauche, 100 � droite
			#define DIRECTIONAL_CROSS_VERTICAL sf::Joystick::PovX //100 en haut, -100 en bas
			#define DIRECTIONAL_CROSS_HORIZONTAL sf::Joystick::PovY //-100 � gauche, 100 � droite
}


#endif
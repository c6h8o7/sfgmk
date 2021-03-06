/*--------------------------------------------------------------------------------------------------

	@author		GMK
	@date		10/12/2014
	@brief		Singleton regroupant l'ensemble des acc�s clavier, souris et joystick

--------------------------------------------------------------------------------------------------*/

#ifndef SFGMK_INPUT_MANAGER_HPP
#define SFGMK_INPUT_MANAGER_HPP


namespace sfgmk
{
	namespace engine
	{
		enum eKeyStates
		{
			eKEY_UP = 0,
			eKEY_PRESSED = 1 << 0,
			eKEY_DOWN = eKEY_PRESSED | 1 << 1,
			eKEY_RELEASED = 1 << 2,
		};

		enum eMouseWheelStates
		{
			eWHEEL_BOT = -1,
			eWHEEL_CENTER = 0,
			eWHEEL_TOP = 1
		};

		class SFGMK_API InputManager : public SingletonTemplate<InputManager>
		{
			friend class SingletonTemplate<InputManager>;

			public:
				void update();
				void handleEvents();

				Keyboard& getKeyboard();
				Mouse& getMouse();
				Joystick& getJoystick(int _Index);

				sf::Vector2f getJoystickUnitVector(int _Id, sf::Joystick::Axis _AxisVertical, sf::Joystick::Axis _AxisHorizontal);
				float getJoystickAngle(int _Id, sf::Joystick::Axis _AxisVertical, sf::Joystick::Axis _AxisHorizontal);

				void setGeneralVibration(float _Time, sf::Vector2i _Vibration);

			private:
				InputManager();
				~InputManager();

				sf::Event m_Event;

				Keyboard m_Keyboard;
				Mouse m_Mouse;
				Joystick m_Joystick[sf::Joystick::Count];
		};
	}
}


#endif
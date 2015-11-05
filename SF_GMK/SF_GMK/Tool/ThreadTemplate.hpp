/*--------------------------------------------------------------------------------------------------

	@author		GMK
	@date		02/07/2015
	@brief		Classe ajoutant des fonctionnalités aux std::thread

--------------------------------------------------------------------------------------------------*/

#ifndef SFGMK_THREAD_TEMPLATE_HPP
#define SFGMK_THREAD_TEMPLATE_HPP


namespace sfgmk
{
	template<typename... Args>
	class SFGMK_API ThreadTemplate
	{
		private:
			std::thread* m_Thread;
			FoncterTemplate* m_Function;
			bool m_bLaunched;

			inline void Run(Args... _Args)
			{
				m_Function->Execute(_Args...);
			}

		public:
			ThreadTemplate(FoncterTemplate* _Foncter = NULL) : m_Thread(NULL), m_Function(_Foncter), m_bLaunched(false) {}
			~ThreadTemplate() { Wait(); SAFE_DELETE(m_Function); }

			bool SetFunc(FoncterTemplate* _Foncter)
			{
				if( m_bLaunched )
					return false;

				m_Function = _Foncter;
				return true;
			}

			bool Launch(Args... _Args)
			{
				if( !m_bLaunched && m_Function )
				{
					m_Thread = new std::thread(&ThreadTemplate::Run, this, _Args...);
					return true;
				}

				return false;
			}

			void Wait()
			{
				if( m_bLaunched )
					m_Thread->join();
			}
	};
}


#endif
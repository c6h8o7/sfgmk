/*--------------------------------------------------------------------------------------------------

	@author		GMK
	@date		18/12/2014
	@brief		Classe de base représentant une entité dans l'espace de jeu

--------------------------------------------------------------------------------------------------*/

#ifndef SFGMK_ENTITY_HPP
#define SFGMK_ENTITY_HPP


namespace sfgmk
{
	class EntityTransformation;

	class SFGMK_API Entity : public sf::Transformable, WARDEN(Entity)
	{
		protected:
			int m_iEntityType;
			bool m_bIsAlive;
			unsigned int m_uiSingleId;

			bool m_bIsComputatedByParallax;
			bool m_bIsScaledByParallax;
			float m_fPositionZ;

			Sprite* m_Sprite;
			std::vector<EntityTransformation*> m_Transformation;
			sf::Vector2f m_RelativOrigin;

			sf::Transformable m_VirtualTransform;

			Collider* m_Collider;

			engine::AIStateMachine* m_AI;

			engine::MsgActor m_MsgActor;

		public:
			Entity(const int& _Type = 0);
			Entity(const sf::Vector3f& _Position, const int& _Type = 0);
			virtual ~Entity();

			virtual void update(const float& _TimeDelta);
			virtual void finalize(const float& _TimeDelta);
			virtual void draw(sf::RenderTexture* _Render);

			const int& getType();
			void setType(int _Type);
			const bool& getIsAlive();
			void setIsAlive(bool _State);
			const unsigned int& getSingleId();
			void setSingleId(const unsigned int& _Id);

			const bool& getIsComputatedByParralax();
			void setIsComputatedByParralax(bool _Boolean);
			const bool& getIsScaledByParralax();
			void setIsScaledByParralax(bool _Boolean);

			Sprite* getSprite();
			const sf::Vector2f& getRelativOrigin();
			void setRelativOrigin(const float& _X, const float& _Y);
			void addTransformation(EntityTransformation* _Transformation);
			void removeTransformation(const int _Index);
			std::vector<EntityTransformation*>& getTransformation();

			const float& getZ();
			sf::Vector2f getCenter();
			sf::Vector3f getPosition3D();
			void setPosition(const sf::Vector2f& position);
			void setPosition(const sf::Vector3f& _Position);
			void move(const sf::Vector2f& _Vector);
			void move(const sf::Vector3f& _Vector);

			sf::Transformable& getVirtualTransform();
			void setVirtualTransformWithTransform();

			Collider* getCollider();
			void addSphereCollider();
			void addSphereCollider(const float& _Radius);
			void addObbCollider();
			void addObbCollider(const sf::Vector2f& _Size);

			virtual void onPhysicEnter();
			virtual void onPhysicCollision(Entity* _entity);
			virtual void onPhysicExit();

			engine::AIStateMachine* getAiFsm();
			void addAiFsm(int _InitState = 0);
			bool addAiState(int _StateId, FoncterTemplate* _NewFunction, const std::string& _StateName);

			sfgmk::engine::MsgActor& getMsgActor();
	};
}


#endif
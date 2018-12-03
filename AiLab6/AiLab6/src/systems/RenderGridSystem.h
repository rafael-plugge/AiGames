#ifndef _RENDER_GRID_SYSTEM_H
#define _RENDER_GRID_SYSTEM_H

#include "BaseSystem.h"
#include "graphics/SfWindow.h"

namespace app::sys
{
	class RenderGridSystem : public BaseSystem
	{
	public: // Constructors/Destructor/Assignments
		RenderGridSystem(app::gra::SfWindow & window);
		virtual ~RenderGridSystem() = default;

		RenderGridSystem(RenderGridSystem const &) = default;
		RenderGridSystem & operator=(RenderGridSystem const &) = default;

		RenderGridSystem(RenderGridSystem &&) = default;
		RenderGridSystem & operator=(RenderGridSystem &&) = default;


	public: // Public Static Functions
	public: // Public Member Functions
		virtual void update(app::time::nanoseconds const & dt) override;
	public: // Public Static Variables
	public: // Public Member Variables
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
	private: // Private Static Functions
	private: // Private Member Functions
	private: // Private Static Variables
	private: // Private Member Variables
		app::gra::SfWindow & m_window;
		sf::RenderTexture m_renderTarget;
		sf::RectangleShape m_renderShape;
		sf::RenderStates const m_renderStates;
	};
}

#endif // !_RENDER_GRID_SYSTEM_H

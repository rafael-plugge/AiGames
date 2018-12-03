#ifndef _COMPONENT_RENDER_RECT_H
#define _COMPONENT_RENDER_RECT_H

#include "visitors/RenderRectVisitor.h"

namespace app::comp
{
	struct RenderRect
	{
	public: // Constructors/Destructor/Assignments
		RenderRect() = default;

		~RenderRect() = default;

		RenderRect(RenderRect const &) = default;
		RenderRect & operator=(RenderRect const &) = default;

		RenderRect(RenderRect &&) = default;
		RenderRect & operator=(RenderRect &&) = default;
	public: // Public Static Functions
	public: // Public Member Functions
	public: // Public Static Variables
	public: // Public Member Variables
		std::variant<std::shared_ptr<sf::Texture>, sf::Color> fill = nullptr;
		std::optional<sf::Color> stroke;
		std::optional<float> thickness;
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
	private: // Private Static Functions
	private: // Private Member Functions
	private: // Private Static Variables
	private: // Private Member Variables
	};

	void to_json(js::json & j, app::comp::RenderRect const & renderRect);
	void from_json(js::json const & j, app::comp::RenderRect & renderRect);
}

#endif // !_COMPONENT_RENDER_RECT_H

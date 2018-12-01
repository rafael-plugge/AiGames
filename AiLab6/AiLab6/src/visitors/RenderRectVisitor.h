#ifndef _VISITOR_RENDER_RECT_H
#define _VISITOR_RENDER_RECT_H

namespace app::vis
{
	class RenderRectVisitor
	{
	public: // Constructors/Destructor/Assignments
		RenderRectVisitor(sf::RectangleShape & renderShape);

		~RenderRectVisitor() = default;

		RenderRectVisitor(RenderRectVisitor const &) = default;
		RenderRectVisitor & operator=(RenderRectVisitor const &) = default;

		RenderRectVisitor(RenderRectVisitor &&) = default;
		RenderRectVisitor & operator=(RenderRectVisitor &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		void operator()(sf::Color const & color);
		void operator()(std::shared_ptr<sf::Texture> const & sptrTexture);
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
		sf::RectangleShape & m_renderShape;
	};
}

#endif // !_VISITOR_RENDER_RECT_H

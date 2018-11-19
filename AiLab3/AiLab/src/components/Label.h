#ifndef _LABEL_H
#define _LABEL_H

namespace app::comp
{
	struct Label
	{
	public: // Constructors/Destructor/Assignments
		Label() = default;
		Label(Label const &) = default;
		Label(Label &&) = default;

		~Label() = default;

		Label & operator=(Label const &) = default;
		Label & operator=(Label &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
	public: // Public Static Variables
	public: // Public Member Variables
		std::shared_ptr<sf::Font> font;
		std::string text;
		sf::Vector2f offset;
		sf::Color color;
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
	private: // Private Static Functions
	private: // Private Member Functions
	private: // Private Static Variables
	private: // Private Member Variables

	};
}

#endif // !_LABEL_H

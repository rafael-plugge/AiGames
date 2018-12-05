#ifndef _LAB_BLOCK_H
#define _LAB_BLOCK_H

namespace app::lab
{
	class Block
	{
	public: // Constructors/Destructor/Assignments
		Block() = default;
		~Block() = default;

		Block(Block const &) = default;
		Block & operator=(Block const &) = default;

		Block(Block &&) = default;
		Block & operator=(Block &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		bool const & getIsClicked() const;
		sf::Color const & getFill() const;

		Block & setClicked(bool const & clicked);
		Block & setClicked(bool && clicked);
	public: // Public Static Variables
	public: // Public Member Variables
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
	private: // Private Static Functions
	private: // Private Member Functions
		sf::Color getFillColor(bool const & clicked);
	private: // Private Static Variables
	private: // Private Member Variables
		bool m_clicked;
		sf::Color m_fill;
	};
}

#endif // !_LAB_BLOCK_H

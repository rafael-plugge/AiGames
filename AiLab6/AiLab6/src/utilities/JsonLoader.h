#ifndef _UTILITIES_JSON_LOADER_H
#define _UTILITIES_JSON_LOADER_H

namespace app::util
{
	class JsonLoader
	{
	private: // Constructors/Destructor/Assignments
		JsonLoader() = default;
		~JsonLoader() = default;

		JsonLoader(JsonLoader const &) = default;
		JsonLoader & operator=(JsonLoader const &) = default;

		JsonLoader(JsonLoader &&) = default;
		JsonLoader & operator=(JsonLoader &&) = default;

	public: // Public Static Functions
		static js::json load(std::string const & filepath);
	public: // Public Member Functions
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
	};
}

#endif // !_UTILITIES_JSON_LOADER_H

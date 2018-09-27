﻿#ifndef _MATH_H
#define _MATH_H

namespace app
{
	class Math
	{
	public: // Constructors/Destructor/Assignments
		Math() = delete;
		Math(Math const &) = delete;
		Math(Math &&) = delete;

		~Math() = delete;

		Math & operator=(Math const &) = delete;
		Math & operator=(Math &&) = delete;

	public: // Public Static Functions
		template<typename T>
		static constexpr T pi() { return static_cast<T>(std::acos(-1.0)); }
		template<typename T>
		static constexpr T degToRad(T const & degrees) { return degrees * (pi<T>() / static_cast<T>(180)); }
		template<typename T>
		static constexpr T radToDeg(T const & radians) { return radians * (static_cast<T>(180) / pi<T>()); }
		template<typename T>
		static constexpr T length(sf::Vector2<T> const & v) { return std::sqrt((v.x * v.x) + (v.y * v.y)); }
		template<typename T>
		static constexpr T absolute(T const & num) { return num > 0 ? num : -num; }
		template<typename T>
		static constexpr T angleBetweenRad(T const & left, T const & right) { return std::atan2(std::sin(left - right), std::cos(left - right)); }
		template<typename T>
		static constexpr T angleBetween(T const & left, T const & right) { return radToDeg(angleBetweenRad(degToRad(left), degToRad(right))); }
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

#endif // !_MATH_H

#include <iostream>

class Warlock
{
	private:
		std::string m_name;
		std::string m_title;

	public:
		Warlock();
		Warlock(std::string name, std::string title);
		Warlock(Warlock const &toCopy);
		Warlock &operator = (Warlock const &toCopy);
		~Warlock();
		const std::string &getName(void) const;
		const std::string &getTitle(void) const;
		void setTitle(const std::string &title);
		void introduce() const;

};

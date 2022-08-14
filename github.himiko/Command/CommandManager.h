#ifndef CommandManager_class
#define CommandManager_class

#include <vector> 
#include <string>
#include <exception>
#include "Command.h"

using namespace github;
using CommandList = std::vector<Command*>;

namespace github
{
	class CommandManager
	{
	public: 
		CommandManager() = default;

		/// <summary>
		/// Checks if command allready excist
		/// </summary>
		/// <returns></returns>
		bool is_command_alive(const std::string command_name);
		/// <summary>
		/// Adds object to a Command List
		/// </summary>
		/// <param name="command"></param>
		/// <returns></returns>
		CommandManager operator+=(Command* command);
		/// <summary>
		/// Pointer points to the Commands which are in the same Category
		/// </summary>
		/// <returns></returns>
		Command* get_commands_by_category(Category category);
		/// <summary>
		/// Pointer points to the Messeage Command which got the this commandName
		/// </summary>
		/// <param name="commandName"></param>
		/// <returns></returns>
		Command* get_commands_by_name(std::string commandName);
		/// <summary>
		/// Pointer points to the Slash Command which got the this commandName
		/// </summary>
		/// <param name="commandName"></param>
		/// <returns></returns>
		Command* get_slash_command_by_name(std::string commandName);
		/// <summary>
		/// Gets Command information
		/// </summary>
		std::string get_commands_info();


	private:
		CommandList commands;
	};
}

#endif
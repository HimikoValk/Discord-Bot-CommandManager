#include <vector> 
#include <string>
#include <exception>
#include "Command.h"
#include "CommandManager.h"

namespace github
{
	bool CommandManager::is_command_alive(const std::string command_name)
	{
		for (auto item : commands)
		{
			if ('!' + item->get_command_name() == command_name)
			{
				return true;
			}
		}

		return false;
	}

	CommandManager CommandManager::operator+=(Command* command)
	{
		if (is_command_alive(command->get_command_name()) == false)
		{
			commands.push_back(command);
			std::cout << command->get_command_name() << " Added!" << std::endl;
			return *this;
		}
		else
		{
			throw std::exception("Command allready Excist!");
		}
	}

	Command* CommandManager::get_commands_by_name(std::string commandName)
	{
		for (auto item : commands)
		{
			if ('!' + item->get_command_name() == commandName)
			{
				return item;
			}
		}
	}

	Command* CommandManager::get_slash_command_by_name(std::string commandName)
	{
		for (auto item : commands)
		{
			if (item->get_command_name() == commandName)
			{
				return item;
			}
		}
	}

	Command* CommandManager::get_commands_by_category(Category category)
	{
		for (auto item : commands)
		{
			if (item->get_category() == category)
			{
				return item;
			}
		}
	}

	std::string CommandManager::get_commands_info()
	{
		std::string commandInfos = "";
		for (auto item : commands)
		{
			commandInfos += item->get_command_name();
		}
		return commandInfos;
	}
}


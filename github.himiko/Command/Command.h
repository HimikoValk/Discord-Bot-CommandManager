#include <dpp/dpp.h>
#include <string>
#include <vector>
#pragma once


namespace github
{
	enum Category
	{
		FUN, HELP, TICKET, TOKEN
	};

	class Command
	{
	public:
		Command(const std::string commandName, const std::string commandDescription, Category category) : commandName(commandName), commandDescription(commandDescription), category(category)
		{

		}

		std::string get_command_name()
		{
			return this->commandName;
		}

		std::string get_command_description()
		{
			return this->commandDescription;
		}

		Category get_category()
		{
			return this->category;
		}

		virtual void onCommand(dpp::message_create_t event, dpp::cluster* bot)
		{

		}

		virtual void onSlashCommand(dpp::slashcommand_t event, dpp::cluster* bot)
		{

		}

	private:
		const std::string commandName;
		const std::string commandDescription;
		const Category category;
	};
}
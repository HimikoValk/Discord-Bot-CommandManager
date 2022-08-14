#include "Command/CommandManager.h"
#include "Command/Command.h"
#include "Command/Commands/TestCommand.h"

#include <iostream>
#include <dpp/dpp.h>

static github::CommandManager commandManager; 

github::TestCommand testCommand; 

const std::string BOT_TOKEN = "Your Token"; 


int main()
{
	//Add Command to CommandManager
	commandManager += &testCommand;

	/*Create bot cluster*/
	dpp::cluster bot(BOT_TOKEN, dpp::i_default_intents | dpp::i_message_content);

	/*Output log messages*/
	bot.on_log(dpp::utility::cout_logger()); 

	/*Reades Messages and checking if it is a Command*/
	bot.on_message_create([&](const dpp::message_create_t& event)
		{
			if (commandManager.is_command_alive(event.msg.content))
			{
				auto com = commandManager.get_commands_by_name(event.msg.content);
				com->onCommand(event, &bot); 
			}
		}); 

	/*Start the bot*/
	bot.start(false); 
	return 0; 
}
#include "../Command.h"
#include "../CommandManager.h"
#include <dpp/dpp.h>
#include <string>
#include <vector>
#include <vector>
#pragma once

namespace github
{
	class TestCommand : public Command
	{
	public:
		TestCommand() : Command("test", "Just a Test Command", Category::FUN)
		{
			
		}

		void onCommand(dpp::message_create_t event, dpp::cluster* bot) override
		{
			bot->message_create(dpp::message(event.msg.channel_id, "Hello this is a Test Command!"));
		}

	};
}

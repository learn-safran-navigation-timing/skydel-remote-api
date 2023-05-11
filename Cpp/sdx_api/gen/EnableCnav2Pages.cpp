
#include "gen/EnableCnav2Pages.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnableCnav2Pages
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnableCnav2Pages::CmdName = "EnableCnav2Pages";
    const char* const EnableCnav2Pages::Documentation = "Set the enabled L1C CNAV2 pages";

    REGISTER_COMMAND_FACTORY(EnableCnav2Pages);


    EnableCnav2Pages::EnableCnav2Pages()
      : CommandBase(CmdName)
    {}

    EnableCnav2Pages::EnableCnav2Pages(const std::vector<int>& messages)
      : CommandBase(CmdName)
    {

      setMessages(messages);
    }

    EnableCnav2PagesPtr EnableCnav2Pages::create(const std::vector<int>& messages)
    {
      return std::make_shared<EnableCnav2Pages>(messages);
    }

    EnableCnav2PagesPtr EnableCnav2Pages::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EnableCnav2Pages>(ptr);
    }

    bool EnableCnav2Pages::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<int>>::is_valid(m_values["Messages"])
        ;

    }

    std::string EnableCnav2Pages::documentation() const { return Documentation; }


    int EnableCnav2Pages::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::vector<int> EnableCnav2Pages::messages() const
    {
      return parse_json<std::vector<int>>::parse(m_values["Messages"]);
    }

    void EnableCnav2Pages::setMessages(const std::vector<int>& messages)
    {
      m_values.AddMember("Messages", parse_json<std::vector<int>>::format(messages, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

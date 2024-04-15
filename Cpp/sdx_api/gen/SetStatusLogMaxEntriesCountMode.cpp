
#include "SetStatusLogMaxEntriesCountMode.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetStatusLogMaxEntriesCountMode
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetStatusLogMaxEntriesCountMode::CmdName = "SetStatusLogMaxEntriesCountMode";
    const char* const SetStatusLogMaxEntriesCountMode::Documentation = "Sets the mode for how the maximum number of entries in the Status Log is handled. The \"Unlimited\" mode allows the Status Log to have an infinite amount of entries. The \"Custom\" mode allows to set a maximum entries count for the Status Log. In that mode, when the maximum count is reached, Skydel will start overwritting the older entries in the Status Log.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"
      "Mode string Status Log maximum count mode, accepts \"Unlimited\" and \"Custom\". If \"Custom\" mode is set, use the command SetStatusLogMaxEntriesCount to set the maximum number of entries in the Status Log.";
    const char* const SetStatusLogMaxEntriesCountMode::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetStatusLogMaxEntriesCountMode);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetStatusLogMaxEntriesCountMode);


    SetStatusLogMaxEntriesCountMode::SetStatusLogMaxEntriesCountMode()
      : CommandBase(CmdName, TargetId)
    {}

    SetStatusLogMaxEntriesCountMode::SetStatusLogMaxEntriesCountMode(const std::string& mode)
      : CommandBase(CmdName, TargetId)
    {

      setMode(mode);
    }

    SetStatusLogMaxEntriesCountModePtr SetStatusLogMaxEntriesCountMode::create(const std::string& mode)
    {
      return std::make_shared<SetStatusLogMaxEntriesCountMode>(mode);
    }

    SetStatusLogMaxEntriesCountModePtr SetStatusLogMaxEntriesCountMode::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetStatusLogMaxEntriesCountMode>(ptr);
    }

    bool SetStatusLogMaxEntriesCountMode::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Mode"])
        ;

    }

    std::string SetStatusLogMaxEntriesCountMode::documentation() const { return Documentation; }

    const std::vector<std::string>& SetStatusLogMaxEntriesCountMode::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Mode"}; 
      return names; 
    }


    int SetStatusLogMaxEntriesCountMode::executePermission() const
    {
      return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }


    std::string SetStatusLogMaxEntriesCountMode::mode() const
    {
      return parse_json<std::string>::parse(m_values["Mode"]);
    }

    void SetStatusLogMaxEntriesCountMode::setMode(const std::string& mode)
    {
      m_values.AddMember("Mode", parse_json<std::string>::format(mode, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

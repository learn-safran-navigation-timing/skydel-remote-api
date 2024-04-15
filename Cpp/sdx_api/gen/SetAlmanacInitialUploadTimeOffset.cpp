
#include "SetAlmanacInitialUploadTimeOffset.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetAlmanacInitialUploadTimeOffset
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetAlmanacInitialUploadTimeOffset::CmdName = "SetAlmanacInitialUploadTimeOffset";
    const char* const SetAlmanacInitialUploadTimeOffset::Documentation = "Set next almanac upload time relative to simulation start time.\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ -------------------------------------------------------------------------------------------\n"
      "System string Must be \"GPS\"\n"
      "Offset int    Next upload time in sec (relative to simulation start time). Accepted range is [30..259200]";
    const char* const SetAlmanacInitialUploadTimeOffset::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetAlmanacInitialUploadTimeOffset);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetAlmanacInitialUploadTimeOffset);


    SetAlmanacInitialUploadTimeOffset::SetAlmanacInitialUploadTimeOffset()
      : CommandBase(CmdName, TargetId)
    {}

    SetAlmanacInitialUploadTimeOffset::SetAlmanacInitialUploadTimeOffset(const std::string& system, int offset)
      : CommandBase(CmdName, TargetId)
    {

      setSystem(system);
      setOffset(offset);
    }

    SetAlmanacInitialUploadTimeOffsetPtr SetAlmanacInitialUploadTimeOffset::create(const std::string& system, int offset)
    {
      return std::make_shared<SetAlmanacInitialUploadTimeOffset>(system, offset);
    }

    SetAlmanacInitialUploadTimeOffsetPtr SetAlmanacInitialUploadTimeOffset::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetAlmanacInitialUploadTimeOffset>(ptr);
    }

    bool SetAlmanacInitialUploadTimeOffset::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["Offset"])
        ;

    }

    std::string SetAlmanacInitialUploadTimeOffset::documentation() const { return Documentation; }

    const std::vector<std::string>& SetAlmanacInitialUploadTimeOffset::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "Offset"}; 
      return names; 
    }


    int SetAlmanacInitialUploadTimeOffset::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetAlmanacInitialUploadTimeOffset::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void SetAlmanacInitialUploadTimeOffset::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetAlmanacInitialUploadTimeOffset::offset() const
    {
      return parse_json<int>::parse(m_values["Offset"]);
    }

    void SetAlmanacInitialUploadTimeOffset::setOffset(int offset)
    {
      m_values.AddMember("Offset", parse_json<int>::format(offset, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

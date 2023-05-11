
#include "gen/SetAlmanacInitialUploadTimeOffset.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetAlmanacInitialUploadTimeOffset
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetAlmanacInitialUploadTimeOffset::CmdName = "SetAlmanacInitialUploadTimeOffset";
    const char* const SetAlmanacInitialUploadTimeOffset::Documentation = "Set next almanac upload time relative to simulation start time.";

    REGISTER_COMMAND_FACTORY(SetAlmanacInitialUploadTimeOffset);


    SetAlmanacInitialUploadTimeOffset::SetAlmanacInitialUploadTimeOffset()
      : CommandBase(CmdName)
    {}

    SetAlmanacInitialUploadTimeOffset::SetAlmanacInitialUploadTimeOffset(const std::string& system, int offset)
      : CommandBase(CmdName)
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

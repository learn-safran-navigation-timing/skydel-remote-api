
#include "gen/SetEphemerisTocOffset.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetEphemerisTocOffset
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetEphemerisTocOffset::CmdName = "SetEphemerisTocOffset";
    const char* const SetEphemerisTocOffset::Documentation = "Set the ephemeris TOC offset in seconds relative to the ephemeris update time.";

    REGISTER_COMMAND_FACTORY(SetEphemerisTocOffset);


    SetEphemerisTocOffset::SetEphemerisTocOffset()
      : CommandBase(CmdName)
    {}

    SetEphemerisTocOffset::SetEphemerisTocOffset(const std::string& system, int offset)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setOffset(offset);
    }

    SetEphemerisTocOffsetPtr SetEphemerisTocOffset::create(const std::string& system, int offset)
    {
      return std::make_shared<SetEphemerisTocOffset>(system, offset);
    }

    SetEphemerisTocOffsetPtr SetEphemerisTocOffset::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetEphemerisTocOffset>(ptr);
    }

    bool SetEphemerisTocOffset::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["Offset"])
        ;

    }

    std::string SetEphemerisTocOffset::documentation() const { return Documentation; }


    int SetEphemerisTocOffset::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetEphemerisTocOffset::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void SetEphemerisTocOffset::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetEphemerisTocOffset::offset() const
    {
      return parse_json<int>::parse(m_values["Offset"]);
    }

    void SetEphemerisTocOffset::setOffset(int offset)
    {
      m_values.AddMember("Offset", parse_json<int>::format(offset, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

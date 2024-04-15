
#include "SetEphemerisTocOffset.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetEphemerisTocOffset
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetEphemerisTocOffset::CmdName = "SetEphemerisTocOffset";
    const char* const SetEphemerisTocOffset::Documentation = "Set the ephemeris TOC offset in seconds relative to the ephemeris update time.\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ -------------------------------------------------------\n"
      "System string \"GPS\", \"Galileo\", \"BeiDou\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
      "Offset int    Offset in sec. Accepted range is [-604800..604800].";
    const char* const SetEphemerisTocOffset::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetEphemerisTocOffset);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetEphemerisTocOffset);


    SetEphemerisTocOffset::SetEphemerisTocOffset()
      : CommandBase(CmdName, TargetId)
    {}

    SetEphemerisTocOffset::SetEphemerisTocOffset(const std::string& system, int offset)
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& SetEphemerisTocOffset::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "Offset"}; 
      return names; 
    }


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

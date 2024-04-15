
#include "GetEphemerisTocOffset.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetEphemerisTocOffset
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetEphemerisTocOffset::CmdName = "GetEphemerisTocOffset";
    const char* const GetEphemerisTocOffset::Documentation = "Get the ephemeris TOC offset in seconds relative to the ephemeris update time.\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ -------------------------------------------------------\n"
      "System string \"GPS\", \"Galileo\", \"BeiDou\", \"QZSS\", \"NavIC\" or \"PULSAR\"";
    const char* const GetEphemerisTocOffset::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetEphemerisTocOffset);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetEphemerisTocOffset);


    GetEphemerisTocOffset::GetEphemerisTocOffset()
      : CommandBase(CmdName, TargetId)
    {}

    GetEphemerisTocOffset::GetEphemerisTocOffset(const std::string& system)
      : CommandBase(CmdName, TargetId)
    {

      setSystem(system);
    }

    GetEphemerisTocOffsetPtr GetEphemerisTocOffset::create(const std::string& system)
    {
      return std::make_shared<GetEphemerisTocOffset>(system);
    }

    GetEphemerisTocOffsetPtr GetEphemerisTocOffset::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetEphemerisTocOffset>(ptr);
    }

    bool GetEphemerisTocOffset::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
        ;

    }

    std::string GetEphemerisTocOffset::documentation() const { return Documentation; }

    const std::vector<std::string>& GetEphemerisTocOffset::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System"}; 
      return names; 
    }


    int GetEphemerisTocOffset::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetEphemerisTocOffset::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetEphemerisTocOffset::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

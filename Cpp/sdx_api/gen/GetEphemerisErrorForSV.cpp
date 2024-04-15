
#include "GetEphemerisErrorForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetEphemerisErrorForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetEphemerisErrorForSV::CmdName = "GetEphemerisErrorForSV";
    const char* const GetEphemerisErrorForSV::Documentation = "Get the satellite ephemeris error.\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ ------------------------------------------------------------------\n"
      "System string \"GPS\", \"Galileo\", \"GLONASS\", \"BeiDou\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
      "SvId   int    Satellite SV ID.";
    const char* const GetEphemerisErrorForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetEphemerisErrorForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetEphemerisErrorForSV);


    GetEphemerisErrorForSV::GetEphemerisErrorForSV()
      : CommandBase(CmdName, TargetId)
    {}

    GetEphemerisErrorForSV::GetEphemerisErrorForSV(const std::string& system, int svId)
      : CommandBase(CmdName, TargetId)
    {

      setSystem(system);
      setSvId(svId);
    }

    GetEphemerisErrorForSVPtr GetEphemerisErrorForSV::create(const std::string& system, int svId)
    {
      return std::make_shared<GetEphemerisErrorForSV>(system, svId);
    }

    GetEphemerisErrorForSVPtr GetEphemerisErrorForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetEphemerisErrorForSV>(ptr);
    }

    bool GetEphemerisErrorForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
        ;

    }

    std::string GetEphemerisErrorForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& GetEphemerisErrorForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "SvId"}; 
      return names; 
    }


    int GetEphemerisErrorForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetEphemerisErrorForSV::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetEphemerisErrorForSV::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetEphemerisErrorForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetEphemerisErrorForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

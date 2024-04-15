
#include "GetElevationAzimuthForEachSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetElevationAzimuthForEachSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetElevationAzimuthForEachSV::CmdName = "GetElevationAzimuthForEachSV";
    const char* const GetElevationAzimuthForEachSV::Documentation = "Get elevation and azimuth position angles for all satellites.\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ ---------------------------------------------------------------------------\n"
      "System string \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\".";
    const char* const GetElevationAzimuthForEachSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetElevationAzimuthForEachSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetElevationAzimuthForEachSV);


    GetElevationAzimuthForEachSV::GetElevationAzimuthForEachSV()
      : CommandBase(CmdName, TargetId)
    {}

    GetElevationAzimuthForEachSV::GetElevationAzimuthForEachSV(const std::string& system)
      : CommandBase(CmdName, TargetId)
    {

      setSystem(system);
    }

    GetElevationAzimuthForEachSVPtr GetElevationAzimuthForEachSV::create(const std::string& system)
    {
      return std::make_shared<GetElevationAzimuthForEachSV>(system);
    }

    GetElevationAzimuthForEachSVPtr GetElevationAzimuthForEachSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetElevationAzimuthForEachSV>(ptr);
    }

    bool GetElevationAzimuthForEachSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
        ;

    }

    std::string GetElevationAzimuthForEachSV::documentation() const { return Documentation; }

    const std::vector<std::string>& GetElevationAzimuthForEachSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System"}; 
      return names; 
    }


    int GetElevationAzimuthForEachSV::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }


    std::string GetElevationAzimuthForEachSV::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetElevationAzimuthForEachSV::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

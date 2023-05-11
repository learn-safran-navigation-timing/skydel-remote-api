
#include "gen/GetElevationAzimuthForEachSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetElevationAzimuthForEachSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetElevationAzimuthForEachSV::CmdName = "GetElevationAzimuthForEachSV";
    const char* const GetElevationAzimuthForEachSV::Documentation = "Get elevation and azimuth position angles for all satellites.";

    REGISTER_COMMAND_FACTORY(GetElevationAzimuthForEachSV);


    GetElevationAzimuthForEachSV::GetElevationAzimuthForEachSV()
      : CommandBase(CmdName)
    {}

    GetElevationAzimuthForEachSV::GetElevationAzimuthForEachSV(const std::string& system)
      : CommandBase(CmdName)
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

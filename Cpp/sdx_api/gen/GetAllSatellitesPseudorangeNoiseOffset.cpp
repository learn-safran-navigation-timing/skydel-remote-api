
#include "gen/GetAllSatellitesPseudorangeNoiseOffset.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetAllSatellitesPseudorangeNoiseOffset
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetAllSatellitesPseudorangeNoiseOffset::CmdName = "GetAllSatellitesPseudorangeNoiseOffset";
    const char* const GetAllSatellitesPseudorangeNoiseOffset::Documentation = "Please note the command GetAllSatellitesPseudorangeNoiseOffset is deprecated since 21.3. You may use GetPseudorangeNoiseOffsetForEachSV.\n\nGet the satellite pseudorange noise constant offset for all satellites.";

    REGISTER_COMMAND_FACTORY(GetAllSatellitesPseudorangeNoiseOffset);


    GetAllSatellitesPseudorangeNoiseOffset::GetAllSatellitesPseudorangeNoiseOffset()
      : CommandBase(CmdName)
    {}

    GetAllSatellitesPseudorangeNoiseOffset::GetAllSatellitesPseudorangeNoiseOffset(const std::string& system)
      : CommandBase(CmdName)
    {

      setSystem(system);
    }

    GetAllSatellitesPseudorangeNoiseOffsetPtr GetAllSatellitesPseudorangeNoiseOffset::create(const std::string& system)
    {
      return std::make_shared<GetAllSatellitesPseudorangeNoiseOffset>(system);
    }

    GetAllSatellitesPseudorangeNoiseOffsetPtr GetAllSatellitesPseudorangeNoiseOffset::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetAllSatellitesPseudorangeNoiseOffset>(ptr);
    }

    bool GetAllSatellitesPseudorangeNoiseOffset::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
        ;

    }

    std::string GetAllSatellitesPseudorangeNoiseOffset::documentation() const { return Documentation; }


    int GetAllSatellitesPseudorangeNoiseOffset::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetAllSatellitesPseudorangeNoiseOffset::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetAllSatellitesPseudorangeNoiseOffset::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

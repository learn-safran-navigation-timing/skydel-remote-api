
#include "GetAllSatellitesPseudorangeNoiseOffset.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetAllSatellitesPseudorangeNoiseOffset
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetAllSatellitesPseudorangeNoiseOffset::CmdName = "GetAllSatellitesPseudorangeNoiseOffset";
    const char* const GetAllSatellitesPseudorangeNoiseOffset::Documentation = "Please note the command GetAllSatellitesPseudorangeNoiseOffset is deprecated since 21.3. You may use GetPseudorangeNoiseOffsetForEachSV.\n"
      "\n"
      "Get the satellite pseudorange noise constant offset for all satellites.\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ --------------------------------------------------------------------------\n"
      "System string \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"";
    const char* const GetAllSatellitesPseudorangeNoiseOffset::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetAllSatellitesPseudorangeNoiseOffset);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetAllSatellitesPseudorangeNoiseOffset);


    GetAllSatellitesPseudorangeNoiseOffset::GetAllSatellitesPseudorangeNoiseOffset()
      : CommandBase(CmdName, TargetId)
    {}

    GetAllSatellitesPseudorangeNoiseOffset::GetAllSatellitesPseudorangeNoiseOffset(const std::string& system)
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& GetAllSatellitesPseudorangeNoiseOffset::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System"}; 
      return names; 
    }


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

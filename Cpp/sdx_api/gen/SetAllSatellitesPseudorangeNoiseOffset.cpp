
#include "SetAllSatellitesPseudorangeNoiseOffset.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetAllSatellitesPseudorangeNoiseOffset
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetAllSatellitesPseudorangeNoiseOffset::CmdName = "SetAllSatellitesPseudorangeNoiseOffset";
    const char* const SetAllSatellitesPseudorangeNoiseOffset::Documentation = "Please note the command SetAllSatellitesPseudorangeNoiseOffset is deprecated since 21.3. You may use SetPseudorangeNoiseOffsetForEachSV.\n"
      "\n"
      "Set the satellite pseudorange noise constant offset for all satellites.\n"
      "\n"
      "Name    Type         Description\n"
      "------- ------------ --------------------------------------------------------------------------\n"
      "System  string       \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
      "Enabled array bool   If true, the offset is enabled (applied)\n"
      "Offset  array double The constant offset in metters";
    const char* const SetAllSatellitesPseudorangeNoiseOffset::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetAllSatellitesPseudorangeNoiseOffset);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetAllSatellitesPseudorangeNoiseOffset);


    SetAllSatellitesPseudorangeNoiseOffset::SetAllSatellitesPseudorangeNoiseOffset()
      : CommandBase(CmdName, TargetId)
    {}

    SetAllSatellitesPseudorangeNoiseOffset::SetAllSatellitesPseudorangeNoiseOffset(const std::string& system, const std::vector<bool>& enabled, const std::vector<double>& offset)
      : CommandBase(CmdName, TargetId)
    {

      setSystem(system);
      setEnabled(enabled);
      setOffset(offset);
    }

    SetAllSatellitesPseudorangeNoiseOffsetPtr SetAllSatellitesPseudorangeNoiseOffset::create(const std::string& system, const std::vector<bool>& enabled, const std::vector<double>& offset)
    {
      return std::make_shared<SetAllSatellitesPseudorangeNoiseOffset>(system, enabled, offset);
    }

    SetAllSatellitesPseudorangeNoiseOffsetPtr SetAllSatellitesPseudorangeNoiseOffset::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetAllSatellitesPseudorangeNoiseOffset>(ptr);
    }

    bool SetAllSatellitesPseudorangeNoiseOffset::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<std::vector<bool>>::is_valid(m_values["Enabled"])
          && parse_json<std::vector<double>>::is_valid(m_values["Offset"])
        ;

    }

    std::string SetAllSatellitesPseudorangeNoiseOffset::documentation() const { return Documentation; }

    const std::vector<std::string>& SetAllSatellitesPseudorangeNoiseOffset::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "Enabled", "Offset"}; 
      return names; 
    }


    int SetAllSatellitesPseudorangeNoiseOffset::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetAllSatellitesPseudorangeNoiseOffset::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void SetAllSatellitesPseudorangeNoiseOffset::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<bool> SetAllSatellitesPseudorangeNoiseOffset::enabled() const
    {
      return parse_json<std::vector<bool>>::parse(m_values["Enabled"]);
    }

    void SetAllSatellitesPseudorangeNoiseOffset::setEnabled(const std::vector<bool>& enabled)
    {
      m_values.AddMember("Enabled", parse_json<std::vector<bool>>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> SetAllSatellitesPseudorangeNoiseOffset::offset() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Offset"]);
    }

    void SetAllSatellitesPseudorangeNoiseOffset::setOffset(const std::vector<double>& offset)
    {
      m_values.AddMember("Offset", parse_json<std::vector<double>>::format(offset, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

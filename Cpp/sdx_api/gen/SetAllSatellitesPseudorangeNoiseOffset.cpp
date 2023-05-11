
#include "gen/SetAllSatellitesPseudorangeNoiseOffset.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetAllSatellitesPseudorangeNoiseOffset
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetAllSatellitesPseudorangeNoiseOffset::CmdName = "SetAllSatellitesPseudorangeNoiseOffset";
    const char* const SetAllSatellitesPseudorangeNoiseOffset::Documentation = "Please note the command SetAllSatellitesPseudorangeNoiseOffset is deprecated since 21.3. You may use SetPseudorangeNoiseOffsetForEachSV.\n\nSet the satellite pseudorange noise constant offset for all satellites.";

    REGISTER_COMMAND_FACTORY(SetAllSatellitesPseudorangeNoiseOffset);


    SetAllSatellitesPseudorangeNoiseOffset::SetAllSatellitesPseudorangeNoiseOffset()
      : CommandBase(CmdName)
    {}

    SetAllSatellitesPseudorangeNoiseOffset::SetAllSatellitesPseudorangeNoiseOffset(const std::string& system, const std::vector<bool>& enabled, const std::vector<double>& offset)
      : CommandBase(CmdName)
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


#include "GetSVGainPatternOffset.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSVGainPatternOffset
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSVGainPatternOffset::CmdName = "GetSVGainPatternOffset";
    const char* const GetSVGainPatternOffset::Documentation = "Get the offset (in dB) for the antenna gain pattern of the band.\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- ------------------------------------------------------------------------------------\n"
      "Band        GNSSBand        Offset will be apply to this band. (\"L1\", \"L2\", \"L5\", \"E6\" or \"S\")\n"
      "System      string          \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
      "AntennaName optional string Vehicle antenna name. If no name is specified, apply the offset to the Basic Antenna";
    const char* const GetSVGainPatternOffset::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetSVGainPatternOffset);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetSVGainPatternOffset);


    GetSVGainPatternOffset::GetSVGainPatternOffset()
      : CommandBase(CmdName, TargetId)
    {}

    GetSVGainPatternOffset::GetSVGainPatternOffset(const Sdx::GNSSBand& band, const std::string& system, const std::optional<std::string>& antennaName)
      : CommandBase(CmdName, TargetId)
    {

      setBand(band);
      setSystem(system);
      setAntennaName(antennaName);
    }

    GetSVGainPatternOffsetPtr GetSVGainPatternOffset::create(const Sdx::GNSSBand& band, const std::string& system, const std::optional<std::string>& antennaName)
    {
      return std::make_shared<GetSVGainPatternOffset>(band, system, antennaName);
    }

    GetSVGainPatternOffsetPtr GetSVGainPatternOffset::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSVGainPatternOffset>(ptr);
    }

    bool GetSVGainPatternOffset::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<Sdx::GNSSBand>::is_valid(m_values["Band"])
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["AntennaName"])
        ;

    }

    std::string GetSVGainPatternOffset::documentation() const { return Documentation; }

    const std::vector<std::string>& GetSVGainPatternOffset::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Band", "System", "AntennaName"}; 
      return names; 
    }


    int GetSVGainPatternOffset::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    Sdx::GNSSBand GetSVGainPatternOffset::band() const
    {
      return parse_json<Sdx::GNSSBand>::parse(m_values["Band"]);
    }

    void GetSVGainPatternOffset::setBand(const Sdx::GNSSBand& band)
    {
      m_values.AddMember("Band", parse_json<Sdx::GNSSBand>::format(band, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetSVGainPatternOffset::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetSVGainPatternOffset::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> GetSVGainPatternOffset::antennaName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["AntennaName"]);
    }

    void GetSVGainPatternOffset::setAntennaName(const std::optional<std::string>& antennaName)
    {
      m_values.AddMember("AntennaName", parse_json<std::optional<std::string>>::format(antennaName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

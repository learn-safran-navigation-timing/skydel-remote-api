
#include "GetSVPhasePatternOffset.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSVPhasePatternOffset
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSVPhasePatternOffset::CmdName = "GetSVPhasePatternOffset";
    const char* const GetSVPhasePatternOffset::Documentation = "Get the offset (in rad) for the antenna phase pattern of the band.\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- ------------------------------------------------------------------------------------\n"
      "Band        GNSSBand        Offset will be apply to this band.\n"
      "System      string          \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
      "AntennaName optional string Vehicle antenna name. If no name is specified, apply the offset to the Basic Antenna";
    const char* const GetSVPhasePatternOffset::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetSVPhasePatternOffset);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetSVPhasePatternOffset);


    GetSVPhasePatternOffset::GetSVPhasePatternOffset()
      : CommandBase(CmdName, TargetId)
    {}

    GetSVPhasePatternOffset::GetSVPhasePatternOffset(const Sdx::GNSSBand& band, const std::string& system, const std::optional<std::string>& antennaName)
      : CommandBase(CmdName, TargetId)
    {

      setBand(band);
      setSystem(system);
      setAntennaName(antennaName);
    }

    GetSVPhasePatternOffsetPtr GetSVPhasePatternOffset::create(const Sdx::GNSSBand& band, const std::string& system, const std::optional<std::string>& antennaName)
    {
      return std::make_shared<GetSVPhasePatternOffset>(band, system, antennaName);
    }

    GetSVPhasePatternOffsetPtr GetSVPhasePatternOffset::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSVPhasePatternOffset>(ptr);
    }

    bool GetSVPhasePatternOffset::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<Sdx::GNSSBand>::is_valid(m_values["Band"])
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["AntennaName"])
        ;

    }

    std::string GetSVPhasePatternOffset::documentation() const { return Documentation; }

    const std::vector<std::string>& GetSVPhasePatternOffset::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Band", "System", "AntennaName"}; 
      return names; 
    }


    int GetSVPhasePatternOffset::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    Sdx::GNSSBand GetSVPhasePatternOffset::band() const
    {
      return parse_json<Sdx::GNSSBand>::parse(m_values["Band"]);
    }

    void GetSVPhasePatternOffset::setBand(const Sdx::GNSSBand& band)
    {
      m_values.AddMember("Band", parse_json<Sdx::GNSSBand>::format(band, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetSVPhasePatternOffset::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetSVPhasePatternOffset::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> GetSVPhasePatternOffset::antennaName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["AntennaName"]);
    }

    void GetSVPhasePatternOffset::setAntennaName(const std::optional<std::string>& antennaName)
    {
      m_values.AddMember("AntennaName", parse_json<std::optional<std::string>>::format(antennaName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

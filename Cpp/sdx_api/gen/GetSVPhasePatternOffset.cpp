
#include "gen/GetSVPhasePatternOffset.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSVPhasePatternOffset
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSVPhasePatternOffset::CmdName = "GetSVPhasePatternOffset";
    const char* const GetSVPhasePatternOffset::Documentation = "Get the offset (in rad) for the antenna phase pattern of the band.";

    REGISTER_COMMAND_FACTORY(GetSVPhasePatternOffset);


    GetSVPhasePatternOffset::GetSVPhasePatternOffset()
      : CommandBase(CmdName)
    {}

    GetSVPhasePatternOffset::GetSVPhasePatternOffset(const Sdx::GNSSBand& band, const std::string& system, const Sdx::optional<std::string>& antennaName)
      : CommandBase(CmdName)
    {

      setBand(band);
      setSystem(system);
      setAntennaName(antennaName);
    }

    GetSVPhasePatternOffsetPtr GetSVPhasePatternOffset::create(const Sdx::GNSSBand& band, const std::string& system, const Sdx::optional<std::string>& antennaName)
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
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["AntennaName"])
        ;

    }

    std::string GetSVPhasePatternOffset::documentation() const { return Documentation; }


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



    Sdx::optional<std::string> GetSVPhasePatternOffset::antennaName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["AntennaName"]);
    }

    void GetSVPhasePatternOffset::setAntennaName(const Sdx::optional<std::string>& antennaName)
    {
      m_values.AddMember("AntennaName", parse_json<Sdx::optional<std::string>>::format(antennaName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

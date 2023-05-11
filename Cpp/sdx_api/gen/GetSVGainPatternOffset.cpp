
#include "gen/GetSVGainPatternOffset.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSVGainPatternOffset
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSVGainPatternOffset::CmdName = "GetSVGainPatternOffset";
    const char* const GetSVGainPatternOffset::Documentation = "Get the offset (in dB) for the antenna gain pattern of the band.";

    REGISTER_COMMAND_FACTORY(GetSVGainPatternOffset);


    GetSVGainPatternOffset::GetSVGainPatternOffset()
      : CommandBase(CmdName)
    {}

    GetSVGainPatternOffset::GetSVGainPatternOffset(const Sdx::GNSSBand& band, const std::string& system, const Sdx::optional<std::string>& antennaName)
      : CommandBase(CmdName)
    {

      setBand(band);
      setSystem(system);
      setAntennaName(antennaName);
    }

    GetSVGainPatternOffsetPtr GetSVGainPatternOffset::create(const Sdx::GNSSBand& band, const std::string& system, const Sdx::optional<std::string>& antennaName)
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
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["AntennaName"])
        ;

    }

    std::string GetSVGainPatternOffset::documentation() const { return Documentation; }


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



    Sdx::optional<std::string> GetSVGainPatternOffset::antennaName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["AntennaName"]);
    }

    void GetSVGainPatternOffset::setAntennaName(const Sdx::optional<std::string>& antennaName)
    {
      m_values.AddMember("AntennaName", parse_json<Sdx::optional<std::string>>::format(antennaName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

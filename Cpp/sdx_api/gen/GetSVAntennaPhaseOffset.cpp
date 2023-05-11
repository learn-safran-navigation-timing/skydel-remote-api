
#include "gen/GetSVAntennaPhaseOffset.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSVAntennaPhaseOffset
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSVAntennaPhaseOffset::CmdName = "GetSVAntennaPhaseOffset";
    const char* const GetSVAntennaPhaseOffset::Documentation = "Get space vehicle phase offset antenna pattern. If no name is specified, the command is aplied to Basic Vehicle Antenna.";

    REGISTER_COMMAND_FACTORY(GetSVAntennaPhaseOffset);


    GetSVAntennaPhaseOffset::GetSVAntennaPhaseOffset()
      : CommandBase(CmdName)
    {}

    GetSVAntennaPhaseOffset::GetSVAntennaPhaseOffset(const Sdx::GNSSBand& band, const std::string& system, const Sdx::optional<std::string>& name)
      : CommandBase(CmdName)
    {

      setBand(band);
      setSystem(system);
      setName(name);
    }

    GetSVAntennaPhaseOffsetPtr GetSVAntennaPhaseOffset::create(const Sdx::GNSSBand& band, const std::string& system, const Sdx::optional<std::string>& name)
    {
      return std::make_shared<GetSVAntennaPhaseOffset>(band, system, name);
    }

    GetSVAntennaPhaseOffsetPtr GetSVAntennaPhaseOffset::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSVAntennaPhaseOffset>(ptr);
    }

    bool GetSVAntennaPhaseOffset::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<Sdx::GNSSBand>::is_valid(m_values["Band"])
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["Name"])
        ;

    }

    std::string GetSVAntennaPhaseOffset::documentation() const { return Documentation; }


    int GetSVAntennaPhaseOffset::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    Sdx::GNSSBand GetSVAntennaPhaseOffset::band() const
    {
      return parse_json<Sdx::GNSSBand>::parse(m_values["Band"]);
    }

    void GetSVAntennaPhaseOffset::setBand(const Sdx::GNSSBand& band)
    {
      m_values.AddMember("Band", parse_json<Sdx::GNSSBand>::format(band, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetSVAntennaPhaseOffset::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetSVAntennaPhaseOffset::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetSVAntennaPhaseOffset::name() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["Name"]);
    }

    void GetSVAntennaPhaseOffset::setName(const Sdx::optional<std::string>& name)
    {
      m_values.AddMember("Name", parse_json<Sdx::optional<std::string>>::format(name, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}

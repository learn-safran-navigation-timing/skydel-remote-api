
#include "gen/GetSVAntennaGain.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSVAntennaGain
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSVAntennaGain::CmdName = "GetSVAntennaGain";
    const char* const GetSVAntennaGain::Documentation = "Get space vehicle gain antenna pattern. If no name is specified, the command is aplied to Basic SV Antenna.";

    REGISTER_COMMAND_FACTORY(GetSVAntennaGain);


    GetSVAntennaGain::GetSVAntennaGain()
      : CommandBase(CmdName)
    {}

    GetSVAntennaGain::GetSVAntennaGain(const Sdx::GNSSBand& band, const std::string& system, const Sdx::optional<std::string>& name)
      : CommandBase(CmdName)
    {

      setBand(band);
      setSystem(system);
      setName(name);
    }

    GetSVAntennaGainPtr GetSVAntennaGain::create(const Sdx::GNSSBand& band, const std::string& system, const Sdx::optional<std::string>& name)
    {
      return std::make_shared<GetSVAntennaGain>(band, system, name);
    }

    GetSVAntennaGainPtr GetSVAntennaGain::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSVAntennaGain>(ptr);
    }

    bool GetSVAntennaGain::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<Sdx::GNSSBand>::is_valid(m_values["Band"])
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["Name"])
        ;

    }

    std::string GetSVAntennaGain::documentation() const { return Documentation; }


    int GetSVAntennaGain::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    Sdx::GNSSBand GetSVAntennaGain::band() const
    {
      return parse_json<Sdx::GNSSBand>::parse(m_values["Band"]);
    }

    void GetSVAntennaGain::setBand(const Sdx::GNSSBand& band)
    {
      m_values.AddMember("Band", parse_json<Sdx::GNSSBand>::format(band, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetSVAntennaGain::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetSVAntennaGain::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetSVAntennaGain::name() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["Name"]);
    }

    void GetSVAntennaGain::setName(const Sdx::optional<std::string>& name)
    {
      m_values.AddMember("Name", parse_json<Sdx::optional<std::string>>::format(name, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}


#include "gen/GetVehicleAntennaGain.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetVehicleAntennaGain
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetVehicleAntennaGain::CmdName = "GetVehicleAntennaGain";
    const char* const GetVehicleAntennaGain::Documentation = "Get Vehicle gain antenna pattern. If no name is specified, the command is aplied to Basic vehicle Antenna.";

    REGISTER_COMMAND_FACTORY(GetVehicleAntennaGain);


    GetVehicleAntennaGain::GetVehicleAntennaGain()
      : CommandBase(CmdName)
    {}

    GetVehicleAntennaGain::GetVehicleAntennaGain(const Sdx::GNSSBand& band, const Sdx::optional<std::string>& name)
      : CommandBase(CmdName)
    {

      setBand(band);
      setName(name);
    }

    GetVehicleAntennaGainPtr GetVehicleAntennaGain::create(const Sdx::GNSSBand& band, const Sdx::optional<std::string>& name)
    {
      return std::make_shared<GetVehicleAntennaGain>(band, name);
    }

    GetVehicleAntennaGainPtr GetVehicleAntennaGain::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetVehicleAntennaGain>(ptr);
    }

    bool GetVehicleAntennaGain::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<Sdx::GNSSBand>::is_valid(m_values["Band"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["Name"])
        ;

    }

    std::string GetVehicleAntennaGain::documentation() const { return Documentation; }


    int GetVehicleAntennaGain::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    Sdx::GNSSBand GetVehicleAntennaGain::band() const
    {
      return parse_json<Sdx::GNSSBand>::parse(m_values["Band"]);
    }

    void GetVehicleAntennaGain::setBand(const Sdx::GNSSBand& band)
    {
      m_values.AddMember("Band", parse_json<Sdx::GNSSBand>::format(band, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetVehicleAntennaGain::name() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["Name"]);
    }

    void GetVehicleAntennaGain::setName(const Sdx::optional<std::string>& name)
    {
      m_values.AddMember("Name", parse_json<Sdx::optional<std::string>>::format(name, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
